; Define Constants
.equ DDRC, 0x07        ; Data Direction Register for Port C
.equ PORTC, 0x08       ; Output Register for Port C

.equ LED_PIN, 5        ; Pin 5 of PORTC

.org 0x00              ; Start address of the program

; Reset Vector
rjmp main              ; Jump to main program
main:
    ; Set PORTC Pin 5 as output
    ldi r16, (1 << LED_PIN)  ; Load 1 shifted by LED_PIN (0b00100000)
    out DDRC, r16            ; Set DDRC to configure Pin 5 as output

loop:
    ; Turn on LED
    ldi r16, (1 << LED_PIN)  ; Load 1 shifted by LED_PIN
    out PORTC, r16           ; Write to PORTC to set Pin 5 high

    rcall delay              ; Call delay subroutine

    ; Turn off LED
    ldi r16, 0               ; Load 0
    out PORTC, r16           ; Write to PORTC to set Pin 5 low

    rcall delay              ; Call delay subroutine

    rjmp loop                ; Repeat loop

delay:
    ; Simple delay loop
    ldi r18, 100             ; Outer loop count (arbitrary value for ~200 ms)
outer_loop:
    ldi r19, 255             ; Inner loop count
inner_loop:
    dec r19                  ; Decrement inner loop counter
    brne inner_loop          ; If not zero, continue inner loop
    dec r18                  ; Decrement outer loop counter
    brne outer_loop          ; If not zero, continue outer loop
    ret                      ; Return from subroutine
