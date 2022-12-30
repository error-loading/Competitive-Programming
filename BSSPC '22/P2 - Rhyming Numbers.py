# https://dmoj.ca/problem/bsspc22c1p2
# BSSPC '22 P2 - Rhyming Numbers

n = int(input())
for i in range(n):
    x, y = map(str, input().split())

    if x[-1] == "7":
        if len(x) > 1 and x[-2] == "1":
            print("NO")
        elif y[-2:] == "11":
            print("YES")
        else:
            print("NO")
    elif y[-1] == "7":
        if len(y) > 1 and y[-2] == "1":
            print("NO")
        elif x[-2:] == "11":
            print("YES")
        else:
            print("NO")
    else:
        print("NO")