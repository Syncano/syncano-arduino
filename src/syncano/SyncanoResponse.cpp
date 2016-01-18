#include "SyncanoResponse.h"

SyncanoResponse::SyncanoResponse(){

}
SyncanoResponse::~SyncanoResponse(){

}
String SyncanoResponse::getResponseToString(Connector & connector) {
  String response="";
  char c;
  while (connector.available()) {
    c = connector.read();
    if(c!='\t' || c!='\n' || c!='\r'){
      response += (String)c;
    }
  }
  connector.flush();
  return response;
}
