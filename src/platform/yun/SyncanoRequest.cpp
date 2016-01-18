#include "../../syncano/SyncanoRequest.h"

SyncanoRequest::SyncanoRequest(SyncanoClient* client) {
  this->client = client;
  baseUrl = "https://api.syncano.io/v1/instances/";
}

SyncanoRequest::~SyncanoRequest() {

}

String SyncanoRequest::sendRequest(String httpType, String url, bool async) {
  connector.begin("curl");
  connector.addParameter("-X");
  connector.addParameter(httpType);
  connector.addParameter("-H");
  connector.addParameter("X-API-KEY:"+client->getApiKey());
  connector.addParameter(baseUrl+url);
  if(async == 0){
    connector.run();
    return this->response.getResponseToString(connector);
  }else{
    connector.runAsynchronously();
  }
}

String SyncanoRequest::sendRequest(String httpType, String url, String requestBody, bool async){
  connector.begin("curl");
  connector.addParameter("-X");
  connector.addParameter(httpType);
  connector.addParameter("-H");
  connector.addParameter("X-API-KEY:"+client->getApiKey());
  connector.addParameter("-H");
  connector.addParameter("Content-Type: application/json");
  connector.addParameter("-d");
  connector.addParameter(requestBody);
  connector.addParameter(baseUrl+url);
  if(async == 0){
    connector.run();
    return this->response.getResponseToString(connector);
  }else{
    connector.runAsynchronously();
  }
}

String SyncanoRequest::sendRequest(String httpType, String url, String requestBody, String requestQuery, bool async){
  connector.begin("curl");
  connector.addParameter("-X");
  connector.addParameter(httpType);
  connector.addParameter("-G");
  connector.addParameter("-H");
  connector.addParameter("X-API-KEY:"+client->getApiKey());
  connector.addParameter("-H");
  connector.addParameter("Content-Type: application/json");

  if(requestBody!=NULL){
    connector.addParameter("-d");
    connector.addParameter(requestBody);
  }

  if(requestQuery!=NULL){
    connector.addParameter("-d");
    connector.addParameter(requestQuery);
  }

  connector.addParameter(baseUrl+url);
  if(async == 0){
    connector.run();
    return this->response.getResponseToString(connector);
  }else{
    connector.runAsynchronously();
  }
}
