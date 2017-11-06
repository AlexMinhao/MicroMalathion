%%load raw position 
sen= csvread('2_sensor.csv');  %删去前750点 删去4000后点
raw=csvread('2_vicon.csv');
global s A B C O;
A.x=raw(:,1);A.y=raw(:,2);A.z=raw(:,3);
B.x=raw(:,4);B.y=raw(:,5);B.z=raw(:,6);
C.x=raw(:,7);C.y=raw(:,8);C.z=raw(:,9);
O.x=(A.x+B.x+C.x)/3;O.y=(A.y+B.y+C.y)/3;O.z=(A.z+B.z+C.z)/3;
%%-------------Sensor value-----------
s.ax=sen(:,2);s.ay=sen(:,3);s.az=sen(:,4);%% Acc
s.gx=sen(:,5);s.gy=sen(:,6);s.gz=sen(:,7);%% Gyo
%s.qx=sen(:,8);s.qy=sen(:,9);s.qz=sen(:,10);s.qw=sen(:,11);%% Qut

fs=200;
b = fir1(fs, 2/fs*2, 'low');  %2.2hz 低通滤波器
s.ax = filtfilt(b,1,s.ax);s.ay = filtfilt(b,1,s.ay);s.az = filtfilt(b,1,s.az);
% subplot(322);plot(s.ax);
% subplot(324);plot(s.ay);
% subplot(326);plot(s.az);
Degree=caculate_angle(s);
%%-----------------FFT----------------------%%
%fs=200;
%b = fir1(fs, 0.5/fs*2, 'low');  %2.2hz 低通滤波器
%b = fir1(fs, 25/fs*2, 'high');   %5hz  高通滤波器
%Degree(:,1) = filtfilt(b,1,Degree(:,1));Degree(:,2) = filtfilt(b,1,Degree(:,2));Degree(:,3) = filtfilt(b,1,Degree(:,3));                %%低通
%figure;
% subplot(311);hua_fft(Degree(:,1),fs,1);
% subplot(312);hua_fft(Degree(:,2),fs,1);
% subplot(313);hua_fft(Degree(:,3),fs,1);
%%-----------------END----------------------%%
figure;
subplot(3,2,1);plot(Degree(:,1));title('sensor_x轴的倾斜角度');
subplot(3,2,3);plot(Degree(:,2));title('sensor_y轴的倾斜角度');
subplot(3,2,5);plot(Degree(:,3));title('sensor_z轴的倾斜角度');
%plot_triangle(A,B,C,O);
%O.angle=transfer_angle(O);
%subplot(4,1,4);plot(O.angle');title('vicon');

[Nx,Ny,Nz,M]= normal_vector(A,B,C);
[a1,a2,a3]=vector_angle(Nx,Ny,Nz);

function [degree]=caculate_angle(acc)
    count=length(acc.ax);
    degree= zeros(count,3);
    for i=1:count      
        R =sqrt((acc.ax(i)).^2+(acc.ay(i)).^2+(acc.az(i)).^2);
        %% caculate angle
        dx = 180-acos(acc.ax(i)/R) * 180 / pi;
        dy = acos(acc.ay(i)/R) * 180 / pi; 
        dz = acos(acc.az(i)/R) * 180 / pi; %将弧度转换为角度
        degree(i,1)=dx;degree(i,2)=dy;degree(i,3)=dz;
    end
 
end
function [angle]=transfer_angle(p)
    angle=[];
    for i=1:(length(p.x)-1)
        M= [p.x(i) p.y(i) p.y(i)]; N= [p.x(i+1) p.y(i+1) p.y(i+1)]; 
        Q=acos(dot(M,N)/(norm(M)*norm(N)))*180/pi;
        angle=[angle Q];
    end
   
end

function [dx,dy,dz,m]= normal_vector(p1,p2,p3,p4)
    dx=[];dy=[];dz=[]; m=zeros(length(p1.x),2);     %p1p3=p3-p1  p1p2=p2-p1
    for i = 1:(length(p1.x))  
        p1_p2=[p2.x(i)-p1.x(i) p2.y(i)-p1.y(i) p2.z(i)-p1.z(i)];
        p1_p3=[p3.x(i)-p1.x(i) p3.y(i)-p1.y(i) p3.z(i)-p1.z(i)];
        n=cross(p1_p2,p1_p3);
        n=n/norm(n);
        m(i,1)=p1_p2*n';m(i,2)=p1_p3*n';
        dx=[dx n(1)];dy=[dy n(2)];dz=[dz n(3)];
        %subplot(211);plot(m(:,1));
        %subplot(212);plot(m(:,2));
    end
end

function [theta_1,theta_2,theta_3]=vector_angle(x,y,z)
    theta_1=[];theta_2=[];theta_3=[];
    for i = 1:(length(x))
        n=[x(i) y(i) z(i)];
        theta_1= [theta_1 acos(x(i)/norm(n))*180/pi];theta_2= [theta_2 acos(y(i)/norm(n))*180/pi];theta_3= [theta_3 acos(z(i)/norm(n))*180/pi];
    end
    subplot(3,2,2);plot(theta_1);title('vicon_x轴夹角');
    subplot(3,2,4);plot(theta_2);title('vicon_y轴夹角');
    subplot(3,2,6);plot(theta_3);title('vicon_z轴夹角');
end


function [] = plot_triangle( p1, p2, p3,p4, fig_handle)
    if nargin < 10
        fig_handle = figure;
    end
    figure(fig_handle);
    for i = 1:(length(p1.x)) 
        subplot(121);
        %line([p1.x(i) p2.x(i)], [p1.y(i) p2.y(i)],[p1.z(i) p2.z(i)], 'Color', 'r', 'LineWidth', 1.5);
        %line([p2.x(i) p3.x(i)], [p2.y(i) p3.y(i)],[p2.z(i) p3.z(i)], 'Color', 'r', 'LineWidth', 1.5);
        %line([p3.x(i) p1.x(i)], [p3.y(i) p1.y(i)],[p3.z(i) p1.z(i)], 'Color', 'r', 'LineWidth', 1.5);
        line([p1.x(1)-p1.x(1) p2.x(1)-p1.x(1)], [p1.y(1)-p1.y(1) p2.y(1)-p1.y(1)],[p1.z(1)-p1.z(1) p2.z(1)-p1.z(1)], 'Color', 'r', 'LineWidth', 1.5);
        line([p2.x(1)-p1.x(1) p3.x(1)-p1.x(1)], [p2.y(1)-p1.y(1) p3.y(1)-p1.y(1)],[p2.z(1)-p1.z(1) p3.z(1)-p1.z(1)], 'Color', 'r', 'LineWidth', 1.5);
        line([p3.x(1)-p1.x(1) p1.x(1)-p1.x(1)], [p3.y(1)-p1.y(1) p1.y(1)-p1.y(1)],[p3.z(1)-p1.z(1) p1.z(1)-p1.z(1)], 'Color', 'r', 'LineWidth', 1.5);
        subplot(122);scatter3(p4.x(i),p4.y(i),p4.z(i),'o','b');
        hold on;
    end  
end

