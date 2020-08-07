def lcs(a, b):
    m = len(a)
    n = len(b)
    dp = [[None for _ in range(n+1)] for _ in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if(i==0 or j==0):
                dp[i][j] = 0
            elif(a[i-1] == b[j-1]):
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp

def printscs(a, b):
    dp = lcs(a, b)
    res = []
    i = len(a)
    j = len(b)
    while(i > 0 and j > 0):
        if(a[i-1] == b[j-1]):
            res.append(a[i-1])
            i, j = i-1, j-1
        else:
            if(dp[i-1][j]>dp[i][j-1]):
                res.append(a[i-1])
                i, j = i-1, j
            else:
                res.append(b[j-1])
                i, j = i, j-1
    while(i>0):
        res.append(a[i-1])
        i -= 1
    while(j>0):
        res.append(b[j-1])
        j-=1
    
    res.reverse()
    return ''.join(res)

test = int(input())
for i in range(test):
    a = input()
    b = input()
    print(printscs(a, b))