#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
  /* set pin 5 of PORTB for output*/
  DDRB = DDRB | (1 << DDB5);

  while (1) {
    /* set pin 5 high to turn led on */
    PORTB = PORTB | (1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);

    /* set pin 5 low to turn led off */
    PORTB = PORTB & ~(1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);
  }
}
