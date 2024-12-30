#include "lcd.h"

void delay_us(unsigned int us) {
    unsigned int i;
    for (i = 0; i < us; i++);
}


void lcd_cmd(unsigned char cmd) {
    RS = 0;         
    RW = 0;         
    LCD_DATA = cmd; 
    EN = 1;         
    delay_us(10);   
    EN = 0;         
    delay_us(2000); 
}


void lcd_data(unsigned char dat) {
    RS = 1;         
    RW = 0;         
    LCD_DATA = dat; 
    EN = 1;         
    delay_us(10);   
    EN = 0;        
    delay_us(200);  
}

void lcd_init(void) {
    lcd_cmd(0x38); 
    lcd_cmd(0x0C); 
    lcd_cmd(0x06); 
    lcd_cmd(0x01); 
    delay_us(2000); 
}


void lcd_clear(void) {
    lcd_cmd(0x01);  
    delay_us(2000); 
}


void lcd_puts(char *str) {
    while (*str) {
        lcd_data(*str); 
        str++;
    }
}

void lcd_gotoxy(unsigned char x, unsigned char y) {
    unsigned char addr;
    if (y == 0)
        addr = 0x80 + x; // Dòng 1
    else
        addr = 0xC0 + x; // Dòng 2
    lcd_cmd(addr);
}
