#include<stdio.h>
#include<string.h>

int main(){
    char a[15];int w,h;
    while(scanf("%s%d%d",a, &w, &h)!=EOF){
        for(int hn=0;hn<h;hn++){
            for(int wow=0;wow<strlen(a);wow++){
                int nown=a[wow]-48;
                for(int width=0;width<w;width++){
                    if(hn==0){
                        switch(nown){
                            case 0: case 2: case 3: case 5: case 6: case 7: case 8: case 9:
                                if(width==0 || width==w-1 || width ==w-2){printf(" ");}
                                else if(width>0 && width<=w-3){printf("%d",nown);}break;
                            case 1: case 4:
                                printf(" ");}
                    }
                    else if(hn==h-1){
                        switch(nown){
                            case 0:case 2:case 3:case 5: case 6:case 8:
                                if(width==0 || width==w-1 || width ==w-2){printf(" ");}
                                else if(width>0 && width<=w-3){printf("%d",nown);}break;
                            default:
                                printf(" ");
                        }
                    }
                    else if(hn==(h-1)/2){
                        switch(nown){
                            case 9:case 2:case 3:case 5: case 6:case 8:case 4:
                                if(width==0 || width==w-1 || width ==w-2){printf(" ");}
                                else if(width>0 && width<=w-3){printf("%d",nown);}break;
                            default:
                                printf(" ");
                        }
                    }
                    else if(hn<(h-1)/2 && hn>0){
                        switch(nown){
                            case 0:case 4:case 7:case 8: case 9:
                                if(width==0 || width==w-2){printf("%d",nown);}
                                else{printf(" ");}break;
                            case 1:case 2:case 3:
                                if(width==w-2){printf("%d",nown);}
                                else{printf(" ");}break;
                            default:
                                if(width!=0){printf(" ");}
                                else{printf("%d",nown);}
                        }
                    }
                    else if(hn>(h-1)/2 && hn<h-1){
                        switch(nown){
                            case 0:case 6:case 8:
                                if(width==0 || width==w-2){printf("%d",nown);}
                                else{printf(" ");}break;
                            case 1:case 4:case 3:case 5:case 7:case 9:
                                if(width==w-2){printf("%d",nown);}
                                else{printf(" ");}break;
                            default:
                                if(width!=0){printf(" ");}
                                else{printf("%d",nown);}
                        }
                        
                    }
                    
                }
               
            }
             printf("\n");
        }
    }
    
    return 0;
}