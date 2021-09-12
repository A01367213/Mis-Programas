[x,y] = meshgrid(-10:0.5:10,-10:0.5:10);
u = sin(x)+sin(y);
v = sin(x)-sin(y);
figure
quiver(x,y,u,v)