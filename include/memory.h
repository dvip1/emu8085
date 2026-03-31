// ./include/memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stdbool.h>

#define MEM_SIZE 65536

extern uint8_t memory[MEM_SIZE];

// Initialize memory (usually all zeros or load a ROM file)
void mem_init();

// Read 1 byte from a 16-bit address
uint8_t mem_read(uint16_t address);

// Write 1 byte to a 16-bit address
void mem_write(uint16_t address, uint8_t data);

bool load_rom(const char *filename);

#endif // MEMORY_H