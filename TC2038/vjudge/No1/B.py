n=int(input())
a=[]


for i in range(n):
    x=input()
    x=x.split(" ")
    for j in range(len(x)):
        a.append(x[j])

team1=[]
team2=[]

for i in range(len(a)):
    aux1=i%2
    if aux1==0:
        team1.append(a[i])
    else:
        team2.append(a[i])

counter=0
for i in range(len(team1)):
    for j in range(len(team2)):
        if team1[i]==team2[j]:
            counter=counter+1

print(counter)

