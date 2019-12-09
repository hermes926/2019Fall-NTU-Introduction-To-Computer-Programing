#include<stdio.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int score[b][7];
    for(int c=0;c<b;c++){
        score[c][6]=0;
        for(int d=0;d<6;d++){
            scanf("%d",&score[c][d]);
           
            if(d>0){score[c][6]+=score[c][d];}
            
        }
        //printf("%d\n",score[c][6]);
    }
    for(int c=0;c<b;c++){
        for(int d=0;d<c;d++){
            if(score[d][6]<score[c][6]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
            else if(score[d][6]==score[c][6]&&score[d][1]<score[c][1]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
            else if(score[d][6]==score[c][6]&&score[d][1]==score[c][1]&&score[d][2]<score[c][2]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
            else if(score[d][6]==score[c][6]&&score[d][1]==score[c][1]&&score[d][2]==score[c][2]&&score[d][3]<score[c][3]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
            else if(score[d][6]==score[c][6]&&score[d][1]==score[c][1]&&score[d][2]==score[c][2]&&score[d][3]==score[c][3]&&score[d][4]<score[c][4]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
            else if(score[d][6]==score[c][6]&&score[d][1]==score[c][1]&&score[d][2]==score[c][2]&&score[d][3]==score[c][3]&&score[d][4]==score[c][4]&&score[d][5]<score[c][5]){
                int tem[7];
                for(int e=0;e<7;e++){tem[e]=score[c][e];score[c][e]=score[d][e];score[d][e]=tem[e];}
            }
        }
    }

    int con=0,z=1;
        while(con==0){
            if(score[a-1][6]==score[a-1+z][6]&&score[a-1][1]==score[a-1+z][1]&&score[a-1][2]==score[a-1+z][2]&&score[a-1][3]==score[a-1+z][3]&&score[a-1][4]==score[a-1+z][4]&&score[a-1][5]==score[a-1+z][5])
                a++;
            else{
                con++;
            }    
            
        }
        
    
    for(int c=0;c<a;c++){
       printf("%d\n",score[c][0]); 
    }


    
    
    return 0;
}