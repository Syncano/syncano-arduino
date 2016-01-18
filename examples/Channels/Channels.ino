/*
 * In this example we will use simple Channel Poll with Syncano.
 * In order to complete this task you need Syncano class 
 * with data object connected to channel.
*/

#include <Syncano.h>
#include <Bridge.h>

#define ACCOUNT_KEY "ACCOUNT_KEY"
#define INSTANCE_NAME "INSTANCE_NAME"
#define CLASS_NAME "CLASS_NAME"
#define CHANNEL_NAME "CHANNEL_NAME"

SyncanoClient* syncano;
SyncanoClass* classHolder;
SyncanoDataObject* object;
SyncanoChannel* channel;

void setup() {
  initSyncanoClient(ACCOUNT_KEY);
  Serial.begin(115200);

  startBridge();

  // Setup Syncano client used to connect
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  classHolder = new SyncanoClass(CLASS_NAME);
  // Initialize class, remember that you cannot add new fields after this command
  classHolder->addField("fieldname");
  classHolder->initClass();

  // Initialize local empty object based on class
  object = classHolder->initObject();

  channel = new SyncanoChannel(CHANNEL_NAME);
  channel->setObject(object);
}

void loop() {
  // Poll on Syncano Channel
  channel->poll();
  // Print object key and values to confirm new data income
  object->printDetails();
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

