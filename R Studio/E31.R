NaE=as.integer(readline(prompt="Cantidad de números a enlistar : "))#NaE=Números a enlistar
v<-vector(mode='numeric',length=NaE)
i=1
current<-0
while (i<=NaE){
  current<-as.integer(readline(prompt="Introduce el número: "))
  if (current<=0){
    error<-T
    while(error){
      print("FAVOR DE INGRESAR VALORES MAYORES A 0 ")
      current<-as.integer(readline(prompt="Introduce el número: "))
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
print(paste("Entre los números",min,"y",max,"se encuentran los siguientes números naturales"))
j=(min+1)
while (j<max){
  
  print(j)
  j=j+1
}