# https://dmoj.ca/problem/ecoo21p2
# ECOO '21 P2 - DNA Derren
import sys
input = sys.stdin.readline

dna = input().strip()

newStr = dna[0]

for i in range(1,len(dna)):
    if (dna[i] == "A" or dna[i-1] == "A") and dna[i] != dna[i-1]:
        newStr += dna[i]
    
    else:
        newStr += " " + dna[i]

print(newStr)
        
