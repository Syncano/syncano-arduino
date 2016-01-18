/*! \file SyncanoResponse.h
*  \brief SyncanoResponse object with free function to manage SyncanoResponse
*/
/*! \class SyncanoResponse
*  \brief Class to manage SyncanoResponse
*/
#ifndef SYNCANO_ARDUINO_LIBRARY_SYNCANORESPONSE_H
#define SYNCANO_ARDUINO_LIBRARY_SYNCANORESPONSE_H

#include "SyncanoSetup.h"

class SyncanoResponse{
private:
  /**
   * @brief   SyncanoResponse connector
   */
  Connector connector;
public:
  /**
   * \fn SyncanoResponse();
   * \brief Constructor without arguments
   *
   * Example Usage:
   * @code
   *    SyncanoResponse();
   * @endcode
   */
  SyncanoResponse();
  /**
   * \fn ~SyncanoResponse();
   * \brief Deconstructor
   *
   * Example Usage:
   * @code
   *    SyncanoResponse sr = new SyncanoResponse();
   *    delete sr;
   * @endcode
   */
  ~SyncanoResponse();
  /**
   * @fn String getResponseToString(Connector connector);
   * \brief Return response
   *
   * @param Connector [connector] - instance of connector
   *
   * Example Usage:
   * @code
   *    getResponseToString(connector);
   * @endcode
   */
  String getResponseToString(Connector & connector);
};

#endif //SYNCANO_ARDUINO_LIBRARY_SYNCANORESPONSE_H
