def mincoins(n, coins, sumi):
    dp = [[0 for _ in range(sumi+1)] for _ in range(n+1)]

    for i in range(n+1):
        for j in range(sumi+1):
            if(i==0):
                dp[i][j] = float('inf')-1  
            if(j==0):
                dp[i][j] = 0
            if(i==1):
                if(j%coins[i-1]==0):
                    dp[i][j] = j//coins[i-1]
                else:
                    dp[i][j] = float('inf')-1
            elif(coins[i-1]<=j):
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][sumi] 

test = int(input())
for i in range(test):
    n = int(input())
    coins = list(map(int, input().split()))
    sumi = int(input())
    print(mincoins(n, coins, sumi))