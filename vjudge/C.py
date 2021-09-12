ply="11110111011101"
t0=0
t1=0

for i in range(len(ply)):
    if ply[i]=="0":
        t0=t0+1
        t1=0
        if t0==7:
            print("YES")
            break
        
    if ply[i]=="1":
        t1=t1+1
        t0=0
        if t1==7:
            print("YES")
            break

if t0<7 and t1<7:
    print("NO")
