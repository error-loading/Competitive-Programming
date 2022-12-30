# https://dmoj.ca/problem/ccc21j3
# CCC '21 J3 - Secret Instructions

previous=""
while True:
    n = input()
    sum = int(n[0])+int(n[1])
    if int(n)==99999:
        break
    preDirection = ""
    if sum==0:
        preDirection=previous
    elif sum%2==1:
        preDirection = "left"
    elif sum%2==0:
        preDirection = "right"
    print(preDirection + " " + n[2:])
    previous=preDirection