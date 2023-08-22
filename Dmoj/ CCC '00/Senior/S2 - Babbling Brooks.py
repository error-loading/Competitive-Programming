N = int(input())
arr = [int(input()) for i in range(N)]

smth = int(input())

while smth != 77:
    if smth == 88:
        ind = int(input()) - 1
        arr = arr[:ind] + [arr[ind + 1] + arr[ind]] + arr[(ind + 2):]
    
    else:
        ind = int(input()) - 1
        perc = int(input())

        arr = arr[:ind] + [round(arr[ind] * perc / 100, 0), round(arr[ind] * (100 - perc) / 100, 0)] + arr[(ind + 1):]
    
    smth = int(input())

print(*arr)