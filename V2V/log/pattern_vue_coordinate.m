clear all;
close all;
clc;


center=load('center_coordinate.txt');
fid=fopen('pattern_vue_coordinate.txt');
lines=cell(5);

figure(1)

colors=linspecer(5);
shapes=['o','^','v','S','D'];

while 1
    for i=1:5
        lines{i}=fgets(fid);
    end
    if lines{1}==-1
        break;
    else
        hold on;
        plot(center(:,1).',center(:,2).','b*','LineWidth',2);
        for j=1:5
            lineStrs = regexp(lines{j}, ' +', 'split');
            lineNum=zeros(1,floor(length(lineStrs)/2)*2);
            for k=1:length(lineNum)
                lineNum(k)=str2num(lineStrs{k});
            end
            plot(lineNum(1:2:end),lineNum(2:2:end),shapes(j),'Color',colors(j,:),'LineWidth',2);
        end
        hold off;
        clf;
    end
end
