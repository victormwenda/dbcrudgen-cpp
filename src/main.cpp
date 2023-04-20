#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "databases/generic/Database.h"
#include "orm/projects/CppMYSQLProjectModel.h"
#include "orm/creators/cpp/CppMYSQLProjectCreator.h"
#include "orm/creators/postman/PostmanProjectCreator.h"
#include "orm/creators/php/LaravelProjectCreator.h"
#include "orm/projects/LaravelProjectModel.h"
#include "orm/projects/JaxWsProjectModel.h"
#include "orm/creators/java/JaxWsProjectCreator.h"
#include "orm/creators/java/JaxRsProjectCreator.h"
#include "orm/projects/AngularProjectModel.h"
#include "orm/creators/angular/AngularProjectCreator.h"
#include "orm/projects/SpringBootProjectModel.h"
#include "orm/creators/java/SpringBootProjectCreator.h"


/**
 * Create Angular Project
 */
void createAngularProject();

/**
 * Create CPP Project
 */
void createCppProject();

/**
 * Create PHP Project
 */
void createPhpProject();

/**
 * Create Postman project
 */
void createPostmanProject(std::string &projectName, std::string &storeDirectory, std::string &protocol,
                          std::string &apiHost, int port, std::string &pathSegments, std::string &databaseType,
                          std::string &databaseName);

void createJavaProject();

void createJaxRsHibernateProject();

void createSpringBootHibernateProject();

void testPostmanProject();

int main(int argc, char **argv) {


    return EXIT_SUCCESS;
}


void createCppProject(dbcrudgen::db::generic::Database databaseModel) {

    std::string projectName = "pesarika-cpp";
    std::string workspaceDir = "/opt/victor/workspace/cpp";
    std::string includesDir = "includes";
    std::string libsDir = "libs";
    std::string generatedCodeDir = "src/crud";
    std::string generatedModelCodeDir = "model";
    std::string generatedDbOpsCodeDir = "dao";

    dbcrudgen::orm::CppMYSQLProjectModel projectModel{projectName, workspaceDir, includesDir, libsDir,
                                                      generatedCodeDir, generatedModelCodeDir, generatedDbOpsCodeDir};

    dbcrudgen::orm::CppMYSQLProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();

}

void createAngularProject(dbcrudgen::db::generic::Database databaseModel) {

    std::string projectName = "eqtr-web";
    std::string workspaceDir = "/opt/workspace/javascript";
    std::string distDir = "dist";
    std::string e2eDir = "e2e";
    std::string nodeModulesDir = "node_modules";
    std::string srcDir = "src";
    std::string appDir = "app";
    std::string assetsDir = "assets";
    std::string environmentDir = "environments";
    std::string moduleDir = "admin";
    std::string modelsDir = "models";
    std::string baseUrl = "http://127.0.0.1:8000/api/v1";

    dbcrudgen::orm::AngularProjectModel projectModel{workspaceDir, projectName, distDir, e2eDir,
                                                     nodeModulesDir, srcDir, appDir, assetsDir,
                                                     environmentDir, moduleDir, modelsDir, baseUrl};

    dbcrudgen::orm::AngularProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();

}

void createPhpProject(dbcrudgen::db::generic::Database databaseModel) {

    std::string projectName = "eqtr-web-adm-laravel";
    std::string workspaceDir = "/var/www/html";
    std::string assetsDir = "public";
    std::string jsDir = "js";
    std::string cssDir = "css";
    std::string controllersDir = "app/Http/Controllers";
    std::string modelsDir = "app/Http/Models";
    std::string viewsDir = "resources/views";
    std::string routesDir = "routes";
    std::string apiVersion = "v1";
    std::string webRouteFile = "web.php";
    std::string apiRouteFile = "api.php";

    dbcrudgen::orm::LaravelProjectModel projectModel{projectName, workspaceDir, controllersDir, modelsDir,
                                                     viewsDir, routesDir, assetsDir, jsDir, cssDir, webRouteFile,
                                                     apiRouteFile,
                                                     apiVersion};

    dbcrudgen::orm::LaravelProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();

}

void testPostmanProject() {
    std::string projectName = "Digisoko";
    std::string storeDirectory = "/home/victor/Desktop";
    std::string protocol = "https";
    std::string apiHost = "localhost";
    int port = 443;
    std::string pathSegments = "/v1/";
    std::string databaseType = "mysql";
    std::string databaseName = "digisoko";
    createPostmanProject(projectName, storeDirectory, protocol, apiHost, port, pathSegments, databaseType,
                         databaseName);
}

void createPostmanProject(dbcrudgen::db::generic::Database &databaseModel, std::string &projectName,
                          std::string &storeDirectory, std::string &protocol, std::string &apiHost, int port,
                          std::string &pathSegments, std::string &databaseType,  std::string &databaseName) {


    std::map<std::string, std::string> headers;

    headers.insert(std::pair<std::string, std::string>(std::string{"Content-Type"}, std::string{"application/json"}));
    headers.insert(std::pair<std::string, std::string>(std::string{"Accept"}, std::string{"application/json"}));

    dbcrudgen::orm::PostmanProjectModel projectModel{projectName, storeDirectory, protocol, apiHost, port,
                                                     pathSegments, headers, databaseType};
    dbcrudgen::orm::PostmanProjectCreator projectCreator{projectModel, databaseModel};
    projectCreator.createProject();
}

void createJavaProject(dbcrudgen::db::generic::Database& databaseModel) {

    std::string projectName = "eqtr-apis";
    std::string workspaceDir = "/opt/workspace/java";
    std::string packageName = "com.eqtr.webservices";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";

    std::string webDir = "webapp";
    std::string apisPkg = "web.apis";
    std::string dbConnPkg = "database.conn";
    std::string entitiesPkg = "database.entities";
    std::string transactionsPkg = "database.transactions";
    std::string webAppPkg = "web.application";
    std::string beansPkg = "web.beans";

    std::string apiClassSuffix = "Resource";
    std::string entityClassSuffix = "Entity";
    std::string trxClassSuffix = "Transactions";
    std::string beansClassSuffix = "Beans";

    std::string webAppClass = "WebApplication";
    std::string dbConnClass = "DatabaseConnectionHandler";
    std::string urlPattern = "/api/v1/*";

    dbcrudgen::orm::JaxWsProjectModel jaxWsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, dbConnPkg, entitiesPkg,
                                                 transactionsPkg, webAppPkg, beansPkg, apiClassSuffix,
                                                 entityClassSuffix,
                                                 trxClassSuffix, beansClassSuffix, webAppClass, dbConnClass,
                                                 urlPattern};
    dbcrudgen::orm::JaxWsProjectCreator jaxWsCreator{jaxWsModel, databaseModel};
    //jaxWsCreator.createProject();


    dbcrudgen::orm::JaxRsProjectModel jaxRsModel{projectName, workspaceDir,
                                                 srcDir, moduleDir, javaDir, libsDir,
                                                 resourcesDir, packageName, webDir, apisPkg, dbConnPkg, entitiesPkg,
                                                 transactionsPkg, webAppPkg, beansPkg, apiClassSuffix,
                                                 entityClassSuffix,
                                                 trxClassSuffix, beansClassSuffix, webAppClass, dbConnClass,
                                                 urlPattern};

    dbcrudgen::orm::JaxRsProjectCreator jaxRsCreator{jaxRsModel, databaseModel};
    jaxRsCreator.createProject();

}

void createJaxRsHibernateProject(dbcrudgen::db::generic::Database& databaseModel) {
    createJavaProject(databaseModel);
}

void createSpringBootHibernateProject(dbcrudgen::db::generic::Database& databaseModel) {

    std::string projectName = "nats-java";
    std::string workspaceDir = "/opt/workspace/java";
    std::string packageName = "ke.co.nats";

    std::string srcDir = "src";
    std::string moduleDir = "main";
    std::string javaDir = "java";
    std::string libsDir = "libs";
    std::string resourcesDir = "resources";
    std::string webDir = "public";
    dbcrudgen::orm::SpringProjectDirs sbDirs{srcDir, moduleDir, javaDir, libsDir, resourcesDir, webDir};

    std::string beansPkg = "dblayer.beans";
    std::string dbConnPkg = "dblayer.conn";
    std::string reposPkg = "dblayer.repos";
    std::string entitiesPkg = "dblayer.entities";
    std::string modelPkg = "dblayer.models";

    std::string httpReqPkg = "entry.http.requests";
    std::string httpResPkg = "entry.http.responses";
    std::string ctlPkg = "entry.controllers";
    std::string transactionsPkg = "dblayer.dao";
    std::string bzLogicPkg = "service.business";
    std::string webAppPkg = "app";
    dbcrudgen::orm::SpringProjectPackages sbPkgs{beansPkg, bzLogicPkg, ctlPkg, dbConnPkg, entitiesPkg, httpReqPkg,
                                                 httpResPkg, modelPkg, reposPkg, transactionsPkg, webAppPkg};

    std::string webAppClass = "Application";
    std::string dbConnClass = "DatabaseConnectionHandler";
    std::string applicationProperties = "application.properties";
    dbcrudgen::orm::SpringProjectClasses sbClasses{dbConnClass, webAppClass, applicationProperties};

    std::string urlPattern = "/";
    int serverPort = 8080;

    std::string ctlClassSuffix = "Controller";
    std::string beansClassSuffix = "Beans";
    std::string bzLogicClassSuffix = "Service";
    std::string entityClassSuffix = "Entity";
    std::string httpReqClassSuffix = "Request";
    std::string httpResClassSuffix = "Response";
    std::string reposClassSuffix = "Repository";
    std::string trxClassSuffix = "Dao";
    std::string modelClassSuffix = "Model";

    dbcrudgen::orm::SpringProjectSuffixes sbClsSuffxs{beansClassSuffix, bzLogicClassSuffix, ctlClassSuffix,
                                                      entityClassSuffix, httpReqClassSuffix, httpResClassSuffix,
                                                      modelClassSuffix, reposClassSuffix, trxClassSuffix};

    dbcrudgen::orm::SpringBootProjectModel sbModel{projectName, workspaceDir, packageName, sbDirs, sbPkgs, sbClasses,
                                                   sbClsSuffxs, urlPattern, serverPort};

    dbcrudgen::orm::SpringBootProjectCreator sbCreator{sbModel, databaseModel};
    sbCreator.createProject();
}