#include "headers/load.h"

/*
 * Takes a byte (uint8_t) array, and "encodes" it into a format that the library can work with.
 * Supply only so big numbers, that len % sizeof(base) = 0.
 */


boolean load(uint8_t *array, base len, base dest, base *destlen)
{
   *destlen = len;
   for (int i = 0; i < len; i++)
   {
        #ifdef DEV
      printf("%02x", array[i]);
        #endif
      *((uint8_t *)(dest + (i + sizeof(base)) / sizeof(base) * sizeof(base) - 1 - i % sizeof(base))) = array[i]; //To compensae for the weird way of writing memory from registers
   }
   return(true);
}

boolean store(uint8_t *array, base *len, base src, base srclen)
{
   *len = srclen;
   for (int i = 0; i < srclen; i++)
   {
      array[i] = *((uint8_t *)(src + (i + sizeof(base)) / sizeof(base) * sizeof(base) - 1 - i % sizeof(base)));  //To compensae for the weird way of writing memory from registers

        #ifdef DEV
      printf("%02x", array[i]);
        #endif
   }
   return(true);
}
