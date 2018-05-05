n,k=list(map(int,input().split()))
h=list(map(int,input().split()))
a=[[sum(h[:k]),1]]
for i in range(n-k):
    a.append([a[i][0]+h[i+k]-h[i],i+2])
print(min(a)[1])