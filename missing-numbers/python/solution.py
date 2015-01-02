#!/usr/bin/python3

def missingNumbers(A, B):
    if len(A) == len(B):
        return []
    
    maximum = 0
    minimum = 99999

    for n in B:
        if n > maximum:
            maximum = n
        if n < minimum:
            minimum = n

    t = [0] *  ((maximum - minimum) + 1)
    for n in B:
        t[n % minimum] += 1

    for n in A:
        t[n % minimum] -= 1

    out = []
    for i,v in enumerate(t):
        if v > 0:
            out.append(i + minimum)

    return out



Alen = input()
A = [int(i) for i in input().strip().split(" ")]

Blen = input()
B = [int(i) for i in input().strip().split(" ")]

out = missingNumbers(A,B)
s = ""

for n in out:
    s += "{0} ".format(n)

print(s)
