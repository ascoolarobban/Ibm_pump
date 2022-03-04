from tinydb import TinyDB , Query
from serialArduino import *
db = TinyDB('database.json')

table = db.table('pump')
q = Query()

pumpState = 0
newPumpState = 0

def getFieldData():
    result = [r['pumpStatus'] for r in db]
    status = result[0]
    global pumpState
    pumpState= status
    return status



def set_pumpState():
    global pumpState
    global newPumpState
    if pumpState != newPumpState:
        newPumpState = pumpState
        return True

def send_on_pumpStatus():
    if set_pumpState() == True:
        arduino_control('A')
        print("A")


def updateDb():
    result = [r['pumpStatus'] for r in db]
    status = result[0]
    if status == 1:
        db.update({'pumpStatus': 0})
    else:
        db.update({'pumpStatus': 1})

#INCASE NEED TO PRINT PORTS
import serial.tools.list_ports as ports
# com_ports = list(ports.comports())  # create a list of com ports
# for i in com_ports:
#     print(i.device)  # returns 'COMx'

while True:
    getFieldData()
    send_on_pumpStatus()
    readFromArduino()



