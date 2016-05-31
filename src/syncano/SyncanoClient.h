/*! \file SyncanoClient.h
 *  \brief SyncanoClient object with free function to manage SyncanoClient
 */

/*! \class SyncanoClient
 *  \brief Class to manage SyncanoClient
 */
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOCLIENT_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOCLIENT_H

#include "SyncanoSetup.h"

class SyncanoClient {
private:
  /**
   * @brief   Holds client Api Key
   */
  String clientApiKey = "0";
  /**
   * @brief   Holds instance name
   */
  String instanceName = "";
public:

  /**
   * @brief   enumerator for HTTP REST methods
   */
  enum class HTTP {
    GET,
    POST,
    PATCH,
    DELETE
  };

  /**
   * @fn SyncanoClient();
   * \brief Create Syncano Client object
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient();
   * @endcode
   */
  SyncanoClient();

  /**
   * @fn SyncanoClient(String clientApiKey);
   * \brief Create Syncano Client object with passed api key
   *
   * @param String [clientApiKey] - client api key
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient("<API_KEY>");
   * @endcode
   */
  SyncanoClient(String clientApiKey);

  /**
   * @fn ~SyncanoClient();
   * \brief Delete Syncano Client object
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient();
   *    delete sc;
   * @endcode
   */
  ~SyncanoClient();


  /**
   * @fn setInstanceName(String instanceName);
   * \brief Set instance name
   *
   * @param String [instanceName] - instance name
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient();
   *    sc.setInstanceName("instancename");
   * @endcode
   */
  void setInstanceName(String instanceName);

  /**
   * @fn getApiKey();
   * \brief Return Api Key from client
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient();
   *    String apikey = sc.getApiKey();
   * @endcode
   */
  String getApiKey();

  /**
   * @fn getInstanceName();
   * \brief Get instance name
   *
   * Example Usage:
   * @code
   *    SyncanoClient sc = SyncanoClient();
   *    String instanceName = sc.getInstanceName();
   * @endcode
   */
  String getInstanceName();
};
extern SyncanoClient* Syncano;
/**
 * @fn initSyncanoClient(String apiKey);
 * \brief Initialize Syncano object
 *
 * @param String [apiKey] - syncano user api key
 *
 * Example Usage:
 * @code
 *    initSyncanoClient('uxfg98bvcby87cv0dsdkcx');
 * @endcode
 */
void initSyncanoClient(String apiKey);

/**
 * @fn getSyncanoClient();
 * \brief Get Syncano client object
 *
 * Example Usage:
 * @code
 *    getSyncanoClient();
 * @endcode
 */
SyncanoClient* getSyncanoClient();

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOCLIENT_H
