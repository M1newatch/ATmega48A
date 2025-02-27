#include <avr/io.h>

int main(void) {
    // Configure anodes as outputs
    DDRC = 0x3F; // PC0-PC5 as output (0b00111111)
    DDRD = 0xF1; // PD0 and PD4-PD7 as output (0b11110001)

    // Configure cathodes as outputs
    DDRB = (1 << PB1) | (1 << PB2); // PB1 and PB2 as output

    // Turn on all LEDs
    PORTC = 0x00; // Set PC0-PC5 high
    PORTD = 0xF1; // Set PD0 and PD4-PD7 high
    PORTB &= ~((1 << PB1) | (1 << PB2)); // Set PB1 and PB2 low

    // Infinite loop
    while (1) {
        // Nothing to do here; LEDs remain ON
    }

    return 0; // Should never reach here
}
