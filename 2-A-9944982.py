a=[]
b={}
n=int(input())
for i in range(n):
    x,y=input().split()
    y=int(y)
    b[x]=b.get(x,0)+y
    a.append([x,b[x]])

m=max(b.values())
for i,j in a:
    if j>=m and b[i]==m:
        print(i)
        break