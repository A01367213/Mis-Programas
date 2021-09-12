is.wholenumber <-
  function(x, t = .Machine$double.eps^0.5)  abs(x - round(x)) < t #t=tolerancia
b1<-TRUE #Bandera 1
l1<-c() #Arreglo 1
i<-1
n=1 #Número
print('Para terminar, ingrese 0 como valor final')
while(b1){
  print(paste('Inserte número positivo',n,':'))
  x<-as.numeric(readline())
  if(x>=1){
    n=n+1
    l1[i]<-x
    i<-i+1
  }else if(x<0){
    print('Favor de ingresar números POSITIVOS')
    p=readline('') #Pausa
  }else if(x==0){
    break
  }
}
l1<-sort(l1)
l2<-c() #Arreglo 2
b2<-TRUE #Bandera 2
m1<-1 #m=Marca
m2<-1
while(b2){
  a<-l1[m1]
  if(is.wholenumber(a)){
    l2[m2]<-a
    m2<-m2+1
  }
  m1<-m1+1
  if(m1==i){
    break
  }
}
print("Numeros naturales sin Extremos")
print(l2[2:(m2-2)])