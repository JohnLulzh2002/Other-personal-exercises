inc='tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl'
inc=list(map(ord,inc))
# inc=list(map(ord,'abcad'))
#[97,122]
def match(s):
    global inc
    i=0
    for j in inc:
        if j==s[i]:
            i+=1
            if i==len(s):
                return True
    return False
ans=0
def dfs(s):
    global ans
    if match(s):
        ans+=1
        # print(list(map(chr,s)))
        for i in range(s[-1]+1,123):
            t=s[:]
            t.append(i)
            dfs(t)
for i in range(97,123):
    dfs([i])
print(ans)