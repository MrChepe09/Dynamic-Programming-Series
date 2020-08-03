def rodcutting(n, length, price):
    dp = [[0 for _ in range(n+1)] for _ in range(len(price)+1)]

    for i in range(len(price)+1):
        for j in range(n+1):
            if(i == 0 or j == 0):
                dp[i][j] = 0
            elif(length[i-1]<=j):
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[len(price)][n]        


test = int(input())
for i in range(test):
    n = int(input())
    length = list(map(int, input().split()))
    price = list(map(int, input().split()))
    print(rodcutting(n, length, price))


