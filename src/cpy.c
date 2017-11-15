#include "cpy.h"

boolean cpy(base a, base a_len, base b, base *b_len)
{
    if(a_len > *b_len) return false;
    memcpy((base*)b, (base*)a, a_len);
    *b_len = a_len;
    return true;
}