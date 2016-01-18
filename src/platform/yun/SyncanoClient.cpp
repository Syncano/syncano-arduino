#ifdef ARDUINO_AVR_YUN

#include "../../syncano/SyncanoClient.h"

SyncanoClient::SyncanoClient(){}

SyncanoClient::SyncanoClient(String ApiKey) {
  this->clientApiKey = ApiKey;
}

SyncanoClient::~SyncanoClient(){
  this->clientApiKey = "0";
}

void SyncanoClient::setInstanceName(String instanceName){
  this->instanceName = instanceName;
}

String SyncanoClient::getApiKey(){
  return this->clientApiKey;
}

String SyncanoClient::getInstanceName(){
  return this->instanceName;
}

SyncanoClient* Syncano = 0;

SyncanoClient* getSyncanoClient(){
  return Syncano;
}

void initSyncanoClient(String apiKey) {
  if (Syncano != 0)
    delete Syncano;
  Syncano = new SyncanoClient(apiKey);
}

#endif
