def distance(n):
    a = [0 for _ in range(n+1)]
    a[0] = 1
    a[1] = 1
    a[2] = 2
    for i in range(3, n+1):
        a[i] = a[i-1]+a[i-2]+a[i-3]
    return a[n]

test = int(input())
for i in range(test):
    n = int(input())
    print(distance(n))