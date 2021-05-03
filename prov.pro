QT += quick
QT += quick quickcontrols2
CONFIG += c++11
QT+=sql
QT+=widgets
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
RC_FILE+=sopp.rc

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        auxclass/backenddbcon.cpp \
        auxclass/dbinterface.cpp \
        auxclass/filep.cpp \
        auxclass/klog.cpp \
        auxclass/sqlqrymodel.cpp \
        auxclass/sqlquerymodel.cpp \
        backend.cpp \
        counters.cpp \
        global.cpp \
        ipserver.cpp \
        main.cpp \
        target.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    prov_de_DE.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    OrderDialog.qml \
    img/back.png \
    img/back@2x.png \
    img/back@3x.png \
    img/back@4x.png \
    img/drawer.png \
    img/drawer@2x.png \
    img/drawer@3x.png \
    img/drawer@4x.png \
    img/menu.png

HEADERS += \
    auxclass/backenddbcon.h \
    auxclass/dbinterface.h \
    auxclass/filep.h \
    auxclass/klog.h \
    auxclass/sqlqrymodel.h \
    auxclass/sqlquerymodel.h \
    backend.h \
    counters.h \
    global.h \
    ipserver.h \
    target.h \
    version.h

@VERSION = 1.0.1
 QMAKE_TARGET_COMPANY = IKS
 QMAKE_TARGET_PRODUCT = PROV
 QMAKE_TARGET_DESCRIPTION = Production visualization
 QMAKE_TARGET_COPYRIGHT = IKS
