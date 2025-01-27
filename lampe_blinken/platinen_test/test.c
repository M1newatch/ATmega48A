#include <avr/io.h>
#include <util/delay.h>

#define LED_DELAY 200 // Delay in milliseconds

int main(void) {
    // Configure all LED pins as outputs
    // Assuming LEDs are connected to PORTD and PORTC
    DDRD = 0xFF; // Set all pins on PORTD as output
    DDRC = 0xFF; // Set all pins on PORTC as output

    while (1) {
        // Flash LEDs on PORTD
        for (uint8_t i = 0; i < 8; i++) {
            PORTD = (1 << i); // Turn on one LED at a time
            _delay_ms(LED_DELAY); // Wait
        }

        // Flash LEDs on PORTC
        for (uint8_t i = 0; i < 8; i++) {
            PORTC = (1 << i); // Turn on one LED at a time
            _delay_ms(LED_DELAY); // Wait
        }
    }

    return 0; // Should never reach here
}