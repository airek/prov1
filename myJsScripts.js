// connecting with server
function createServer()
{
    var IPServer;
    var portNr;
    var serverName;
    // checking if is already listening

    IPServer=serverIp.text
    portNr=serverPortNr.text;
    serverName=devName.text;
    console.log("Server IP "+IPServer)
    console.log("Port Nr "+portNr)

   //server.setPortnr(portNr)
   //server.setIpaddr(IPServer)
    if(backend.listen(IPServer,portNr,serverName))
    {
        toggBt.checked=false
        toggBt.text="Off"

    }else
    {
        toggBt.checked=true
        toggBt.text="On"

    }



}

function secondstotime(secs)
  {
        var t = new Date(1970,0,1);
        t.setSeconds(secs);
        var s = t.toTimeString().substr(0,8);
        if(secs > 86399)
            s = Math.floor((t - Date.parse("1/1/70")) / 3600000) + s.substr(2);
        return s;
  }

function toTimeString(seconds) {
  return (new Date(seconds * 1000)).toUTCString().match(/(\d\d:\d\d:\d\d)/)[0];
}

// getting current time in seconds from midnight

function getCurrentTimeInSeconds()
{
    var currentt = new Date().toLocaleTimeString()
    var tInSecs
    //onsole.log("hour in seconds "+currentt.substr(0,2)*3600)
    var hour=currentt.substr(0,2)*3600
    var minutes=currentt.substr(3,2)*60
    var seconds=currentt.substr(6,2)

    tInSecs=parseInt(hour)+parseInt(minutes)+parseInt(seconds)

    return tInSecs
}
// getting date in format yyyymmdd
function getSpecialDate()
{
    var dt=new Date()
    var dd=dt.getDate()
    var mm=dt.getMonth()+1
    var yy=dt.getFullYear()
    var idDate

    if(dd<10)
    {
        dd='0'+dd;
    }

    if(mm<10)
    {
        mm='0'+mm;
    }

    idDate=yy+mm+dd

    //console.log("id Date "+idDate)

    return idDate;
}
// getting date in format yyyy-mm-dd
function getDate()
{
    var dt=new Date()
    var dd=dt.getDate()
    var mm=dt.getMonth()+1
    var yy=dt.getFullYear()
    var curDate

    if(dd<10)
    {
        dd='0'+dd;
    }

    if(mm<10)
    {
        mm='0'+mm;
    }


    curDate=yy+"-"+mm+"-"+dd

    return curDate
}

// creating ID for order
function createOrderID()
{
    var id
    var currentDate=getSpecialDate()
    // creating id from lineNr,current date in format yyyymmdd, currenttime in seconds
    var tinSec = getCurrentTimeInSeconds()

    id=lineNr.text+currentDate+tinSec
    //console.log("order id "+id)
    return id
}
// calculate target tact
function calculateTargetTact()
{

    var tactTarget=3600/vTargetPerHour
    tactTarget=tactTarget.toFixed(2)
    return tactTarget

}


// inserting new protokol
function insertProtokol()
{
   vOrderID=createOrderID()
   var line=lineNr.text
   var partNumbr=partNr.text
   var persQty=vpersQty
   var loginDate=getDate()
   var timeInSec=getCurrentTimeInSeconds()
   var targetTact=calculateTargetTact()

   var sqlQry="insert into protokol (id,line,partNr,persQty,loginDate,loginTime,targetTact)"
    +"values('"+vOrderID+"','"+line+"','"+partNumbr+"',"+persQty+",'"+loginDate+"',"+timeInSec
    +","+targetTact+")"

    console.log("sql Qry "+sqlQry)

    backendDbCon.execQry(sqlQry)

}

// calculate time of production or standstill
function calculateTime(auxTime,auxDate)
{

    var currT=getCurrentTimeInSeconds()
    var ttime=currT-auxTime


    return ttime


}
// updating protokol
function updateProtokol()
{
    var strQry
    var realTact
    var rTact=calculateRealTact()
    rTact=rTact.toFixed(2)
    //console.log("real Tact "+rTact)
    var productivity=calculateProductivity(rTact)

    strQry="update protokol set orderQty="+backend.getOrderCntr()+","
    +"realTact="+rTact+",logoffDate='"+getDate()+"',logOffTime="+getCurrentTimeInSeconds()
    +",productionTime="+vProdTime+",breaks="+vBreakTime+","
    +"productivity="+productivity+" where id='"+vOrderID+"'"

    console.log("strQry before update "+strQry)

    if(!backendDbCon.execQry(strQry))
    {
        backendDbCon.writeNID(strQry)
    }

}
// calculate real tact
function calculateRealTact()
{

  var oQty=backend.getOrderCntr()
  console.log("Ilość na zleceniu "+oQty)

  var rTact=vProdTime/oQty

  return rTact
}

// getting target Tact
function calculateProductivity(rTact)
{
    var res
    var strQry="select targetTact from protokol where id='"+vOrderID+"'"
    res=backendDbCon.getDbData(",",strQry);

    var ts=res[0]

    //
    var data=ts.split(",")
    var targetT=data[0]
    console.log("targetT "+targetT)

    var productivity=targetT/rTact
    productivity=productivity.toFixed(2)
    console.log("productivity "+productivity)

    return productivity
}
