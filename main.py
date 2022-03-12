from __future__ import print_function, unicode_literals
from PyInquirer import prompt, print_json
import serial
questions = [
    {
        'name':'Val',
        'type':'confirm',
        'message':'Do you love fish fingers'
    },
    {
        'type': 'list',
        'name': 'first_name',
        'message': 'What is the siomgus gonna do?',
        'choices': ["Forward","Backwards","Left","Right","Stop","Backtrack","Pong","Capture"]
    }
]

answers = prompt(questions)
print()  # use the answers as input for your app


comm = {"Forward":"2672ffba658ea5ca 8 7d303b53125fa3d5 64726177726f46 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Backwards":"2672ffba658ea5ca a f58b4caf7dfb8e24 647261776b636142 73 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Left":"2672ffba658ea5ca 5 1626ad01693aa7d6 7466654c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Pong":"2672ffba658ea5ca 5 58c3c8b04570e396 676e6f50 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Stop":"2672ffba658ea5ca 6 556133595cdc0d60 7468676952 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Capture":"2672ffba658ea5ca 8 a7df9b152844dd77 65727574706143 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
        "Backtrack":"2672ffba658ea5ca 9 d58970f320ef0d6f 6b63616261746144 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
        }
ser = serial.Serial('/dev/ttyUSB0', 9600)
k = "AT+TEST=TXLRSTR, \""+comm[answers["first_name"]]+"\""

ser.write(bytes(k,'utf-8'))
k = ser.readline()

data3 = ser.readline()
datainf = ser.readline()
data = ser.readline()
data4 = ser.readline()
ser.write(b"AT+TEST=RXLRPKT\r\n")
data5 = ser.readline()
#data6 = ser.readline()
print(data3,'\n',k,'\n',datainf,'\n',data,'\n',data4,'\n',data5,'\n',data6)