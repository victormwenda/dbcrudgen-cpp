//
// Created by victor on 8/31/21.
//

#ifndef DBCRUDGEN_CPP_MSSQLRESULTSET_H
#define DBCRUDGEN_CPP_MSSQLRESULTSET_H

#include <sqlext.h>
#include <autotest.h>
#include <string>

namespace dbcrudgen {
    namespace db {
        namespace mssql {
            class MSSQLResultSet {
            public:

                int columnIndex;
                std::string columnName;
                short dataType;

                char cColumnValue;
                bool bColumnValue;
                short shColumnValue;
                int iColumnValue;
                long int liColumnValue;
                float fColumnValue;
                double dColumnValue;
                long lColumnValue;
                std::string strColumnValue;


                MSSQLResultSet(int &columnIndex, std::string &columnName, SQLSMALLINT &dataType, SQLPOINTER columnValue)
                        : columnIndex(columnIndex), dataType(dataType), columnName(columnName) {
                    setColumnValue(columnValue);
                }

                int getColumnIndex() const {
                    return columnIndex;
                }

                void setColumnIndex(int &columnIndex) {
                    MSSQLResultSet::columnIndex = columnIndex;
                }

                const std::string &getColumnName() const {
                    return columnName;
                }

                void setColumnName(const std::string &columnName) {
                    MSSQLResultSet::columnName = columnName;
                }

                /**
                 * Get column value
                 * @return void* ptr of column value. user *reinterpret_cast<datatype>(pVoid) to get value of object
                 */
                void *getColumnValue() const {
                    switch (dataType) {
                        case SQL_C_BINARY:
                            break;
                        case SQL_C_BIT:
                            break;
                        case SQL_C_CHAR:
                            return (char *) &strColumnValue;
                        case SQL_C_DOUBLE:
                            break;
                        case SQL_C_FLOAT:
                            break;
                        case SQL_C_LONG:
                            break;
                        case SQL_C_SHORT:
                            break;
                        case SQL_C_TYPE_DATE:
                            break;
                        case SQL_C_TYPE_TIME:
                            break;
                        case SQL_C_TYPE_TIMESTAMP:
                            break;
                        case SQL_C_TINYINT:
                            break;
                        case SQL_C_WCHAR:
                            break;
                    }
                }

                /**
                 * Set column value
                 * @param ptrColumnValue
                 */
                void setColumnValue(SQLPOINTER ptrColumnValue) {
                    switch (dataType) {
                        case SQL_C_BINARY:
                            break;
                        case SQL_C_BIT:
                            break;
                        case SQL_C_CHAR:
                            strColumnValue = std::string(
                                    reinterpret_cast<const char *>(reinterpret_cast<SQLCHAR *>(ptrColumnValue)));
                            break;
                        case SQL_C_DOUBLE:
                            break;
                        case SQL_C_FLOAT:
                            break;
                        case SQL_C_LONG:
                            break;
                        case SQL_C_SHORT:
                            break;
                        case SQL_C_TYPE_DATE:
                            break;
                        case SQL_C_TYPE_TIME:
                            break;
                        case SQL_C_TYPE_TIMESTAMP:
                            break;
                        case SQL_C_TINYINT:
                            break;
                        case SQL_C_WCHAR:
                            break;
                    }
                }
            };
        }
    }
}
#endif //DBCRUDGEN_CPP_MSSQLRESULTSET_H