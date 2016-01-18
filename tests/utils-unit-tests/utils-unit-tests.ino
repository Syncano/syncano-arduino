#line 2 "utils-unit-tests.ino"
#include <ArduinoUnit.h>
#include <Syncano.h>
#include <Bridge.h>

test(once_getInt){
  String JSON = "{\n"
    "  \"channel_room\": null,\n"
    "  \"group\": null,\n"
    "  \"name\": \"Coën\",\n"
    "  \"links\": {\n"
    "    \"self\": \"/v1/instances/rivia/classes/witchers/objects/14/\"\n"
    "  },\n"
    "  \"city\": \"Poviss\",\n"
    "  \"group_permissions\": \"none\",\n"
    "  \"created_at\": \"2015-05-20T19:55:14.045278Z\",\n"
    "  \"owner_permissions\": \"none\",\n"
    "  \"updated_at\": \"2015-05-20T20:47:42.975848Z\",\n"
    "  \"id\": 14,\n"
    "  \"owner\": null,\n"
    "  \"other_permissions\": \"none\",\n"
    "  \"channel\": null,\n"
    "  \"revision\": 3\n"
    "}";
  int id = getIntFromJsonDirty(JSON, "id");
  assertEqual(id, 14);
}

test(once_getString){
  String JSON="{\n"
    "  \"status\": \"ready\",\n"
    "  \"group\": null,\n"
    "  \"name\": \"witchers\",\n"
    "  \"links\": {\n"
    "    \"self\": \"/v1/instances/rivia/classes/witchers/\",\n"
    "    \"objects\": \"/v1/instances/rivia/classes/witchers/objects/\"\n"
    "  },\n"
    "  \"group_permissions\": \"none\",\n"
    "  \"created_at\": \"2015-05-18T18:59:56.220333Z\",\n"
    "  \"description\": \"List of all known and alive witchers\",\n"
    "  \"updated_at\": \"2015-05-19T01:24:17.471806Z\",\n"
    "  \"objects_count\": 0,\n"
    "  \"metadata\": {},\n"
    "  \"revision\": 1,\n"
    "  \"other_permissions\": \"none\",\n"
    "  \"schema\": [\n"
    "    {\n"
    "      \"type\": \"string\",\n"
    "      \"name\": \"name\"\n"
    "    },\n"
    "    {\n"
    "      \"type\": \"string\",\n"
    "      \"name\": \"city\"\n"
    "    }\n"
    "  ]\n"
    "}";
  String result = getStringFromJsonDirty(JSON, "status");
  String endp = F("ready");
  assertEqual(result, endp);
}

test(once_getBool){
  String JSON="{\n"
    "  \"status\": \"ready\",\n"
    "  \"group\": null,\n"
    "  \"name\": \"witchers\",\n"
    "  \"links\": {\n"
    "    \"self\": \"/v1/instances/rivia/classes/witchers/\",\n"
    "    \"objects\": \"/v1/instances/rivia/classes/witchers/objects/\"\n"
    "  },\n"
    "  \"group_permissions\": \"none\",\n"
    "  \"created_at\": \"2015-05-18T18:59:56.220333Z\",\n"
    "  \"description\": \"List of all known and alive witchers\",\n"
    "  \"updated_at\": \"2015-05-19T01:24:17.471806Z\",\n"
    "  \"objects_count\": 0,\n"
    "  \"metadata\": {},\n"
    "  \"revision\": 1,\n"
    "  \"other_permissions\": \"none\",\n"
    "  \"schema\": [\n"
    "    {\n"
    "      \"type\": \"string\",\n"
    "      \"name\": \"name\"\n"
    "    },\n"
    "    {\n"
    "      \"type\": \"string\",\n"
    "      \"name\": \"city\"\n"
    "    }\n"
    "  ]\n"
    "}";
  bool result = checkExistFromJsonDirty(JSON, "status");
  assertTrue(result);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Bridge.begin();

  // Set include to test which should be run
  Test::include("once_getInt");
  Test::include("once_getString");
  Test::include("once_getBool");
}

void loop() {
  Test::run();
}
