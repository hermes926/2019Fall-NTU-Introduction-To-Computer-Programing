#include<stdio.h> 

main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int d=a*b*c;
	int e=2*((a*b)+(a*c)+(b*c));
	
	printf("%d\n%d\n",e,d);
	
return 0;
}
