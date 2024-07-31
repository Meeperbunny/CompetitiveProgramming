import sys
import math

# Uncomment this for debugging
# def dbg(*args):
#     print('[{}:{}] ({}):'.format(__file__, sys._getframe().f_lineno, ', '.join(map(str, args))), *args)

def ops_to_get_to(tar, a, b):
    numat = 0
    numops = 0
    for i in range(len(a)):
        numops += max(0, (a[i] + b[i] - 1 - tar) // b[i])
        if (a[i] + b[i] - 1 - tar) // b[i] >= 0:
            if (a[i] - tar) % b[i] == 0:
                numat += 1
    return numops, numat

def tc(n, k, a, b, ans):
    me = max(a) + 1
    men = -1

    ta = me
    while ta >= 1:
        while True:
            res = ops_to_get_to(men + ta, a, b)
            oc, at = res
            if oc > k:
                men += ta
            elif oc + at < k:
                break
            else:
                tot = 0
                tn = men + ta
                tind = k - oc
                tot += tind * tn
                for i in range(n):
                    oc = max(0, (a[i] + b[i] - 1 - tn) // b[i])
                    tadd = max(0, a[i] * oc - (oc * (oc - 1)) // 2 * b[i])
                    tot += tadd
                print(tot)
                return
        ta >>= 1

    tot = 0
    tn = 0
    for i in range(n):
        oc = max(0, (a[i] + b[i] - 1 - tn) // b[i])
        tadd = max(0, a[i] * oc - (oc * (oc - 1)) // 2 * b[i])
        tot += tadd
    print(tot)

if __name__ == "__main__":
    T = int(input().strip())
    for _ in range(T):
        n, k = map(int, input().strip().split())
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        tc(n, k, a, b, 0)
