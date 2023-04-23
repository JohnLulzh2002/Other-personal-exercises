from string import ascii_lowercase

d=[0 for i in  range(26)]
with open('word.txt','r') as f:
    for c in f.readline():
        if c in ascii_lowercase:
            d[ord(c)-ord('a')]+=1
for i,c in sorted(enumerate(d),key=lambda x:x[1],reverse=True):
    print(ascii_lowercase[i],end='')
    # print(ascii_lowercase[i],c,'{:2f}'.format(100*c/sum(d)),sep='\t')