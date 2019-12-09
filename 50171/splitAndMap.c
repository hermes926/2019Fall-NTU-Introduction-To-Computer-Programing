#include<stdio.h>
#include<string.h>
#include "splitAndMap.h"

void splitAndMap(char*** ptr, char* str){
	int i=0;
	
	while(ptr[i] != NULL){
		//printf("%p\n", ptr+i);
		i++;
	}
	//printf("%d\n",i);;
	int lettercount[i]; int strcount[i];
	for(int j=0;j<i;j++){
		lettercount[j]=0;strcount[j]=0;
	}
	char delimeters[] = "*";int min = 0;
	char * start = strtok(str, delimeters);
	while(start != NULL){
		min = 0;
		for(int j=0;j<i;j++){
			if(lettercount[j] < lettercount[min])
				min = j;
		}
		//printf("%d ", i);
		lettercount[min] += strlen(start);
		//printf("%c ", start[min]);
		//printf("%d %d\n", min,strcount[min]);
		*(*(ptr+min)+strcount[min]) = start;
		strcount[min]++;
		
		printf("%s \n", start);
		start = strtok(NULL, delimeters);	
	}
	for(int j=0;j<i;j++){
		*(*(ptr+j)+strcount[j]) = NULL;
	}
}
