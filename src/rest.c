#include "rest.h"

/*
Takes two operands (a and m) and calculate a mod m.
The result replaces op1.
*/

base rest_op1_ptr;
base rest_op1_len;
base rest_op2_ptr;
base rest_op2_len;

boolean rest()
{
    //place rest_op2 into compl_op
    compl(0);
    //place rest_op2 into add_op2
    for(base i = 8; i <= rest_op1_len; i+=8)
    {
        while(compare(rest_op1_ptr, i, rest_op2_ptr, rest_op2_len))
        {
            //place rest_op1 into add_op1
            add(1);
        }
    }

}

//returns true if a is bigger than or equals to b, returns false otherwise

boolean compare(base a_ptr, base a_len, base b_ptr, base b_len)
{
    if(a_len > b_len)
    {
        for(base i = 0; i < a_len - b_len; i+=8)
        {
            if(*(base*)(a_ptr) != 0) return true;
            a_ptr+=8;
        }
    }
    else if(a_len < b_len)
    {
        for(base i = 0; i < a_len - b_len; i+=8)
        {
            if(*(base*)(b_ptr) != 0) return false;
            b_ptr += 8;
        }
    }
    for(base i = 0; i<a_len; i+=8)
    {
        if(*(base*)(a_ptr) > *(base*)(b_ptr)) return true;
        if(*(base*)(a_ptr) < *(base*)(b_ptr)) return false;
    }
    return true;


}