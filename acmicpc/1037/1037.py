
measure_num = int(input())
real_measure = [ int(i) for i in input().split() ]
real_measure.sort()
print(real_measure[0] * real_measure[-1])