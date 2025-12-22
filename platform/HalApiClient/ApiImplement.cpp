#include "Client.h"
#include "Convert.h"

#include "util_cmn.h"


#ifdef __cplusplus
extern "C" {
#endif

#define CLIENT m_client.m_client

#define CHECK_RSP(rsp) \
do {\
    if ((rsp) == OPLK_ERR) {\
        return rsp;\
    }\
} while(0)


static Client m_client;


/* DevBoardCApi.h */

int
BOARD_GetChassisMfg(CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.BOARD_GetChassisMfg(data);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
BOARD_SetChassisMfg(const char *pcFilePath)
{
    return CLIENT.BOARD_SetChassisMfg(pcFilePath);
}

int
BOARD_SetChassisConfigType(const char *pcConfigType)
{
    return CLIENT.BOARD_SetChassisConfigType(pcConfigType);
}

int
BOARD_GetChassisCali(CCali *pstCali)
{
    CCali_rsp data;
    CLIENT.BOARD_GetChassisCali(data);

    CHECK_RSP(data.response);

    Convert::ToCCali(*pstCali, data.data);
    return data.response;
}

int
BOARD_SetChassisCali(const char *pcFilePath)
{
    return CLIENT.BOARD_SetChassisCali(pcFilePath);
}

int
BOARD_GetChassisCfg(uint32_t uiAddrSlice, const char *pcFilePath)
{
    return CLIENT.BOARD_GetChassisCfg((int32_t)uiAddrSlice, pcFilePath);
}

int
BOARD_SetChassisCfg(uint32_t uiAddrSlice, uint32_t uiSize, const char *pcFilePath)
{
    return CLIENT.BOARD_SetChassisCfg((int32_t)uiAddrSlice, (int32_t)uiSize, pcFilePath);
}

int
BOARD_GetUpgInfo(uint8_t *pucBuf, uint32_t ulLen)
{
    binary_rsp data;
    CLIENT.BOARD_GetUpgInfo(data, (int32_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucBuf, &data.data[0], ulLen);
    return data.response;
}

int
BOARD_SetUpgInfo(uint8_t *pucBuf, uint32_t ulLen)
{
    std::string data((const char *)pucBuf, ulLen);
    return CLIENT.BOARD_SetUpgInfo(data, (int32_t)ulLen);
}

int
BOARD_GetBdlHead(uint8_t *pucBuf, uint32_t ulLen)
{
    binary_rsp data;
    CLIENT.BOARD_GetBdlHead(data, (int32_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucBuf, &data.data[0], ulLen);
    return data.response;
}

int
BOARD_SetBdlHead(uint8_t *pucBuf, uint32_t ulLen)
{
    std::string data((const char *)pucBuf, ulLen);
    return CLIENT.BOARD_SetBdlHead(data, (int32_t)ulLen);
}

int
BOARD_GetStatusData(CBoardStatusData *pstBoardStatus)
{
    CBoardStatusData_rsp data;
    CLIENT.BOARD_GetStatusData(data);

    CHECK_RSP(data.response);

    Convert::ToCBoardStatusData(*pstBoardStatus, data.data);
    return data.response;
}

int
BOARD_GetSccMfg(CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.BOARD_GetSccMfg(data);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
BOARD_SetSccMfg(const char *pcFilePath)
{
    return CLIENT.BOARD_SetSccMfg(pcFilePath);
}

int
BOARD_SetResetType(uint8_t ucResetType)
{
    return CLIENT.BOARD_SetResetType((int8_t)ucResetType);
}

int
BOARD_GetResetType(int iIndex, uint8_t *pucResetType)
{
    i8_rsp data;
    CLIENT.BOARD_GetResetType(data, iIndex);

    CHECK_RSP(data.response);

    *pucResetType = data.data;
    return data.response;
}

int
BOARD_CfgWatchDogTime(bool bEnable, uint8_t ucTimeout)
{
    return CLIENT.BOARD_CfgWatchDogTime(bEnable, (int8_t)ucTimeout);
}

int
BOARD_GetApsdStatus(int iIndex, bool *pbCfg, bool *pbStatus, bool *pbEvent)
{
    bool_list_rsp data;
    CLIENT.BOARD_GetApsdStatus(data, iIndex);

    CHECK_RSP(data.response);

    *pbCfg = data.data[0];
    *pbStatus = data.data[1];
    *pbEvent = data.data[2];
    return data.response;
}

int
BOARD_SetLedState(uint32_t uiDevIdx, uint32_t uiState)
{
    return CLIENT.BOARD_SetLedState((int32_t)uiDevIdx, (int32_t)uiState);
}

int
BOARD_ResetLogic(uint32_t uiDevIdx, uint8_t ucResetType)
{
    return CLIENT.BOARD_ResetLogic((int32_t)uiDevIdx, (int8_t)ucResetType);
}

int
BOARD_UpgradeLogic(uint32_t uiDevIdx, const char *c_pcFilePath)
{
    return CLIENT.BOARD_UpgradeLogic((int32_t)uiDevIdx, c_pcFilePath);
}

int
BOARD_GetUpgadeStatus()
{
    return CLIENT.BOARD_GetUpgadeStatus();
}

int
FAN_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.FAN_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
FAN_SetMfg(uint32_t uiDevIdx, const char *pcFilePath)
{
    return CLIENT.FAN_SetMfg((int32_t)uiDevIdx, pcFilePath);
}

int
FAN_SetSpeed(uint32_t uiDevIdx, uint32_t uiDuty)
{
    return CLIENT.FAN_SetSpeed((int32_t)uiDevIdx, (int32_t)uiDuty);
}

int
FAN_SetControllerEEP(uint32_t uiDevIdx)
{
    return CLIENT.FAN_SetControllerEEP((int32_t)uiDevIdx);
}

int
FAN_SetLed(uint32_t uiDevIdx, uint32_t uiValue)
{
    return CLIENT.FAN_SetLed((int32_t)uiDevIdx, (int32_t)uiValue);
}

int
POWER_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.POWER_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

char *BOARD_GetProductName(char *pcBuf, size_t nSize)
{
    string_rsp data;
    CLIENT.BOARD_GetProductName(data, (int32_t)nSize);

    if (data.response == OPLK_ERR) {
        return NULL;
    }

    memcpy(pcBuf, &data.data[0], nSize);
    return pcBuf;
}

char *BOARD_GetConfigType(char *pcBuf, size_t nSize)
{
    string_rsp data;
    CLIENT.BOARD_GetConfigType(data, (int32_t)nSize);

    if (data.response == OPLK_ERR) {
        return NULL;
    }

    memcpy(pcBuf, &data.data[0], nSize);
    return pcBuf;
}

PRODUCT_TYPE_EN
BOARD_GetProductType()
{
    return (PRODUCT_TYPE_EN)CLIENT.BOARD_GetProductType();
}

int
BOARD_SetLogLevel(uint32_t uiLogLevel)
{
    return CLIENT.BOARD_SetLogLevel((int32_t)uiLogLevel);
}

int
BOARD_ConvertDevType(const char *pcName, uint32_t *puiDevType)
{
    i32_rsp data;
    CLIENT.BOARD_ConvertDevType(data, pcName);

    *puiDevType = data.data;
    return data.response;
}


/* DevCvCApi.h */

int
Cv_GetMuxStatusData(EnCvLine enCvLine, CCvMuxStatusData *pstMuxStatus)
{
    CCvMuxStatusData_rsp data;
    CLIENT.Cv_GetMuxStatusData(data, (int32_t)enCvLine);

    CHECK_RSP(data.response);

    Convert::ToCCvMuxStatusData(*pstMuxStatus, data.data);
    return data.response;
}

int
Cv_GetClientStatusData(EnCvLine enCvLine, CCvClientStatusData *pstClientStatus)
{
    CCvClientStatusData_rsp data;
    CLIENT.Cv_GetClientStatusData(data, (int32_t)enCvLine);

    CHECK_RSP(data.response);

    Convert::ToCCvClientStatusData(*pstClientStatus, data.data);
    return data.response;
}

int
Cv_GetRef(CCvRef *pstRef)
{
    CCvRef_rsp data;
    CLIENT.Cv_GetRef(data);

    CHECK_RSP(data.response);

    Convert::ToCCvRef(*pstRef, data.data);
    return data.response;
}


/* DevDbgCApi.h */

int
DBG_ReadLogicReg(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    binary_rsp data;
    CLIENT.DBG_ReadLogicReg(data, (int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucVal, &data.data[0], ulLen);
    return data.response;
}

int
DBG_WriteLogicReg(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    std::string data((const char *)pucVal, ulLen);
    return CLIENT.DBG_WriteLogicReg((int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen, data);
}

int
DBG_ReadLogicRegSlc(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    binary_rsp data;
    CLIENT.DBG_ReadLogicRegSlc(data, (int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucVal, &data.data[0], ulLen);
    return data.response;
}

int
DBG_WriteLogicRegSlc(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    std::string data((const char *)pucVal, ulLen);
    return CLIENT.DBG_WriteLogicRegSlc((int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen, data);
}

int
DBG_LoopEnable(bool bEnable)
{
    return CLIENT.DBG_LoopEnable(bEnable);
}

int
DBG_LoopInterval(uint32_t uiInterval)
{
    return CLIENT.DBG_LoopInterval((int32_t)uiInterval);
}

int
DBG_IdleEnable(bool bEnable)
{
    return CLIENT.DBG_IdleEnable(bEnable);
}

int
DBG_ApsdEnable(int iIndex, bool bEnable)
{
    return CLIENT.DBG_ApsdEnable(iIndex, bEnable);
}

int
DBG_GetAprStatus(uint32_t uiIndex, uint8_t *pucVal)
{
    i8_rsp data;
    CLIENT.DBG_GetAprStatus(data, (int32_t)uiIndex);

    CHECK_RSP(data.response);

    *pucVal = (uint8_t)data.data;
    return data.response;
}

int
DBG_SpiSendCommand(uint32_t ulChip, uint8_t *pucBufW, uint8_t *pucBufR, uint32_t ulLen)
{
    binary_rsp data;
    std::string data1((const char *)pucBufW, ulLen);
    CLIENT.DBG_SpiSendCommand(data, (int32_t)ulChip, data1, (int32_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucBufR, &data.data[0], ulLen);
    return data.response;
}

int
DBG_SpiFlashRead(uint64_t ulChip, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    binary_rsp data;
    CLIENT.DBG_SpiFlashRead(data, (int64_t)ulChip, (int64_t)ulAddr, (int64_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucVal, &data.data[0], ulLen);
    return data.response;
}

int
DBG_SpiFlashWrite(uint64_t ulChip, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    std::string data((const char *)pucVal, ulLen);
    return CLIENT.DBG_SpiFlashWrite((int64_t)ulChip, (int64_t)ulAddr, (int64_t)ulLen, data);
}

int
DBG_MdioRead(uint32_t uiIdx, uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData)
{
    i16_rsp data;
    CLIENT.DBG_MdioRead(data, (int32_t)uiIdx, (int32_t)ulPhyAddr, (int32_t)ulRegAddr);

    CHECK_RSP(data.response);

    *pusData = (uint16_t)data.data;
    return data.response;
}

int
DBG_MdioWrite(uint32_t uiIdx, uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData)
{
    return CLIENT.DBG_MdioWrite((int32_t)uiIdx, (int32_t)ulPhyAddr, (int32_t)ulRegAddr, (int16_t)usData);
}

int
DBG_NetSwitchRead(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData)
{
    i16_rsp data;
    CLIENT.DBG_NetSwitchRead(data, (int32_t)ulPhyAddr, (int32_t)ulRegAddr);

    CHECK_RSP(data.response);

    *pusData = (uint16_t)data.data;
    return data.response;
}

int
DBG_NetSwitchWrite(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData)
{
    return CLIENT.DBG_NetSwitchWrite((int32_t)ulPhyAddr, (int32_t)ulRegAddr, (int16_t)usData);
}

int
DBG_SwitchPhyRead(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData)
{
    i16_rsp data;
    CLIENT.DBG_SwitchPhyRead(data, (int32_t)ulPhyAddr, (int32_t)ulRegAddr);

    CHECK_RSP(data.response);

    *pusData = (uint16_t)data.data;
    return data.response;
}

int
DBG_SwitchPhyWrite(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData)
{
    return CLIENT.DBG_SwitchPhyWrite((int32_t)ulPhyAddr, (int32_t)ulRegAddr, (int16_t)usData);
}

int
DBG_ReadEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    binary_rsp data;
    CLIENT.DBG_ReadEeprom(data, (int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucVal, &data.data[0], ulLen);
    return data.response;
}

int
DBG_WriteEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    std::string data((const char *)pucVal, ulLen);
    return CLIENT.DBG_WriteEeprom((int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen, data);
}


/* DevEdfaCApi.h */

int
EDFA_GetMfg(uint32_t uiDevType, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.EDFA_GetMfg(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
EDFA_GetStatusData(uint32_t uiDevType, COaStatusData *pstEdfaStatus)
{
    COaStatusData_rsp data;
    CLIENT.EDFA_GetStatusData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOaStatusData(*pstEdfaStatus, data.data);
    return data.response;
}

int
EDFA_GetCfgData(uint32_t uiDevType, COaCfgData *pstEdfaCfg)
{
    COaCfgData_rsp data;
    CLIENT.EDFA_GetCfgData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOaCfgData(*pstEdfaCfg, data.data);
    return data.response;
}

int
EDFA_GetDebugInfo(uint32_t uiDevType, const char *pcFilePath)
{
    return CLIENT.EDFA_GetDebugInfo((int32_t)uiDevType, pcFilePath);
}

int
EDFA_GetMcuDebugInfo(uint32_t uiDevType, const char *pcFilePath)
{
    return CLIENT.EDFA_GetMcuDebugInfo((int32_t)uiDevType, pcFilePath);
}

int
EDFA_SetGainRange(uint32_t uiDevType, int16_t sGainRange)
{
    return CLIENT.EDFA_SetGainRange((int32_t)uiDevType, sGainRange);
}

int
EDFA_SetGain(uint32_t uiDevType, int16_t sGain)
{
    return CLIENT.EDFA_SetGain((int32_t)uiDevType, sGain);
}

int
EDFA_SetTilt(uint32_t uiDevType, int16_t sTilt)
{
    return CLIENT.EDFA_SetTilt((int32_t)uiDevType, sTilt);
}

int
EDFA_SetMode(uint32_t uiDevType, uint8_t ucMode, int16_t sVal)
{
    return CLIENT.EDFA_SetMode((int32_t)uiDevType, (int8_t)ucMode, sVal);
}

int
EDFA_SetPumpEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetPumpEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetAprEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetAprEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetAutolosEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetAutolosEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetRxLosThr(uint32_t uiDevType, int16_t sThr, int16_t sHys)
{
    return CLIENT.EDFA_SetRxLosThr((int32_t)uiDevType, sThr, sHys);
}

int
EDFA_SetAttn(uint32_t uiDevType, int16_t sAttn)
{
    return CLIENT.EDFA_SetAttn((int32_t)uiDevType, sAttn);
}

int
EDFA_GetAttn(uint32_t uiDevType, int16_t *psAttn)
{
    i16_rsp data;
    CLIENT.EDFA_GetAttn(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *psAttn = data.data;
    return data.response;
}

int
EDFA_Reset(uint32_t uiDevType, uint8_t ucResetType)
{
    return CLIENT.EDFA_Reset((int32_t)uiDevType, (int8_t)ucResetType);
}

int
EDFA_Upgrade(uint32_t uiDevType, const char *c_pcFilePath)
{
    return CLIENT.EDFA_Upgrade((int32_t)uiDevType, c_pcFilePath);
}

int
EDFA_Swap(uint32_t uiDevType)
{
    return CLIENT.EDFA_Swap((int32_t)uiDevType);
}

int
EDFA_Commit(uint32_t uiDevType)
{
    return CLIENT.EDFA_Commit((int32_t)uiDevType);
}

int
EDFA_GetUpgadeStatus(uint32_t uiDevType)
{
    return CLIENT.EDFA_GetUpgadeStatus((int32_t)uiDevType);
}

int
EDFA_DbgRead(uint32_t uiDevType, uint8_t *pucBuf, uint32_t uiLen)
{
    binary_rsp data;
    CLIENT.EDFA_DbgRead(data, (int32_t)uiDevType, (int32_t)uiLen);

    CHECK_RSP(data.response);

    memcpy(pucBuf, &data.data[0], uiLen);
    return data.response;
}

int
EDFA_DbgWrite(uint32_t uiDevType, uint8_t *pucBuf, uint32_t uiLen)
{
    std::string data((const char *)pucBuf, uiLen);
    return CLIENT.EDFA_DbgWrite((int32_t)uiDevType, data, (int64_t)uiLen);
}

int
EDFA_SetDfbEnable(uint32_t uiDevType, bool bEnable, int32_t iPower)
{
    return CLIENT.EDFA_SetDfbEnable((int32_t)uiDevType, bEnable, iPower);
}

int
EDFA_SetOscEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetOscEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetOtdrSwitchPos(uint32_t uiDevType, uint32_t uiPos)
{
    return CLIENT.EDFA_SetOtdrSwitchPos((int32_t)uiDevType, uiPos);
}

int
EDFA_SetOscAddThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys)
{
    return CLIENT.EDFA_SetOscAddThrHys((int32_t)uiDevType, sThr, sHys);
}

int
EDFA_SetOscDropThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys)
{
    return CLIENT.EDFA_SetOscDropThrHys((int32_t)uiDevType, sThr, sHys);
}

int
EDFA_SetOscRxThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys)
{
    return CLIENT.EDFA_SetOscRxThrHys((int32_t)uiDevType, sThr, sHys);
}

int
EDFA_SetApsdEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetApsdEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_GetApsdStatus(uint32_t uiDevType, bool *pbCfg, bool *pbStatus, bool *pbEvent)
{
    bool_list_rsp data;
    CLIENT.EDFA_GetApsdStatus(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *pbCfg = data.data[0];
    *pbStatus = data.data[1];
    *pbEvent = data.data[2];
    return data.response;
}

int
EDFA_GetOcmAttn(uint32_t uiDevType, int16_t *psAttn)
{
    i16_rsp data;
    CLIENT.EDFA_GetOcmAttn(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *psAttn = data.data;
    return data.response;
}

int
EDFA_SetUpgState(uint32_t uiDevType, int16_t sState)
{
    return CLIENT.EDFA_SetUpgState((int32_t)uiDevType, sState);
}

int
EDFA_SetLedState(uint32_t uiDevType, int16_t sState)
{
    return CLIENT.EDFA_SetLedState((int32_t)uiDevType, sState);
}

int
EDFA_SetLedAlm(uint32_t uiDevType, int16_t sState)
{
    return CLIENT.EDFA_SetLedAlm((int32_t)uiDevType, sState);
}

int
EDFA_GetCali(uint32_t uiDevType, COaCaliData *pstCaliInfo)
{
    COaCaliData_rsp data;
    CLIENT.EDFA_GetCali(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOaCaliData(*pstCaliInfo, data.data);
    return data.response;
}

int
EDFA_SetOtdrCali(uint32_t uiDevType, char *pcFilePath)
{
    return CLIENT.EDFA_SetOtdrCali((int32_t)uiDevType, pcFilePath);
}

int
EDFA_SetOcmCali(uint32_t uiDevType, char *pcFilePath)
{
    return CLIENT.EDFA_SetOcmCali((int32_t)uiDevType, pcFilePath);
}

int
EDFA_SetManualVoaEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetManualVoaEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetPaddingVoaConfigPower(uint32_t uiDevType, int16_t sOutPower)
{
    return CLIENT.EDFA_SetPaddingVoaConfigPower((int32_t)uiDevType, sOutPower);
}

int
EDFA_SetManualGainEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.EDFA_SetManualGainEnable((int32_t)uiDevType, bEnable);
}

int
EDFA_SetThr(uint32_t uiDevType, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr, int16_t sHys)
{
    return CLIENT.EDFA_SetThr((int32_t)uiDevType, (int32_t)uiPortIdx, (int32_t)uiType, sThr, sHys);
}

int
EDFA_SetPumpCurrent(uint32_t uiDevType, uint32_t uiPumpIdx, int16_t sCurrent)
{
    return CLIENT.EDFA_SetPumpCurrent((int32_t)uiDevType, (int32_t)uiPumpIdx, sCurrent);
}

int
EDFA_SetAlmMask(uint32_t uiDevType, int32_t iMaskIdx, int32_t iMaskVal)
{
    return CLIENT.EDFA_SetAlmMask((int32_t)uiDevType, iMaskIdx, iMaskVal);
}

int
EDFA_GetEventLog(uint32_t uiDevType, COaEventLogAllData *pstEventLogAll)
{
    COaEventLogAllData_rsp data;
    CLIENT.EDFA_GetEventLog(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOaEventLogAllData(*pstEventLogAll, data.data);
    return data.response;
}

int
EDFA_SetShutterState(uint32_t uiDevType, bool block)
{
    return CLIENT.EDFA_SetShutterState((int32_t)uiDevType, block);
}

int EDFA_GetShutterState(uint32_t uiDevType, bool *block)
{
    bool_rsp data;
    CLIENT.EDFA_GetShutterState(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *block = data.data;
    return data.response;
}


/* DevExtendCApi.h */

int
EXTEND_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.EXTEND_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
EXTEND_GetStatusData(uint32_t uiDevIdx, CExtendStatusData *pstStatus)
{
    CExtendStatusData_rsp data;
    CLIENT.EXTEND_GetStatusData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCExtendStatusData(*pstStatus, data.data);
    return data.response;
}

int
EXTEND_Reset(uint32_t uiDevIdx, uint8_t ucResetType)
{
    return CLIENT.EXTEND_Reset((int32_t)uiDevIdx, (int8_t)ucResetType);
}

int
EXTEND_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath)
{
    return CLIENT.EXTEND_Upgrade((int32_t)uiDevIdx, c_pcFilePath);
}

int
EXTEND_GetUpgadeStatus(uint32_t uiDevIdx)
{
    return CLIENT.EXTEND_GetUpgadeStatus((int32_t)uiDevIdx);
}

int
EXTEND_DbgRead(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen)
{
    binary_rsp data;
    CLIENT.EXTEND_DbgRead(data, (int32_t)uiDevIdx, (int32_t)uiLen);

    CHECK_RSP(data.response);

    memcpy(pucBuf, &data.data[0], uiLen);
    return data.response;
}

int
EXTEND_DbgWrite(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen)
{
    std::string data((const char *)pucBuf, uiLen);
    return CLIENT.EXTEND_DbgWrite((int32_t)uiDevIdx, data, (int32_t)uiLen);
}

int
EXTEND_SetSfp(uint32_t uiDevIdx, uint32_t ulVal)
{
    return CLIENT.EXTEND_SetSfp((int32_t)uiDevIdx, (int32_t)ulVal);
}

int
MIRROR_GetStatusData(uint32_t uiDevIdx, CMirrorData *pstStatus)
{
    CMirrorData_rsp data;
    CLIENT.MIRROR_GetStatusData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMirrorData(*pstStatus, data.data);
    return data.response;
}

int
SWITCH_Pos(uint32_t uiDevIdx, uint32_t uiPort)
{
    return CLIENT.SWITCH_Pos((int32_t)uiDevIdx, (int32_t)uiPort);
}


/* DevMuxCApi.h */

int
MUX_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.MUX_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
MUX_GetStatusData(uint32_t uiDevIdx, CMuxStatusData *pstStatus)
{
    CMuxStatusData_rsp data;
    CLIENT.MUX_GetStatusData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMuxStatusData(*pstStatus, data.data);
    return data.response;
}

int
MUX_GetCali(uint32_t uiDevIdx, CMuxCaliData *pstCali)
{
    CMuxCaliData_rsp data;
    CLIENT.MUX_GetCali(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMuxCaliData(*pstCali, data.data);
    return data.response;
}


/* DevOcmCApi.h */

int
OCM_GetMfg(uint32_t uiDevType, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.OCM_GetMfg(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
OCM_GetStatusData(uint32_t uiDevType, COcmStatusData *pstOcmStatus)
{
    COcmStatusData_rsp data;
    CLIENT.OCM_GetStatusData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOcmStatusData(*pstOcmStatus, data.data);
    return data.response;
}

int
OCM_GetChPower(uint32_t uiDevType, uint32_t uiPortId, COcmChPower *pstOcmChPower)
{
    COcmChPower_rsp data;
    CLIENT.OCM_GetChPower(data, (int32_t)uiDevType, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOcmChPower(*pstOcmChPower, data.data);
    return data.response;
}

int
OCM_GetOsaData(uint32_t uiDevType, uint32_t uiPortId, COcmOsa *pstOcmOsa)
{
    COcmOsa_rsp data;
    CLIENT.OCM_GetOsaData(data, (int32_t)uiDevType, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOcmOsa(*pstOcmOsa, data.data);
    return data.response;
}

int
OCM_GetRealTimeOsaData(uint32_t uiDevType, uint32_t uiPortId, COcmOsa *pstOcmOsa)
{
    COcmOsa_rsp data;
    CLIENT.OCM_GetRealTimeOsaData(data, (int32_t)uiDevType, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOcmOsa(*pstOcmOsa, data.data);
    return data.response;
}

int
OCM_SetWaveplan(uint32_t uiDevType, uint32_t uiPortId, uint32_t uiChCnt, CWavePlanSlice *pstWavePlan)
{
    std::vector<CWavePlanSlice_t> data;
    for (uint32_t i = 0; i < uiChCnt; i++) {
        CWavePlanSlice_t temp;
        Convert::ToCWavePlanSlice_t(temp, *(pstWavePlan + i));
        data.push_back(temp);
    }
    
    return CLIENT.OCM_SetWaveplan((int32_t)uiDevType, (int32_t)uiPortId, (int32_t)uiChCnt, data);
}

int
OCM_SetOcmWaveplan(uint32_t uiDevType, uint32_t uiPortId, uint32_t uiChCnt, STChannelGrid *pstWavePlan)
{
    std::vector<STChannelGrid_t> data;
    for (uint32_t i = 0; i < uiChCnt; i++) {
        STChannelGrid_t temp;
        Convert::ToSTChannelGrid_t(temp, *(pstWavePlan + i));
        data.push_back(temp);
    }
    
    return CLIENT.OCM_SetOcmWaveplan((int32_t)uiDevType, (int32_t)uiPortId, (int32_t)uiChCnt, data);
}

int
OCM_Reset(uint32_t uiDevType, uint8_t ucResetType)
{
    return CLIENT.OCM_Reset((int32_t)uiDevType, (int8_t)ucResetType);
}

int
OCM_Upgrade(uint32_t uiDevType, const char *c_pcFilePath)
{
    return CLIENT.OCM_Upgrade((int32_t)uiDevType, c_pcFilePath);
}

int
OCM_Commit(uint32_t uiDevType)
{
    return CLIENT.OCM_Commit((int32_t)uiDevType);
}

int
OCM_GetUpgradeStatus(uint32_t uiDevType)
{
    return CLIENT.OCM_GetUpgradeStatus((int32_t)uiDevType);
}

int
OCM_SetVoa(uint32_t uiDevType, int16_t sAttn)
{
    return CLIENT.OCM_SetVoa((int32_t)uiDevType, sAttn);
}

int
OCM_GetVoa(uint32_t uiDevType, int16_t *psAttn)
{
    i16_rsp data;
    CLIENT.OCM_GetVoa(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *psAttn = data.data;
    return data.response;
}

int
OCM_GetVoaPd(uint32_t uiDevType, int16_t *psVoaIn, int16_t *psVoaOut)
{
    i16_list_rsp data;
    CLIENT.OCM_GetVoaPd(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *psVoaIn = data.data[0];
    *psVoaOut = data.data[1];
    return data.response;
}


/* DevOcsCApi.h */

int
OCS_GetMfg(uint32_t uiDevType, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.OCS_GetMfg(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
OCS_GetStatusData(uint32_t uiDevType, COcsStatusData *pstStatus)
{
    COcsStatusData_rsp data;
    CLIENT.OCS_GetStatusData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOcsStatusData(*pstStatus, data.data);
    return data.response;
}

int
OCS_SetConnection(uint32_t uiDevType, const COcsConnection *pstConnection)
{
    COcsConnection_t data;
    Convert::ToCOcsConnection_t(data, *pstConnection);

    return CLIENT.OCS_SetConnection(uiDevType, data);
}

int
OCS_SetConnections(uint32_t uiDevType, const COcsConnections *pstConnections)
{
    COcsConnections_t data;
    Convert::ToCOcsConnections_t(data, *pstConnections);

    return CLIENT.OCS_SetConnections(uiDevType, data);
}

int
OCS_SetLedState(uint32_t uiDevType, uint32_t index, uint32_t uiState)
{
    return CLIENT.OCS_SetLedState(uiDevType, index, uiState);
}

int
OCS_SetLedMode(uint32_t uiDevType, uint32_t uiMode)
{
    return CLIENT.OCS_SetLedMode(uiDevType, uiMode);
}

int
OCS_Reset(uint32_t uiDevType, uint8_t ucResetType)
{
    return CLIENT.OCS_Reset(uiDevType, ucResetType);
}

int
OCS_Upgrade(uint32_t uiDevType, const char *pcPath)
{
    return CLIENT.OCS_Upgrade(uiDevType, pcPath);
}

int
OCS_GetUpgradeStatus(uint32_t uiDevType)
{
    return CLIENT.OCS_GetUpgradeStatus(uiDevType);
}


/* DevOpsCApi.h */

int
OPS_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.OPS_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
OPS_GetCommStatusData(uint32_t uiDevType, COpsCommStatusData *pstOpsStatus)
{
    COpsCommStatusData_rsp data;
    CLIENT.OPS_GetCommStatusData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOpsCommStatusData(*pstOpsStatus, data.data);
    return data.response;
}

int
OPS_GetCfgData(uint32_t uiDevIdx, COpsCfgData *pstOpsCfg, uint32_t uiPortId)
{
    COpsCfgData_rsp data;
    CLIENT.OPS_GetCfgData(data, (int32_t)uiDevIdx, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOpsCfgData(*pstOpsCfg, data.data);
    return data.response;
}

int
OPS_GetStatusData(uint32_t uiDevIdx, COpsStatusData *pstOpsStatus, uint32_t uiPortId)
{
    COpsStatusData_rsp data;
    CLIENT.OPS_GetStatusData(data, (int32_t)uiDevIdx, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOpsStatusData(*pstOpsStatus, data.data);
    return data.response;
}

int
OPS_GetHistoryData(uint32_t uiDevIdx, COpsHistoryData *pstData, uint32_t uiPortId)
{
    COpsHistoryData_rsp data;
    CLIENT.OPS_GetHistoryData(data, (int32_t)uiDevIdx, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOpsHistoryData(*pstData, data.data);
    return data.response;
}

int
OPS_GetLedStatus(uint32_t uiDevIdx, COpsLed *pstData)
{
    COpsLed_rsp data;
    CLIENT.OPS_GetLedStatus(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCOpsLed(*pstData, data.data);
    return data.response;
}

int
OPS_ClearAlarmDuration(uint32_t uiDevIdx)
{
    return CLIENT.OPS_ClearAlarmDuration((int32_t)uiDevIdx);
}

int
OPS_SetThrPwrDiff(uint32_t uiDevIdx, int16_t sThr, int16_t sHys, uint32_t uiPortId)
{
    return CLIENT.OPS_SetThrPwrDiff((int32_t)uiDevIdx, sThr, sHys, (int32_t)uiPortId);
}

int
OPS_SetThrLine(uint32_t uiDevIdx, uint32_t uiPortIdx, int16_t sThr, int16_t sHys, uint32_t uiPortId)
{
    return CLIENT.OPS_SetThrLine((int32_t)uiDevIdx, (int32_t)uiPortIdx, sThr, sHys, (int32_t)uiPortId);
}

int
OPS_SetPortPowerThr(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr, uint32_t uiPortId)
{
    return CLIENT.OPS_SetPortPowerThr((int32_t)uiDevIdx, (int32_t)uiPortIdx, (int32_t)uiType, sThr, (int32_t)uiPortId);
}

int
OPS_SetPortPowerHys(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sHys, uint32_t uiPortId)
{
    return CLIENT.OPS_SetPortPowerHys((int32_t)uiDevIdx, (int32_t)uiPortIdx, (int32_t)uiType, sHys, (int32_t)uiPortId);
}

int
OPS_SetWtr(uint32_t uiDevIdx, uint32_t uiWtr, uint32_t uiPortId)
{
    return CLIENT.OPS_SetWtr((int32_t)uiDevIdx, (int32_t)uiWtr, (int32_t)uiPortId);
}

int
OPS_SetHoldOffTime(uint32_t uiDevIdx, uint32_t uiHoldOffTime, uint32_t uiPortId)
{
    return CLIENT.OPS_SetHoldOffTime((int32_t)uiDevIdx, (int32_t)uiHoldOffTime, (int32_t)uiPortId);
}

int
OPS_SetRevertive(uint32_t uiDevIdx, bool bRevertive, uint32_t uiPortId)
{
    return CLIENT.OPS_SetRevertive((int32_t)uiDevIdx, bRevertive, (int32_t)uiPortId);
}

int
OPS_SetMode(uint32_t uiDevIdx, uint32_t uiMode, uint32_t uiPortId)
{
    return CLIENT.OPS_SetMode((int32_t)uiDevIdx, (int32_t)uiMode, (int32_t)uiPortId);
}

int
OPS_SetRelativeThr(uint32_t uiDevIdx, int16_t sThr, uint32_t uiPortId)
{
    return CLIENT.OPS_SetRelativeThr((int32_t)uiDevIdx, sThr, (int32_t)uiPortId);
}

int
OPS_SetRelativeOffset(uint32_t uiDevIdx, int16_t sOffset, uint32_t uiPortId)
{
    return CLIENT.OPS_SetRelativeOffset((int32_t)uiDevIdx, sOffset, (int32_t)uiPortId);
}

int
OPS_SetSwitchThr(uint32_t uiDevIdx, uint32_t uiPos, int32_t iThr, uint32_t uiPortId)
{
    return CLIENT.OPS_SetSwitchThr((int32_t)uiDevIdx, (int32_t)uiPos, iThr, (int32_t)uiPortId);
}

int
OPS_SetSwitchHys(uint32_t uiDevIdx, uint32_t uiPos, int32_t iHys, uint32_t uiPortId)
{
    return CLIENT.OPS_SetSwitchHys((int32_t)uiDevIdx, (int32_t)uiPos, iHys, (int32_t)uiPortId);
}

int
OPS_Reset(uint32_t uiDevIdx, uint8_t ucResetType)
{
    return CLIENT.OPS_Reset((int32_t)uiDevIdx, (int8_t)ucResetType);
}

int
OPS_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath)
{
    return CLIENT.OPS_Upgrade((int32_t)uiDevIdx, c_pcFilePath);
}

int
OPS_GetUpgadeStatus(uint32_t uiDevIdx)
{
    return CLIENT.OPS_GetUpgadeStatus((int32_t)uiDevIdx);
}

int
OPS_SetLedDebugMode(uint32_t uiDevType, uint32_t uiMode)
{
    return CLIENT.OPS_SetLedDebugMode((int32_t)uiDevType, (int32_t)uiMode);
}

int
OPS_SetLedStatus(uint32_t uiDevType, uint32_t uiLedIdx, uint32_t uiStatus)
{
    return CLIENT.OPS_SetLedStatus((int32_t)uiDevType, (int32_t)uiLedIdx, (int32_t)uiStatus);
}

int
OPS_SetConnectionPdThr(uint32_t uiDevIdx, uint32_t uiPdIdx, uint32_t uiType, int16_t sThr, uint32_t uiPortId)
{
    return CLIENT.OPS_SetConnectionPdThr((int32_t)uiDevIdx, (int32_t)uiPdIdx, (int32_t)uiType, sThr, (int32_t)uiPortId);
}

int
OPS_SetConnectionPdHys(uint32_t uiDevIdx, uint32_t uiPdIdx, uint32_t uiType, int16_t sHys, uint32_t uiPortId)
{
    return CLIENT.OPS_SetConnectionPdHys((int32_t)uiDevIdx, (int32_t)uiPdIdx, (int32_t)uiType, sHys, (int32_t)uiPortId);
}

int32_t
OPS_SetAlmMask(uint32_t uiDevType, int32_t iMaskIdx, int32_t iMaskVal, uint32_t uiPortId)
{
    return CLIENT.OPS_SetAlmMask((int32_t)uiDevType, iMaskIdx, iMaskVal, (int32_t)uiPortId);
}

int
OPS_GetEventLog(uint32_t uiDevType, COpsEventLogAllData *pstEventLogAll, uint32_t uiPortId)
{
    COpsEventLogAllData_rsp data;
    CLIENT.OPS_GetEventLog(data, (int32_t)uiDevType, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOpsEventLogAllData(*pstEventLogAll, data.data);
    return data.response;
}

int
OPS_SetRemoteStatus(uint32_t uiDevIdx, COpsReqStatus *pstStatus, uint32_t uiPortId)
{
    COpsReqStatus_t data;
    Convert::ToCOpsReqStatus_t(data, *pstStatus);

    return CLIENT.OPS_SetRemoteStatus((int32_t)uiDevIdx, data, (int32_t)uiPortId);
}

int
OPS_GetRequestStatus(uint32_t uiDevIdx, COpsBidirectionStatus *pstStatus, uint32_t uiPortId)
{
    COpsBidirectionStatus_rsp data;
    CLIENT.OPS_GetRequestStatus(data, (int32_t)uiDevIdx, (int32_t)uiPortId);

    CHECK_RSP(data.response);

    Convert::ToCOpsBidirectionStatus(*pstStatus, data.data);
    return data.response;
}

int
OPS_SetSwitchingType(uint32_t uiDevIdx, uint8_t ucType, uint32_t uiPortId)
{
    return CLIENT.OPS_SetSwitchingType((int32_t)uiDevIdx, (int8_t)ucType, (int32_t)uiPortId);
}

int
OPS_GetOpsDevIdByKey(char *pcName, uint32_t *piDevId, uint32_t *piPortId)
{
    i32_list_rsp data;
    CLIENT.OPS_GetOpsDevIdByKey(data, pcName);

    CHECK_RSP(data.response);

    *piDevId = (uint32_t)data.data[0];
    *piPortId = (uint32_t)data.data[1];
    return data.response;
}


/* DevOscCApi.h */

int
OSC_GetStatusData(uint32_t uiDevType, COscStatusData *pstOscStatus)
{
    COscStatusData_rsp data;
    CLIENT.OSC_GetStatusData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOscStatusData(*pstOscStatus, data.data);
    return data.response;
}

int
OSC_GetCfgData(uint32_t uiDevType, COscCfgData *pstOscCfg)
{
    COscCfgData_rsp data;
    CLIENT.OSC_GetCfgData(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOscCfgData(*pstOscCfg, data.data);
    return data.response;
}

int
OSC_SetEnable(uint32_t uiDevType, bool bEnable)
{
    return CLIENT.OSC_SetEnable((int32_t)uiDevType, bEnable);
}

int
OSC_SetVoa(uint32_t uiDevType, uint32_t uiTxRx, int16_t sAttn)
{
    return CLIENT.OSC_SetVoa((int32_t)uiDevType, (int32_t)uiTxRx, sAttn);
}

int
OSC_GetVoa(uint32_t uiDevType, uint32_t uiTxRx, int16_t *psAttn)
{
    i16_rsp data;
    CLIENT.OSC_GetVoa(data, (int32_t)uiDevType, (int32_t)uiTxRx);

    CHECK_RSP(data.response);

    *psAttn = data.data;
    return data.response;
}

int
OSC_SetSwitchPos(uint32_t uiDevType, COscSwitchPosSet rstSwitchPos)
{
    COscSwitchPosSet_t data;
    Convert::ToCOscSwitchPosSet_t(data, rstSwitchPos);

    return CLIENT.OSC_SetSwitchPos((int32_t)uiDevType, data);
}

int
OSC_GetSwitchPos(uint32_t uiDevType, COscSwitchPos *pstSwitchPos)
{
    COscSwitchPos_rsp data;
    CLIENT.OSC_GetSwitchPos(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOscSwitchPos(*pstSwitchPos, data.data);
    return data.response;
}


/* DevOtdrCApi.h */

int
OTDR_GetMfg(uint32_t ulDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.OTDR_GetMfg(data, (int32_t)ulDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
OTDR_GetStatusData(uint32_t ulDevIdx, COtdrStatusData *pstStatus)
{
    COtdrStatusData_rsp data;
    CLIENT.OTDR_GetStatusData(data, (int32_t)ulDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCOtdrStatusData(*pstStatus, data.data);
    return data.response;
}

int
OTDR_GetCfgData(uint32_t ulDevIdx, COtdrCfgData *pstCfg)
{
    COtdrCfgData_rsp data;
    CLIENT.OTDR_GetCfgData(data, (int32_t)ulDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCOtdrCfgData(*pstCfg, data.data);
    return data.response;
}

int
OTDR_StartScan(uint32_t ulDevIdx)
{
    return CLIENT.OTDR_StartScan((int32_t)ulDevIdx);
}

int
OTDR_SetPara(uint32_t ulDevIdx, uint32_t ulDistRang, uint32_t ulPulseWidth, double dSamplingResolution)
{
    return CLIENT.OTDR_SetPara((int32_t)ulDevIdx, (int32_t)ulDistRang, (int32_t)ulPulseWidth, dSamplingResolution);
}

int
OTDR_SetMeasuringTime(uint32_t ulDevIdx, uint32_t ulMeasuringTime)
{
    return CLIENT.OTDR_SetMeasuringTime((int32_t)ulDevIdx, (int32_t)ulMeasuringTime);
}

int
OTDR_SetUserIOR(uint32_t ulDevIdx, double dUserIOR)
{
    return CLIENT.OTDR_SetUserIOR((int32_t)ulDevIdx, dUserIOR);
}

int
OTDR_SetThr(uint32_t ulDevIdx, double dRefThr, double dSpliceLosThr, double dFiberEndThr)
{
    return CLIENT.OTDR_SetThr((int32_t)ulDevIdx, dRefThr, dSpliceLosThr, dFiberEndThr);
}

int
OTDR_Reset(uint32_t ulDevIdx, uint8_t ucResetType)
{
    return CLIENT.OTDR_Reset((int32_t)ulDevIdx, (uint8_t)ucResetType);
}

int
OTDR_Upgrade(uint32_t ulDevIdx, const char *c_pcFilePath)
{
    return CLIENT.OTDR_Upgrade((int32_t)ulDevIdx, c_pcFilePath);
}

int
OTDR_GetUpgadeStatus(uint32_t uiDevIdx)
{
    return CLIENT.OTDR_GetUpgadeStatus((int32_t)uiDevIdx);
}

int
OTDR_DbgRead(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen)
{
    binary_rsp data;
    CLIENT.OTDR_DbgRead(data, (int32_t)uiDevIdx, (int32_t)uiLen);

    CHECK_RSP(data.response);

    memcpy(pucBuf, &data.data[0], uiLen);
    return data.response;
}

int
OTDR_DbgWrite(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen)
{
    std::string data((const char *)pucBuf, uiLen);
    return CLIENT.OTDR_DbgWrite((int32_t)uiDevIdx, data, (int32_t)uiLen);
}

int32_t
OTDR_SetScanMode(uint32_t uiDevType, uint32_t ulScanMode)
{
    return CLIENT.OTDR_SetScanMode((int32_t)uiDevType, (int32_t)ulScanMode);
}

int
OTDR_SetStartOffset(uint32_t uiDevType, COtdrStartOffset *pstStartOffset)
{
    COtdrStartOffset_t data;
    Convert::ToCOtdrStartOffset_t(data, *pstStartOffset);

    return CLIENT.OTDR_SetStartOffset((int32_t)uiDevType, data);
}

int
OTDR_GetStartOffset(uint32_t uiDevType, COtdrStartOffset *pstStartOffset)
{
    COtdrStartOffset_rsp data;
    CLIENT.OTDR_GetStartOffset(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    Convert::ToCOtdrStartOffset(*pstStartOffset, data.data);
    return data.response;
}

int32_t
OTDR_StartScanPort(uint32_t ulDevIdx, uint32_t ulPortId)
{
    return CLIENT.OTDR_StartScanPort((int32_t)ulDevIdx, (int32_t)ulPortId);
}


/* DevSlotCApi.h */

int
SLOT_GetDevIdx(uint32_t uiDevType, uint32_t *puiDevIdx, uint32_t *puiDevSubIdx)
{
    i32_list_rsp data;
    CLIENT.SLOT_GetDevIdx(data, (int32_t)uiDevType);

    CHECK_RSP(data.response);

    *puiDevIdx = (uint32_t)data.data[0];
    *puiDevSubIdx = (uint32_t)data.data[1];
    return data.response;
}

int
SLOT_SetOnline(uint32_t uiSlotIdx, bool bOnline)
{
    return CLIENT.SLOT_SetOnline((int32_t)uiSlotIdx, bOnline);
}

int
SLOT_GetSlotNum(uint32_t *puiSlotNum)
{
    i32_rsp data;
    CLIENT.SLOT_GetSlotNum(data);

    CHECK_RSP(data.response);

    *puiSlotNum = (uint32_t)data.data;
    return data.response;
}

int
SLOT_SetMfg(uint32_t uiSlotIdx, const char *c_pcFilePath)
{
    return CLIENT.SLOT_SetMfg((int32_t)uiSlotIdx, c_pcFilePath);
}

int
SLOT_GetMfg(uint32_t uiSlotIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.SLOT_GetMfg(data, (int32_t)uiSlotIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
SLOT_GetStatusData(uint32_t uiSlotIdx, CSlotStatusData *pstStatus)
{
    CSlotStatusData_rsp data;
    CLIENT.SLOT_GetStatusData(data, (int32_t)uiSlotIdx);

    CHECK_RSP(data.response);

    Convert::ToCSlotStatusData(*pstStatus, data.data);
    return data.response;
}

int
SLOT_ClearPlugFlag(uint32_t uiSlotIdx)
{
    return CLIENT.SLOT_ClearPlugFlag((int32_t)uiSlotIdx);
}

int
SLOT_GetInfo(uint32_t uiSlotIdx, CSlotInfo *pstInfo)
{
    CSlotInfo_rsp data;
    CLIENT.SLOT_GetInfo(data, (int32_t)uiSlotIdx);

    CHECK_RSP(data.response);

    Convert::ToCSlotInfo(*pstInfo, data.data);
    return data.response;
}

int
SLOT_GetCali(uint32_t uiSlotIdx, CCali *pstCaliInfo)
{
    CCali_rsp data;
    CLIENT.SLOT_GetCali(data, (int32_t)uiSlotIdx);

    CHECK_RSP(data.response);

    Convert::ToCCali(*pstCaliInfo, data.data);
    return data.response;
}

int
SLOT_SetCali(uint32_t uiSlotIdx, const char *pcFilePath)
{
    return CLIENT.SLOT_SetCali((int32_t)uiSlotIdx, pcFilePath);
}

int
SLOT_Reset(uint32_t uiSlotIdx, uint8_t ucResetType)
{
    return CLIENT.SLOT_Reset((int32_t)uiSlotIdx, (int8_t)ucResetType);
}

int
SLOT_SetLed(uint32_t uiSlotIdx, uint32_t uiLedIdx, uint32_t uiState)
{
    return CLIENT.SLOT_SetLed((int32_t)uiSlotIdx, (int32_t)uiLedIdx, (int32_t)uiState);
}

int
SLOT_ReadEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    binary_rsp data;
    CLIENT.SLOT_ReadEeprom(data, (int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen);

    CHECK_RSP(data.response);

    memcpy(pucVal, &data.data[0], ulLen);
    return data.response;
}

int
SLOT_WriteEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal)
{
    std::string data((const char *)pucVal, ulLen);
    return CLIENT.SLOT_WriteEeprom((int32_t)uiIdx, (int64_t)ulAddr, (int64_t)ulLen, data);
}


/* DevTdcmCApi.h */

int
TDCM_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.TDCM_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
TDCM_GetStatusData(uint32_t uiDevIdx, CTdcmStatusData *pstTdcmStatus)
{
    CTdcmStatusData_rsp data;
    CLIENT.TDCM_GetStatusData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCTdcmStatusData(*pstTdcmStatus, data.data);
    return data.response;
}

int
TDCM_GetCfgData(uint32_t uiDevIdx, CTdcmCfgData *pstTdcmCfg)
{
    CTdcmCfgData_rsp data;
    CLIENT.TDCM_GetCfgData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCTdcmCfgData(*pstTdcmCfg, data.data);
    return data.response;
}

int
TDCM_SetFrequency(uint32_t uiDevIdx, float fFrequency)
{
    return CLIENT.TDCM_SetFrequency((int32_t)uiDevIdx, fFrequency);
}

int
TDCM_SetDispersion(uint32_t uiDevIdx, float fDispersion)
{
    return CLIENT.TDCM_SetDispersion((int32_t)uiDevIdx, fDispersion);
}

int
TDCM_Reset(uint32_t uiDevIdx, uint8_t ucResetType)
{
    return CLIENT.TDCM_Reset((int32_t)uiDevIdx, (int8_t)ucResetType);
}


/* DevWssCApi.h */

int
WSS_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg)
{
    CMfg_rsp data;
    CLIENT.WSS_GetMfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCMfg(*pstMfg, data.data);
    return data.response;
}

int
WSS_GetCfg(uint32_t uiDevIdx, CWssAllCfg *pstAllCfg)
{
    CWssAllCfg_rsp data;
    CLIENT.WSS_GetCfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCWssAllCfg(*pstAllCfg, data.data);
    return data.response;
}

int
WSS_GetOscCfg(uint32_t uiDevIdx, CWssAllCfg *pstCfg)
{
    CWssAllCfg_rsp data;
    CLIENT.WSS_GetOscCfg(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCWssAllCfg(*pstCfg, data.data);
    return data.response;
}

int
WSS_GetStatusData(uint32_t uiDevIdx, CWssStatusData *pstStatus)
{
    CWssStatusData_rsp data;
    CLIENT.WSS_GetStatusData(data, (int32_t)uiDevIdx);

    CHECK_RSP(data.response);

    Convert::ToCWssStatusData(*pstStatus, data.data);
    return data.response;
}

int
WSS_SetAllChCfg(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWssCfg *pstWssCfg)
{
    std::vector<CWssCfg_t> data;
    for (uint32_t i = 0; i < uiChCnt; i++) {
        CWssCfg_t temp;
        Convert::ToCWssCfg_t(temp, *(pstWssCfg + i));
        data.push_back(temp);
    }
    
    return CLIENT.WSS_SetAllChCfg((int32_t)uiDevIdx, (int32_t)uiSubIdx, (int32_t)uiChCnt, data);
}

int
WSS_SetOscChCfg(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWssCfg *pstWssCfg)
{
    std::vector<CWssCfg_t> data;
    for (uint32_t i = 0; i < uiChCnt; i++) {
        CWssCfg_t temp;
        Convert::ToCWssCfg_t(temp, *(pstWssCfg + i));
        data.push_back(temp);
    }
    
    return CLIENT.WSS_SetOscChCfg((int32_t)uiDevIdx, (int32_t)uiSubIdx, (int32_t)uiChCnt, data);
}

int
WSS_SetWaveplan(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWavePlan *pstWavePlan)
{
    std::vector<CWavePlan_t> data;
    for (uint32_t i = 0; i < uiChCnt; i++) {
        CWavePlan_t temp;
        Convert::ToCWavePlan_t(temp, *(pstWavePlan + i));
        data.push_back(temp);
    }
    
    return CLIENT.WSS_SetWaveplan((int32_t)uiDevIdx, (int32_t)uiSubIdx, (int32_t)uiChCnt, data);
}

int
WSS_SetPortPowerThr(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr)
{
    return CLIENT.WSS_SetPortPowerThr((int32_t)uiDevIdx, (int32_t)uiPortIdx, (int32_t)uiType, sThr);
}

int
WSS_SetPortPowerHys(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sHys)
{
    return CLIENT.WSS_SetPortPowerHys((int32_t)uiDevIdx, (int32_t)uiPortIdx, (int32_t)uiType, sHys);
}

int
WSS_GetPortPowerHistory(uint32_t uiDevIdx)
{
    return CLIENT.WSS_GetPortPowerHistory((int32_t)uiDevIdx);
}

int
WSS_SetLedMode(uint32_t uiDevIdx, uint32_t uiMode)
{
    return CLIENT.WSS_SetLedMode((int32_t)uiDevIdx, (int32_t)uiMode);
}

int
WSS_SetLedDebugMode(uint32_t uiDevIdx, uint32_t uiMode)
{
    return CLIENT.WSS_SetLedDebugMode((int32_t)uiDevIdx, (int32_t)uiMode);
}

int
WSS_SetLedStatus(uint32_t uiDevIdx, uint32_t uiLedIdx, uint32_t uiStatus)
{
    return CLIENT.WSS_SetLedStatus((int32_t)uiDevIdx, (int32_t)uiLedIdx, (int32_t)uiStatus);
}

int
WSS_Reset(uint32_t uiDevIdx, uint8_t ucResetType)
{
    return CLIENT.WSS_Reset((int32_t)uiDevIdx, (int8_t)ucResetType);
}

int
WSS_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath)
{
    return CLIENT.WSS_Upgrade((int32_t)uiDevIdx, c_pcFilePath);
}

int
WSS_GetUpgradeStatus(uint32_t uiDevIdx)
{
    return CLIENT.WSS_GetUpgradeStatus((int32_t)uiDevIdx);
}

int
WSS_SetUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen)
{
    std::string data((const char *)pucData, nLen);
    return CLIENT.WSS_SetUserData((int32_t)uiDevIdx, data, (int32_t)nLen);
}

int
WSS_GetUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen)
{
    binary_rsp data;
    CLIENT.WSS_GetUserData(data, (int32_t)uiDevIdx, (int32_t)nLen);

    CHECK_RSP(data.response);

    memcpy(pucData, &data.data[0], nLen);
    return data.response;
}

int
WSS_SetPmUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen)
{
    std::string data((const char *)pucData, nLen);
    return CLIENT.WSS_SetPmUserData((int32_t)uiDevIdx, data, (int32_t)nLen);
}

int
WSS_GetPmUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen)
{
    binary_rsp data;
    CLIENT.WSS_GetPmUserData(data, (int32_t)uiDevIdx, (int32_t)nLen);

    CHECK_RSP(data.response);

    memcpy(pucData, &data.data[0], nLen);
    return data.response;
}


#ifdef __cplusplus
};
#endif