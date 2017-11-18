#include "headers/shift.h"

extern base shiftright(base, base);
extern base shiftleft(base, base);

boolean shift_right(base a, base len, base c)
{
   for (base i = a; i < a + len; i += sizeof(base))
   {
      c = shiftright(i, c);
   }
   return(true);
}

boolean shift_left(base a, base len, base c)
{
   for (base i = a + len - sizeof(base); i >= a; i -= sizeof(base))
   {
      c = shiftleft(i, c) * 0x8000000000000000;
      c = c;
   }
   return(true);
}
