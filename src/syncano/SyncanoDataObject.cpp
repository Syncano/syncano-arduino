#include "SyncanoDataObject.h"

SyncanoClass * masterClass;

void *operator new( size_t size, void *ptr ){
  return ptr;
}
 
void operator delete( void *obj, void *alloc ){
  return;
}

enum class DataType { 
  NONE,
  STRING, 
  INTEGER,
  FLOAT
};

struct DataHolder{ 
  DataHolder() {
    currentType = DataType::NONE;
  }

  ~DataHolder() {
    destroy();
  }

  private:
    DataType currentType;
    union {
      String v_string;
      int v_int;
      float v_float;
    };

  public:
    String getString() {
      if(currentType == DataType::STRING) return v_string;
    }

    void setString(String s) {
      destroy();
      new(&v_string) String{s};
      currentType = DataType::STRING;
    }

    void setInt(int s){
      v_int = s;
      currentType = DataType::INTEGER;
    }

    int getInt(){
      if(currentType == DataType::INTEGER) return v_int;
    }

    void setFloat(float s){
      v_float = s;
      currentType = DataType::FLOAT;
    }

    float getFloat(){
      if(currentType == DataType::FLOAT) return v_float;
    }
    
    DataType getDataType() {
      return currentType;
    }

  private: 
    void destroy() {
      if (currentType == DataType::STRING) {
        v_string.~String();
      }
      currentType = DataType::NONE;
  }
};

DataHolder * fieldValue;

SyncanoDataObject::SyncanoDataObject(){
  fieldValue = 0;
}

SyncanoDataObject::~SyncanoDataObject(){
  if(this->fieldValue){
    delete fieldValue;
  }
}

SyncanoDataObject::SyncanoDataObject(SyncanoClass* incommingClass){
  masterClass = incommingClass;
  fieldValue = new DataHolder [incommingClass->getFieldCount()];
}

void SyncanoDataObject::setFieldValue(String fieldName, String fieldValue){
  this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].setString(fieldValue);
}

void SyncanoDataObject::setFieldValue(String fieldName, int fieldValue){
  this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].setInt(fieldValue);
}

void SyncanoDataObject::setFieldValue(String fieldName, float fieldValue){
  this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].setFloat(fieldValue);
}

String SyncanoDataObject::getFieldValue(String fieldName){
  if(this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].getDataType() == DataType::FLOAT){
    return String(this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].getFloat());
  }else if(this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].getDataType()  == DataType::INTEGER){
    return String(this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].getInt());
  }else{
    return this->fieldValue[masterClass->getFieldIdByFieldName(fieldName)].getString();
  }
}

bool SyncanoDataObject::add(){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String id = request.sendRequest("POST",client->getInstanceName()+F("/classes/")+masterClass->getClassName()+F("/objects/"),JSONencode());

  this->setFieldValue("id",getIntFromJsonDirty(id, "id"));
  if(this->getFieldValue("id").toInt() >= 0 ){
    return true;
  }

  return false;
}

bool SyncanoDataObject::details(int id){
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();

  if(id == -1){
    id = this->getFieldValue("id").toInt();
  }

  String neededFields = "";
  for(int var = 0; var < masterClass->getFieldCount(); var++){
    neededFields += masterClass->getFieldName(var);
    if( (var+1) != masterClass->getFieldCount()){
      neededFields+=",";
    }
  }
  String returnedString = request.sendRequest("GET",client->getInstanceName()+F("/classes/")+masterClass->getClassName()+F("/objects/")+String(id)+F("/?fields=")+neededFields);
  neededFields = "";

  if(returnedString != ""){
    if(JSONdecode(returnedString)){
      return true;
    }
  }
  return false;
}

bool SyncanoDataObject::update() {
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  String response = request.sendRequest("PATCH",client->getInstanceName()+F("/classes/")+masterClass->getClassName()+F("/objects/")+String(this->getFieldValue("id"))+"/",JSONencode());
  if(getIntFromJsonDirty(response, "id") >= 0){
    return true;
  }
  else{
    return false;
  }
}

void SyncanoDataObject::remove() {
  SyncanoRequest request(getSyncanoClient());
  SyncanoClient* client = getSyncanoClient();
  request.sendRequest("DELETE",client->getInstanceName()+F("/classes/")+masterClass->getClassName()+F("/objects/")+this->getFieldValue("id")+"/");

  delete fieldValue;
  fieldValue = new DataHolder [masterClass->getFieldCount()];
  for(int i=0;i<masterClass->getFieldCount();i++){
    this->setFieldValue(masterClass->getFieldName(i),"0");
  }
}

String SyncanoDataObject::JSONencode(){
  String JSON;
  StaticJsonBuffer<150> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  for ( int x = 0; x < masterClass->getFieldCount(); x++ ) {
    if(fieldValue[x].getDataType() == DataType::FLOAT){
      root[masterClass->getFieldName(x)] = fieldValue[x].getFloat();
    }else if(fieldValue[x].getDataType() == DataType::INTEGER){
      root[masterClass->getFieldName(x)] = fieldValue[x].getInt();
    }else{
      root[masterClass->getFieldName(x)] = fieldValue[x].getString();
    }
  }
  root.printTo(JSON);
  return JSON;
}

bool SyncanoDataObject::JSONdecode(String capture){
  StaticJsonBuffer<150> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(capture);

  if(root.success() && root.containsKey("id")) {
    for(int i = 0; i < masterClass->getFieldCount(); i++){
      if(root[masterClass->getFieldName(i)].is<float>()){
        this->setFieldValue(masterClass->getFieldName(i),root[masterClass->getFieldName(i)].as<float>());
      }else if(root[masterClass->getFieldName(i)].is<int>()){
        this->setFieldValue(masterClass->getFieldName(i),root[masterClass->getFieldName(i)].as<int>());
      }else{
        this->setFieldValue(masterClass->getFieldName(i),root[masterClass->getFieldName(i)].asString());
      }
    }
    return true;
  }

  return false;
}

void SyncanoDataObject::printDetails(){
  Serial.println();
  for ( int x = 0; x < masterClass->getFieldCount(); x++ ) {
    Serial.print("Field: "+masterClass->getFieldName(x)+" Value: ");
    switch(fieldValue[x].getDataType()){
      case DataType::STRING:
        Serial.print(fieldValue[x].getString());
        break;
      case DataType::INTEGER:
        Serial.print(fieldValue[x].getInt());
        break;
      case DataType::FLOAT:
        Serial.print(fieldValue[x].getFloat());
        break;
      default:
        break;
    }
    Serial.println();
  }
}
