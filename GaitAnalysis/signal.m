t = 0.01:0.01:10;
fs=100;%采样率
T=10;%时宽
n=round(T*fs);%采样点个数
t1=linspace(0,100,n);
f =2*sin(2*pi*20*t)+4*sin(2*pi*30*t);
fft_init = abs(fft(f));
N = 30 ;               %滤波器节点个数

wc = 0.5;              %归一化截止频率

hd = fir1(N,25/(fs/2),'low'); % 基于加窗函数的FIR滤波器设计

ft = conv(f,hd);
%ft =filtfilt(hd,1,f);

figure(1)

plot(t1,fft_init);

title('原始信号f');

figure(2)
t2=linspace(0,100,1030);
plot(t2,abs(fft(ft)));

title('滤波后信号ft');