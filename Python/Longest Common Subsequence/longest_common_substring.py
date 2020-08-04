def substring(a, b):
    m = len(a)
    n = len(b)
    dp = [[None for _ in range(n+1)] for _ in range(m+1)]
    result = 0

    for i in range(m+1):
        for j in range(n+1):
            if(i==0 or j==0):
                dp[i][j] = 0
            elif(a[i-1] == b[j-1]):
                dp[i][j] = dp[i-1][j-1] + 1
                result = max(result, dp[i][j])
            else:
                dp[i][j] = 0
    return result

test = int(input())
for i in range(test):
    a = input()
    b = input()
    print(substring(a, b))