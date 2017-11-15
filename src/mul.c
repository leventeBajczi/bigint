#include "mul.h"

/*
Takes two operands and calculates their product. 
The two operands MUST be the same length (patch is under consideration)
The product must be 2*(operand size) to function normally, otherwise throws a SIGSEGV
*/

base mul_op1_ptr;
base mul_op1_len;
base mul_op2_ptr;
base mul_op2_len;
base mul_res_ptr;
base mul_res_len;

extern base mulbit(base, base, base, base);

boolean mul()
{
    base z = 0;
    base carry = 0;
    base offset = 0;

    base nulldata = 0x0;
    for(base i = 0; i < mul_res_len; i+=8)
    {
        *(base*)(mul_res_ptr + i) = nulldata;
    }

    for(base i = mul_op1_len; i >= 8 ; i-=8)
    {
        carry = 0;
        for(base j = 0; j <= mul_op2_len - 8; j+=8)
        {
            base place = mul_res_ptr + mul_res_len/2 - j + offset;
            base second = mul_op2_ptr + mul_op2_len - 8 - j;
            carry = mulbit(carry, mul_op1_ptr + i - 8, second,  place);
        } 
        base check = *(base*)( mul_res_ptr + offset);
        *(base*)( mul_res_ptr + offset) += carry;
        z = 0;
        while(check > *(base*)( mul_res_ptr +  offset - z)){
            z+=8;
            check = *(base*)( mul_res_ptr + offset - z);
            *(base*)( mul_res_ptr + offset - z) += 1;
        }
        offset += 8;
    }
    carry = 0;
}