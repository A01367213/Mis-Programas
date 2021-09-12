is.wholenumber <-
  function(x, tol = .Machine$double.eps^0.5)  abs(x - round(x)) < tol

flag<-TRUE
list<-c()
i<-1
print("(Usa un un valor menor o igual a 0 para terminar la lista)")
while(flag){
  x<-as.numeric(readline(prompt="Introduce un valor positivo: "))
  if(x<=0){
    break
  }
  else{
    list[i]<-x
    i<-i+1
  }
}

list<-sort(list)
whole<-c()
flag<-TRUE
j<-1
k<-1
while(flag){
  a<-list[j]
  if(is.wholenumber(a)){
    whole[k]<-a
    k<-k+1
  }
  j<-j+1
  if(j==i){
    break
  }
}

#print(list)
print("Numeros naturales (sin incluir los extremos)")
print(whole[2:(k-2)])