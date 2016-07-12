#include "SyncanoScript.h"

String SyncanoScriptRun(int scriptId){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest(SyncanoClient::HTTP::POST,client->getInstanceName()+"/snippets/scripts/"+scriptId+"/run/");
}

String SyncanoScriptRun(int scriptId,String JSON){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest(SyncanoClient::HTTP::POST,client->getInstanceName()+"/snippets/scripts/"+scriptId+"/run/",JSON);
}