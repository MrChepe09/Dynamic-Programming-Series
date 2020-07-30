# n*n floor with 1*4 tile
def tile(n):
    a = [0 for _ in range(n+1)]
    for i in range(1, n+1):
        if(i<=3):
            a[i] = 1
        elif(i==4):
            a[i] = 2
        else:
            a[i] = a[i-1] + a[i-4]
    return a[n]


test = int(input())
for i in range(test):
    n = int(input())
    print(tile(n))