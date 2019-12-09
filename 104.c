#include<stdio.h>
#include<stdbool.h>

bool per(int a,int b,int c,int da, int db, int dc,int ea,int eb,int ec,int fa,int fb,int fc){
    bool final = true;
    if((a==da && b==db && c==dc) || (a==ea && b==eb && c==ec) || (a==fa && b==fb && c==fc)){
        return 1;
    }
    else if((a<da || b<db || c<dc) && (a<ea || b<eb || c<ec) && (a<fa || b<fb || c<fc)){
        return 0;
    }
    else{
        return per(a-da, b-db,c-dc, da, db, dc, ea, eb, ec, fa, fb, fc) + per(a-fa, b-fb,c-fc, da, db, dc, ea, eb, ec, fa, fb, fc) +per(a-ea, b-eb,c-ec, da, db, dc, ea, eb, ec, fa, fb, fc);
    }
}

#define abc f##or

int main(){
    int da, db, dc, ea, eb, ec, fa, fb, fc, n;
    scanf("%d%d%d%d%d%d%d%d%d%d",&da, &db, &dc, &ea, &eb, &ec, &fa, &fb, &fc, &n);
    int a,b,c;
    abc(int d=0;d<n;d++){
        scanf("%d%d%d",&a,&b,&c);
        bool anw = per(a, b,c, da, db, dc, ea, eb, ec, fa, fb, fc);
        anw ? printf("yes\n") : printf("no\n");

    }
    return 0;
}