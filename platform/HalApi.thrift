
/* DevData.h */

struct CLedCfg_t {
    1: i32 uiState
}

struct CLedSta_t {
    1: i32 uiState
}

struct CMfg_t {
    1: string acManufacturer,
    2: string acProductName,
    3: string acModuleType,
    4: string acBootVer,
    5: string acSwVer,
    6: string acFwVer,
    7: string acFpgaRunVer,
    8: string acFpga1Ver,
    9: string acFpga2Ver,
    10: string acCpldRunVer,
    11: string acCpld1Ver,
    12: string acCpld2Ver,
    13: string acHwVer,
    14: string acHwFuncRev,
    15: string acPcbRev,
    16: string acSN,
    17: string acPN,
    18: string acMfgDate,
    19: string acCaliDate,
    20: string acCleiCode,
    21: string acSubBdlVer,
    22: string acEepromVer,
    23: string acEth0Mac,
    24: string acEth1Mac,
    25: string acEth2Mac,
    26: string acEth3Mac,
    27: string acEth4Mac,
    28: string acEth5Mac,
    29: string acEth6Mac,
    30: string acEth7Mac,
    31: string acEth8Mac,
    32: string acEth9Mac,
    33: string acUnitName,
    34: string acFCPN,
    35: string acFCIss,
    36: string acFujitsuPN,
    37: string acConfigType,
    38: string acFjtSn,
    39: string acResv
}

struct CCali_t {
    1: i16 sLineInToPaIn,
    2: i16 sLineInToBaIn,
    3: i16 sPaOutToLineOut,
    4: i16 sBaOutToLineOut,
    5: list<i16> asRsv1,
    6: i16 sPaInToOcm,
    7: i16 sPaOutToOcm,
    8: i16 sBaInToOcm,
    9: i16 sBaOutToOcm,
    10: i16 sWss1InToOcm,
    11: i16 sWss1OutToOcm,
    12: i16 sWss2InToOcm,
    13: i16 sWss2OutToOcm,
    14: i16 sLineInToOsc1Drop,
    15: i16 sOsc1AddToLineOut,
    16: i16 sLineInToOsc1Rx,
    17: i16 sOsc1TxToLineOut,
    18: i16 sLineInToOsc2Drop,
    19: i16 sOsc2AddToLineOut,
    20: i16 sLineInToOsc2Rx,
    21: i16 sOsc2TxToLineOut,
    22: i16 sMirrorTxToMuxIn,
    23: i16 sMirrorTxToDemuxIn,
    24: i16 sMuxInToMirrorRx,
    25: i16 sDemuxInToMirrorRx,
    26: i16 sOcmPortToOcm,
    27: list<i16> asRsv4,
    28: list<i16> asExpInToBaIn,
    29: list<i16> asRsv5,
    30: list<i16> asPaOutToExpOut,
    31: list<i16> asRsv6,
    32: list<i16> asRsv7
}


/* DevOscData.h */

struct COscCfgData_t {
    1: i8 ucLaserEnable,
    2: i8 ucSwitch,
    3: i16 sRxThr,
    4: i16 sRxHys,
    5: i16 sTxThr,
    6: i16 sTxHys,
    7: i16 sAddThr,
    8: i16 sAddHys,
    9: i16 sDropThr,
    10: i16 sDropHys
}

struct COscStatusData_t {
    1: i8 ucModStatus,
    2: i16 sRxPower,
    3: i16 sTxPower,
    4: i16 sAddPower,
    5: i16 sDropPower,
    6: bool bFailure,
    7: bool bInnerErr,
    8: bool bOffLine,
    9: bool bRxLos,
    10: bool bTxLos,
    11: bool bAddLos,
    12: bool bDropLos,
    13: bool bLinkDown,
    14: bool bMisMatch,
    15: bool bRxLow,
    16: bool bTxLow,
    17: bool bAddLow,
    18: bool bDropLow,
    19: bool bRxHigh,
    20: bool bTxHigh,
    21: bool bAddHigh,
    22: bool bDropHigh,
    23: bool bLaserSafety
}


/* DevOtdrData.h */

struct COtdrCfgData_t {
    1: i32 ulScanCtrl,
    2: i32 ulScanMode,
    3: i32 ulExpScanTime,
    4: i32 ulExpPulseWidth,
    5: i32 ulScanStartPos,
    6: i32 ulScanEndPos,
    7: double fReflIdx,
    8: double fReflEventThr,
    9: double fNonReflEventThr,
    10: double fFiberEndThr,
    11: double fBackCoef,
    12: double fOrlThr,
    13: double fInputPwrThr,
    14: double fReflEventFhThr,
    15: double fRamanSetpont
}

struct COtdrEventTop_t {
    1: i32 ulCnt,
    2: double dFiberLen,
    3: double dTotalLoss,
    4: double dReturnLoss
}

struct COtdrEventLine_t {
    1: i32 ulEventId,
    2: double dLocation,
    3: double dEventLoss,
    4: double dReflectance,
    5: double dTotalLoss,
    6: i32 enEventType
}

struct COtdrTemp_t {
    1: double fTecTemp,
    2: double fModuleTemp,
    3: double fFpgaTemp
}

struct COtdrStartOffset_t {
    1: i32 uiPositionOffset,
    2: double fLossOffset
}

struct COtdrStartOffsetPort_t {
    1: i32 uiPositionOffset,
    2: list<double> fRev0,
    3: double fLossOffset,
    4: list<double> fRev1
}

struct COtdrStartOffsetAll_t {
    1: list<COtdrStartOffsetPort_t> stOtdrStartOffsetPort,
    2: list<double> fRev,
    3: i32 ulCrc32
}

struct COtdrStatusData_t {
    1: i32 ulScanStatus,
    2: COtdrEventTop_t stEventTop,
    3: list<COtdrEventLine_t> astEventLine,
    4: COtdrTemp_t stTemp,
    5: COtdrStartOffset_t stStartOffset,
    6: binary aucDbgBuf
}


/* DevWssData.h */

struct CWavePlan_t {
    1: i32 uiChId,
    2: i32 uiCenterFreq,
    3: i16 usSliceCount
}

struct CWssCfg_t {
    1: i32 uiId,
    2: i32 uiComPort,
    3: i32 uiExpPort,
    4: i32 uiAtten
}

struct CWssAllCfg_t {
    1: list<CWavePlan_t> astWavePlan,
    2: list<CWssCfg_t> astWssChCfgAdd,
    3: list<CWssCfg_t> astWssChCfgDrop
}

struct CWssPortPowerHistory_t {
    1: list<list<i16>> asPortPower
}

struct CWssCurData_t {
    1: list<i16> asPortPower,
    2: list<i16> asPortPowerOut
}

struct CWssAlarm_t {
    1: list<list<bool>> abPortPower,
    2: list<list<i32>> auiDuration
}

struct CWssStatusData_t {
    1: CWssCurData_t stCurData,
    2: CWssAlarm_t stAlarm
}

struct CPortPowerCfg_t {
    1: list<i16> asPortPowerThrLos,
    2: list<i16> asPortPowerHysLos,
    3: list<i16> asPortPowerThrLow,
    4: list<i16> asPortPowerHysLow,
    5: list<i16> asPortPowerThrHigh,
    6: list<i16> asPortPowerHysHigh
}


/* DevOcmData.h */

struct CWavePlanSlice_t {
    1: i8 ucChId,
    2: i16 usStartSlice,
    3: i16 usEndSlice
}

struct STChannelGrid_t {
    1: i32 uCentralFreq,
    2: i32 uBandwidth
}

struct COcmCfgData_t {
    1: list<list<CWavePlan_t>> aastWavePlan,
    2: list<i32> auiSchdlList
}

struct COcmChPower_t {
    1: list<i16> asPower,
    2: list<i16> asOsnr
}

struct COcmOsa_t {
    1: list<i16> asOsa
}

struct COcmStatusData_t {
    1: binary aucAlm,
    2: binary aucEvent,
    3: i32 iCvPower
}

struct COcmMode_t {
    1: i32 uiPortId,
    2: i32 uiMode
}

struct COcmPortCali_t {
    1: double dRevL,
    2: double dK3L,
    3: double dK2L,
    4: double dK1L,
    5: double dCL,
    6: double dRevN,
    7: double dK3N,
    8: double dK2N,
    9: double dK1N,
    10: double dCN,
    11: double dRevH,
    12: double dK3H,
    13: double dK2H,
    14: double dK1H,
    15: double dCH
}

struct COcmCali_t {
    1: list<COcmPortCali_t> stOcmPortCali,
    2: binary aucRev,
    3: i32 ulCrc32
}


/* DevEdfaData.h */

struct COaCaliData_t {
    1: COtdrStartOffsetAll_t stOtdrCaliInfo,
    2: COcmCali_t stOcmCaliInfo
}

struct COaCfgData_t {
    1: i8 ucMode,
    2: i8 ucGainRange,
    3: i8 ucRflAlmEnable,
    4: i8 ucLosAlmMode,
    5: i8 ucMute,
    6: i8 ucMuteMode,
    7: bool bPumpEnable,
    8: bool bAlsEnable,
    9: bool bSafeEnable,
    10: bool bAprEnable,
    11: i8 ucBandType,
    12: binary aucPortStatus,
    13: i16 sGain,
    14: i16 sApcTarget,
    15: i16 sTilt,
    16: i16 sAprPower,
    17: list<i16> asPumpCurrent,
    18: i16 sInThr,
    19: i16 sInHys,
    20: i16 sOutThr,
    21: i16 sOutHys,
    22: i16 sMsaInThr,
    23: i16 sMsaInHys,
    24: i16 sMsaOutThr,
    25: i16 sMsaOutHys,
    26: i16 sAttn,
    27: COaCaliData_t stCaliData
}

struct COaAlarm_t {
    1: bool bFailure,
    2: bool bDisable,
    3: bool bInnerErr,
    4: bool bInLos,
    5: bool bOutLos,
    6: bool bMsaInLos,
    7: bool bMsaOutLos,
    8: bool bRFL,
    9: bool bOOG,
    10: bool bOOP,
    11: list<bool> abPumpEOL,
    12: list<bool> abPumpTemp,
    13: bool bCaseTemp,
    14: bool bPumpTempHigh,
    15: bool bPumpTempLow,
    16: bool bLimited,
    17: bool bApsd,
    18: bool bInLow,
    19: bool bOutLow,
    20: bool bInHigh,
    21: bool bOutHigh,
    22: bool bFiberTemp,
    23: bool bHeaterTemp,
    24: bool bApr
}

struct CMN_THR_HYS_INFO_ST_t {
    1: i32 iThr,
    2: i32 iHys
}

struct EDFA_LASER_SAFETY_ST_t {
    1: i32 stPinIn,
    2: i32 stPinOut
}

struct COaCurData_t {
    1: bool bIsInService,
    2: i8 ucModeActual,
    3: i16 sInPower,
    4: i16 sOutSigCPower,
    5: i16 sOutSigLPower,
    6: i16 sOutTotalPower,
    7: i16 sPortOutSigCPower,
    8: i16 sPortOutSigLPower,
    9: i16 sPortOutTotalPower,
    10: i16 sMsaInPower,
    11: i16 sMsaOutPower,
    12: i16 sBackRefPower,
    13: i16 sBackRefRatio,
    14: i16 sGainActual,
    15: i16 sTiltActual,
    16: list<i16> asVoaAttnActual,
    17: list<i16> asCaseTemp,
    18: list<i16> asHeaterTemp,
    19: list<i16> asPumpTemp,
    20: list<i32> asPumpCurrent,
    21: list<i16> asExtPdPower,
    22: bool abDfbEnable,
    23: bool abApsdStatus,
    24: bool abApsdEvent,
    25: bool abApsdEnable,
    26: i16 uiOtdrSwitchInEx,
    27: i16 uiOtdrSwitch,
    28: i32 uiDFBPwr,
    29: i16 sDfbInPower2,
    30: i16 sDfbOutPower2,
    31: i16 sDfbInPower1,
    32: i16 sDfbOutPower1,
    33: i16 sLaserSafetyTxPower,
    34: i16 sLaserSafetyRxPower,
    35: EDFA_LASER_SAFETY_ST_t stLaserSafety,
    36: list<list<CMN_THR_HYS_INFO_ST_t>> astThrHys
}

struct COaAnnexData_t {
    1: i32 uiSccUpgSta,
    2: i32 uiTestLedSta,
    3: i32 uiLedAlmSta,
    4: binary aucLedSta,
    5: list<i32> aucAlmMask,
    6: i8 ucShutterSta,
    7: binary reserve
}

struct COaStatusData_t {
    1: COaAlarm_t stOaAlm,
    2: COaCurData_t stOaCurData,
    3: COscStatusData_t stOscCurData,
    4: binary aucDbgBuf,
    5: COaAnnexData_t stOaAnnexData
}

struct COaEventLogData_t {
    1: i32 uiLostTimeCount,
    2: i32 uiLostPD,
    3: i32 uiLinkDownTimeCount,
    4: i32 uiApsdTimeCount
}

struct COaEventLogAllData_t {
    1: list<COaEventLogData_t> stOaEventLogData,
    2: i32 uiBaLostTimeCount,
    3: binary rev
}


/* DevExtendData.h */

struct CExtendCfgData_t {
    1: list<i16> asSwitchPos,
    2: list<i16> asVoaAttn
}

struct CExtendStatusData_t {
    1: list<i16> asPD,
    2: list<i16> asSwitchPosActual,
    3: list<i16> asVoaAttnActual,
    4: binary aucDbgBuf
}

struct CMirrorData_t {
    1: i16 sTxPower,
    2: i16 sMuxInPower,
    3: i16 sDemuxInPower
}


/* DevMuxData.h */

struct CMuxCfgData_t {

}

struct CMuxStatusData_t {
    1: list<i16> asPdPower
}

struct CMuxCaliData_t {
    1: double dRefMuxTCali,
    2: double dRefDemuxRCali
}


/* DevOpsData.h */

struct COpsLedChannel_t {
    1: i8 ucW,
    2: i8 ucP,
    3: i8 ucMux,
    4: i8 ucWP
}

struct COpsLedAll_t {
    1: i8 ucAct,
    2: i8 ucAlm,
    3: list<COpsLedChannel_t> stOpsLedChannel
}

union COpsLed_t {
    1: binary aucStatus,
    2: COpsLedAll_t stOpsLedAll
}

struct COpsCurData_t {
    1: i8 ucWorkMode,
    2: i8 ucSwitchPos,
    3: i8 ucFswStatus,
    4: i8 ucSwitchingType,
    5: list<i16> asPortPower,
    6: i16 sTxPower,
    7: bool bFailure,
    8: bool bInnerErr,
    9: bool bOffLine
}

struct COpsAlarm_t {
    1: binary aaucPortAlarm,
    2: i8 ucSwitchFailed,
    3: i8 ucRelative,
    4: list<bool> abSwitchAlarm,
    5: i8 ucMfgFailed,
    6: i8 ucComInLoss,
    7: i8 ucPowerDiffer,
    8: list<list<i32>> auiDuration
}

struct COpsHistoryUnitData_t {
    1: i32 uiHour,
    2: i32 uiMinute,
    3: i32 uiSecond,
    4: i32 uiMillisecond,
    5: list<list<i16>> asPortPowerHistory
}

struct COpsHistoryData_t {
    1: i32 uiSwitchTimes,
    2: list<COpsHistoryUnitData_t> astOpsHisUnitData
}

struct COscPd_t {
    1: list<i16> asPd
}

struct COscSwitchPos_t {
    1: i32 uiOut,
    2: i32 uiIn
}

struct COscSwitchPosSet_t {
    1: i32 uiSwitchIdx,
    2: i32 uiPos
}

struct COpsVoltage_t {
    1: list<i16> asVoltage
}

struct COpsIL_t {
    1: list<i16> asInsertionLoss
}

struct COpsUpgStat_t {
    1: i16 sStatus
}

struct COpsConnectionPd_t {
    1: list<i16> asPd
}

struct COpsPdAdc_t {
    1: list<i32> asPdAdc
}

struct COpsConnectionPdThr_t {
    1: list<i16> asPdThr
}

struct COpsConnectionPdHys_t {
    1: list<i16> asPdHys
}

struct COpsReqStatus_t {
    1: i8 ucProtTypeR,
    2: i8 ucProtTypeD,
    3: i8 ucProtTypeB,
    4: i8 ucProtTypeA,
    5: i8 ucApsState,
    6: i8 ucRequestedSignal,
    7: i8 ucBridgedSignal,
    8: i8 ucReserved
}

struct COpsBidirectionStatus_t {
    1: i8 ucLocalWorkMode,
    2: i8 ucLocalPosition,
    3: i8 ucLocalStatus,
    4: COpsReqStatus_t stRemoteStatus
}

struct COpsAlmMask_t {
    1: i8 Line1InLossAlarm,
    2: i8 Line2InLossAlarm,
    3: i8 SwitchFailedAlarm,
    4: i8 LutAlarm,
    5: i8 RelativeAlarmbetweenLine1andLine2,
    6: i8 PDVoltageAlarm,
    7: i8 ComInLossAlarm,
    8: i8 ReceivePowerDifferBetween
}

struct COpsCommStatusData_t {
    1: COpsAlarm_t stAlarm,
    2: COpsLed_t stLed,
    3: COpsVoltage_t stVoltage,
    4: COpsAlmMask_t stAlmMask
}

struct COpsStatusData_t {
    1: COpsCurData_t stCurData,
    2: CWssStatusData_t stWssStaData,
    3: COscPd_t stOscPd,
    4: COpsIL_t stIl,
    5: COpsConnectionPd_t stConnectionPds,
    6: COpsBidirectionStatus_t stBidiStatus
}

struct COpsSwitchThr_t {
    1: list<i16> asThr
}

struct COpsSwitchHys_t {
    1: list<i16> asHys
}

struct CPortPowerThr_t {
    1: list<list<i16>> asThr,
    2: i16 sDifferBetweenLine1Line2
}

struct CPortPowerHys_t {
    1: list<list<i16>> asHys
}

struct CWssPortPowerThr_t {
    1: list<list<i16>> asThr
}

struct CWssPortPowerHys_t {
    1: list<list<i16>> asHys
}

struct CRelativeThr_t {
    1: i16 sThr
}

struct CRelativeOffset_t {
    1: i16 sOffset
}

struct COpsCfgData_t {
    1: i8 ucWorkMode,
    2: i16 usRelativeEnable,
    3: i16 usHoldTime,
    4: i16 usRelativeSwitchThr,
    5: i16 sRelativeOffset,
    6: i32 uiWtrTime,
    7: i32 uiHour,
    8: i32 uiMinute,
    9: i32 uiSecond,
    10: CPortPowerThr_t stPortPowerThr,
    11: CPortPowerHys_t stPortPowerHys,
    12: CWssPortPowerThr_t stWssPortPowerThr,
    13: CWssPortPowerHys_t stWssPortPowerHys,
    14: COpsSwitchThr_t stSwitchThr,
    15: COpsSwitchHys_t stSwitchHys,
    16: COpsConnectionPdThr_t stConnectionPdThr,
    17: COpsConnectionPdHys_t stConnectionPdHys
}

struct COpsEventLogData_t {
    1: i32 uiSwitchOffsetTime,
    2: i32 uiAlarmOffsetTime,
    3: i16 sAlarmWPower,
    4: i16 sAlarmPPower,
    5: i32 uiSwitchState
}

struct COpsEventLogAllData_t {
    1: list<COpsEventLogData_t> stOpsEventLogData,
    2: binary rev
}


/* DevCvData.h */

struct CCvMuxStatusData_t {
    1: i16 sOutputPowerR,
    2: i16 sInputPowerR,
    3: i16 sOutputPowerT,
    4: i16 sInputPowerT
}

struct CCvClientStatusData_t {
    1: i16 sOutputPowerR,
    2: i16 sInputPowerR,
    3: i16 sOutputPowerT,
    4: i16 sInputPowerT
}

struct CCvRef_t {
    1: i16 sOutputPower,
    2: i16 sRefPower
}


/* DevOcsData.h */

struct COcsConnection_t {
    1: i8 ucId,
    2: i8 ucSource,
    3: i8 ucDestination,
    4: i8 ucReserve
}

struct COcsConnections_t {
    1: i32 uiCount,
    2: list<COcsConnection_t> astConn
}

struct COcsAlarm_t {
    1: list<bool> abAlarms,
    2: binary aucReserve
}

struct COcsLedSta_t {
    1: binary aucLedSta,
    2: i8 ucLedWorkSta,
    3: binary aucReserve
}

struct COcsTempSta_t {
    1: i16 sCaseTemp,
    2: binary aucReserve
}

struct COcsStatusData_t {
    1: COcsAlarm_t stAlm,
    2: COcsConnections_t stConnsSta,
    3: COcsLedSta_t stLedSta,
    4: COcsTempSta_t stTempSta
}

struct COcsCfgData_t {
    1: COcsConnections_t stConns
}


/* DevSlotData.h */

struct CSlotDevInfo_t {
    1: i32 uiDevType,
    2: i32 uiDevIdx,
    3: i32 uiSubType,
    4: i32 uiFuncType,
    5: bool bOnBoard
}

struct CSlotInfo_t {
    1: i32 uiCardType,
    2: i32 uiSlotState,
    3: i32 uiPlugFlag,
    4: i32 uiResetType,
    5: i32 uiDevNum,
    6: list<CSlotDevInfo_t> astDevInfo
}

struct CSlotStatusData_t {
    1: i32 iTemp,
    2: list<CLedSta_t> astLed,
    3: bool bEEpromAlarm
}


/* DevBoardData.h */

struct CFanCfg_t {
    1: i32 uiDuty
}

struct CFanSta_t {
    1: bool bIsOnline,
    2: bool bIsFailure,
    3: i32 uiSpeed,
    4: i32 uiLedState
}

struct CPowerCfg_t {

}

struct CPowerSta_t {
    1: bool bIsOnline,
    2: bool bIsFailure,
    3: i16 usInVol,
    4: i16 usOutVol,
    5: i32 uiInCurrent,
    6: i32 uiOutCurrent,
    7: i32 uiWatts,
    8: i32 iTemp
}

struct CBoardMfg_t {
    1: CMfg_t stChassis,
    2: bool bChassisMfgOk,
    3: CMfg_t stScc,
    4: bool bSccMfgOk,
    5: list<CMfg_t> astFan,
    6: list<bool> abFanMfgOk,
    7: list<CMfg_t> astPower,
    8: list<bool> abPowerMfgOk
}

struct CBoardCfgData_t {
    1: list<CLedCfg_t> astLed,
    2: list<CFanCfg_t> astFan,
    3: list<CPowerCfg_t> astPower
}

struct CBoardCali_t {
    1: CCali_t stChassis
}

struct CLtc4215Sta_t {
    1: i32 iSense,
    2: i32 iSource
}

struct CMax1139Sta_t {
    1: list<double> adVoltage
}

struct CMp5023Sta_t {
    1: double dVIn,
    2: double dVOut,
    3: double dIOut
}

struct CBoardStatusData_t {
    1: list<CFanSta_t> astFan,
    2: list<CPowerSta_t> astPower,
    3: list<CLedSta_t> astLed,
    4: list<bool> abApsdStatus,
    5: list<bool> abApsdEvent,
    6: list<bool> abApsdEnable,
    7: binary aucResetType,
    8: list<i32> aiTemp,
    9: list<i32> aiPortPower,
    10: list<CLtc4215Sta_t> astLtc4215,
    11: list<CMp5023Sta_t> astMp5023,
    12: list<CMax1139Sta_t> astMax1139
}

struct CBoardRealTimeData_t {
    1: binary aucLogicVal,
    2: binary aucUpgInfo,
    3: binary aucBdlHead
}


/* DevTdcmData.h */

struct CTdcmStatusData_t {
    1: double fFrequency,
    2: double fDispersion
}

struct CTdcmCfgData_t {

}


/* Struct response define */

struct CLedCfg_rsp {
    1: i32 response,
    2: CLedCfg_t data
}

struct CLedSta_rsp {
    1: i32 response,
    2: CLedSta_t data
}

struct CMfg_rsp {
    1: i32 response,
    2: CMfg_t data
}

struct CCali_rsp {
    1: i32 response,
    2: CCali_t data
}

struct COscCfgData_rsp {
    1: i32 response,
    2: COscCfgData_t data
}

struct COscStatusData_rsp {
    1: i32 response,
    2: COscStatusData_t data
}

struct COtdrCfgData_rsp {
    1: i32 response,
    2: COtdrCfgData_t data
}

struct COtdrEventTop_rsp {
    1: i32 response,
    2: COtdrEventTop_t data
}

struct COtdrEventLine_rsp {
    1: i32 response,
    2: COtdrEventLine_t data
}

struct COtdrTemp_rsp {
    1: i32 response,
    2: COtdrTemp_t data
}

struct COtdrStartOffset_rsp {
    1: i32 response,
    2: COtdrStartOffset_t data
}

struct COtdrStartOffsetPort_rsp {
    1: i32 response,
    2: COtdrStartOffsetPort_t data
}

struct COtdrStartOffsetAll_rsp {
    1: i32 response,
    2: COtdrStartOffsetAll_t data
}

struct COtdrStatusData_rsp {
    1: i32 response,
    2: COtdrStatusData_t data
}

struct CWavePlan_rsp {
    1: i32 response,
    2: CWavePlan_t data
}

struct CWssCfg_rsp {
    1: i32 response,
    2: CWssCfg_t data
}

struct CWssAllCfg_rsp {
    1: i32 response,
    2: CWssAllCfg_t data
}

struct CWssPortPowerHistory_rsp {
    1: i32 response,
    2: CWssPortPowerHistory_t data
}

struct CWssCurData_rsp {
    1: i32 response,
    2: CWssCurData_t data
}

struct CWssAlarm_rsp {
    1: i32 response,
    2: CWssAlarm_t data
}

struct CWssStatusData_rsp {
    1: i32 response,
    2: CWssStatusData_t data
}

struct CPortPowerCfg_rsp {
    1: i32 response,
    2: CPortPowerCfg_t data
}

struct CWavePlanSlice_rsp {
    1: i32 response,
    2: CWavePlanSlice_t data
}

struct STChannelGrid_rsp {
    1: i32 response,
    2: STChannelGrid_t data
}

struct COcmCfgData_rsp {
    1: i32 response,
    2: COcmCfgData_t data
}

struct COcmChPower_rsp {
    1: i32 response,
    2: COcmChPower_t data
}

struct COcmOsa_rsp {
    1: i32 response,
    2: COcmOsa_t data
}

struct COcmStatusData_rsp {
    1: i32 response,
    2: COcmStatusData_t data
}

struct COcmMode_rsp {
    1: i32 response,
    2: COcmMode_t data
}

struct COcmPortCali_rsp {
    1: i32 response,
    2: COcmPortCali_t data
}

struct COcmCali_rsp {
    1: i32 response,
    2: COcmCali_t data
}

struct COaCaliData_rsp {
    1: i32 response,
    2: COaCaliData_t data
}

struct COaCfgData_rsp {
    1: i32 response,
    2: COaCfgData_t data
}

struct COaAlarm_rsp {
    1: i32 response,
    2: COaAlarm_t data
}

struct CMN_THR_HYS_INFO_ST_rsp {
    1: i32 response,
    2: CMN_THR_HYS_INFO_ST_t data
}

struct EDFA_LASER_SAFETY_ST_rsp {
    1: i32 response,
    2: EDFA_LASER_SAFETY_ST_t data
}

struct COaCurData_rsp {
    1: i32 response,
    2: COaCurData_t data
}

struct COaAnnexData_rsp {
    1: i32 response,
    2: COaAnnexData_t data
}

struct COaStatusData_rsp {
    1: i32 response,
    2: COaStatusData_t data
}

struct COaEventLogData_rsp {
    1: i32 response,
    2: COaEventLogData_t data
}

struct COaEventLogAllData_rsp {
    1: i32 response,
    2: COaEventLogAllData_t data
}

struct CExtendCfgData_rsp {
    1: i32 response,
    2: CExtendCfgData_t data
}

struct CExtendStatusData_rsp {
    1: i32 response,
    2: CExtendStatusData_t data
}

struct CMirrorData_rsp {
    1: i32 response,
    2: CMirrorData_t data
}

struct CMuxCfgData_rsp {
    1: i32 response,
    2: CMuxCfgData_t data
}

struct CMuxStatusData_rsp {
    1: i32 response,
    2: CMuxStatusData_t data
}

struct CMuxCaliData_rsp {
    1: i32 response,
    2: CMuxCaliData_t data
}

struct COpsLedChannel_rsp {
    1: i32 response,
    2: COpsLedChannel_t data
}

struct COpsLedAll_rsp {
    1: i32 response,
    2: COpsLedAll_t data
}

struct COpsLed_rsp {
    1: i32 response,
    2: COpsLed_t data
}

struct COpsCurData_rsp {
    1: i32 response,
    2: COpsCurData_t data
}

struct COpsAlarm_rsp {
    1: i32 response,
    2: COpsAlarm_t data
}

struct COpsHistoryUnitData_rsp {
    1: i32 response,
    2: COpsHistoryUnitData_t data
}

struct COpsHistoryData_rsp {
    1: i32 response,
    2: COpsHistoryData_t data
}

struct COscPd_rsp {
    1: i32 response,
    2: COscPd_t data
}

struct COscSwitchPos_rsp {
    1: i32 response,
    2: COscSwitchPos_t data
}

struct COscSwitchPosSet_rsp {
    1: i32 response,
    2: COscSwitchPosSet_t data
}

struct COpsVoltage_rsp {
    1: i32 response,
    2: COpsVoltage_t data
}

struct COpsIL_rsp {
    1: i32 response,
    2: COpsIL_t data
}

struct COpsUpgStat_rsp {
    1: i32 response,
    2: COpsUpgStat_t data
}

struct COpsConnectionPd_rsp {
    1: i32 response,
    2: COpsConnectionPd_t data
}

struct COpsPdAdc_rsp {
    1: i32 response,
    2: COpsPdAdc_t data
}

struct COpsConnectionPdThr_rsp {
    1: i32 response,
    2: COpsConnectionPdThr_t data
}

struct COpsConnectionPdHys_rsp {
    1: i32 response,
    2: COpsConnectionPdHys_t data
}

struct COpsReqStatus_rsp {
    1: i32 response,
    2: COpsReqStatus_t data
}

struct COpsBidirectionStatus_rsp {
    1: i32 response,
    2: COpsBidirectionStatus_t data
}

struct COpsAlmMask_rsp {
    1: i32 response,
    2: COpsAlmMask_t data
}

struct COpsCommStatusData_rsp {
    1: i32 response,
    2: COpsCommStatusData_t data
}

struct COpsStatusData_rsp {
    1: i32 response,
    2: COpsStatusData_t data
}

struct COpsSwitchThr_rsp {
    1: i32 response,
    2: COpsSwitchThr_t data
}

struct COpsSwitchHys_rsp {
    1: i32 response,
    2: COpsSwitchHys_t data
}

struct CPortPowerThr_rsp {
    1: i32 response,
    2: CPortPowerThr_t data
}

struct CPortPowerHys_rsp {
    1: i32 response,
    2: CPortPowerHys_t data
}

struct CWssPortPowerThr_rsp {
    1: i32 response,
    2: CWssPortPowerThr_t data
}

struct CWssPortPowerHys_rsp {
    1: i32 response,
    2: CWssPortPowerHys_t data
}

struct CRelativeThr_rsp {
    1: i32 response,
    2: CRelativeThr_t data
}

struct CRelativeOffset_rsp {
    1: i32 response,
    2: CRelativeOffset_t data
}

struct COpsCfgData_rsp {
    1: i32 response,
    2: COpsCfgData_t data
}

struct COpsEventLogData_rsp {
    1: i32 response,
    2: COpsEventLogData_t data
}

struct COpsEventLogAllData_rsp {
    1: i32 response,
    2: COpsEventLogAllData_t data
}

struct CCvMuxStatusData_rsp {
    1: i32 response,
    2: CCvMuxStatusData_t data
}

struct CCvClientStatusData_rsp {
    1: i32 response,
    2: CCvClientStatusData_t data
}

struct CCvRef_rsp {
    1: i32 response,
    2: CCvRef_t data
}

struct COcsConnection_rsp {
    1: i32 response,
    2: COcsConnection_t data
}

struct COcsConnections_rsp {
    1: i32 response,
    2: COcsConnections_t data
}

struct COcsAlarm_rsp {
    1: i32 response,
    2: COcsAlarm_t data
}

struct COcsLedSta_rsp {
    1: i32 response,
    2: COcsLedSta_t data
}

struct COcsTempSta_rsp {
    1: i32 response,
    2: COcsTempSta_t data
}

struct COcsStatusData_rsp {
    1: i32 response,
    2: COcsStatusData_t data
}

struct COcsCfgData_rsp {
    1: i32 response,
    2: COcsCfgData_t data
}

struct CSlotDevInfo_rsp {
    1: i32 response,
    2: CSlotDevInfo_t data
}

struct CSlotInfo_rsp {
    1: i32 response,
    2: CSlotInfo_t data
}

struct CSlotStatusData_rsp {
    1: i32 response,
    2: CSlotStatusData_t data
}

struct CFanCfg_rsp {
    1: i32 response,
    2: CFanCfg_t data
}

struct CFanSta_rsp {
    1: i32 response,
    2: CFanSta_t data
}

struct CPowerCfg_rsp {
    1: i32 response,
    2: CPowerCfg_t data
}

struct CPowerSta_rsp {
    1: i32 response,
    2: CPowerSta_t data
}

struct CBoardMfg_rsp {
    1: i32 response,
    2: CBoardMfg_t data
}

struct CBoardCfgData_rsp {
    1: i32 response,
    2: CBoardCfgData_t data
}

struct CBoardCali_rsp {
    1: i32 response,
    2: CBoardCali_t data
}

struct CLtc4215Sta_rsp {
    1: i32 response,
    2: CLtc4215Sta_t data
}

struct CMax1139Sta_rsp {
    1: i32 response,
    2: CMax1139Sta_t data
}

struct CMp5023Sta_rsp {
    1: i32 response,
    2: CMp5023Sta_t data
}

struct CBoardStatusData_rsp {
    1: i32 response,
    2: CBoardStatusData_t data
}

struct CBoardRealTimeData_rsp {
    1: i32 response,
    2: CBoardRealTimeData_t data
}

struct CTdcmStatusData_rsp {
    1: i32 response,
    2: CTdcmStatusData_t data
}

struct CTdcmCfgData_rsp {
    1: i32 response,
    2: CTdcmCfgData_t data
}


/* Basic types response define */

struct bool_rsp {
    1: i32 response,
    2: bool data
}

struct bool_list_rsp {
    1: i32 response,
    2: list<bool> data
}

struct i8_rsp {
    1: i32 response,
    2: i8 data
}

struct i8_list_rsp {
    1: i32 response,
    2: binary data
}

struct i16_rsp {
    1: i32 response,
    2: i16 data
}

struct i16_list_rsp {
    1: i32 response,
    2: list<i16> data
}

struct i32_rsp {
    1: i32 response,
    2: i32 data
}

struct i32_list_rsp {
    1: i32 response,
    2: list<i32> data
}

struct i64_rsp {
    1: i32 response,
    2: i64 data
}

struct i64_list_rsp {
    1: i32 response,
    2: list<i64> data
}

struct double_rsp {
    1: i32 response,
    2: double data
}

struct double_list_rsp {
    1: i32 response,
    2: list<double> data
}

struct string_rsp {
    1: i32 response,
    2: string data
}

struct string_list_rsp {
    1: i32 response,
    2: list<string> data
}

struct binary_rsp {
    1: i32 response,
    2: binary data
}

/* service define */

service HalApi {

    /* DevBoardCApi.h */

    //int BOARD_GetChassisMfg(CMfg *pstMfg);
    CMfg_rsp BOARD_GetChassisMfg(),

    //int BOARD_SetChassisMfg(const char *pcFilePath);
    i32 BOARD_SetChassisMfg(1:string pcFilePath),

    //int BOARD_SetChassisConfigType(const char *pcConfigType);
    i32 BOARD_SetChassisConfigType(1:string pcConfigType),

    //int BOARD_GetChassisCali(CCali *pstCali);
    CCali_rsp BOARD_GetChassisCali(),

    //int BOARD_SetChassisCali(const char *pcFilePath);
    i32 BOARD_SetChassisCali(1:string pcFilePath),

    //int BOARD_GetChassisCfg(uint32_t uiAddrSlice, const char *pcFilePath);
    i32 BOARD_GetChassisCfg(1:i32 uiAddrSlice, 2:string pcFilePath),

    //int BOARD_SetChassisCfg(uint32_t uiAddrSlice, uint32_t uiSize, const char *pcFilePath);
    i32 BOARD_SetChassisCfg(1:i32 uiAddrSlice, 2:i32 uiSize, 3:string pcFilePath),

    //int BOARD_GetUpgInfo(uint8_t *pucBuf, uint32_t ulLen);
    binary_rsp BOARD_GetUpgInfo(1:i32 ulLen),

    //int BOARD_SetUpgInfo(uint8_t *pucBuf, uint32_t ulLen);
    i32 BOARD_SetUpgInfo(1:binary pucBuf, 2:i32 ulLen),

    //int BOARD_GetBdlHead(uint8_t *pucBuf, uint32_t ulLen);
    binary_rsp BOARD_GetBdlHead(1:i32 ulLen),

    //int BOARD_SetBdlHead(uint8_t *pucBuf, uint32_t ulLen);
    i32 BOARD_SetBdlHead(1:binary pucBuf, 2:i32 ulLen),

    //int BOARD_GetStatusData(CBoardStatusData *pstBoardStatus);
    CBoardStatusData_rsp BOARD_GetStatusData(),

    //int BOARD_GetSccMfg(CMfg *pstMfg);
    CMfg_rsp BOARD_GetSccMfg(),

    //int BOARD_SetSccMfg(const char *pcFilePath);
    i32 BOARD_SetSccMfg(1:string pcFilePath),

    //int BOARD_SetResetType(uint8_t ucResetType);
    i32 BOARD_SetResetType(1:i8 ucResetType),

    //int BOARD_GetResetType(int iIndex, uint8_t *pucResetType);
    i8_rsp BOARD_GetResetType(1:i32 iIndex),

    //int BOARD_CfgWatchDogTime(bool bEnable, uint8_t ucTimeout);
    i32 BOARD_CfgWatchDogTime(1:bool bEnable, 2:i8 ucTimeout),

    //int BOARD_GetApsdStatus(int iIndex, bool *pbCfg, bool *pbStatus, bool *pbEvent);
    bool_list_rsp BOARD_GetApsdStatus(1:i32 iIndex),

    //int BOARD_SetLedState(uint32_t uiDevIdx, uint32_t uiState);
    i32 BOARD_SetLedState(1:i32 uiDevIdx, 2:i32 uiState),

    //int BOARD_ResetLogic(uint32_t uiDevIdx, uint8_t ucResetType);
    i32 BOARD_ResetLogic(1:i32 uiDevIdx, 2:i8 ucResetType),

    //int BOARD_UpgradeLogic(uint32_t uiDevIdx, const char *c_pcFilePath);
    i32 BOARD_UpgradeLogic(1:i32 uiDevIdx, 2:string c_pcFilePath),

    //int BOARD_GetUpgadeStatus();
    i32 BOARD_GetUpgadeStatus(),

    //int FAN_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp FAN_GetMfg(1:i32 uiDevIdx),

    //int FAN_SetMfg(uint32_t uiDevIdx, const char *pcFilePath);
    i32 FAN_SetMfg(1:i32 uiDevIdx, 2:string pcFilePath),

    //int FAN_SetSpeed(uint32_t uiDevIdx, uint32_t uiDuty);
    i32 FAN_SetSpeed(1:i32 uiDevIdx, 2:i32 uiDuty),

    //int FAN_SetControllerEEP(uint32_t uiDevIdx);
    i32 FAN_SetControllerEEP(1:i32 uiDevIdx),

    //int FAN_SetLed(uint32_t uiDevIdx, uint32_t uiValue);
    i32 FAN_SetLed(1:i32 uiDevIdx, 2:i32 uiValue),

    //int POWER_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp POWER_GetMfg(1:i32 uiDevIdx),

    //char *BOARD_GetProductName(char *pcBuf, size_t nSize);
    string_rsp BOARD_GetProductName(1:i32 nSize),

    //char *BOARD_GetConfigType(char *pcBuf, size_t nSize);
    string_rsp BOARD_GetConfigType(1:i32 nSize),

    //PRODUCT_TYPE_EN BOARD_GetProductType();
    i32 BOARD_GetProductType(),

    //int BOARD_SetLogLevel(uint32_t uiLogLevel);
    i32 BOARD_SetLogLevel(1:i32 uiLogLevel),

    //int BOARD_ConvertDevType(const char *pcName, uint32_t *puiDevType);
    i32_rsp BOARD_ConvertDevType(1:string pcName),

    /* DevCvCApi.h */

    //int Cv_GetMuxStatusData(EnCvLine enCvLine, CCvMuxStatusData *pstMuxStatus);
    CCvMuxStatusData_rsp Cv_GetMuxStatusData(1:i32 enCvLine),

    //int Cv_GetClientStatusData(EnCvLine enCvLine, CCvClientStatusData *pstClientStatus);
    CCvClientStatusData_rsp Cv_GetClientStatusData(1:i32 enCvLine),

    //int Cv_GetRef(CCvRef *pstRef);
    CCvRef_rsp Cv_GetRef(),


    /* DevDbgCApi.h */

    //int DBG_ReadLogicReg(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    binary_rsp DBG_ReadLogicReg(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen),

    //int DBG_WriteLogicReg(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    i32 DBG_WriteLogicReg(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen, 4:binary pucVal),

    //int DBG_ReadLogicRegSlc(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    binary_rsp DBG_ReadLogicRegSlc(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen),

    //int DBG_WriteLogicRegSlc(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    i32 DBG_WriteLogicRegSlc(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen, 4:binary pucVal),

    //int DBG_LoopEnable(bool bEnable);
    i32 DBG_LoopEnable(1:bool bEnable),

    //int DBG_LoopInterval(uint32_t uiInterval);
    i32 DBG_LoopInterval(1:i32 uiInterval),

    //int DBG_IdleEnable(bool bEnable);
    i32 DBG_IdleEnable(1:bool bEnable),

    //int DBG_ApsdEnable(int iIndex, bool bEnable);
    i32 DBG_ApsdEnable(1:i32 iIndex, 2:bool bEnable),

    //int DBG_GetAprStatus(uint32_t uiIndex, uint8_t *pucVal);
    i8_rsp DBG_GetAprStatus(1:i32 uiIndex),

    //int DBG_SpiSendCommand(uint32_t ulChip, uint8_t *pucBufW, uint8_t *pucBufR, uint32_t ulLen);
    binary_rsp DBG_SpiSendCommand(1:i32 ulChip, 2:binary pucBufW, 4:i32 ulLen),

    //int DBG_SpiFlashRead(uint64_t ulChip, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    binary_rsp DBG_SpiFlashRead(1:i64 ulChip, 2:i64 ulAddr, 3:i64 ulLen),

    //int DBG_SpiFlashWrite(uint64_t ulChip, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    i32 DBG_SpiFlashWrite(1:i64 ulChip, 2:i64 ulAddr, 3:i64 ulLen, 4:binary pucVal),

    //int DBG_MdioRead(uint32_t uiIdx, uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData);
    i16_rsp DBG_MdioRead(1:i32 uiIdx, 2:i32 ulPhyAddr, 3:i32 ulRegAddr),

    //int DBG_MdioWrite(uint32_t uiIdx, uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData);
    i32 DBG_MdioWrite(1:i32 uiIdx, 2:i32 ulPhyAddr, 3:i32 ulRegAddr, 4:i16 usData),

    //int DBG_NetSwitchRead(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData);
    i16_rsp DBG_NetSwitchRead(1:i32 ulPhyAddr, 2:i32 ulRegAddr),

    //int DBG_NetSwitchWrite(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData);
    i32 DBG_NetSwitchWrite(1:i32 ulPhyAddr, 2:i32 ulRegAddr, 3:i16 usData),

    //int DBG_SwitchPhyRead(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t *pusData);
    i16_rsp DBG_SwitchPhyRead(1:i32 ulPhyAddr, 2:i32 ulRegAddr),

    //int DBG_SwitchPhyWrite(uint32_t ulPhyAddr, uint32_t ulRegAddr, uint16_t usData);
    i32 DBG_SwitchPhyWrite(1:i32 ulPhyAddr, 2:i32 ulRegAddr, 3:i16 usData),

    //int DBG_ReadEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    binary_rsp DBG_ReadEeprom(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen),

    //int DBG_WriteEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    i32 DBG_WriteEeprom(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen, 4:binary pucVal),


    /* DevEdfaCApi.h */

    //int EDFA_GetMfg(uint32_t uiDevType, CMfg *pstMfg);
    CMfg_rsp EDFA_GetMfg(1:i32 uiDevType),

    //int EDFA_GetStatusData(uint32_t uiDevType, COaStatusData *pstEdfaStatus);
    COaStatusData_rsp EDFA_GetStatusData(1:i32 uiDevType),

    //int EDFA_GetCfgData(uint32_t uiDevType, COaCfgData *pstEdfaCfg);
    COaCfgData_rsp EDFA_GetCfgData(1:i32 uiDevType),

    //int EDFA_GetDebugInfo(uint32_t uiDevType, const char *pcFilePath);
    i32 EDFA_GetDebugInfo(1:i32 uiDevType, 2:string pcFilePath),

    //int EDFA_GetMcuDebugInfo(uint32_t uiDevType, const char *pcFilePath);
    i32 EDFA_GetMcuDebugInfo(1:i32 uiDevType, 2:string pcFilePath),

    //int EDFA_SetGainRange(uint32_t uiDevType, int16_t sGainRange);
    i32 EDFA_SetGainRange(1:i32 uiDevType, 2:i16 sGainRange),

    //int EDFA_SetGain(uint32_t uiDevType, int16_t sGain);
    i32 EDFA_SetGain(1:i32 uiDevType, 2:i16 sGain),

    //int EDFA_SetTilt(uint32_t uiDevType, int16_t sTilt);
    i32 EDFA_SetTilt(1:i32 uiDevType, 2:i16 sTilt),

    //int EDFA_SetMode(uint32_t uiDevType, uint8_t ucMode, int16_t sVal);
    i32 EDFA_SetMode(1:i32 uiDevType, 2:i8 ucMode, 3:i16 sVal),

    //int EDFA_SetPumpEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetPumpEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetAprEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetAprEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetAutolosEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetAutolosEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetRxLosThr(uint32_t uiDevType, int16_t sThr, int16_t sHys);
    i32 EDFA_SetRxLosThr(1:i32 uiDevType, 2:i16 sThr, 3:i16 sHys),

    //int EDFA_SetAttn(uint32_t uiDevType, int16_t sAttn);
    i32 EDFA_SetAttn(1:i32 uiDevType, 2:i16 sAttn),

    //int EDFA_GetAttn(uint32_t uiDevType, int16_t *psAttn);
    i16_rsp EDFA_GetAttn(1:i32 uiDevType),

    //int EDFA_Reset(uint32_t uiDevType, uint8_t ucResetType);
    i32 EDFA_Reset(1:i32 uiDevType, 2:i8 ucResetType),

    //int EDFA_Upgrade(uint32_t uiDevType, const char *c_pcFilePath);
    i32 EDFA_Upgrade(1:i32 uiDevType, 2:string c_pcFilePath),

    //int EDFA_Swap(uint32_t uiDevType);
    i32 EDFA_Swap(1:i32 uiDevType),

    //int EDFA_Commit(uint32_t uiDevType);
    i32 EDFA_Commit(1:i32 uiDevType),

    //int EDFA_GetUpgadeStatus(uint32_t uiDevType);
    i32 EDFA_GetUpgadeStatus(1:i32 uiDevType),

    //int EDFA_DbgRead(uint32_t uiDevType, uint8_t *pucBuf, uint32_t uiLen);
    binary_rsp EDFA_DbgRead(1:i32 uiDevType, 2:i32 uiLen),

    //int EDFA_DbgWrite(uint32_t uiDevType, uint8_t *pucBuf, uint32_t uiLen);
    i32 EDFA_DbgWrite(1:i32 uiDevType, 2:binary pucBuf, 3:i32 uiLen),

    //int EDFA_SetDfbEnable(uint32_t uiDevType, bool bEnable, int32_t iPower);
    i32 EDFA_SetDfbEnable(1:i32 uiDevType, 2:bool bEnable, 3:i32 iPower),

    //int EDFA_SetOscEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetOscEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetOtdrSwitchPos(uint32_t uiDevType, uint32_t uiPos);
    i32 EDFA_SetOtdrSwitchPos(1:i32 uiDevType, 2:i32 uiPos),

    //int EDFA_SetOscAddThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys);
    i32 EDFA_SetOscAddThrHys(1:i32 uiDevType, 2:i16 sThr, 3:i16 sHys),

    //int EDFA_SetOscDropThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys);
    i32 EDFA_SetOscDropThrHys(1:i32 uiDevType, 2:i16 sThr, 3:i16 sHys),

    //int EDFA_SetOscRxThrHys(uint32_t uiDevType, int16_t sThr, int16_t sHys);
    i32 EDFA_SetOscRxThrHys(1:i32 uiDevType, 2:i16 sThr, 3:i16 sHys),

    //int EDFA_SetApsdEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetApsdEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_GetApsdStatus(uint32_t uiDevType, bool *pbCfg, bool *pbStatus, bool *pbEvent);
    bool_list_rsp EDFA_GetApsdStatus(1:i32 uiDevType),

    //int EDFA_GetOcmAttn(uint32_t uiDevType, int16_t *psAttn);
    i16_rsp EDFA_GetOcmAttn(1:i32 uiDevType),

    //int EDFA_SetUpgState(uint32_t uiDevType, int16_t sState);
    i32 EDFA_SetUpgState(1:i32 uiDevType, 2:i16 sState),

    //int EDFA_SetLedState(uint32_t uiDevType, int16_t sState);
    i32 EDFA_SetLedState(1:i32 uiDevType, 2:i16 sState),

    //int EDFA_SetLedAlm(uint32_t uiDevType, int16_t sState);
    i32 EDFA_SetLedAlm(1:i32 uiDevType, 2:i16 sState),

    //int EDFA_GetCali(uint32_t uiDevType, COaCaliData *pstCaliInfo);
    COaCaliData_rsp EDFA_GetCali(1:i32 uiDevType),

    //int EDFA_SetOtdrCali(uint32_t uiDevType, char *pcFilePath);
    i32 EDFA_SetOtdrCali(1:i32 uiDevType, 2:string pcFilePath),

    //int EDFA_SetOcmCali(uint32_t uiDevType, char *pcFilePath);
    i32 EDFA_SetOcmCali(1:i32 uiDevType, 2:string pcFilePath),

    //int EDFA_SetManualVoaEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetManualVoaEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetPaddingVoaConfigPower(uint32_t uiDevType, int16_t sOutPower);
    i32 EDFA_SetPaddingVoaConfigPower(1:i32 uiDevType, 2:i16 sOutPower),

    //int EDFA_SetManualGainEnable(uint32_t uiDevType, bool bEnable);
    i32 EDFA_SetManualGainEnable(1:i32 uiDevType, 2:bool bEnable),

    //int EDFA_SetThr(uint32_t uiDevType, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr, int16_t sHys);
    i32 EDFA_SetThr(1:i32 uiDevType, 2:i32 uiPortIdx, 3:i32 uiType, 4:i16 sThr, 5:i16 sHys),

    //int EDFA_SetPumpCurrent(uint32_t uiDevType, uint32_t uiPumpIdx, int16_t sCurrent);
    i32 EDFA_SetPumpCurrent(1:i32 uiDevType, 2:i32 uiPumpIdx, 3:i16 sCurrent),

    //int EDFA_SetAlmMask(uint32_t uiDevType, int32_t iMaskIdx, int32_t iMaskVal);
    i32 EDFA_SetAlmMask(1:i32 uiDevType, 2:i32 iMaskIdx, 3:i32 iMaskVal),

    //int EDFA_GetEventLog(uint32_t uiDevType, COaEventLogAllData *pstEventLogAll);
    COaEventLogAllData_rsp EDFA_GetEventLog(1:i32 uiDevType),

    //int EDFA_SetShutterState(uint32_t uiDevType, bool block);
    i32 EDFA_SetShutterState(1:i32 uiDevType, 2:bool block),

    //int EDFA_GetShutterState(uint32_t uiDevType, bool *block);
    bool_rsp EDFA_GetShutterState(1:i32 uiDevType),

    /* DevExtendCApi.h */

    //int EXTEND_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp EXTEND_GetMfg(1:i32 uiDevIdx),

    //int EXTEND_GetStatusData(uint32_t uiDevIdx, CExtendStatusData *pstStatus);
    CExtendStatusData_rsp EXTEND_GetStatusData(1:i32 uiDevIdx),

    //int EXTEND_Reset(uint32_t uiDevIdx, uint8_t ucResetType);
    i32 EXTEND_Reset(1:i32 uiDevIdx, 2:i8 ucResetType),

    //int EXTEND_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath);
    i32 EXTEND_Upgrade(1:i32 uiDevIdx, 2:string c_pcFilePath),

    //int EXTEND_GetUpgadeStatus(uint32_t uiDevIdx);
    i32 EXTEND_GetUpgadeStatus(1:i32 uiDevIdx),

    //int EXTEND_DbgRead(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen);
    binary_rsp EXTEND_DbgRead(1:i32 uiDevIdx, 2:i32 uiLen),

    //int EXTEND_DbgWrite(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen);
    i32 EXTEND_DbgWrite(1:i32 uiDevIdx, 2:binary pucBuf, 3:i32 uiLen),

    //int EXTEND_SetSfp(uint32_t uiDevIdx, uint32_t ulVal);
    i32 EXTEND_SetSfp(1:i32 uiDevIdx, 2:i32 ulVal),

    //int MIRROR_GetStatusData(uint32_t uiDevIdx, CMirrorData *pstStatus);
    CMirrorData_rsp MIRROR_GetStatusData(1:i32 uiDevIdx),

    //int SWITCH_Pos(uint32_t uiDevIdx, uint32_t uiPort);
    i32 SWITCH_Pos(1:i32 uiDevIdx, 2:i32 uiPort),


    /* DevMuxCApi.h */

    //int MUX_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp MUX_GetMfg(1:i32 uiDevIdx),

    //int MUX_GetStatusData(uint32_t uiDevIdx, CMuxStatusData *pstStatus);
    CMuxStatusData_rsp MUX_GetStatusData(1:i32 uiDevIdx),

    //int MUX_GetCali(uint32_t uiDevIdx, CMuxCaliData *pstCali);
    CMuxCaliData_rsp MUX_GetCali(1:i32 uiDevIdx),


    /* DevOcmCApi.h */

    //int OCM_GetMfg(uint32_t uiDevType, CMfg *pstMfg);
    CMfg_rsp OCM_GetMfg(1:i32 uiDevType),

    //int OCM_GetStatusData(uint32_t uiDevType, COcmStatusData *pstOcmStatus);
    COcmStatusData_rsp OCM_GetStatusData(1:i32 uiDevType),

    //int OCM_GetChPower(uint32_t uiDevType, uint32_t uiPortId, COcmChPower *pstOcmChPower);
    COcmChPower_rsp OCM_GetChPower(1:i32 uiDevType, 2:i32 uiPortId),

    //int OCM_GetOsaData(uint32_t uiDevType, uint32_t uiPortId, COcmOsa *pstOcmOsa);
    COcmOsa_rsp OCM_GetOsaData(1:i32 uiDevType, 2:i32 uiPortId),

    //int OCM_GetRealTimeOsaData(uint32_t uiDevType, uint32_t uiPortId, COcmOsa *pstOcmOsa);
    COcmOsa_rsp OCM_GetRealTimeOsaData(1:i32 uiDevType, 2:i32 uiPortId),

    //int OCM_SetWaveplan(uint32_t uiDevType, uint32_t uiPortId, uint32_t uiChCnt, CWavePlanSlice *pstWavePlan);
    i32 OCM_SetWaveplan(1:i32 uiDevType, 2:i32 uiPortId, 3:i32 uiChCnt, 4:list<CWavePlanSlice_t> pstWavePlan),

    //int OCM_SetOcmWaveplan(uint32_t uiDevType, uint32_t uiPortId, uint32_t uiChCnt, STChannelGrid *pstWavePlan);
    i32 OCM_SetOcmWaveplan(1:i32 uiDevType, 2:i32 uiPortId, 3:i32 uiChCnt, 4:list<STChannelGrid_t> pstWavePlan),

    //int OCM_Reset(uint32_t uiDevType, uint8_t ucResetType);
    i32 OCM_Reset(1:i32 uiDevType, 2:i8 ucResetType),

    //int OCM_Upgrade(uint32_t uiDevType, const char *c_pcFilePath);
    i32 OCM_Upgrade(1:i32 uiDevType, 2:string c_pcFilePath),

    //int OCM_Commit(uint32_t uiDevType);
    i32 OCM_Commit(1:i32 uiDevType),

    //int OCM_GetUpgradeStatus(uint32_t uiDevType);
    i32 OCM_GetUpgradeStatus(1:i32 uiDevType),

    //int OCM_SetVoa(uint32_t uiDevType, int16_t sAttn);
    i32 OCM_SetVoa(1:i32 uiDevType, 2:i16 sAttn),

    //int OCM_GetVoa(uint32_t uiDevType, int16_t *psAttn);
    i16_rsp OCM_GetVoa(1:i32 uiDevType),

    //int OCM_GetVoaPd(uint32_t uiDevType, int16_t *psVoaIn, int16_t *psVoaOut);
    i16_list_rsp OCM_GetVoaPd(1:i32 uiDevType),


    /* DevOcsCApi.h */

    //int OCS_GetMfg(uint32_t uiDevType, CMfg *pstMfg);
    CMfg_rsp OCS_GetMfg(1:i32 uiDevType),

    //int OCS_GetStatusData(uint32_t uiDevType, COcsStatusData *pstStatus);
    COcsStatusData_rsp OCS_GetStatusData(1:i32 uiDevType),

    //int OCS_SetConnection(uint32_t uiDevType, const COcsConnection *pstConnection);
    i32 OCS_SetConnection(1:i32 uiDevType, 2:COcsConnection_t pstConnection),

    //int OCS_SetConnections(uint32_t uiDevType, const COcsConnections *pstConnections);
    i32 OCS_SetConnections(1:i32 uiDevType, 2:COcsConnections_t pstConnections),

    //int OCS_SetLedState(uint32_t uiDevType, uint32_t index, uint32_t uiState);
    i32 OCS_SetLedState(1:i32 uiDevType, 2:i32 index, 3:i32 uiState),

    //int OCS_SetLedMode(uint32_t uiDevType, uint32_t uiMode);
    i32 OCS_SetLedMode(1:i32 uiDevType, 2:i32 uiMode),

    //int OCS_Reset(uint32_t uiDevType, uint8_t ucResetType);
    i32 OCS_Reset(1:i32 uiDevType, 2:i8 ucResetType),

    //int OCS_Upgrade(uint32_t uiDevType, const char *pcPath);
    i32 OCS_Upgrade(1:i32 uiDevType, 2:string pcPath),

    //int OCS_GetUpgradeStatus(uint32_t uiDevType);
    i32 OCS_GetUpgradeStatus(1:i32 uiDevType),


    /* DevOpsCApi.h */

    //int OPS_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp OPS_GetMfg(1:i32 uiDevIdx),

    //int OPS_GetCommStatusData(uint32_t uiDevType, COpsCommStatusData *pstOpsStatus);
    COpsCommStatusData_rsp OPS_GetCommStatusData(1:i32 uiDevIdx),

    //int OPS_GetCfgData(uint32_t uiDevIdx, COpsCfgData *pstOpsCfg, uint32_t uiPortId);
    COpsCfgData_rsp OPS_GetCfgData(1:i32 uiDevIdx, 2:i32 uiPortId),

    //int OPS_GetStatusData(uint32_t uiDevIdx, COpsStatusData *pstOpsStatus, uint32_t uiPortId);
    COpsStatusData_rsp OPS_GetStatusData(1:i32 uiDevIdx, 2:i32 uiPortId),

    //int OPS_GetHistoryData(uint32_t uiDevIdx, COpsHistoryData *pstData, uint32_t uiPortId);
    COpsHistoryData_rsp OPS_GetHistoryData(1:i32 uiDevIdx, 2:i32 uiPortId),

    //int OPS_GetLedStatus(uint32_t uiDevIdx, COpsLed *pstData);
    COpsLed_rsp OPS_GetLedStatus(1:i32 uiDevIdx),

    //int OPS_ClearAlarmDuration(uint32_t uiDevIdx);
    i32 OPS_ClearAlarmDuration(1:i32 uiDevIdx),

    //int OPS_SetThrPwrDiff(uint32_t uiDevIdx, int16_t sThr, int16_t sHys, uint32_t uiPortId);
    i32 OPS_SetThrPwrDiff(1:i32 uiDevIdx, 2:i16 sThr, 3:i16 sHys, 4:i32 uiPortId),

    //int OPS_SetThrLine(uint32_t uiDevIdx, uint32_t uiPortIdx, int16_t sThr, int16_t sHys, uint32_t uiPortId);
    i32 OPS_SetThrLine(1:i32 uiDevIdx, 2:i32 uiPortIdx, 3:i16 sThr, 4:i16 sHys, 5:i32 uiPortId),

    //int OPS_SetPortPowerThr(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr, uint32_t uiPortId);
    i32 OPS_SetPortPowerThr(1:i32 uiDevIdx, 2:i32 uiPortIdx, 3:i32 uiType, 4:i16 sThr, 5:i32 uiPortId),

    //int OPS_SetPortPowerHys(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sHys, uint32_t uiPortId);
    i32 OPS_SetPortPowerHys(1:i32 uiDevIdx, 2:i32 uiPortIdx, 3:i32 uiType, 4:i16 sHys, 5:i32 uiPortId),

    //int OPS_SetWtr(uint32_t uiDevIdx, uint32_t uiWtr, uint32_t uiPortId);
    i32 OPS_SetWtr(1:i32 uiDevIdx, 2:i32 uiWtr, 3:i32 uiPortId),

    //int OPS_SetHoldOffTime(uint32_t uiDevIdx, uint32_t uiHoldOffTime, uint32_t uiPortId);
    i32 OPS_SetHoldOffTime(1:i32 uiDevIdx, 2:i32 uiHoldOffTime, 3:i32 uiPortId),

    //int OPS_SetRevertive(uint32_t uiDevIdx, bool bRevertive, uint32_t uiPortId);
    i32 OPS_SetRevertive(1:i32 uiDevIdx, 2:bool bRevertive, 3:i32 uiPortId),

    //int OPS_SetMode(uint32_t uiDevIdx, uint32_t uiMode, uint32_t uiPortId);
    i32 OPS_SetMode(1:i32 uiDevIdx, 2:i32 uiMode, 3:i32 uiPortId),

    //int OPS_SetRelativeThr(uint32_t uiDevIdx, int16_t sThr, uint32_t uiPortId);
    i32 OPS_SetRelativeThr(1:i32 uiDevIdx, 2:i16 sThr, 3:i32 uiPortId),

    //int OPS_SetRelativeOffset(uint32_t uiDevIdx, int16_t sOffset, uint32_t uiPortId);
    i32 OPS_SetRelativeOffset(1:i32 uiDevIdx, 2:i16 sOffset, 3:i32 uiPortId),

    //int OPS_SetSwitchThr(uint32_t uiDevIdx, uint32_t uiPos, int32_t iThr, uint32_t uiPortId);
    i32 OPS_SetSwitchThr(1:i32 uiDevIdx, 2:i32 uiPos, 3:i32 iThr, 4:i32 uiPortId),

    //int OPS_SetSwitchHys(uint32_t uiDevIdx, uint32_t uiPos, int32_t iHys, uint32_t uiPortId);
    i32 OPS_SetSwitchHys(1:i32 uiDevIdx, 2:i32 uiPos, 3:i32 iHys, 4:i32 uiPortId),

    //int OPS_Reset(uint32_t uiDevIdx, uint8_t ucResetType);
    i32 OPS_Reset(1:i32 uiDevIdx, 2:i8 ucResetType),

    //int OPS_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath);
    i32 OPS_Upgrade(1:i32 uiDevIdx, 2:string c_pcFilePath),

    //int OPS_GetUpgadeStatus(uint32_t uiDevIdx);
    i32 OPS_GetUpgadeStatus(1:i32 uiDevIdx),

    //int OPS_SetLedDebugMode(uint32_t uiDevType, uint32_t uiMode);
    i32 OPS_SetLedDebugMode(1:i32 uiDevIdx, 2:i32 uiMode),

    //int OPS_SetLedStatus(uint32_t uiDevType, uint32_t uiLedIdx, uint32_t uiStatus);
    i32 OPS_SetLedStatus(1:i32 uiDevIdx, 2:i32 uiLedIdx, 3:i32 uiStatus),

    //int OPS_SetConnectionPdThr(uint32_t uiDevIdx, uint32_t uiPdIdx, uint32_t uiType, int16_t sThr, uint32_t uiPortId);
    i32 OPS_SetConnectionPdThr(1:i32 uiDevIdx, 2:i32 uiPdIdx, 3:i32 uiType, 4:i16 sThr, 5:i32 uiPortId),

    //int OPS_SetConnectionPdHys(uint32_t uiDevIdx, uint32_t uiPdIdx, uint32_t uiType, int16_t sHys, uint32_t uiPortId);
    i32 OPS_SetConnectionPdHys(1:i32 uiDevIdx, 2:i32 uiPdIdx, 3:i32 uiType, 4:i16 sHys, 5:i32 uiPortId),

    //int OPS_SetAlmMask(uint32_t uiDevType, int32_t iMaskIdx, int32_t iMaskVal, uint32_t uiPortId);
    i32 OPS_SetAlmMask(1:i32 uiDevType, 2:i32 iMaskIdx, 3:i32 iMaskVal,4:i32 uiPortId),

    //int OPS_GetEventLog(uint32_t uiDevType, COpsEventLogAllData *pstEventLogAll, uint32_t uiPortId);
    COpsEventLogAllData_rsp OPS_GetEventLog(1:i32 uiDevType, 2:i32 uiPortId),

    //int OPS_SetRemoteStatus(uint32_t uiDevIdx, COpsReqStatus *pstStatus, uint32_t uiPortId);
    i32 OPS_SetRemoteStatus(1:i32 uiDevIdx, 2:COpsReqStatus_t pstStatus, 3:i32 uiPortId),

    //int OPS_GetRequestStatus(uint32_t uiDevIdx, COpsBidirectionStatus *pstStatus, uint32_t uiPortId);
    COpsBidirectionStatus_rsp OPS_GetRequestStatus(1:i32 uiDevIdx, 2:i32 uiPortId),

    //int OPS_SetSwitchingType(uint32_t uiDevIdx, uint8_t ucType, uint32_t uiPortId);
    i32 OPS_SetSwitchingType(1:i32 uiDevIdx, 2:i8 ucType, 3:i32 uiPortId),

    //int OPS_GetOpsDevIdByKey(char *pcName, uint32_t *piDevId, uint32_t *piPortId);
    i32_list_rsp OPS_GetOpsDevIdByKey(1:string pcName),


    /* DevOscCApi.h */

    //int OSC_GetStatusData(uint32_t uiDevType, COscStatusData *pstOscStatus);
    COscStatusData_rsp OSC_GetStatusData(1:i32 uiDevType),

    //int OSC_GetCfgData(uint32_t uiDevType, COscCfgData *pstOscCfg);
    COscCfgData_rsp OSC_GetCfgData(1:i32 uiDevType),

    //int OSC_SetEnable(uint32_t uiDevType, bool bEnable);
    i32 OSC_SetEnable(1:i32 uiDevType, 2:bool bEnable),

    //int OSC_SetVoa(uint32_t uiDevType, uint32_t uiTxRx, int16_t sAttn);
    i32 OSC_SetVoa(1:i32 uiDevType, 2:i32 uiTxRx, 3:i16 sAttn),

    //int OSC_GetVoa(uint32_t uiDevType, uint32_t uiTxRx, int16_t *psAttn);
    i16_rsp OSC_GetVoa(1:i32 uiDevType, 2:i32 uiTxRx),

    //int OSC_SetSwitchPos(uint32_t uiDevType, COscSwitchPosSet rstSwitchPos);
    i32 OSC_SetSwitchPos(1:i32 uiDevType, 2:COscSwitchPosSet_t rstSwitchPos),

    //int OSC_GetSwitchPos(uint32_t uiDevType, COscSwitchPos *pstSwitchPos);
    COscSwitchPos_rsp OSC_GetSwitchPos(1:i32 uiDevType),


    /* DevOtdrCApi.h */

    //int OTDR_GetMfg(uint32_t ulDevIdx, CMfg *pstMfg);
    CMfg_rsp OTDR_GetMfg(1:i32 ulDevIdx),

    //int OTDR_GetStatusData(uint32_t ulDevIdx, COtdrStatusData *pstStatus);
    COtdrStatusData_rsp OTDR_GetStatusData(1:i32 ulDevIdx),

    //int OTDR_GetCfgData(uint32_t ulDevIdx, COtdrCfgData *pstCfg);
    COtdrCfgData_rsp OTDR_GetCfgData(1:i32 ulDevIdx),

    //int OTDR_StartScan(uint32_t ulDevIdx);
    i32 OTDR_StartScan(1:i32 ulDevIdx),

    //int OTDR_SetPara(uint32_t ulDevIdx, uint32_t ulDistRang, uint32_t ulPulseWidth, double dSamplingResolution);
    i32 OTDR_SetPara(1:i32 ulDevIdx, 2:i32 ulDistRang, 3:i32 ulPulseWidth, 4:double dSamplingResolution),

    //int OTDR_SetMeasuringTime(uint32_t ulDevIdx, uint32_t ulMeasuringTime);
    i32 OTDR_SetMeasuringTime(1:i32 ulDevIdx, 2:i32 ulMeasuringTime),

    //int OTDR_SetUserIOR(uint32_t ulDevIdx, double dUserIOR);
    i32 OTDR_SetUserIOR(1:i32 ulDevIdx, 2:double dUserIOR),

    //int OTDR_SetThr(uint32_t ulDevIdx, double dRefThr, double dSpliceLosThr, double dFiberEndThr);
    i32 OTDR_SetThr(1:i32 ulDevIdx, 2:double dRefThr, 3:double dSpliceLosThr, 4:double dFiberEndThr),

    //int OTDR_Reset(uint32_t ulDevIdx, uint8_t ucResetType);
    i32 OTDR_Reset(1:i32 ulDevIdx, 2:i8 ucResetType),

    //int OTDR_Upgrade(uint32_t ulDevIdx, const char *c_pcFilePath);
    i32 OTDR_Upgrade(1:i32 ulDevIdx, 2:string c_pcFilePath),

    //int OTDR_GetUpgadeStatus(uint32_t uiDevIdx);
    i32 OTDR_GetUpgadeStatus(1:i32 ulDevIdx),

    //int OTDR_DbgRead(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen);
    binary_rsp OTDR_DbgRead(1:i32 ulDevIdx, 2:i32 uiLen),

    //int OTDR_DbgWrite(uint32_t uiDevIdx, uint8_t *pucBuf, uint32_t uiLen);
    i32 OTDR_DbgWrite(1:i32 ulDevIdx, 2:binary pucBuf, 3:i32 uiLen),

    //int OTDR_SetScanMode(uint32_t uiDevType, uint32_t ulScanMode);
    i32 OTDR_SetScanMode(1:i32 uiDevType, 2:i32 ulScanMode),

    //int OTDR_SetStartOffset(uint32_t uiDevType, COtdrStartOffset *pstStartOffset);
    i32 OTDR_SetStartOffset(1:i32 uiDevType, 2:COtdrStartOffset_t pstStartOffset),

    //int OTDR_GetStartOffset(uint32_t uiDevType, COtdrStartOffset *pstStartOffset);
    COtdrStartOffset_rsp OTDR_GetStartOffset(1:i32 uiDevType),

    //int OTDR_StartScanPort(uint32_t ulDevIdx, uint32_t ulPortId);
    i32 OTDR_StartScanPort(1:i32 ulDevIdx, 2:i32 ulPortId),


    /* DevSlotCApi.h */

    //int SLOT_GetDevIdx(uint32_t uiDevType, uint32_t *puiDevIdx, uint32_t *puiDevSubIdx);
    i32_list_rsp SLOT_GetDevIdx(1:i32 uiDevType),

    //int SLOT_SetOnline(uint32_t uiSlotIdx, bool bOnline);
    i32 SLOT_SetOnline(1:i32 uiSlotIdx, 2:bool bOnline),

    //int SLOT_GetSlotNum(uint32_t *puiSlotNum);
    i32_rsp SLOT_GetSlotNum(),

    //int SLOT_SetMfg(uint32_t uiSlotIdx, const char *c_pcFilePath);
    i32 SLOT_SetMfg(1:i32 uiSlotIdx, 2:string c_pcFilePath),

    //int SLOT_GetMfg(uint32_t uiSlotIdx, CMfg *pstMfg);
    CMfg_rsp SLOT_GetMfg(1:i32 uiSlotIdx),

    //int SLOT_GetStatusData(uint32_t uiSlotIdx, CSlotStatusData *pstStatus);
    CSlotStatusData_rsp SLOT_GetStatusData(1:i32 uiSlotIdx),

    //int SLOT_ClearPlugFlag(uint32_t uiSlotIdx);
    i32 SLOT_ClearPlugFlag(1:i32 uiSlotIdx),

    //int SLOT_GetInfo(uint32_t uiSlotIdx, CSlotInfo *pstInfo);
    CSlotInfo_rsp SLOT_GetInfo(1:i32 uiSlotIdx),

    //int SLOT_GetCali(uint32_t uiSlotIdx, CCali *pstCaliInfo);
    CCali_rsp SLOT_GetCali(1:i32 uiSlotIdx),

    //int SLOT_SetCali(uint32_t uiSlotIdx, const char *pcFilePath);
    i32 SLOT_SetCali(1:i32 uiSlotIdx, 2:string c_pcFilePath),

    //int SLOT_Reset(uint32_t uiSlotIdx, uint8_t ucResetType);
    i32 SLOT_Reset(1:i32 uiSlotIdx, 2:i8 ucResetType),

    //int SLOT_SetLed(uint32_t uiSlotIdx, uint32_t uiLedIdx, uint32_t uiState);
    i32 SLOT_SetLed(1:i32 uiSlotIdx, 2:i32 uiLedIdx, 3:i32 uiState),

    //int SLOT_ReadEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    binary_rsp SLOT_ReadEeprom(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen),

    //int SLOT_WriteEeprom(uint32_t uiIdx, uint64_t ulAddr, uint64_t ulLen, uint8_t *pucVal);
    i32 SLOT_WriteEeprom(1:i32 uiIdx, 2:i64 ulAddr, 3:i64 ulLen, 4:binary pucVal),


    /* DevTdcmCApi.h */

    //int TDCM_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp TDCM_GetMfg(1:i32 uiDevIdx),

    //int TDCM_GetStatusData(uint32_t uiDevIdx, CTdcmStatusData *pstTdcmStatus);
    CTdcmStatusData_rsp TDCM_GetStatusData(1:i32 uiDevIdx),

    //int TDCM_GetCfgData(uint32_t uiDevIdx, CTdcmCfgData *pstTdcmCfg);
    CTdcmCfgData_rsp TDCM_GetCfgData(1:i32 uiDevIdx),

    //int TDCM_SetFrequency(uint32_t uiDevIdx, float fFrequency);
    i32 TDCM_SetFrequency(1:i32 uiDevIdx, 2:double fFrequency),

    //int TDCM_SetDispersion(uint32_t uiDevIdx, float fDispersion);
    i32 TDCM_SetDispersion(1:i32 uiDevIdx, 2:double fDispersion),

    //int TDCM_Reset(uint32_t uiDevIdx, uint8_t ucResetType);
    i32 TDCM_Reset(1:i32 uiDevIdx, 2:i8 ucResetType),


    /* DevWssCApi.h */

    //int WSS_GetMfg(uint32_t uiDevIdx, CMfg *pstMfg);
    CMfg_rsp WSS_GetMfg(1:i32 uiDevIdx),

    //int WSS_GetCfg(uint32_t uiDevIdx, CWssAllCfg *pstAllCfg);
    CWssAllCfg_rsp WSS_GetCfg(1:i32 uiDevIdx),

    //int WSS_GetOscCfg(uint32_t uiDevIdx, CWssAllCfg *pstCfg);
    CWssAllCfg_rsp WSS_GetOscCfg(1:i32 uiDevIdx),

    //int WSS_GetStatusData(uint32_t uiDevIdx, CWssStatusData *pstStatus);
    CWssStatusData_rsp WSS_GetStatusData(1:i32 uiDevIdx),

    //int WSS_SetAllChCfg(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWssCfg *pstWssCfg);
    i32 WSS_SetAllChCfg(1:i32 uiDevIdx, 2:i32 uiSubIdx, 3:i32 uiChCnt, 4:list<CWssCfg_t> pstWssCfg);

    //int WSS_SetOscChCfg(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWssCfg *pstWssCfg);
    i32 WSS_SetOscChCfg(1:i32 uiDevIdx, 2:i32 uiSubIdx, 3:i32 uiChCnt, 4:list<CWssCfg_t> pstWssCfg);

    //int WSS_SetWaveplan(uint32_t uiDevIdx, uint32_t uiSubIdx, uint32_t uiChCnt, CWavePlan *pstWavePlan);
    i32 WSS_SetWaveplan(1:i32 uiDevIdx, 2:i32 uiSubIdx, 3:i32 uiChCnt, 4:list<CWavePlan_t> pstWavePlan);

    //int WSS_SetPortPowerThr(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sThr);
    i32 WSS_SetPortPowerThr(1:i32 uiDevIdx, 2:i32 uiPortIdx, 3:i32 uiType, 4:i16 sThr);

    //int WSS_SetPortPowerHys(uint32_t uiDevIdx, uint32_t uiPortIdx, uint32_t uiType, int16_t sHys);
    i32 WSS_SetPortPowerHys(1:i32 uiDevIdx, 2:i32 uiPortIdx, 3:i32 uiType, 4:i16 sHys);

    //int WSS_GetPortPowerHistory(uint32_t uiDevIdx);
    i32 WSS_GetPortPowerHistory(1:i32 uiDevIdx),

    //int WSS_SetLedMode(uint32_t uiDevIdx, uint32_t uiMode);
    i32 WSS_SetLedMode(1:i32 uiDevIdx, 2:i32 uiMode),

    //int WSS_SetLedDebugMode(uint32_t uiDevIdx, uint32_t uiMode);
    i32 WSS_SetLedDebugMode(1:i32 uiDevIdx, 2:i32 uiMode),

    //int WSS_SetLedStatus(uint32_t uiDevIdx, uint32_t uiLedIdx, uint32_t uiStatus);
    i32 WSS_SetLedStatus(1:i32 uiDevIdx, 2:i32 uiLedIdx, 3:i32 uiStatus),

    //int WSS_Reset(uint32_t uiDevIdx, uint8_t ucResetType);
    i32 WSS_Reset(1:i32 uiDevIdx, 2:i8 ucResetType),

    //int WSS_Upgrade(uint32_t uiDevIdx, const char *c_pcFilePath);
    i32 WSS_Upgrade(1:i32 uiDevIdx, 2:string c_pcFilePath),

    //int WSS_GetUpgradeStatus(uint32_t uiDevIdx);
    i32 WSS_GetUpgradeStatus(1:i32 uiDevIdx),

    //int WSS_SetUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen);
    i32 WSS_SetUserData(1:i32 uiDevIdx, 2:binary pucData, 3:i32 nLen),

    //int WSS_GetUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen);
    binary_rsp WSS_GetUserData(1:i32 uiDevIdx, 2:i32 nLen),

    //int WSS_SetPmUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen);
    i32 WSS_SetPmUserData(1:i32 uiDevIdx, 2:binary pucData, 3:i32 nLen),

    //int WSS_GetPmUserData(uint32_t uiDevIdx, uint8_t *pucData, size_t nLen);
    binary_rsp WSS_GetPmUserData(1:i32 uiDevIdx, 2:i32 nLen),

}
