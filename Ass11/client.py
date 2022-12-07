import socket
import os


def power(a, b, P):
	if (b == 1):
		return a

	else:
		return ((pow(a, b)) % P)


def generation_alpha(i, P):
    l = []
    for j in range(2, P-1):
        c1 = power(i, j, P)
        if l.count(c1) == 1:
            return False
        l.append(c1)
    return True


print("************CLIENT PROGRAM STARTED ******************")
s = socket.socket()
host = socket.gethostname()  # server hostname
#host='127.0.0.1'
port = 12000  # same as server
s.connect((host, port))
print("Connected to : ", host, port)
# fileToSend = open("ToSend.txt","r")
# content = fileToSend.read()
P = 941
q_alpha=0
for i in range(2, P-1):
    if (generation_alpha(i, P)):
        q_alpha = i
        break
b = int(input('Enter Your private Key: '))
y = power(q_alpha, b, P)
s.send(str(y).encode())
x = int(s.recv(100).decode())
kb = power(x, b, P)
print('Secret Key of Bob: ', kb)
print("************CLIENT PROGRAM ENDED ******************")

# private key - 347
