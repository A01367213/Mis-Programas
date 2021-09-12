m<-function(n){      #Solicitud Matriz
  print(paste("Dimensiones de matriz ",n)) #n=Nombre de matriz
  n=as.integer(readline(prompt = 'Índica la cantidad de filas y columnas: '))
  flag<-TRUE
  a<-c()
  print("(Introduce los elementos de la matriz por COLUMNAS)")
  for(i in 1:(n*n)){
    x<-as.numeric(readline(prompt="Introduce un valor: "))
    a[i]<-x
  }
  dim(a) <- c(n,n)
  a
}
pr<-function(A, B){ #Producto de matriz
    nm<-matrix(data=0,nrow=dim(A)[1], ncol=dim(B)[2])#Nueva matriz
    for(i in 1:(dim(A)[1])){
      for(j in 1:(dim(B)[2])){
        for(k in 1:(dim(B)[1])){
          nm[i,j] <- nm[i,j] +(A[i,k]*B[k,j])
        }
      }
    }
    nm
}

b1<-T
while (b1){
  b1<-F
  A=m("A")
  B=m("B")
  if((dim(A))==(dim(B))){
    C<-pr(A,B)
    i<-solve(C)
    print("Producto A*B")
    print(C)
    print("Inversa del producto")
    print(i)

  }else{
    print('Matrices incompatibles')
    b1<-T
  }

}
options(warn = -1)

