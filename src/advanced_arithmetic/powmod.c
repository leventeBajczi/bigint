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

extern base res_op1_ptr;
extern base res_op1_len;
extern base res_op2_ptr;
extern base res_op2_len;


boolean powmod()
{
    base i = 0;
    cpy(rest_op2_ptr, rest_op2_len, mul_res_ptr, &mul_res_len); //merely saving it for further calculations
    while(((uint8_t*)rest_op2_ptr)[7] == 0 && compare(rest_op1_ptr, rest_op1_len, rest_op2_ptr, rest_op2_len))
    {
        shift_left(rest_op2_ptr, rest_op2_len, 0);
    }
    cpy(rest_op1_ptr, rest_op1_len, add_op1_ptr, &add_op1_len);

    while(compare(rest_op2_ptr, rest_op2_len, mul_res_ptr, mul_res_len))
    {
        while(compare(add_op1_ptr, add_op1_len, rest_op2_ptr, rest_op2_len))
        {
            cpy(rest_op2_ptr, rest_op2_len, compl_op_ptr, &compl_op_len);
            compl();
            cpy(compl_op_ptr, compl_op_len, add_op2_ptr, &add_op2_len);
            add(0);
        }
        shift_right(rest_op2_ptr, rest_op2_len, 0);
    }
    
    cpy(add_op1_ptr, add_op1_len, rest_op1_ptr, &rest_op1_len);
    

    return true;

}

//returns true if a is bigger than or equals to b, returns false otherwise

boolean compare(base a_ptr, base a_len, base b_ptr, base b_len)
{
    if(a_len > b_len)
    {
        for(base i = 0; i < a_len - b_len; i+=sizeof(base))
        {
            if(*(base*)(a_ptr) != 0) return true;
            a_ptr+=sizeof(base);
        }
    }
    else if(a_len < b_len)
    {
        for(base i = 0; i < a_len - b_len; i+=sizeof(base))
        {
            if(*(base*)(b_ptr) != 0) return false;
            b_ptr += sizeof(base);
        }
    }
    for(base i = 0; i<a_len; i+=sizeof(base))
    {
        if(*(base*)(a_ptr+i) > *(base*)(b_ptr+i)) return true;
        if(*(base*)(a_ptr+i) < *(base*)(b_ptr+i)) return false;
    }
    return true;


}