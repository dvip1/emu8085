# Architecture
I'd be sharing architecture, I'd learned here to make this project which I didn't knew before  

### Endianess 
In some languages people write from left to right, and others in right to left. Arabic vs English.  
Endianess is the same concept, but for computers.  

#### What is Big-endian?
  
In a big-endian system, the most significant byte (MSB) is stored at the lowest memory address. This means the "big end" (the most significant part of the data) comes first. For instance, a 32-bit integer 0x12345678 would be stored in memory as follows in a big-endian system:  
```txt
Address:   00   01   02   03  
Data:         12   34   56   78
```

Here, 0x12 is the most significant byte, placed at the lowest address (00), followed by 0x34, 0x56, and 0x78 at the highest address (03).
  
#### What is Little-endian?  
A little-endian system stores the least significant byte (LSB) at the lowest memory address. The "little end" (the least significant part of the data) comes first. For the same 32-bit integer 0x12345678, a little-endian system would store it as:  
```txt
Address:   00   01   02   03
Data:        78   56   34   12
```  
Here, 0x78 is the least significant byte, placed at the lowest address (00), followed by 0x56, 0x34, and 0x12 at the highest address (03).


