% Miguel Ángel Santamaria Vilchis A01366795
% Horacio Lamas Arellano A01367213
% Victor Hugo Franco Juárez A01366475
% Juan Pablo Ortiz Ortega A01366969
clear;
clc;
syms x

fprintf("3 a) x*log(x)=1.2")
secante(x*log10(x)-1.2);
fprintf("3 b) x-cos(x)=0")
secante(x-cos(x))

f3=[1 -4 1 6];
f4=[1 0 -25 -10098];

disp("3 c) Las raíces del polinomio f3 son : ")
R3=roots(f3);
disp(R3)

disp("3 d) Las 3 enteros son:")
R4=roots(f4);
disp([R4(1,1) R4(1,1)+5 R4(1,1)-5])

function secante(fx)
c=0;
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

end