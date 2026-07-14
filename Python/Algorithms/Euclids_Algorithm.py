def EuclidsGCD(a,b):
    if(a == 0):
        return b
    return EuclidsGCD(b % a, a)
       

a = 6
b = 2
gcd = EuclidsGCD(a,b)

print(gcd)