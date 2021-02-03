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
