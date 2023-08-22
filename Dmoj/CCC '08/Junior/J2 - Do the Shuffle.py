B = int(input())
N = int(input())

string = "ABCDE"

while B != 4:
    for i in range(N):
        if B == 1:
            string = string[1:] + string[0]
        
        elif B == 2:
            string = string[-1] + string[:-1]
        
        else:
            string = string[1] + string[0] + string[2:]
        
    B = int(input())
    N = int(input())

print(*list(string))