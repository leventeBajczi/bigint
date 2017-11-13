#include "mul.h"

extern base keylen, addr, ptr;

extern base mulbit(base, base, base, base);

boolean mul()
{
    base carry = 0;
    base offset = 0;

    base nulldata = 0x0;
    for(base i = 0; i < keylen*4; i++)
    {
        *(base*)(addr + ptr + 2*keylen+i) = nulldata;
    }


    for(base i = addr + ptr + keylen - 8; i >= addr + ptr ; i-=8)
    {
        carry = 0;
        for(base j = 0; j <= keylen - 8; j+=8)
        {
            base place = (base)addr + (base)ptr + 4*keylen - 8 - j + offset;
            base second = (base)addr + (base)ptr + 2 * keylen - 8 - j;
            carry = mulbit(carry, i, second,  place);
        }
        *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset) = carry;
        offset += 8;
    }
    carry = 0;
}