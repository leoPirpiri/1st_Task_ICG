#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>

#define MIDDLE 2*IMAGE_WIDTH*IMAGE_HEIGHT
//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
	void putPixel (int ponto, std::vector<int> cor, int especura, int fatorH, int direcao){
		ponto = ponto*4;
		for (int i=0; i<especura; i++){
			FBptr[MIDDLE+(IMAGE_WIDTH*4*fatorH)+(i*IMAGE_WIDTH*4*direcao)+ponto] = cor.at(1); //Red
			FBptr[MIDDLE+(IMAGE_WIDTH*4*fatorH)+(i*IMAGE_WIDTH*4*direcao)+ponto+1] = cor.at(2); //Green
			FBptr[MIDDLE+(IMAGE_WIDTH*4*fatorH)+(i*IMAGE_WIDTH*4*direcao)+ponto+2] = cor.at(3); //Blue
			FBptr[MIDDLE+(IMAGE_WIDTH*4*fatorH)+(i*IMAGE_WIDTH*4*direcao)+ponto+3] = cor.at(0); //Alpha
		}	
	}
	void beatHeart(int ponto, std::vector<int> cor, int linha){
		ponto = ponto*4;
		FBptr[(IMAGE_WIDTH*4*linha)+ponto] = cor.at(5); //Red
		FBptr[(IMAGE_WIDTH*4*linha)+ponto+1] = cor.at(6); //Green
		FBptr[(IMAGE_WIDTH*4*linha)+ponto+2] = cor.at(7); //Blue
		FBptr[(IMAGE_WIDTH*4*linha)+ponto+3] = cor.at(4); //Alpha
	}
	void go_ahead(int ponto, std::vector<int> cor, int especura) {
		putPixel (ponto, cor, especura, 0, 1);
	}
	void go_down(int ponto, std::vector<int> cor, int especura, int fatorH) {
		putPixel (ponto, cor, especura*2, fatorH, 1);
	}
	void go_up(int ponto, std::vector<int> cor, int especura, int fatorH) {
		putPixel (ponto, cor, especura*2, fatorH, -1);
	}

#endif // _MYGL_H_

