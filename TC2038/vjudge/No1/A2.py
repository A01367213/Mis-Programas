n=input()
coin=input()
coin=coin.split(" ")
for i in range(len(coin)):
    coin[i]=int(coin[i])

coin.sort(reverse=True)



counterMe=0
counterBro=0
sumMe=0
sumBro=0
for i in range(len(coin)):
    if (i%2)==0:
        counterMe=counterMe+1
        sumMe=sumMe+coin[i]
    else:
        counterBro=counterBro+1
        sumBro=sumBro+coin[i]


if sumMe>sumBro:
    print(counterMe)
if sumMe==sumBro:
    print(counterMe+1)

