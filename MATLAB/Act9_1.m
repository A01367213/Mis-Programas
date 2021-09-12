clear,clc;
syms x
%Ecuaciónes
f1 = x-cos(x); 
f2 = x.*exp(x)-1;
f3 = x.*log(x)-1.2;
f4 = exp(x.*0.3)-x.^2+4;
f5 = 2.*cos(x)-(x^(1/2)/2)-1;
%Despliegues
fprintf("Para: "),disp(f1)
NR(f1)
fprintf("Para: "),disp(f2)
NR(f2)
fprintf("Para: "),disp(f3)
NR(f3)
fprintf("Para: "),disp(f4)
NR(f4)
fprintf("Para: "),disp(f5)
NR(f5)
function[]=NR(fx)
t=0;
x0=3;
c=0;
tol=0.001;
while(t==0)
    t=1;
    fx0=subs(fx,x0);
    dx=diff(fx);
    dx0=subs(dx,x0);
    x1=x0-(fx0/dx0);

    if abs(x0-x1)>tol
        c=c+1;
        x0=x1;
        t=0;
    end
end
fprintf("La raíz se encuentra en: "),disp(vpa(x1))
fprintf("Número de iteraciones: "),disp(c)
end