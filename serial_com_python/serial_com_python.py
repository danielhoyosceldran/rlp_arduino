# si no chuta, pot caler instalar:
# pip install pyserial

import serial
import time

s = serial.Serial()
s.baundrate = 96000
s.port = 'COM3'
s.open()

while True:
    command = '21348'
    print(type(command))
    s.write(command.encode('utf-8'))
    if command == 'exit':
        s.close()
        exit()
    input("command: ")
