def kadane(n, a):
    max_so_far = a[0]
    max_current = a[0]
    
    for i in range(1, n):
        max_current = max(max_current + a[i], a[i])
        max_so_far = max(max_current,  max_so_far)
        
    return max_so_far

test = int(input())
for i in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    print(kadane(n, a))
