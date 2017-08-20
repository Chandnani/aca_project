clear
acc = zeros(40,1);
load mnist.mat;
for k = 1:40
a = zeros(10,784);
s = k*50;
for i=1:10
a(i:i,:) = sum(dataX{i}(1:s,:),1)/s;
end
b = zeros(10,1);
ans=0;
for i = 1:10000
for j=1:10
b(j)=sum(abs(a(j:j,:)-X_test(i:i,:)));
end
[c d] = min(b);
d = d-1;
if d==Y_test(i)
	ans=ans+1;
end
end
acc(k)= ans/10000 ;
end
plot(50*(1:40),acc),ylabel('accuracy'),xlabel('no of training examples'),title('accuracy vs iters')