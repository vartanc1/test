

%1 Problem
V = [0.958 2.004 3.004 4.01 5.00 6.01];
i = [5.01 10.47 15.70 21.05 26.21 31.50]; % mA
i2 = i /10q 00; %Amps
hold off;
plot(V,i2,"x");hold on;
ylabel("Current (i)");
xlabel("Voltage (V)");

R = V./i2;
resistanceAverage = mean(R);


p = polyfit(V,i2,1);
G = p(1);
intercept_value = p(2);
Resistance = 1/G % ohm
n = length(i);
plot(V,p(1)*V+p(2),'-');

epsilon=sqrt(sum((i2-p(1)*V-p(2)).^2)/(n-2));
delta=n*sum(V.^2)-(sum(V))^2;
sigG=sqrt(n*epsilon^2/delta);

sigR=sigG/G^2  %ohm


% #2 Problem
V2 = [0.769 0.872 0.913 0.936 0.950];
i3 = [21.71 12.47 8.67 6.68 5.42];
i4 = i3 * 10^-3;

R2 = V2./i4;
resistivity = 1/(1.45*10^6);

A = resistivity/G;
%d= sqrt(4*A/pi);


