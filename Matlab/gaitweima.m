sen4= csvread('run_1104.csv');  
global r2
r2.ax=sen4(:,1);r2.ay=sen4(:,2);r2.az=sen4(:,3);
r2.gx=sen4(:,4);r2.gy=sen4(:,5);r2.gz=sen4(:,6);%% Gyo
r2.qx=sen4(:,7);r2.qy=sen4(:,8);r2.qz=sen4(:,9);r2.qw=sen4(:,10); %% Q
r2.click =sen4(:,11);
%% Running
fs=100;
Ra=[r2.ax(800:11000) r2.ay(800:11000) r2.az(800:11000)];
Rg=[r2.gx(800:11000) r2.gy(800:11000) r2.gz(800:11000)];
Rq=[r2.qx(800:11000) r2.qy(800:11000) r2.qz(800:11000) r2.qw(800:11000)];
%subplot(311);hua_fft(R1(:,1),fs,1);subplot(312);hua_fft(R1(:,2),fs,1);subplot(313);hua_fft(R1(:,3),fs,1);
%subplot(311);hua_fft(Ra(:,1),fs,1);title('ax');subplot(312);hua_fft(Ra(:,2),fs,1);title('ay');subplot(313);hua_fft(Ra(:,3),fs,1);title('az');
R2=[r2.ax r2.ay r2.az]; 
%% ---------------Filtered-FFT--------------------
b = fir1(fs, 5/fs*2, 'low');  %2.2hz 低通滤波器
%b = fir1(fs, 2/fs*2, 'high');   %5hz  高通滤波器
%b1 = fir1(fs, [0.2/fs*2,1/fs*2], 'stop');  %48~52hz 带阻滤波器 
Raf(:,1) = filtfilt(b,1,Ra(:,1));Raf(:,2) = filtfilt(b,1,Ra(:,2));Raf(:,3) = filtfilt(b,1,Ra(:,3));%
Rgf(:,1) = filtfilt(b,1,Rg(:,1));Rgf(:,2) = filtfilt(b,1,Rg(:,2));Rgf(:,3) = filtfilt(b,1,Rg(:,3));

 subplot(311);hua_fft(Raf(:,1),fs,1);title('3HZ');subplot(312);hua_fft(Raf(:,2),fs,1);subplot(313);hua_fft(Raf(:,3),fs,1);
%%
% az = Raf(:,3);
% gz = Rgf(:,3);
% t = 0:length(az)-1;
% figure;
% plot(t,az); 
% xlabel('t'); ylabel('az');
% figure;
% plot(t,gz); 
% xlabel('t'); ylabel('gz');
%%-0.4800   -0.5626   -0.5435   -0.3970
% Q1 = [-0.4800   -0.5626   -0.5435   -0.3970];
Q1 = [-0.707   0   0   -0.707];
Q1=Q1/norm(Q1);

ax=[];ay=[];az=[];an=[];
for i = 1:(length(Rq(:,1)))
   Qc=[Rq(i,1) Rq(i,2) Rq(i,3) Rq(i,4)];
   Qc=Qc/norm(Qc);
   %Qd=quatmultiply(quatinv(Q1),Qc); %diff
   Qd=quatmultiply(Qc,quatinv(Q1));
   Acc=[Ra(i,1) Ra(i,2) Ra(i,3)];
   Acc=[Acc 0];
   Acc_c=quatmultiply(quatinv(Qd),Acc);
   Acc_c=quatmultiply(Acc_c,Qd);
%    Acc_c=quatmultiply(quatinv(Qd),Acc);
%    Acc_c=(R*[Acc_c(1) Acc_c(2) Acc_c(3)]')';
   %Acc_c=[Acc_c(1) Acc_c(2) Acc_c(3)];
   ax=[ax Acc_c(1)];ay=[ay Acc_c(2)];az=[az Acc_c(3)];%A.accn=[A.accn Acc_c(4)];
end

V=[];
for i = 1:length(az)
    for j = 1:i
        v = sum(az(j))/100;
    end
    V=[V v];
end

figure;plot(V);title('sensor校准后横向加速度');

a0z=Ra(:,3); %%原始z加速度
g0z=Rg(:,3);
azf = filtfilt(b,1,a0z); %%滤波z加速度
gzf = filtfilt(b,1,g0z); %%滤波z角速度
t = 1:length(r2.click);
figure; plot(azf);title('sensor滤波z轴的加速度');hold on;scatter(t,r2.click*2.5,'b','*');
figure; plot(gzf);title('sensor滤波z轴的角速度');hold on;scatter(t,r2.click*9,'b','*');
% figure;subplot(211);hua_fft(az,fs,1);subplot(212);hua_fft(azf,fs,1);