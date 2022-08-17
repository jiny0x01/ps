import math
n = int(input())
fac = str(math.factorial(n))
fac = fac[::-1]
cnt = 0
for i in fac:
    if i != '0': break
    cnt+=1

print(cnt)
