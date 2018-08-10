#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"


//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

	int change_red = 255;
	int change_blue = 255;
	int change_green = 255;

	void print_a_dot(int aux, int troca) {
	aux=aux*4;
	if (troca == 1){
		change_red = rand()%255;
		change_blue = rand()%255;
		change_green = rand()%255;
	}
	int middle_dot = 2*IMAGE_WIDTH*(IMAGE_HEIGHT+1);
		//for (int i=0; i<IMAGE_WIDTH*2; i+=4){
			FBptr[middle_dot+aux] = change_red;   //Red
			FBptr[middle_dot+1+aux] = change_green; //Green
			FBptr[middle_dot+2+aux] = change_blue; //Blue
			FBptr[middle_dot+3+aux] = 255; //Alpha
			FBptr[(IMAGE_WIDTH*4)+middle_dot+aux] = change_red;   //Red
			FBptr[(IMAGE_WIDTH*4)+middle_dot+1+aux] = change_green; //Green
			FBptr[(IMAGE_WIDTH*4)+middle_dot+2+aux] = change_blue; //Blue
			FBptr[(IMAGE_WIDTH*4)+middle_dot+3+aux] = 255; //Alpha
			FBptr[(IMAGE_WIDTH*8)+middle_dot+aux] = change_red;   //Red
			FBptr[(IMAGE_WIDTH*8)+middle_dot+1+aux] = change_green; //Green
			FBptr[(IMAGE_WIDTH*8)+middle_dot+2+aux] = change_blue; //Blue
			FBptr[(IMAGE_WIDTH*8)+middle_dot+3+aux] = 255; //Alpha
		//}
	}

#endif // _MYGL_H_

