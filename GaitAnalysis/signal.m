t = 0.01:0.01:10;
fs=100;%������
T=10;%ʱ��
n=round(T*fs);%���������
t1=linspace(0,100,n);
f =2*sin(2*pi*20*t)+4*sin(2*pi*30*t);
fft_init = abs(fft(f));
N = 30 ;               %�˲����ڵ����

wc = 0.5;              %��һ����ֹƵ��

hd = fir1(N,25/(fs/2),'low'); % ���ڼӴ�������FIR�˲������

ft = conv(f,hd);
%ft =filtfilt(hd,1,f);

figure(1)

plot(t1,fft_init);

title('ԭʼ�ź�f');

figure(2)
t2=linspace(0,100,1030);
plot(t2,abs(fft(ft)));

title('�˲����ź�ft');