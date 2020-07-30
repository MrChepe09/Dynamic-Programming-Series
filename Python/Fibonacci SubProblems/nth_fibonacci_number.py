def nthfibonacci(n):
    a = [0 for _ in range(n+1)]
    a[0] = 0
    a[1] = 1
    for i in range(2, n+1):
        a[i] = a[i-1]+a[i-2]
    return a[n]

test = int(input())
for i in range(test):
    n = int(input())
    print(nthfibonacci(n))