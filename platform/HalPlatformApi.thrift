
service HalPlatformApi {
    /* PSU */
    string PsuGetModel(1:string name),
    string PsuGetSerial(1:string name),
    string PsuGetRevision(1:string name),
    bool PsuGetPresence(1:string name),
    bool PsuGetStatus(1:string name),
    bool PsuIsReplaceable(1:string name),
    double PsuGetVoltage(1:string name),
    double PsuGetCurrent(1:string name),
    double PsuGetPower(1:string name),
    double PsuGetTemp(1:string name),
    double PsuGetInputVoltage(1:string name),
    double PsuGetInputCurrent(1:string name),
    string PsuGetLedState(1:string name),
    bool PsuSetLedState(1:string name, 2:string state),

    /* FAN */
    string FanGetModel(1:string name),
    string FanGetSerial(1:string name),
    string FanGetRevision(1:string name),
    bool FanGetPresence(1:string name),
    bool FanGetStatus(1:string name),
    bool FanIsReplaceable(1:string name),
    string FanGetDirection(1:string name),
    i32 FanGetSpeed(1:string name),
    i32 FanGetTargetSpeed(1:string name),
    i32 FanGetSpeedTolerance(1:string name),
    bool FanSetSpeed(1:string name, 2:i32 speed),
    string FanGetLedState(1:string name),
    bool FanSetLedState(1:string name, 2:string state),
    i32 FanGetPositionInParent(1:string name),

    /* FAN_DRAWER */
    bool FanDrawerGetPresence(1:string name),
    bool FanDrawerGetStatus(1:string name),
    bool FanDrawerIsReplaceable(1:string name),
    string FanDrawerGetLedState(1:string name),
    bool FanDrawerSetLedState(1:string name, 2:string state),

    /* LED */
    string LedGetState(1:string name),
    bool LedSetState(1:string name, 2:string state),

    /* THERMAL */
    double ThermalGetTemp(1:string name),
    double ThermalGetHighThreshold(1:string name),
    double ThermalGetLowThreshold(1:string name),
    bool ThermalSetHighThreshold(1:string name, 2:double value),
    bool ThermalSetLowThreshold(1:string name, 2:double value),
    double ThermalGetHighCriticalThreshold(1:string name),
    double ThermalGetLowCriticalThreshold(1:string name),
    bool ThermalSetHighCriticalThreshold(1:string name, 2:double value),
    bool ThermalSetLowCriticalThreshold(1:string name, 2:double value),
    double ThermalGetMinimumRecorded(1:string name),
    double ThermalGetMaximumRecorded(1:string name),

    /* WATCHDOG */
    bool WatchDogArm(1:i32 index, 2:i32 seconds),
    bool WatchDogDisrm(1:i32 index),
    bool WatchDogIsArmed(1:i32 index),

    /* CHASSIS */
    string ChassisGetName(),
    string ChassisGetModel(),
    string ChassisGetSerial(),
    string ChassisGetRevision(),
    string ChassisGetBaseMac(),
    i32 ChassisGetSlot(),
    string ChassisGetLedState(),
    bool ChassisSetLedState(1:string state),
    string ChassisGetList(),
    bool ChassisIsModular(),

    /* MODULE */
    string ModuleGetModel(1:string name),
    string ModuleGetSerial(1:string name),
    string ModuleGetRevision(1:string name),
    string ModuleGetBaseMac(1:string name),
    i32 ModuleGetSlot(1:string name),
    string ModuleGetType(1:string name),
    string ModuleGetStatus(1:string name),
    double ModuleGetTemp(1:string name),
    string ModuleGetLedState(1:string name),
    bool ModuleSetLedState(1:string name, 2:string state),

    /* COMPONENT */
    string ComponentGetFwVer(1:string name)
}