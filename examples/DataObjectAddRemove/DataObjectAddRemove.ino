/*
 * In this example we will create Syncano Class and Syncano Data Object based on it.
 * Last step will remove Data Object from Syncano.
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
  classHolder->addField("firstname");

  // Initialize class, remember that you cannot add new fields after this command
  classHolder->initClass();
}

void loop() {
  // Create class in Syncano
  classHolder->add();

  // Initialize empty local object based on class
  object = classHolder->initObject();

  object->setFieldValue("firstname","john");
  // Create Data Object in Syncano
  object->add();
  delay(5000);
  
  object->remove();
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
