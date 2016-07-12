#include "SyncanoUtils.h"

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
