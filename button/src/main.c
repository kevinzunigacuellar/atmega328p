#include <avr/io.h>

int main(void) {
  // set pin 5 of PORTB for output (built-in LED)
  DDRB |= (1 << DDB5);

  // set pin 2 of PORTD for input
  DDRD &= ~(1 << DDD2);

  // enable pull-up resistor for pin 2 of PORTD
  PORTD |= (1 << PORTD2);

  while (1) {
    if (PIND & (1 << PIND2)) {
      /* set pin 5 high to turn led on */
      PORTB |= (1 << PORTB5);
    } else {
      /* set pin 5 low to turn led off */
      PORTB &= ~(1 << PORTB5);
    }
  }
}
