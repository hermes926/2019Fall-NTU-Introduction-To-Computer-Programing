#include <stdio.h>
#include "book.h"
#include "date.h"
#include <stdbool.h>
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
	int time = 0;unsigned int totalfine = 0;
	bool leap_borrow = false, leap_return = false; 
	if((date_borrowed.year % 4 == 0 && date_borrowed.year % 100 != 0) || (date_borrowed.year % 400) == 0){
			leap_borrow = true;
	}
	if((date_returned.year % 4 == 0 && date_returned.year % 100 != 0) || (date_returned.year % 400) == 0){
			leap_return = true;
	}
	for(int i = date_borrowed.year; i < date_returned.year ; i++){
		if((i % 4 == 0 && i % 100 != 0) || (i % 400) == 0){
			time += 366;
		}
		else
			time += 365;
	}
	for(int i = date_borrowed.month - 1; i >= 1; i--){
		switch(i){
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				time -= 31;break;
			case 4:case 6:case 9:case 11:
				time -= 30;break;
			case 2:
				if(leap_borrow)
					time -= 29;
				else
					time -= 28;
				break;
		}
	}
	time -= date_borrowed.day;
	for(int i = 1; i < date_returned.month; i++){
		switch(i){
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				time += 31;break;
			case 4:case 6:case 9:case 11:
				time += 30;break;
			case 2:
				if(leap_return)
					time += 29;
				else
					time += 28;
				break;
		}
	}
	time += date_returned.day;
	int dailyfine = 0;int t1 = -1, t2 = -1, count = 0;
	while(book.importance != 0){
		if(book.importance % 2 == 1){
			if(t1 == t2)
				t1 = count;
			else
				t2 = count;
		}
		book.importance = (book.importance >> 1);
		count ++;
	}
	dailyfine = t2 - t1 - 1;
	printf("%d\n", time);
	switch(book.type){
		case NOVEL:
			if(time > 90)
				totalfine += (time - 90) * dailyfine;
			break;
		case COMICS:
			if(time > 10)
				totalfine += (time - 10) * dailyfine;
			break;
		
		case MANUAL:
			if(time > 100)
				totalfine += (time - 100) * dailyfine;
			break;
		case TEXTBOOK:
			if(time > 5)
				totalfine += (time - 5) * dailyfine;
			break;
	}
	return totalfine;
}
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        TEXTBOOK,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        1025
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2003;
    date_borrowed.month = 2;
    date_borrowed.day   = 21;
    date_returned.year  = 2004;
    date_returned.month = 3;
    date_returned.day   = 1;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}
