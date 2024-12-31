#include <reg51.h>
#include <lcd.h>  

sbit smoke_sensor = P3^0;  // Cam bien khoi chan P3_2
sbit flame_sensor = P3^2;  // Cam bien lua chan P3_0
sbit relay = P1^2;         // Relay chan P1_2

void delay_ms(unsigned int ms);

void main() {
    unsigned char smoke_detected = 0;
    unsigned char flame_detected = 0;

   
    lcd_init();  
    lcd_clear();

   
    relay = 0;  // tat relay 

    while (1) {
        smoke_detected = smoke_sensor;  // Doc trang thai cam bien khoi
        flame_detected = flame_sensor; // Doc trang thai cam bien lua

        lcd_clear();
        if (smoke_detected && flame_detected) {
            lcd_gotoxy(0, 0);
            lcd_puts("SAFE ROOM");
            relay = 0;  
        } else if (smoke_detected) {
            lcd_gotoxy(0, 0);
            lcd_puts("Gas detected");
            relay = 1;
        } else if (flame_detected) {
            lcd_gotoxy(0, 0);
            lcd_puts("Flame detected");
            relay = 1;
        } else {
            lcd_gotoxy(0, 0);
            lcd_puts("GAS & SMOKE");
            relay = 1;
        }
        delay_ms(500); 
    }
}

// Hàm delay
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 127; j++);
}
