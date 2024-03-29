//
// Created by victor on 3/15/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H
#define DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H

#include "CppMYSQLProjectCodeGen.h"
#include "../../../databases/mysql/scaffolding/entities/Tables.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLDbTableModelCodeGen : public CppMYSQLProjectCodeGen {

        public:

            /**
            * Create database table model
            * @param databaseModel
            * @param generatedCodeDir
            */
            void createDatabaseTableModel(CppMYSQLProjectModel projectModel, dbcrudgen::db::generic::Database& databaseModel,
                                          std::string generatedCodeDir) {

                CppClassTableModelTemplate sourceTemplate;

                auto tables = databaseModel.getTables();

                for (const auto &table : tables) {

                    std::string tableName = table.getTableName();

                    //Get the source template
                    std::string content = sourceTemplate.getTemplate();

                    //Set the headers
                    std::string projectName = projectModel.getProjectName();
                    projectName = parser.parseProjectNameToHeaderName(projectName);
                    content = StringUtils::replace(content, "${PROJECT_NAME}", projectName);


                    //Set the class name
                    std::string classname = parser.toCppClassName(tableName);
                    content = StringUtils::replace(content, "${CLASS_NAME}", classname);

                    std::string classnameHeader = parser.parseClassNameToHeaderName(tableName);
                    content = StringUtils::replace(content, "${CLASS_NAME_HEADER}", classnameHeader);


                    //Set the table name
                    content = StringUtils::replace(content, "${TABLE_NAME}", tableName);


                    const auto tableColumnsMap = databaseModel.getTables();
                    const auto tableColumnsIterator = tableColumnsMap.find(tableName);

                    if (tableColumnsIterator != tableColumnsMap.end()) {

                        std::vector<dbcrudgen::db::mysql::Columns> tableColumns = tableColumnsIterator->second;

                        std::string ctorParams{};
                        std::string ctorVars{};
                        std::string ctorInitializers{};
                        std::string columnGetters{};
                        std::string columnsMetaData{};

                        int index = 0;


                        for (auto tableColumn : tableColumns) {

                            bool isBeforeLast = index < tableColumns.size() - 1;

                            ctorParams += createClassProperties(CppVariableTemplate{}, tableColumn);

                            ctorVars += createConstructorParams(CppVariableTemplate{}, tableColumn, isBeforeLast);

                            ctorInitializers += createConstructorParamInitializers(CppCtorInitializersTemplate{},
                                                                                   tableColumn, isBeforeLast);

                            columnGetters += createColumnGetters(CppPropertyGetterTemplate{}, tableColumn);

                            columnsMetaData += createColumnsMetaData(CppStructTableColumnModelTemplate{},
                                                                     tableColumn, //Add 1 to index for position naming of columns
                                                                     index + 1);

                            index++;
                        }

                        //create class properties
                        content = StringUtils::replace(content, "${COLUMNS_VARS}", ctorParams);

                        //create constructor variables
                        content = StringUtils::replace(content, "${CTOR_VARIABLES}", ctorVars);

                        //Create constructor initializers
                        content = StringUtils::replace(content, "${INSTANCE_VARIABLES_INITIALIZERS}",
                                                       ctorInitializers);

                        //Create column getters
                        content = StringUtils::replace(content, "${COLUMNS_GETTERS}", columnGetters);


                        //Create columns meta data
                        content = StringUtils::replace(content, "${COLUMNS_METADATA}", columnsMetaData);
                    }

                    std::string filename = generatedCodeDir + "/" + classname + ".h";

                    FilesWriter::writeFile(filename, content);
                }

            }

            /**
             * Create column getters
             * @param model
             * @param table
             * @return
             */
            std::string createColumnGetters(CppPropertyGetterTemplate getterTemplate, dbcrudgen::db::mysql::Columns column) {

                std::string getterTmp = getterTemplate.getTemplate();

                std::string dataType = column.getDataType();
                std::string columnName = column.getColumnName();

                getterTmp = parser.parseTableColumnsGetters(getterTemplate, column);

                return getterTmp;
            }


            std::string createClassProperties(CppVariableTemplate sourceTemplate, dbcrudgen::db::mysql::Columns column) {

                std::string source;


                std::string srcTmp = sourceTemplate.getTemplate();

                std::string delimiter = ";";

                source += parseTableInstanceVariables(sourceTemplate, column, delimiter);


                return source;
            }

            std::string
            createConstructorParams(CppVariableTemplate sourceTemplate, dbcrudgen::db::mysql::Columns column, bool isBeforeLast) {

                std::string source;

                std::string srcTmp = sourceTemplate.getTemplate();

                std::string delimiter = "";

                if (isBeforeLast) {
                    delimiter = ",";
                }

                source += parser.parseTableColumnVariables(sourceTemplate, column, delimiter);

                return source;
            }

            /**
             * Create constructor param initializers
             * @param model
             * @param table
             * @return
             */
            std::string
            createConstructorParamInitializers(CppCtorInitializersTemplate sourceTemplate, dbcrudgen::db::mysql::Columns column,
                                               bool isBeforeLast) {

                std::string source;

                std::string srcTmp = sourceTemplate.getTemplate();

                std::string delimiter = "";

                if (isBeforeLast) {
                    delimiter = ",";
                }

                source += parser.parseClassConstructorInitializerProperties(sourceTemplate, column, delimiter);

                return source;
            }

            /**
                 * Create constructor param initializers
                 * @param model
                 * @param table
                 * @return
                 */
            std::string
            createColumnsMetaData(CppStructTableColumnModelTemplate sourceTemplate, dbcrudgen::db::mysql::Columns column, int index) {
                std::string source;
                std::string srcTmp = sourceTemplate.getTemplate();
                source += parser.parseTableColumnsMetaData(sourceTemplate, column, index);
                return source;
            }

            /**
             * Parse Table Column Properties. Or Variables
             * @param codeTemplate
             * @param column
             * @param delimiter
             * @return
             */
            static std::string
            parseTableInstanceVariables(CppVariableTemplate &codeTemplate, dbcrudgen::db::mysql::Columns &column,
                                        std::string &delimiter) {

                std::string source = codeTemplate.getTemplate();

                const std::string &dataType = column.getDataType();
                const std::string &columnName = column.getColumnName();

                std::string className = getParser().toCppClassName(columnName);
                std::string columnNameProperty = getParser().toCppVariableName(columnName);


                std::string cppDataType = getParser().toCppDataType(dataType.c_str());

                source = StringUtils::replace(source, "${DATA_TYPE}", cppDataType);
                source = StringUtils::replace(source, "${PROPERTY_NAME}", columnNameProperty);
                source = StringUtils::replace(source, "${DELIMITER}", delimiter);

                return source;
            }
        };

    }
}


#endif //DBCRUDGEN_CPP_CPPMYSQLDBTABLEMODELCODEGEN_H
