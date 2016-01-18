#include "SyncanoWebhook.h"

String SyncanoWebhooksRun(String webhookName){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest("POST",client->getInstanceName()+"/webhooks/"+webhookName+"/run/");
}

String SyncanoWebhooksRun(String webhookName, String JSON){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  return request.sendRequest("POST",client->getInstanceName()+"/webhooks/"+webhookName+"/run/",JSON);
}