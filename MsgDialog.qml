import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2

Dialog {
    id: msgDialog
    title: winTitle
    standardButtons: Dialog.Ok

    property string winTitle
    property string info
    property string infot

    Material.theme: Material.Dark
    Material.accent: Material.Teal

    opacity: 0.9


    header:ToolBar
    {
        id:header
        Material.foreground:Material.Indigo

        Material.primary:"white"
        height:msgDialog.height/7

        RowLayout {
            id: layout

             anchors.horizontalCenter: parent.horizontalCenter
             spacing: 10
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
             Label {
                  Material.foreground: "#00a987"

                  width: msgDialog.width
                  text: winTitle
                  wrapMode: Label.Wrap
                  font.pixelSize:Math.min(msgDialog.width,msgDialog.height)*0.07
                  opacity:0.7
                  font.bold: true
              }
        }


    }

           Label {
                Material.foreground: "white"


                Material.background: Material.Grey
                width: msgDialog.width
                text: info
                wrapMode: Label.Wrap
                font.pixelSize:Math.min(msgDialog.width,msgDialog.height)*0.1
                font.bold: true
            }






}
