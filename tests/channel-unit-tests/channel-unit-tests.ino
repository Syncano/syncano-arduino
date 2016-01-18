#line 2 "channel-unit-tests.ino"
#include <ArduinoUnit.h>
#include <Syncano.h>
#include <Bridge.h>

#define ACCOUNT_KEY "API_KEY"
#define INSTANCE_NAME "INSTANCE_NAME"
#define CLASS_NAME "UNIT_TEST_CLASS_NAME"
#define CLASS_DESCRIPTION "UNIT_TEST_CLASS_DESCRIPTION"
#define CHANNEL_NAME "UNIT_TEST_CHANNEL"

// Create pointers for Client, Class, Object and Channel
SyncanoClient* syncano;
SyncanoClass* testClass;
SyncanoDataObject* object;
SyncanoChannel* channel;

test(once_Init){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  String syncanoApiKey = syncano->getApiKey();
  assertEqual(syncanoApiKey,(String)ACCOUNT_KEY);
}

test(once_channelAdd){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  channel = new SyncanoChannel("ut");
  bool addStatus = channel->add();
  assertTrue(addStatus);
}

test(once_channelPoll){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("monster");
  testClass->addField("id");
  testClass->initClass();
  object = testClass->initObject();
  channel = new SyncanoChannel(CHANNEL_NAME);
  channel->setObject(object);
  bool pollStatus = channel->poll();
  assertTrue(pollStatus);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Bridge.begin();

  // Set include to test which should be run
  Test::include("once_Init");
  Test::include("once_channelAdd");
  Test::include("once_channelPoll");

}

void loop(){
    Test::run();
}

