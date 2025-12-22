
#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "HalApi.h"
#include "HalApiData.h"
#include "Convert.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

#define printobj(f, o) \
do {\
    std::cout << #f << std::endl;\
    o.printTo(std::cout);\
    std::cout << std::endl;\
} while(0)

#define printrsp(f, r) \
do {\
    std::cout << #f << std::endl;\
    std::cout << "response: " << r << std::endl;\
} while(0)

int main() {
  std::shared_ptr<TTransport> socket(new TSocket(DEF_THRIFT_ADDR, DEF_THRIFT_PORT));
  std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  HalApiClient client(protocol);

  try {
    transport->open();

    const int lens = 256;

    /* board */
    CMfg_rsp mfg;
    client.BOARD_GetChassisMfg(mfg);
    printobj(BOARD_GetChassisMfg, mfg);
  
    client.BOARD_GetSccMfg(mfg);
    printobj(BOARD_GetSccMfg, mfg);

    CBoardStatusData_rsp bdsta;
    client.BOARD_GetStatusData(bdsta);
    printobj(BOARD_GetStatusData, bdsta);

    client.FAN_GetMfg(mfg, FAN0);
    printobj(FAN_GetMfg, mfg);

    client.POWER_GetMfg(mfg, PWR0);
    printobj(POWER_GetMfg, mfg);

    string_rsp str;
    client.BOARD_GetProductName(str, lens);
    printobj(BOARD_GetProductName, str);

    /* OPS */
    client.OPS_GetMfg(mfg, DEV_TYPE_OPS);
    printobj(OPS_GetMfg, mfg);

    COpsCommStatusData_rsp opscomsta;
    client.OPS_GetCommStatusData(opscomsta, DEV_TYPE_OPS);
    printobj(OPS_GetCommStatusData, opscomsta);

    COpsStatusData_rsp opssta;
    client.OPS_GetStatusData(opssta, DEV_TYPE_OPS, OPS_SUB_INDEX_DEFAULT);
    printobj(OPS_GetStatusData, opssta);

    /* EDFA */
    client.EDFA_GetMfg(mfg, DEV_TYPE_BA);
    printobj(EDFA_GetMfg, mfg);
#if 0
    int32_t rsp = client.EDFA_SetGainRange(DEV_TYPE_BA, 0);
    printrsp(EDFA_SetGainRange, rsp);

    rsp = client.EDFA_SetGain(DEV_TYPE_BA, 150);
    printrsp(EDFA_SetGain, rsp);

    rsp = client.EDFA_SetAttn(DEV_TYPE_BA, 1234);
    printrsp(EDFA_SetAttn, rsp);
#endif
    COaCfgData_rsp cfg;
    client.EDFA_GetCfgData(cfg, DEV_TYPE_BA);
    printobj(EDFA_GetCfgData, cfg);

    COaStatusData_rsp sta;
    client.EDFA_GetStatusData(sta, DEV_TYPE_BA);
    printobj(EDFA_GetStatusData, sta);

    client.EDFA_GetStatusData(sta, DEV_TYPE_PA);
    printobj(EDFA_GetStatusData, sta);
    
  } catch(...) {

  }

  transport->close();

}