import math

    def erlangB(a,n):
        num= a ** n / math.factorial(n);
        den=0;
        for x in range(0,n+1):
            den+=a**x/math.factorial(x)
        return num/den
