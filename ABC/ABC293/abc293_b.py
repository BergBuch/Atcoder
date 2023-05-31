N = int(input())
A=[0]
A += list(map(int,input().split()))
             
X=[False for _ in range(N+1)]
for i in range(1,N+1):
    if not X[i]: X[A[i]] = True

X_list = []
for i in range(1,N+1):
    if not X[i]: X_list.append(i)

K = len(X_list)

print(K)
res=''
for i in range(K):
    if i==K-1:
        res+=str(X_list[i])
    else:
        res+=f'{X_list[i]} '
print(res)
    