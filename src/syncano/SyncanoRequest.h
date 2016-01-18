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
   * @fn sendRequest(String httpType, String url);
   * \brief Send request with type and url
   *
   * @param String [httpType] - set HTTP REST Method
   * @param String [url] - destination url
   * @param bool [async] - if set to 0 will run sync in other case async
   *
   * Example Usage:
   * @code
   *    response = sendRequest("GET", "/INSTANCE_NAME/")
   * @endcode
   */
  String sendRequest(String httpType, String url, bool async=0);
  /**
   * @fn sendRequest(String httpType, String url, String requestBody);
   * \brief Send request with type, url and request body
   *
   * @param String [httpType] - set HTTP REST Method
   * @param String [url] - destination url
   * @param String [requestBody] - request body in JSON format
   * @param bool [async] - if set to 0 will run sync in other case async
   *
   * Example Usage:
   * @code
   *    response = sendRequest("GET", "/INSTANCE_NAME/","{\"key\":\"value\"}")
   * @endcode
   */
  String sendRequest(String httpType, String url, String requestBody, bool async=0);
  /**
   * @fn sendRequest(String httpType, String url, String requestBody, String requestQuery);
   * \brief Send request with type, url, request body and request query
   *
   * @param String [httpType] - set HTTP REST Method
   * @param String [url] - destination url
   * @param String [requestBody] - request body in JSON format
   * @param String [requestQuery] - request query
   * @param bool [async] - if set to 0 will run sync in other case async
   *
   * Example Usage:
   * @code
   *    response = sendRequest("GET", "/INSTANCE_NAME/","{\"key\":\"value\"}", "QUERY")
   * @endcode
   */
  String sendRequest(String httpType, String url, String requestBody, String requestQuery, bool async=0);
};
#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANOREQUEST_H
