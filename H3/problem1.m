%BLOCK A
fa = [-2 -1 -2];
A = [2 2 1; 1 2 2; 1 2 2; 1 2 2; 2 2 2;];
va = [9; 9; 9; 9; 9;];
Aeq = []; aeq = []; la = [0 0 0]; ua = [];
[Q,W] = linprog(fa,A,va,Aeq,aeq,la,ua);

%BLOCK B
fb = [-1 -1 -2];
B = [1 2 1; 1 1 2; 1 2 1; 1 1 2; 1 1 2;];
vb = [9; 9; 9; 9; 9;];
Beq = []; beq = []; lb = [0 0 0]; ub = [];
[E,R] = linprog(fb,B,vb,Beq,beq,lb,ub);

%BLOCK C
fc = [-1 -1 -3];
C = [1 3 1; 1 1 3; 1 3 1; 1 1 3; 1 1 3;];
vc = [9; 9; 9; 9; 9;];
Ceq = []; ceq = []; lc = [0 0 0]; uc = [];
[T,Y] = linprog(fc,C,vc,Ceq,ceq,lc,uc);
