n= (int)(input())
fact=1
fp=1
mod=109546051211
if(n>600000):
    fp=0;
else:
    for i in range(1,n+1):
        fact=fact*i
        if(fact>mod):
            fact= fact%mod
        fp= (fp*fact)%mod
print(fp)
