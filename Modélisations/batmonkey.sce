clc;
clear;
close(winsid());


function y=uh(x)
    [r,c]=size(x);
    y=zeros(r,c);
    y(x==0)=0;
    y(x>0)=1;
endfunction

function g=f1(x)
    g=descendre1(x)+monter1(x-200)+descendre1(x-255);
endfunction

function g=f2(x)
    g=descendre2(x)+monter2(x-200)+descendre2(x-255);
endfunction

function k=descendre1(x)
    k=(30+x*0.7).*uh(-(x-199.75)).*uh(x+0.25);
endfunction

function l=monter1(x)
    l=monter1a(x)+monter1b(x-5)+monter1c(x-50)
endfunction

function m=descendre2(x)
    m=(130-x*0.6).*uh(-(x-199.75)).*uh(x+0.25);
endfunction

function l=monter2(x)
    l=monter2a(x)+monter2b(x-5)
endfunction

function g=monter1a(x)
    g=(170).*uh(-(x-4.75)).*uh(x+0.25);
endfunction

function g=monter1b(x)
    g=(170-3.11*x).*uh(-(x-44.75)).*uh(x+0.25)
endfunction

function g=monter1c(x)
    g=(30).*uh(-(x-4.75)).*uh(x+0.25);
endfunction

function f=monter2a(x)
    f=(-2.12*x+10.6).*uh(-(x-4.75)).*uh(x+0.25)
endfunction

function f=monter2b(x)
    f=(2.6*x).*uh(-(x-49.75)).*uh(x+0.25)
endfunction


function k=getPhi(x)
    k=acos(((-1 - 8.5 .* cos(t/255*3.14)) / 16))
endfunction
t=linspace(0,255 ,256);



t2=linspace(256,511,256);

plot2d(t,getPhi(t))

title("courbes des moteurs pour le bat monkey")
xlabel("t [~ms]")
ylabel("angle(t) [rad]")
