a = []
b = [1, 1]

for i in range(len(b), 100):
    b.append(b[-1] + 1)

for i in range(100):
    a.append(b[i] if i < 5 else b[i] + a[i - 5])

print(a)
