n=int(input())
x=list(map(int,input().split()))
for i in range(1,n):
    if x[i-1] > x[i]:
        if sorted(x)==(x[i:]+x[:i]):
            print(n-i)
            exit()
        else:
            print(-1)
            exit()
print(0)