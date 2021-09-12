%generacion de coordenadas a partir de vectores
[x,y] = meshgrid(-8:0.5:8,-8:0.5:8);

%obtención de función escalar u usando multip. de arreglos
u = y.^3-9.*y;
%obtención de función escalar v usando multip. de arreglos
v = x.^3-9*x;

%establece el destino del siguiente gráfico
figure
%quiver muestra una flecha en cada punto de datos de x & y 
%de forma que la dirección y longitud de la flecha 
%represente los valores correspondientes en u y v.
quiver(x,y,u,v)