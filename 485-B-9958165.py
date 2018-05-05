n=int(input())
a=[]
b=[]
for i in range(n):
    x,y=list(map(int,input().split()))
    a.append(x)
    b.append(y)

s=max(a)-min(a)
t=max(b)-min(b)
if s>t:
    print(s*s)
else:
    print(t*t)