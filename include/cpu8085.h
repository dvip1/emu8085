// ./include/cpu8085.h
#ifndef CPU8085_H
#define CPU8085_H

#include <stdint.h>
/*
    1. B, C, D, E, H, and L: These are used to store temporary data during execution.
    2. Register Pairs: When used for 16-bit operations, they form the pairs BC, DE, and HL.
    3. The HL Pair: This is the most important pair as it often acts as a Memory Pointer (M), pointing to a specific location in the RAM.
    4. Accumulator (A): This is the primary register used for arithmetic and logical operations. It holds the result of these operations.
    5. Flag Register (F): This register contains the status flags that indicate the outcome
         of operations. The flags include:
         - Carry Flag (CY): Indicates if there was a carry out of the most significant bit during an addition or a borrow during a subtraction.
         - Parity Flag (P): Indicates if the number of set bits in the result is even or odd.
         - Auxiliary Carry Flag (AC): Used in BCD (Binary-Coded Decimal) operations to indicate a carry from the lower nibble to the upper nibble.
         - Zero Flag (Z): Indicates if the result of an operation is zero.
         - Sign Flag (S): Indicates if the result of an operation is negative (most significant bit is set).

    6. Program Counter (PC): This register holds the address of the next instruction to be executed.
    7. Stack Pointer (SP): This register points to the top of the stack in
            memory, which is used for storing return addresses, local variables, and for passing parameters during subroutine calls.
*/

#define FLAG_CY 0x01
#define FLAG_P 0x04
#define FLAG_AC 0x10
#define FLAG_Z 0x40
#define FLAG_S 0x80

typedef struct
{
    union
    {
        struct
        {
            uint8_t C, B;
        };
        uint16_t BC;
    };
    union
    {
        struct
        {
            uint8_t E, D;
        };
        uint16_t DE;
    };
    union
    {
        struct
        {
            uint8_t L, H;
        };
        uint16_t HL;
    };

    uint8_t A;

    uint8_t W, Z;

    uint16_t PC;
    uint16_t SP;

    uint8_t F; // flags register

} CPU8085;

#endif // CPU8085_H