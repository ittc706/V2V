clear all;
close all;
clc;

time_slot_0=load('time_slot_0.txt');
time_slot_1=load('time_slot_1.txt');
time_slot_2=load('time_slot_2.txt');
time_slot_3=load('time_slot_3.txt');
center=load('center_coordinate.txt');


figure(1)

colors=linspecer(4);

hold on;
plot(time_slot_0(:,1)',time_slot_0(:,2)','.','Color',colors(1,:),'LineWidth',2);
plot(time_slot_1(:,1)',time_slot_1(:,2)','.','Color',colors(2,:),'LineWidth',2);

if ~isempty(center)
plot(time_slot_2(:,1)',time_slot_2(:,2)','.','Color',colors(3,:),'LineWidth',2);
plot(time_slot_3(:,1)',time_slot_3(:,2)','.','Color',colors(4,:),'LineWidth',2);
plot(center(:,1).',center(:,2).','bo','LineWidth',2);
end

hold off;
title('time_slot','LineWidth',2);
xlabel('x','LineWidth',2);
ylabel('y','LineWidth',2);
grid on;