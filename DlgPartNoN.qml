import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.QryModel 1.0
//import com.SqlQryModel 1.0
//import QtQuick.Dialogs 1.2

Dialog {
    id: partNoDialog
    title: winTitle
    //modality:Qt.WindowModal

    signal activated(string partNo)
    property string winTitle
    property string number
    property string machineD


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
        qry="Select distinct(partNr) from targets where partNr like '"+txtField.text+"%'"
        console.log(qry)
        qryModel.setQuery(qry)

    }
    // searching machines
    /*function searchMachines()
    {
        var qry
        qry="select a.machineDesc,b.weight from machines a "
        +" inner join wght b "
        +" on a.machineId=b.machineId "
        +" where b.partNr='"+txtField.text+"'"
        console.log(qry)
        machinesQryModel.setQuery(qry)
        //qryModel.setQuery(qry)




    }*/

    function onActivated(number)
    {
        console.log("przekazany number "+number)
        searchForMachines(number)
        activated(number)
        close()

    }

    QryModel
    {

        id:qryModel
        Component.onCompleted:
        {
            console.log("start qry model")

        }
    }

    /*SqlQryModel
    {
        id:machinesQryModel
        Component.onCompleted:
        {
            console.log("start machines qry model")
            searchMachines()
        }

    }*/

    header:ToolBar
    {
        id:header


        height:partNoDialog.height/8

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
            placeholderText: "Meldowanie zlecenia "

            anchors.margins: 20
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/2

        }

        Button
        {
            id:searchButton
            anchors.top: mainR.top

            anchors.left: txtField.right
            anchors.leftMargin: 30
            width: 100

            text: "Szukaj"

            onClicked:
            {
                searchNumbers()
            }
        }


            ListView
            {
                id:partListView
                anchors
                {
                    top:txtField.bottom
                    topMargin:20

                    horizontalCenter:mainR.horizontalCenter

                }

                width: mainR.width/4
                height: mainR.height/2

                model: qryModel

                delegate: ItemDelegate
                {
                        //width: parent.width

                        text:partNr

                        font.pixelSize:parent.width*0.1
                        highlighted:partListView.currentIndex

                        onClicked:
                        {
                            console.log("part "+partNr)
                            //onActivated(partNr)
                            txtField.text=partNr

                        }

                }

            }

            Button
            {
                id:btAccept
                anchors.top: partListView.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 40


                width: 100

                text: "Zatwierdź"

                onClicked:
                {
                    activated(txtField.text)
                    close()
                }
            }




        ///
        /*Rectangle
        {
            id:tempRect
            anchors.top:partListView.bottom
            anchors.topMargin: 10

            visible: true

            width: mainR.width/2
            height: mainR.height/6
            anchors.horizontalCenter: mainR.horizontalCenter
            border.width: 1
            border.color: Qt.lighter("blue")
            radius: 10

            ListView
            {
                id:machinesLst
                anchors.fill: parent

                //model: machinesQryModel
                model:machinesQryModel

                delegate: ItemDelegate
                {

                        width: parent.width
                        Text
                        {
                            id:machine
                            anchors.left:parent.left
                            anchors.leftMargin: 20
                            width:parent.width/2

                            text:machineDesc
                            //a.machineDesc,b.weight
                            font.pixelSize:width*0.06
                        }

                        Text
                        {
                            id:wght
                            anchors.left:machine.right
                            anchors.leftMargin: 20
                            width:parent.width/2

                            text:weight
                            //a.machineDesc,b.weight
                            font.pixelSize:width*0.06
                        }




                        //highlighted:machinesLst.currentIndex



                }

            }

        }*/
    }



}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
