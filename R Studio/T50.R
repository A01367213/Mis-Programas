print('Se procederá a hacer una gráfica x/t')
print('Favor de ingresar los datos solicitados')
x<-c()
t<-c()
for (i in 1:5) {
  x[i]<-as.integer(readline(prompt = 'Posición: '))
  t[i]<-as.integer(readline(prompt = 'Tiempo  : '))
}
x1<-x
plot(t,x)
for (j in 1:5) {
  x1[j]<-abs(x1[j])
}
dtr<-sum(x1) #dtr=Distancia total recorrida
print(paste('Distancia total recorrida:',dtr))