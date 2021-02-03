import QtQuick 2.0

Item {
    id:root
    property string hourCntr;
    property string shiftCounter;
    property string hrTargetText;
    property string shTargetText;

    property string shTargetColorD;
    property string shTargetColorU;
    property string hrTargetColorD
    property string hrTargetColorU

    property int minVal;
    property int midVal;
    property int maxVal;



    hrTargetColorD: "#fffd60"
    hrTargetColorU: "#fffc0b"

    shTargetColorD: "#52ef4e"
    shTargetColorU: "#05c400"

    //javascript
    function calculateHourColor()
    {
        var hrRatio=(hourCntr/hrTargetText)*100
        //console.log("hr ratio "+hrRatio)


        if(hrRatio>=maxVal)
        {
            hrTargetColorD="#52ef4e"
            hrTargetColorU="#05c400"

        }else if(hrRatio<maxVal && hrRatio>=midVal)
        {
            hrTargetColorD="#fffd60"
            hrTargetColorU="#fffc0b"
        }else
        {
            hrTargetColorD="#ff3636"
            hrTargetColorU="#f81818"
        }
    }

    //calculating shiftColor
    function calculateShiftColor()
    {
        var shRatio=(shiftCounter/shTargetText)*100
        //console.log("sh ratio "+shRatio)

        if(shRatio>=maxVal)
        {

            shTargetColorD="#52ef4e"
            shTargetColorU="#05c400"
        }else if(shRatio<maxVal && shRatio>=midVal)
        {
            shTargetColorD="#fffd60"
            shTargetColorU="#fffc0b"
        }else
        {
            shTargetColorD="#ff3636"
            shTargetColorU="#f81818"
        }
    }



    // target per hour
    Rectangle
    {
        id:hourTarget
        anchors
        {
            top:parent.top
            left:root.left

        }
        radius: 10
        border.width: 2
        border.color: "#2f2727"
        height: root.height/2
        width: root.width/2
        gradient: Gradient
        {
            GradientStop{

                position:0
                color: "#777373"
            }
            GradientStop
            {
                position: 1
                color: "#171515"
            }
        }
        Text {
            id: hrTitle
            text: qsTr("Cel na godzinę")
            anchors
            {
                top:parent.top
                horizontalCenter:parent.horizontalCenter
                topMargin:10
            }

            font.pixelSize: 24
            color: "white"
        }
        Text {
            id: hrTarget
            text: hrTargetText
            anchors
            {

                verticalCenter:hourTarget.verticalCenter
                horizontalCenter:hourTarget.horizontalCenter
                topMargin:10

            }

            font.pixelSize: root.height/3
            font.bold: true
            color:"white"

            onTextChanged:
            {
                calculateHourColor()
            }
        }
    }


    // target per shift
    Rectangle
    {
        id:shiftTarget
        anchors
        {
            top:hourTarget.bottom
            left:root.left

        }
        radius: 10
        border.width: 2
        border.color: "#2f2727"
        height: root.height/2
        width: root.width/2
        gradient: Gradient
        {
            GradientStop{

                position:0
                color: "#777373"
            }
            GradientStop
            {
                position: 1
                color: "#171515"
            }
        }
        Text {
            id: shiftTitle
            text: qsTr("Cel na zmianę")
            anchors
            {
                top:parent.top
                horizontalCenter:parent.horizontalCenter
                topMargin:10
            }

            font.pixelSize: 24
            color:"white"
        }
        Text {
            id: shiftTargteText
            text: shTargetText
            anchors
            {

                verticalCenter:parent.verticalCenter
                horizontalCenter:parent.horizontalCenter
                topMargin:5

            }

            font.pixelSize: root.height/3
            font.bold: true
            color:"white"
            onTextChanged: calculateShiftColor()
        }
    }

    // hour Result
    Rectangle
    {
        id:hourResult
        anchors
        {
            top:root.top
            right:root.right

        }
        radius: 10
        border.width: 2
        border.color: "#2f2727"
        height: root.height/2
        width: root.width/2
        gradient: Gradient
        {
            GradientStop{

                position:0
                color: hrTargetColorD
            }
            GradientStop
            {
                position: 1
                color: hrTargetColorU
            }
        }
        Text {
            id: hrResultTitle
            text: qsTr("Rezultat na godzinę ")
            anchors
            {
                top:parent.top
                horizontalCenter:parent.horizontalCenter
                topMargin:10
            }

            font.pixelSize: 24
            color:"#2f2727"
        }
        Text {
            id: hrResult
            text: qsTr(hourCntr)
            anchors
            {

                verticalCenter:parent.verticalCenter
                horizontalCenter:parent.horizontalCenter
                topMargin:5

            }

            font.pixelSize: root.height/3
            font.bold: true
            color:"#2f2727"

            onTextChanged: calculateHourColor()
        }
    }

    // shift Result
    Rectangle
    {
        id:shiftResult
        anchors
        {
            top:hourResult.bottom
            right:root.right

        }
        radius: 10
        border.width: 2
        border.color: "#2f2727"
        height: root.height/2
        width: root.width/2
        gradient: Gradient
        {
            GradientStop{

                position:0
                color: shTargetColorD
            }
            GradientStop
            {
                position: 1
                color: shTargetColorU
            }
        }
        Text {
            id: shftResultTitle
            text: qsTr("Rezultat na zmianę ")
            anchors
            {
                top:parent.top
                horizontalCenter:parent.horizontalCenter
                topMargin:10
            }

            font.pixelSize: 24
        }
        Text {
            id: shftResult
            text: qsTr(shiftCounter)
            anchors
            {

                verticalCenter:parent.verticalCenter
                horizontalCenter:parent.horizontalCenter
                topMargin:5

            }

            font.pixelSize: root.height/3
            font.bold: true

            onTextChanged: calculateShiftColor()
        }
    }


}
