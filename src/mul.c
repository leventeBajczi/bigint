#include "mul.h"

extern base keylen, addr, ptr;

extern base mulbit(base, base, base, base);

boolean mul()
{
    base z = 0;
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
        base check = *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset);
        *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset) += carry;
        z = 0;
        while(check > *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset - z)){
            z++;
            check = *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset - z);
            *(base*)((base)addr+(base)ptr+3*keylen - 8 + offset - z) += carry;
        }
        offset += 8;
    }
    carry = 0;
}