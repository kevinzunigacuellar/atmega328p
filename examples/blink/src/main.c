#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void) {
  /* set pin 5 of PORTB for output */
  DDRB |= (1 << DDB5);

  while (1) {
    /* toggle pin 5 to turn LED on/off */
    PORTB ^= (1 << PORTB5);
    _delay_ms(BLINK_DELAY_MS);
  }
}
