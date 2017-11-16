#include "headers/add.h"

/*
Takes two operands, and puts their sum into the first operand's place.
If the two operands are not of the same size, the second one needs to be the smaller. Then it goes on with the value c (received as parameter) (->signdness)
Can be used to substract two numbers from each other, see compl.c for further details (a - b = a + (-b)).
The value of the second operand will be destroyed.
*/


base add_op1_ptr;
base add_op1_len;
base add_op2_ptr;
base add_op2_len;

extern base addbit(base, base, base);

boolean add(base c)
{
    base c_save = c;
    base carry = 0;
    for(base i = add_op1_len; i >= sizeof(base); i-=sizeof(base))                             //After 0: Overflow, i>=0 will always be true -> -sizeof(base) in the addbit function
    {
        if(add_op1_len - add_op2_len >= i)
        {
            c = c_save; //needs reset
            carry = addbit(carry, (base)&c, add_op1_ptr + i - sizeof(base));
        }
        else carry = addbit(carry, add_op2_ptr + i - sizeof(base) - add_op1_len + add_op2_len, add_op1_ptr + i - sizeof(base));
    }

    return false;
}