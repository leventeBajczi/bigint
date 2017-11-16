#ifndef LOAD_H
#define LOAD_H

#include "../../typedefs.h"

#ifdef DEV
#include <stdio.h>
#endif

boolean load(uint8_t*, base, base, base*);
boolean store(uint8_t*, base*, base, base);

#endif