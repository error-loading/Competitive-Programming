# https://dmoj.ca/problem/ccc22j3
# CCC '22 J3 - Harp Tuning

alph = "ABCDEFGHIJKLMNOPQRST"
string = input()
lst = []
newLst = []
for i in range(len(string)):
    if string[i] == '+':
        newLst.append(" tighten ")
    elif string[i] == "-":
        newLst.append(" loosen ")
    elif string[i] in alph:
        newLst.append(string[i])
    else:
        if i+1 == len(string) or string[i+1] in alph:
            lst.append("".join(newLst)+""+string[i])
            newLst = []
        else:
            newLst.append(string[i])
for i in lst:
    print(i)