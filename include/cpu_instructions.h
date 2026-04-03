#ifndef CPU_INSTRUCTIONS_H
#define CPU_INSTRUCTIONS_H

#include "cpu8085.h"
#include <stdbool.h>

/**
 * Execute a single CPU instruction
 * Reads the opcode at CPU.PC and executes it, updating CPU state accordingly
 *
 * @param cpu Pointer to the CPU8085 structure
 * @return true if execution should continue, false if HLT was encountered
 */
bool execute_instruction(CPU8085 *cpu);

#endif // CPU_INSTRUCTIONS_H
