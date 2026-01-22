import serial
import time
import os

f=""
def readserial(comport, baudrate, timestamp=False):

    ser = serial.Serial(comport, baudrate, timeout=0.1)         # 1/timeout is the frequency at which the port is read

    while True:
        
        data = ser.readline().decode().strip()

        if data and timestamp:
            f = open("assets/data1.csv", "a")
            timestamp = time.strftime('%Y-%m-%d %H:%M')
            f.write(timestamp+","+data+"\n")
            f.close()
            os._exit(0)
            #print(f'{timestamp} > {data}')
        


if __name__ == '__main__':

    readserial('/dev/cu.usbmodem48CA435FA7AC2', 9600, True)  