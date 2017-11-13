#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <string.h>
 #include <sys/mman.h>
#include "typedefs.h"

boolean test_mem();
boolean del();
boolean init(base*);
boolean allocate_safemem();

#endif