/*! \file SyncanoScript.h
 *  \brief SyncanoScript basic run functions
 */

#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOSCRIPT_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOSCRIPT_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"
#include "../lib/ArduinoJson/src/ArduinoJson.h"

/**
* @fn SyncanoScriptRun(int scriptId);
* \brief Run SyncanoScript
*
* @param int [scriptId] - script id
*
* Example Usage:
* @code
*	    String response = SyncanoScriptRun(1);
* @endcode
*/
String SyncanoScriptRun(int scriptId);


/**
* @fn SyncanoScriptRun(int scriptId,String JSON);
* \brief Run SyncanoScript
*
* @param int [scriptId] - script id
* @param String [JSON] - JSON data package based on syncano HTTP API
*
* Example Usage:
* @code
*	    String response = SyncanoScriptRun(1, "{\"payload\":{\"KEY\":\"VALUE\"}}");
* @endcode
*/
String SyncanoScriptRun(int scriptId,String JSON);

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOSCRIPT_H
