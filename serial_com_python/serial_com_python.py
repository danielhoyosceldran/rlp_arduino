# si no chuta, pot caler instalar:
# pip install pyserial

import serial
import serial.tools.list_ports
import sympy as sp   # library for symbolic calculation
import numpy as np
from sympy import *

def calcula(p): # Calculate IK function
    eq1 = 0.3 * cos(theta1) + 0.3 * cos(theta1 + theta2) - p[0]
    eq2 = 0.3 * sin(theta1) + 0.3 * sin(theta1 + theta2) - p[1]
    q = nsolve((eq1,eq2),(theta1,theta2),(1,1))
    return q

s = serial.Serial()
s.baundrate = 96000

# choose port
ports = serial.tools.list_ports.comports()

if ports:
    print("Ports serial disponibles:")
    for port in ports:
        print(f"- {port.device}: {port.description}")
else:
    print("No s'han trobat ports serial disponibles.")

s.port = input("Port: ")

# start communication
s.open()

while True:
    command = input()
    s.write(command.encode('utf-8'))
    if command == 'exit' or command == 'EXIT':
        s.close() # so important.
        exit()