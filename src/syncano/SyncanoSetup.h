/*! \file SyncanoSetup.h
*  \brief SyncanoSetup object with free function to manage SyncanoSetup
*/

#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOSETUP_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOSETUP_H

#include <Arduino.h>

#ifdef ARDUINO_AVR_YUN

  #include <Bridge.h>
  typedef Process Connector;

#elif ARDUINO_AVR_UNO

  //TODO

#endif

#endif
