def tiling(n, m):
    a = [0 for _ in range(n+1)]
    for i in range(n+1):
        if(i<m):
            a[i] = 1
        elif(i==m):
            a[i] = 2
        else:
            a[i] = a[i-1] + a[i-m]
    return a[n]


test = int(input())
for i in range(test):
    n = int(input())
    m = int(input())
    print(tiling(n, m))