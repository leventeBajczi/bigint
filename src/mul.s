.globl mul

#multiplies two keylen+1 length numbers (at ptr and ptr+keylen+1) and stores it in the space after these two (2*(keylen+1)-sized)

.text
mul:
   