clear all;
close all;
clc;


figId=1;
%% PL

DistancePl=load('distance_pl.txt');
Distance=DistancePl(:,1).';
Pl=DistancePl(:,2).';

figure(figId)
figId=figId+1;
semilogy(Distance,Pl,'b.','LineWidth',2);
title('Distance-Pl','LineWidth',2);
xlabel('Distance(m)','LineWidth',2);
ylabel('PL','LineWidth',2);
grid on;
