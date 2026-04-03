#include <stdio.h>
#include "cpu_instructions.h"
#include "memory.h"

bool execute_instruction(CPU8085 *cpu)
{
    unsigned char opcode = mem_read(cpu->PC);
    // printf("[%d] 0x%04x ", cpu->PC, opcode);

    switch (opcode)
    {
    case 0x00: // NOP
        printf("NOP\n");
        cpu->PC += 1;
        break;

    case 0x03: // INX B
        printf("INX B\n");
        // Increment the 16-bit BC register pair
        cpu->C++;
        if (cpu->C == 0)
        { // If C overflows from 255 to 0, carry over to B
            cpu->B++;
        }
        cpu->PC += 1;
        break;

    case 0x06: // MVI B, d8
        printf("MVI B, %02XH\n", mem_read(cpu->PC + 1));
        cpu->B = mem_read(cpu->PC + 1);
        cpu->PC += 2;
        break;

    case 0x3E: // MVI A, d8
        printf("MVI A, %02XH\n", mem_read(cpu->PC + 1));
        cpu->A = mem_read(cpu->PC + 1);
        cpu->PC += 2;
        break;

    case 0x47: // MOV B, A
        printf("MOV B, A\n");
        cpu->B = cpu->A;
        cpu->PC += 1;
        break;

    case 0x76: // HLT
        printf("HLT\n");
        cpu->PC += 1;
        return false; // Stop execution
        break;

    case 0x80: // ADD B
        printf("ADD B\n");
        cpu->A += cpu->B;
        // TODO: Eventually need to update the Flag register (Carry, Zero, etc.) here!
        cpu->PC += 1;
        break;

    case 0xC3: // JMP a16
    {
        unsigned short addr = mem_read(cpu->PC + 1) |
                              (mem_read(cpu->PC + 2) << 8);
        printf("JMP %04XH\n", addr);
        cpu->PC = addr;
        break;
    }

    default:
    {
        printf("Unknown OP Code %02X at PC: %04X\n", opcode, cpu->PC);
        return false; // Stop execution on unknown opcode
        break;
    }
    }

    return true; // Continue execution
}
