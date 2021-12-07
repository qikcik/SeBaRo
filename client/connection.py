import serial
import time

import setup

class Connection:
    def __init__(self):
        self.arduino = serial.Serial(port=setup.PORT, baudrate=setup.BOUNDRATE, timeout=0.05)

    def read(self):
        line = self.arduino.readline().decode()

        if line:
            print(line)
            return line.split(" ")

    def send(self, x):
        print(x)
        self.arduino.write(bytes(x, 'utf-8'))

