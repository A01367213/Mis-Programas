askX<-function(){
  print('Agregue las posiciones del objeto (en m)')
  x<-c()
  for(i in 1:5){
    x[i]<-as.integer(readline(prompt = 'Posici�n: '))
  }
  x
}
askT<-function(){
  print('Agregue el tiempo correspondiente en orden conforme anot� las posiciones (en s)')
  t<-c()
  for(i in 1:5){
    t[i]<-as.integer(readline(prompt = 'Tiempo: '))
  }
  t
}
distR<-function(x){
  for (i in 1:5) {
    x[i]<-abs(x[i])
  }
  sx<-sum(x)
  print(paste('Distancia total recorrida:',sx,'m'))
}
print('Se proceder� a hacer una gr�fica x/t')
print('Favor de ingresar los datos solicitados')
x<-askX()
t<-askT()
plot(t,x)
distR(x)

