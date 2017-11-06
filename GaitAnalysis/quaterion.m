  f1=10;%第一个点频信号分量频率
        f2=30;%第二个点频信号分量频率
        fs=100;%采样率
        T=8;%时宽
        B=20;%带宽
        n=round(T*fs);%采样点个数
        t=linspace(0,T,n);
        y=cos(2*pi*f1*t)+cos(2*pi*f2*t);
             plot(t,y);
        title('原始信号时域');
        xlabel('t/s');
        ylabel('幅度');
        figure;
        fft_y=fftshift(fft(y));
        f=linspace(-fs/2,fs/2,n);
        plot(f,abs(fft_y));
        title('原始信号频谱');
        xlabel('f/Hz');
        ylabel('幅度');
        axis([ 0 50 0 100]);
        figure;
         s=csvread('signal_filtered.csv');
         fft_s=fftshift(fft(s));
         plot(abs(fft_s));
         plot(s);
  