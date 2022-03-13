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
    k=(110-x*5/14).*uh(-(x-199.75)).*uh(x+0.25);
endfunction

function l=monter1(x)
    l=monter1a(x)+monter1b(x-5)+monter1c(x-50)
endfunction

function m=descendre2(x)
    m=(150-x*0.6).*uh(-(x-199.75)).*uh(x+0.25);
endfunction

function l=monter2(x)
    l=monter2a(x)+monter2b(x-5)
endfunction

function g=monter1a(x)
    g=(38.75).*uh(-(x-4.75)).*uh(x+0.25);
endfunction

function g=monter1b(x)
    g=(1.58*x+38.75).*uh(-(x-44.75)).*uh(x+0.25)
endfunction

function g=monter1c(x)
    g=(110).*uh(-(x-4.75)).*uh(x+0.25);
endfunction

function f=monter2a(x)
    f=(-2.12*x+30.6).*uh(-(x-4.75)).*uh(x+0.25)
endfunction

function f=monter2b(x)
    f=(2.6*x+20).*uh(-(x-49.75)).*uh(x+0.25)
endfunction

t=linspace(0,255 ,256);


t2=linspace(256,511,256);

plot2d(t,f2(t),color("green"))
plot2d(t,f2(t+64),color("blue"))
plot2d(t,f2(t+128),color("purple"))
plot2d(t,f2(t+192),color("red"))
plot2d(t,f1(t),color("green"))
plot2d(t,f1(t+64),color("blue"))
plot2d(t,f1(t+128),color("purple"))
plot2d(t,f1(t+192),color("red"))
title("courbes des moteurs pour le bat monkey")
xlabel("t [~ms]")
ylabel("angle(t) [rad]")
