#include<stdio.h>
#include "value.h"

main(){
	int a,b,c,d;int e=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=value(a,b,c,d);
	printf("%d\n",e);
	return 0;
}
