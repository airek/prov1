import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.SqlQryModel 1.0
import "myJsScripts.js" as MyScripts

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

    function getQuestions()
    {
        var qry
        qry="Select id,question from checkListM order by id"
        console.log(qry)
        qryModel.setQuery(qry)
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
            height: 350
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

        Button
        {
            id:btSubmit
            anchors
            {
                top:scrollV.bottom
                horizontalCenter:mainRect.horizontalCenter
            }
            text:qsTr("Zatwierdź")
        }


    }



    /*ScrollView {
        id: scrollView
        anchors.fill: parent
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10

        ColumnLayout
        {
            id:mColumn
            spacing: 20
            anchors.fill: parent

            // main Label

            Label {
                id: lblCheckLista
                text: qsTr("Check Lista Zmiana Artykułu")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Layout.fillHeight: false
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                font.pointSize: checkList.width*0.02
            }


            Row
            {
                id:mSenR
                spacing: 20

                Label {
                    id: lblArt
                    text: qsTr("Artykuł:")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    font.pointSize: 16
                }

                Label {
                    id: lblPartNr
                    text: qsTr("96427")
                    font.pointSize: 16
                }

                Label {
                    id: lblPreviousA
                    text: qsTr("Poprzedni artykuł:")
                    font.pointSize: 16
                }

                Label {
                    id: lblPreviousArt
                    text: qsTr("96245")
                    font.pointSize: 16
                }

                Label {
                    id: lblDate
                    text: qsTr("2021-06-10")

                    font.pointSize: 16
                }

                Label {
                    id: lblShift
                    text: qsTr("2")
                    font.pointSize: 16
                }

                Label {
                    id: lblLine
                    text: qsTr("10245-13")

                    wrapMode: Text.WordWrap
                    font.pointSize: 16
                }

                RadioButton {
                    id: radioButton
                    text: qsTr("Ze zmianą produktu")
                    font.pointSize: 12
                }

                RadioButton {
                    id: radioButton1
                    text: qsTr("tylko zmiana opakowań")
                    font.pointSize: 12

                }

                RadioButton {
                    id: radioButton2
                    text: qsTr("Nie dotyczy")
                    font.pointSize: 12
                }


            }
        }



    }*/


}
