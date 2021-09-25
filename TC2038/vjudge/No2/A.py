from array import *

nTest = int(input())
userIn = []
test = []


for i in range(nTest):
    userIn = list(map(int, input().split()))
    test.insert(i, userIn)
    test[i].sort(reverse = True)

for j in range(nTest):
    boot1 = 0
    boot2 = 0
    
    for k in range(len(test[j])):
        if boot1 == boot2:
            boot1 = boot1 + test[j][k]
        elif boot1 > boot2:
            boot2 = boot2 + test[j][k]
        else:
            boot1 = boot1 + test[j][k]
            
    if boot1 == boot2:
        print('YES')
    else:
        print('NO')
        
    



