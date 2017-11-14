#include "compl.h"

base compl_op_ptr;
base compl_op_len;

extern base complbit(base, base);

boolean compl()
{
    base carry = 1;
    for(base i = compl_op_len - 8; i >= 0; i-=8)
    {
        carry = complbit(compl_op_ptr + i, carry);
    }
}