# https://dmoj.ca/problem/ccc96s3
# CCC '96 S3 - Pattern Generator

m = int(input())

def bits(curPattern, numDigits, numOnes):
    if numDigits == 0:
        if numOnes == 0:
            print(curPattern)
        return

    if numDigits < numOnes:
        return

    if numOnes != 0:
        bits(curPattern + '1', numDigits -1, numOnes - 1)
    bits(curPattern + '0', numDigits - 1, numOnes)
    
    return


for i in range(m):
    n, k = map(int, input().split())
    print("The bit patterns are")
    bits('', n, k)
    if i != m-1:
        print("")