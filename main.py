from __future__ import print_function, unicode_literals
from PyInquirer import prompt, print_json
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)
ser.write(b"AT+MODE=TEST\r\n")
ser.write(b"AT+TEST=RFCFG, 868.100, SF7, 125, 8, 8, 14, ON, OFF, OFF\r\n")

comm = {"Forward":"2672ffba658ea5ca 8 7d303b53125fa3d5 64726177726f46 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Backwards":"2672ffba658ea5ca a f58b4caf7dfb8e24 647261776b636142 73 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Left":"2672ffba658ea5ca 5 1626ad01693aa7d6 7466654c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Pong":"2672ffba658ea5ca 5 58c3c8b04570e396 676e6f50 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Stop":"2672ffba658ea5ca 6 556133595cdc0d60 7468676952 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Capture":"2672ffba658ea5ca 8 a7df9b152844dd77 65727574706143 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "Backtrack":"2672ffba658ea5ca 9 d58970f320ef0d6f 6b63616261746144 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
            }

question0 = [
    {
        'name':'Val',
        'type':'confirm',
        'message':'Do you love fish fingers'
    }
]
question1 = [
    {
        'type': 'list',
        'name': 'command',
        'message': 'What is the siomgus gonna do?',
        'choices': ["Forward","Backwards","Left","Right","Stop","Backtrack","Pong","Capture","Other"]
        #add right
    }
]
question3 = [
    {
        "type":"text",
        "name":"Stack",
        "message":"Stack commands"
    }
]

answers = prompt(question0)
if(answers["Val"]):
    answers = prompt(question1)
    if(answers["command"] == 'Other'):
        answers = prompt(question3)
        list_lett = list(answers["Stack"])
        #for i in list_lett:
            


    k = "AT+TEST=TXLRSTR, \""+comm[answers["command"]]+"\"\r"

    ser.write(bytes(k,'utf-8'))
    k = ser.readline()
#data3 = ser.readline()
#print(k,""",data3""")
#datainf = ser.readline()
#data = ser.readline()
#data4 = ser.readline()
#ser.write(b"AT+TEST=RXLRPKT\r\n")
#data5 = ser.readline()
#data6 = ser.readline()
#print(data3,'\n',k,'\n',datainf,'\n',data,'\n',data4,'\n',data5,'\n',data6)