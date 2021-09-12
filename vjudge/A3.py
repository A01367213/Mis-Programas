import sys
if name == 'main':
    no_coins = int(sys.stdin.readline())
    coin_vals = sys.stdin.readline().split()
    coins = []
    s = 0
    min = 0
    for i in range(len(coin_vals)):
        c = int(coin_vals[i])
        coins.append(c)
        s = s + c
    coins.sort(reverse=True)
    for i in range(len(coins)):
        min = min + coins[i]
        if(min > s/2):
            print(i+1)
            break
