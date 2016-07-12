#include "SyncanoEndpointScript.h"

String SyncanoEndpointScriptRun(String scriptName){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest(SyncanoClient::HTTP::POST,client->getInstanceName()+"/endpoints/scripts/"+scriptName+"/run/");
}

String SyncanoEndpointScriptRun(String scriptName, String JSON){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest(SyncanoClient::HTTP::POST,client->getInstanceName()+"/endpoints/scripts/"+scriptName+"/run/",JSON);
}