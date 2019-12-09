#include<stdio.h>
#include<stdbool.h>

/*int magic(int num, int xs,int ys, int zs, int x, int y, int z, int xcount, int ycount, int zcount){
    int final=0;
    if((num==x && xs>0)||(num==z && zs>0)||(num==y && ys>0)||num==0){
        return 1;
    }
    else if(x>num && y>num && z>num){
        return 0;
    }
    else if(xs==0 && ys==0 && zs==0){
        return 0;
    }
    else{
        if(xs>0 && num>=x && ((xcount <= ycount && xcount <= zcount)||(z==0 && y==0))){
            xs--;xcount++;
            final+=magic(num-x,xs,ys,zs,x,y,z, xcount, ycount, zcount);
        }
        else if(ys>0 && num>=y && (ycount <= zcount || z==0)){
            ys--;ycount++;
            final+=magic(num-y,xs,ys,zs,x,y,z,xcount, ycount, zcount);
        }
        else if(zs>0 && num>=z){
            zs--;zcount++;
            final+=magic(num-z,xs,ys,zs,x,y,z,xcount, ycount, zcount);
        }
        //printf("fin:%d\n",final);
        return final;
    }
}*/


int main(){
    int a=0;
    scanf("%d",&a);
    
    for(int c=0;c<a;c++){
        int num,xs,ys,zs,x,y,z;bool found = false;
        scanf("%d%d%d%d%d%d%d", &num, &xs, &ys, &zs, &x, &y, &z);
        long long int sum = 0,tempxsum = 0, tempysum = 0;
        for(int i=0;i<=xs;i++){
            sum = 0;
            sum += (x*i);
            tempxsum = sum;
            if(sum > num)
                break;
            for(int j=0;j<=ys;j++){
                sum = tempxsum + (y*j);
                tempysum = sum;
                if(sum > num)
                    break;
                for(int k=0;k<=zs;k++){
                    sum = tempysum + (z*k);
                    //printf("%d---\n", sum);
                    if(sum > num)
                        break;
                    if(sum == num){
                        found = true; break;
                    }

                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        found ? printf("yes\n") : printf("no\n");    
    }
    

    return 0;
}