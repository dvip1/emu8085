#include "../include/memory.h"
#include <strings.h>

uint8_t memory[MEM_SIZE];

void mem_init()
{
    memset(memory, 0, MEM_SIZE);
}

uint8_t memory_read(uint16_t address)
{
    return memory[address];
}

void mem_write(uint16_t address, uint8_t data)
{
    memory[address] = data;
}