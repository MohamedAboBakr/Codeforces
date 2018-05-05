y=int(input())
a=[int(x) for x in input().split()]
num=0
j=0
for i in range(y):
    if a[i]==i:
        num+=1
    elif a[a[i]]==i:
        j=1
if(num!=y):
    print(num+j+1)
else:
    print(num)