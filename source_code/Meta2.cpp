/* ===================================================================================
	Departamento Eng. Informatica - FCTUC
	Computacao Grafica - 2021/22
	................................................ Tiago Oliveira nº 2019219068
	Meta 2 - Projeto
======================================================================================= */

#include "Meta2.h"

//================================================================================
//=========================================================================== INIT
void initTextures() {
	//------------------------------------------------------------------ SKY BOX
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("Indoor.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ LEATHER
	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("Leather.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ BLACK PLASTIC
	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("Plastic_BLACK.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ RED PLASTIC
	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	imag.LoadBmpFile("Plastic_RED.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ BLUE PLASTIC
	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("Plastic_BLUE.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ WHITE PLASTIC
	glGenTextures(1, &texture[5]);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	imag.LoadBmpFile("Plastic_WHITE.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());

	//------------------------------------------------------------------ STARTUP IMAGE
	glGenTextures(1, &texture[6]);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	imag.LoadBmpFile("startup.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
}

void initMaterials(int material) {
	switch (material) {
	case 0: //……………………………………………………………………………………………chrome
		glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, chromeSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, chromeCoef);
		break;
	case 1: //……………………………………………………………………………………………blackPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
		break;
	case 2: //……………………………………………………………………………………………whitePlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, whitePlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whitePlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whitePlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, whitePlasticCoef);
		break;
	}
}

//…………………………………………………………………………………………………………………………………………… LUZES
void initLights(void) {
	//…………………………………………………………………………………………………………………………………………… Ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	//…………………………………………………………………………………………………………………………………………… Teto
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);

	//……………………………………………………………………………………………………………………………Foco
	glLightfv(GL_LIGHT1, GL_POSITION, Pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Foco_cor);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Foco_ak);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Foco_al);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Foco_aq);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Foco_direccao);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Foco_Expon);
}

void inicializa(void)
{
	glClearColor(WHITE);
	glShadeModel(GL_SMOOTH);	//………………………………………………………………………………Interpolacao de cores
	glEnable(GL_DEPTH_TEST);	//………………………………………………………………………………Profundidade
	glEnable(GL_NORMALIZE);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_FLOAT, 0, normais);
	glEnableClientState(GL_NORMAL_ARRAY);

	glTexCoordPointer(2, GL_FLOAT, 0, texturas);   // coordenadas textura
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	initTextures();

	//…………………………………………………………………………………………………………………………… ILUMINACAO / Materiais
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	initLights();
	initMaterials(2);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Esfera : Quadrica
void drawEsfera()
{
	//------------------------- Esfera
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	initMaterials(2);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluQuadricDrawStyle(esfera, GLU_FILL);
	gluQuadricNormals(esfera, GLU_SMOOTH);
	gluQuadricTexture(esfera, GL_TRUE);
	gluSphere(esfera, 60.0, 100, 100);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void drawCube() {
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, esquerda);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, direita);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, cima);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, baixo);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, frente);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, tras);
}

void drawMalha() {
	int				i, j;
	float			med_dim = (float)dim / 2;

	//------------------------------------ TOPO
	glPushMatrix();
	glTranslatef(-4.5, -1.55, -3);
	glRotatef(90, 1, 0, 0);
	glScalef(4.5, 3, 0);
	glNormal3f(0, 1, 0);          //normal 
	glBegin(GL_QUADS);
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++) {
			glTexCoord2f((float)j / dim, (float)i / dim);
			glVertex3d((float)j / med_dim, (float)i / med_dim, 0);
			glTexCoord2f((float)(j + 1) / dim, (float)i / dim);
			glVertex3d((float)(j + 1) / med_dim, (float)i / med_dim, 0);
			glTexCoord2f((float)(j + 1) / dim, (float)(i + 1) / dim);
			glVertex3d((float)(j + 1) / med_dim, (float)(i + 1) / med_dim, 0);
			glTexCoord2f((float)j / dim, (float)(i + 1) / dim);
			glVertex3d((float)j / med_dim, (float)(i + 1) / med_dim, 0);
		}
	glEnd();
	glPopMatrix();

	//------------------------------------ FRENTE
	glPushMatrix();
	glTranslatef(-4.5, -2.15, 3);
	glScalef(4.5, 0.3, 0);
	glNormal3f(0, 0, 1);          //normal 
	glBegin(GL_QUADS);
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++) {
			glTexCoord2f((float)j / dim, (float)i / dim);
			glVertex3d((float)j / med_dim, (float)i / med_dim, 0);
			glTexCoord2f((float)(j + 1) / dim, (float)i / dim);
			glVertex3d((float)(j + 1) / med_dim, (float)i / med_dim, 0);
			glTexCoord2f((float)(j + 1) / dim, (float)(i + 1) / dim);
			glVertex3d((float)(j + 1) / med_dim, (float)(i + 1) / med_dim, 0);
			glTexCoord2f((float)j / dim, (float)(i + 1) / dim);
			glVertex3d((float)j / med_dim, (float)(i + 1) / med_dim, 0);
		}
	glEnd();
	glPopMatrix();
}

void drawScene() {
	glEnable(GL_TEXTURE_2D);
	//==================================== Nintendo	
	//------------------------------------ Carcaça da consola
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(2.0, 1.0, 0.1);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	drawCube();

	//------------------------------------ Ecrã da consola
	glTranslatef(0, 0, .1);
	glScalef(.9, .81, 1);	//90% da escala de 90% que seria precisa caso se usasse mais um push e um pop
	if (ligado) 
		glBindTexture(GL_TEXTURE_2D, texture[6]);
	else 
		glBindTexture(GL_TEXTURE_2D, texture[5]);
	drawCube();
	glPopMatrix();

	//------------------------------------ Comando Esquerdo
	glPushMatrix();
	glTranslatef(-3.45, hComE, 0);
	glScalef(.3, 1, .1);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	drawCube();
	glPopMatrix();

	//------------------------------------ Comando Direito
	glPushMatrix();
	glTranslatef(3.45, hComD, 0);
	glScalef(.3, 1, .1);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	drawCube();
	glPopMatrix();

	//------------------------------------ Analógico Esquerdo
	glPushMatrix();
	glTranslatef(-3.45, hComE + .5, 0);
	glRotatef(agEY, 1.0, 0.0, 0.0);
	glRotatef(agEX, 0.0, 1.0, 0.0);
	glTranslatef(0, 0, .15);
	glScalef(.03, .03, .15);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	drawCube();

	glTranslatef(0, 0, 1.5);
	glScalef(4, 4, .2);
	drawCube();
	glPopMatrix();

	//------------------------------------ Analógico Direito
	glPushMatrix();
	glTranslatef(3.45, hComD - .5, 0);
	glRotatef(agDY, 1.0, 0.0, 0.0);
	glRotatef(agDX, 0.0, 1.0, 0.0);
	glTranslatef(0, 0, .15);
	glScalef(.03, .03, .15);
	drawCube();

	glTranslatef(0, 0, 1.5);
	glScalef(4, 4, .2);
	drawCube();
	glPopMatrix();

	//------------------------------------- Botao Esquerdo
	glPushMatrix();
	glTranslatef(-3.45, hComE - .5, BotaoE);
	glScalef(.05, .05, .1);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	drawCube();
	glPopMatrix();

	//------------------------------------- Botao Direito
	glPushMatrix();
	glTranslatef(3.45, hComD + .5, BotaoD);
	glScalef(.05, .05, .1);
	drawCube();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//------------------------------------- Mesa
	glPushMatrix();
	initMaterials(material);		// CHROME / BLACK PLASTIC
	glTranslatef(0, -6.65, 0);
	glScalef(0.5, 3, 0.5);
	drawCube();
	glPopMatrix();
	
	initMaterials(2);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (malha) drawMalha();
	else {
		glPushMatrix();
		glTranslatef(0, -1.85, 0);
		glScalef(3, .2, 2);
		drawCube();
		glPopMatrix();
	}
	glDisable(GL_BLEND);
	glPopMatrix();
	
}

//======================================================================== ILUMINCCAO
void iluminacao() {
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
	if (ligaTeto)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);

	//……………………………………………………………………………………………………………………………Foco
	glLightfv(GL_LIGHT1, GL_POSITION, Pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Foco_cor);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Foco_ak);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Foco_al);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Foco_aq);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Foco_direccao);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Foco_Expon);

	if (Foco)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);
}

void desenhaTexto(char* string, GLfloat x, GLfloat y, GLfloat z) {
	glRasterPos3f(x, y, z);
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string++);
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//=============================================== Viewport0 Informacao - sem corIluminacao
	glDisable(GL_LIGHTING);
	glViewport(0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-xC, xC, -xC, xC, -zC, zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, -1);

	//------------------------------------------------ Informacao
	glColor3f(1, 1, 1);			// nao se está a usar LUZ !!   DisableLight
	sprintf_s(texto, 30, "Ambiente 'Z' - %d", Dia);
	desenhaTexto(texto, -90, 1, -92);
	sprintf_s(texto, 30, "Pontual 'T' ['Y' - %.0f %%]", intensidadeT*50.0);
	desenhaTexto(texto, -90, 1, -88);
	sprintf_s(texto, 30, "\tR - %d | G - %d | B - %d' ", luzR, luzG, luzB);
	desenhaTexto(texto, -90, 1, -84);
	sprintf_s(texto, 30, "Foco 'F' - %d | ", Foco);
	desenhaTexto(texto, -90, 1, -80);
	sprintf_s(texto, 30, "Intensidade ['9'/'0' - %d] |", dim);
	desenhaTexto(texto, -70, 1, -80);
	sprintf_s(texto, 30, " Abertura ['7'/'8' - %.0f]", aberturaFoco);
	desenhaTexto(texto, -33, 1, -80);
	sprintf_s(texto, 30, "Malha 'N' - %d ", malha);
	desenhaTexto(texto, -90, 1, -76);
	sprintf_s(texto, 30, "Material 'M' - %s ", Materiais[material]);
	desenhaTexto(texto, -90, 1, -72);
	if (material == 0)
		sprintf_s(texto, 30, "Coef Espec '5'/'6' - %d ", chromeCoef);
	else
		sprintf_s(texto, 30, "Coef Espec '5'/'6' - %d ", blackPlasticCoef);
	desenhaTexto(texto, -57, 1, -72);

	strcpy_s(texto, "Observador: SETAS");
	desenhaTexto(texto, 50, 1, -92);
	strcpy_s(texto, "Com Esq - Sub '1'/Des '2'");
	desenhaTexto(texto, 50, 1, -88);
	strcpy_s(texto, "Com Dir - Sub '3'/Des '4'");
	desenhaTexto(texto, 50, 1, -84);
	strcpy_s(texto, "Rodar Analogico Esq 'w/s/a/d'");
	desenhaTexto(texto, 50, 1, -80);
	strcpy_s(texto, "Rodar Analogico Dir 'i/k/j/l'");
	desenhaTexto(texto, 50, 1, -76);
	strcpy_s(texto, "Pressionar Botoes 'q/p'");
	desenhaTexto(texto, 50, 1, -72);
	strcpy_s(texto, "Zoom +/-");
	desenhaTexto(texto, 50, 1, -68);

	//================================================================= ViewPort 1
	glEnable(GL_LIGHTING);
	glViewport(0, 0, wScreen, hScreen);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angZoom, (float)wScreen / hScreen, 0.1, 3 * zC);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);

	//…………………………………………………………………………………………………………………………………………………………Objectos
	iluminacao();
	drawEsfera();
	drawScene();

	//================================================================= ViewPort 2
	initMaterials(2);
	glViewport(0, 0, 200, 150);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// A consola tem um comprimento de 3.9 e uma altura de 1.5
	// A proporcao do ecra e de 1:0.75
	glOrtho(-4, 4, -3, 3, 0, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 1, 0, 0, -1, 0, 1, 0);

	//…………………………………………………………………………………………………………………………………………………………Objectos
	iluminacao();
	drawScene();

	//. . . . . . . . . . . . . . . . . . . . .  Actualização
	glutSwapBuffers();
}

void updateLuz() {
	localCorAmb[0] = luzR * intensidadeT;
	localCorAmb[1] = luzG * intensidadeT;
	localCorAmb[2] = luzB * intensidadeT;
	localCorDif[0] = luzR * intensidadeT;
	localCorDif[1] = luzG * intensidadeT;
	localCorDif[2] = luzB * intensidadeT;
	localCorEsp[0] = luzR * intensidadeT;
	localCorEsp[1] = luzG * intensidadeT;
	localCorEsp[2] = luzB * intensidadeT;
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
}

void Timer(int value)
{
	if (boolEY1) if (agEY > -30 && agEY <= 0) agEY -= inc; else boolEY1 = false;
	if (!boolEY1 && agEY < 0) agEY += inc;
	if (boolEY2) if (agEY < 30 && agEY >= 0) agEY += inc; else boolEY2 = false;
	if (!boolEY2 && agEY > 0) agEY -= inc;
	if (boolEX1) if (agEX > -30 && agEX <= 0) agEX -= inc; else boolEX1 = false;
	if (!boolEX1 && agEX < 0) agEX += inc;
	if (boolEX2) if (agEX < 30 && agEX >= 0) agEX += inc; else boolEX2 = false;
	if (!boolEX2 && agEX > 0) agEX -= inc;
	if (boolDY1) if (agDY > -30 && agDY <= 0) agDY -= inc; else boolDY1 = false;
	if (!boolDY1 && agDY < 0) agDY += inc;
	if (boolDY2) if (agDY < 30 && agDY >= 0) agDY += inc; else boolDY2 = false;
	if (!boolDY2 && agDY > 0) agDY -= inc;
	if (boolDX1) if (agDX > -30 && agDX <= 0) agDX -= inc; else boolDX1 = false;
	if (!boolDX1 && agDX < 0) agDX += inc;
	if (boolDX2) if (agDX < 30 && agDX >= 0) agDX += inc; else boolDX2 = false;
	if (!boolDX2 && agDX > 0) agDX -= inc;


	if (boolBE) if (BotaoE > 0.05) BotaoE -= pressao; else boolBE = false;
	if (!boolBE && BotaoE < 0.15) BotaoE += pressao;
	if (boolBD) if (BotaoD > 0.05) BotaoD -= pressao; else boolBD = false;
	if (!boolBD && BotaoD < 0.15) BotaoD += pressao;

	glutPostRedisplay();
	glutTimerFunc(30, Timer, 0);
}

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
		//------------------------------- Comando Esquerdo
	case '1': 
		if (hComE < 3.5)
			hComE += incComandos;
		glutPostRedisplay();
		break;
	case '2':
		if (hComE > 0)
			hComE -= incComandos;
		glutPostRedisplay();
		break;
		//------------------------------- Comando Direito
	case '3':
		if (hComD < 3.5)
			hComD += incComandos;
		glutPostRedisplay();
		break;
	case '4':
		if (hComD > 0)
			hComD -= incComandos;
		glutPostRedisplay();
		break;
		//------------------------------- Analogico Esquerdo
	case 'W': case 'w':
		boolEY1 = true;
		break;
	case 'S': case 's':
		boolEY2 = true;
		break;
	case 'A': case 'a':
		boolEX1 = true;
		break;
	case 'D': case 'd':
		boolEX2 = true;
		break;
		//------------------------------- Analogico Direito
	case 'I': case 'i':
		boolDY1 = true;
		break;
	case 'K': case 'k':
		boolDY2 = true;
		break;
	case 'J': case 'j':
		boolDX1 = true;
		break;
	case 'L': case 'l':
		boolDX2 = true;
		break;
		//------------------------------- Botao Esquerdo
	case 'Q': case 'q':
		boolBE = true;
		ligado = false;
		break;
		//------------------------------- Botao Direito
	case 'P': case 'p':
		boolBD = true;
		ligado = true;
		break;
		//------------------------------- Mudar angulo da perspetiva
	case '+':
		if (angZoom > 15)
			angZoom -= incZoom;
		glutPostRedisplay();
		break;
	case '-':
		if (angZoom < 105)
			angZoom += incZoom;
		glutPostRedisplay();
		break;

	//===================================== ILUMINCAAO
	//--------------------------- Dia/noite
	case 'Z': case 'z':
		Dia = !Dia;
		if (Dia) {
			luzGlobalCorAmb[0] = 1.0;
			luzGlobalCorAmb[1] = 1.0;
			luzGlobalCorAmb[2] = 1.0;
		}
		else {
			luzGlobalCorAmb[0] = 0.0;
			luzGlobalCorAmb[1] = 0.0;
			luzGlobalCorAmb[2] = 0.0;
		}
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);
		glutPostRedisplay();
		break;

		//--------------------------- TETO
	case 't':case 'T':
		ligaTeto = !ligaTeto;
		updateLuz();
		glutPostRedisplay();
		break;
		//--------------------------- Iluminacao da sala
	case 'Y': case 'y':
		intensidadeT += 0.1;
		if (intensidadeT > 2.1) intensidadeT = 0;
		updateLuz();
		glutPostRedisplay();
		break;
	case 'R': case 'r':
		luzR = (luzR + 1) % 2;
		updateLuz();
		glutPostRedisplay();
		break;
	case 'G': case 'g':
		luzG = (luzG + 1) % 2;
		updateLuz();
		glutPostRedisplay();
		break;
	case 'B': case 'b':
		luzB = (luzB + 1) % 2;
		updateLuz();
		glutPostRedisplay();
		break;
		//--------------------------- Material
	case 'm': case 'M':
		if (material == 0) material = 1;
		else material = 0;
		initMaterials(material);
		glutPostRedisplay();
		break;
		//--------------------------- Malha
	case 'n': case 'N':
		malha = !malha;
		glutPostRedisplay();
		break;
		//--------------------------- Foco
	case 'f': case 'F':
		Foco = !Foco;
		glutPostRedisplay();
		break;
		//--------------------------- Dimensao Foco
	case '0':
		dim = 2 * dim;
		if (dim > 256) dim = 256;
		glutPostRedisplay();
		break;
	case '9':
		dim = 0.5 * dim;
		if (dim < 1) dim = 1;
		glutPostRedisplay();
		break;
		//--------------------------- Abertura do Foco
	case '8':
		aberturaFoco += anguloINC;
		if (aberturaFoco > anguloMAX) aberturaFoco = anguloMAX;
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
		glutPostRedisplay();
		break;
	case '7':
		aberturaFoco -= anguloINC;
		if (aberturaFoco < anguloMIN) aberturaFoco = anguloMIN;
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
		glutPostRedisplay();
		break;
		//--------------------------- Coeficiente de Especularidade
	case '6':
		chromeCoef = 2 * chromeCoef;
		if (chromeCoef > 256) chromeCoef = 256;
		glMaterialf(GL_FRONT, GL_SHININESS, chromeCoef);
		glutPostRedisplay();
		break;
	case '5':
		chromeCoef = 0.5 * chromeCoef;
		if (chromeCoef < 1) chromeCoef = 1;
		glMaterialf(GL_FRONT, GL_SHININESS, chromeCoef);
		glutPostRedisplay();
		break;
		//--------------------------- Escape
	case 27:
		exit(0);
		break;
	}

}


void teclasNotAscii(int key, int x, int y) {
	//.. observador pode andar à volda da cena  (setas esquerda / direita)
	//.. observador pode andar para cima e para baixo (setas cima / baixo )

	if (key == GLUT_KEY_UP)   obsP[1] += 0.5;
	if (key == GLUT_KEY_DOWN) obsP[1] -= 0.5;
	if (key == GLUT_KEY_LEFT)  aVisao += 0.1;
	if (key == GLUT_KEY_RIGHT) aVisao -= 0.1;

	if (obsP[1] > 10)   obsP[1] = 10;   // limita altura
	if (obsP[1] < -10)  obsP[1] = -10;

	obsP[0] = rVisao * cos(aVisao);      // actualiza posicao (X,Z)
	obsP[2] = rVisao * sin(aVisao);

	glutPostRedisplay();
}


//======================================================= MAIN
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(wScreen, hScreen);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Tiago Oliveira - 2019219068");

	inicializa();

	glutSpecialFunc(teclasNotAscii);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, Timer, 0);

	glutMainLoop();

	return 0;
}
