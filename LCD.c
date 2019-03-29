#include "lcd_driver.h"
#include "lcd_graphic.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	
    volatile int delay_count; // volatile so C compiler doesn't remove the loop

    /* create a message to be displayed on the VGA display */
    
	// Days of the Week
	void Display_DoW(int y, int m, int d){
		
		static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}; 
		y -= m < 3;
		int DOW = ( (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7 ) + 1;

				
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
	
	
	// Date
	void Display_Date(int d){
		
		char text_date_lcd[2];
		char ones = 0, tens = 0;
				
		//itoa(d, text_date_lcd, 10); // idk if this works but google says to use // 10 means decimal
		
		// ASCII Table:
		// Char || 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
		// Dec  || 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 |
		
		if (d < 10){
			
			ones = d + 48;			
		}
		
		else if (d > 9 && d < 20){
			
			ones = d - 10;
			tens = 1;
		}
		
		else if (d > 19 && d < 30){
			
			ones = d - 20;
			tens = 2;			
		}
		
		else if (d > 29 && d < 32){
			
			ones = d - 30;
			tens = 3;			
		}
		
		text_date_lcd[0] = tens;
		text_date_lcd[1] = ones;
		LCD_text(text_date_lcd, 2);
			
	}
	
	

    char text_temp_lcd[17]    = "Temp: 5 deg C\0";

    init_spim0();
    init_lcd();

    clear_screen();

    // output the text message on the LCD display
    LCD_text(text_year_lcd, 3);
    LCD_text(text_temp_lcd, 5);


    refresh_buffer();

    while (1) {

        for (delay_count = 100000; delay_count != 0; --delay_count)
            ; // delay loop
    } 
}