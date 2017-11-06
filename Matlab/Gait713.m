%%load raw position 
sen1= csvread('713V1.csv');    
sen2= csvread('713W1.csv'); 
sen3= csvread('714Run1.csv');
sen4= csvread('717Run3.csv');  
global v1 w1 d r1 r2
w1.ax=sen2(:,1);w1.ay=sen2(:,2);w1.az=sen2(:,3);
w1.gx=sen2(:,4);w1.gy=sen2(:,5);w1.gz=sen2(:,6);%% Gyo
w1.qx=sen2(:,7);w1.qy=sen2(:,8);w1.qz=sen2(:,9);w1.qw=sen2(:,10); %% Q
r1.ax=sen3(:,1);r1.ay=sen3(:,2);r1.az=sen3(:,3);
r1.gx=sen3(:,4);r1.gy=sen3(:,5);r1.gz=sen3(:,6);%% Gyo
r1.qx=sen3(:,7);r1.qy=sen3(:,8);r1.qz=sen3(:,9);r1.qw=sen3(:,10); %% Q

r2.ax=sen4(:,1);r2.ay=sen4(:,2);r2.az=sen4(:,3);
r2.gx=sen4(:,4);r2.gy=sen4(:,5);r2.gz=sen4(:,6);%% Gyo
r2.qx=sen4(:,7);r2.qy=sen4(:,8);r2.qz=sen4(:,9);r2.qw=sen4(:,10); %% Q
%% Walking
M=[w1.ax w1.ay w1.az]; %加速度计整个6段步态， 每段大概5M
M1=[w1.ax(2200:4500) w1.ay(2200:4500) w1.az(2200:4500)];
M2=[w1.ax(4500:6900) w1.ay(4500:6900) w1.az(4500:6900)];  %加速度计截取一段完整步态
M3=[w1.ax(7000:9200) w1.ay(7000:9200) w1.az(7000:9200)];  %加速度计截取一段完整步态
M4=[w1.ax(9200:11400) w1.ay(9200:11400) w1.az(9200:11400)];
M5=[w1.ax(11400:13800) w1.ay(11400:13800) w1.az(11400:13800)];
%% Running
fs=100;
R=[r1.ax r1.ay r1.az]; 
R1=[r1.ax(800:12000) r1.ay(800:12000) r1.az(800:12000) ];
Rg=[r1.gx(800:12000) r1.gy(800:12000) r1.gz(800:12000)];
Rw=[r1.ax(19000:22000) r1.ay(19000:22000) r1.az(19000:22000)];
%subplot(311);hua_fft(R1(:,1),fs,1);subplot(312);hua_fft(R1(:,2),fs,1);subplot(313);hua_fft(R1(:,3),fs,1);
%subplot(311);hua_fft(Rg(:,1),fs,1);subplot(312);hua_fft(Rg(:,2),fs,1);subplot(313);hua_fft(Rg(:,3),fs,1);
R2=[r2.ax r2.ay r2.az]; 
%% ---------------FFT--------------------

b = fir1(fs, 3/fs*2, 'low');  %2.2hz 低通滤波器
%b = fir1(fs, 2/fs*2, 'high');   %5hz  高通滤波器
%b1 = fir1(fs, [0.2/fs*2,1/fs*2], 'stop');  %48~52hz 带阻滤波器 
M(:,1) = filtfilt(b,1,M(:,1));M(:,2) = filtfilt(b,1,M(:,2));M(:,3) = filtfilt(b,1,M(:,3));  
M1(:,1) = filtfilt(b,1,M1(:,1));M1(:,2) = filtfilt(b,1,M1(:,2));M1(:,3) = filtfilt(b,1,M1(:,3));  
M2(:,1) = filtfilt(b,1,M2(:,1));M2(:,2) = filtfilt(b,1,M2(:,2));M2(:,3) = filtfilt(b,1,M2(:,3));  
M3(:,1) = filtfilt(b,1,M3(:,1));M3(:,2) = filtfilt(b,1,M3(:,2));M3(:,3) = filtfilt(b,1,M3(:,3));  
M4(:,1) = filtfilt(b,1,M4(:,1));M4(:,2) = filtfilt(b,1,M4(:,2));M4(:,3) = filtfilt(b,1,M4(:,3)); 
M5(:,1) = filtfilt(b,1,M5(:,1));M5(:,2) = filtfilt(b,1,M5(:,2));M5(:,3) = filtfilt(b,1,M5(:,3));

R1(:,1) = filtfilt(b,1,R1(:,1));R1(:,2) = filtfilt(b,1,R1(:,2));R1(:,3) = filtfilt(b,1,R1(:,3));%
Rg(:,1) = filtfilt(b,1,Rg(:,1));Rg(:,2) = filtfilt(b,1,Rg(:,2));Rg(:,3) = filtfilt(b,1,Rg(:,3));
R2(:,1) = filtfilt(b,1,R2(:,1));R2(:,2) = filtfilt(b,1,R2(:,2));R2(:,3) = filtfilt(b,1,R2(:,3));
%subplot(311);hua_fft(Rg(:,1),fs,1);subplot(312);hua_fft(Rg(:,2),fs,1);subplot(313);hua_fft(Rg(:,3),fs,1);
%% ----------------END----------------------------------
%% Plot
p=1;
Walk=[w1.ax, w1.ay, w1.az ,w1.gx, w1.gy, w1.gz]; Run=[r1.ax(800:12000), r1.ay(800:12000), r1.az(800:12000) ,r1.gx(800:12000), r1.gy(800:12000) ,r1.gz(800:12000)];
P=Rg;
if p==0
% subplot(311);plot(P(:,1));
% subplot(312);plot(P(:,2));
% subplot(313);plot(P(:,3));
% subplot(321);plot(P(:,1));
% subplot(323);plot(P(:,2));
% subplot(325);plot(P(:,3));
% subplot(322);plot(P(:,4));
% subplot(324);plot(P(:,5)); 
% subplot(326);plot(P(:,6));
% subplot(321);plot(M1(:,1));subplot(323);plot(M1(:,2));subplot(325);plot(M1(:,3));
% subplot(322);hua_fft(M1(:,1),fs,1);subplot(324);hua_fft(M1(:,2),fs,1);subplot(326);hua_fft(M1(:,3),fs,1);
end

%% Data process
%% ---- 极值----- ---add Frame--- ---segmentation---
V=Rg(:,3);
w=min(V);h=max(V)-min(V)+2;
[Vmax,Tmax]=Extreme(V);hold on;
frame=[];
for t=1:length(Tmax)-1
    rectangle('position',[Tmax(t),w,(Tmax(t+1)-Tmax(t)),h]);
    frame=[frame Tmax(t+1)-Tmax(t)];
end
frame=ceil(mean(frame));
seg=zeros(length(Tmax)-1,130);
for i=1:length(Tmax)-1
    seg(i,:)=V(Tmax(i):(Tmax(i)+frame-1));
end
csvwrite('step_seg.csv',seg);
%% -----end-----
[d.x,d.y,d.z]= CaculateVar(M(:,1),M(:,2),M(:,3));
[d.x1,d.y1,d.z1]= CaculateVar(M1(:,1),M1(:,2),M1(:,3));
[d.x2,d.y2,d.z2]= CaculateVar(M2(:,1),M2(:,2),M2(:,3));
[d.x3,d.y3,d.z3]= CaculateVar(M3(:,1),M3(:,2),M3(:,3));
[d.x4,d.y4,d.z4]= CaculateVar(M4(:,1),M4(:,2),M4(:,3));
[d.x5,d.y5,d.z5]= CaculateVar(M5(:,1),M5(:,2),M5(:,3));

[d.rx,d.ry,d.rz]= CaculateVar(R1(:,1),R1(:,2),R1(:,3));
[d.rx_1,d.ry_1,d.rz_1]= CaculateVar(R2(:,1),R2(:,2),R2(:,3)); 

[x,y,z]= CaculateVar(Rw(:,1),Rw(:,2),Rw(:,3)); 

%% Walking
%scatter3(d.x',d.y',d.z','*','r');hold;
%scatter(d.x,d.y,'*','r');hold;
% figure;
% scatter3(d.x1',d.y1',d.z1','.','b');hold;
%scatter3(d.x2',d.y2',d.z2','o','r');hold;
%scatter3(d.x3',d.y3',d.z3','.','g');hold;
%scatter3(d.x4',d.y4',d.z4','*','y');hold;
%scatter3(d.x5',d.y5',d.z5','o','m');hold;
%% Runing_heelfoot
%scatter3(d.rx',d.ry',d.rz','.','b'); 
% scatter(d.rx,d.ry,'.','b');
%% Runing_forefoot
%scatter3(d.rx_1',d.ry_1',d.rz_1','.','k');
%scatter(d.rx,d.ry,'.','b');
%% Test Walking Data
%scatter3(x',y',z','o','k');
%scatter(x',y','.','k');
%% SVM
%figure;
Rtrain=[d.rx' d.ry']; Wtrain=[d.x' d.y'];
%Rtrain=[d.rx' d.ry' d.rz']; Wtrain=[d.x' d.y' d.z'];
traindata=[Rtrain; Wtrain];
label=[ones(1,length(d.rx)) zeros(1,length(d.x))]';
testdata = [x' z']; %testdata = [x' y' z']; %scatter3(x,y,z,'O','d');
% svm_struct = svmtrain(traindata,label,'kernel_function','rbf','method' ,'SMO','Showplot',true); %%training 
% Group = svmclassify(svm_struct,testdata,'Showplot',true);  
%plot(testdata(:,1),testdata(:,2),'.','MarkerSize',12); 
%%
function [X,Y,Z]= CaculateVar(x,y,z)
    X=[];Y=[];Z=[]; ax=[];ay=[];az=[];
    for i = 1:(length(x)/50-1)     %% 1~20
        for j=((i-1)*50+1):((i-1)*50+100)   %% 1~100  51~150 ...951~1050
            ax= [ax x(j)];ay= [ay y(j)];az= [az z(j)];
        end
         ax=ax-mean(ax); ay=ay-mean(ay);az=az-mean(az);  %DC
         X=[X var(ax)]; Y=[Y var(ay)];Z=[Z var(az)];
         ax=0;ay=0;az=0;
    end
end

