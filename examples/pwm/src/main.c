#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  // Set fast PWM mode with non-inverted output
  TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
  // Set prescaler to 64
  TCCR0B = (1 << CS01) | (1 << CS00);
  // Set pin 6 of PORTD as output
  DDRD |= (1 << DDD6);

  uint8_t brightness = 0;
  int8_t delta = 1;

  while (1)
  {
    // Set compare value for PWM
    OCR0A = brightness;
    brightness += delta;

    if (brightness == 0 || brightness == 255)
    {
      delta = -delta;
    }

    _delay_ms(10);
  }
}
