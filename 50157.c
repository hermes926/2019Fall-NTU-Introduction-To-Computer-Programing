#include<stdio.h>

int main(){
	int k;
	scanf("%d",&k);
	int a=0;int wa=0,fi=0,wi=0;int ma1=0,ma2=0,fm=0;int count=0;
	while(scanf("%d",&a)!=EOF){
		count++;
        if(a%3==0){wa++;		}
		else if(a%3==1){fi++;		}
		else{wi++;		}
		
		if(a>ma1){ma2=ma1;ma1=a;		}
		else if(a<=ma1&&a>ma2){ma2=a;		}
        //printf("%d %d\n",ma1,ma2);
		if(wa>=k&&fi>=k&&wi>=k){
			
            fm+=ma2;
            //printf("%d\n",fm);
            ma1=0;ma2=0;count=0;
			wa=0;fi=0;wi=0;	
		}
	}
	if(count==1){fm+=ma1;}
    else{fm+=ma2;}
	printf("%d\n",fm);
	
	
	return 0;
} 