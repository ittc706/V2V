clear all;
close all;
clc;


figId=1;
%% PRR
losDistance=load('distance_los.txt');
nlosDistance=load('distance_nlos.txt');
allDistance=[losDistance.' nlosDistance.'];

IntersectDistance=min(allDistance):1:max(max(losDistance),max(allDistance));

[numLos,centerLos]=hist(losDistance',IntersectDistance);
[numNlos,centerNlos]=hist(nlosDistance',IntersectDistance);
[numAll,centerAll]=hist(allDistance',IntersectDistance);

losRate=numLos./numAll;
nlosRate=numNlos./numAll;

figure(figId)
figId=figId+1;
plot(centerLos,losRate,'b.','LineWidth',2);
title('LosNum-Distance','LineWidth',2);
xlabel('Distance(m)','LineWidth',2);
ylabel('LosNum','LineWidth',2);
grid on;


figure(figId)
figId=figId+1;
plot(centerNlos,nlosRate,'b.','LineWidth',2);
title('NLosNum-Distance','LineWidth',2);
xlabel('Distance(m)','LineWidth',2);
ylabel('LosNum','LineWidth',2);
grid on;