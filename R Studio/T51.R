askX<-function(){
  print('Agregue las posiciones del objeto (en m)')
  x<-c()
  for(i in 1:5){
    x[i]<-as.integer(readline(prompt = 'Posición: '))
  }
  x
}
askT<-function(){
  print('Agregue el tiempo correspondiente en orden conforme anotó las posiciones (en s)')
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
print('Se procederá a hacer una gráfica x/t')
print('Favor de ingresar los datos solicitados')
x<-askX()
t<-askT()
plot(t,x)
distR(x)

