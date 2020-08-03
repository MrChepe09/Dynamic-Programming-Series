def unbound(n, w, v, W):
    dp = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(W+1):
            if(i==0 or j==0):
                dp[i][j] = 0
            elif(w[i-1]<=j):
                dp[i][j] = max(v[i-1] + dp[i][j-w[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][W]


test = int(input())
for i in range(test):
    n = int(input())
    w = list(map(int, input().split()))
    v = list(map(int, input().split()))
    W = int(input())
    print(unbound(n, w, v, W))


