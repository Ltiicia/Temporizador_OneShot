#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

#define RED_LED_PIN 13
#define BLUE_LED_PIN 12
#define GREEN_LED_PIN 11
#define BUTTON_PIN 5
#define DEBOUNCE_TIME_MS 50

volatile bool button_pressed = false;
volatile bool sequence_running = false;
volatile uint32_t last_button_press_time = 0;

void set_led_brightness(uint pin, uint16_t brightness)
{
    pwm_set_gpio_level(pin, brightness);
}

void init_pwm(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);
}

bool turn_off_callback(struct repeating_timer *t)
{
    static int state = 1; 

    if (state == 1)
    {
        set_led_brightness(RED_LED_PIN, 0);
    }
    else if (state == 2)
    {
        set_led_brightness(BLUE_LED_PIN, 0);
    }
    else if (state == 3)
    {
        set_led_brightness(GREEN_LED_PIN, 0);
        sequence_running = false;
        state = 0;    
        return false; 
    }

    state++;
    return true; 
}

void button_callback(uint gpio, uint32_t events)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_button_press_time > DEBOUNCE_TIME_MS)
    {
        last_button_press_time = current_time;
        if (!sequence_running)
        {
            button_pressed = true;
        }
    }
}

int main()
{
    stdio_init_all();

    
    init_pwm(RED_LED_PIN);
    init_pwm(BLUE_LED_PIN);
    init_pwm(GREEN_LED_PIN);

  
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    struct repeating_timer timer;

    while (true)
    {
        if (button_pressed && !sequence_running)
        {
            button_pressed = false;
            sequence_running = true;

          
            set_led_brightness(RED_LED_PIN, 255);
            set_led_brightness(BLUE_LED_PIN, 255);
            set_led_brightness(GREEN_LED_PIN, 255);

           
            add_repeating_timer_ms(3000, turn_off_callback, NULL, &timer);
        }
    }
}