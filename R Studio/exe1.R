entermatrix<-function(rows,columns){
  elements<-columns*rows
  element<-1
  cu_row<-1
  mat<-matrix(nrow=rows, ncol=columns)
  add<-1
  column<-1
  
  while(element<=elements){
    current<-as.integer(readline(prompt="Introduce el elemento: "))
    mat[cu_row,column]<-current
    show(mat)
    element<-element+1
    column<-column+1
    if((column-1)==columns){
      cu_row<-cu_row+1
      column<-1
    }
  }
  inverse<-solve(mat)
  show(inverse)
}
rows<-as.integer(readline(prompt="Número de filas: "))
columns<-as.integer(readline(prompt="Número de columnas: "))
entermatrix(rows,columns)