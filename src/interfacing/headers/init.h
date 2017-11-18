#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <string.h>
 #include <sys/mman.h>
#include "../../typedefs.h"

boolean test_mem(base *, base);
boolean del(base * *, base *, uint8_t);
boolean init(base * *, base * *, base *, uint8_t);
boolean allocate_safemem(base *, base);

#endif
