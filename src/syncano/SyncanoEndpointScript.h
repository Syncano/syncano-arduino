/*! \file SyncanoWebhook.h
 *  \brief SyncanoWebhook free run function
 */
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOENDPOINTSCRIPT_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOENDPOINTSCRIPT_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"

/**
 * @fn SyncanoEndpointScriptRun(String scriptName);
 * \brief Run SyncanoWebhook with script nsme
 *
 * @param String [scriptName] - The script name used to pull data.
 *
 * Example Usage:
 * @code
 *    String response = SyncanoEndpointScriptRun('script');
 * @endcode
 */
String SyncanoEndpointScriptRun(String scriptName);
/**
 * @fn SyncanoEndpointScriptRun(String scriptName, String JSON);
 * \brief Run SyncanoWebhook with script name and json data
 *
 * @param String [scriptName] - The script name used to pull data.
 * @param String [JSON] - JSON data package based on syncano HTTP API
 *
 * Example Usage:
 * @code
 *    String response = SyncanoEndpointScriptRun('script', "{\"key\":\"value\"}");
 * @endcode
 */
String SyncanoEndpointScriptRun(String scriptName, String JSON);
#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOENDPOINTSCRIPT_H
