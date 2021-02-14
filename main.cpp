#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <global.h>
#include <QDebug>
#include <ipserver.h>
#include <QQmlContext>
#include <backend.h>
#include "auxclass/sqlquerymodel.h"
#include <auxclass/backenddbcon.h>
#include <QIcon>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Global  global;
    global.writeLog("**** Start Aplikacji ****");
    global.writeLog(Global::mFileName);



    if(global.connectToDb())
    {
        //qDebug()<<"Polączono z bazą danych";
        global.writeLog("Połączono z bazą danych ");
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
        //qDebug()<<"Nie połączono z db raportowany błąd "<<global.dbError();
    }

    qmlRegisterType<Backend>("com.Backend", 1, 0, "Backend");
    qmlRegisterType<BackendDbCon>("com.BackendDbCon", 1, 0, "BackendCon");
    qmlRegisterType<SqlQueryModel>("com.QryModel", 1, 0, "QryModel");

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
