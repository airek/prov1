import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.SqlQryModel 1.0
import "myJsScripts.js" as MyScripts
import com.BackendDbCon 1.0

ApplicationWindow {

    id: checkList
    title: wTitle
    flags: Qt.Dialog


    property string wTitle
    Material.theme: Material.System
    Material.foreground: Material.Indigo
    Material.accent: Material.BlueGrey
    Material.primary: Material.Orange

    property string actPartNr
    property string prevPartNr
    property string dtString

    SqlQryModel
    {
        id:qryModel

        objectName:
        {
            getQuestions()
        }

    }

    BackendCon
    {
        id:backendDbCon
    }

    function getQuestions()
    {
        var qry
        qry="Select id,question from checkListM order by id"
        console.log(qry)
        qryModel.setQuery(qry)
    }

    // insert
    function insertToCheckLog()
    {
        var logId,question,checkDate,checkTime
        var workerId,shiftNr
        var opt1,opt2,opt3
        var strQry

        var i

        opt1=0
        opt2=0
        opt3=0
        workerId=txtWorkerId.text
        console.log("worker Id "+workerId)
        //logId=MyScripts.getCurrentTimeInSeconds()+dtString
        checkDate=MyScripts.getDate()
        checkTime=MyScripts.getLocalTime()
        //workerId="3885"
        shiftNr=MyScripts.getShift()

        if(mSRadB1.checked===true)
            opt1=1
        else if(mSRadB2===true)
            opt2=1
        else
            opt3=1

        console.log("logId "+logId)

        strQry="insert into checkListLog (partNr,prevPartNr,dtString,question,"
        +"opt1,opt2,opt3,checkDate,checkTime,workerId,shiftNr) values"
        +"('"+actPartNr+"','"+prevPartNr+"','"+dtString+"','check Lista' "
        +","+opt1+","+opt2+","+opt3+",'"+checkDate+"','"+checkTime+"','"+workerId+"',"
        +shiftNr+")"

        //console.log("qry "+strQry)


        backend.execQry(strQry);



        opt1=1
        opt2=0
        opt3=0

        for(i = 0; i < qryModel.rowCount(); ++i) {

            question=qryModel.data(qryModel.index(i,1))

            strQry="insert into checkListLog (partNr,prevPartNr,dtString,question,"
            +"opt1,opt2,opt3,checkDate,checkTime,workerId,shiftNr) values "
            +"('"+actPartNr+"','"+prevPartNr+"','"+dtString+"','"+question+"' "
            +","+opt1+","+opt2+","+opt3+",'"+checkDate+"','"+checkTime+"','"+workerId+"',"
            +shiftNr+")"



            backend.execQry(strQry);


        }

        /*for(var child in qLst.contentItem.children) {
            var c = qLst.contentItem.children[child].item;
            if(typeof c !== "undefined")
                 console.log(c.answer)
            else
            {
                console.log("undefined")
            }
        }*/


    }

    Rectangle
    {
        id:mainRect
        anchors.fill: parent

        Rectangle
        {
            id:chkTitle
            anchors.top:parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10
            width: parent.width
            height: parent.height/7

            Text {
                id: chkTitleText
                text: qsTr("Check Lista Zmiana Artykułu")
                font.pixelSize: mainRect.width*0.03

                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle
        {
            id:mainSe
            width: mainRect.width
            height: mainRect.height/7

            anchors
            {
                top:chkTitle.bottom
                margins:30

            }


                Text {
                    id: mSArtD
                    text: qsTr("Artykuł:")
                    font.pixelSize: mainSe.width*0.02
                    anchors
                    {
                        left:mainSe.left
                        leftMargin:20
                    }

                }

                Text{
                    id:mSArt
                    text:actPartNr
                    font.pixelSize: mainSe.width*0.02
                    color: "blue"
                    anchors{

                       left:mSArtD.right
                    }
                }

                Text{
                    id:mSPartD
                    text:qsTr("Poprzedni Artykuł:")
                    font.pixelSize: mainSe.width*0.02

                    anchors{

                       left:mSArt.right
                       leftMargin: 15
                    }
                }

                Text{
                    id:mSPart
                    text:prevPartNr
                    font.pixelSize: mainSe.width*0.02
                    color: "blue"
                    anchors{

                       left:mSPartD.right
                    }
                }

                Text {
                    id: mSDateShift
                    text: dtString
                    font.pixelSize: mainSe.width*0.02
                    color:"orange"
                    anchors{

                       left:mSPart.right
                       leftMargin: 20
                    }

                }

                RadioButton {
                    id: mSRadB1
                    text: qsTr("Ze zmianą produktu")
                    anchors
                    {
                      left:mSDateShift.right
                      leftMargin:20
                    }
                }
                RadioButton {
                    id: mSRadB2
                    text: qsTr("Tylko zmiana opakowań")
                    anchors
                    {
                      left:mSRadB1.right
                      leftMargin:10
                    }
                }
                RadioButton {
                    id: mSRadB3
                    text: qsTr("Nie dotyczy")
                    anchors
                    {
                      left:mSRadB2.right
                      leftMargin:10
                    }
                }


            }

        ScrollView
        {
            id:scrollV

            width: mainRect.width
            height: mainRect.height/2
            clip: true
            anchors.top:mainSe.bottom

            ListView {
                id: qLst
                model: qryModel
                width: parent.width
                height: parent.height
                anchors.fill: parent


                delegate: Item {

                    x: 5
                    width: parent.width
                    height: 60

                    //anchors.horizontalCenter: parent.horizontalCenter

                    Row {
                        id: row1
                        spacing:20

                        Text
                        {
                            id:qst
                            text:question
                            font.pixelSize: 25

                        }

                        RadioButton {
                            id: rdYes
                            text: qsTr("TAK")

                        }
                        RadioButton {
                            id: rdNo
                            text: qsTr("NIE")

                        }
                        RadioButton {
                            id: rdNa
                            text: qsTr("Nie dotyczy")

                        }


                    }
                }


            }
        }
        TextField
        {
            id:txtWorkerId

            anchors
            {
                top: scrollV.bottom
                horizontalCenter: mainRect.horizontalCenter
                //left:searchButton.left
                topMargin:10
            }


            enabled: false

            placeholderText: "Numer osoby zatwierdzającej  "
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/2
            text:orderD.vTeam


        }

        Button
        {
            id:btSubmit
            anchors
            {
                top:txtWorkerId.bottom
                horizontalCenter:mainRect.horizontalCenter
            }
            text:qsTr("Zatwierdź")

            onClicked:
            {
                insertToCheckLog()
                close()
            }
        }


    }



}
