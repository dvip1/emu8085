#include "../include/memory.h"
#include <string.h>
#include <stdio.h>

uint8_t memory[MEM_SIZE];

void mem_init()
{
    memset(memory, 0, MEM_SIZE);
}

uint8_t mem_read(uint16_t address)
{
    return memory[address];
}

void mem_write(uint16_t address, uint8_t data)
{
    memory[address] = data;
}

bool load_rom(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        printf("Error: could not open %s\n", filename);
        return false;
    }
    size_t bytes_read = fread(memory, 1, MEM_SIZE, file); // size: 1, going to read byte by byte
    printf("Sucessfully loaded %zu bytes from %s\n", bytes_read, filename);
    fclose(file);
    return true;
}