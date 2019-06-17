#include "header.h"
#include "function.h"

int CheckDimension(int ALUop, int vert_dimA0, int hor_dimA0, int vert_dimB0, int hor_dimB0)
{
	if (ALUop == ADD || ALUop == SUB) {
		if (vert_dimA0 == vert_dimB0 && hor_dimA0 == hor_dimB0)
			return VALID;
		else
			return INVALID;
	}
	
	else if (ALUop == MULTIPLY) {
		if (hor_dimA0 == vert_dimB0)
			return VALID;
		else
			return INVALID;
	}
	
	else
		return -1;
}
