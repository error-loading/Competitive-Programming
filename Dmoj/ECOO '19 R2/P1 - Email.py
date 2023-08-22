for _ in range(10):
    N = int(input())

    arr = set()
    for i in range(N):
        word = input().lower().split("@")


        if "+" in word[0]: word[0] = word[0][:word[0].find("+")]

        if "." in word[0]: arr.add(word[0].replace(".", "") + word[1])
        else: arr.add(word[0] + word[1])
    
    print(len(arr))