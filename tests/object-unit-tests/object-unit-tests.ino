#line 2 "object-unit-tests.ino"
#include <ArduinoUnit.h>
#include <Syncano.h>
#include <Bridge.h>

#define ACCOUNT_KEY "API_KEY"
#define INSTANCE_NAME "INSTANCE_NAME"
#define CLASS_NAME "UNIT_TEST_CLASS_NAME"
#define CLASS_DESCRIPTION "UNIT_TEST_DESCRIPTION"
#define OBJECT_ID "OBJECT_ID"

// Create pointers for Client, Class and Object
SyncanoClient* syncano;
SyncanoClass* testClass;
SyncanoDataObject* object;

test(once_Init){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  String syncanoApiKey = syncano->getApiKey();
  assertEqual(syncanoApiKey,(String)ACCOUNT_KEY);
}

test(once_objectAdd){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->initClass();
  object = testClass->initObject();
  object->setFieldValue("test","Test");
  bool addStatus = object->add();
  assertTrue(addStatus);
}

test(once_objectUpdate){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->addField("id");
  testClass->initClass();
  object = testClass->initObject();
  object->setFieldValue("test","Test234");
  object->setFieldValue("id",OBJECT_ID);
  bool updateStatus = object->update();
  assertTrue(updateStatus);
}

test(once_CreatedObjectUpdate){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->addField("id");
  testClass->initClass();
  object = testClass->initObject();
  object->setFieldValue("test","Test");
  object->add();
  object->setFieldValue("test","Test234");
  bool updateStatus = object->update();
  assertTrue(updateStatus);
}

test(once_ObjectDetails){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->addField("id");
  testClass->initClass();
  object = testClass->initObject();
  bool detailsStatus = object->details(int(OBJECT_ID));
  assertTrue(detailsStatus);
}

test(once_CreatedObjectDetails){
  initSyncanoClient(ACCOUNT_KEY);
  syncano = getSyncanoClient();
  syncano->setInstanceName(INSTANCE_NAME);
  testClass = new SyncanoClass(CLASS_NAME, CLASS_DESCRIPTION);
  testClass->addField("test");
  testClass->addField("id");
  testClass->initClass();
  object = testClass->initObject();
  object->setFieldValue("test","Test");
  object->add();
  bool detailsStatus = object->details();
  assertTrue(detailsStatus);
}

void setup(){
  Serial.begin(115200);
  while(!Serial);
  Bridge.begin();

  // Set include to test which should be run
  Test::include("once_Init");
  Test::include("once_objectAdd");
  Test::exclude("once_objectUpdate");
  Test::exclude("once_CreatedObjectUpdate");
  Test::exclude("once_ObjectDetails");
  Test::exclude("once_CreatedObjectDetails");
}

void loop(){
    Test::run();
}

