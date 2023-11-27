clear all
close all

x = [200, 400, 800, 1600, 3200]
y = [267.24, 482.03, 1232.49, 2505.07, 5375.61;
	141.76, 270.05, 633.23, 1316.20, 2417.55;
	73.79, 141.34, 275.87, 452.55, 1091.34;
	47.02, 85.17, 151.06, 270.67, 577.27]
p = [1; 2; 4; 8]
m = size(y, 1)
n = size(y, 2)
serial = y(1, :);
temp = 1 ./ y
s = temp .* serial
e = s ./ p

plot(x, e)
xlabel("n/千")
ylabel("Efficiency")
title("Odd-Even-Sort")
legend("1","2","4","8");
print( "Efficiency", '-dpng' );
