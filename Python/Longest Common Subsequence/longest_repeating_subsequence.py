def repeatsubseq(a):
    m = len(a)
    dp = [[0 for _ in range(m+1)] for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, m+1):
            if(a[i-1] == a[j-1] and i != j):
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][m]

test = int(input())
for i in range(test):
    a = input()
    print(repeatsubseq(a))