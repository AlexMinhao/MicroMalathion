  f1=10;%��һ����Ƶ�źŷ���Ƶ��
        f2=30;%�ڶ�����Ƶ�źŷ���Ƶ��
        fs=100;%������
        T=8;%ʱ��
        B=20;%����
        n=round(T*fs);%���������
        t=linspace(0,T,n);
        y=cos(2*pi*f1*t)+cos(2*pi*f2*t);
             plot(t,y);
        title('ԭʼ�ź�ʱ��');
        xlabel('t/s');
        ylabel('����');
        figure;
        fft_y=fftshift(fft(y));
        f=linspace(-fs/2,fs/2,n);
        plot(f,abs(fft_y));
        title('ԭʼ�ź�Ƶ��');
        xlabel('f/Hz');
        ylabel('����');
        axis([ 0 50 0 100]);
        figure;
         s=csvread('signal_filtered.csv');
         fft_s=fftshift(fft(s));
         plot(abs(fft_s));
         plot(s);
  