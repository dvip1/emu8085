# 8085 Emulator - Implementation Learning Path

## Your Current State ✓

- **Memory system** - Read/write capability
- **ROM loading** - Can load .bin files
- **CPU structure** - Register definitions started
- **Understanding** - Endianness concepts documented

## Where to Go Next (Suggested Learning Order)

### 1. **Instruction Decoding** (Next immediate step)

Learn to:
- Parse the bytecode from memory into individual instructions
- Understand the 8085 instruction format (opcode + operands)
- Map opcodes to instruction mnemonics (MOV, ADD, JMP, etc.)
- Create a lookup structure or switch statement for instruction handling

**Prerequisite knowledge:** Understand binary/hex, instruction sets basics

### 2. **CPU Execution Cycle**

Learn the Fetch-Decode-Execute loop:
- **Fetch:** Read instruction from PC (program counter)
- **Decode:** Figure out what the instruction does
- **Execute:** Modify registers/memory/flags accordingly
- **Update PC:** Move to next instruction

### 3. **Implement Instructions Progressively**

Start in order of complexity:

1. **Data Transfer (MOV, MVI)** - Simplest, register-to-register copies
2. **Arithmetic (ADD, SUB, INR, DCR)** - Operate on registers, update flags
3. **Logical (AND, OR, XOR)** - Similar pattern to arithmetic
4. **Jump Instructions (JMP, JZ, JNZ)** - Control flow
5. **Stack Operations (PUSH, POP, CALL, RET)** - More complex, needs SP management

### 4. **Flag Register Management** (Parallelize with instructions)

Learn when each flag updates:
- **Zero (Z):** After any ALU operation that results in 0
- **Sign (S):** Bit 7 of result
- **Carry (CY):** Overflow from MSB
- **Parity (P):** Even number of 1-bits
- **Aux Carry (AC):** Carry from bit 3 to bit 4

### 5. **Testing & Debugging**

Learn to:
- Create simple test .bin files with known instructions
- Print CPU state (registers, flags, PC) after each instruction
- Verify outputs match expected behavior
- Use stepping through execution to debug

## Key Learning Resources for 8085

**Study these topics:**
1. Intel 8085 Instruction Set Reference (lookup table of all instructions, their opcodes, timing)
2. BCD (Binary-Coded Decimal) - Used for AC flag calculations
3. Memory addressing modes (direct, indirect, register indirect)
4. I/O operations (if you want to expand later with IN/OUT instructions)

## Project Architecture to Consider

```
cpu_init()              → Initialize registers, PC=0, SP, flags
fetch_decode_execute()  → Main loop - the core of your emulator
execute_instruction()   → Dispatch to specific handlers (MOV, ADD, etc.)
update_flags()          → Common function used by many instructions
print_cpu_state()       → Debugging tool
```

## Recommended Starting Point: MOV Instruction

**Why start with MOV?**
- Simplest instruction (copies data)
- No flag updates
- Only 2 operands
- Used very frequently in real programs
- Once MOV works, you have pattern for ~70% of other instructions

After MOV works successfully, expand to arithmetic operations.

## Implementation Checklist

- [ ] Create instruction fetch function
- [ ] Create instruction decoder (parse opcode)
- [ ] Implement MOV instruction (register-to-register)
- [ ] Add instruction execution loop in main
- [ ] Print CPU state after each instruction
- [ ] Test with simple_mov.bin
- [ ] Implement MVI (immediate load)
- [ ] Implement ADD instruction
- [ ] Implement SUB instruction
- [ ] Implement flag update logic
- [ ] Add more instructions incrementally
- [ ] Implement jump instructions (JMP, JZ, JNZ, etc.)
- [ ] Implement stack operations (PUSH, POP)
- [ ] Implement CALL and RET

## Tips

1. **Start small** - Each instruction completed is progress
2. **Test frequently** - Create test cases for each instruction
3. **Reference the datasheet** - Keep the 8085 instruction set handy
4. **Document as you go** - Future you will thank you
5. **Modularize** - Keep instruction handlers cleanly separated
