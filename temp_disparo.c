#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" //biblioteca para gerenciar temprizador e alarme

#define led_red 13 //luz vermelha
#define led_blue 12 //led azul 
#define led_green 11 // luz verde
#define button_a 5 // botão A

//variáveis para representar situação dos leds
bool led_red_active = false;
bool led_blue_active = false;
bool led_green_active = false;




int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
