/*! \file SyncanoCodeBox.h
 *  \brief SyncanoCodeBox object with free function to manage SyncanoCodeBox
 */

#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOCODEBOX_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOCODEBOX_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"
#include "../lib/ArduinoJson/src/ArduinoJson.h"

/**
* @fn SyncanoCodeBoxRun(int codeBoxId);
* \brief Run SyncanoCodeBox
*
* @param int [codeBoxId] - codebox id
*
* Example Usage:
* @code
*	    String response = SyncanoCodeBoxRun(1);
* @endcode
*/
String SyncanoCodeBoxRun(int codeBoxId);


/**
* @fn SyncanoCodeBoxRun(int codeBoxId,String JSON);
* \brief Run SyncanoCodeBox
*
* @param int [codeBoxId] - codebox id
* @param String [JSON] - JSON data package based on syncano HTTP API
*
* Example Usage:
* @code
*	    String response = SyncanoCodeBoxRun(1, "{\"payload\":{\"KEY\":\"VALUE\"}}");
* @endcode
*/
String SyncanoCodeBoxRun(int codeBoxId,String JSON);

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOCODEBOX_H
