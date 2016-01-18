#include "SyncanoUtils.h"

int getIntFromJsonDirty(String &JSON, String key){
  int end;
  end = JSON.indexOf("\""+key+"\":");
  JSON.remove(0,end+key.length() + 3);
  return (end != -1)? JSON.substring(0,JSON.indexOf(",")).toInt() : -1;
}

String getStringFromJsonDirty(String &JSON, String key){
  String value = "";
  int end;
  end = JSON.indexOf("\""+key+"\":");
  if(end != -1){
    JSON.remove(0,end+key.length() + 3);
    value = JSON.substring(0,JSON.indexOf(","));
  }

  return value;
}

bool checkExistFromJsonDirty(String &JSON, String key){
  int end;
  end = JSON.indexOf("\""+key+"\"");
  if(end != -1){
    return true;
  }
  return false;
}
