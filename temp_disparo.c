#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" 
#include "hardware/gpio.h"
#include "hardware/timer.h" //bibliotecas para gerenciar temprizador e alarme

#define led_red 13 //luz vermelha
#define led_blue 12 //led azul 
#define led_green 11 // luz verde
#define button_a 5 // botão A

//funções após o fim da rotina dos leds
int64_t turn_off_callback_green(alarm_id_t id, void *user_data){
    gpio_put(led_green, false);
    
    return 0;
}

int64_t turn_off_callback_blue(alarm_id_t id, void *user_data){
    gpio_put(led_blue, false);
    add_alarm_in_ms(3000, turn_off_callback_green, NULL, false);
    return 0;
}

int64_t turn_off_callback_red(alarm_id_t id, void *user_data){
    gpio_put(led_red, false);
    add_alarm_in_ms(3000, turn_off_callback_blue, NULL, false);
    return 0;
}

//função que ligará os leds pelo tempo determinado
void acionar(uint gpio, uint32_t eventos){
    if (gpio_get(led_red) != 0 || gpio_get(led_blue) != 0 || gpio_get(led_green) != 0){
        return;
    } else { 
    gpio_put(led_red, true);
    gpio_put(led_blue, true);
    gpio_put(led_green, true);

    add_alarm_in_ms(3000, turn_off_callback_red, NULL, false);
    }
    
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

    //leds desligados
    gpio_put(led_red, false);
    gpio_put(led_blue, false);
    gpio_put(led_green, false);

    //configuração do botão como entrada
    gpio_set_dir(button_a, false);

    //habilita o resistor pull-up interno para o pino do botão.
    gpio_pull_up(button_a);

    //chama função de interrupção
    gpio_set_irq_enabled_with_callback(button_a, GPIO_IRQ_EDGE_FALL, true, acionar);

    while (true) {
        
    }

}
