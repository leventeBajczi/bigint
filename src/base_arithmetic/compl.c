#include "headers/compl.h"

/*
 * Takes an operand and negates it (creates it's two's complement).
 * The result will replace the operand.
 * Use this to substract two numbers.
 */

base compl_op_ptr;
base compl_op_len;

extern base complbit(base, base);

boolean compl()
{
   base carry = 1;

   for (base i = compl_op_len; i >= sizeof(base); i -= sizeof(base))          //After 0: Overflow, i>=0 will always be true -> -sizeof(base) in the addbit function
   {
      carry = complbit(compl_op_ptr + i - sizeof(base), carry);
   }

   return(true);
}
