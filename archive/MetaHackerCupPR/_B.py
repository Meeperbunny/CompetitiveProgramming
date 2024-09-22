import decimal, math
from decimal import Decimal, getcontext
getcontext().prec = 30

with open('file.in', 'r') as fin, open('file.out', 'w') as fout:
    T = int(fin.readline())
    for t in range(T):
        fout.write(f"Case #{t + 1}: ")
        minc = Decimal(0.000000000000000001)
        k = Decimal(0)
        n, p = [Decimal(int(e)) for e in fin.readline().strip().split()]
        p /= 100
        
        binc = Decimal(1)
        while binc >= minc:
            while True:
                if (p + k + binc) ** n < p ** (n - 1):
                    k += binc
                else:
                    break
            binc /= 2
        
        fout.write(f"{k * 100:.12f}\n")
