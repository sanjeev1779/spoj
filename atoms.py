t=(int) (input())
for i in range(t):
    x= raw_input().split(' ')
    N=(int)(x[0])
    K=(int)(x[1])
    M=(int)(x[2])
    #print(N,K,M)
    time=0
    while(N*K<=M):
        N=N*K
        time=time+1
    print(time)
    
