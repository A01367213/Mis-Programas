m<-function(n){      #Solicitud Matriz
  print(paste("Dimensiones de matriz ",n)) #n=Nombre de matriz
  f<-as.integer(readline(prompt="Filas    :"))
  c<-as.integer(readline(prompt="Columnas :"))
  flag<-TRUE
  a<-c()
  print("(Introduce los elementos de la matriz por COLUMNAS)")
  for(i in 1:(f*c)){
    x<-as.numeric(readline(prompt="Introduce un valor: "))
    a[i]<-x
  }
  dim(a) <- c(f,c)
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
A=m("A")
B=m("B")
C<-pr(A,B)
i<-solve(C)
print("Producto A*B")
print(C)
print("Inversa del producto")
print(i)