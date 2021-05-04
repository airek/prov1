import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2
import com.SqlQryModel 1.0
import com.BackendDbCon 1.0
import "myJsScripts.js" as MyScripts


ApplicationWindow {

    id: orderDialog
    title: winTitle
    flags: Qt.Dialog


    signal activated(string partNo)
    property string winTitle
    /*property string number
    property string machineD*/


    Material.theme: Material.System
    Material.foreground: Material.Indigo
    Material.accent: Material.BlueGrey
    Material.primary: Material.Orange





    //Dlg Part Number
    DlgPartNoN
    {
        id:dlgPartNon
        modal: true
        focus: true
        winTitle: "Szukaj numeru"

        x: (orderDialog.width - width)/2
        //x:appWindow.x+10
        y: orderDialog.y-header.height
        width: Math.min(appWindow.width, appWindow.height) / 2 * 2
        height: 400

       // width: appWindow.width-40
       // height: appWindow.height-20

        onActivated:
        {
            console.log("Part "+partNo)

            txtFPartNr.text=partNo
            searchForMachines()
            getPartData()

        }

    }


    SqlQryModel
    {
        id:qryModel

        Component.onCompleted:
        {
            searchForMachines()
        }

    }

    BackendCon
    {
        id:backendDbCon
    }

    //javascript

    function calculateTitleFont()
    {

        var fontSize=Math.min(orderDialog.width,orderDialog.height)*0.07

        return fontSize
    }
    //
    function calculateFont()
    {

        var fontSize=Math.min(orderDialog.width,orderDialog.height)*0.03

        return fontSize
    }

    function searchForMachines()
    {
        var qry
        qry="select a.machineDesc,b.weight from machines a "
        +" inner join wght b "
        +" on a.machineId=b.machineId "
        +" where b.partNr='"+txtFPartNr.text+"'"
        console.log(qry)
        qryModel.setQuery(qry)
    }
    function getPartData()
    {
        var qry
        var res
        var data
        var toSplit
        var shiftFactor
        var hourTarget
        var shiftTarget
        var timeToProduce
        var tactTime
        var partQty


        // Sql Server version
        qry="select shiftTarget,numPersons from targets "
            +" where partnr='"+txtFPartNr.text+"'"

        // sqlite version
        /*qry="select shiftTarget,numOperators from targets "
                    +" where partnr='"+txtFPartNr.text+"'"*/
        console.log(qry)

        res=backendDbCon.getDbData(",",qry)
        toSplit=res[0]

        data=toSplit.split(",")

        shiftFactor=backendDbCon.getSHiftFactor();

        lblShiftTarget.text="Cel na zmianę "+data[0]+" szt."
        spnPersQty.value=data[1]

        // calculating hourTarget
        shiftTarget=data[0]
        hourTarget=parseInt(shiftTarget)/shiftFactor

        lblHourTarget.text="Cel na godzinę "+parseInt(hourTarget)+" szt."

        // tact time
        tactTime=3600/hourTarget
        console.log("tact "+tactTime)

        // getting part Qty
        partQty=spnQty.value
        console.log("part Qty "+partQty)

        // time to produce
        timeToProduce=partQty*tactTime

        timeToProduce=parseInt(timeToProduce)
        console.log("time to produce "+timeToProduce)
        var ttime=MyScripts.secondstotime(timeToProduce)
                //MyScripts.secondstotime(ttime)
                //MyScripts.toTimeString(timeToProduce)
        console.log("time "+ttime)
        lblTimeToProduce.text="Szacowany czas "+ttime


    }

    // person calculation
    function calculatePersQty(wght,action)
    {
        var result=0
        var personQ=parseInt(spnPersQty.value)
        console.log("res "+result+" personQ "+personQ+"wght "+wght)

        if(action==="minus")
           {
            result=personQ-parseInt(wght)
           }
        else if(action==="plus")
        {
            result=personQ+parseInt(wght)
        }

        console.log("result "+result)
        spnPersQty.value=result



    }


    // reset
    function resetSett()
    {
        txtFPartNr.clear()
    }

    // header
    header:ToolBar
    {
        id:header

        height:orderDialog.height/8

        RowLayout {
            id: rLayout

            anchors.horizontalCenter: parent.horizontalCenter
            Layout.topMargin: 40
            spacing: 40

            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Label {


                width: rLayout.width
                text: winTitle
                wrapMode: Label.Wrap
                font.pixelSize:calculateTitleFont()


            }
        }


    }

    //Main Rectangle

    Rectangle
    {
        id:mainRect
        anchors.fill: parent
        anchors.rightMargin: -6
        anchors.bottomMargin: 0
        anchors.leftMargin: 6
        anchors.topMargin: 0


        Button
        {
            id:searchButton

            anchors
            {
                top:mainRect.top
                topMargin:20
                left:btAccept.right
                leftMargin:20

            }

            onClicked:
            {
                dlgPartNon.open()
            }


            width: 100

            text: "Wyszukaj"

        }

        // txt for partNr
        TextField
        {
            id:txtFPartNr

            anchors
            {
                top: mainRect.top
                horizontalCenter: parent.horizontalCenter
                //left:searchButton.left
                topMargin:20
            }


            placeholderText: "Numer zlecenia  "
            horizontalAlignment: Text.AlignHCenter
            width: parent.width/2


        }

        ListView {
            id: machineLst
            width: parent.width/2
            height: parent.height/6
            anchors.top: txtFPartNr.bottom
            anchors.horizontalCenterOffset: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
            model: qryModel
            delegate: Item {
                x: 5
                width: 70
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter

                Row {
                    id: row1
                    spacing: 50
                    Text
                    {
                        id:machine
                        /*anchors.left:parent.left
                        anchors.leftMargin: 20*/
                        //width:parent.width/2

                        text:machineDesc
                        //a.machineDesc,b.weight
                        //font.pixelSize:width*0.06
                        font.pixelSize: calculateFont()

                    }

                    Text
                    {
                        id:wght
                        /*anchors.left:machine.right
                        anchors.leftMargin: 30*/
                        //width:parent.width/2

                        text:weight
                        //a.machineDesc,b.weight
                        font.pixelSize:calculateFont()
                        color: "orange"
                    }

                    CheckBox
                    {
                        id:chKweight
                        checked: false

                        onCheckStateChanged:
                        {
                            if(checkState==Qt.Checked)
                                calculatePersQty(wght.text,"minus")
                            else if(checkState==Qt.Unchecked)
                                calculatePersQty(wght.text,"plus")


                        }

                    }


                   /*Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }*/

                }
            }


            /*model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }*/
        }

        CheckBox {
            id: chkLine
            text: qsTr("Niepełna linka")
            font.pixelSize: calculateFont()
            anchors.top: machineLst.bottom

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20

            onCheckStateChanged:
            {
                if(chkLine.checked)
                {
                    spnPersQty.enabled=true
                    spnPersQty.editable=true
                }else
                {
                    spnPersQty.enabled=false
                    spnPersQty.editable=false
                }
            }
        }

        Label {
            id: lblQty
            text: qsTr("Ilość sztuk")
            font.pixelSize: calculateFont()
            anchors.top: chkLine.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignBottom
            anchors.horizontalCenterOffset: -20

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
        }

        SpinBox {
            id: spnQty
            y: 230
            anchors.left: lblQty.right
            anchors.leftMargin: 10
            anchors.top: chkLine.bottom
            editable: true
            to: 99999
            from: 1
            value: 1000
            anchors.topMargin: 10
            font.pixelSize: Math.min(orderDialog.width,orderDialog.height)*0.03
        }

        Label {
            id: lblPersonQty
            text: qsTr("Ilość osób")
            anchors.top: lblQty.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignBottom
            anchors.horizontalCenterOffset: -20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 50
            font.pixelSize: calculateFont()
        }

        SpinBox {
            id: spnPersQty
            anchors.left: lblPersonQty.right
            anchors.top: spnQty.bottom
            enabled: false
            to: 35
            from: 1
            value: 1
            anchors.leftMargin: 10
            anchors.topMargin: 30
            font.pixelSize: Math.min(orderDialog.width,orderDialog.height)*0.03
        }

        Label {
            id: lblShiftTarget
            text: qsTr("Cel na zmianę 0 szt.")
            anchors.left: parent.left
            anchors.top: spnPersQty.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: 10
            anchors.topMargin: 40
            width: parent.width/3

            font.pixelSize: calculateFont()
        }

        Label {
            id: lblHourTarget
            text: qsTr("Cel na godzinę 0 szt.")
            anchors.left: lblShiftTarget.right
            anchors.top: spnPersQty.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: 10
            anchors.topMargin: 40
            width: parent.width/3
            font.pixelSize: calculateFont()
        }

        Label {
            id: lblTimeToProduce
            text: qsTr("Czas wykonania 00:00:00")
            anchors.left: lblHourTarget.right
            anchors.top: spnPersQty.bottom
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: 10
            anchors.topMargin: 40
            width: parent.width/3
            font.pixelSize: calculateFont()
        }

        Button {
            id: btSubmit

            text: qsTr("OK")
            anchors.top: lblHourTarget.bottom
            display: AbstractButton.TextOnly
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
            width: 200


        }

        Button {
            id: btAccept
            text: qsTr("Zatwierdź")
            anchors.left: txtFPartNr.right
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.leftMargin: 20

            onClicked:
            {
                searchForMachines()
                getPartData()
            }
        }


    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
