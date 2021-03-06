/*! \file SyncanoUtils.h
 *  \brief Syncano Utils for Syncano
 */
#ifndef SYNCANO_ARDUINOLIBRARY_SYNCANOUTILS_H
#define SYNCANO_ARDUINOLIBRARY_SYNCANOUTILS_H

#include <Arduino.h>

/**
 * @fn getStringFromJsonDirty(String JSON, String key)
 * \brief return String value from Json
 *
 * @param String [JSON] - String in Json format
 * @param String [key] - Field name to search for
 *
 * Example Usage:
 * @code
 *    getStringFromJsonDirty("exampleJson", "exampleFiled")
 * @endcode
 */
String getStringFromJsonDirty(String &JSON, String key);

#endif
