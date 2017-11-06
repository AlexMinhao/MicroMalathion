%%load raw position 
sen= csvread('2_sensor.csv');  %删去9500后的点，和前2350  
raw=csvread('2_vicon.csv');
global s A B C O;
A.x=raw(:,1);A.y=raw(:,2);A.z=raw(:,3);
B.x=raw(:,4);B.y=raw(:,5);B.z=raw(:,6);
C.x=raw(:,7);C.y=raw(:,8);C.z=raw(:,9);
O.x=(A.x+B.x+C.x)/3;O.y=(A.y+B.y+C.y)/3;O.z=(A.z+B.z+C.z)/3;
s.ax=sen(:,2);s.ay=sen(:,3);s.az=sen(:,4);
s.gx=sen(:,5);s.gy=sen(:,6);s.gz=sen(:,7);%% Gyo

%%---------------FFT
fs=100;
b = fir1(fs, 49/fs*2, 'low');  %2.2hz 低通滤波器
%b = fir1(fs, 40/fs*2, 'high');   %5hz  高通滤波器
s.gx = filtfilt(b,1,s.gx);s.gy = filtfilt(b,1,s.gy);s.gz = filtfilt(b,1,s.gz);  
%  figure;
%  subplot(311);hua_fft(s.gx,fs,1);
%  subplot(312);hua_fft(s.gy,fs,1);
%  subplot(313);hua_fft(s.gz,fs,1);
%%----------------END
interval=0.02;
theta0=[90 90 0];
Degree=caculate_angle(theta0,interval,s);

subplot(321);plot(s.gx);
subplot(323);plot(s.gy);
subplot(325);plot(s.gz);
subplot(322);plot(180-Degree(:,1));
subplot(324);plot(Degree(:,2));
subplot(326);plot(Degree(:,3));

%%---------------Angle
function [degree]=caculate_angle(theta_0,Interval,acc)
    count=length(acc.gx);
    degree= zeros(count,3);
    theta_x=theta_0(1);theta_y=theta_0(2);theta_z=theta_0(3);
    for i=1:count      
       dx=(acc.gx(i)-mean(acc.gx))*Interval* 180 / pi;dy=(acc.gy(i)--mean(acc.gy))*Interval* 180 / pi;dz=(acc.gz(i)-mean(acc.gz))*Interval* 180 / pi;
       %% caculate angle
       gyo_x=theta_x+dx;gyo_y=theta_y+dy;gyo_z=theta_z+dz; 
%        if(gyo_x>180) 
%            gyo_x=360-gyo_x; 
%        end
%        if(gyo_x<0)
%            gyo_x=-gyo_x;
%        end
%        if(gyo_y>180) gyo_y=360-gyo_y; end
%        if(gyo_y<0)
%            gyo_y=-gyo_y;
%        end
%        if(gyo_z>180) gyo_z=360-gyo_z; end
%        if(gyo_z<0)
%            gyo_z=-gyo_z;
%        end
       degree(i,1)=gyo_x;degree(i,2)=gyo_y;degree(i,3)=gyo_z;
       theta_x=gyo_x;theta_y=gyo_y;theta_z=gyo_z;
    end
end
%%---------------END