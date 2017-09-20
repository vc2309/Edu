function J = Cost(x,y,th)
m=size(x,1);
preds=x*th;
err=(preds-y).^2;
J=sum(err)/(2*m)