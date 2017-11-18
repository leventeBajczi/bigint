#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdlib.h>
#include "../../typedefs.h"
#include "load.h"
#include "../../base_arithmetic/headers/compl.h"
#include "../../base_arithmetic/headers/add.h"
#include "../../base_arithmetic/headers/mul.h"
#include "../../advanced_arithmetic/headers/rest.h"
#include "../../advanced_arithmetic/headers/powmod.h"

uint8_t* addbig(uint8_t*, base, uint8_t*, base);
uint8_t* subbig(uint8_t*, base, uint8_t*, base);
uint8_t* mulbig(uint8_t*, base, uint8_t*, base);
uint8_t* restbig(uint8_t*, base, uint8_t*, base);
uint8_t* powmodulo(uint8_t*, base, uint8_t*, base, uint8_t*, base);
uint8_t* isprime(uint8_t*, base, base);
boolean isnull(uint8_t*, base);
boolean setbig(uint8_t*, base, uint8_t);


#endif