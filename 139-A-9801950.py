import math
n = int(input())
x=input()
day=x.split(" ")
day_pages=[]
for i in range(7):
    day_pages.append(int(day[i]))
sum1=0
i=0
while True:
    sum1+=day_pages[i]
    if(sum1>n or sum1 == n):
        print(i+1)
        break
    if i==6 and sum1<n:
        i=-1
    i+=1