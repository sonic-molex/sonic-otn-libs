#pragma once

#define DEF_RETURN_NONE             (-1)

#define DEF_THRIFT_ADDR             ("0.0.0.0")
#define DEF_THRIFT_PORT             (10972)

/* Fan drawer */
#define DEF_FANDRAWER_NAME          ("FanTray0")
#define DEF_FANDRAWER_LED_INDEX     (2)

/* Fan */
#define DEF_FAN_NAME                ("Fan")
#define DEF_FAN_LED_INDEX           (3)
#define DEF_FAN_SPEED_LOW           (0)
#define DEF_FAN_SPEED_UP            (100)
#define DEF_FAN_SPEED_TOLERANCE     (2)

/* Watch dog */
#define DEF_WD_TIME_S_UNIT          (30)

/* PSU */
#define DEF_PSU_NAME                ("PSU")

/* Thermal */
#define DEF_THERMAL_HIGH_THERS      (75.0)
#define DEF_THERMAL_LOW_THERS       (-5.0)
#define DEF_THERMAL_HIGH_CRIT_THERS (70.0)
#define DEF_THERMAL_LOW_CRIT_THERS  (0.0)
#define DEF_THERMAL_NONE            (0.0)

/* Chassis */
#define DEF_CHASSIS_LED_INDEX       (0)

/* CPU */
#define DEF_CPU_NAME                ("CPU")
#define DEF_CPU_CMD_TEMP            ("sensors | grep Core")
#define DEF_CPU_TEMP_WEIGHT         (10)

/* Module */
#define DEF_MODULE_NAME_LINECARD    ("LINE-CARD")
#define DEF_MODULE_NAME_SUPERVISOR  ("SUPERVISOR0")

/* Components */
#define DEF_COMPONENT_NAME_LENS     (32)
#define DEF_COMPONENT_NAME_NA       ("N/A")
#define DEF_COMPONENT_NAME_BIOS     ("BIOS")
#define DEF_COMPONENT_NAME_FPGA     ("FPGA")
#define DEF_COMPONENT_NAME_CPLD     ("CPLD")
#define DEF_COMPONENT_NAME_ONIE     ("ONIE")
#define DEF_COMPONENT_NAME_OPS      ("OPS")
#define DEF_COMPONENT_NAME_MUX      ("MUX")
#define DEF_COMPONENT_NAME_OA       ("OA")
#define DEF_COMPONENT_NAME_OCM      ("OCM")
#define DEF_COMPONENT_NAME_OTDR     ("OTDR")
#define DEF_COMPONENT_NAME_EEPROM   ("EEPROM")
#define DEF_COMPONENT_VER_BIOS      ("5.6.5")
#define DEF_COMPONENT_VER_ONIE      ("2022.08")

#define DEV_TYPE_NONE               (0)  

typedef enum EN_FAN_DIRECTION
{
    FAN_DIRECTION_INTAKE = 0,
    FAN_DIRECTION_EXHAUST
} FAN_DIRECTION;

typedef enum EN_MODULE_TYPE
{
    MODULE_TYPE_SUPERVISOR = 0,
    MODULE_TYPE_LINECARD,
    MODULE_TYPE_FABRIC
} MODULE_TYPE;