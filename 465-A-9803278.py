import math

n=int(input())
d=list(input())
old_num_bin=[]
for i in range(n):
    old_num_bin.append(int(d[n-i-1]))
old_num_value=0
for i in range(n):
    old_num_value+=(int(d[i]))*(pow(2,i))
new_num_value=old_num_value+1
new_num_bin=list(bin(new_num_value)[2:])

if len(new_num_bin)<n:
    append_index=n-len(new_num_bin)
    for i in range(append_index):
        new_num_bin.insert(0,0)
elif len(new_num_bin)>n:
    append_index=len(new_num_bin)-n
    new_num_bin=list(new_num_bin[append_index:])
k=0
for i in range(n):
    if int(old_num_bin[i])!= int(new_num_bin[i]):
        k+=1

print(k)