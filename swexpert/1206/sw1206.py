
def look_around(colums, i):
    local_max = max(colums[i-2:i] + colums[i+1:i+3])
    sub = colums[i] - local_max
    if sub <= 0:
        return 0
    else:
        return sub

for j in range(10):
    t = int(input())
    colums = [ int(i) for i in input().split() ]
    
    result = 0
    for i in range(2, t-2):
        result += look_around(colums, i)
    print("#{} {}".format(j+1, result))