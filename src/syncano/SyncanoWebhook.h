/*! \file SyncanoWebhook.h
 *  \brief SyncanoWebhook object with free function to manage SyncanoWebhook
 */
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOWEBHOOK_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOWEBHOOK_H

#include "SyncanoClient.h"
#include "SyncanoRequest.h"

/**
 * @fn SyncanoWebhooksRun(String webhookName);
 * \brief Run SyncanoWebhook with webhook nsme
 *
 * @param String [webhookName] - The webhook name used to pull data.
 *
 * Example Usage:
 * @code
 *    String response = SyncanoWebhooksRun('webhook');
 * @endcode
 */
String SyncanoWebhooksRun(String webhookName);
/**
 * @fn SyncanoWebhooksRun(String webhookName, String JSON);
 * \brief Run SyncanoWebhook with webhook name and json data
 *
 * @param String [webhookName] - The webhook name used to pull data.
 * @param String [JSON] - JSON data package based on syncano HTTP API
 *
 * Example Usage:
 * @code
 *    String response = SyncanoWebhooksRun('webhook', "{\"key\":\"value\"}");
 * @endcode
 */
String SyncanoWebhooksRun(String webhookName, String JSON);
#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOWEBHOOK_H
