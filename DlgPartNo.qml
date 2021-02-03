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


    Material.theme: Material.System
    Material.foreground: Material.Orange
    Material.accent: Material.Orange
    Material.primary: Material.Orange

    function setQry()
    {
        qryModel.setQuery("Select partNr from targets")

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


           ColumnLayout
           {
             id:mainRect
             spacing: 20
             anchors.fill: parent




             ComboBox
             {
                 id:cmbR

                 Material.accent: Material.Orange
                 Layout.preferredWidth: 300
                 Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                 Layout.minimumWidth: 250

                 font.pixelSize: width/8
                 editable: true
                 model:qryModel

                 delegate: ItemDelegate
                 {
                     text:partNr
                     font.pixelSize:22
                     Material.foreground:Material.Indigo
                 }


             }

             Button
             {
                 id:mainButton

                 Material.background: "white"
                 Layout.alignment: Qt.AlignHCenter

                 Layout.minimumWidth: 100
                 Layout.preferredWidth: 110

                 text: "OK"

                 onClicked:
                 {
                    console.log(cmbR.currentText)
                    activated(cmbR.currentText)
                    close()
                 }
             }

           }




}
