#include "headers/cpy.h"

boolean cpy(base a, base a_len, base b, base *b_len)
{

    memcpy((uint8_t*)b, (uint8_t*)a, (sizeof(base) - a_len%(sizeof(base))));
    a+=(sizeof(base) - a_len%(sizeof(base)));
    b+=(sizeof(base) - a_len%(sizeof(base)));
    for(uint8_t i = 0; i<a_len%(sizeof(base)); i++){
        *(uint8_t*)b = 0;
        b++;
    }
    memcpy((base*)b, (base*)a, a_len - (sizeof(base) - a_len%(sizeof(base))));

    *b_len = a_len;
    return true;
}