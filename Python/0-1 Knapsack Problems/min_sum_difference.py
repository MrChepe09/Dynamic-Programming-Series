def subset(n, arr, s):
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
    return dp[-1]

def sumdiff(n, arr):
    mini = 0
    maxi = sum(arr)
    ans = float('inf')
    dp = subset(n, arr, maxi)
    #print(dp)
    for i in range(mini, (maxi+2)//2):
        if(dp[i]):
            ans = min(ans, maxi-2*i)
    return ans
    


test = int(input())
for i in range(test):
    n = int(input())
    arr = list(map(int, input().split()))
    print(sumdiff(n, arr))