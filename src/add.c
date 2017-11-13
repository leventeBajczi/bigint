#include "add.h"

extern base keylen, addr, ptr;

extern base addbit(base, base, base);

boolean add()
{
    base carry = 0;
    for(base i = addr + ptr + keylen*2 - 8; i >= addr + ptr; i-=8)
    {
        carry = addbit(carry, i, i+keylen*2);
    }
}