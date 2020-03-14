a, b, v = [ int(i) for i in input().split()]

if v < a:
    print(1)
else:
    print(int((v-b-1)/(a-b) + 1))
    