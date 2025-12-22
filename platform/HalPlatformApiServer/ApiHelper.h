#pragma once
#include "Json.hpp"
#include "HalPlatformData.h"
#include "HalPlatformApi.h"
#include "virtual_platform.h"

using pctstr = const char *;
using string = std::string;
using json = nlohmann::json;
using pairii = std::pair<int32_t, int32_t>;

class DevDesc
{
public:
    DevDesc(int32_t iItemType, string strItemName, string strItemDesc) : \
        m_iItemType(iItemType), m_strItemName(strItemName), m_strItemDesc(strItemDesc)
    {
    }

    int32_t
    GetItemType(void) const
    {
        return m_iItemType;
    }

    const string &
    GetItemName(void) const
    {
        return m_strItemName;
    }

    const string &
    GetItemDesc(void) const
    {
        return m_strItemDesc;
    }

    bool
    IsName(const string &name) const
    {
        return name == m_strItemName;
    }

private:
    int32_t m_iItemType;
    string m_strItemName;
    string m_strItemDesc;
};

using mapid = const std::map<int32_t, DevDesc>;
using mapib = std::map<int32_t, bool>;
using mapii = std::map<int32_t, int32_t>;
using mapis = std::map<int32_t, string>;
using mapsi = std::map<string, int32_t>;
using mapsd = std::map<string, double>;

class ApiHelper : public HalPlatformApiIf
{
public:
    ApiHelper():
        mgr(virtual_platform::instance()) {}

    ~ApiHelper() = default;

    const json &GetDevicesList(void);

    /* thrift api */
    void PsuGetModel(std::string& _return, const std::string& name) override;
    void PsuGetSerial(std::string& _return, const std::string& name) override;
    void PsuGetRevision(std::string& _return, const std::string& name) override;
    bool PsuGetPresence(const std::string& name) override;
    bool PsuGetStatus(const std::string& name) override;
    bool PsuIsReplaceable(const std::string& name) override;
    double PsuGetVoltage(const std::string& name) override;
    double PsuGetCurrent(const std::string& name) override;
    double PsuGetPower(const std::string& name) override;
    double PsuGetTemp(const std::string& name) override;
    double PsuGetInputVoltage(const std::string& name) override;
    double PsuGetInputCurrent(const std::string& name) override;
    void PsuGetLedState(std::string& _return, const std::string& name) override;
    bool PsuSetLedState(const std::string& name, const std::string& state) override;
    void FanGetModel(std::string& _return, const std::string& name) override;
    void FanGetSerial(std::string& _return, const std::string& name) override;
    void FanGetRevision(std::string& _return, const std::string& name) override;
    bool FanGetPresence(const std::string& name) override;
    bool FanGetStatus(const std::string& name) override;
    bool FanIsReplaceable(const std::string& name) override;
    void FanGetDirection(std::string& _return, const std::string& name) override;
    int32_t FanGetSpeed(const std::string& name) override;
    int32_t FanGetTargetSpeed(const std::string& name) override;
    int32_t FanGetSpeedTolerance(const std::string& name) override;
    bool FanSetSpeed(const std::string& name, const int32_t speed) override;
    void FanGetLedState(std::string& _return, const std::string& name) override;
    bool FanSetLedState(const std::string& name, const std::string& state) override;
    int32_t FanGetPositionInParent(const std::string& name) override;
    bool FanDrawerGetPresence(const std::string& name) override;
    bool FanDrawerGetStatus(const std::string& name) override;
    bool FanDrawerIsReplaceable(const std::string& name) override;
    void FanDrawerGetLedState(std::string& _return, const std::string& name) override;
    bool FanDrawerSetLedState(const std::string& name, const std::string& state) override;
    void LedGetState(std::string& _return, const std::string& name) override;
    bool LedSetState(const std::string& name, const std::string& state) override;
    double ThermalGetTemp(const std::string& name) override;
    double ThermalGetHighThreshold(const std::string& name) override;
    double ThermalGetLowThreshold(const std::string& name) override;
    bool ThermalSetHighThreshold(const std::string& name, const double value) override;
    bool ThermalSetLowThreshold(const std::string& name, const double value) override;
    double ThermalGetHighCriticalThreshold(const std::string& name) override;
    double ThermalGetLowCriticalThreshold(const std::string& name) override;
    bool ThermalSetHighCriticalThreshold(const std::string& name, const double value) override;
    bool ThermalSetLowCriticalThreshold(const std::string& name, const double value) override;
    double ThermalGetMinimumRecorded(const std::string& name) override;
    double ThermalGetMaximumRecorded(const std::string& name) override;
    bool WatchDogArm(const int32_t index, const int32_t seconds) override;
    bool WatchDogDisrm(const int32_t index) override;
    bool WatchDogIsArmed(const int32_t index) override;
    void ChassisGetName(std::string& _return) override;
    void ChassisGetModel(std::string& _return) override;
    void ChassisGetSerial(std::string& _return) override;
    void ChassisGetRevision(std::string& _return) override;
    void ChassisGetBaseMac(std::string& _return) override;
    int32_t ChassisGetSlot() override;
    void ChassisGetLedState(std::string& _return) override;
    bool ChassisSetLedState(const std::string& state) override;
    void ChassisGetList(std::string& _return) override;
    bool ChassisIsModular() override;
    void ModuleGetModel(std::string& _return, const std::string& name) override;
    void ModuleGetSerial(std::string& _return, const std::string& name) override;
    void ModuleGetRevision(std::string& _return, const std::string& name) override;
    void ModuleGetBaseMac(std::string& _return, const std::string& name) override;
    int32_t ModuleGetSlot(const std::string& name) override;
    void ModuleGetType(std::string& _return, const std::string& name) override;
    void ModuleGetStatus(std::string& _return, const std::string& name) override;
    double ModuleGetTemp(const std::string& name) override;
    void ModuleGetLedState(std::string& _return, const std::string& name) override;
    bool ModuleSetLedState(const std::string& name, const std::string& state) override;
    void ComponentGetFwVer(std::string& _return, const std::string& name) override;

private:
    string GetChassisName(void);
    int32_t GetChassisSlot(void);
    bool IsPsuFan(const string &name);
    int32_t GetDevIndex(const string &name);
    int32_t GetModuleType(const string &name);
    pairii GetModuleInfo(const string &name);
    double GetThermalTemp(const string &name);
    const DevDesc *GetDevDesc(int32_t id, bool isCard = false);
    int32_t GetDevType(const string &name);
    int32_t RecordDevIndex(const string &strComponentType);
    void GetThermalNames(void);
    string GetLedState(int32_t index);
    bool SetLedState(int32_t index, const string &state);

    static mapid m_modules;
    static mapid m_components;
    json m_json;
    mapsi m_idxs;
    mapsi m_devs;
    mapis m_thermals;
    mapsi m_fanTarSpd;
    mapsd m_thermalHighThres;
    mapsd m_thermalLowThres;
    mapsd m_thermalHighCriticalThres;
    mapsd m_thermalLowCriticalThres;
    mapsd m_thermalMinRecord;
    mapsd m_thermalMaxRecord;
    mapib m_wdArmed;

    virtual_platform& mgr;
};


// Generic helper to ensure a device exists in the virtual platform
template <typename T>
T* ensure_virtual_device(virtual_platform& mgr, const std::string& name)
{
    // Try to get an existing device
    auto* dev = mgr.get_device<T>(name);
    if (dev)
        return dev;

    // Otherwise, create it
    dev = mgr.create_device<T>(name);
    if (!dev)
        return nullptr;

    // perform per-device setup
    if (std::is_same<T, virtual_module_device>::value ||
        std::is_same<T, virtual_psu_device>::value ||
        std::is_same<T, virtual_fan_device>::value ||
        std::is_same<T, virtual_thermal_device>::value) {
            dev->update_data(mgr.count_devices_of_type<T>());
    }

    return dev;
}
