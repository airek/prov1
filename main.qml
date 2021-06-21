import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import com.Backend 1.0
import com.BackendDbCon 1.0
import "myJsScripts.js" as MyScripts

ApplicationWindow{


    id:appWindow
    visible: true

    width: Screen.width
    height: Screen.height
    visibility: Window.Maximized
    title: qsTr("PROV")
    Material.theme:Material.System

    property string vtimeToProduce
    property int vpersQty
    property int vpartQty
    property int vTargetPerHour
    property string previousPartNr

    // dodać do ini
    property string vOrderID
    property int vAuxTime // store temp time to calculate
    property int vProdTime // production time
    property int vBreakTime // breaks time
    property string vAuxDate // to check if date change


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
            backend.writeSettings()
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

            if(vpartQty>0)
            {
                vpartQty=vpartQty-1
                orderQty.text=vpartQty+" szt."
                calculateTimeToProduce()
            }

            if(lineStat.text!="PRODUKCJA")
            {
                if(lineStat.text==="KONIEC ZLECENIA")
                {
                    MyScripts.insertProtokol();
                }

                vBreakTime=vBreakTime+MyScripts.calculateTime(vAuxTime,vAuxDate)
                console.log("Czas postojów "+vBreakTime)
                vAuxTime=MyScripts.getCurrentTimeInSeconds()
                vAuxDate=MyScripts.getDate()

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
                insertEvent("KONIEC ZLECENIA");
                MyScripts.updateProtokol()
                //MyScripts.setEndOfShift()

            }



        }

        onTargetsZero:
        {
            init.hrTargetText=backend.getTargetPerH();
            init.shTargetText=backend.getTargetPers();
        }

    }

    //clock variable
    /*property string strHour
    property string strMinute
    property string strSeconds*/
    property string page
    property string timeString



    //javascript
    function timeChanged()
    {
        /*var date = new Date;


        strHour=date.getHours().toString().
        strMinute = date.getMinutes().toString()
        strSeconds = date.getUTCSeconds().toString()*/

        timeString=new Date().toLocaleTimeString()
       // console.log("time "+timeString)

        /*if(strSeconds.length===1)
        {
            strSeconds="0"+strSeconds
        }

        if(strHour.length===1)
            strHour="0"+strHour

        if(strMinute.length===1)
            strMinute="0"+strMinute*/

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
        console.log("Target per hour "+targetpH)

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
        var today = new Date().toLocaleTimeString()

        //var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();

        console.log("Time "+today)

        return today;
    }

    function insertEvent(eventName)
    {
        var shiftN=MyScripts.getShift()
        var team=orderD.vTeam

        console.log("shiftNr "+shiftN)
        console.log("team "+team)
        var currentDate=getDate()
        var qry="insert into events (eventDate,eventTime,event,hourCntr,shiftCntr,hourTarget,shiftTargte,partNr,line,tinSecs,shiftNr,team) "
        +" values('"+currentDate+"','"+getCurrentTime()+"'"
        +",'"+eventName+"',"+init.hourCntr+","+init.shiftCounter+","+init.hrTargetText+","
        +init.shTargetText+",'"+partNr.text+"','"+lineNr.text+"',"+MyScripts.getCurrentTimeInSeconds()+","+shiftN+",'"+team+"')";

        console.log("qry before insert "+qry);

        if(backend.isDbConnected())
            backend.execQry(qry);
        else
        {
            if(backend.connectToDB())
                backend.execQry(qry)
            else
                backendDbCon.writeNID(qry)
        }

    }

    function writeAppSettings()
    {
        console.log("line Status "+lineStat.text)
        console.log("write Settings"+orderD.vTeam)
        var orderCntr=backend.getOrderCntr()
        backend.writeSettings(partNr.text,init.hrTargetText,init.shTargetText,
                              init.hourCntr,init.shiftCounter,lineStat.text,vpersQty,
                              vpartQty,vtimeToProduce,vTargetPerHour,orderCntr,
                              vOrderID,vAuxTime,vAuxDate,vProdTime,vBreakTime,orderD.vTeam)
    }

    function setAppSettings()
    {
        init.hourCntr=backend.getHourCntr();
        init.shiftCounter=backend.getShiftCntr();
        init.hrTargetText=backend.getTargetPerH();
        init.shTargetText=backend.getTargetPers();
        
        vpersQty=backend.getPersQty();
        vpartQty=backend.getPartQty()
        vtimeToProduce=backend.getTimeToProduce();
        vOrderID=backend.getOrderID()
        vAuxTime=backend.getAuxTime()
        vProdTime=backend.getProdTime()
        vBreakTime=backend.getBreakTime()
        vAuxDate=backend.getAuxDate()


        partNr.text=backend.getPartNr();
        vTargetPerHour=backend.getHourTarget()
        //console.log("vTarget "+vTargetPerHour)
        setTarget();
        lineNr.text=backend.getLine();
        lineStat.text=backend.getStatus();
        orderD.vTeam=backend.getTeam();
        setStatus(lineStat.text);

    }

    // setting target
    function setTarget()
    {
        backend.setTarget(parseInt(vTargetPerHour))

    }

    function calculateTimeToProduce()
    {
        var qty
        var tactTime
        var timeToProduce

        // tact time
        tactTime=3600/vTargetPerHour
        //console.log("tact "+tactTime)

        // time to produce
        timeToProduce=vpartQty*tactTime

        timeToProduce=parseInt(timeToProduce)

        vtimeToProduce=MyScripts.secondstotime(timeToProduce)

        timeElapsed.text=vtimeToProduce
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



            vProdTime=vProdTime+MyScripts.calculateTime(vAuxTime,vAuxDate)
            vAuxDate=MyScripts.getDate()
            vAuxTime=MyScripts.getCurrentTimeInSeconds()
            console.log("Czas Produkcji "+vProdTime)

            insertEvent(lineStat.text)
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

        //x: (appWindow.width - width)/2
        x:appWindow.x+10

        y: appWindow.y-header.height
        //width: Math.min(appWindow.width, appWindow.height) / 2 * 2

        width: appWindow.width-40
        height: appWindow.height-20

        onActivated:
        {
            console.log("Part "+partNo)

            partNr.text=partNo
            getTarget()
            insertEvent(partNo)
        }

    }

    OrderDialog
    {
        id:orderD

        winTitle: "Rejestruj zlecenie"

        width: appWindow.width-20
        height: appWindow.height-10

        onActivated:
        {
            partNr.text=partNo
            MyScripts.updateProtokol()

            numOperators.text="osób: "+vpersQty
            orderQty.text=vpartQty+" szt."
            target.text=vTargetPerHour+" szt/h"
            calculateTimeToProduce()
            setTarget()
            // setting orderCntr to zero
            backend.setOrderCntr(0)
            insertEvent(partNo)
            // ustawianie dodatkowych zmiennych do obliczania czasów na 0
            vProdTime=0
            vBreakTime=0
            vAuxTime=MyScripts.getCurrentTimeInSeconds()
            vAuxDate=MyScripts.getDate()

            // insert new data to order
            MyScripts.insertProtokol()
            // opening chekList
            chkList.actPartNr=partNo
            chkList.prevPartNr=previousPartNr

            /* checking if actPartNr is different than previousPartNr
            and setting in lineCom table is set to 1 to show chelist
            otherwise checklist is not show */
            if(partNo!==previousPartNr && backend.getCheckList()===1)
            {
                var dtD=MyScripts.createDTString()
                var shfNr=MyScripts.getShift()
                var dtStr=dtD+"/"+shfNr+"/"+lineNr.text
                chkList.dtString=dtStr
                chkList.show()
            }
        }


    }
    CheckLista
    {

        id:chkList
        width: appWindow.width-20
        height: appWindow.height-10


    }

    // header
    header:ToolBar
    {
        id:header
        Material.primary:Material.Indigo
        Material.foreground:"white"
        height:appWindow.height/4

        RowLayout
        {
            anchors.fill:parent
            spacing: 40

            /*ToolButton
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

                }*/
            ColumnLayout
            {

                id:firstCol

                Label {

                    id: currentTime
                    //text: strHour+":"+strMinute+":"+strSeconds
                    text:timeString
                    font.pixelSize:header.height*0.3
                    font.bold: false
                    elide: Label.ElideRight
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.fillWidth: true

                 }

                Label
                {
                    id:numOperators
                    text:"osób: "+vpersQty
                    font.pixelSize: header.height*0.3
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.fillWidth: true

                }



            }
            ColumnLayout
            {
                id:lineStatus
                spacing:10

                Label
                {
                    id:lineNr
                    text:"10032-13"
                    font.pixelSize: header.height*0.3
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
                    text:"5831"
                    font.pixelSize: header.height*0.2
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
                    text:vTargetPerHour+" szt./h"
                    font.pixelSize: header.height*0.2
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

                Row
                {
                    id:orderDataRL

                    spacing:40
                    Label
                    {
                        id:orderQty
                        text:vpartQty+" szt."
                        font.pixelSize: header.height*0.2
                        font.bold: false
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment:Qt.AlignRight
                        Layout.fillWidth:true
                    }

                    Label
                    {
                        id:timeElapsed
                        text:vtimeToProduce
                        font.pixelSize: header.height*0.2
                        font.bold: false
                        horizontalAlignment: Qt.AlignHCenter
                        verticalAlignment:Qt.AlignRight
                        Layout.fillWidth:true
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
                // temp
               /* RoundButton
                {
                   id:test
                   width: 40
                   height: 40
                   radius: 30
                   Material.background: Material.Brown

                   onClicked:
                   {
                       //chkList.getQuestions()
                       MyScripts.getShift()
                       chkList.show()

                   }


                }*/

                RoundButton
                {
                    id:statusChange
                    width: 40
                    height: 40
                    radius: 30
                    //Material.background: Material.Indigo
                    Material.background: Material.DeepOrange
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
                        //dlgPartNon.open()
                        //dlgPartN.open()
                        //orderD.resetSett()
                        previousPartNr=partNr.text
                        orderD.show()
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
