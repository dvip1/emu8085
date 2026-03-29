# C Synatax 


### The Union
```c
union
{
    struct
    {
        uint8_t C, B;
    };
    uint16_t BC;
};
```  
Union means all the members share same memory location.  
So instead of separate storage, everything overlaps.
```ascii
+--------+--------+
|   C    |   B    |
+--------+--------+
   byte0    byte1
```  
You can either access both Individually or together the 16 bits with 'BC'. 
