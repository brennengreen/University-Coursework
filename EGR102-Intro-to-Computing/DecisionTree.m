rough = xlsread("sandyboi.xlsx");
medium = xlsread("greensheet.xlsx");
smooth = xlsread("polymer.xlsx");

train = [rough;medium;smooth];

result(1:10) = 1;
result(11:20) = 2;
result(21:30) = 3;
result = result';

Mdl = fitctree(train, result);

view(Mdl,'mode','graph');
