#include <stdio.h>
#include "stationDistance.h"
#define MAXN 10000
 
int main(int argc, char const *argv[])
{
    int R_distance[MAXN]={0};
    int G_distance[MAXN]={0};
    int B_distance[MAXN]={0};
    int G_origin,G_destination;
    int startStation[2],endStation[2];
 
    int Rindex,Gindex,Bindex;
    Rindex =0; 
    while(scanf("%d",&R_distance[Rindex])){
        if( R_distance[Rindex]==0){
            break;
        }
        Rindex++;
    }
    Gindex=0;
    while(scanf("%d",&G_distance[Gindex])){
        if( G_distance[Gindex]==0){
            break;
        }
        Gindex++;
    }    
    Bindex=0;
    while(scanf("%d",&B_distance[Bindex])){
        if( B_distance[Bindex]==0)
            break;
        Bindex++;
    }
    scanf("%d%d",&G_origin,&G_destination);
    scanf("%d%d",&startStation[0],&startStation[1]);
    scanf("%d%d",&endStation[0],&endStation[1]);
    int distanceSum =stationDistance(R_distance,G_distance,B_distance,G_origin,G_destination,startStation,endStation);
    printf("%d\n",distanceSum );
}
