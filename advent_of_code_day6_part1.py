from collections import defaultdict

P = defaultdict(list)

score = 0
with open('in.txt', 'r') as file:
    for line in file:
        words = line.split()
        for i, word in enumerate(words):
            try:
                P[i].append(int(word))
            except:
                P[i].append(word)


for k in P:
    op = P[k][-1]
    #print(op)
    if op == '+':
        score += sum(P[k][:-1])
    elif op == '*':
        res = 1
        for v in P[k][:-1]:
            res *= v    
        score += res

print(score)
