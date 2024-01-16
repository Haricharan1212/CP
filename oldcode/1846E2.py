import math

t = int(input())

done = set()

num = int(1e6 + 1)
for k in range(1, num):
    s = 1 + k
    curr = k

    while (True):
        curr *= k
        s += curr
        done.add(s)

        if (s > 1e18): break

while (t):
    t -= 1

    n = int(input())
    print(n)



