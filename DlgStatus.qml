import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2

Dialog {
    id: msgDialog
    title: winTitle

    signal activated(int index)
    property string winTitle
    property string info
    property string infot

    Material.theme: Material.System
    Material.foreground: Material.Orange
    Material.accent: Material.Orange
    Material.primary: Material.Orange


    header:ToolBar
    {
        id:header


        height:msgDialog.height/7

        RowLayout {
            id: layout

             anchors.horizontalCenter: parent.horizontalCenter
             spacing: 10
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
             Label {


                  width: msgDialog.width
                  text: winTitle
                  wrapMode: Label.Wrap
                  font.pixelSize:Math.min(msgDialog.width,msgDialog.height)*0.07
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


                 model: ListModel
                 {
                     id:model

                     ListElement
                     {
                      text:"AWARIA"
                     }
                     ListElement
                     {
                      text:"PRZERWA"
                     }
                     ListElement
                     {
                      text:"ZMIANA ZLECENIA"
                     }
                     ListElement
                     {
                      text:"KONIEC ZLECENIA"
                     }
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
                     if(cmbR.currentText==="AWARIA")
                     {
                         activated(1)
                     }else if(cmbR.currentText==="PRZERWA")
                     {
                         activated(2)
                     }else if(cmbR.currentText==="ZMIANA ZLECENIA")
                     {
                         activated(3)
                     }else
                     {
                         activated(4)
                     }

                     close()
                 }
             }

           }




}
