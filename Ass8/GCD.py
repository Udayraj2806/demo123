


def func(a,b):
    t1 = 0
    t2 = 1
    print('q','a','b','r','t1','t2','t')
    print(0,a,b,0,0,1,0)
    while (b != 0):
        q = a // b
        r = a % b
        a = b
        b = r
        t = t1 - (q * t2)
        t1 = t2
        t2 = t
        print(q,a,b,r,t1,t2,t)
    return a

print("\n\nEnter number whose GCD to be calculated: ")
a=int(input("Enter A: "))
b=int(input("Enter B: "))
print("\n\nGCD of given numbers are: ",func(a, b))

