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

//função que será acionada quando o botão for pressionado
int64_t turn_off_callback(alarm_id_t id, void *user_data){
    //condição para acionamento de cada led
    if(led_red_active == false && led_blue_active == false && led_green_active == false){
        gpio_put(led_red, true);
        gpio_put(led_blue, true);
        gpio_put(led_green, true);

        led_red_active = true;
        led_blue_active = true;
        led_green_active = true;
    } else if (led_red_active == true && led_blue_active == true && led_green_active == true){
        gpio_put(led_red, false);
        
        led_red_active = false;
    } else if (led_red_active == false && led_blue_active == true && led_green_active == true){
        gpio_put(led_blue, false);

        led_blue_active = false;
    } else if (led_red_active == false && led_blue_active == false && led_green_active == true){
        gpio_put(led_green, false);

        led_green_active = false
    }
    
    return 0
}




int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
