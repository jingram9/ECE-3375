#include "lcd_driver.h"
#include "lcd_graphic.h"
#include "lcd_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Days of the Week
void Display_DoW(int y, int m, int d){
	
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}; 
	y -= m < 3;
	int DoW = ( (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7 ) + 1;
				
	char text_Su_lcd[17] = "Sunday\0"; // 17 char - 6 char = 11 char --> 11 char / 2 = 5.5char
	char text_M_lcd[17] = "Monday\0";
	char text_Tu_lcd[17] = "Tuesday\0";
	char text_W_lcd[17] = "Wednesday\0";
	char text_Th_lcd[17] = "Thursday\0";
	char text_F_lcd[17] = "Friday\0";
	char text_Sa_lcd[17] = "Saturday\0";
	
	switch (DoW){
			
		case 1: LCD_text(text_Su_lcd, 0);	break;
		
		case 2: LCD_text(text_M_lcd, 0);	break;
			
		case 3:	LCD_text(text_Tu_lcd, 0);	break;
			
		case 4:	LCD_text(text_W_lcd, 0);	break;
			
		case 5:	LCD_text(text_Th_lcd, 0);	break;
			
		case 6:	LCD_text(text_F_lcd, 0);	break;
		
		case 7: LCD_text(text_Sa_lcd, 0);	break;
		
		default: LCD_text(text_Su_lcd, 0);
		
	}
				
}
	
	
// Month
void Display_Month(int m){
	
	char text_Jan_lcd[17] = "January\0";		char text_Feb_lcd[17] = "February\0";
	char text_Mar_lcd[17] = "March\0";			char text_Apr_lcd[17] = "April\0";
	char text_May_lcd[17] = "May\0";			char text_Jun_lcd[17] = "June\0";
	char text_Jul_lcd[17] = "July\0";			char text_Aug_lcd[17] = "August\0";
	char text_Sept_lcd[17] = "September\0";		char text_Oct_lcd[17] = "October\0";
	char text_Nov_lcd[17] = "November\0";		char text_Dec_lcd[17] = "December\0";
	
	switch (m){
					
		case 1: LCD_text(text_Jan_lcd, 1);	break;
			
		case 2:	LCD_text(text_Feb_lcd, 1);	break;
			
		case 3:	LCD_text(text_Mar_lcd, 1);	break;
			
		case 4:	LCD_text(text_Apr_lcd, 1);	break;
			
		case 5:	LCD_text(text_May_lcd, 1);	break;
				
		case 6: LCD_text(text_Jun_lcd, 1);	break;
			
		case 7: LCD_text(text_Jul_lcd, 1);	break;
			
		case 8: LCD_text(text_Aug_lcd, 1);	break;
			
		case 9: LCD_text(text_Sept_lcd, 1);	break;
			
		case 10: LCD_text(text_Oct_lcd, 1);	break;
			
		case 11: LCD_text(text_Nov_lcd, 1);	break;
		
		case 12: LCD_text(text_Dec_lcd, 1);	break;
		
		default: LCD_text(text_Jan_lcd, 1);
	
	}
	
		
}
	
	
// Day
void Display_Date(int d){
	
	char text_date_lcd[17] = "\0";
	char ones = 0, tens = 0;
	
	// ASCII Table:
	// Char || 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
	// Dec  || 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 |

	if ( (d > 0) && (d < 10) ){
		
		ones = d + 48;
		tens = 32;
	}
	
	else if ( (d > 9) && (d < 20) ){
			
		ones = (d - 10) + 48;
		tens = 49;
	}
		
	else if ( (d > 19) && (d < 30) ){
		
		ones = (d - 20) + 48;
		tens = 50;			
	}
		
	else if ( (d > 29) && (d < 32) ){
		
		ones = (d - 30) + 48;
		tens = 51;			
	}
	else{
		ones = 45;
		tens = 45;
	}
	
	text_date_lcd[0] = tens;
	text_date_lcd[1] = ones;
	
	LCD_text(text_date_lcd, 2);
	
}
	
		
// Year
void Display_Year(int y){
	
	char text_year_lcd[17] = "2018\0";
	char ones = 0, tens = 0;
	
	y = y - 2000;
	
	if ( (y > 9) && (y < 20) ){
		
		ones = (y - 10) + 48;
		tens = 49;			
	}
	
	else if ( (y > 19) && (y < 30) ){
		
		ones = (y - 20) + 48;
		tens = 50;			
	}
	
	else if ( (y > 29) && (y < 40) ){
		
		ones = (y - 30) + 48;
		tens = 51;			
	}
	
	else if (y > 39) {
		text_year_lcd[0] = 'g';
		text_year_lcd[1] = 'e';
		ones = ' ';
		tens = 't';
		text_year_lcd[4] = 'a';
		text_year_lcd[5] = ' ';
		text_year_lcd[6] = 'n';
		text_year_lcd[7] = 'e';
		text_year_lcd[8] = 'w';
		text_year_lcd[9] = ' ';
		text_year_lcd[10] = 'c';
		text_year_lcd[11] = 'l';
		text_year_lcd[12] = 'o';
		text_year_lcd[13] = 'c';
		text_year_lcd[14] = 'k';
		
	}
	
	else{
		//ones = 49;
		//tens = 57;
	}
	
	text_year_lcd[2] = tens;
	text_year_lcd[3] = ones;
	
	LCD_text(text_year_lcd, 3);
}
		
	
//Temperature
void Display_Temp(int t){
	
	//char text_temp_lcd[17] = "Temp:  25 deg C\0";
	char sign = 0, ones = 0, tens = 0;
	
	if ( (t > -60) && (t < -49) ){
		
		sign = 45;
		ones = (-t - 50) + 48;
		tens = 53;			
	}
	
	else if ( (t > -50) && (t < -39) ){
		
		sign = 45;
		ones = (-t - 40) + 48;
		tens = 52;			
	}
	
	else if ( (t > -40) && (t < -29) ){
		
		sign = 45;
		ones = (-t - 30) + 48;
		tens = 51;			
	}
	
	else if ( (t > -30) && (t < -19) ){
		
		sign = 45;
		ones = (-t - 20) + 48;
		tens = 50;			
	}
		
	
	else if ( (t > -20) && (t < -9) ){
		
		sign = 45;
		ones = (-t - 10) + 48;
		tens = 49;			
	}
	
	else if ( (t > -10) && (t < 0) ){
		
		sign = 45;
		ones = -t + 48;		
	}
	
		else if ( (t >= 0) && (t < 10) ){
		
		sign = 32;
		ones = t + 48;
		tens = 32;			
	}
	
	else if ( (t > 9) && (t < 20) ){
		
		sign = 32;
		ones = (t - 10) + 48;
		tens = 49;
	}
		
	else if ( (t > 19) && (t < 30) ){
		
		sign = 32;
		ones = (t - 20) + 48;
		tens = 50;			
	}
		
	else if ( (t > 29) && (t < 40) ){
		
		sign = 32;	
		ones = (t - 30) + 48;
		tens = 51;			
	}
		
	else if ( (t > 39) && (t < 50) ){
		
		sign = 32;	
		ones = (t - 40) + 48;
		tens = 52;			
	}
		
	else if ( (t > 49) && (t < 60) ){
		
		sign = 32;
		ones = (t - 50) + 48;
		tens = 53;			
	}
	else{
		
		sign = 45;
		ones = 45;
		tens = 45;
	}
		
	char text_temp_lcd[17] = "Temp:  25 deg C\0";
	text_temp_lcd[6] = sign;
	text_temp_lcd[7] = tens;
	text_temp_lcd[8] = ones;
	
	LCD_text(text_temp_lcd, 5);
	
}
