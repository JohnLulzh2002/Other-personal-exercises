import serial
ser = serial.Serial('COM4')
print(ser.name)
try:
    count=1
    while 1:
        print('['+str(count) + ']: ' + ser.readline().decode('utf-8')[:-2])
        count = count+1
except KeyboardInterrupt:
    ser.close()
    print('[End]')