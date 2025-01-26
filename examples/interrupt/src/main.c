#include <avr/interrupt.h>
#include <avr/io.h>

ISR(INT0_vect) {
  // Toggle LED on interrupt
  PORTB ^= (1 << PORTB5);
}

int main(void) {
  // set LED as output
  DDRB |= (1 << DDB5);

  // Set pin 2 of PORTD for input with pull-up
  DDRD &= ~(1 << DDD2);
  PORTD |= (1 << PORTD2);

  // Configure INT0 to trigger on falling edge
  EICRA |= (1 << ISC01);
  EIMSK |= (1 << INT0);
  sei();

  while (1) {
    /* do nothing */
  }
}
