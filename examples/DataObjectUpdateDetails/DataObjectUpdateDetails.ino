/*
 * In this example we will fetch data from Syncano, change it and update on Syncano.
 * To use this example you need Syncano class.
*/
#include <Syncano.h>
#include <Bridge.h>

#define ACCOUNT_KEY "ACCOUNT_KEY"
#define INSTANCE_NAME "INSTANCE_NAME"
#define CLASS_NAME "CLASS_NAME"

SyncanoClient* syncano;
SyncanoClass* classHolder;
SyncanoDataObject* object;

void setup() {
  initSyncanoClient(ACCOUNT_KEY);
  Serial.begin(115200);
  startBridge();

  // Setup Syncano client used to connect
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  classHolder = new SyncanoClass(CLASS_NAME);
}

void loop() {
  classHolder->details();

  // Initialize empty object based on class
  object = classHolder->initObject();

  // Get object details from Syncano and parse inside local object
  object->details();
  object->printDetails();
  
  // Update local object
  object->setFieldValue("firstname","andrew2");

  // Update Data Object in Syncano
  object->update();
  object->printDetails();

  delay(5000);
}

// Start Arduino Bridge, used to connect Arduino processor to OpenWRT Linux
void startBridge(){
  while(!Serial);
  Serial.println(F("Serial ready."));
  Serial.println(F("Starting bridge...\n"));
  pinMode(13,OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
}
