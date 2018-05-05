import sys,math
a1,a2,a3 = map(int,sys.stdin.readline().split())
b1,b2,b3 = map(int,sys.stdin.readline().split())
n =int(input())
sum_a = a1 + a2 + a3
sum_b = b1 +  b2 +  b3
shef_a_num = math.ceil(sum_a/5)
shef_b_num = math.ceil(sum_b/10)
if (shef_a_num  + shef_b_num)<= n:
     print("YES")
else:
     print("NO")