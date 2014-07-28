import math
import random
def miller_rabin_pass(a, n):
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1

    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in range(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1

def isprime(n):
    for repeat in range(20):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, n):
            return False
    return True

t= int(input())
for i in range(t):
    x= int(input())
    flag=0
    if(x==2):
        print("2")
        flag=1
    elif(x%2==0):
       x=x-1
    if(flag==0):
        while(True):
            if(isprime(x)):
                print(x)
            break
            x=x-2

        
