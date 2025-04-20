from itertools import permutations
with open("t.out", "w") as f:
    k = 3
    s = "P" * k + "B" * k
    for p in set(permutations(s)):
        print(p)