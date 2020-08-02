def countsub(arr, s):
    n = len(arr)
    dp = [[0 for _ in range(s+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(s+1):
            if(i==0):
                dp[i][j] = 0
            if(j==0):
                dp[i][j] = 1
            elif(arr[i-1]<=j):
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][s]

def target(n, arr, s):
    maxi = sum(arr)
    #print(dp)
    s1 = (s+maxi)//2
    #print(s1)
    return countsub(arr, s1)


test = int(input())
for i in range(test):
    n = int(input())
    arr = list(map(int, input().split()))
    s = int(input())
    print(target(n, arr, s))