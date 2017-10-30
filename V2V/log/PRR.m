clear all;
close all;
clc;


figId=1;
%% PRR
lossDistance=load('loss_package_distance.txt');
transimitDistance=load('transmit_package_distance.txt');

%IntersectDistance=intersect(unique(PackageLossDistance),unique(PackageTransimitDistance));
IntersectDistance=0:10:max(transimitDistance);

[numLoss,~]=hist(lossDistance',IntersectDistance);
[numTransmit,~]=hist(transimitDistance',IntersectDistance);

rateLoss=numLoss./numTransmit;

figure(figId)
figId=figId+1;
plot(IntersectDistance,1-rateLoss,'bo-','LineWidth',2);
title('PRR','LineWidth',2);
xlabel('Distance(m)','LineWidth',2);
ylabel('PRR','LineWidth',2);
axis([0 500 0 1])
grid on;