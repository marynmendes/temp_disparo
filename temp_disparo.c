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

//função após o fim da rotina dos leds
int64_t turn_off_callback(alarm_id_t id, void *user_data){
        
        led_red_active = false;
        led_blue_active = false;
        led_green_active = false;
    
    return 0;
}

int main()
{
    stdio_init_all();
    //inicialização de cada led e do botão
    gpio_init(led_red);
    gpio_init(led_blue);
    gpio_init(led_green);
    gpio_init(button_a);

    //configuração dos leds como saída
    gpio_set_dir(led_red, true);
    gpio_set_dir(led_blue, true);
    gpio_set_dir(led_green, true);

    //configuração do botão como entrada
    gpio_set_dir(button_a, GPIO_IN);

    //habilita o resistor pull-up interno para o pino do botão.
    gpio_pull_up(button_a);

    while (true) {
         // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(button_a) == 0 && !(led_red_active == false && led_blue_active == false && led_green_active == false)) {
            sleep_ms(50);
            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(button_a) == 0) {
                //condições para acionamento de leds
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

                    led_green_active = false;
                }
                
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
    }

}
