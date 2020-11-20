for _ in range(int(input())):
    n,k = map(int, input().split())
    x = list(map(int, input().split()))
    k %= n
    if k == 0: 
        print(*x)
    else:
        print(*list(x[-k%n:] + x[:n-k]))
