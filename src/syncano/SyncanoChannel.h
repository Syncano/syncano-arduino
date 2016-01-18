/*! \file SyncanoChannel.h
 *  \brief Syncano channel with additional free functions
 */

/*! \class SyncanoChannel
 *  \brief Syncano channel used to manage local and remote Syncano channels
 */
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOCHANNEL_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOCHANNEL_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"
#include "SyncanoDataObject.h"

class SyncanoDataObject;

class SyncanoChannel
{
  /**
   * @brief   Holds Syncano channel name
   */
  String channelName;
  /**
   * @brief   Holds Syncano channel description
   */
  String channelDescription;
  /**
   * @brief   Holds Syncano channel type
   */
  char channelType;
  /**
   * @brief   Holds pointer to object used as data container
   */
  SyncanoDataObject* dataObject;
public:
  /**
   * @fn SyncanoChannel();
   * \brief Default constructor
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc;
   *    sc = new SyncanoChannel();
   * @endcode
   */
  SyncanoChannel();
  /**
   * @fn SyncanoChannel(String incChannelName);
   * \brief Constructor taking channel name
   *
   * @param String [incChannelName] - channel name
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc;
   *    sc = new SyncanoChannel("ChannelName");
   * @endcode
   */
  SyncanoChannel(String incChannelName);
  /**
   * @fn SyncanoChannel(String incChannelName, String incChannelDesc);
   * \brief Constructor taking channel name
   *
   * @param String [incChannelName] - channel name
   * @param String [incChannelDesc] - channel description
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc;
   *    sc = new SyncanoChannel("ChannelName","ChannelDesc");
   * @endcode
   */
  SyncanoChannel(String incChannelName, String incChannelDesc);
  /**
   * @fn SyncanoChannel(String incChannelName, String incChannelDesc, String incChannelType);
   * \brief Constructor taking channel name
   *
   * @param String [incChannelName] - channel name
   * @param String [incChannelDesc] - channel description
   * @param String [incChannelType] - channel type
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc;
   *    sc = new SyncanoChannel("ChannelName","ChannelDesc","default");
   * @endcode
   */
  SyncanoChannel(String incChannelName, String incChannelDesc, String incChannelType);
  /**
   * @fn ~SyncanoChannel()
   * \brief Default deconstructor
   */
  ~SyncanoChannel();
  /**
   * @fn add()
   * \brief Create remote Syncano channel based on local channel object. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName","ChannelDesc");
   *    sc->add();
   * @endcode
   */
  bool add();
  /**
   * @fn details()
   * \brief Update local channel object with data fetch from Syncano. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    sc->details();
   *    sc->printDetails();
   * @endcode
   */
  bool details();
  /**
   * @fn poll()
   * \brief Poll channel, on data income parse JSON and place all data in object container. Function returns TRUE if process was successful, FALSE in other case.
   *
   * Example Usage:
   * @code
   *    SyncanoClass* class = new SyncanoClass("ExampleClass");
   *    class->addField("state");
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    SyncanoDataObject* object = class->initObject();
   *    sc->setObject(object);
   *    sc->poll();
   *    object->printDetails();
   * @endcode
   */
  bool poll();
  /**
   * @fn publish(String fieldName, String fieldValue)
   * \brief Publish data in Syncano channel.
   *
   * @param String [fieldName] - key used in publish
   * @param String [fieldValue] - value used in publish
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    sc->publish("FieldName","FieldValue");
   * @endcode
   */
  void publish(String fieldName, String fieldValue);
  /**
   * @fn remove()
   * \brief Remove channel from Syncano.
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    sc->remove();
   * @endcode
   */
  void remove();
  /**
   * @fn JSONencode()
   * \brief Returns JSON in String format, contains data from local channel object.
   */
  String JSONencode();
  /**
   * @fn JSONpollDecode(String capture)
   * \brief Parse string as JSON object with channel polled data, filling local data object fields with data from JSON.
   *
   * @param String [capture] - response JSON in String format
   */
  bool JSONpollDecode(String & capture);
  /**
   * @fn JSONdecode(String capture)
   * \brief Parse string as JSON object with channel polled data, filling local channel object with data from JSON.
   *
   * @param String [capture] - response JSON in String format
   */
  bool JSONdecode(String capture);
  /**
   * @fn printDetails()
   * \brief Prints channel name, description and data object information to Serial output
   *
   * Example Usage:
   * @code
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    sc->printDetails();
   * @endcode
   */
  void printDetails();
  /**
   * @fn setObject(SyncanoDataObject* incObject)
   * \brief Select data object to use as data container. One data object can be connected to one channel.
   *
   * @param SyncanoDataObject* [incObject] - pointer to Syncano data object
   *
   * Example Usage:
   * @code
   *    SyncanoClass* class = new SyncanoClass("ExampleClass");
   *    class->addField("state");
   *    SyncanoChannel* sc = new SyncanoChannel("ChannelName");
   *    SyncanoDataObject* object = class->initObject();
   *    sc->setObject(object);
   * @endcode
   */
  void setObject(SyncanoDataObject* incObject);
  /**
   * @fn simpleEnum(String value)
   * \brief Simple function used to convert String type name to short char.
   *
   * @param String [value] - variable
   *
   * Example Usage:
   * @code
   *   char type = simpleEnum("default");
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
   *   String type = simpleEnum('0');
   * @endcode
   */
  String simpleEnum(char value);
};

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOCHANNEL_H
