#include "SyncanoChannel.h"

String channelName;
String channelDescription;
char channelType;
SyncanoDataObject* dataObject;

SyncanoChannel::SyncanoChannel(){
  channelName = "";
  channelDescription = "";
  channelType = '0';
}

SyncanoChannel::SyncanoChannel(String incChannelName){
  channelName = incChannelName;
  channelDescription = "";
  channelType = '0';
}

SyncanoChannel::SyncanoChannel(String incChannelName, String incChannelDesc){
  channelName = incChannelName;
  channelDescription = incChannelDesc;
  channelType = '0';
}

SyncanoChannel::SyncanoChannel(String incChannelName, String incChannelDesc, String incChannelType){
  channelName = incChannelName;
  channelDescription = incChannelDesc;
  channelType = simpleEnum(incChannelType);
}

SyncanoChannel::~SyncanoChannel(){
}

bool SyncanoChannel::add(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String response = request.sendRequest(F("POST"),client->getInstanceName()+F("/channels/?template_response=arduino"),JSONencode());
  return response.toInt() > 0 ? true : false;
}

bool SyncanoChannel::details(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String response = request.sendRequest(F("GET"),client->getInstanceName()+F("/channels/")+this->channelName+F("/?fields=name,description"));
  if(response != ""){
    return JSONdecode(response);
  }
  else{
    return false;
  }
}

bool SyncanoChannel::poll(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String response = request.sendRequest(F("GET"),client->getInstanceName()+F("/channels/")+this->channelName+F("/poll/?template_response=arduino"));
  if(response != ""){
    return JSONpollDecode(response);
  }
  return false;
}

void SyncanoChannel::publish(String fieldName, String fieldValue){
  String JSON;
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  JsonObject& schema = root.createNestedObject("payload");
  schema[fieldName] = fieldValue;
  root.printTo(JSON);
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  request.sendRequest(F("POST"),client->getInstanceName()+F("/channels/")+this->channelName+F("/publish/"),JSON);
}

void SyncanoChannel::remove(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  request.sendRequest("DELETE",client->getInstanceName()+F("/channels/")+this->channelName+"/");
}

String SyncanoChannel::JSONencode(){
  String JSON;
  StaticJsonBuffer<120> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["name"] = this->channelName;
  if(this->channelDescription)
    root["description"] = this->channelDescription;
  root["type"] = simpleEnum(this->channelType);
  root.printTo(JSON);
  return JSON;
}

bool SyncanoChannel::JSONpollDecode(String & capture){
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(capture);
  String keeper;
    if(root.success()){
      for(int i=0; i< dataObject->masterClass->getFieldCount() ; i++){        
        keeper = dataObject->masterClass->getFieldName(i);
        if(root.containsKey(keeper)){
          if(root[keeper].is<float>()){
            this->dataObject->setFieldValue(keeper,root[keeper].as<float>());
          }else if(root[keeper].is<int>()){
            this->dataObject->setFieldValue(keeper,root[keeper].as<int>());           
          }else{
            this->dataObject->setFieldValue(keeper,root[keeper].asString());        
          }
        }
      }
      return true;
    }
  return false;
}

bool SyncanoChannel::JSONdecode(String capture){
  StaticJsonBuffer<150> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(capture);
  if(root.success() && root.containsKey("name")){
    this->channelName = root["name"].asString();
    this->channelDescription = root["description"].asString();
    this->channelType = simpleEnum(root["type"].asString());
    return true;
  }
  return false;
}

void SyncanoChannel::printDetails(){
  Serial.println();
  Serial.print(F("Name: "));
  Serial.print(this->channelName);
  Serial.println();
  Serial.print(F("Desc: "));
  Serial.print(this->channelDescription);
  Serial.println();
  Serial.print(F("Type: "));
  Serial.print(this->simpleEnum(channelType));
  Serial.println();
  if(this->dataObject){
    Serial.print(F("Connected object fields: "));
    Serial.println();
    this->dataObject->printDetails();
  }
  Serial.println();
}

char SyncanoChannel::simpleEnum(String value){
  if(value == "default") return '0';
  if(value == "separate_rooms") return '1';
   return '0';
}

String SyncanoChannel::simpleEnum(char value){
  if(value == '0') return "default";
  if(value == '1') return "separate_rooms";
  return "default";
}

void SyncanoChannel::setObject(SyncanoDataObject* incObject){
  dataObject = incObject;
}