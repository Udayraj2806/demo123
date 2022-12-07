

def Mod_Inv( a, b):
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
    if (t1 < 0):
        t1 = t1 + b
    return t1


print("\n\nTo finnd Modulo multiplicative inverse of a under  mod b")
a=int(input("Enter A: "))
b=int(input("Enter B: "))
print("\n\nModulo Multiplicative Inver of a under mod b is:  ",Mod_Inv(a, b))

