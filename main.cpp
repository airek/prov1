#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <global.h>
#include <QDebug>
#include <ipserver.h>
#include <QQmlContext>
#include <backend.h>
#include "auxclass/sqlquerymodel.h"
#include <auxclass/backenddbcon.h>
#include <auxclass/sqlqrymodel.h>
#include <QIcon>
#include <QSharedMemory>
#include <QSystemSemaphore>
#include <QtWidgets/QMessageBox>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //QGuiApplication app(argc, argv);
    QApplication app(argc,argv);

    Global  global;
    global.writeLog("**** Start Aplikacji ****");
    global.writeLog(Global::mFileName);

    QSystemSemaphore semaphore("<prov>", 1);  // create semaphore
    semaphore.acquire(); // Raise the semaphore, barring other instances to work with shared memory

    #ifndef Q_OS_WIN32
       // in linux / unix shared memory is not freed when the application terminates abnormally,
        // so you need to get rid of the garbage
        QSharedMemory nix_fix_shared_memory("<prov 2>");
        if(nix_fix_shared_memory.attach()){
            nix_fix_shared_memory.detach();
        }
    #endif

       QSharedMemory sharedMemory("<prov 2>");  // Create a copy of the shared memory
       bool is_running;            // variable to test the already running application
       if (sharedMemory.attach()){ // We are trying to attach a copy of the shared memory
                                   // To an existing segment
           is_running = true;   // If successful, it determines that there is already a running instance
        }else{
            sharedMemory.create(1); // Otherwise allocate 1 byte of memory
            is_running = false;     // And determines that another instance is not running
        }
        semaphore.release();

        // If you already run one instance of the application, then we inform the user about it
        // and complete the current instance of the application
        if(is_running){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText("Aplikacja juz działa.\n"
                           "Dozwolona tylko jedna instancja aplikacji.");
            msgBox.exec();
            return 1;
        }



    if(global.connectToDb())
    {
        //qDebug()<<"Polączono z bazą danych";
        global.writeLog("Połączono z bazą danych ");
        qDebug()<<"Połączono z bazą danych ";
        global.readDataSettings();
        global.getDeviceStatus();

        if(global.isDebug)
        {
            global.writeLog("***** Ustawienia *****");
            global.writeSettingsLog();
            global.writeDataSettings();
        }


    }else
    {
        global.writeLog("nie połączono z bazdą danych błąd "+global.dbError());
        qDebug()<<"Nie połączono z db raportowany błąd "<<global.dbError();
    }

    qmlRegisterType<Backend>("com.Backend", 1, 0, "Backend");
    qmlRegisterType<BackendDbCon>("com.BackendDbCon", 1, 0, "BackendCon");
    qmlRegisterType<SqlQueryModel>("com.QryModel", 1, 0, "QryModel");
    qmlRegisterType<sqlqryModel>("com.SqlQryModel", 1, 0, "SqlQryModel");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QQuickStyle::setStyle("Material");
    engine.load(url);
    app.setWindowIcon(QIcon(":/img/graph.png"));

    if(global.checkMagicNumber())
        return app.exec();
    else
        return 0;
}
