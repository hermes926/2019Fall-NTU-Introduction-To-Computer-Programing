#include <stdio.h>
#include "findLength.h"
#define MAXN 256
int main () {
    int array[MAXN][MAXN];
    int N;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
		}}
    int length=0, maxlength=0;
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
			for (int k = 0; k < 4; k++){
        		length=findLength(array, N, i, j, direction[k][0], direction[k][1]);
        		if(length>maxlength){maxlength=length;		}
    }}}
    printf("%d\n",maxlength);
    return 0;
}
