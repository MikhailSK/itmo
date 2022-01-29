g = [1]

for n in range(1, 10):
    g.append(sum(i * g[n - i] for i in range(1, n + 1)))

print(g)
