clear all;
close all;
clc;


center=load('center_coordinate.txt');
building=load('building_coordinate.txt');


figure(1)


hold on;
plot(center(:,1).',center(:,2).','bo','LineWidth',2);
plot(building(:,1).',building(:,2).','r.','LineWidth',2);
hold off;
title('buildings and center','LineWidth',2);
xlabel('x','LineWidth',2);
ylabel('y','LineWidth',2);
grid on;