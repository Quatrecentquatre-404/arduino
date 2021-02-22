#include <Arduino.h>

using low_int = unsigned short int;
const low_int leds[] = {2, 4, 6};
const low_int max_leds_range[] = {2, 13};

void shutdown_outputs();
void setup();
void loop();

void shutdown_outputs()
{
    for (low_int index = max_leds_range[0]; index <= max_leds_range[1]; index++)
        digitalWrite(index, LOW);
}

void setup()
{
    for (low_int index = 0; index < sizeof(leds); index++)
        pinMode(leds[index], OUTPUT);

    shutdown_outputs();
}

const low_int deferred(const low_int pad)
{
    if (pad != 0 && pad != 1) return 0;
    for (low_int index = 0; index < sizeof(leds); index++)
    {
        if (index % 2 == pad)
        {
            digitalWrite(leds[index], HIGH);
        }
        else
        {
            digitalWrite(leds[index], LOW);
        }
    }
    return (pad % 2 == 0) ? pad + 1 : pad - 1;
}

void loop()
{
    const low_int pad = deferred(0);
    delay(1000);
    deferred(pad);
    delay(1000);
}
