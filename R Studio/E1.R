sol<-function(){
  f<-as.integer(readline(prompt = 'No. de filas:'))
  c<-as.integer(readline(prompt = 'No. de columnas:'))
  A=matrix(nrow = f,ncol = c)
  show(A)
}

A=sol()