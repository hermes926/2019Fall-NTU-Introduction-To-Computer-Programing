#include<stdio.h>
#include "value.h"

int value(int type, int width, int height, int length){
	int price;
	switch(type){
		//30,10,4,5,3,9 47,29,82,26,22
		case 79:price=30;break;
		case 47:price=10;break;
		case 29:price=4;break;
		case 82:price=5;break;
		case 26:price=3;break;
		case 22:price=9;break;
		default: price=-1;
	}
	if(((width<=0)||(length<=0)||(height<=0))&&price!=-1){ price=-2;	}
	int x;
	if(price>0){
		for(int a=width;a>0;a=a-1){
			if(width%a==0&&length%a==0&&height%a==0){
			x=a;
			break;
			}}
	price=price*(width*length*height)*(x*x*x);
	}
	return price;
}
