# https://dmoj.ca/problem/dwite09c1p2
# DWITE '09 R1 #2 - Word Scrambler

def rec(letters, combination = ""):
    if len(letters) == 0:
        print(combination)
        return 0;
    for i in range(len(letters)):
        rec(letters[:i] + letters[i+1:], combination + letters[i])
for i in range(5):
    string = input()
    rec(string)