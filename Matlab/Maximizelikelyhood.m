%%
clc;  
clear;  
close all;  
%%每100个点取一次均值，一次方差 
%% X[ax ay az gx gy gz] -> X[]
global d;global p;
d.raw_Data = randi([-10.0,10.0],[10000,3]);
d.raw_Data1 = randi([-15.0,15.0],[10000,3]);
d.testdata = randi([-20.0,15.0],[200,3]);

[d.x,d.y,d.z]= CaculateVar(d.raw_Data(:,1),d.raw_Data(:,2),d.raw_Data(:,3));
[d.x1,d.y1,d.z1]= CaculateVar(d.raw_Data1(:,1),d.raw_Data1(:,2),d.raw_Data1(:,3));
[x,y,z]= CaculateVar(d.testdata(:,1),d.testdata(:,2),d.testdata(:,3));

d.Acc=[d.x' d.y' d.z']; scatter3(d.x',d.y',d.z','*','b');hold;
d.Acc1=[d.x1' d.y1' d.z1']; scatter3(d.x1',d.y1',d.z1','.','r');
%% FFT
fs=100;
figure;
hua_fft(d.x1,fs,1);
N=length(d.x1);
y_1=abs(fft(d.x1));
f=(1:N)*fs/N;
plot(f,abs(y_1));
%% PCA 计算原来样本矩阵的协方差矩阵
%% X:校正集的原始数据 latent：特征值（已从大到小排列） pc：特征向量（主成分系数） score：主成分
pcadata=[d.Acc d.Acc1 d.Acc1]; 
[p.coeff, p.score, p.latent, p.tsquared, p.explained, p.mu] = pca(pcadata);

%%
traindata=[d.Acc; d.Acc1];
label=[ones(1,length(d.x)) zeros(1,length(d.x1))]';
d.testdata = [x; y; z]; %%scatter3(x,y,z,'O','d');
svm_struct = svmtrain(traindata,label,'kernel_function','rbf','method' ,'SMO'); %%training 
Group = svmclassify(svm_struct,d.testdata);  
%%hold on;  

%%plot(testdata(:,1),testdata(:,2),'ro','MarkerSize',12);       % testing  
%%hold off  

function [X,Y,Z]= CaculateVar(x,y,z)
    X=[];Y=[];Z=[]; ax=[];ay=[];az=[];
    for i = 1:(length(x)/50-1)     %% 1~20
        for j=((i-1)*50+1):((i-1)*50+100)   %% 1~100  51~150 ...951~1050
            ax= [ax x(j)];ay= [ay y(j)];az= [az z(j)];
        end
         X=[X var(ax)]; Y=[Y var(ay)];Z=[Z var(az)];
         ax=0;ay=0;az=0;
    end
end





