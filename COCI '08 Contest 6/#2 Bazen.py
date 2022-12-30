# https://dmoj.ca/problem/coci08c6p2
# COCI '08 Contest 6 #2 Bazen

x1, y1 = map(int, input().split())

if x1 == 0 and y1 == 0:
    print("125.00 125.00")

elif x1 == 0:
    if y1 > 125:
        x2 = 31250/y1 * 1.0
        print(str("{:.2f}".format(round(x2, 2))), str("0.00"))

    else:
        x2 = 31250 / (250-y1) * 1.0
        print(str("{:.2f}".format(round(x2, 2))), str("{:.2f}".format(round(250-x2, 2))))

elif y1 == 0:
    if x1 > 125:
        y2 = 31250/x1 * 1.0
        print(str("0.00"), str("{:.2f}".format(round(y2, 2))))

    else:
        y2 = 31250 / (250-x1) * 1.0
        print(str(r"{:.2f}".format(round(250-y2, 2))), str("{:.2f}".format(round(y2, 2))))

elif y1 !=0 and x1 != 0:
    if y1 > 125: # Y2 = 0
        y2 = (31250/y1 - 250) * -1 * 1.0
        print(str("{:.2f}".format(round(y2, 2))), str("0.00"))

    else:
        y2 = (-31250/x1 + 250)
        print(str("0.00"), str("{:.2f}".format(round(y2, 2))))
