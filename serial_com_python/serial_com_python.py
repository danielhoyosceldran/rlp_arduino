# si no chuta, pot caler instalar:
# pip install pyserial

import serial
import serial.tools.list_ports


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
    action = input("action: ")
    if (action == "write" or action == "w" or action == "WRITE"):
        command1 = input("shoulder: ")
        command2 = input("elbow: ")
        command = command1 + command2
        s.write(command.encode('utf-8'))
    elif action == 'exit' or action == 'EXIT' or action == "q":
        s.close() # so important.
        exit()