mod=1298074214633706835075030044377087
t=(int)(input())
l1=[]
def func():
        su=1
        l1.append(1)
        ans=1
        for i in range(1,501):
            ans= ans*2
            if(ans>=mod):
                ans%=mod
            su=su+ans
            if(su>=mod):
                su%=mod
            l1.append(su)
func()        
for i in range(t):
    n=(int)(input()) 
    print(l1[n])
            

