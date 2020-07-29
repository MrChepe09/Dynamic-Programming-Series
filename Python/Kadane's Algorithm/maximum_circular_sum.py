def max_sum(n, a):
    total, maxSum, curMax, minSum, curMin = 0, a[0], 0, a[0], 0
    for i in range(len(a)):
        curMax = max(curMax+a[i], a[i])
        maxSum = max(curMax, maxSum)
        curMin = min(curMin+a[i], a[i])
        minSum = min(curMin, minSum)
        total += a[i]
    return max(maxSum, total-minSum) if maxSum > 0 else maxSum

test = int(input())
for i in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    print(max_sum(n, a))