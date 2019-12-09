#include<stdio.h>
#include "fill_array.h"

void fill_array(int *ptr[], int n){
	int z=0;int preva=0,a=0,con=0;
	while((ptr[0]+z)<=ptr[n-1]){
		con=0;
		for(int c=0;c<n;c++){
			if((ptr[0]+z)==ptr[c]){
				con=1;
				*(ptr[0]+z)=c;
			}
		}
		//printf("%d\n",con);
		if(con==1){
			for(int c=preva+1;c<z;c++){
				*(ptr[0]+c)=*(ptr[0]+preva)+*(ptr[0]+z);
				//printf("%d %d %d\n",*ptr[c],*ptr[preva],*ptr[z]);
			}
			preva=z;
		}
		
		
		
		z++;
	}
	
}
 
