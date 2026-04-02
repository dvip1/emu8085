/*
  o__ __o                     o                 o/            
 <|     v\                  _<|>_              /v             
 / \     <\                                   />              
 \o/       \o    o      o     o    \o_ __o              __o__ 
  |         |>  <|>    <|>   <|>    |    v\            />  \  
 / \       //   < >    < >   / \   / \    <\           \o     
 \o/      /      \o    o/    \o/   \o/     /            v\    
  |      o        v\  /v      |     |     o              <\   
 / \  __/>         <\/>      / \   / \ __/>         _\o__</   
                                   \o/                        
                                    |                         
                                   / \                        
    o__ __o         o__ __o         o__ __o      o__ __o__/_  
   /v     v\       /v     v\       /v     v\    <|    v       
  />       <\     />       <\     />       <\   < >           
  \o       o/   o/           \o   \o       o/   _\o____       
   |>_   _<|   <|             |>   |>_   _<|         \_\__o__ 
  /         \   \\           //   /         \              \  
  \         /     \         /     \         /    \         /  
   o       o       o       o       o       o      o       o   
   <\__ __/>       <\__ __/>       <\__ __/>      <\__ __/>   
*/

#include <stdio.h>
#include "memory.h"
#include "cpu8085.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <program.bin>\n", argv[0]);
    }

    CPU8085 cpu = {0};
    mem_init();

    if (!load_rom(argv[1]))
        return 1;

    cpu.PC = 0;
    while (cpu.PC < 100)
    {
        unsigned char opcode = mem_read(cpu.PC);
        // printf("[%d] 0x%04x ", cpu.PC, opcode);
        switch (opcode)
        {
        case 0x00:
            printf("NOP\n");
            cpu.PC += 1;
            break;
        case 0x3E:
            printf("MVI A, %02XH\n", mem_read(cpu.PC + 1));
            cpu.PC += 2;
            break;
        case 0x47:
            printf("MOV B, A\n");
            cpu.PC += 1;
            break;
        case 0x76:
            printf("HLT\n");
            cpu.PC += 1;
            break;
        case 0xC3:
        {
            unsigned short addr = mem_read(cpu.PC + 1) | mem_read(cpu.PC + 2);
            printf("JMP %04XH\n", addr);
            cpu.PC += 3;
            break;
        }
        default:
        {
            printf("Unknown OP Code %02X\n", mem_read(cpu.PC));
            cpu.PC += 1;
            break;
        }
        }
    }
    // printf("First instruction byte in memory: 0x%02X\n", mem_read(0x0000));
    return 0;
}
