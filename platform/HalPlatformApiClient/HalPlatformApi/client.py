import sys
import glob

from .HalPlatformApi import Client

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol


transport = None
client = None


def Initialize():
    '''
    Initialize the dynamic library

    Returns:
        A boolean, True if initialized successfully, False if not
    '''
    try:
        # Make socket
        global transport
        transport = TSocket.TSocket('0.0.0.0', 10972)

        # Buffering is critical. Raw sockets are very slow
        transport = TTransport.TBufferedTransport(transport)

        # Wrap in a protocol
        protocol = TBinaryProtocol.TBinaryProtocol(transport)

        # Create a client to use the protocol encoder
        global client
        client = Client(protocol)

        # Connect!
        transport.open()

        return True
    except Thrift.TException as tx:
        print('%s' % tx.message)
        return False


def Destroy():
    # Close!
    global transport
    global client
    if transport is not None:
        transport.close()
        transport = None
        client = None


# PSU

def PsuGetModel(name):
    '''
    Retrieves the model number (or part number) of the device

    Args:
        name: A string, the device name
    Returns:
        A string, model/part number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.PsuGetModel(name)


def PsuGetSerial(name):
    '''
    Retrieves the serial number of the device

    Args:
        name: A string, the device name
    Returns:
        A string, serial number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.PsuGetSerial(name)


def PsuGetRevision(name):
    '''
    Retrieves the hardware revision of the device

    Args:
        name: A string, the device name
    Returns:
        A string, revision value of device, None if operation failed
    '''
    if client is None:
        return None

    return client.PsuGetRevision(name)


def PsuGetPresence(name):
    '''
    Retrieves the presence of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is present, False if not
    '''
    if client is None:
        return None

    return client.PsuGetPresence(name)


def PsuGetStatus(name):
    '''
    Retrieves the operational status of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is operating properly, False if not
    '''
    if client is None:
        return None

    return client.PsuGetStatus(name)


def PsuIsReplaceable(name):
    '''
    Indicate whether this device is replaceable.

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if it is replaceable, False if not
    '''
    if client is None:
        return None

    return client.PsuIsReplaceable(name)


def PsuGetVoltage(name):
    '''
    Retrieves current PSU voltage output

    Args:
        name: A string, the device name
    Returns:
        A float number, the output voltage in volts, e.g. 12.1
    '''
    if client is None:
        return None

    return client.PsuGetVoltage(name)


def PsuGetCurrent(name):
    '''
    Retrieves present electric current supplied by PSU

    Args:
        name: A string, the device name
    Returns:
        A float number, the electric current in amperes, e.g 15.4
    '''
    if client is None:
        return None

    return client.PsuGetCurrent(name)


def PsuGetPower(name):
    '''
    Retrieves current energy supplied by PSU

    Args:
        name: A string, the device name
    Returns:
        A float number, the power in watts, e.g. 302.6
    '''
    if client is None:
        return None

    return client.PsuGetPower(name)


def PsuGetTemp(name):
    '''
    Retrieves current temperature reading from PSU

    Args:
        name: A string, the device name
    Returns:
        A float number of current temperature in Celsius, e.g. 30.1
    '''
    if client is None:
        return None

    return client.PsuGetTemp(name)


def PsuGetInputVoltage(name):
    '''
    Retrieves current PSU voltage input

    Args:
        name: A string, the device name
    Returns:
        A float number, the input voltage in volts, e.g. 12.1
    '''
    if client is None:
        return None

    return client.PsuGetInputVoltage(name)


def PsuGetInputCurrent(name):
    '''
    Retrieves the input current draw of the power supply

    Args:
        name: A string, the device name
    Returns:
        A float number, the electric current in amperes, e.g 15.4
    '''
    if client is None:
        return None

    return client.PsuGetInputCurrent(name)


def PsuGetLedState(name):
    '''
    Gets the state of the PSU status LED

    Args:
        name: A string, the device name
    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.PsuGetLedState(name)


def PsuSetLedState(name, color):
    '''
    Sets the state of the PSU status LED

    Args:
        name: A string, the device name
        color: A string representing the color with which to set the PSU status LED
    Returns:
        A bool, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.PsuSetLedState(name, color)


# FAN

def FanGetModel(name):
    '''
    Retrieves the model number (or part number) of the device

    Args:
        name: A string, the device name
    Returns:
        A string, model/part number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.FanGetModel(name)


def FanGetSerial(name):
    '''
    Retrieves the serial number of the device

    Args:
        name: A string, the device name
    Returns:
        A string, serial number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.FanGetSerial(name)


def FanGetRevision(name):
    '''
    Retrieves the hardware revision of the device

    Args:
        name: A string, the device name
    Returns:
        A string, revision value of device, None if operation failed
    '''
    if client is None:
        return None

    return client.FanGetRevision(name)


def FanGetPresence(name):
    '''
    Retrieves the presence of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is present, False if not
    '''
    if client is None:
        return None

    return client.FanGetPresence(name)


def FanGetStatus(name):
    '''
    Retrieves the operational status of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is operating properly, False if not
    '''
    if client is None:
        return None

    return client.FanGetStatus(name)


def FanIsReplaceable(name):
    '''
    Indicate whether this device is replaceable.

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if it is replaceable, False if not
    '''
    if client is None:
        return None

    return client.FanIsReplaceable(name)


def FanGetDirection(name):
    '''
    Retrieves the direction of fan

    Args:
        name: A string, the device name
    Returns:
        A string, either FAN_DIRECTION_INTAKE or FAN_DIRECTION_EXHAUST depending on fan direction
    '''
    if client is None:
        return None

    return client.FanGetDirection(name)


def FanGetSpeed(name):
    '''
    Retrieves the speed of fan as a percentage of full speed

    Args:
        name: A string, the device name
    Returns:
        An integer, the percentage of full fan speed, in the range 0 (off) to 100 (full speed)
    '''
    if client is None:
        return None

    return client.FanGetSpeed(name)


def FanGetTargetSpeed(name):
    '''
    Retrieves the target (expected) speed of the fan

    Args:
        name: A string, the device name
    Returns:
        An integer, the percentage of full fan speed, in the range 0 (off) to 100 (full speed)
    '''
    if client is None:
        return None

    return client.FanGetTargetSpeed(name)


def FanGetSpeedTolerance(name):
    '''
    Retrieves the speed tolerance of the fan

    Args:
        name: A string, the device name
    Returns:
        An integer, the percentage of variance from target speed which is considered tolerable
    '''
    if client is None:
        return None

    return client.FanGetSpeedTolerance(name)


def FanSetSpeed(name, speed):
    '''
    Sets the fan speed

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if speed is set successfully, False if not
    '''
    if client is None:
        return None

    return client.FanSetSpeed(name, speed)


def FanGetLedState(name):
    '''
    Gets the state of the fan status LED

    Args:
        name: A string, the device name
    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.FanGetLedState(name)


def FanSetLedState(name, color):
    '''
    Sets the state of the fan module status LED

    Args:
        name: A string, the device name
        color: A string representing the color with which to set the fan module status LED
    Returns:
        A boolean, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.FanSetLedState(name, color)


def FanGetPositionInParent(name):
    '''
    Retrieves 1-based relative physical position in parent device.
    Returns:
        integer: The 1-based relative physical position in parent
        device or -1 if cannot determine the position
    '''
    if client is None:
        return None

    return client.FanGetPositionInParent(name)



# FAN Drawer
def FanDrawerGetPresence(name):
    '''
    Retrieves the presence of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is present, False if not
    '''
    if client is None:
        return None

    return client.FanDrawerGetPresence(name)


def FanDrawerGetStatus(name):
    '''
    Retrieves the operational status of the device

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if device is operating properly, False if not
    '''
    if client is None:
        return None

    return client.FanDrawerGetStatus(name)


def FanDrawerIsReplaceable(name):
    '''
    Indicate whether this device is replaceable.

    Args:
        name: A string, the device name
    Returns:
        A boolean, True if it is replaceable, False if not
    '''
    if client is None:
        return None

    return client.FanDrawerIsReplaceable(name)


def FanDrawerGetLedState(name):
    '''
    Gets the state of the fan drawer status LED

    Args:
        name: A string, the device name
    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.FanDrawerGetLedState(name)


def FanDrawerSetLedState(name, color):
    '''
    Sets the state of the fan drawer status LED

    Args:
        name: A string, the device name
        color: A string representing the color with which to set the fan module status LED
    Returns:
        A boolean, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.FanDrawerSetLedState(name, color)


# LED
def LedGetState(name):
    '''
    Gets the state of the LED device

    Args:
        name: A string, the device name
    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.LedGetState(name)


def LedSetState(name, state):
    '''
    Sets the state of the LED device

    Args:
        name: A string, the device name
        color: A string representing the color with which to set the fan module status LED
    Returns:
        A boolean, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.LedSetState(name, state)


# THERMAL
def ThermalGetTemp(name):
    '''
    Retrieves current temperature reading from thermal

    Args:
        name: A string, the device name
    Returns:
        A float number of current temperature in Celsius, e.g. 30.1
    '''
    if client is None:
        return None

    return client.ThermalGetTemp(name)


def ThermalGetHighThreshold(name):
    '''
    Retrieves the high threshold temperature of thermal

    Returns:
        A float number, the high threshold temperature of thermal in
        Celsius up to nearest thousandth of one degree Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetHighThreshold(name)


def ThermalGetLowThreshold(name):
    '''
    Retrieves the low threshold temperature of thermal

    Returns:
        A float number, the low threshold temperature of thermal in
        Celsius up to nearest thousandth of one degree Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetLowThreshold(name)


def ThermalSetHighThreshold(name, temperature):
    '''
    Sets the high threshold temperature of thermal

    Args :
        temperature: A float number up to nearest thousandth of one
        degree Celsius, e.g. 30.125
    Returns:
        A boolean, True if threshold is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ThermalSetHighThreshold(name, temperature)


def ThermalSetLowThreshold(name, temperature):
    '''
    Sets the low threshold temperature of thermal

    Args :
        temperature: A float number up to nearest thousandth of one
        degree Celsius, e.g. 30.125
    Returns:
        A boolean, True if threshold is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ThermalSetLowThreshold(name, temperature)


def ThermalGetHighCriticalThreshold(name):
    '''
    Retrieves the high critical threshold temperature of thermal

    Returns:
        A float number, the high critical threshold temperature of
        thermal in Celsius up to nearest thousandth of one degree
        Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetHighCriticalThreshold(name)


def ThermalGetLowCriticalThreshold(name):
    '''
    Retrieves the low critical threshold temperature of thermal

    Returns:
        A float number, the low critical threshold temperature of thermal in Celsius
        up to nearest thousandth of one degree Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetLowCriticalThreshold(name)


def ThermalSetHighCriticalThreshold(name, temperature):
    '''
    Sets the critical high threshold temperature of thermal

    Args :
        temperature: A float number up to nearest thousandth of one degree Celsius,
        e.g. 30.125

    Returns:
        A boolean, True if threshold is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ThermalSetHighCriticalThreshold(name, temperature)


def ThermalSetLowCriticalThreshold(name, temperature):
    '''
    Sets the critical low threshold temperature of thermal

    Args :
        temperature: A float number up to nearest thousandth of one degree Celsius,
        e.g. 30.125

    Returns:
        A boolean, True if threshold is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ThermalSetLowCriticalThreshold(name, temperature)


def ThermalGetMinimumRecorded(name):
    '''
    Retrieves the minimum recorded temperature of thermal

    Returns:
        A float number, the minimum recorded temperature of thermal in Celsius
        up to nearest thousandth of one degree Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetMinimumRecorded(name)


def ThermalGetMaximumRecorded(name):
    '''
    Retrieves the maximum recorded temperature of thermal

    Returns:
        A float number, the maximum recorded temperature of thermal in Celsius
        up to nearest thousandth of one degree Celsius, e.g. 30.125
    '''
    if client is None:
        return None

    return client.ThermalGetMaximumRecorded(name)


# watch dog
def WatchDogArm(index, seconds):
    if client is None:
        return None

    return client.WatchDogArm(index, seconds)


def WatchDogDisrm(index):
    if client is None:
        return None

    return client.WatchDogDisrm(index)


def WatchDogIsArmed(index):
    if client is None:
        return None

    return client.WatchDogIsArmed(index)


# Chassis
def ChassisGetName():
    '''
    Retrieves the model name of the device

    Returns:
        A string, name of the device, None if operation failed
    '''
    if client is None:
        return None

    return client.ChassisGetName()


def ChassisGetModel():
    '''
    Retrieves the model number (or part number) of the device

    Returns:
        A string, model/part number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.ChassisGetModel()


def ChassisGetSerial():
    '''
    Retrieves the serial number of the device

    Returns:
        A string, serial number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.ChassisGetSerial()


def ChassisGetRevision():
    '''
    Retrieves the hardware revision of the device

    Returns:
        A string, revision value of device, None if operation failed
    '''
    if client is None:
        return None

    return client.ChassisGetRevision()


def ChassisGetBaseMac():
    '''
    Retrieves the base MAC address for the chassis

    Returns:
        A string containing the MAC address in the format 'XX:XX:XX:XX:XX:XX'
    '''
    if client is None:
        return None

    return client.ChassisGetBaseMac()


def ChassisGetSlot():
    '''
    Retrieves the physical-slot of this module in the modular chassis.

    Returns:
        An integer, the vendor specific physical slot identifier of this module in the modular-chassis.
    '''
    if client is None:
        return None

    return client.ChassisGetSlot()


def ChassisGetLedState():
    '''
    Gets the state of the system LED

    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.ChassisGetLedState()


def ChassisSetLedState(color):
    '''
    Sets the state of the system LED

    Args:
        color: A string representing the color with which to set the fan module status LED
    Returns:
        A boolean, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ChassisSetLedState(color)


def ChassisGetList():
    '''
    Retrieves the chassis configuration, like platform.json

    Returns:
        A string containing chassis configuration, json format
    '''
    if client is None:
        return None

    return client.ChassisGetList()


def ChassisIsModular():
    '''
    Retrieves whether the sonic instance is part of modular chassis

    Returns:
        A bool value, should return False by default or for fixed-platforms.
        Should return True for supervisor-cards, line-cards etc running as part
        of modular-chassis.
    '''
    if client is None:
        return None

    return client.ChassisIsModular()


def ModuleGetModel(name):
    '''
    Retrieves the firmware version of the component

    Note: the firmware version will be read from HW

    Args:
        name: A string, the device name
    Returns:
        A string containing the firmware version of the component
    '''
    if client is None:
        return None

    return client.ModuleGetModel(name)


def ModuleGetSerial(name):
    '''
    Retrieves the serial number of the device

    Args:
        name: A string, the device name
    Returns:
        A string, serial number of device, None if operation failed
    '''
    if client is None:
        return None

    return client.ModuleGetSerial(name)


def ModuleGetRevision(name):
    '''
    Retrieves the hardware revision of the device

    Args:
        name: A string, the device name
    Returns:
        A string, revision value of device, None if operation failed
    '''
    if client is None:
        return None

    return client.ModuleGetRevision(name)


def ModuleGetBaseMac(name):
    '''
    Retrieves the base MAC address for the chassis

    Args:
        name: A string, the device name
    Returns:
        A string containing the MAC address in the format 'XX:XX:XX:XX:XX:XX'
    '''
    if client is None:
        return None

    return client.ModuleGetBaseMac(name)


def ModuleGetSlot(name):
    '''
    Retrieves the platform vendor's slot number of the module

    Args:
        name: A string, the device name
    Returns:
        An integer, indicating the slot number in the chassis
    '''
    if client is None:
        return None

    return client.ModuleGetSlot(name)


def ModuleGetType(name):
    '''
    Retrieves the type of the module.

    Args:
        name: A string, the device name
    Returns:
        A string, the module-type from one of the predefined types:
        MODULE_TYPE_SUPERVISOR, MODULE_TYPE_LINE or MODULE_TYPE_FABRIC
    '''
    if client is None:
        return None

    return client.ModuleGetType(name)


def ModuleGetStatus(name):
    '''
    Retrieves the operational status of the module

    Args:
        name: A string, the device name
    Returns:
        A string, the operational status of the module from one of the
        predefined status values: MODULE_STATUS_EMPTY, MODULE_STATUS_OFFLINE,
        MODULE_STATUS_FAULT, MODULE_STATUS_PRESENT or MODULE_STATUS_ONLINE
    '''
    if client is None:
        return None

    return client.ModuleGetStatus(name)


def ModuleGetTemp(name):
    '''
    Retrieves current temperature reading from thermal

    Args:
        name: A string, the device name
    Returns:
        A float number of current temperature in Celsius, e.g. 30.1
    '''
    if client is None:
        return None

    return client.ModuleGetTemp(name)


def ModuleGetLedState(name):
    '''
    Gets the state of the module LED

    Returns:
        A string, one of the predefined strings in LedConvert
    '''
    if client is None:
        return None

    return client.ModuleGetLedState(name)


def ModuleSetLedState(name, color):
    '''
    Sets the state of the module status LED

    Args:
        name: A string, the device name
        color: A string representing the color with which to set the module status LED
    Returns:
        A bool, True if status LED state is set successfully, False if not
    '''
    if client is None:
        return None

    return client.ModuleSetLedState(name, color)


def ComponentGetFwVer(name):
    '''
    Retrieves the firmware version of the component

    Note: the firmware version will be read from HW

    Args:
        name: A string, the device name
    Returns:
        A string containing the firmware version of the component
    '''
    if client is None:
        return None

    return client.ComponentGetFwVer(name)