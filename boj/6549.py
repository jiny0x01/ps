import sys

def initList(size = 123123):
    lst = []
    for i in range(size):
        lst.append(0)
    return lst

def getRect(heights) :
    n = len(heights)
    s = [[-1,0]]
    left = initList()
    right = initList()
    heights.insert(0,0)
    
    for i in range(1, n):
        if len(s) > 0:
            while s[len(s)-1][0] >= heights[i]:
                s.pop()
        left[i] = s[len(s)-1][1]
        s.append([heights[i], i])
    
    while len(s) > 0:
        s.pop()
    s.append([-1, n+1])
    
    for i in range(n, 1, -1):
        if len(s) > 0:
            while s[len(s)-1][0] >= heights[i]:
                s.pop()
        right[i] = s[len(s)-1][1]
        s.append([heights[i], i])

    answer = 0
    for i in range(1, n):
        num = heights[i] * (right[i] - left[i] - 1)
       # print("left:%d right:%d, num:%d" %(left[i], right[i], num))
        if answer < num:
            answer = num
 #   print(num)
    return answer

def main():
    while True:
        nums = list(input().split())
        print(nums)
        if len(nums) == 0:
            break
    

if __name__ == "__main__":
    main()


