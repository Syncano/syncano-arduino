#include "SyncanoClass.h"

char * type;
String * name;
int fieldCount;
String className;
String holder;

SyncanoClass::SyncanoClass(){
  type = 0;
  name = 0;
  fieldCount = 0;
  className = "";
}

SyncanoClass::SyncanoClass(String incClassName){
  fieldCount = 0;
  className = incClassName;
  holder = "$";
}

SyncanoClass::~SyncanoClass(){
  if(this->type){
    delete type;
  }
  if(this->name){
    delete name;
  }
}

void SyncanoClass::initClass(){
  if(holder.indexOf("$id!") == -1){
    fieldCount++;
    holder+="id!1$";
  }
  name = new String [ fieldCount ];
  type = new char [ fieldCount ];
  int end;
  holder.remove(0,1);
  for(int i=0;i<fieldCount;i++){
    end = holder.indexOf('!');
    name[i]=holder.substring(0,end);
    holder.remove(0,end+1);
    end = holder.indexOf('$');
    type[i]=(char)holder.substring(0,end)[0];
    holder.remove(0,end+1);
  }
}

bool SyncanoClass::add(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String response = request.sendRequest(SyncanoClient::HTTP::POST,client->getInstanceName()+F("/classes/?template_response=arduino"),JSONencode());
  return response.toInt() > 0 ? true : false;
}

bool SyncanoClass::details(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String returnedString;
  returnedString = request.sendRequest(SyncanoClient::HTTP::GET,client->getInstanceName()+"/classes/"+this->className+F("/?fields=schema"));
  if(returnedString != ""){
    return JSONdecode(returnedString);
  }
  else{
    return false;
  }
}

void SyncanoClass::remove(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  request.sendRequest(SyncanoClient::HTTP::DELETE,client->getInstanceName()+F("/classes/")+this->className+"/");
  if(this->name && this->type){
    while(int i = 0 < fieldCount){
      this->name[i]="";
      this->type[i++]='0';
    }
  }
}

String SyncanoClass::JSONencode(){
  String JSON;
  StaticJsonBuffer<250> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["name"] = this->className;
  JsonArray& schema = root.createNestedArray("schema");

  for ( int i = 0; i < fieldCount; i++ ) {
    if(this->name[i]!="id"){
      JsonObject& data = schema.createNestedObject();
      data["type"] = simpleEnum(this->type[i]);
      data["name"] = this->name[i];
    }
  }
  root.printTo(JSON);
  return JSON;
}

bool SyncanoClass::JSONdecode(String capture){
  StaticJsonBuffer<300> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(capture);

  if(root.success() && root.containsKey("schema")){
    holder = "";
    fieldCount = root["schema"].size();

    if(fieldCount>0){
      holder += '$';
      for(int i = 0 ; i<fieldCount ; i++){
        JsonObject& data = root["schema"][i];
        holder += data["name"].asString();
        holder += '!';
        holder += simpleEnum(data["type"].asString());
        holder += '$';
      }
      initClass();
      return true;
    }
  }
  return false;
}

char SyncanoClass::simpleEnum(String value){
  if(value == "integer") return '1';
  if(value == "float") return '2';
  return '0';
}

String SyncanoClass::simpleEnum(char value){
  if(value == '1') return "integer";
  if(value == '2') return "float";
  return "string";
}

void SyncanoClass::addField(String fieldName){
  fieldCount++;
  holder += fieldName+'!'+0+'$';
}

void SyncanoClass::addField(String fieldType, String fieldName){
  fieldCount++;
  holder += fieldName+'!' + simpleEnum(fieldType)+'$';
}

void SyncanoClass::setField(String oldfieldName, String newfieldName){
  name[getFieldIdByFieldName(oldfieldName)]=newfieldName;
}

int SyncanoClass::getFieldCount(){
  return fieldCount;
}

String SyncanoClass::getClassName(){
  return className;
}

String SyncanoClass::getFieldName(int position){
  return name[position];
}

int SyncanoClass::getFieldIdByFieldName(String fieldName){
  for(int i=0;i<fieldCount;i++){
    if(name[i]==fieldName){
      return i;
    }
  }
  return -1;
}

SyncanoDataObject* SyncanoClass::initObject(){
  SyncanoDataObject* newObject = new SyncanoDataObject(this);
  for(int i=0;i<this->getFieldCount();i++){
    newObject->setFieldValue(getFieldName(i),"0");
  }
  return newObject;
}

void SyncanoClass::printDetails(){
  Serial.println();
  Serial.print(F("Name: "));
  Serial.print(this->className);
  Serial.print(F(" Fields: "));
  if(fieldCount>0){
    for(int i=0;i<fieldCount;i++){
      Serial.println();
      Serial.print(F("Value: "));
      Serial.print(this->name[i]);
      Serial.print(F(" Type: "));
      Serial.print(simpleEnum(this->type[i]));
    }
  }
}
