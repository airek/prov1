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
