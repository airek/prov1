import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.3
import QtQuick.Extras 1.4
//import com.Backend 1.0
import com.BackendDbCon 1.0

import "myJsScripts.js" as MyScripts

Item
{
    id:root
    Material.theme: Material.Light
    Material.accent: Material.DeepOrange
    Material.foreground: Material.Blue
    Material.primary: Material.BlueGrey

    Component.onCompleted:
    {
        var serverStatus=backend.getServerStatus();
        devName.text=backend.getDevName();
        serverPortNr.text=backend.getPortNr();
        serverIp.text=backend.getIpAddr();

        if(serverStatus)
        {
            toggBt.checked=true
            toggBt.text="On"
        }else
        {
            toggBt.checked=false
            toggBt.text="Off"
        }
    }

    BackendCon
    {
        id:backend
    }

    function createComModel()
    {
        var model=[];
        var i
        var data

        for(i=1;i<50;i++)
        {
            if(i<11)
            {
                data="COM"+i
            }else
            {
                data="\\\\.\\COM"+i
            }

            model.push(data)

        }


        return model
    }

    // validating form
    // validating form
    function validateForm()
    {
        var devicename=devName.text
        var IpA=serverIp.text
        var portNr=serverPortNr.text
        var isValidate=false
        var ipformat = /^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/;
        if(devicename.length<3)
        {

            msgD.winTitle="Validation error "
            msgD.info="Nazwa serwera musi mieć minimum trzy znaki"
            devName.focus=true

            msgD.open()

        }else if(!IpA.match(ipformat))
        {
            msgD.winTitle="Validation error "
            msgD.info="To nie jest prawidłowy adres IP"
            serverIp.focus=true

            msgD.open()

        }else if(portNr.length<1)
        {
            msgD.winTitle="Validation error "
            msgD.info="Numer portu jest za krótki"
            serverPortNr.focus=true

            msgD.open()
        }else
        {
            isValidate=true
        }

        return isValidate



    }


    // connecting with server
    function createServer()
    {
        var IPServer;
        var portNr;
        var serverName;
        // checking if is already listening
        var isListening;
        var line=backend.getLine();
        console.log("line "+line)
        IPServer=serverIp.text;
        console.log("Server IP "+IPServer);
        portNr=serverPortNr.text;

        serverName=devName.text;



            if(!backend.listen(serverName,IPServer,portNr))
            {
                console.log("backend zwrócił false");
                isListening=false

            }else
            {
                console.log("backend zwrócił true");
                isListening=true
            }

        return isListening


    }

    function updateServerSettings()
    {
        var IPServer;
        var portNr;
        var serverName;
        var line=backend.getLine();

        var qry="update devices set ipAddr='"+serverIp.text+"',portNr="+serverPortNr.text+
                ",devName='"+devName.text+"' where line='"+line+"'"

        console.log("qry "+qry)

        //
        if(backend.execQry(qry))
        {
            console.log("dane zaktualizowane ")
            stackView.pop()
        }
        else
            console.log("Coś nie zadziałało ")

    }

    MsgDialog
    {

        id:msgD

        modal: true
        focus: true
        winTitle: "Validation error"

        x: (scrView.width - width) / 2
        y: scrView.height / 6
        width: Math.min(scrView.width, scrView.height) / 2 * 2
        height: 200


     }
    states:State {
        name: "localHostiVi"
        PropertyChanges {
            target: localHostInfo
            opacity:1.0
        }
    }
    transitions: [
        Transition {
            NumberAnimation
            {
                duration: 2000
                property: "opacity"
            }
     }
    ]


ScrollView
{
    id:scrView
    anchors.fill: parent
    clip: true

    OpacityAnimator on opacity{
        id:opacityAnim
        from: 1.0
        to: 0.0
        duration:2000
        target: localHostInfo
        running:false
    }
    OpacityAnimator on opacity{
        id:opacityanimV
        from: 0.0
        to: 1.0
        duration:2000
        target: localHostInfo
        running:false
    }

    RowLayout {
        id: layout

         anchors.horizontalCenter: parent.horizontalCenter
         spacing: 6
        //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label
        {
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.margins: 5
            font.pixelSize: 22
            text:"Nazwa urządzenia"
        }

        TextField
        {
            id:devName
            Layout.alignment: Qt.AlignRight
            Layout.margins: 40
            font.pixelSize: 22

            placeholderText: "Enter name"
            focus: true
        }

        RoundButton
        {
            id:roundB
            Layout.margins: 10

            text: qsTr("Update")

            onClicked:
            {
                updateServerSettings()


            }
        }
    }

    RowLayout {
        id: infolayout

         anchors.horizontalCenter: parent.horizontalCenter
         anchors.top: layout.bottom
         spacing: 6
        //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label
        {
            Material.foreground: Material.BlueGray
            id:localHostInfo
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.margins: 5
            font.pixelSize: 22
            text:qsTr("Nasłuchuje na 127.0.0.1 port 6101")
            opacity: 0




        }




    }

   ColumnLayout
    {
        id:colL
        anchors.top:infolayout.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        GroupBox
        {
            id:grpbox
            title: qsTr("Settings")

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumWidth: 600
            //
            ColumnLayout
            {
                id:cmbLa
                anchors.fill:parent

                // Ip addr
                RowLayout
                {
                    id:rowLIpSer

                Label
                {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 50
                    Layout.margins: 5
                    font.pixelSize: 22
                    text:"Server IP"
                }

                TextField
                {
                    id:serverIp
                    Layout.alignment: Qt.AlignRight
                    Layout.margins: 10
                    font.pixelSize: 22
                    Layout.minimumWidth: 150
                    validator:RegExpValidator{regExp: /\d{1,3}(?:.\d{1,3})+$/}

                    placeholderText: "Enter IP"
                    focus: true
                }
                }

                // port nr
                RowLayout
                {
                    id:rowLPortNrSer

                Label
                {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 50
                    Layout.margins: 5
                    font.pixelSize: 22
                    text:"Port Nr"
                }

                TextField
                {
                    id:serverPortNr
                    Layout.alignment: Qt.AlignRight
                    Layout.margins: 10
                    font.pixelSize: 22
                    Layout.minimumWidth: 150
                    validator:RegExpValidator{regExp: /\d{1,3}(?:.\d{1,3})+$/}

                    placeholderText: "Port Nr"
                    focus: true
                }

                }
                //RowLayout


                    ToggleButton
                    {
                        id:toggBt


                        Layout.alignment: Qt.AlignHCenter


                        checked: false
                        text:"Off"
                        onClicked:
                        {


                            if(validateForm())
                            {
                                if(toggBt.text==="Off")
                                {

                                     if(createServer())
                                     {
                                         console.log("server created")
                                         text="On";
                                         checked=true;
                                     }else
                                     {
                                         text="Off";
                                         checked=false;
                                     }


                                     /*if(serverIp.text.length===0)
                                     {
                                         opacityanimV.running=true
                                     }*/

                                }else
                                {
                                    toggBt.text="Off"
                                    toggBt.checked=false
                                }
                            }else
                            {
                                toggBt.text="Off"
                                toggBt.checked=false
                            }



                        }
                    }







            }

        }


        // here listView

    }

    }


}





