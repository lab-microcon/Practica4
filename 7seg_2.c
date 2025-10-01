#include <Arduino.h> 
#include <avr/io.h>
#include <util/delay.h>
// Pines conectados al display de 7 segmentos (ánodo común)
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8

// Función para mostrar un número en el display
void display_number(int number) {
    // Apagar todos los segmentos
    PORTD &= ~((1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F) | (1 << SEG_G));

    switch (number) {
        case 0:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F);
            break;
        case 1:
            PORTD |= (1 << SEG_B) | (1 << SEG_C);
            break;
        case 2:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_G);
            break;
        case 3:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_G);
            break;
        case 4:
            PORTD |= (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_F) | (1 << SEG_G);
            break;
        case 5:
            PORTD |= (1 << SEG_A) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_F) | (1 << SEG_G);
            break;
        case 6:
            PORTD |= (1 << SEG_A) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F) | (1 << SEG_G);
            break;
        case 7:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C);
            break;
        case 8:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F) | (1 << SEG_G);
            break;
        case 9:
            PORTD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_F) | (1 << SEG_G);
            break;
    }
}

void setup() {
    // Configurar pines del display como salidas
    DDRD |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F) | (1 << SEG_G);
}

void loop() {
    for (int i = 0; i <= 9; i++) {
        display_number(i);
        _delay_ms(1000);
    }
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
    return 0;
}
