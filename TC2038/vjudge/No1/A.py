def estafa(nCoin,cValue):
    nCoin=int(nCoin)
    if nCoin >= 1 and nCoin<=100:
        cValue=cValue.split(" ")

        if nCoin == len(cValue):
            rCoin=nCoin%2
            for i in range(len(cValue)):
                cValue[i]=int(cValue[i])
                #print(cValue)
                if cValue[i]<1:
                    return False
                if cValue[i]>100:
                    return False

            if (rCoin)==0:
                mCoin=(nCoin/2)
                return int(mCoin + 1)
            else:
                return int(nCoin/2 + 0.5)
        else:
           #print("")
            return False
    else:
        return False


def main():

    nCoin=input()
    cValue=input()
    #nCoin=10

    #cValue="1 3 4 2 5 9 5 5 100 5"
    result=estafa(nCoin,cValue)
    print(result)

main()

