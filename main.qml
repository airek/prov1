import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import com.Backend 1.0
import com.BackendDbCon 1.0

ApplicationWindow{


    id:appWindow
    visible: true

    width: Screen.width
    height: Screen.height
    title: qsTr("PROV")
    Material.theme:Material.System

    Component.onDestruction:
    {
        console.log("Kończymy");
        insertEvent("Koniec Aplikacji")
        writeAppSettings();
    }

    Component.onCompleted:
    {
        console.log("Zaczynamy");

        setAppSettings();
        insertEvent("Start Aplikacji")

    }

    BackendCon
    {
        id:backendDbCon
    }

    Backend
    {
        id:backend

        Component.onCompleted:
        {
            backend.startServer()
        }
        onServerListening:
        {

            indicator.Material.background=Material.Amber
        }

        onClientServerConnected:
        {
            indicator.Material.background=Material.LightGreen
        }
        onClientServerDisconnected:
        {
            indicator.Material.background=Material.Amber
        }

        onCntrIncreased:
        {
            init.hourCntr=backend.getHourCntr();
            init.shiftCounter=backend.getShiftCntr();

            if(lineStat.text!="PRODUKCJA")
            {
                console.log("Produkcja ")
                lineStat.text="PRODUKCJA"
                insertEvent("PRODUKCJA")
            }
        }

        onTargetsIncreased:
        {
           init.hrTargetText=backend.getTargetPerH();
           init.shTargetText=backend.getTargetPers();
        }

        onCntrZero:
        {
            insertEvent("Zerowanie Liczników")
            init.hourCntr=backend.getHourCntr();
            init.shiftCounter=backend.getShiftCntr();

            //setting Koniec Zlecenia at shift end
            if(init.shiftCounter==="0")
            {
                console.log("Ustawiamy Koniec zmiany")
                lineStat.text="KONIEC ZLECENIA"
                setStatus("KONIEC ZLECENIA")

            }



        }

        onTargetsZero:
        {
            init.hrTargetText=backend.getTargetPerH();
            init.shTargetText=backend.getTargetPers();
        }

    }

    //clock variable
    property string strHour
    property string strMinute
    property string strSeconds
    property string page



    //javascript
    function timeChanged()
    {
        var date = new Date;

        strHour=date.getHours().toString()
        strMinute = date.getMinutes().toString()
        strSeconds = date.getUTCSeconds().toString()


        if(strSeconds.length===1)
        {
            strSeconds="0"+strSeconds
        }

        if(strHour.length===1)
            strHour="0"+strHours

        if(strMinute.length===1)
            strMinute="0"+strMinute

    }
    // javascripts
    function calculateDrawWidth()
    {
        var drawWidth;
        drawWidth=Math.min(appWindow.width,appWindow.height)/3*2;

        return drawWidth;
    }

    // getting target
    function getTarget()
    {
        var targetpH;
        targetpH=backend.getTarget(partNr.text)
        console.log("Target per hour "+target)

        target.text=targetpH+" szt./h"
    }

    function setStatus(status)
    {
        backend.status(status);
    }

    function getMidVal()
    {
        return backendDbCon.getMidVal()
    }
    function getMaxVal()
    {
        return backendDbCon.getMaxVal()
    }
    function getMinVal()
    {
        return backendDbCon.getMinVal()
    }
    //
    function getDate()
    {
        var today=new Date;

        var currentDate=today.getFullYear()+'-'+(today.getMonth()+1)+'-'+today.getDate();
        //console.log("CurDate "+currentDate);

        return currentDate;
    }
    //
    function getCurrentTime()
    {
        var today = new Date();

        var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();

        return time;
    }

    function insertEvent(eventName)
    {
        var currentDate=getDate()
        var qry="insert into events values('"+currentDate+"','"+getCurrentTime()+"'"
        +",'"+eventName+"',"+init.hourCntr+","+init.shiftCounter+","+init.hrTargetText+","
        +init.shTargetText+")";

        console.log("qry before insert "+qry);

        backend.execQry(qry);

    }

    function writeAppSettings()
    {
        console.log("line Status "+lineStat.text)
        backend.writeSettings(partNr.text,init.hrTargetText,init.shTargetText,
                              init.hourCntr,init.shiftCounter,lineStat.text)
    }

    function setAppSettings()
    {
        init.hourCntr=backend.getHourCntr();
        init.shiftCounter=backend.getShiftCntr();
        init.hrTargetText=backend.getTargetPerH();
        init.shTargetText=backend.getTargetPers();
        lineStat.text=backend.getStatus();
        setStatus(lineStat.text);
        partNr.text=backend.getPartNr();
        getTarget()
        lineNr.text=backend.getLine();

    }

    Timer{
        interval: 100; running: true; repeat: true;
        onTriggered: timeChanged()
    }

    DlgStatus
    {
        id:msgD
        modal: true
        focus: true
        winTitle: "Wybierz status"
        info:"Byku"

        x: (appWindow.width - width) / 2
        y: appWindow.height / 6
        width: Math.min(appWindow.width, appWindow.height) / 2 * 2
        height: 200

        onActivated:
        {
            console.log("activated index "+index)
            if(index==1)
            {
                lineStat.text="AWARIA";
                setStatus("AWARIA");
            }else if(index==2)
            {
                lineStat.text="PRZERWA";
                setStatus("PRZERWA");
            }else if(index==3)
            {
                lineStat.text="ZMIANA ZLECENIA"
                setStatus("ZMIANA ZLECENIA")
            }else
            {
                lineStat.text="KONIEC ZLECENIA"
                setStatus("KONIEC ZLECENIA")
            }

            insertEvent(lineStat.text)
        }
    }

    //
    DlgPartNo
    {
        id:dlgPartN
        modal: true
        focus: true
        winTitle: "Wybierz numer"


        x: (appWindow.width - width) / 2
        y: appWindow.height / 6
        width: Math.min(appWindow.width, appWindow.height) / 2 * 2
        height: 200

        onActivated:
        {
            console.log("Part "+partNo)

            partNr.text=partNo

            getTarget()

            insertEvent(partNo)
        }

    }

     //
    //
    DlgPartNoN
    {
        id:dlgPartNon
        modal: true
        focus: true
        winTitle: "Wybierz numer"


        x: (appWindow.width - width) / 2
        y: appWindow.height / 6
        width: Math.min(appWindow.width, appWindow.height) / 2 * 2
        height: 400

        onActivated:
        {
            console.log("Part "+partNo)

            partNr.text=partNo

            getTarget()

            insertEvent(partNo)
        }

    }
    // header
    header:ToolBar
    {
        id:header
        Material.primary:Material.Indigo
        Material.foreground:"white"
        height:appWindow.height/5

        RowLayout
        {
            anchors.fill:parent
            spacing: 20

            ToolButton
            {
                id:toolbutton
                    contentItem: Image {
                    id: drawerImg
                    source: stackView.depth > 1 ? "img/back.png":"img/drawer.png"
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    }

                    // onclicked method
                    onClicked:
                    {
                        if (stackView.depth > 1) {
                            stackView.pop()
                            listView.currentIndex = -1
                        } else {
                            drawer.open()
                        }
                    }

                }

            Label {

                id: currentTime
                text: strHour+":"+strMinute+":"+strSeconds
                font.pixelSize:header.height*0.4
                font.bold: false
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true


             }
            ColumnLayout
            {
                id:lineStatus
                spacing:10

                Label
                {
                    id:lineNr
                    text:"10032-13"
                    font.pixelSize: header.height*0.4
                    font.bold: false
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment:Qt.AlignVCenter
                    Layout.fillWidth:true
                }

                Label
                {
                    id:lineStat
                    text:"PRODUKCJA"
                    font.pixelSize: header.height*0.4
                    font.bold: false
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment:Qt.AlignVCenter
                    Layout.fillWidth:true

                    Behavior on text {

                        SequentialAnimation
                        {
                            NumberAnimation
                            {
                                target:lineStat
                                properties: "scale"
                                from:0.2
                                to:1.7
                                duration: 1200
                            }
                            NumberAnimation
                            {
                                target:lineStat
                                properties: "scale"
                                from:1.7
                                to:1.0
                                duration: 500
                            }

                        }
                    }
                }
            }
            ColumnLayout
            {
                id:columnL
                spacing: 10

                Label
                {
                    id:partNr
                    text:"5831,00"
                    font.pixelSize: header.height*0.3
                    font.bold: false
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment:Qt.AlignVCenter
                    Layout.fillWidth:true

                    Behavior on text {

                        SequentialAnimation
                        {
                            NumberAnimation
                            {
                                target:partNr
                                properties: "scale"
                                from:0.2
                                to:1.7
                                duration: 1200
                            }
                            NumberAnimation
                            {
                                target:partNr
                                properties: "scale"
                                from:1.7
                                to:1.0
                                duration: 500
                            }

                        }
                    }
                }
                Label
                {
                    id:target
                    text:"120 szt./h"
                    font.pixelSize: header.height*0.3
                    font.bold: false
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment:Qt.AlignVCenter
                    Layout.fillWidth:true

                    Behavior on text {

                        SequentialAnimation
                        {
                            NumberAnimation
                            {
                                target:target
                                properties: "scale"
                                from:0.2
                                to:1.7
                                duration: 1200
                            }
                            NumberAnimation
                            {
                                target:target
                                properties: "scale"
                                from:1.7
                                to:1.0
                                duration: 500
                            }

                        }
                    }
                }
            }
            ColumnLayout
            {
                id:buttonLayout
                spacing:2
                Layout.maximumHeight: header.height

                RoundButton
                {
                    id:indicator
                    width: 50
                    height: 50
                    radius: 30
                    Material.background: Material.Red


                    /*Component.onCompleted:
                    {
                        backend.startServer()
                    }*/


                }

                RoundButton
                {
                    id:statusChange
                    width: 40
                    height: 40
                    radius: 30
                    Material.background: Material.Indigo
                    text: qsTr("Status")
                    onClicked:
                    {
                        msgD.open()
                    }

                }

                RoundButton
                {
                    id:partNoChange
                    width: 40
                    height: 40
                    radius: 30
                    Material.background: Material.Blue
                    text:qsTr("Numer")

                    onClicked:
                    {
                        dlgPartNon.open()
                        //dlgPartN.open()
                    }

                }

            }

            /*ToolButton
            {
                id:menu
                contentItem: Image {
                    id: imgManu
                    source: "qrc:/img/menu.png"
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter


                }
                onClicked: appMenu.open()
                Menu {
                    id: appMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    /*MenuItem {
                        text: "Settings"
                        onTriggered: settingsDialog.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }

                }

            }*/
        }
    }



    Drawer
    {
        id:drawer
        width: calculateDrawWidth()
        implicitHeight:appWindow.height-8

        ListView
        {
            id:listView
            anchors.fill:parent
            currentIndex: -1
            model:ListModel
            {
                id:dataModel
                ListElement
                {
                    title:"Komunikacja"
                    source: "TCPServer.qml"
                }
                ListElement
                {
                    title:"Ustawienia"
                    source:"Settings.qml"

                }
            }

            delegate: ItemDelegate
            {
                width: parent.width
                text:title
                highlighted: listView.currentIndex

                onClicked: {
                    listView.currentIndex=index
                    stackView.push(source)
                    drawer.close()


                }
            }
          }
    }
    /*Counters
    {
        id:cntrs
    }*/

    StackView
    {
        id:stackView
        anchors.fill: parent

        initialItem:Counters
        {
            id:init;
            minVal:getMinVal();
            midVal:getMidVal();
            maxVal:getMaxVal();
        }


    }

}
