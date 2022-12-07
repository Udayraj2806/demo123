import socket
import os
import sys


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

print("***********SERVER PROGRAM STARTED ***********")
s = socket.socket()
host = socket.gethostname()
#host='127.0.0.1'
port = 12000  # ports after 6000 are free
s.bind((host, port))
s.listen(10)
P = 941
q_alpha=0
for i in range(2, P-1):
    if (generation_alpha(i, P)):
        q_alpha = i
        break
while True:
    c, addr = s.accept()
    print("Client connected", addr)
    print('Got Connection from', addr)
    a = int(input('Enter Your private Key: '))
    x = power(q_alpha, a, P)
    y = int(c.recv(100).decode())
    if not y:
        break
    c.send(str(x).encode())
    ka = power(y, a, P)  # Secret key for Alice
    print('Secret Key of Alice: ', ka)
    break
print("**********SERVER PROGRAM ENDED *************")

# private key - 781
