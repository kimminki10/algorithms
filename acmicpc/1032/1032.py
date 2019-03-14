
t = int(input())
sequences = [ input() for _ in range(t) ]

result = ""
for i in range(len(sequences[0])):
    tmp = sequences[0][i]
    for j in range(t):
        if sequences[j][i] is not tmp:
            tmp = "?"
            break
    result += tmp

print(result)