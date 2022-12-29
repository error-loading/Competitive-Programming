# https://dmoj.ca/problem/ccc21j4
# CCC '21 J4 - Arranging Books


books = input()
l = books.count("L")
m = books.count("M")
lSect = books[:l]
mSect = books[l:m+l]
sSect = books[l+m:]

wrongL  = 0
wrongM = 0
lm = 0
ml = 0

for i in lSect:
    if i == "M":
        wrongL+=1
        lm+=1
    elif i =="S":
        wrongL+=1

for i in mSect:
    if i == "L":
        ml+=1
        wrongM+=1
    elif i =="S":
        wrongM+=1

print(wrongL+wrongM - min(lm, ml))
