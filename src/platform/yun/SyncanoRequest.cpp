#include "../../syncano/SyncanoRequest.h"

SyncanoRequest::SyncanoRequest(SyncanoClient* client) {
  this->client = client;
  baseUrl = "https://api.syncano.io/v1.1/instances/";
}

SyncanoRequest::~SyncanoRequest() {

}

String SyncanoRequest::sendRequest(SyncanoClient::HTTP httpType, String url, String requestBody, bool async){
  connector.begin("curl");
  connector.addParameter("-X");
  connector.addParameter(this->getHTTPtype(httpType));
  connector.addParameter("-H");
  connector.addParameter("X-API-KEY:"+client->getApiKey());
  if(requestBody != ""){
    connector.addParameter("-H");
    connector.addParameter("Content-Type: application/json");
    connector.addParameter("-d");
    connector.addParameter(requestBody);
  }
  connector.addParameter(baseUrl+url);
  if(async == 0){
    connector.run();
    return this->response.getResponseToString(connector);
  }else{
    connector.runAsynchronously();
  }
}

String SyncanoRequest::getHTTPtype(SyncanoClient::HTTP httpType){
  switch(httpType) {
    case SyncanoClient::HTTP::GET:
      return F("GET");
    case SyncanoClient::HTTP::POST:
      return F("POST");
    case SyncanoClient::HTTP::PATCH:
      return F("PATCH");
    case SyncanoClient::HTTP::DELETE:
      return F("DELETE");
  }
}
