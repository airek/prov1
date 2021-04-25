import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.QryModel 1.0

Dialog {
    id: partNoDialog
    title: winTitle

    signal activated(string partNo)
    property string winTitle
    property string number


    Material.theme: Material.System
    Material.foreground: Material.Orange
    Material.accent: Material.Orange
    Material.primary: Material.Orange

    Component.onCompleted:
    {
        TextField.text=""
    }

    function setQry()
    {
        //qryModel.setQuery("Select partNr from targets")

    }
    function searchNumbers()
    {
        var qry
        qry="Select partNr from targets where partNr like '"+txtField.text+"%'"
        console.log(qry)
        qryModel.setQuery(qry)

    }

    function onActivated(number)
    {
        console.log("przekazany number "+number)
        activated(number)
        close()

    }

    QryModel
    {

        id:qryModel
        Component.onCompleted:
        {
            console.log("start qry model")
            //setQry()
        }
    }

    header:ToolBar
    {
        id:header


        height:partNoDialog.height/7

        RowLayout {
            id: layout

             anchors.horizontalCenter: parent.horizontalCenter
             spacing: 10
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
             Label {


                  width: partNoDialog.width
                  text: winTitle
                  wrapMode: Label.Wrap
                  font.pixelSize:Math.min(partNoDialog.width,partNoDialog.height)*0.07
                  opacity:0.7
                  font.bold: true
              }
        }


    }

    Rectangle
    {

        id:mainR

        anchors.fill: parent

        TextField
        {
            id:txtField
            anchors.top: mainR.top
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "Wpisz szukany numer"
            anchors.margins: 20
            width: parent.width/2

        }

        Button
        {
            id:searchButton
            anchors.top: mainR.top
            anchors.left: txtField.right
            anchors.leftMargin: 30


            text: "Szukaj"

            onClicked:
            {
                searchNumbers()
            }
        }

        ListView
        {
            id:partListView
            anchors.top: txtField.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: mainR.horizontalCenter
            width: mainR.width/2
            height: mainR.height/3



            model: qryModel

            delegate: ItemDelegate
            {
                    //width: parent.width
                    text:partNr
                    font.pixelSize:14
                    highlighted:partListView.currentIndex

                    onClicked:
                    {
                        console.log("part "+partNr)
                        onActivated(partNr)
                    }

            }

        }
    }



}

