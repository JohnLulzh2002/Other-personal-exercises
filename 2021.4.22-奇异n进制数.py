n=int(input())
a=[0]
for i in range(100):
    print(i,end='    ')
    for j in range(len(a),0,-1):
        print(a[j-1],end='')
    print()
    a[0]+=1
    k=0
    while a[k]==n:
        k+=1
        if k>=len(a):
            a.append(0)
        a[k]+=1
    for x in range(k,0,-1):
        a[x-1]=a[x]