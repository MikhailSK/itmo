pattern = '010'

for n in range(20):
    cnt = sum(pattern not in format(i, f"0{n}b") for i in range(2 ** n))
    print(f"{n} -> {cnt}")
