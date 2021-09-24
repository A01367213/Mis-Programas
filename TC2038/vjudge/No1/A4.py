n=input()
coin=input()
coin=coin.split(" ")
total=0
for i in range(len(coin)):
    coin[i]=int(coin[i])
    total=total+coin[i]

coin.sort(reverse=True)

me=0
meAux=total/2
for i in range(len(coin)):
    me=me+coin[i]
    if me>meAux:
        print(i+1)
        break


