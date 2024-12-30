#ifndef _LCD_H_
#define _LCD_H_

#include <reg51.h>

// Ð?nh nghia các chân di?u khi?n LCD
sbit RS = P2^6;   // Chân RS k?t n?i P2.0
sbit RW = P2^5;   // Chân RW k?t n?i P2.1
sbit EN = P2^7;   // Chân EN k?t n?i P2.2
#define LCD_DATA P0  // D? li?u k?t n?i v?i toàn b? port P0

// Khai báo các hàm di?u khi?n LCD
void lcd_init(void);            // Kh?i t?o LCD
void lcd_cmd(unsigned char cmd); // G?i l?nh d?n LCD
void lcd_data(unsigned char dat); // G?i d? li?u d?n LCD
void lcd_puts(char *str);        // Hi?n th? chu?i ký t?
void lcd_clear(void);            // Xóa màn hình LCD
void lcd_gotoxy(unsigned char x, unsigned char y); // Di chuy?n con tr?

#endif
