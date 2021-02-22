#include <Arduino.h>

using low_int = unsigned short int;
const low_int leds[] = {2, 4, 6};
const low_int max_leds_range[] = {2, 13};
low_int led_being_handled = 0;

void shutdown_outputs();
void setup();
void loop();

void shutdown_outputs()
{
    for (low_int index = max_leds_range[0]; index <= max_leds_range[1]; index++)
    {
        digitalWrite(index, LOW);
    }
}

void setup()
{
    for (low_int index = 0; index < sizeof(leds); index++)
    {
        pinMode(leds[index], OUTPUT);
    }
}

void loop()
{
    shutdown_outputs();
    if (led_being_handled == sizeof(leds) - 2) led_being_handled = 0;
    for (low_int index = 0; index < sizeof(leds); index++)
    {
        if (index != led_being_handled)
        {
            digitalWrite(leds[index], HIGH);
        }
    }
    led_being_handled += 1;
    delay(1000);
}
