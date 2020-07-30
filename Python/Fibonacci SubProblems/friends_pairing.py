def friends(n):
    a = [0 for _ in range(n+1)]
    for i in range(n+1):
        if(i<=2):
            a[i] = i
        else:
            a[i] = a[i-1] + (i-1)*a[i-2]

    return a[n]

test = int(input())
for i in range(test):
    n = int(input())
    print(friends(n))