#include "ApiHelper.h"
#include "Convert.h"

#include "util_cmn.h"

#define CHECK_RSP(rsp) \
do {\
    if ((rsp) == OPLK_ERR) {\
        return;\
    }\
} while(0)


void
ApiHelper::BOARD_GetChassisMfg(CMfg_rsp& _return)
{
    CMfg data = {0};
    _return.response = ::BOARD_GetChassisMfg(&data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

int32_t
ApiHelper::BOARD_SetChassisMfg(const std::string& pcFilePath)
{
    return ::BOARD_SetChassisMfg(pcFilePath.data());
}

int32_t
ApiHelper::BOARD_SetChassisConfigType(const std::string& pcConfigType)
{
    return ::BOARD_SetChassisConfigType(pcConfigType.data());
}

void
ApiHelper::BOARD_GetChassisCali(CCali_rsp& _return)
{
    CCali data = {0};
    _return.response = ::BOARD_GetChassisCali(&data);
    CHECK_RSP(_return.response);
    Convert::ToCCali_t(_return.data, data);
}

int32_t
ApiHelper::BOARD_SetChassisCali(const std::string& pcFilePath)
{
    return ::BOARD_SetChassisCali(pcFilePath.data());
}

int32_t
ApiHelper::BOARD_GetChassisCfg(const int32_t uiAddrSlice, const std::string& pcFilePath)
{
    return ::BOARD_GetChassisCfg(uiAddrSlice, pcFilePath.data());
}

int32_t
ApiHelper::BOARD_SetChassisCfg(const int32_t uiAddrSlice, const int32_t uiSize, const std::string& pcFilePath)
{
    return ::BOARD_SetChassisCfg(uiAddrSlice, uiSize, pcFilePath.data());
}

void
ApiHelper::BOARD_GetUpgInfo(binary_rsp& _return, const int32_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::BOARD_GetUpgInfo((uint8_t *)&_return.data[0], ulLen);
}

int32_t
ApiHelper::BOARD_SetUpgInfo(const std::string& pucBuf, const int32_t ulLen)
{
    return ::BOARD_SetUpgInfo((uint8_t *)&pucBuf[0], ulLen);
}

void
ApiHelper::BOARD_GetBdlHead(binary_rsp& _return, const int32_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::BOARD_GetBdlHead((uint8_t *)&_return.data[0], ulLen);
}

int32_t
ApiHelper::BOARD_SetBdlHead(const std::string& pucBuf, const int32_t ulLen)
{
    return ::BOARD_SetBdlHead((uint8_t *)&pucBuf[0], ulLen);
}

void
ApiHelper::BOARD_GetStatusData(CBoardStatusData_rsp& _return)
{
    CBoardStatusData data = {0};
    _return.response = ::BOARD_GetStatusData(&data);
    CHECK_RSP(_return.response);
    Convert::ToCBoardStatusData_t(_return.data, data);
}

void
ApiHelper::BOARD_GetSccMfg(CMfg_rsp& _return)
{
    CMfg data = {0};
    _return.response = ::BOARD_GetSccMfg(&data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

int32_t
ApiHelper::BOARD_SetSccMfg(const std::string& pcFilePath)
{
    return ::BOARD_SetSccMfg(pcFilePath.data());
}

int32_t
ApiHelper::BOARD_SetResetType(const int8_t ucResetType)
{
    return ::BOARD_SetResetType(ucResetType);
}

void
ApiHelper::BOARD_GetResetType(i8_rsp& _return, const int32_t iIndex)
{
    _return.response = ::BOARD_GetResetType(iIndex, (uint8_t *)&_return.data);
}

int32_t
ApiHelper::BOARD_CfgWatchDogTime(const bool bEnable, const int8_t ucTimeout)
{
    return ::BOARD_CfgWatchDogTime(bEnable, ucTimeout);
}

void
ApiHelper::BOARD_GetApsdStatus(bool_list_rsp& _return, const int32_t iIndex)
{
    bool data[3] = {false};
    _return.response = ::BOARD_GetApsdStatus(iIndex, data, data + 1, data + 2);
    CHECK_RSP(_return.response);
    _return.data.push_back(data[0]);
    _return.data.push_back(data[1]);
    _return.data.push_back(data[2]);
}

int32_t
ApiHelper::BOARD_SetLedState(const int32_t uiDevIdx, const int32_t uiState)
{
    return ::BOARD_SetLedState(uiDevIdx, uiState);
}

int32_t
ApiHelper::BOARD_ResetLogic(const int32_t uiDevIdx, const int8_t ucResetType)
{
    return ::BOARD_ResetLogic(uiDevIdx, ucResetType);
}

int32_t
ApiHelper::BOARD_UpgradeLogic(const int32_t uiDevIdx, const std::string& c_pcFilePath)
{
    return ::BOARD_UpgradeLogic(uiDevIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::BOARD_GetUpgadeStatus()
{
    return ::BOARD_GetUpgadeStatus();
}

void
ApiHelper::FAN_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::FAN_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

int32_t
ApiHelper::FAN_SetMfg(const int32_t uiDevIdx, const std::string& pcFilePath)
{
    return ::FAN_SetMfg(uiDevIdx, pcFilePath.data());
}

int32_t
ApiHelper::FAN_SetSpeed(const int32_t uiDevIdx, const int32_t uiDuty)
{
    return ::FAN_SetSpeed(uiDevIdx, uiDuty);
}

int32_t
ApiHelper::FAN_SetControllerEEP(const int32_t uiDevIdx)
{
    return ::FAN_SetControllerEEP(uiDevIdx);
}

int32_t
ApiHelper::FAN_SetLed(const int32_t uiDevIdx, const int32_t uiValue)
{
    return ::FAN_SetLed(uiDevIdx, uiValue);
}

void
ApiHelper::POWER_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::POWER_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::BOARD_GetProductName(string_rsp& _return, const int32_t nSize)
{
    _return.data.resize(nSize, 0x00);
    _return.response = ::BOARD_GetProductName(&_return.data[0], nSize) == NULL ? OPLK_ERR : OPLK_OK;
}

void
ApiHelper::BOARD_GetConfigType(string_rsp& _return, const int32_t nSize)
{
    _return.data.resize(nSize, 0x00);
    _return.response = ::BOARD_GetConfigType(&_return.data[0], nSize) == NULL ? OPLK_ERR : OPLK_OK;
}

int32_t
ApiHelper::BOARD_GetProductType()
{
    return ::BOARD_GetProductType();
}

int32_t
ApiHelper::BOARD_SetLogLevel(const int32_t uiLogLevel)
{
    return ::BOARD_SetLogLevel(uiLogLevel);
}

void
ApiHelper::BOARD_ConvertDevType(i32_rsp& _return, const std::string& pcName)
{
    uint32_t data = 0;
    _return.response = ::BOARD_ConvertDevType(pcName.data(), &data);
    _return.data = (int32_t)data;
}

void
ApiHelper::Cv_GetMuxStatusData(CCvMuxStatusData_rsp& _return, const int32_t enCvLine)
{
    CCvMuxStatusData data = {0};
    _return.response = ::Cv_GetMuxStatusData((EnCvLine)enCvLine, &data);
    CHECK_RSP(_return.response);
    Convert::ToCCvMuxStatusData_t(_return.data, data);
}

void
ApiHelper::Cv_GetClientStatusData(CCvClientStatusData_rsp& _return, const int32_t enCvLine)
{
    CCvClientStatusData data = {0};
    _return.response = ::Cv_GetClientStatusData((EnCvLine)enCvLine, &data);
    CHECK_RSP(_return.response);
    Convert::ToCCvClientStatusData_t(_return.data, data);
}

void
ApiHelper::Cv_GetRef(CCvRef_rsp& _return)
{
    CCvRef data = {0};
    _return.response = ::Cv_GetRef(&data);
    CHECK_RSP(_return.response);
    Convert::ToCCvRef_t(_return.data, data);
}

void
ApiHelper::DBG_ReadLogicReg(binary_rsp& _return, const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::DBG_ReadLogicReg(uiIdx, ulAddr, ulLen, (uint8_t *)&_return.data[0]);
}

int32_t
ApiHelper::DBG_WriteLogicReg(const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen, const std::string& pucVal)
{
    return ::DBG_WriteLogicReg(uiIdx, ulAddr, ulLen, (uint8_t *)&pucVal[0]);
}

void
ApiHelper::DBG_ReadLogicRegSlc(binary_rsp& _return, const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::DBG_ReadLogicRegSlc(uiIdx, ulAddr, ulLen, (uint8_t *)&_return.data[0]);
}

int32_t
ApiHelper::DBG_WriteLogicRegSlc(const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen, const std::string& pucVal)
{
    return ::DBG_WriteLogicRegSlc(uiIdx, ulAddr, ulLen, (uint8_t *)&pucVal[0]);
}

int32_t
ApiHelper::DBG_LoopEnable(const bool bEnable)
{
    return ::DBG_LoopEnable(bEnable);
}

int32_t
ApiHelper::DBG_LoopInterval(const int32_t uiInterval)
{
    return ::DBG_LoopInterval(uiInterval);
}

int32_t
ApiHelper::DBG_IdleEnable(const bool bEnable)
{
    return ::DBG_IdleEnable(bEnable);
}

int32_t
ApiHelper::DBG_ApsdEnable(const int32_t iIndex, const bool bEnable)
{
    return ::DBG_ApsdEnable(iIndex, bEnable);
}

void
ApiHelper::DBG_GetAprStatus(i8_rsp& _return, const int32_t uiIndex)
{
    _return.response = ::DBG_GetAprStatus(uiIndex, (uint8_t *)&_return.data);
}

void
ApiHelper::DBG_SpiSendCommand(binary_rsp& _return, const int32_t ulChip, const std::string& pucBufW, const int32_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::DBG_SpiSendCommand(ulChip, (uint8_t *)&pucBufW[0], (uint8_t *)&_return.data[0], ulLen);
}

void
ApiHelper::DBG_SpiFlashRead(binary_rsp& _return, const int64_t ulChip, const int64_t ulAddr, const int64_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::DBG_SpiFlashRead(ulChip, ulAddr, ulLen, (uint8_t *)&_return.data[0]);
}

int32_t
ApiHelper::DBG_SpiFlashWrite(const int64_t ulChip, const int64_t ulAddr, const int64_t ulLen, const std::string& pucVal)
{
    return ::DBG_SpiFlashWrite(ulChip, ulAddr, ulLen, (uint8_t *)&pucVal[0]);
}

void
ApiHelper::DBG_MdioRead(i16_rsp& _return, const int32_t uiIdx, const int32_t ulPhyAddr, const int32_t ulRegAddr)
{
    _return.response = ::DBG_MdioRead(uiIdx, ulPhyAddr, ulRegAddr, (uint16_t *)&_return.data);
}

int32_t
ApiHelper::DBG_MdioWrite(const int32_t uiIdx, const int32_t ulPhyAddr, const int32_t ulRegAddr, const int16_t usData)
{
    return ::DBG_MdioWrite(uiIdx, ulPhyAddr, ulRegAddr, (uint16_t)usData);
}

void
ApiHelper::DBG_NetSwitchRead(i16_rsp& _return, const int32_t ulPhyAddr, const int32_t ulRegAddr)
{
    _return.response = ::DBG_NetSwitchRead(ulPhyAddr, ulRegAddr, (uint16_t *)&_return.data);
}

int32_t
ApiHelper::DBG_NetSwitchWrite(const int32_t ulPhyAddr, const int32_t ulRegAddr, const int16_t usData)
{
    return ::DBG_NetSwitchWrite(ulPhyAddr, ulRegAddr, (uint16_t)usData);
}

void
ApiHelper::DBG_SwitchPhyRead(i16_rsp& _return, const int32_t ulPhyAddr, const int32_t ulRegAddr)
{
    _return.response = ::DBG_SwitchPhyRead(ulPhyAddr, ulRegAddr, (uint16_t *)&_return.data);
}

int32_t
ApiHelper::DBG_SwitchPhyWrite(const int32_t ulPhyAddr, const int32_t ulRegAddr, const int16_t usData)
{
    return ::DBG_SwitchPhyWrite(ulPhyAddr, ulRegAddr, (uint16_t)usData);
}

void
ApiHelper::DBG_ReadEeprom(binary_rsp& _return, const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::DBG_ReadEeprom(uiIdx, ulAddr, ulLen, (uint8_t *)&_return.data[0]);
}

int32_t
ApiHelper::DBG_WriteEeprom(const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen, const std::string& pucVal)
{
    return ::DBG_WriteEeprom(uiIdx, ulAddr, ulLen, (uint8_t *)&pucVal[0]);
}


void
ApiHelper::EDFA_GetMfg(CMfg_rsp& _return, const int32_t uiDevType)
{
    CMfg data = {0};
    _return.response = ::EDFA_GetMfg(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::EDFA_GetStatusData(COaStatusData_rsp& _return, const int32_t uiDevType)
{
    COaStatusData data = {0};
    _return.response = ::EDFA_GetStatusData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOaStatusData_t(_return.data, data);
}

void
ApiHelper::EDFA_GetCfgData(COaCfgData_rsp& _return, const int32_t uiDevType)
{
    COaCfgData data = {0};
    _return.response = ::EDFA_GetCfgData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOaCfgData_t(_return.data, data);
}

int32_t
ApiHelper::EDFA_GetDebugInfo(const int32_t uiDevType, const std::string& pcFilePath)
{
    return ::EDFA_GetDebugInfo(uiDevType, pcFilePath.data());
}

int32_t
ApiHelper::EDFA_GetMcuDebugInfo(const int32_t uiDevType, const std::string& pcFilePath)
{
    return ::EDFA_GetMcuDebugInfo(uiDevType, pcFilePath.data());
}

int32_t
ApiHelper::EDFA_SetGainRange(const int32_t uiDevType, const int16_t sGainRange)
{
    return ::EDFA_SetGainRange(uiDevType, sGainRange);
}

int32_t
ApiHelper::EDFA_SetGain(const int32_t uiDevType, const int16_t sGain)
{
    return ::EDFA_SetGain(uiDevType, sGain);
}

int32_t
ApiHelper::EDFA_SetTilt(const int32_t uiDevType, const int16_t sTilt)
{
    return ::EDFA_SetTilt(uiDevType, sTilt);
}

int32_t
ApiHelper::EDFA_SetMode(const int32_t uiDevType, const int8_t ucMode, const int16_t sVal)
{
    return ::EDFA_SetMode(uiDevType, ucMode, sVal);
}

int32_t
ApiHelper::EDFA_SetPumpEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetPumpEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetAprEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetAprEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetAutolosEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetAutolosEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetRxLosThr(const int32_t uiDevType, const int16_t sThr, const int16_t sHys)
{
    return ::EDFA_SetRxLosThr(uiDevType, sThr, sHys);
}

int32_t
ApiHelper::EDFA_SetAttn(const int32_t uiDevType, const int16_t sAttn)
{
    return ::EDFA_SetAttn(uiDevType, sAttn);
}

void
ApiHelper::EDFA_GetAttn(i16_rsp& _return, const int32_t uiDevType)
{
    _return.response = ::EDFA_GetAttn(uiDevType, &_return.data);
}

int32_t
ApiHelper::EDFA_Reset(const int32_t uiDevType, const int8_t ucResetType)
{
    return ::EDFA_Reset(uiDevType, ucResetType);
}

int32_t
ApiHelper::EDFA_Upgrade(const int32_t uiDevType, const std::string& c_pcFilePath)
{
    return ::EDFA_Upgrade(uiDevType, c_pcFilePath.data());
}

int32_t
ApiHelper::EDFA_Swap(const int32_t uiDevType)
{
    return ::EDFA_Swap(uiDevType);
}

int32_t
ApiHelper::EDFA_Commit(const int32_t uiDevType)
{
    return ::EDFA_Commit(uiDevType);
}

int32_t
ApiHelper::EDFA_GetUpgadeStatus(const int32_t uiDevType)
{
    return ::EDFA_GetUpgadeStatus(uiDevType);
}

void
ApiHelper::EDFA_DbgRead(binary_rsp& _return, const int32_t uiDevType, const int32_t uiLen)
{
    _return.data.resize(uiLen, 0x00);
    _return.response = ::EDFA_DbgRead(uiDevType, (uint8_t *)&_return.data[0], uiLen);
}

int32_t
ApiHelper::EDFA_DbgWrite(const int32_t uiDevType, const std::string& pucBuf, const int32_t uiLen)
{
    return ::EDFA_DbgWrite(uiDevType, (uint8_t *)&pucBuf[0], uiLen);
}
    
int32_t
ApiHelper::EDFA_SetDfbEnable(const int32_t uiDevType, const bool bEnable, const int32_t iPower)
{
    return ::EDFA_SetDfbEnable(uiDevType, bEnable, iPower);
}

int32_t
ApiHelper::EDFA_SetOscEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetOscEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetOtdrSwitchPos(const int32_t uiDevType, const int32_t uiPos)
{
    return ::EDFA_SetOtdrSwitchPos(uiDevType, uiPos);
}

int32_t
ApiHelper::EDFA_SetOscAddThrHys(const int32_t uiDevType, const int16_t sThr, const int16_t sHys)
{
    return ::EDFA_SetOscAddThrHys(uiDevType, sThr, sHys);
}

int32_t
ApiHelper::EDFA_SetOscDropThrHys(const int32_t uiDevType, const int16_t sThr, const int16_t sHys)
{
    return ::EDFA_SetOscDropThrHys(uiDevType, sThr, sHys);
}

int32_t
ApiHelper::EDFA_SetOscRxThrHys(const int32_t uiDevType, const int16_t sThr, const int16_t sHys)
{
    return ::EDFA_SetOscRxThrHys(uiDevType, sThr, sHys);
}

int32_t
ApiHelper::EDFA_SetApsdEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetApsdEnable(uiDevType, bEnable);
}

void
ApiHelper::EDFA_GetApsdStatus(bool_list_rsp& _return, const int32_t uiDevType)
{
    bool data[3] = {false};
    _return.response = ::EDFA_GetApsdStatus(uiDevType, data, data + 1, data + 2);
    CHECK_RSP(_return.response);
    _return.data.push_back(data[0]);
    _return.data.push_back(data[1]);
    _return.data.push_back(data[2]);
}

void
ApiHelper::EDFA_GetOcmAttn(i16_rsp& _return, const int32_t uiDevType)
{
    _return.response = ::EDFA_GetOcmAttn(uiDevType, &_return.data);
}

int32_t
ApiHelper::EDFA_SetUpgState(const int32_t uiDevType, const int16_t sState)
{
    return ::EDFA_SetUpgState(uiDevType, sState);
}

int32_t
ApiHelper::EDFA_SetLedState(const int32_t uiDevType, const int16_t sState)
{
    return ::EDFA_SetLedState(uiDevType, sState);
}

int32_t
ApiHelper::EDFA_SetLedAlm(const int32_t uiDevType, const int16_t sState)
{
    return ::EDFA_SetLedAlm(uiDevType, sState);
}

void
ApiHelper::EDFA_GetCali(COaCaliData_rsp& _return, const int32_t uiDevType)
{
    COaCaliData data = {0};
    _return.response = ::EDFA_GetCali(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOaCaliData_t(_return.data, data);
}

int32_t
ApiHelper::EDFA_SetOtdrCali(const int32_t uiDevType, const std::string& pcFilePath)
{
    return ::EDFA_SetOtdrCali(uiDevType, (char *)pcFilePath.data());
}

int32_t
ApiHelper::EDFA_SetOcmCali(const int32_t uiDevType, const std::string& pcFilePath)
{
    return ::EDFA_SetOcmCali(uiDevType, (char *)pcFilePath.data());
}

int32_t
ApiHelper::EDFA_SetManualVoaEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetManualVoaEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetPaddingVoaConfigPower(const int32_t uiDevType, const int16_t sOutPower)
{
    return ::EDFA_SetPaddingVoaConfigPower(uiDevType, sOutPower);
}

int32_t
ApiHelper::EDFA_SetManualGainEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::EDFA_SetManualGainEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::EDFA_SetThr(const int32_t uiDevType, const int32_t uiPortIdx, const int32_t uiType, const int16_t sThr, const int16_t sHys)
{
    return ::EDFA_SetThr(uiDevType, uiPortIdx, uiType, sThr, sHys);
}

int32_t
ApiHelper::EDFA_SetPumpCurrent(const int32_t uiDevType, const int32_t uiPumpIdx, const int16_t sCurrent)
{
    return ::EDFA_SetPumpCurrent(uiDevType, uiPumpIdx, sCurrent);
}

int32_t
ApiHelper::EDFA_SetAlmMask(const int32_t uiDevType, const int32_t iMaskIdx, const int32_t iMaskVal)
{
    return ::EDFA_SetAlmMask(uiDevType, iMaskIdx, iMaskVal);
}

void
ApiHelper::EDFA_GetEventLog(COaEventLogAllData_rsp& _return, const int32_t uiDevType)
{
    COaEventLogAllData data = {0};
    _return.response = ::EDFA_GetEventLog(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOaEventLogAllData_t(_return.data, data);
}

int32_t
ApiHelper::EDFA_SetShutterState(const int32_t uiDevType, const bool block)
{
    return ::EDFA_SetShutterState(uiDevType, block);
}

void
ApiHelper::EDFA_GetShutterState(bool_rsp& _return, const int32_t uiDevType)
{
    _return.response = ::EDFA_GetShutterState(uiDevType, &_return.data);
}

void
ApiHelper::EXTEND_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::EXTEND_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::EXTEND_GetStatusData(CExtendStatusData_rsp& _return, const int32_t uiDevIdx)
{
    CExtendStatusData data = {0};
    _return.response = ::EXTEND_GetStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCExtendStatusData_t(_return.data, data);
}

int32_t
ApiHelper::EXTEND_Reset(const int32_t uiDevIdx, const int8_t ucResetType)
{
    return ::EXTEND_Reset(uiDevIdx, ucResetType);
}

int32_t
ApiHelper::EXTEND_Upgrade(const int32_t uiDevIdx, const std::string& c_pcFilePath)
{
    return ::EXTEND_Upgrade(uiDevIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::EXTEND_GetUpgadeStatus(const int32_t uiDevIdx)
{
    return ::EXTEND_GetUpgadeStatus(uiDevIdx);
}

void
ApiHelper::EXTEND_DbgRead(binary_rsp& _return, const int32_t uiDevIdx, const int32_t uiLen)
{
    _return.data.resize(uiLen, 0x00);
    _return.response = ::EXTEND_DbgRead(uiDevIdx, (uint8_t *)&_return.data[0], uiLen);
}

int32_t
ApiHelper::EXTEND_DbgWrite(const int32_t uiDevIdx, const std::string& pucBuf, const int32_t uiLen)
{
    return ::EXTEND_DbgWrite(uiDevIdx, (uint8_t *)&pucBuf[0], uiLen);
}

int32_t
ApiHelper::EXTEND_SetSfp(const int32_t uiDevIdx, const int32_t ulVal)
{
    return ::EXTEND_SetSfp(uiDevIdx, ulVal);
}

void
ApiHelper::MIRROR_GetStatusData(CMirrorData_rsp& _return, const int32_t uiDevIdx)
{
    CMirrorData data = {0};
    _return.response = ::MIRROR_GetStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMirrorData_t(_return.data, data);
}

int32_t
ApiHelper::SWITCH_Pos(const int32_t uiDevIdx, const int32_t uiPort)
{
    return ::SWITCH_Pos(uiDevIdx, uiPort);
}

void
ApiHelper::MUX_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::MUX_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::MUX_GetStatusData(CMuxStatusData_rsp& _return, const int32_t uiDevIdx)
{
    CMuxStatusData data = {0};
    _return.response = ::MUX_GetStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMuxStatusData_t(_return.data, data);
}

void
ApiHelper::MUX_GetCali(CMuxCaliData_rsp& _return, const int32_t uiDevIdx)
{
    CMuxCaliData data = {0};
    _return.response = ::MUX_GetCali(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMuxCaliData_t(_return.data, data);
}

void
ApiHelper::OCM_GetMfg(CMfg_rsp& _return, const int32_t uiDevType)
{
    CMfg data = {0};
    _return.response = ::OCM_GetMfg(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::OCM_GetStatusData(COcmStatusData_rsp& _return, const int32_t uiDevType)
{
    COcmStatusData data = {0};
    _return.response = ::OCM_GetStatusData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOcmStatusData_t(_return.data, data);
}

void
ApiHelper::OCM_GetChPower(COcmChPower_rsp& _return, const int32_t uiDevType, const int32_t uiPortId)
{
    COcmChPower data = {0};
    _return.response = ::OCM_GetChPower(uiDevType, uiPortId, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOcmChPower_t(_return.data, data);
}

void
ApiHelper::OCM_GetOsaData(COcmOsa_rsp& _return, const int32_t uiDevType, const int32_t uiPortId)
{
    COcmOsa data = {0};
    _return.response = ::OCM_GetOsaData(uiDevType, uiPortId, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOcmOsa_t(_return.data, data);
}

void
ApiHelper::OCM_GetRealTimeOsaData(COcmOsa_rsp& _return, const int32_t uiDevType, const int32_t uiPortId)
{
    COcmOsa data = {0};
    _return.response = ::OCM_GetRealTimeOsaData(uiDevType, uiPortId, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOcmOsa_t(_return.data, data);
}

int32_t
ApiHelper::OCM_SetWaveplan(const int32_t uiDevType, const int32_t uiPortId, const int32_t uiChCnt, const std::vector<CWavePlanSlice_t> & pstWavePlan)
{
    std::vector<CWavePlanSlice> data;
    for (auto e : pstWavePlan) {
        CWavePlanSlice d = {0};
        Convert::ToCWavePlanSlice(d, e);
        data.push_back(d);
    }
    return ::OCM_SetWaveplan(uiDevType, uiPortId, uiChCnt, data.data());
}

int32_t
ApiHelper::OCM_SetOcmWaveplan(const int32_t uiDevType, const int32_t uiPortId, const int32_t uiChCnt, const std::vector<STChannelGrid_t> & pstWavePlan)
{
    std::vector<STChannelGrid> data;
    for (auto e : pstWavePlan) {
        STChannelGrid d = {0};
        Convert::ToSTChannelGrid(d, e);
        data.push_back(d);
    }
    return ::OCM_SetOcmWaveplan(uiDevType, uiPortId, uiChCnt, data.data());
}

int32_t
ApiHelper::OCM_Reset(const int32_t uiDevType, const int8_t ucResetType)
{
    return ::OCM_Reset(uiDevType, ucResetType);
}

int32_t
ApiHelper::OCM_Upgrade(const int32_t uiDevType, const std::string& c_pcFilePath)
{
    return ::OCM_Upgrade(uiDevType, c_pcFilePath.data());
}

int32_t
ApiHelper::OCM_Commit(const int32_t uiDevType)
{
    return ::OCM_Commit(uiDevType);
}

int32_t
ApiHelper::OCM_GetUpgradeStatus(const int32_t uiDevType)
{
    return ::OCM_GetUpgradeStatus(uiDevType);
}

int32_t
ApiHelper::OCM_SetVoa(const int32_t uiDevType, const int16_t sAttn)
{
    return ::OCM_SetVoa(uiDevType, sAttn);
}

void
ApiHelper::OCM_GetVoa(i16_rsp& _return, const int32_t uiDevType)
{
    _return.response = ::OCM_GetVoa(uiDevType, &_return.data);
}

void
ApiHelper::OCM_GetVoaPd(i16_list_rsp& _return, const int32_t uiDevType)
{
    int16_t data[2] = {0};
    _return.response = ::OCM_GetVoaPd(uiDevType, data, data + 1);
    CHECK_RSP(_return.response);
    _return.data.push_back(data[0]);
    _return.data.push_back(data[1]);
}

void
ApiHelper::OCS_GetMfg(CMfg_rsp& _return, const int32_t uiDevType)
{
    CMfg data = {0};
    _return.response = ::OCS_GetMfg(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::OCS_GetStatusData(COcsStatusData_rsp& _return, const int32_t uiDevType)
{
    COcsStatusData data = {0};
    _return.response = ::OCS_GetStatusData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOcsStatusData_t(_return.data, data);
}

int32_t
ApiHelper::OCS_SetConnection(const int32_t uiDevType, const COcsConnection_t& pstConnection)
{
    COcsConnection data = {0};
    Convert::ToCOcsConnection(data, pstConnection);
    return ::OCS_SetConnection(uiDevType, &data);
}

int32_t
ApiHelper::OCS_SetConnections(const int32_t uiDevType, const COcsConnections_t& pstConnections)
{
    COcsConnections data = {0};
    Convert::ToCOcsConnections(data, pstConnections);
    return ::OCS_SetConnections(uiDevType, &data);
}

int32_t
ApiHelper::OCS_SetLedState(const int32_t uiDevType, const int32_t index, const int32_t uiState)
{
    //TODO: no implementation
    //return ::OCS_SetLedState(uiDevType, index, uiState);
    return OPLK_OK;
}

int32_t
ApiHelper::OCS_SetLedMode(const int32_t uiDevType, const int32_t uiMode)
{
    return ::OCS_SetLedMode(uiDevType, uiMode);
}

int32_t
ApiHelper::OCS_Reset(const int32_t uiDevType, const int8_t ucResetType)
{
    return ::OCS_Reset(uiDevType, ucResetType);
}

int32_t
ApiHelper::OCS_Upgrade(const int32_t uiDevType, const std::string& pcPath)
{
    return ::OCS_Upgrade(uiDevType, pcPath.data());
}

int32_t
ApiHelper::OCS_GetUpgradeStatus(const int32_t uiDevType)
{
    return ::OCS_GetUpgradeStatus(uiDevType);
}

void
ApiHelper::OPS_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::OPS_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::OPS_GetCommStatusData(COpsCommStatusData_rsp& _return, const int32_t uiDevIdx)
{
    COpsCommStatusData data = {0};
    _return.response = ::OPS_GetCommStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOpsCommStatusData_t(_return.data, data);
}

void
ApiHelper::OPS_GetCfgData(COpsCfgData_rsp& _return, const int32_t uiDevIdx, const int32_t uiPortId)
{
    COpsCfgData data = {0};
    _return.response = ::OPS_GetCfgData(uiDevIdx, &data, uiPortId);
    CHECK_RSP(_return.response);
    Convert::ToCOpsCfgData_t(_return.data, data);
}

void
ApiHelper::OPS_GetStatusData(COpsStatusData_rsp& _return, const int32_t uiDevIdx, const int32_t uiPortId)
{
    COpsStatusData data = {0};
    _return.response = ::OPS_GetStatusData(uiDevIdx, &data, uiPortId);
    CHECK_RSP(_return.response);
    Convert::ToCOpsStatusData_t(_return.data, data);
}

void
ApiHelper::OPS_GetHistoryData(COpsHistoryData_rsp& _return, const int32_t uiDevIdx, const int32_t uiPortId)
{
    COpsHistoryData data = {0};
    _return.response = ::OPS_GetHistoryData(uiDevIdx, &data, uiPortId);
    CHECK_RSP(_return.response);
    Convert::ToCOpsHistoryData_t(_return.data, data);
}

void
ApiHelper::OPS_GetLedStatus(COpsLed_rsp& _return, const int32_t uiDevIdx)
{
    COpsLed data = {0};
    _return.response = ::OPS_GetLedStatus(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOpsLed_t(_return.data, data);
}

int32_t
ApiHelper::OPS_ClearAlarmDuration(const int32_t uiDevIdx)
{
    return ::OPS_ClearAlarmDuration(uiDevIdx);
}

int32_t
ApiHelper::OPS_SetThrPwrDiff(const int32_t uiDevIdx, const int16_t sThr, const int16_t sHys, const int32_t uiPortId)
{
    return ::OPS_SetThrPwrDiff(uiDevIdx, sThr, sHys, uiPortId);
}

int32_t
ApiHelper::OPS_SetThrLine(const int32_t uiDevIdx, const int32_t uiPortIdx, const int16_t sThr, const int16_t sHys, const int32_t uiPortId)
{
    return ::OPS_SetThrLine(uiDevIdx, uiPortIdx, sThr, sHys, uiPortId);
}

int32_t
ApiHelper::OPS_SetPortPowerThr(const int32_t uiDevIdx, const int32_t uiPortIdx, const int32_t uiType, const int16_t sThr, const int32_t uiPortId)
{
    return ::OPS_SetPortPowerThr(uiDevIdx, uiPortIdx, uiType, sThr, uiPortId);
}

int32_t
ApiHelper::OPS_SetPortPowerHys(const int32_t uiDevIdx, const int32_t uiPortIdx, const int32_t uiType, const int16_t sHys, const int32_t uiPortId)
{
    return ::OPS_SetPortPowerHys(uiDevIdx, uiPortIdx, uiType, sHys, uiPortId);
}

int32_t
ApiHelper::OPS_SetWtr(const int32_t uiDevIdx, const int32_t uiWtr, const int32_t uiPortId)
{
    return ::OPS_SetWtr(uiDevIdx, uiWtr, uiPortId);
}

int32_t
ApiHelper::OPS_SetHoldOffTime(const int32_t uiDevIdx, const int32_t uiHoldOffTime, const int32_t uiPortId)
{
    return ::OPS_SetHoldOffTime(uiDevIdx, uiHoldOffTime, uiPortId);
}

int32_t
ApiHelper::OPS_SetRevertive(const int32_t uiDevIdx, const bool bRevertive, const int32_t uiPortId)
{
    return ::OPS_SetRevertive(uiDevIdx, bRevertive, uiPortId);
}

int32_t
ApiHelper::OPS_SetMode(const int32_t uiDevIdx, const int32_t uiMode, const int32_t uiPortId)
{
    return ::OPS_SetMode(uiDevIdx, uiMode, uiPortId);
}

int32_t
ApiHelper::OPS_SetRelativeThr(const int32_t uiDevIdx, const int16_t sThr, const int32_t uiPortId)
{
    return ::OPS_SetRelativeThr(uiDevIdx, sThr, uiPortId);
}

int32_t
ApiHelper::OPS_SetRelativeOffset(const int32_t uiDevIdx, const int16_t sOffset, const int32_t uiPortId)
{
    return ::OPS_SetRelativeOffset(uiDevIdx, sOffset, uiPortId);
}

int32_t
ApiHelper::OPS_SetSwitchThr(const int32_t uiDevIdx, const int32_t uiPos, const int32_t iThr, const int32_t uiPortId)
{
    return ::OPS_SetSwitchThr(uiDevIdx, uiPos, iThr, uiPortId);
}

int32_t
ApiHelper::OPS_SetSwitchHys(const int32_t uiDevIdx, const int32_t uiPos, const int32_t iHys, const int32_t uiPortId)
{
    return ::OPS_SetSwitchHys(uiDevIdx, uiPos, iHys, uiPortId);
}

int32_t
ApiHelper::OPS_Reset(const int32_t uiDevIdx, const int8_t ucResetType)
{
    return ::OPS_Reset(uiDevIdx, ucResetType);
}

int32_t
ApiHelper::OPS_Upgrade(const int32_t uiDevIdx, const std::string& c_pcFilePath)
{
    return ::OPS_Upgrade(uiDevIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::OPS_GetUpgadeStatus(const int32_t uiDevIdx)
{
    return ::OPS_GetUpgadeStatus(uiDevIdx);
}

int32_t
ApiHelper::OPS_SetLedDebugMode(const int32_t uiDevIdx, const int32_t uiMode)
{
    return ::OPS_SetLedDebugMode(uiDevIdx, uiMode);
}

int32_t
ApiHelper::OPS_SetLedStatus(const int32_t uiDevIdx, const int32_t uiLedIdx, const int32_t uiStatus)
{
    return ::OPS_SetLedStatus(uiDevIdx, uiLedIdx, uiStatus);
}

int32_t
ApiHelper::OPS_SetConnectionPdThr(const int32_t uiDevIdx, const int32_t uiPdIdx, const int32_t uiType, const int16_t sThr, const int32_t uiPortId)
{
    return ::OPS_SetConnectionPdThr(uiDevIdx, uiPdIdx, uiType, sThr, uiPortId);
}

int32_t
ApiHelper::OPS_SetConnectionPdHys(const int32_t uiDevIdx, const int32_t uiPdIdx, const int32_t uiType, const int16_t sHys, const int32_t uiPortId)
{
    return ::OPS_SetConnectionPdHys(uiDevIdx, uiPdIdx, uiType, sHys, uiPortId);
}

int32_t
ApiHelper::OPS_SetAlmMask(const int32_t uiDevType, const int32_t iMaskIdx, const int32_t iMaskVal, const int32_t uiPortId)
{
    return ::OPS_SetAlmMask(uiDevType, iMaskIdx, iMaskVal, uiPortId);
}

void
ApiHelper::OPS_GetEventLog(COpsEventLogAllData_rsp& _return, const int32_t uiDevType, const int32_t uiPortId)
{
    COpsEventLogAllData data = {0};
    _return.response = ::OPS_GetEventLog(uiDevType, &data, uiPortId);
    CHECK_RSP(_return.response);
    Convert::ToCOpsEventLogAllData_t(_return.data, data);
}

int32_t
ApiHelper::OPS_SetRemoteStatus(const int32_t uiDevIdx, const COpsReqStatus_t& pstStatus, const int32_t uiPortId)
{
    COpsReqStatus data = {0};
    Convert::ToCOpsReqStatus(data, pstStatus);
    return ::OPS_SetRemoteStatus(uiDevIdx, &data, uiPortId);
}

void
ApiHelper::OPS_GetRequestStatus(COpsBidirectionStatus_rsp& _return, const int32_t uiDevIdx, const int32_t uiPortId)
{
    COpsBidirectionStatus data = {0};
    _return.response = ::OPS_GetRequestStatus(uiDevIdx, &data, uiPortId);
    CHECK_RSP(_return.response);
    Convert::ToCOpsBidirectionStatus_t(_return.data, data);
}

int32_t
ApiHelper::OPS_SetSwitchingType(const int32_t uiDevIdx, const int8_t ucType, const int32_t uiPortId)
{
    return ::OPS_SetSwitchingType(uiDevIdx, ucType, uiPortId);
}

void
ApiHelper::OPS_GetOpsDevIdByKey(i32_list_rsp& _return, const std::string& pcName)
{
    uint32_t data[2] = {0};
    _return.response = ::OPS_GetOpsDevIdByKey((char *)pcName.data(), data, data + 1);
    CHECK_RSP(_return.response);
    _return.data.push_back(data[0]);
    _return.data.push_back(data[1]);
}

void
ApiHelper::OSC_GetStatusData(COscStatusData_rsp& _return, const int32_t uiDevType)
{
    COscStatusData data = {0};
    _return.response = ::OSC_GetStatusData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOscStatusData_t(_return.data, data);
}

void
ApiHelper::OSC_GetCfgData(COscCfgData_rsp& _return, const int32_t uiDevType)
{
    COscCfgData data = {0};
    _return.response = ::OSC_GetCfgData(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOscCfgData_t(_return.data, data);
}

int32_t
ApiHelper::OSC_SetEnable(const int32_t uiDevType, const bool bEnable)
{
    return ::OSC_SetEnable(uiDevType, bEnable);
}

int32_t
ApiHelper::OSC_SetVoa(const int32_t uiDevType, const int32_t uiTxRx, const int16_t sAttn)
{
    return ::OSC_SetVoa(uiDevType, uiTxRx, sAttn);
}

void
ApiHelper::OSC_GetVoa(i16_rsp& _return, const int32_t uiDevType, const int32_t uiTxRx)
{
    _return.response = ::OSC_GetVoa(uiDevType, uiTxRx, &_return.data);
}

int32_t
ApiHelper::OSC_SetSwitchPos(const int32_t uiDevType, const COscSwitchPosSet_t& rstSwitchPos)
{
    COscSwitchPosSet data = {0};
    Convert::ToCOscSwitchPosSet(data, rstSwitchPos);
    return ::OSC_SetSwitchPos(uiDevType, data);
}

void
ApiHelper::OSC_GetSwitchPos(COscSwitchPos_rsp& _return, const int32_t uiDevType)
{
    COscSwitchPos data = {0};
    _return.response = ::OSC_GetSwitchPos(uiDevType, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOscSwitchPos_t(_return.data, data);
}

void
ApiHelper::OTDR_GetMfg(CMfg_rsp& _return, const int32_t ulDevIdx)
{
    CMfg data = {0};
    _return.response = ::OTDR_GetMfg(ulDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void 
ApiHelper::OTDR_GetStatusData(COtdrStatusData_rsp& _return, const int32_t ulDevIdx)
{
    COtdrStatusData data = {0};
    _return.response = ::OTDR_GetStatusData(ulDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOtdrStatusData_t(_return.data, data);
}

void
ApiHelper::OTDR_GetCfgData(COtdrCfgData_rsp& _return, const int32_t ulDevIdx)
{
    COtdrCfgData data = {0};
    _return.response = ::OTDR_GetCfgData(ulDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOtdrCfgData_t(_return.data, data);
}

int32_t
ApiHelper::OTDR_StartScan(const int32_t ulDevIdx)
{
    return ::OTDR_StartScan(ulDevIdx);
}

int32_t
ApiHelper::OTDR_SetPara(const int32_t ulDevIdx, const int32_t ulDistRang, const int32_t ulPulseWidth, const double dSamplingResolution)
{
    return ::OTDR_SetPara(ulDevIdx, ulDistRang, ulPulseWidth, dSamplingResolution);
}

int32_t
ApiHelper::OTDR_SetMeasuringTime(const int32_t ulDevIdx, const int32_t ulMeasuringTime)
{
    return ::OTDR_SetMeasuringTime(ulDevIdx, ulMeasuringTime);
}

int32_t
ApiHelper::OTDR_SetUserIOR(const int32_t ulDevIdx, const double dUserIOR)
{
    return ::OTDR_SetUserIOR(ulDevIdx, dUserIOR);
}

int32_t
ApiHelper::OTDR_SetThr(const int32_t ulDevIdx, const double dRefThr, const double dSpliceLosThr, const double dFiberEndThr)
{
    return ::OTDR_SetThr(ulDevIdx, dRefThr, dSpliceLosThr, dFiberEndThr);
}

int32_t
ApiHelper::OTDR_Reset(const int32_t ulDevIdx, const int8_t ucResetType)
{
    return ::OTDR_Reset(ulDevIdx, ucResetType);
}

int32_t
ApiHelper::OTDR_Upgrade(const int32_t ulDevIdx, const std::string& c_pcFilePath)
{
    return ::OTDR_Upgrade(ulDevIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::OTDR_GetUpgadeStatus(const int32_t ulDevIdx)
{
    return ::OTDR_GetUpgadeStatus(ulDevIdx);
}

void
ApiHelper::OTDR_DbgRead(binary_rsp& _return, const int32_t ulDevIdx, const int32_t uiLen)
{
    _return.data.resize(uiLen, 0x00);
    _return.response = ::OTDR_DbgRead(ulDevIdx, (uint8_t *)&_return.data[0], uiLen);
}

int32_t
ApiHelper::OTDR_DbgWrite(const int32_t ulDevIdx, const std::string& pucBuf, const int32_t uiLen)
{
    return ::OTDR_DbgWrite(ulDevIdx, (uint8_t *)&pucBuf[0], uiLen);
}

int32_t
ApiHelper::OTDR_SetScanMode(const int32_t uiDevType, const int32_t ulScanMode)
{
    return ::OTDR_SetScanMode(uiDevType, ulScanMode);
}

int32_t
ApiHelper::OTDR_SetStartOffset(const int32_t ulDevIdx, const COtdrStartOffset_t& pstStartOffset)
{
    COtdrStartOffset data = {0};
    Convert::ToCOtdrStartOffset(data, pstStartOffset);
    return ::OTDR_SetStartOffset(ulDevIdx, &data);
}

void
ApiHelper::OTDR_GetStartOffset(COtdrStartOffset_rsp& _return, const int32_t ulDevIdx)
{
    COtdrStartOffset data = {0};
    _return.response = ::OTDR_GetStartOffset(ulDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCOtdrStartOffset_t(_return.data, data);
}

int32_t
ApiHelper::OTDR_StartScanPort(const int32_t ulDevIdx, const int32_t ulPortId)
{
    return ::OTDR_StartScanPort(ulDevIdx, ulPortId);
}

void
ApiHelper::SLOT_GetDevIdx(i32_list_rsp& _return, const int32_t uiDevType)
{
    uint32_t data[2] = {0};
    _return.response = ::SLOT_GetDevIdx(uiDevType, data, data + 1);
    CHECK_RSP(_return.response);
    _return.data.push_back(data[0]);
    _return.data.push_back(data[1]);
}

int32_t
ApiHelper::SLOT_SetOnline(const int32_t uiSlotIdx, const bool bOnline)
{
    return ::SLOT_SetOnline(uiSlotIdx, bOnline);
}

void
ApiHelper::SLOT_GetSlotNum(i32_rsp& _return)
{
    _return.response = ::SLOT_GetSlotNum((uint32_t *)&_return.data);
}

int32_t
ApiHelper::SLOT_SetMfg(const int32_t uiSlotIdx, const std::string& c_pcFilePath)
{
    return ::SLOT_SetMfg(uiSlotIdx, c_pcFilePath.data());
}

void
ApiHelper::SLOT_GetMfg(CMfg_rsp& _return, const int32_t uiSlotIdx)
{
    CMfg data = {0};
    _return.response = ::SLOT_GetMfg(uiSlotIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::SLOT_GetStatusData(CSlotStatusData_rsp& _return, const int32_t uiSlotIdx)
{
    CSlotStatusData data = {0};
    _return.response = ::SLOT_GetStatusData(uiSlotIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCSlotStatusData_t(_return.data, data);
}

int32_t
ApiHelper::SLOT_ClearPlugFlag(const int32_t uiSlotIdx)
{
    return ::SLOT_ClearPlugFlag(uiSlotIdx);
}

void
ApiHelper::SLOT_GetInfo(CSlotInfo_rsp& _return, const int32_t uiSlotIdx)
{
    CSlotInfo data = {0};
    _return.response = ::SLOT_GetInfo(uiSlotIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCSlotInfo_t(_return.data, data);
}

void
ApiHelper::SLOT_GetCali(CCali_rsp& _return, const int32_t uiSlotIdx)
{
    CCali data = {0};
    _return.response = ::SLOT_GetCali(uiSlotIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCCali_t(_return.data, data);
}

int32_t
ApiHelper::SLOT_SetCali(const int32_t uiSlotIdx, const std::string& c_pcFilePath)
{
    return ::SLOT_SetCali(uiSlotIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::SLOT_Reset(const int32_t uiSlotIdx, const int8_t ucResetType)
{
    return ::SLOT_Reset(uiSlotIdx, ucResetType);
}

int32_t
ApiHelper::SLOT_SetLed(const int32_t uiSlotIdx, const int32_t uiLedIdx, const int32_t uiState)
{
    return ::SLOT_SetLed(uiSlotIdx, uiLedIdx, uiState);
}

void
ApiHelper::SLOT_ReadEeprom(binary_rsp& _return, const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen)
{
    _return.data.resize(ulLen, 0x00);
    _return.response = ::SLOT_ReadEeprom(uiIdx, ulAddr, ulLen, (uint8_t *)&_return.data[0]);
}

int32_t
ApiHelper::SLOT_WriteEeprom(const int32_t uiIdx, const int64_t ulAddr, const int64_t ulLen, const std::string& pucVal)
{
    return ::SLOT_WriteEeprom(uiIdx, ulAddr, ulLen, (uint8_t *)&pucVal[0]);
}

void
ApiHelper::TDCM_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::TDCM_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::TDCM_GetStatusData(CTdcmStatusData_rsp& _return, const int32_t uiDevIdx)
{
    CTdcmStatusData data = {0};
    _return.response = ::TDCM_GetStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCTdcmStatusData_t(_return.data, data);
}

void
ApiHelper::TDCM_GetCfgData(CTdcmCfgData_rsp& _return, const int32_t uiDevIdx)
{
    CTdcmCfgData data;
    _return.response = ::TDCM_GetCfgData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCTdcmCfgData_t(_return.data, data);
}

int32_t
ApiHelper::TDCM_SetFrequency(const int32_t uiDevIdx, const double fFrequency)
{
    return ::TDCM_SetFrequency(uiDevIdx, fFrequency);
}

int32_t
ApiHelper::TDCM_SetDispersion(const int32_t uiDevIdx, const double fDispersion)
{
    return ::TDCM_SetDispersion(uiDevIdx, fDispersion);
}

int32_t
ApiHelper::TDCM_Reset(const int32_t uiDevIdx, const int8_t ucResetType)
{
    return ::TDCM_Reset(uiDevIdx, ucResetType);
}

void
ApiHelper::WSS_GetMfg(CMfg_rsp& _return, const int32_t uiDevIdx)
{
    CMfg data = {0};
    _return.response = ::WSS_GetMfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCMfg_t(_return.data, data);
}

void
ApiHelper::WSS_GetCfg(CWssAllCfg_rsp& _return, const int32_t uiDevIdx)
{
    CWssAllCfg data = {0};
    _return.response = ::WSS_GetCfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCWssAllCfg_t(_return.data, data);
}

void
ApiHelper::WSS_GetOscCfg(CWssAllCfg_rsp& _return, const int32_t uiDevIdx)
{
    CWssAllCfg data = {0};
    _return.response = ::WSS_GetOscCfg(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCWssAllCfg_t(_return.data, data);
}

void
ApiHelper::WSS_GetStatusData(CWssStatusData_rsp& _return, const int32_t uiDevIdx)
{
    CWssStatusData data = {0};
    _return.response = ::WSS_GetStatusData(uiDevIdx, &data);
    CHECK_RSP(_return.response);
    Convert::ToCWssStatusData_t(_return.data, data);
}

int32_t
ApiHelper::WSS_SetAllChCfg(const int32_t uiDevIdx, const int32_t uiSubIdx, const int32_t uiChCnt, const std::vector<CWssCfg_t> & pstWssCfg)
{
    std::vector<CWssCfg> data;
    for (int32_t i = 0; i < uiChCnt; i++) {
        CWssCfg temp = {0};
        Convert::ToCWssCfg(temp, pstWssCfg[i]);
        data.push_back(temp);
    }
    
    return ::WSS_SetAllChCfg(uiDevIdx, uiSubIdx, uiChCnt, data.data());
}

int32_t
ApiHelper::WSS_SetOscChCfg(const int32_t uiDevIdx, const int32_t uiSubIdx, const int32_t uiChCnt, const std::vector<CWssCfg_t> & pstWssCfg)
{
    std::vector<CWssCfg> data;
    for (int32_t i = 0; i < uiChCnt; i++) {
        CWssCfg temp = {0};
        Convert::ToCWssCfg(temp, pstWssCfg[i]);
        data.push_back(temp);
    }
    
    return ::WSS_SetOscChCfg(uiDevIdx, uiSubIdx, uiChCnt, data.data());
}

int32_t
ApiHelper::WSS_SetWaveplan(const int32_t uiDevIdx, const int32_t uiSubIdx, const int32_t uiChCnt, const std::vector<CWavePlan_t> & pstWavePlan)
{
    std::vector<CWavePlan> data;
    for (int32_t i = 0; i < uiChCnt; i++) {
        CWavePlan temp = {0};
        Convert::ToCWavePlan(temp, pstWavePlan[i]);
        data.push_back(temp);
    }

    return ::WSS_SetWaveplan(uiDevIdx, uiSubIdx, uiChCnt, data.data());
}

int32_t
ApiHelper::WSS_SetPortPowerThr(const int32_t uiDevIdx, const int32_t uiPortIdx, const int32_t uiType, const int16_t sThr)
{
    return ::WSS_SetPortPowerThr(uiDevIdx, uiPortIdx, uiType, sThr);
}

int32_t
ApiHelper::WSS_SetPortPowerHys(const int32_t uiDevIdx, const int32_t uiPortIdx, const int32_t uiType, const int16_t sHys)
{
    return ::WSS_SetPortPowerHys(uiDevIdx, uiPortIdx, uiType, sHys);
}

int32_t
ApiHelper::WSS_GetPortPowerHistory(const int32_t uiDevIdx)
{
    return ::WSS_GetPortPowerHistory(uiDevIdx);
}

int32_t
ApiHelper::WSS_SetLedMode(const int32_t uiDevIdx, const int32_t uiMode)
{
    return ::WSS_SetLedMode(uiDevIdx, uiMode);
}

int32_t
ApiHelper::WSS_SetLedDebugMode(const int32_t uiDevIdx, const int32_t uiMode)
{
    return ::WSS_SetLedDebugMode(uiDevIdx, uiMode);
}

int32_t
ApiHelper::WSS_SetLedStatus(const int32_t uiDevIdx, const int32_t uiLedIdx, const int32_t uiStatus)
{
    return ::WSS_SetLedStatus(uiDevIdx, uiLedIdx, uiStatus);
}

int32_t
ApiHelper::WSS_Reset(const int32_t uiDevIdx, const int8_t ucResetType)
{
    return ::WSS_Reset(uiDevIdx, ucResetType);
}

int32_t
ApiHelper::WSS_Upgrade(const int32_t uiDevIdx, const std::string& c_pcFilePath)
{
    return ::WSS_Upgrade(uiDevIdx, c_pcFilePath.data());
}

int32_t
ApiHelper::WSS_GetUpgradeStatus(const int32_t uiDevIdx)
{
    return ::WSS_GetUpgradeStatus(uiDevIdx);
}

int32_t
ApiHelper::WSS_SetUserData(const int32_t uiDevIdx, const std::string& pucData, const int32_t nLen)
{
    return ::WSS_SetUserData(uiDevIdx, (uint8_t *)&pucData[0], nLen);
}

void
ApiHelper::WSS_GetUserData(binary_rsp& _return, const int32_t uiDevIdx, const int32_t nLen)
{
    _return.data.resize(nLen, 0x00);
    _return.response = ::WSS_GetUserData(uiDevIdx, (uint8_t *)&_return.data[0], nLen);
}

int32_t
ApiHelper::WSS_SetPmUserData(const int32_t uiDevIdx, const std::string& pucData, const int32_t nLen)
{
    return ::WSS_SetPmUserData(uiDevIdx, (uint8_t *)&pucData[0], nLen);
}

void
ApiHelper::WSS_GetPmUserData(binary_rsp& _return, const int32_t uiDevIdx, const int32_t nLen)
{
    _return.data.resize(nLen, 0x00);
    _return.response = ::WSS_GetPmUserData(uiDevIdx, (uint8_t *)&_return.data[0], nLen);
}
