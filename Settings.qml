import QtQuick 2.6
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.BackendDbCon 1.0

Flickable {
    id: flickable

    contentHeight: pane.height

    Material.theme: Material.Light
    Material.accent: Material.DeepOrange
    Material.foreground: Material.Indigo
    Material.primary: Material.BlueGrey

    property bool ackS;



    BackendCon
    {
        id:backend
    }

    // javascript
    function execQry()
    {
        var qry;
        var isSwitch;

        if(ackSwitch.checked==true)
            isSwitch='true'
        else
            isSwitch='false'

        qry="update settings set signal='"+txtSignal.text+"',shiftFactor="+txtShFactor.text+
            ",midVal="+txtYellow.text+",maxVal="+txtGreen.text+
            ",ackSignal='"+isSwitch+"',fshift="+txtFirstShft.text+
            ",sshift="+txtSecondShft.text+",tshift="+txtthirdShft.text+" where id=1"

        console.log("qry "+qry)

        if(backend.execQry(qry))
        {
            console.log("Wprowadzono")
            stackView.pop()
        }
        else
            console.log("Nie wprowadzono")

    }

    Component.onCompleted:
    {

        txtGreen.text=backend.getMaxVal()
        txtYellow.text=backend.getMidVal()
        txtShFactor.text=backend.getSHiftFactor()
        txtSignal.text=backend.getSignal()
        txtFirstShft.text=backend.getEFShift()
        txtSecondShft.text=backend.getESShift()
        txtthirdShft.text=backend.getETShift()
        ackS=backend.getAckSignal()

        if(ackS===true)
            ackSwitch.checked=true
        else
            ackSwitch.checked=false
    }

    Pane {
        id: pane
        width: flickable.width
        height: flickable.height * 1.6

        Column {
            id: column
            spacing: 40
            width: parent.width


            GroupBox
            {
                id:grpbox
                title: qsTr("Sygnał")

                anchors.horizontalCenter: parent.horizontalCenter
                //anchors.top: parent.top

                width: parent.width*0.5
                ColumnLayout
                {
                    id:cmbLa
                    anchors.fill:parent

                    //
                    RowLayout
                    {
                        id:rowLSignal

                        Label
                        {
                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Sygnał zaliczenia"
                        }

                        TextField
                        {
                            id:txtSignal

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"

                            placeholderText: "Wprowadź sygnał"
                            focus: true
                        }
                    }

                    //
                    RowLayout
                    {
                        id:rowAck

                        Switch
                        {
                            id:ackSwitch
                            text:qsTr("Potwierdzenie sygnału")
                            Layout.alignment: Qt.AlignRight

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                        }

                    }

                    RowLayout
                    {
                        id:rowLShFactor

                        Label
                        {
                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Faktor zmiany"
                        }

                        TextField
                        {
                            id:txtShFactor

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"

                            placeholderText: "Wprowadź faktor"
                            focus: true
                        }
                    }


                }

            }
            GroupBox
            {
                id:grpThreads
                title: qsTr("Progi")

                anchors.top:grpbox.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width*0.5

                ColumnLayout
                {
                    id:grpThreadsL
                    anchors.fill: parent
                    spacing: 10

                    RowLayout
                    {
                        id:rowLGreen

                        Label
                        {

                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Kolor zielony powyżej"
                        }

                        TextField
                        {
                            id:txtGreen

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"
                            placeholderText: "Wprowadź próg"
                            focus: true
                        }

                    }

                    //yellow
                    RowLayout
                    {
                        id:rowLYellow

                        Label
                        {

                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Kolor żółty powyżej"
                        }

                        TextField
                        {
                            id:txtYellow

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"
                            placeholderText: "Wprowadź próg"
                            focus: true
                        }

                    }




                }

            }

            // Shifts
            // first shift
            GroupBox
            {
                id:grpShifts
                title: qsTr("Zmiany")
                anchors.top:grpThreads.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width*0.5


                ColumnLayout
                {
                    id:grpShiftsL
                    anchors.fill: parent
                    spacing: 10

                    RowLayout
                    {
                        id:rowLfirstShft
                        Label
                        {

                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Koniec zmiany pierwszej"
                        }

                        TextField
                        {
                            id:txtFirstShft

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"
                            placeholderText: "Wprowadź godzinę"
                            focus: true
                        }

                    }

                    //second shift
                    RowLayout
                    {
                        id:rowLSecondShft

                        Label
                        {

                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Koniec zmiany drugiej"
                        }

                        TextField
                        {
                            id:txtSecondShft

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"
                            placeholderText: "Wprowadź godzinę "
                            focus: true
                        }

                    }

                    //

                    //thirdshift
                    RowLayout
                    {
                        id:rowLThirdShft


                        Label
                        {

                            Layout.fillWidth: true
                            Layout.minimumWidth: 200
                            Layout.margins: 5
                            font.pixelSize: 22
                            text:"Koniec zmiany trzeciej"
                        }

                        TextField
                        {
                            id:txtthirdShft

                            Layout.margins: 10
                            font.pixelSize: 22
                            Layout.minimumWidth: 200
                            horizontalAlignment: "AlignHCenter"
                            placeholderText: "Wprowadź godzinę "
                            focus: true
                        }

                    }




                }

            }

            //second shift
            Row
            {
                id:rowLButtons
                spacing: 20
                anchors.top: grpShifts.bottom
                anchors.horizontalCenter: parent.horizontalCenter

                anchors.margins:20


                Button
                {
                    id:buttonOK
                    Layout.minimumWidth: 280
                    Layout.fillWidth: true
                    Layout.margins: 5
                    font.pixelSize: 22
                    text:"OK"
                    onClicked: execQry()


                }



            }


        }
    }

    ScrollBar.vertical: ScrollBar { }
}
