=== Projeto EmbarcaTech ===
ATIIVDADE 2: Temporizador one shot

Com o emprego da função add_alarm_in_ms(), presente na
ferramenta Pico SDK, foi projetado um sistema de temporização 
para o acionamento de LEDs, que atua a partir do clique em um
botão.

O projeto pôde ser simulado com ajuda da plataforma wokwi, utilizando

1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (azul, vermelho e verde).
3) 03 Resistores de 330 Ω.
4) Botão (Pushbutton)

Ao apertar o botão 3 LEDs são acionados e a cada 3 segundos um deles se apaga,
finalizando um ciclo. O botão só pode ser apertado de novo quando todos os LEDs 
estiverem apagados.
