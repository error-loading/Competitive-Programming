# https://dmoj.ca/problem/p171ex6a
# BlueBook - Max

t = int(input())

maxS = -10000000

for i in range(t):
    x = float(input())
    maxS = max(x, maxS)
print("%.4f" % maxS)
