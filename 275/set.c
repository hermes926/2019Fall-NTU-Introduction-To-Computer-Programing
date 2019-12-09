#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "set.h"

typedef unsigned long long Set;
void init(Set *set){
	*set = 0;
}
void add(Set *set, int i){
	//printf("%ld ",*set);
	unsigned long long int a=1;
	a = a << i;
	*set = (*set | a);
	
}
void has(Set set, int i){
	((set >> i) % 2 == 1) ? printf("set has %d\n",i) : printf("set does not have %d\n",i);
	
}

Set setUnion(Set a, Set b){
	Set c= (a|b);
	return c;
}
Set setIntersect(Set a, Set b){
	Set c= (a&b);
	return c;
}
Set setDifference(Set a, Set b){
	Set c=(a^b);
	return c;
}
