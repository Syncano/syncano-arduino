/*! \file SyncanoClass.h
 *  \brief Syncano class with additional free functions
 */

/*! \class SyncanoClass
 *  \brief Syncano class used to manage local and remote Syncano classes
 */
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOCLASS_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOCLASS_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"
#include "SyncanoDataObject.h"
#include "SyncanoUtils.h"

class SyncanoDataObject;

class SyncanoClass
{
  /**
   * @brief   Holds pointer to char array, containing field type information
   */
  char * type;
  /**
   * @brief   Holds pointer to String array, containing field names
   */
  String * name;
  /**
   * @brief   Holds pointer to SyncanoClass name table
   */
  int fieldCount;
  /**
   * @brief   Holds Syncano class name
   */
  String className;
  /**
   * @brief   Holds Syncano class description
   */
  String classDescription;
  /**
   * @brief   Holds fields names, used to initialize class
   */
  String holder;
  public:
  /**
   * @fn SyncanoClass();
   * \brief Default constructor
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc;
   *   sc = new SyncanoClass();
   * @endcode
   */
  SyncanoClass();
  /**
   * @fn SyncanoClass(String incClassName);
   * \brief Constructor taking class name
   *
   * @param String [incClassName] - class name
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc;
   *   sc = new SyncanoClass("ClassName");
   * @endcode
   */
  SyncanoClass(String incClassName);
  /**
   * @fn SyncanoClass(String incClassName, String incClassDescription)
   * \brief Constructor taking class name and description
   *
   * @param String [incClassName] - class name
   * @param String [incClassDescription] - class description
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc;
   *   sc = new SyncanoClass("ClassName","Description");
   * @endcode
   */
  SyncanoClass(String incClassName, String incClassDescription);
  /**
   * @fn ~SyncanoClass()
   * \brief Default deconstructor
   */
  ~SyncanoClass();
  /**
   * @fn add()
   * \brief Create remote Syncano class based on local class object. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->add();
   * @endcode
   */
  bool add();
  /**
   * @fn details()
   * \brief Create local class based on data fetch from Syncano. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->details();
   *   sc->printDetails();
   * @endcode
   */
  bool details();
  /**
   * @fn remove()
   * \brief Delete Syncano class on remote. Local class fields are set to 0 or empty String ( depends on field type ).
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->remove();
   * @endcode
   */
  void remove();
  /**
   * @fn JSONencode()
   * \brief Returns JSON in String format, contains data from local class object.
   */
  String JSONencode();
  /**
   * @fn JSONdecode(String capture)
   * \brief Parse string as JSON object with class data, filling local class object fields with data from JSON.
   *
   * @param String [capture] - class name
   */
  bool JSONdecode(String capture);
  /**
   * @fn initClass()
   * \brief Function initialize name and type fields with data from holder variable.
   */
  void initClass();
  /**
   * @fn addField(String fieldName)
   * \brief Adds new class field with name passed as parameter. Field type will be set as String.
   *
   * @param String [fieldName] - field name
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->addField("id");
   *   sc->printDetails();
   * @endcode
   */
  void addField(String fieldName);
  /**
   * @fn addField(String fieldType, String fieldName)
   * \brief Adds new class field with name and type passed as parameter.
   *
   * @param String [fieldName] - field name
   * @param String [fieldType] - field type
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->addField("string","id");
   *   sc->printDetails();
   * @endcode
   */
  void addField(String fieldType, String fieldName);
  /**
   * @fn setField(String oldfieldName, String newfieldName)
   * \brief Set new field name.
   *
   * @param String [oldfieldName] - old field name
   * @param String [newfieldName] - new field name
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->addField("string","id");
   *   sc->setField("id","firstname");
   *   sc->printDetails();
   * @endcode
   */
  void setField(String oldfieldName, String newfieldName);
  /**
   * @fn simpleEnum(String value)
   * \brief Simple function used to convert String type name to short char.
   *
   * @param String [value] - variable
   *
   * Example Usage:
   * @code
   *   char data = simpleEnum("string");
   * @endcode
   */
  char simpleEnum(String value);
  /**
   * @fn simpleEnum(char value)
   * \brief Simple function used to convert char to String type name.
   *
   * @param char [value] - variable
   *
   * Example Usage:
   * @code
   *   String data = simpleEnum('0');
   * @endcode
   */
  String simpleEnum(char value);
  /**
   * @fn SyncanoDataObject* initObject()
   * \brief Initialize object based on local class fields
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->addField("string","id");
   *   SyncanoDataObject* object = sc->initObject();
   * @endcode
   */
  SyncanoDataObject* initObject();
  /**
   * @fn getClassDescription()
   * \brief Returns local class description
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   String desc = sc->getDescription();
   * @endcode
   */
  String getClassDescription();
  /**
   * @fn getClassName()
   * \brief Returns local class name
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   String name = sc->getName();
   * @endcode
   */
  String getClassName();
  /**
   * @fn getFieldCount()
   * \brief Returns class field count
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   int count = sc->getFieldCount();
   * @endcode
   */
  int getFieldCount();
  /**
   * @fn getFieldName(int position)
   * \brief Returns class field name based on int position. Used by ex.Data Object to implement simple dictionary.
   *
   * @param int [position] - field position
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   String fieldName = sc->getFieldName(2);
   * @endcode
   */
  String getFieldName(int position);
  /**
   * @fn getFieldIdByFieldName(String fieldName)
   * \brief Returns class field position. Used by ex.Data Object to implement simple dictionary.
   *
   * @param String [fieldName] - field position
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   int fieldName = sc->getFieldIdByFieldName("firstname");
   * @endcode
   */
  int getFieldIdByFieldName(String fieldName);
  /**
   * @fn printDetails()
   * \brief Prints class name, description with all fields with types to Serial output
   *
   * Example Usage:
   * @code
   *   SyncanoClass* sc = new SyncanoClass("ClassName","Description");
   *   sc->printDetails();
   * @endcode
   */
  void printDetails();
};

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOCLASS_H
