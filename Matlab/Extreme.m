function [V,T]=Extreme(v)
t = 0:length(v)-1;
Lmax = diff(sign(diff(v)))== -2; % logic vector for the local max value
Lmin = diff(sign(diff(v)))==  2; % logic vector for the local min value
% match the logic vector to the original vecor to have the same length
Lmax = [false; Lmax; false];
Lmin =  [false; Lmin; false];
tmax = t (Lmax); % locations of the local max elements
tmin = t (Lmin); % locations of the local min elements
vmax = v (Lmax); % values of the local max elements
vmin = v (Lmin); % values of the local min elements
% find the frame
L = sign(diff(vmax));
for i=1:length(L)
    if L(i)<0
        L(i)=0;
    end
end
L = logical([false;L]);
T = tmax(L);
V = vmax(L);
% plot them on a figure
plot(t,v); 
xlabel('t'); ylabel('v');
hold on;
plot(tmax, vmax, 'r+');
plot(tmin,vmin, 'g+');
hold off;
end
