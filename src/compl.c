#include "compl.h"

extern base keylen, addr, ptr;

extern base complbit(base, base);

boolean compl()
{
    base carry = 1;
    for(base i = addr + ptr + keylen*2 - 8; i >= addr + ptr; i-=8)
    {
        carry = complbit(i, carry);
    }
}