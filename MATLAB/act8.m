% Miguel Ángel Santamaria Vilchis A01366795
% Horacio Lamas Arellano A01367213
% Victor Hugo Franco Juárez A01366475
% Juan Pablo Ortiz Ortega A01366969

% Los incisos del ejercicio 3 están como comentarios en la definición de la
% Función fx

clear;
clc;

% Declara variable simbolica 
syms x 

% Contador 
cuenta = 0;

% Ecuación (input("f(x)="))
%fx = x-cos(x); 
%fx = x*2.7128^x-1;
%fx = x*log10(x)-1.2;
%fx = 2.7128^(0.3*x)-x.^2+4;
fx = 2*cos(x)-(sqrt(x)/2)-1;


xa = 0; 
xb = 10;
% Tolerancia de error
t0 = 0.0001;

% error GRANDE 
t1 = intmax;
iteraciones = 100;
xr = xa; 
while (t1>t0)
    xra = xr; % es xr antes de ser modificado
    xr = (xa+xb)/2; 
    fxr = subs(fx,x,xr); 
    fxa = subs(fx,x,xa);
    if ((fxr*fxa)<0)
        xb=xr;
    elseif ((fxr*fxa)>0)
        xa=xr;
    end 
    t1 = abs(xr-xra); 
    cuenta = cuenta + 1;
    if (cuenta == iteraciones)
        break;
    end
end 

fprintf('La raíz de la función se encuentra en :')
disp(xr)
fprintf('El número de iteraciones realizadas fue de :')
disp(cuenta)
