s1= csvread('raw_gyo.csv'); 
s2= csvread('signal_filtered.csv');
fs=100;
b = fir1(fs, 5/fs*2, 'low');
s3=filtfilt(b,1,s1);
subplot(311);plot(s1);subplot(312);plot(s2(101:13903));subplot(313);plot(s3);