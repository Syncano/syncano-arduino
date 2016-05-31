/*! \file SyncanoRequest.h
*  \brief SyncanoRequest object with free function to manage SyncanoRequest
*/

/*! \class SyncanoRequest
*  \brief Class to manage requests
*/
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANOREQUEST_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANOREQUEST_H

#include "SyncanoSetup.h"
#include "SyncanoClient.h"
#include "SyncanoResponse.h"

class SyncanoRequest{
private:
  /**
   * @brief   SyncanoRequest connector
   */
  Connector connector;
  /**
   * @brief   Holds pointer to SyncanoClient
   */
  SyncanoClient* client;
  /**
   * @brief   Holds SyncanoResponse response
   */
  SyncanoResponse response;
  /**
   * @brief   Holds base url
   */
  String baseUrl;

  String getHTTPtype(SyncanoClient::HTTP httpType);
public:
  /**
   * @fn SyncanoRequest(SyncanoClient* client);
   * \brief Constructor with arguments
   *
   * Example Usage:
   * @code
   *    SyncanoRequest(client);
   * @endcode
   */
  SyncanoRequest(SyncanoClient* client);
  /**
   * @fn ~SyncanoRequest();
   * \brief Deconstructor
   *
   * Example Usage:
   * @code
   *    SyncanoClass sc = SyncanoClass();
   *    delete sc;
   * @endcode
   */
  ~SyncanoRequest();

  /**
   * @fn sendRequest(SyncanoClient::HTTP httpType, String url, String requestBody, bool async);
   * \brief Send request with type, url, request body
   *
   * @param SyncanoClient::HTTP [httpType] - set HTTP REST Method
   * @param String [url] - destination url
   * @param String [requestBody] - request body in JSON format
   * @param bool [async] - if set to 0 will run sync in other case async
   *
   * Example Usage:
   * @code
   *    response = sendRequest(SyncanoClient::HTTP::GET, "/INSTANCE_NAME/","{\"key\":\"value\"}", "QUERY")
   * @endcode
   */
  String sendRequest(SyncanoClient::HTTP httpType, String url, String requestBody="", bool async=0);
};
#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOREQUEST_H
