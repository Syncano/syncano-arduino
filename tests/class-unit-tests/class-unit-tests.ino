#line 2 "class-unit-tests.ino"
#include <ArduinoUnit.h>
#include <Syncano.h>
#include <Bridge.h>

#define ACCOUNT_KEY "API_KEY"
#define INSTANCE_NAME "INSTANCE_NAME"
#define CLASS_NAME "UNIT_TEST_CLASS_NAME"
#define CLASS_DESCRIPTION "UNIT_TEST_DESCRIPTION"

// Create pointers for Client and Class
SyncanoClient* syncano;
SyncanoClass* testClass;

test(once_Init){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  String syncanoApiKey = syncano->getApiKey();
  assertEqual(syncanoApiKey,(String)ACCOUNT_KEY);
}

test(once_classAddWithoutFields){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->initClass();
  bool addStatus = testClass->add();
  assertTrue(addStatus);
}

test(once_classAddWithOneField){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->initClass();
  bool addStatus = testClass->add();
  assertTrue(addStatus);
}

test(once_classUpdate){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, "Updated Description");
  testClass->addField("test");
  testClass->initClass();
  bool updateStatus = testClass->update();
  assertTrue(updateStatus);
}

test(once_classDetails){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME);
  bool detailsStatus = testClass->details();
  assertTrue(detailsStatus);
}

test(once_classDetailsToExistedClass){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME);
  testClass->addField("test");
  testClass->initClass();
  bool detailsStatus = testClass->details();
  assertTrue(detailsStatus);
}


void setup() {
  Serial.begin(115200);
  while(!Serial);
  Bridge.begin();

  // Set include to test which should be run
  Test::include("once_Init");
  Test::exclude("once_classAddWithoutFields");
  Test::exclude("once_classAddWithOneField");
  Test::exclude("once_classUpdate");
  Test::exclude("once_classDetails");
  Test::exclude("once_classDetailsToExistedClass");
}

void loop(){
    Test::run();
}

