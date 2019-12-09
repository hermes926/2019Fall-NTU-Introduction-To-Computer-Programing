#include<stdio.h>
#include<string.h>

int min(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}

int letter(char a[11], char b[11], int count, int mini){
    if(count > mini)
        return 1000;
    char aa[11], bb[11];
    memcpy(aa, a+1, strlen(a));
    memcpy(bb, b+1, strlen(b));
    if(strlen(a) == 0)
        return strlen(b);
    else if(strlen(b) == 0)
        return strlen(a);
    else if(a[0] == b[0]){
        return letter(aa, bb, count, mini);
    }
    else{
        return (1+min(letter(aa, b, count+1, mini), letter(bb,a, count+1, mini)));
    }
}

int main(){
    char in[100][11];
    scanf("%s", in[0]);
    int i=1;int mini=1000, ID1=1000, ID2=1000;
    while(scanf("%s", in[i])!=EOF){ 
        i++;
    }
    for(int k=1;k<i;k++){
        for(int j=0;j<k;j++){
            int t = letter(in[k], in[j], 0 ,mini);
            if(t < mini || (t == mini && j<ID1)){
                mini = t;
                ID1 = j;ID2 = k;
            }
        }
    }
    printf("%d %d %d\n", mini, ID1+1, ID2+1);


    return 0;
}