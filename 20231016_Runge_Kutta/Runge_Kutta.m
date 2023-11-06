clc;
clear all;
close all ;


num = 25;
t  = [0:0.01:0.01*num];
g  = 9.81;
m  = 80;
b  = 50;

v  = zeros(1, num+1);
k1 = zeros(1, num+1);
k2 = zeros(1, num+1);
k3 = zeros(1, num+1);
k4 = zeros(1, num+1);

v(1) = 20;

for i=1:1:num
    k1(i) = (0.01)*(g-b/m * (v(i)^2));
    k2(i) = (0.01)*(g-b/m * (v(i)+k1(i)/2)^2);
    k3(i) = (0.01)*(g-b/m * (k1(i)+k2(i)/2)^2);
    k4(i) = (0.01)*(g-b/m * (k2(i)+k3(i)/2)^2);

    if(i<=num)
        v(i+1) = v(i) + ((1/6) * (k1(i)+2*k2(i)+2*k3(i)+k4(i)));
    end
end

plot(t,v);