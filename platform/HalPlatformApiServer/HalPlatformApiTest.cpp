
#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "HalPlatformApi.h"
#include "HalPlatformData.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


int main() {
  std::shared_ptr<TTransport> socket(new TSocket(DEF_THRIFT_ADDR, DEF_THRIFT_PORT));
  std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  HalPlatformApiClient client(protocol);

  try {
    transport->open();

    string rst;
    bool bv;
    int iv;
    double dv;
    client.ChassisGetList(rst);
    cout << "ChassisGetList: " << rst << endl;
    client.ChassisGetName(rst);
    cout << "ChassisGetName: " << rst << endl;
    client.ChassisGetModel(rst);
    cout << "ChassisGetModel: " << rst << endl;
    client.ChassisGetSerial(rst);
    cout << "ChassisGetSerial: " << rst << endl;
    client.ChassisGetRevision(rst);
    cout << "ChassisGetRevision: " << rst << endl;
    client.ChassisGetBaseMac(rst);
    cout << "ChassisGetBaseMac: " << rst << endl;
    iv = client.ChassisGetSlot();
    cout << "ChassisGetSlot: " << iv << endl;
    client.ChassisGetRevision(rst);
    cout << "ChassisGetRevision: " << rst << endl;

    string psus[] = {"PSU0", "PSU1"};
    for (string name : psus) {
        client.PsuGetModel(rst, name);
        cout << name << " PsuGetModel: " << rst << endl;
        client.PsuGetSerial(rst, name);
        cout << name << " PsuGetSerial: " << rst << endl;
        client.PsuGetRevision(rst, name);
        cout << name << " PsuGetRevision: " << rst << endl;
        bv = client.PsuGetPresence(name);
        cout << name << " PsuGetPresence: " << bv << endl;
        bv = client.PsuGetStatus(name);
        cout << name << " PsuGetStatus: " << bv << endl;
        bv = client.PsuIsReplaceable(name);
        cout << name << " PsuIsReplaceable: " << bv << endl;
        dv = client.PsuGetVoltage(name);
        cout << name << " PsuGetVoltage: " << dv << endl;
        dv = client.PsuGetCurrent(name);
        cout << name << " PsuGetCurrent: " << dv << endl;
        dv = client.PsuGetPower(name);
        cout << name << " PsuGetPower: " << dv << endl;
        dv = client.PsuGetTemp(name);
        cout << name << " PsuGetTemp: " << dv << endl;
        dv = client.PsuGetInputVoltage(name);
        cout << name << " PsuGetInputVoltage: " << dv << endl;
        dv = client.PsuGetInputCurrent(name);
        cout << name << " PsuGetInputCurrent: " << dv << endl;
    }

    string fans[] = {"FAN0", "FAN1", "FAN2", "FAN3"};
    for (string name : fans) {
        client.FanGetModel(rst, name);
        cout << name << " FanGetModel: " << rst << endl;
        client.FanGetSerial(rst, name);
        cout << name << " FanGetSerial: " << rst << endl;
        iv = client.FanGetSpeed(name);
        cout << name << " FanGetSpeed: " << iv << endl;
    }
    

    string thermals[] = {"System Exhaust", "System Board", "System Intake"};
    for (string name : thermals) {
        dv = client.ThermalGetTemp(name);
        cout << name << " ThermalGetTemp: " << dv << endl;
    }

    string cards[] = {"LINE-CARD0", "LINE-CARD1", "LINE-CARD2", "LINE-CARD3", "SUPERVISOR0"};
    for (string name : cards) {
        client.ModuleGetModel(rst, name);
        cout << name << " ModuleGetModel: " << rst << endl;
        client.ModuleGetSerial(rst, name);
        cout << name << " ModuleGetSerial: " << rst << endl;
        client.ModuleGetRevision(rst, name);
        cout << name << " ModuleGetRevision: " << rst << endl;
        client.ModuleGetBaseMac(rst, name);
        cout << name << " ModuleGetBaseMac: " << rst << endl;
        iv = client.ModuleGetSlot(name);
        cout << name << " ModuleGetSlot: " << iv << endl;
        client.ModuleGetType(rst, name);
        cout << name << " ModuleGetType: " << rst << endl;
        client.ModuleGetStatus(rst, name);
        cout << name << " ModuleGetStatus: " << rst << endl;
        dv = client.ModuleGetTemp(name);
        cout << name << " ModuleGetTemp: " << dv << endl;
    }

    string components[] = {"BIOS", "FPGA", "CPLD", "ONIE", "OPS0-0", "OA1-0", "OA1-1", "OCM1-0", "OTDR1-0", "OA2-0", "OA2-1", "OCM2-0", "OTDR2-0", "MUX3-0"};
    for (string name : components) {
        client.ComponentGetFwVer(rst, name);
        cout << name << " ComponentGetFwVer: " << rst << endl;
    }
  } catch(...) {

  }

  transport->close();

}