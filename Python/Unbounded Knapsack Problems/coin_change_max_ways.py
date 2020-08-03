def coinways(n, coins, sumi):
    dp = [[0 for _ in range(sumi+1)] for _ in range(n+1)]

    for i in range(n+1):
        for j in range(sumi+1):
            if(i==0):
                dp[i][j] = 0
            if(j==0):
                dp[i][j] = 1
            elif(coins[i-1]<=j):
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][sumi] 

test = int(input())
for i in range(test):
    n = int(input())
    coins = list(map(int, input().split()))
    sumi = int(input())
    print(coinways(n, coins, sumi))