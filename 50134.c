#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    if(a==0){
        char order[4];unsigned int in32=0;unsigned short int input16=0;char inch[2]={0};char space;
        while(scanf("%s",order)!=EOF){
            scanf("%u",&in32);scanf("%hu ",&input16);scanf("%c%c",&inch[0],&inch[1]);
            //printf("%s %u %hu %s\n",order,in32,input16,inch);
            unsigned long long int final=0;int chcon=0;
            for(int c=0;c<4;c++){
                
                switch(order[c]){
                    case 'L':
                       // scanf("%u ",&in32);
                        //printf("%u ",in32);
                        final = final << 32;
                        final+=in32;break;
                    case 'S':
                        //scanf("%hu ",&in16);
                        //printf("%hu ",input16);
                        final = final << 16;final+=input16;break;

                    case 'C':
                        //scanf("%c",&inch[chcon]);
                        //printf("%c ",inch[chcon]);
                        final = final << 8;final+=inch[chcon];chcon++;break;
                    default:
                        break;

                }
            }
            printf("%llu\n",final); 
        }
    }
    else if(a==1){
        unsigned long long int input=0;char order[4];
        while(scanf("%s", order)!=EOF){
            scanf("%llu",&input);
            unsigned int o32=0;unsigned short int o16=0;char och[2]={0};
            int chcon=0;
            for(int c=0;c<4;c++){
                switch(order[c]){
                    case 'C':
                        och[chcon]=(input >> 56)%256;
                        input = input << 8;chcon++;break;
                    case 'L':
                        o32=(input >> 48)%(256*256);
                        o32=o32 << 16;
                        o32 += (input >> 32)%(256*256);
                        input = input << 32;break;
                    case 'S':
                        o16=(input >> 48)%(256*256);
                        input = input << 16;break;
                    default:
                        break;
                }
            }
            printf("%u %hu %c%c\n",o32,o16,och[0],och[1]);
        }
    }
    return 0;
}