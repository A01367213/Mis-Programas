NaE=as.integer(readline(prompt="Cantidad de n�meros a enlistar : "))#NaE=N�meros a enlistar
v<-vector(mode='numeric',length=NaE)
i=1
current<-0
while (i<=NaE){
  current<-as.integer(readline(prompt="Introduce el n�mero: "))
  if (current<=0){
    error<-T
    while(error){
      print("FAVOR DE INGRESAR VALORES MAYORES A 0 ")
      current<-as.integer(readline(prompt="Introduce el n�mero: "))
      if (current>0){
        error<-F
      }
    }
    
  }
  
  v[i]<-current
  
  i=i+1
}

v<-sort(decreasing=TRUE,v)
max<-(v[1])
min<-(v[i-1])
print(paste("Entre los n�meros",min,"y",max,"se encuentran los siguientes n�meros naturales"))
j=(min+1)
while (j<max){
  
  print(j)
  j=j+1
}