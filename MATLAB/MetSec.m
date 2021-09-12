clear;
clc;
syms x
c=0; %Cuenta
%Función
%fx=x-cos(x);
fx=x.*log(x)-1.2
%Valores Iniciales
x1=7;
x0=5;
t=0;
while(t==0)
    t=1;
    fx1=subs(fx,x1);
    fx0=subs(fx,x0);
    x2=x1-((fx1*(x0-x1))/(fx0-fx1));
    e=abs((x2-x1)/x2)*100;
    if (e>1)
        x0=x1;
        x1=x2;
        c=c+1;
        t=0;
    end
    
    
end
fprintf("La raíz se encuentra en: "),disp(vpa(x2))
fprintf("Error aproximado: "),disp(vpa(e))
fprintf("Número de iteraciones: "),disp(c)