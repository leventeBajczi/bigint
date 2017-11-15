#include "rest.h"

/*
Takes two operands (a and m) and calculate a mod m.
The result replaces op1.
*/

base rest_op1_ptr;
base rest_op1_len;
base rest_op2_ptr;
base rest_op2_len;

extern base compl_op_ptr;
extern base compl_op_len;

extern base add_op1_ptr;
extern base add_op1_len;
extern base add_op2_ptr;
extern base add_op2_len;

boolean rest()
{
    base test = 0x03;
    cpy(rest_op1_ptr, rest_op1_len, add_op1_ptr, &add_op1_len);
    cpy((base)&test, sizeof(test), add_op2_ptr, &add_op2_len);
    add(0);
    cpy(add_op1_ptr, add_op1_len, rest_op1_ptr, &rest_op1_len);


    cpy(rest_op2_ptr, rest_op2_len, compl_op_ptr, &compl_op_len);
    compl();
    cpy(compl_op_ptr, compl_op_len, add_op2_ptr, &add_op2_len);
    for(base i = sizeof(base); i <= rest_op1_len; i+=sizeof(base))
    {
        while(compare(rest_op1_ptr, i, rest_op2_ptr, rest_op2_len))
        {
            cpy(rest_op1_ptr, rest_op1_len, add_op1_ptr, &add_op1_len);
            add(1);
            cpy(add_op1_ptr, add_op1_len, rest_op1_ptr, &rest_op1_len);
        }
    }

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
        if(*(base*)(a_ptr) > *(base*)(b_ptr)) return true;
        if(*(base*)(a_ptr) < *(base*)(b_ptr)) return false;
    }
    return true;


}