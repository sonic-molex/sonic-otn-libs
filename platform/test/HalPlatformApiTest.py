import sys
import _thread
import random
import time

from HalPlatformApi.client import *


def main(argv):
    if not Initialize():
        print('Initialize error.')
        return
    print('Initialize OK')

    #'''
    print('-----------------------Chassis------------------------')
    v = ChassisGetList()
    print('Chassis list:', v)
    v = ChassisGetList()
    print('Chassis list:', v)
    v = ChassisGetModel()
    print('Chassis pn:', v)
    v = ChassisGetSerial()
    print('Chassis sn:', v)
    v = ChassisGetRevision()
    print('Chassis rev:', v)
    v = ChassisGetBaseMac()
    print('Chassis mac:', v)
    v = ChassisGetSlot()
    print('Chassis slot:', v)
    v = ChassisGetLedState()
    print('Chassis LED state:', v)
    #'''

    '''
    print('----------------------LED-------------------------')
    for i in range(0, 7):
        v = LedGetState(i)
        print('LED', i, 'state:', v)
    #'''

    #'''
    print('----------------------Thermal-------------------------')
    names = ['System Exhaust', 'System Board', 'CPU Core 0', 'CPU Core 1', 'CPU Core 2', 'CPU Core 3']
    for name in names:
        v = ThermalGetTemp(name)
        print(name, 'temp:', v)
        v = ThermalGetHighThreshold(name)
        print(name, 'high threshold:', v)
        v = ThermalGetLowThreshold(name)
        print(name, 'low threshold:', v)
        s = random.uniform(0.7, 0.8) * 100
        v = ThermalSetHighThreshold(name, s)
        print(name, 'set high threshold:', v, format(s, '.3f'))
        v = ThermalGetHighThreshold(name)
        print(name, 'high threshold:', v)
        s = random.uniform(-0.1, 0) * 100
        v = ThermalSetLowThreshold(name, s)
        print(name, 'set low threshold:', v, format(s, '.3f'))
        v = ThermalGetLowThreshold(name)
        print(name, 'low threshold:', v)
        v = ThermalGetHighCriticalThreshold(name)
        print(name, 'high critical threshold:', v)
        v = ThermalGetLowCriticalThreshold(name)
        print(name, 'low critical threshold:', v)
        s = random.uniform(0.6, 0.7) * 100
        v = ThermalSetHighCriticalThreshold(name, s)
        print(name, 'set high critical threshold:', v, format(s, '.3f'))
        v = ThermalGetHighCriticalThreshold(name)
        print(name, 'high critical threshold:', v)
        s = random.uniform(0, 0.1) * 100
        v = ThermalSetLowCriticalThreshold(name, s)
        print(name, 'set low critical threshold:', v, format(s, '.3f'))
        v = ThermalGetLowCriticalThreshold(name)
        print(name, 'low critical threshold:', v)
        for i in range(0, 3):
            v = ThermalGetTemp(name)
            print(name, 'temp:', v)
            time.sleep(1)
        v = ThermalGetMinimumRecorded(name)
        print(name, 'minimum recorded:', v)
        v = ThermalGetMaximumRecorded(name)
        print(name, 'maximum recorded:', v)
        print('')
    #'''

    #'''
    print('-----------------------PSU------------------------')
    names = ['PSU0', 'PSU1']
    for name in names:
        print(name, 'name:', name)
        v = PsuGetModel(name)
        print(name, 'model:', v)
        v = PsuGetSerial(name)
        print(name, 'sn:', v)
        v = PsuGetRevision(name)
        print(name, 'rev:', v)
        v = PsuGetPresence(name)
        print(name, 'presence:', v)
        v = PsuGetStatus(name)
        print(name, 'status:', v)
        v = PsuIsReplaceable(name)
        print(name, 'replaceable:', v)
        v = PsuGetVoltage(name)
        print(name, 'voltage:', v)
        v = PsuGetCurrent(name)
        print(name, 'current:', v)
        v = PsuGetPower(name)
        print(name, 'power:', v)
        v = PsuGetTemp(name)
        print(name, 'temperature:', v)
        v = PsuGetInputVoltage(name)
        print(name, 'input voltage:', v)
        v = PsuGetInputCurrent(name)
        print(name, 'input current:', v)
        v = PsuGetLedState(name)
        print(name, 'LED state:', v)
        v = PsuSetLedState(name, 'amber')
        print(name, 'LED set:', v)
        print('')
    #'''

    #'''
    print('---------------------FAN--------------------------')
    names = ['FanTray0-Fan0', 'FanTray0-Fan1', 'FanTray0-Fan2', 'FanTray0-Fan3', 'PSU0-Fan', 'PSU1-Fan']
    for name in names:
        print(name, 'name:', name)
        v = FanGetModel(name)
        print(name, 'model:', v)
        v = FanGetSerial(name)
        print(name, 'sn:', v)
        v = FanGetRevision(name)
        print(name, 'rev:', v)
        v = FanGetPresence(name)
        print(name, 'presence:', v)
        v = FanGetStatus(name)
        print(name, 'status:', v)
        v = FanIsReplaceable(name)
        print(name, 'replaceable:', v)
        v = FanGetDirection(name)
        print(name, 'direction:', v)
        v = FanGetSpeed(name)
        print(name, 'speed:', v)
        v = FanGetTargetSpeed(name)
        print(name, 'target speed:', v)
        spd = random.randint(1, 100)
        v = FanSetSpeed(name, spd)
        print(name, 'set speed', spd, ':', v)
        v = FanGetSpeed(name)
        print(name, 'speed:', v)
        v = FanGetTargetSpeed(name)
        print(name, 'target speed:', v)
        v = FanGetSpeedTolerance(name)
        print(name, 'speed tolerance:', v)
        v = FanGetLedState(name)
        print(name, 'LED state:', v)
        v = FanSetLedState(name, 'amber')
        print(name, 'LED set: ', v)
        v = FanGetPositionInParent(name)
        print(name, 'parent pos: ', v)
        print('')
    #'''

    '''
    print('------------------------EEPROM-----------------------')
    for i in range(0, 1):
        with open('eeprom{}.data'.format(i), 'wb') as f:
            for j in range(0, 1):
                len = 1024
                addr = j * len
                print('read eeprom', i, ',addr ', addr)
                v = EepromRead(i, addr, len)
                f.write(v)
    '''

    #'''
    print('---------------------FAN Drawer--------------------------')
    names = ['FanTray0']
    for name in names:
        print(name, 'name:', name)
        v = FanDrawerGetPresence(name)
        print(name, 'presence:', v)
        v = FanDrawerGetStatus(name)
        print(name, 'status:', v)
        v = FanDrawerIsReplaceable(name)
        print(name, 'replaceable:', v)
        v = FanDrawerGetLedState(name)
        print(name, 'LED state:', v)
        v = FanDrawerSetLedState(name, 'amber')
        print(name, 'LED set: ', v)
    #'''

    #'''
    print('----------------------Module-------------------------')
    names = ['LINE-CARD0', 'LINE-CARD1', 'LINE-CARD2', 'LINE-CARD3', 'SUPERVISOR0']
    for name in names:
        v = ModuleGetSlot(name)
        print(name, 'slot:', v)
        v = ModuleGetModel(name)
        print(name, 'model:', v)
        v = ModuleGetSerial(name)
        print(name, 'sn:', v)
        v = ModuleGetRevision(name)
        print(name, 'rev:', v)
        v = ModuleGetBaseMac(name)
        print(name, 'mac:', v)
        v = ModuleGetType(name)
        print(name, 'type:', v)
        v = ModuleGetStatus(name)
        print(name, 'status:', v)
        v = ModuleGetTemp(name)
        print(name, 'temp:', v)
        v = ModuleGetLedState(name)
        print(name, 'LED state:', v)
        print('')
    #'''

    #'''
    print('----------------------Conponent-------------------------')
    names = ['BIOS', 'FPGA', 'CPLD', 'ONIE', 'OPS0-0', 'OA1-0', 'OA1-1', 'OCM1-0',
            'OTDR1-0', 'OA2-0', 'OA2-1', 'OCM2-0', 'OTDR2-0', 'MUX3-0']
    for name in names:
        v = ComponentGetFwVer(name)
        print(name, 'firmware ver:', v)
    #'''

    Destroy()


if __name__ == '__main__':
    main(sys.argv)