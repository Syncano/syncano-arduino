#include "SyncanoCodeBox.h"

String SyncanoCodeBoxRun(int codeBoxId){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest("POST",client->getInstanceName()+"/codeboxes/"+codeBoxId+"/run/");
}

String SyncanoCodeBoxRun(int codeBoxId,String JSON){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest("POST",client->getInstanceName()+"/codeboxes/"+codeBoxId+"/run/",JSON);
}