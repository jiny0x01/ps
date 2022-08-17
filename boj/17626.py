import math
def find(num, dp):
    r = 0
    i = 1
    while i**i <= num:
        if dp[i] == 0:
            dp[i] = i**i
            r = i
        i+=1
    print(r)
    return r

num = int(input())
print(num)


dp = [0] * 50000 
cnt = 0

answer = []
'''
while num > 0:
    t = math.floor(math.sqrt(num) + 1) 
    print("num:%d, t:%d" % (num,t))
    r = find(t, dp)  
    num -= r
    answer.append(r)
    print("r:%d" %(r))
'''

while num > 0:
    t = int(math.sqrt(num))
    print(t*t)
    
    if t * t > num:
        t-=1
    answer.append(t)
    num -= t*t
print(answer)
