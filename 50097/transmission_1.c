#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
 
bool buffer[1048576][64];
 
void transmission(long long int belt[] , int N , int T){
 
    T %= 64 * N;
    //printf("%d\n", T);
    long long int * temp = malloc(N * sizeof(long long int));
    memcpy(temp , belt , N * sizeof(long long int));
 
    for(int i = 0; i < N; i++){
        belt[i] = temp[(i + T / 64) % N];
    }
 
    free(temp);
    T %= 64;
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < T; j++){
            buffer[i][j] = (bool)(belt[i] >> (63 - j));
        }
    }
 
    for(int i = 0; i < N; i++)
        belt[i] = (belt[i] << T);
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < T; j++){
            bool bit = buffer[i][j];
            belt[(i + 1) % N] |= ((long long int)bit << (T - j - 1));
        }
    }
}
