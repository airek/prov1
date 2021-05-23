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
    property int shiftTarget
    property int hourTarget
    property int packaging
    property double shiftFact
    property string ttProduce

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
            getPackaging()
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
    function getPackaging()
    {
        var qry
        var pack
        var res
        var ts
        var data


        qry="select packaging from partNumbers where partnr='"+txtFPartNr.text+"'"
        res=backendDbCon.getDbData(",",qry)
        //console.log("qry  get packaging "+qry)
        ts=res[0]

        //
        data=ts.split(",")
        packaging=data[0]


        //console.log("pack "+packaging)



    }

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
        var timeToProduce
        var tactTime
        var partQty
        var shiftTargetVE

        // Sql Server version
        qry="select shiftTarget,numPersons from targets "
            +" where partnr='"+txtFPartNr.text+"' and baseVal=1"

        // sqlite version
        /*qry="select shiftTarget,numOperators from targets "
                    +" where partnr='"+txtFPartNr.text+"' "*/
        console.log(qry)

        res=backendDbCon.getDbData(",",qry)
        toSplit=res[0]
        data=toSplit.split(",")
        shiftFactor=backendDbCon.getSHiftFactor();
        shiftFact=shiftFactor

        //console.log("shFactor "+shiftFactor)
        // calculating hourTarget
        shiftTargetVE=data[0]
        shiftTarget=shiftTargetVE*packaging
        // setting orderQty
        spnQty.value=shiftTarget
        //console.log("shiftTarget VE "+shiftTargetVE+" packaging "+packaging+"shiftTarget "+shiftTarget)
        lblShiftTarget.text="Cel na zmianę "+shiftTarget+" szt."

        spnPersQty.value=parseInt(data[1])

        hourTarget=shiftTarget/shiftFactor

        lblHourTarget.text="Cel na godzinę "+hourTarget+" szt."

        estimateTimetoProduce()
        /*// tact time
        tactTime=3600/hourTarget
        //console.log("tact "+tactTime)

        // getting part Qty
        partQty=spnQty.value
        //console.log("part Qty "+partQty)

        // time to produce
        timeToProduce=partQty*tactTime

        timeToProduce=parseInt(timeToProduce)
        //console.log("time to produce "+timeToProduce)
        var ttime=MyScripts.secondstotime(timeToProduce)

        //console.log("time "+ttime)
        ttProduce=ttime
        lblTimeToProduce.text="Szacowany czas "+ttProduce*/


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
        lblShiftTarget.text="Cel na zmianę 0 szt."
        lblHourTarget.text="Cel na godzinę 0 szt."
        lblTimeToProduce.text="Szacowany czas 00:00:00"
        spnPersQty.value=0
        spnQty.value=1000
        qryModel.clearModel()


    }

    function getTargetwv()
    {
        var res
        var qry
        var numP=spnPersQty.value
        var data
        var toSplit
        var shiftTargetVE


        qry="Select shiftTarget from targets where partNr='"+txtFPartNr.text+"'"
        +" and numPersons="+numP+""

        console.log("getNrPers "+qry)

        res=backendDbCon.getDbData(",",qry)

        console.log(res)
        toSplit=res[0]
        data=toSplit.split(",")

        shiftTargetVE=data[0]
        console.log("shiftTarget "+shiftTargetVE)

        shiftTarget=shiftTargetVE*packaging
        spnQty.value=shiftTarget

        lblShiftTarget.text="Cel na zmianę "+shiftTarget+" szt."

        //
        //calculating hour T
        hourTarget=shiftTarget/shiftFact
        lblHourTarget.text="Cel na godzinę "+hourTarget+" szt."

        estimateTimetoProduce()


    }

    function estimateTimetoProduce()
    {
        var qty
        var tactTime
        var timeToProduce
        var partQty


        // tact time
        tactTime=3600/hourTarget
        //console.log("tact "+tactTime)

        // getting part Qty
        partQty=spnQty.value
        //console.log("part Qty "+partQty)

        // time to produce
        timeToProduce=partQty*tactTime

        timeToProduce=parseInt(timeToProduce)
        console.log("time to produce "+timeToProduce)
        var ttime=MyScripts.secondstotime(timeToProduce)
        ttProduce=ttime
        console.log("time "+ttProduce)
        lblTimeToProduce.text="Szacowany czas "+ttProduce

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
                            {
                                calculatePersQty(wght.text,"minus")
                                getTargetwv()
                            }
                            else if(checkState==Qt.Unchecked)
                            {
                                calculatePersQty(wght.text,"plus")
                                getTargetwv()
                            }


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
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: machineLst.bottom

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
            anchors.topMargin: 40
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
            anchors.topMargin: 20
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

            onClicked:
            {


               vpersQty=spnPersQty.value
               vpartQty=spnQty.value
               console.log("part Qty "+vpartQty)
               vtimeToProduce=ttProduce
               vTargetPerHour=hourTarget


               //timeElapsed.text=lblTimeToProduce.text
               activated(txtFPartNr.text)
               close()
            }


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
                getPackaging()
                getPartData()
                //estimateTimetoProduce()
            }
        }


    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
