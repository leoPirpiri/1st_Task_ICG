#include "main.h"
#include <unistd.h>
#include <vector>

#define ESPECURA_LINHA 2

int i = 0;
int j = IMAGE_WIDTH*0.3;
int fatorH = 0;
int direcao = 0; //1 to up; 0 to front; -1 to down;
std::vector<int> cor;
//vermelho
//preto/*
/*
cor2.push_back(255); //Alpha
cor2.push_back(0); //Red
cor2.push_back(0); //Green
cor2.push_back(0); //Blue/*/
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	
	cor.push_back(255); //Alpha
	cor.push_back(255); //Red
	cor.push_back(0); //Green
	cor.push_back(0); //Blue
	if (direcao == 0) {
		putPixel(i++, cor, ESPECURA_LINHA, 0, 1);
		if(i>IMAGE_WIDTH/4 && i<(3*IMAGE_WIDTH)/4) {
			direcao = -1;
		}
		if (i>=IMAGE_WIDTH){
			i=0;
		}
	}else{
		if((i>=IMAGE_WIDTH/4 && i<(4*IMAGE_WIDTH)/12) || (i>=IMAGE_WIDTH/2 && i<(15*IMAGE_WIDTH)/24) || (i>=(17*IMAGE_WIDTH)/24 && i<=(3*IMAGE_WIDTH)/4)) {
			putPixel(i++, cor, ESPECURA_LINHA*2, fatorH, 1);
			fatorH += 2;
		}else{
			putPixel(i++, cor, ESPECURA_LINHA*2, fatorH, -1);
			fatorH -= 2;
		}
		if(i>(3*IMAGE_WIDTH)/4){
			direcao = 0;
			fatorH = 0;
		}
	}
	cor.push_back(255); //Alpha
	cor.push_back(0); //Red
	cor.push_back(0); //Green
	cor.push_back(0); //Blue
	for (int k = IMAGE_HEIGHT*0.19; k<=IMAGE_HEIGHT*0.8; k++){
		beatHeart(j, cor, k);
	}
	if (++j>=IMAGE_WIDTH) {
		j=0;
	}
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

