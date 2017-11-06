%%load raw position 
sen3= csvread('714Run1.csv');
sen4= csvread('717Run3.csv');  
global r1 r2

r1.ax=sen3(:,1);r1.ay=sen3(:,2);r1.az=sen3(:,3);
r1.gx=sen3(:,4);r1.gy=sen3(:,5);r1.gz=sen3(:,6);%% Gyo
r1.qx=sen3(:,7);r1.qy=sen3(:,8);r1.qz=sen3(:,9);r1.qw=sen3(:,10); %% Q

r2.ax=sen4(:,1);r2.ay=sen4(:,2);r2.az=sen4(:,3);
r2.gx=sen4(:,4);r2.gy=sen4(:,5);r2.gz=sen4(:,6);%% Gyo
r2.qx=sen4(:,7);r2.qy=sen4(:,8);r2.qz=sen4(:,9);r2.qw=sen4(:,10); %% Q
%% Running
fs=100;
Ra=[r1.ax(800:12000) r1.ay(800:12000) r1.az(800:12000)];
Rg=[r1.gx(800:12000) r1.gy(800:12000) r1.gz(800:12000)];
Rq=[r1.qx(800:12000) r1.qy(800:12000) r1.qz(800:12000) r1.qw(800:12000)];
Rw=[r1.ax(19000:22000) r1.ay(19000:22000) r1.az(19000:22000)];
%subplot(311);hua_fft(R1(:,1),fs,1);subplot(312);hua_fft(R1(:,2),fs,1);subplot(313);hua_fft(R1(:,3),fs,1);
%subplot(311);hua_fft(Rg(:,1),fs,1);subplot(312);hua_fft(Rg(:,2),fs,1);subplot(313);hua_fft(Rg(:,3),fs,1);
R2=[r2.ax r2.ay r2.az]; 
%% ---------------FFT--------------------
b = fir1(fs, 3/fs*2, 'low');  %2.2hz µÍÍ¨ÂË²¨Æ÷
%b = fir1(fs, 2/fs*2, 'high');   %5hz  ¸ßÍ¨ÂË²¨Æ÷
%b1 = fir1(fs, [0.2/fs*2,1/fs*2], 'stop');  %48~52hz ´ø×èÂË²¨Æ÷ 
Raf(:,1) = filtfilt(b,1,Ra(:,1));Raf(:,2) = filtfilt(b,1,Ra(:,2));Raf(:,3) = filtfilt(b,1,Ra(:,3));%
Rgf(:,1) = filtfilt(b,1,Rg(:,1));Rgf(:,2) = filtfilt(b,1,Rg(:,2));Rgf(:,3) = filtfilt(b,1,Rg(:,3));
R2(:,1)  = filtfilt(b,1,R2(:,1));R2(:,2) = filtfilt(b,1,R2(:,2));R2(:,3) = filtfilt(b,1,R2(:,3));
%subplot(311);hua_fft(Rg(:,1),fs,1);subplot(312);hua_fft(Rg(:,2),fs,1);subplot(313);hua_fft(Rg(:,3),fs,1);
%% ----------------END----------------------------------
%% Data process
%% ---- ¼«Öµ----- ---add Frame--- ---segmentation---
V=Raf(:,3); global d;
w=min(V);h=max(V)-min(V)+2;
[Vmax,Tmax]=Extreme(V);hold on;
frame=[];
for t=1:length(Tmax)-1
    rectangle('position',[Tmax(t),w,(Tmax(t+1)-Tmax(t)),h]);
    frame=[frame Tmax(t+1)-Tmax(t)];
end
frame=ceil(mean(frame));
seg_ax=zeros(length(Tmax)-1,frame);seg_ay=zeros(length(Tmax)-1,frame);seg_az=zeros(length(Tmax)-1,frame);
seg_gx=zeros(length(Tmax)-1,frame);seg_gy=zeros(length(Tmax)-1,frame);seg_gz=zeros(length(Tmax)-1,frame);
seg_qx=zeros(length(Tmax)-1,frame);seg_qy=zeros(length(Tmax)-1,frame);seg_qz=zeros(length(Tmax)-1,frame);seg_qw=zeros(length(Tmax)-1,frame);
for i=1:length(Tmax)-1
    seg_ax(i,:)=Ra((Tmax(i):(Tmax(i)+frame-1)),1);seg_ay(i,:)=Ra((Tmax(i):(Tmax(i)+frame-1)),2);seg_az(i,:)=Ra((Tmax(i):(Tmax(i)+frame-1)),3);
    seg_gx(i,:)=Rg((Tmax(i):(Tmax(i)+frame-1)),1);seg_gy(i,:)=Rg((Tmax(i):(Tmax(i)+frame-1)),2);seg_gz(i,:)=Rg((Tmax(i):(Tmax(i)+frame-1)),3);
    seg_qx(i,:)=Rq((Tmax(i):(Tmax(i)+frame-1)),1);seg_qy(i,:)=Rq((Tmax(i):(Tmax(i)+frame-1)),2);seg_qz(i,:)=Rq((Tmax(i):(Tmax(i)+frame-1)),3);seg_qw(i,:)=Rq((Tmax(i):(Tmax(i)+frame-1)),4);
end
csvwrite('step_seg_ax.csv',seg_ax);csvwrite('step_seg_ay.csv',seg_ay);csvwrite('step_seg_az.csv',seg_az);
csvwrite('step_seg_gx.csv',seg_gx);csvwrite('step_seg_gy.csv',seg_gy);csvwrite('step_seg_gz.csv',seg_gz);
csvwrite('step_seg_qx.csv',seg_qx);csvwrite('step_seg_qy.csv',seg_qy);csvwrite('step_seg_az.csv',seg_qz);csvwrite('step_seg_qw.csv',seg_qw);
%% -----end-----

[d.rx,d.ry,d.rz]= CaculateVar(Ra(:,1),Ra(:,2),Ra(:,3));
[d.rx_1,d.ry_1,d.rz_1]= CaculateVar(R2(:,1),R2(:,2),R2(:,3)); 

[x,y,z]= CaculateVar(Rw(:,1),Rw(:,2),Rw(:,3)); 


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

