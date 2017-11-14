#include "compl.h"

/*
Takes an operand and negates it (creates it's two's complement).
The result will replace the operand.
Use this to substract two numbers.
*/

base compl_op_ptr;
base compl_op_len;

extern base complbit(base, base);

boolean compl()
{
    base carry = 1;
    for(base i = compl_op_len; i >= 8; i-=8)            //After 0: Overflow, i>=0 will always be true -> -8 in the addbit function
    {
        carry = complbit(compl_op_ptr + i - 8, carry);
    }
}