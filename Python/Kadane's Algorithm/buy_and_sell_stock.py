def buysell(n, a):
    if(n==0):
        return 0
    diff = [0]*n
    
    for i in range(1, n):
        diff[i] = a[i]-a[i-1]

    for i in range(1, n):
        diff[i] = max(diff[i]+diff[i-1], diff[i])
    return max(diff)

test = int(input())
for i in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    print(buysell(n, a))
