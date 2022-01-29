solns = {
    16: [
        [1, -2, 3, -4],
        lambda a, n: 2 * a[n - 2] - a[n - 4]
    ],
    17: [
        [0, 1, 8, 27],
        lambda a, n: 4 * a[n - 1] - 6 * a[n - 2] + 4 * a[n - 3] - a[n - 4]
    ],
    18: [
        [1, 4],
        lambda a, n: 4 * a[n - 1] - 4 * a[n - 2]
    ],
    19: [
        [2, 5],
        lambda a, n: 5 * a[n - 1] - 6 * a[n - 2]
    ],
    20: [
        [1, 1, 4],
        lambda a, n: 2 * a[n - 1] + 2 * a[n - 2] - a[n - 3]
    ],
    21: [
        [1, 1, 1],
        lambda a, n: a[n - 1] + a[n - 2] + a[n - 3]
    ],
    22: [
        [1, 1, 1],
        lambda a, n: a[n - 1] - 2 * a[n - 3]
    ],
    23: [
        [1, 2, 4],
        lambda a, n: 2 * a[n - 1] - a[n - 3]
    ],
    24: [
        [1, 3],
        lambda a, n: 3 * a[n - 1] - a[n - 2]
    ],
    25: [
        [1, 4, 12],
        lambda a, n: 4 * a[n - 1] - 4 * a[n - 2] + a[n - 3]
    ],
    27: [
        [1, 2, 4],
        lambda a, n: a[n - 1] + a[n - 2] + a[n - 3]
    ],
    28: [
        [1, 2, 4],
        lambda a, n: 2 * a[n - 1] - a[n - 2] + a[n - 3]
    ],
    30: [
        [1, 1, 2, 3, 5],
        lambda a, n: a[n - 1] + a[n - 2] + a[n - 5]
    ]
}

for task, soln in solns.items():
    a, f = soln
    for i in range(len(a), 10):
        a.append(f(a, i))
    print(f"{task} => {a}")
