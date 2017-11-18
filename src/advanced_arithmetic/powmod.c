#include "headers/powmod.h"
/*
Takes two operands (a and m) and calculate a mod m.
The result replaces op1.
*/

base powm_op1_ptr;
base powm_op1_len;
base powm_op2_ptr;
base powm_op2_len;
base powm_op3_ptr;
base powm_op3_len;
base powm_res_ptr;
base powm_res_len;

extern base rest_op1_ptr;
extern base rest_op1_len;
extern base rest_op2_ptr;
extern base rest_op2_len;

extern base mul_op1_ptr;
extern base mul_op1_len;
extern base mul_op2_ptr;
extern base mul_op2_len;
extern base mul_res_ptr;
extern base mul_res_len;

extern base add_op1_ptr;
extern base add_op1_len;
extern base add_op2_ptr;
extern base add_op2_len;


extern boolean compare(base, base, base, base);

boolean powmod()
{
    uint8_t zero[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    uint8_t one[8] = {0, 0, 0, 0, 0, 0, 0, 1};
    for(base i = 0; i<powm_op1_len*2; i+=sizeof(base))load(zero, 8, powm_res_ptr, &powm_res_len);
    powm_res_len = powm_op1_len*2;

    cpy(powm_res_ptr, powm_res_len, add_op1_ptr, &add_op1_len);
    cpy((base)one, 8, add_op2_ptr, &add_op2_len);
    add(0);
    cpy(add_op1_ptr, add_op1_len, powm_res_ptr, &powm_res_len);

    cpy(powm_op3_ptr, powm_op3_len, rest_op2_ptr, &rest_op2_len);
    while(compare(powm_op2_ptr, powm_op2_len, (base)zero, 8) != 1)
    {
        if(*(base*)(powm_op2_ptr + powm_op2_len - sizeof(base)) % 2)
        {
            cpy(powm_res_ptr, powm_res_len, mul_op1_ptr, &mul_op1_len);
            cpy(powm_op1_ptr, powm_op1_len, mul_op2_ptr, &mul_op2_len);
            mul();
            mul_res_len = powm_res_len + powm_op1_len;
            cpy(mul_res_ptr, mul_res_len, rest_op1_ptr, &rest_op1_len);
            rest();
            cpy(rest_op1_ptr+rest_op1_len/2, rest_op1_len/2, powm_res_ptr, &powm_res_len);
        }
        shift_right(powm_op2_ptr, powm_op2_len, 0);
        cpy(powm_op1_ptr, powm_op1_len, mul_op1_ptr, &mul_op1_len);
        cpy(powm_op1_ptr, powm_op1_len, mul_op2_ptr, &mul_op2_len);
        mul();
        mul_res_len = 2*powm_op1_len;
        cpy(mul_res_ptr, mul_res_len, rest_op1_ptr, &rest_op1_len);
        rest();
        cpy(rest_op1_ptr+rest_op1_len/2, rest_op1_len/2, powm_op1_ptr, &powm_op1_len);
    }
    return true;
}