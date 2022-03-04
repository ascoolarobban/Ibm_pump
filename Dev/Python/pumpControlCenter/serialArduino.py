import pyfirmata
import serial
import time
board = "/dev/ttyACM0"
arduino = serial.Serial(port=board, baudrate=9200, timeout=.1)



def arduino_control(command):
        arduino.write(bytes(command, 'utf-8'))
        time.sleep(0.05)

#not gonna use this one bc safety
def readFromArduino():
        data = arduino.readline()
        return data

