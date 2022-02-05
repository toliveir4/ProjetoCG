/* ===================================================================================
	Departamento Eng. Informatica - FCTUC
	Computacao Grafica - 2021/22
	................................................ Tiago Oliveira nº 2019219068
	Meta 2 - Projeto
======================================================================================= */

#ifndef META2_H
#define META2_H

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/Glut.h>
#include "RgbImage.h"

//--------------------------------- Definir cores
#define WHITE    1.0, 1.0, 1.0, 1.0
#define PI		 3.14159

//------------------------------------------------------------ Objectos (sistema coordenadas)
GLint		wScreen = 800, hScreen = 600;			//.. janela (pixeis)
GLfloat		xC = 100.0, yC = 100.0, zC = 100.0;		//.. Mundo  (unidades mundo)

//------------------------------------------------------------ Visualizacao/Observador 
GLfloat  rVisao = 10, aVisao = 0.5 * PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 3.0, rVisao * sin(aVisao) };
GLfloat  angZoom = 65;
GLfloat  incZoom = 10;

GLfloat hComE = 0.0;		//.. altura do comando da esquerda/ incremento para translacao
GLfloat hComD = 0.0;		//.. altura do comando da direita
GLfloat incComandos = 0.5;			//.. incremento para translacao

GLfloat agEY = 0.0, agEX = 0.0;		//.. angulo de rotacao do analogico esquerdo (Eixo Y) / (Eixo X)
GLfloat agDY = 0.0, agDX = 0.0;		//.. angulo de rotacao do analogico direito (Eixo Y) / (Eixo X)
GLfloat inc = 3.0;					//.. incremento para rotacao
GLboolean boolEY1, boolEY2, boolEX1, boolEX2, boolDY1, boolDY2, boolDX1, boolDX2;

GLfloat BotaoE = 0.15, BotaoD = 0.15, pressao = 0.01;		//.. pressionar o botao incrementa esta variavel e reinicia-a
GLboolean boolBE, boolBD;

GLboolean ligado = false;

char     texto[30];

static GLfloat vertices[] = {
	//…………………………………………………………………………………………………… x=tam (Esquerda) 
		-1.5,   1.5,  1.5,	// 0 
		-1.5,   1.5, -1.5,	// 1 
		-1.5,  -1.5, -1.5,	// 2 
		-1.5,  -1.5,  1.5,	// 3
	//…………………………………………………… Direita
		 1.5,  -1.5,  1.5,	// 4 
		 1.5,  -1.5, -1.5,	// 5
		 1.5,   1.5, -1.5,	// 6
		 1.5,   1.5,  1.5,	// 7  
	//……………………………………………………… Cima
		-1.5,  1.5,  1.5,	// 8 
		 1.5,  1.5,  1.5,	// 9 
		 1.5,  1.5, -1.5,	// 10
		-1.5,  1.5, -1.5,	// 11
	//……………………………………………………… Baixo
		-1.5, -1.5,  1.5,	// 12
		-1.5, -1.5, -1.5,	// 13
		1.5, -1.5, -1.5,	// 14
		1.5, -1.5,  1.5,	// 15
	//……………………………………………………… Frente
		-1.5,  1.5,  1.5,	// 16 
		-1.5, -1.5,  1.5,	// 17 
		 1.5, -1.5,  1.5,	// 18
		 1.5,  1.5,  1.5,	// 19
	//……………………………………………………… Trás
		 1.5,  1.5, -1.5,	// 20 
		 1.5, -1.5, -1.5,	// 21 
		-1.5, -1.5, -1.5,	// 22
		-1.5,  1.5, -1.5,	// 23
};

static GLfloat normais[] = {
	//…………………………………………………………………………………………………… Esquerda
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
		-1.0,  0.0,  0.0,
	//…………………………………………………………………………………………………… Direita
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
		1.0,  0.0,  0.0,
	//…………………………………………………………………………………………………… Cima
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
		0.0,  1.0,  0.0,
	//…………………………………………………………………………………………………… Baixo
		0.0, -1.0,  0.0,
		0.0, -1.0,  0.0,
		0.0, -1.0,  0.0,
		0.0, -1.0,  0.0,
	//…………………………………………………………………………………………………… Frente
		0.0,  0.0,  1.0,
		0.0,  0.0,  1.0,
		0.0,  0.0,  1.0,
		0.0,  0.0,  1.0,
	//…………………………………………………………………………………………………… Trás
		0.0,  0.0, -1.0,
		0.0,  0.0, -1.0,
		0.0,  0.0, -1.0,
		0.0,  0.0, -1.0,
};

static GLuint	esquerda[] = { 0, 1, 2, 3 };
static GLuint	direita[] = { 4, 5, 6, 7 };
static GLuint	cima[] = { 8, 9, 10,  11 };
static GLuint	baixo[] = { 12, 13, 14,  15 };
static GLuint	frente[] = { 16, 17, 18,  19 };
static GLuint	tras[] = { 20, 21, 22,  23 };


//=================================================================== TEXTURAS
static GLfloat texturas[] = {
	//…………………………………………………… Esquerda 
		 1,  1,		// 0 
		 1,  0,		// 1 
		 0,  0,		// 2 
		 0,  1,		// 3
	//…………………………………………………… Direita
		 0,  1,		// 4 
		 0,  0,		// 5
		 1,  0,		// 6
		 1,  1,		// 7  
	//…………………………………………………… Cima
		 0,  1,		// 8 
		 1,  1,		// 9 
		 1,  0,		// 10
		 0,  0,		// 11
	//…………………………………………………… Baixo
		 0,  1,		// 12
		 0,  0,		// 13
		 1,  0,		// 14
		 1,  1,		// 15
	//…………………………………………………… Frente
		 0,  1,		// 16 
		 0,  0,		// 17 
		 1,  0,		// 18
		 1,  1,		// 19
	//…………………………………………………… Trás
		 1,  1,		// 20 
		 1,  0,		// 21 
		 0,  0,		// 22
		 0,  1,		// 23
};

RgbImage imag;

//------------------------------------------------------------ Skybox
GLUquadricObj* esfera = gluNewQuadric();
//------------------------------------------------------------ Texturas
GLuint   texture[7];

//------------------------------------------------- Propriedades Materiais
char Materiais[2][30] = {"Chrome", "blackPlastic"};

GLfloat  chromeAmb[] = { 0.25 ,0.25 ,0.25 };
GLfloat  chromeDif[] = { 0.4 ,0.4 ,0.4 };
GLfloat  chromeSpec[] = { 0.774597 ,0.774597 ,0.774597 };
GLint  chromeCoef = 0.6 * 128;

GLfloat blackPlasticAmb[] = { 0.0 ,0.0 ,0.0 };
GLfloat blackPlasticDif[] = { 0.00 ,0.00 ,0.00 };
GLfloat blackPlasticSpec[] = { 0.0 ,0.00 ,0.0 };
GLint blackPlasticCoef = 0.25 * 128;

GLfloat whitePlasticAmb[] = { 0.8 ,0.8 ,0.8 };
GLfloat whitePlasticDif[] = { 0.55 ,0.55 ,0.55 , 0.3 };
GLfloat whitePlasticSpec[] = { 0.870 ,0.870 ,0.870 };
GLint whitePlasticCoef = 0.25 * 128;

GLint material = 0;

//---------------------------------------------------- AMBIENTE - fixa
GLint   Dia = 0;     //:::   'Z'  
GLfloat intensidadeDia = 0;
GLfloat luzGlobalCorAmb[4] = { intensidadeDia, intensidadeDia, intensidadeDia, 1.0 };   // 

//---------------------------------------------------- Luz pontual no TETO (eixo Y)
GLint   ligaTeto = 1;		 //:::   'T'  
GLfloat intensidadeT = 0.3;  //:::   'Y'  
GLint   luzR = 1;		 	 //:::   'R'  
GLint   luzG = 1;			 //:::   'G'  
GLint   luzB = 1;			 //:::   'B'  
GLfloat localPos[4] = { 0.0, 5.0, 0.0, 1.0 };
GLfloat localCorAmb[4] = { 0, 0, 0, 0.0 };
GLfloat localCorDif[4] = { luzR, luzG, luzB, 1.0 };
GLfloat localCorEsp[4] = { luzR, luzG, luzB, 1.0 };

//…………………………………………………………………………………………………………………………………………………………………………………………
GLboolean 		Foco = 0;		//.. Foco ligado ou desligado
GLfloat		aberturaFoco = 20.0;		//.. angulo inicial do foco
GLfloat		anguloINC = 3.0;		//.. incremento
GLfloat		anguloMIN = 3.0;		//.. minimo
GLfloat		anguloMAX = 70.0;		//.. maximo

GLfloat Foco_direccao[] = { 0, 0, -1, 0 };
GLfloat Foco_cor[] = { 1, 1, 1, 1 };
GLfloat Foco_ak = 1.0;
GLfloat Foco_al = 0.05f;
GLfloat Foco_aq = 0.0f;
GLfloat Foco_Expon = 2.0;		// Foco, SPOT_Exponent

GLfloat Pos[] = { 0, 1, 15, 1};   // Foco

//…………………………………………………………………………………………………………………………………
GLint dim = 128;   //numero divisoes da grelha

GLboolean malha = 0;

#endif // !META2_H
