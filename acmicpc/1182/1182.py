import sys
input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

result = 0
def countcount(sumsum, idx):
    global result
    if idx >= n:
        return
    sumsum += arr[idx]
    if sumsum == s:
        result += 1
    countcount(sumsum, idx+1)
    countcount(sumsum-arr[idx], idx+1)
    
countcount(0, 0)

print(result)

