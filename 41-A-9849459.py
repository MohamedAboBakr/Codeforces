s=input()
t=input()
len1=len(s)
len2=len(t)
if len1>len2:
    len_s=len1
else:
    len_s=len2
if(len1 != len2):
    print("NO")
    exit()
k=0
for i in range(len_s):
    if(s[i]==t[len_s-1-i]):
        k+=1

if(k==len_s):
    print("YES")
else:
    print("NO")