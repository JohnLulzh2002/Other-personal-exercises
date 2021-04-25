def exgcd(a,b):
    if not b:
        return 1,0
    x,y=exgcd(b,a%b)
    return y,x-a//b*y
def inv(n,p):
    return exgcd(n,p)[0]%p
n,p=[int(x)for x in input().split()]
for i in range(1,n+1):
    print(inv(i,p))