clc;
clear;
close(winsid());

t=linspace(0,5,48000*5);


function e=en(t)
    [r,c]=size(t);
    e=zeros(r,c);
    e(t<1)=(1/2)*sin(2*3.14*440*t)+(1/2)*sin(2*3.14*660*t);
    e(t>2)=sin(2*3.14*880*t);
    e(t>3)=0;
endfunction

e=en(t);
playsnd(e,48000);
