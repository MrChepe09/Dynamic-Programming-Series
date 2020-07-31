def equalsum(n, arr, s):
    dp = [[0 for _ in range(s+1)] for _ in range(n+1)]

    for i in range(n+1):
        for j in range(s+1):
            if(i==0):
                dp[i][j] = False
            elif(j==0):
                dp[i][j] = True
            elif(arr[i-1]<=j):
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][s]


arr = list(map(int, input().split()))
if(sum(arr)%2==1):
    print(False)
else:
    s = sum(arr)//2
    print(equalsum(len(arr), arr, s))