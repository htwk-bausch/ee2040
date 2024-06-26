// ---------------------------------------------------------------------
// name: UART_4
// date: 2019-01-01          
// Entwickler: Gerold Bausch
//
// Das Programm konfiguriert die UART mit 9600 Baud (8N1) und aktiviert
// den Empfang von Zeichen mittels Interrupt.
// Wird ein Zeichen empfangen, sendet der Controller das Zeichen
// wieder zurück an den Sender.
//----------------------------------------------------------------------

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

// Baud rate settings 
// see Data sheet page 164 (settings for F_OSC = 16000000UL)
#define BAUD_RATE_9600_BPS    103

int main (void) {
  
  // set baud rate
  UBRR0H = (uint8_t)(BAUD_RATE_9600_BPS>>8);              // Upper 8 bits of the baud rate value
  UBRR0L = (uint8_t)(BAUD_RATE_9600_BPS);                 // Lower 8 bits of the baud rate value
  
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);  // enable receiver, transmitter and RX ISR
  UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);                // Use 8-bit character sizes 
  
  sei();                                                  // enable global interrupts
  
  while(1) {}                                             // Super loop
  
  return 0;
}

ISR(USART_RX_vect) {
  
  uint8_t buffer;
  
  buffer = UDR0;                                  // fetch the received byte
  
  while ((UCSR0A & (1 << UDRE0)) == 0) {};        // wait for empty buffer
  UDR0 = buffer;                                  // echo buffer back
  
}
