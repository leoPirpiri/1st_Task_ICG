#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

	void print_a_dot(void) {
	int middle_dot = 2*IMAGE_WIDTH*(IMAGE_HEIGHT+1);
		for (int i=0; i<IMAGE_WIDTH*2; i++){
			FBptr[middle_dot+i] = i/255; //componente R
			FBptr[middle_dot+1+i] = i/255; //componente G
			FBptr[middle_dot+2+i] = i/255; //componente B
			FBptr[middle_dot+3+i] = 255; //componente A
		}
	}

#endif // _MYGL_H_

