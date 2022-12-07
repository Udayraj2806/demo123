def Mod_Inv(a, b):
    t1 = 0
    t2 = 1
    c = b
    d = a
    while (b != 0):
        q = a // b
        r = a % b
        a = b
        b = r
        t = t1 - (q * t2)
        t1 = t2
        t2 = t
    if (t1 < 0):
        t1 = t1 + d
    return t1


def findMinX(num, rem, k):
    prod = 1
    for i in range(0, k):
        prod = prod * num[i]
    print(prod)
    result = 0

    for i in range(0, k):
        pp = prod // num[i]
        result = result + rem[i] * Mod_Inv(pp, num[i]) * pp

    return result % prod


# num = [25, 4]
# rem = [129934811447123020117172145698449, 129934811447123020117172145698449]
# x = 129934811447123020117172145698449(mod 25)
# x = 129934811447123020117172145698449(mod 4)
n = int(input("Enter n: "))
rem = []

num = list(map(int, input("Enter nums : ").strip().split()))[:n]
rem = list(map(int, input("Enter rems : ").strip().split()))[:n]

print("x is", findMinX(num, rem, n))
