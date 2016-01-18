/*! \file SyncanoDataObject.h
*  \brief Syncano data object with additional free functions
*/

/*! \class SyncanoDataObject
*  \brief Class used to manage local and remote Syncano Objects
*/
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANODATAOBJECT_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANODATAOBJECT_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"
#include "SyncanoClass.h"
#include "../lib/ArduinoJson/src/ArduinoJson.h"
#include "SyncanoUtils.h"

class SyncanoClass;

struct DataHolder;

class SyncanoDataObject
{
/**
 * @brief   Holds pointer to field value array
 */
DataHolder * fieldValue;
public:
  /**
   * @brief   Holds pointer to SyncanoClass object
   */
  SyncanoClass * masterClass;
  /**
   * @fn SyncanoDataObject();
   * \brief Default constructor
   *
   * Example Usage:
   * @code
   *  SyncanoDataObject* sdo;
   *  sdo = new SyncanoDataObject();
   * @endcode
   */
  SyncanoDataObject();
  /**
   * @fn SyncanoDataObject();
   * \brief Constructor taking pointer to SyncanoClassObject
   *
   * @param SyncanoClass* [incommingClass] - pointer to SyncanoClass object
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc;
   *  sc = new SyncanoClass("ClassName");
   *  SyncanoDataObject* sdo;
   *  sdo = new SyncanoDataObject(sc);
   * @endcode
   */
  SyncanoDataObject(SyncanoClass* incommingClass);
  /**
   * @fn ~SyncanoDataObject()
   * \brief Default deconstructor
   */
  ~SyncanoDataObject();
  /**
   * @fn add()
   * \brief Create remote Syncano object based on local class object. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField","exampleValue");
   *  sdo->add();
   * @endcode
   */
  bool add();
  /**
   * @fn details(int id)
   * \brief Create local object based on data fetch from Syncano. Without any parameter it will use id of local object if is set. Function returns TRUE if process was successful, FALSE in other case.
   *
   * @param int [id = -1] - remote object ID
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("id");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->add();
   *  sdo->details()	// Create local object with id of created object
   *  sdo->details(123)	// Create local object with id = 123
   * @endcode
   */
  bool details(int id = -1);
  /**
   * @fn update()
   * \brief Update remote Syncano object. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField","exampleValue");
   *  sdo->update();
   * @endcode
   */
  bool update();
  /**
   * @fn remove()
   * \brief Delete Syncano remote object. Local object fields are set empty String.
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("id");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("id","123");
   *  sdo->remove();
   * @endcode
   */
  void remove();
  /**
   * @fn printDetails()
   * \brief Print to Serial local object field name and value.
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->details(123)
   *  sdo->printDetails()
   * @endcode
   */
  void printDetails();
  /**
   * @fn setFieldValue(String fieldName, String fieldValue)
   * \brief Set local object fieldName and its value. Object must be first created in class object.
   *
   * @param String [fieldName] - field name
   * @param String [fieldValue] - field value
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField","exampleValue");
   * @endcode
   */
  void setFieldValue(String fieldName, String fieldValue);
  /**
   * @fn setFieldValue(String fieldName, int fieldValue)
   * \brief Set local object fieldName and its value. Object must be first created in class object.
   *
   * @param String [fieldName] - field name
   * @param int [fieldValue] - field value
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField",44);
   * @endcode
   */
  void setFieldValue(String fieldName, int fieldValue);
  /**
   * @fn setFieldValue(String fieldName, float fieldValue)
   * \brief Set local object fieldName and its value. Object must be first created in class object.
   *
   * @param String [fieldName] - field name
   * @param float [fieldValue] - field value
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField",15.15);
   * @endcode
   */
  void setFieldValue(String fieldName, float fieldValue);
  /**
   * @fn getFieldValue(String fieldName)
   * \brief Return value of selected field
   *
   * @param String [fieldName] - field name
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->getFieldValue("exampleField");
   * @endcode
   */
  String getFieldValue(String fieldName);
  /**
   * @fn JSONencode()
   * \brief Create String formatted as Json from object fields
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  sdo->setFieldValue("exampleField","exampleValue");
   *  Serial.println(sdo->JSONencode());
   * @endcode
   */
  String JSONencode();
  /**
   * @fn JSONdecode(String capture)
   * \brief Decode Json and fill object fields with values from Json. Function returns TRUE if process was successful, FALSE in other case.
   *
   * @param String [capture] - String from response to decode
   *
   * Example Usage:
   * @code
   *  SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *  sc->addField("exampleField");
   *  sc->initClass();
   *  SyncanoDataObject* sdo = sc->initObject();
   *  String capture = request.sendRequest("GET","instances/INSTANCE_NAME/classes/CLASS_NAME/objects/OBJECT_ID/");
   *  sdo->JSONdecode(String capture);
   * @endcode
   */
  bool JSONdecode(String capture);
};

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANODATACREATE_H
