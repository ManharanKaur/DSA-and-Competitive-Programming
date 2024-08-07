import array as A
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

L = A.array('i', {1,2,3,4,5,6,7,8,9})
k = 4
len = len(L)
for i in range(gcd(len, k)):
    for j in range (1,len//gcd(len,k)):
        L[i], L[(i + j*k)%len] = L[(i+j*k)%len], L[i]

for i in range(len):
    print(L[i], end=" ")