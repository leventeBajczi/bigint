#include "add.h"

base add_op1_ptr;
base add_op1_len;
base add_op2_ptr;
base add_op2_len;

extern base addbit(base, base, base);

boolean add()
{
    base carry = 0;
    for(base i = add_op1_len - 8; i >= 0; i-=8)
    {
        carry = addbit(carry, add_op1_ptr + i, add_op2_ptr + i);
    }
}