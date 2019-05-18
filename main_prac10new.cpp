//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Pérez Tepox Luis Carlos *********************************//
//*************				CG02  PROYECTO FINAL						******//
//******************************* FERIA   *****************************//
//************************************************************//

#include "p10/texture.h"
#include "p10/figuras.h"
#include "p10/Camera.h"



#include "p10/cmodel/CModel.h"

#include "irrKlang.h"

using namespace irrklang;
ISoundEngine *SoundEngine = createIrrKlangDevice();
void game()
{

	SoundEngine->play2D("audio/2t.mp3", GL_TRUE);
}
//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture rusas;
CTexture esfera;
CTexture puesto;
CTexture rf;
CTexture tree;

CTexture palos;
CTexture can;
CTexture cerca1;
CTexture puesto2;
CTexture carpa;
CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras f_Metz;

CFiguras fig7; //Para el monito

//Figuras de 3D Studio
CModel kit;
CModel llanta;
CModel nigga;
CModel arbusto;
CModel fence;
CModel baño;
CModel banca;
CModel lampara;
CModel iman;

float movKitX = 0.0;
float movKitY = 0.0;
float movKitZ = 0.0;
float rol=0;
int rebanadas = 16;
int sas = 16;
double luz;
int i=0, c;
float x;
float vcs;

GLfloat torDiffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };			// Diffuse Light Values
GLfloat torSpecular[] = { 1.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat torPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };



//Animación del coche
float movKit = 0.0;
bool g_fanimacion = false;
bool dir = false;
bool circuito = false;
float rotKit = 0.0;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;



			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);			// Position The Light

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
	esfera.LoadTGA("p10/tigre.tga");
	esfera.BuildGLTexture();
	esfera.ReleaseImage();

    text1.LoadBMP("p10/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("p10/logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("p10/city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("p10/city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("p10/city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("p10/city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();


	rusas.LoadTGA("p10/rusa.tga");
	rusas.BuildGLTexture();
	rusas.ReleaseImage();

	rf.LoadTGA("p10/rf.tga");
	rf.BuildGLTexture();
	rf.ReleaseImage();

	can.LoadTGA("p10/cn.tga");
	can.BuildGLTexture();
	can.ReleaseImage();

	puesto.LoadTGA("p10/puesto.tga");
	puesto.BuildGLTexture();
	puesto.ReleaseImage();

	palos.LoadTGA("p10/palos.tga");
	palos.BuildGLTexture();
	palos.ReleaseImage();

	puesto2.LoadTGA("p10/puesto2.tga");
	puesto2.BuildGLTexture();
	puesto2.ReleaseImage();

	carpa.LoadTGA("p10/carpa.tga");
	carpa.BuildGLTexture();
	carpa.ReleaseImage();


	tree.LoadTGA("Tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();


	cerca1.LoadTGA("p10/cerca1.tga");
	cerca1.BuildGLTexture();
	cerca1.ReleaseImage();

	//Carga de Figuras
	kit._3dsLoad("p10/modelos/kitt.3ds");	
	//kit.VertexNormals();
	
	llanta._3dsLoad("p10/modelos/k_rueda.3ds");
	nigga._3dsLoad("p10/modelos/nigga.3ds");
	arbusto._3dsLoad("p10/modelos/arbustos.3ds");
	fence._3dsLoad("p10/modelos/fence1.3ds");
	baño._3dsLoad("p10/modelos/baños.3ds");
	lampara._3dsLoad("p10/modelos/lamparas.3ds");
	banca._3dsLoad("p10/modelos/bancas.3ds");
	iman._3dsLoad("p10/modelos/ironman.3ds");



	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void arbol_alpha()
{
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);

	glPopMatrix();
}


void canastilla() {

	glPushMatrix();
	glTranslatef(movKitX, movKitY, movKitZ);
	glRotatef(rotKit,0,0,1);
	glTranslatef(0,10,0);
	glRotatef(90,0,0,1);
	fig1.cono(2,1.5,20,rf.GLindex);
	glTranslatef(-1,-2,0);
	fig1.prisma(4,1,1.5,rf.GLindex);
	glTranslatef(1, 0, 1);
	fig1.prisma(4, 3, 0.5, rf.GLindex);
	glTranslatef(0, 0, -2);
	fig1.prisma(4, 3, 0.5, rf.GLindex);
	glTranslatef(0, -1.75, 1);
	fig1.prisma(0.5, 2, 1.5, rf.GLindex);

	glPopMatrix();


}

void arbol_blend()
{
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	//glEnable(GL_LIGHTING);
}


void fortuna() {
			glPushMatrix();
				
				glScalef(2,2,2);
				glTranslatef(15,20,-20);
				glRotatef(90,1,0,0);
				//glDisable(GL_LIGHTING);
					glPushMatrix();
						glRotatef(rol,0,1,0);
						//glColor3f(1, 0, 0);
						glMaterialfv(GL_FRONT, GL_DIFFUSE, torDiffuse);
						glMaterialfv(GL_FRONT, GL_SPECULAR, torDiffuse);
							fig1.torus(14,13, 50, 50);
							glRotatef(rol, 0, 1, 0);
							//fig1.torus(8, 7, 50, 50);
							glRotatef(rol, 0, 1, 0);
							glTranslatef(0,-5,0);
							glMaterialfv(GL_FRONT, GL_DIFFUSE, torDiffuse);
							glMaterialfv(GL_FRONT, GL_SPECULAR, torDiffuse);
							fig1.torus(14, 13, 50, 50);
							glRotatef(rol, 0, 1, 0);
							//fig1.torus(8, 7, 50, 50);
							glPushMatrix();
							glTranslatef(0,-0.5, 7);
							//fig1.cilindro(1, 6, 20, 0);
							glTranslatef(-4,0,-0.7);
							//fig1.cilindro(1, 6, 20, 0);
							glPopMatrix();
							glPopMatrix();
					glPushMatrix();
					glTranslatef(0,1,0);
					fig1.torus(3, 2.5, 50, 50);
					glTranslatef(0, -6, 0);
					fig1.torus(3, 2.5, 50, 50);
					glRotatef(-90, 1, 0, 0);
					glTranslatef(0,-19.5,2.5);
					fig7.prisma(1,30,14,rf.GLindex);

					//base delantera
					//glColor3f(1,1,1);
					glPushMatrix();
					glRotatef(-30,0,0,1);
					glTranslatef(-10,5,4);
					fig1.prisma(22,1,1, rf.GLindex);
					glPopMatrix();

					glPushMatrix();
					//glColor3f(1, 1, 1);
					glRotatef(30, 0, 0, 1);
					glTranslatef(10, 5, 4);
					fig1.prisma(22, 1, 1, rf.GLindex);
					glPopMatrix();

					//base trasera
					glPushMatrix();
					glRotatef(-30, 0, 0, 1);
					glTranslatef(-10, 5, -4);
					fig1.prisma(22, 1, 1, rf.GLindex);
					glPopMatrix();

					glPushMatrix();
					//glColor3f(1, 1, 1);
					glRotatef(30, 0, 0, 1);
					glTranslatef(10, 5, -4);
					fig1.prisma(22, 1, 1, rf.GLindex);
					glPopMatrix();
					/////////// CILINDRO DE GIRO
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0,-8,0);
					glRotatef(rol, 0, 1, 0);
					fig1.cilindro(3,12,20, rf.GLindex);
					//////// Y ES Z
					glPushMatrix();
					glTranslatef(0,8,0);
					glRotatef(90,1,0,0);
					fig1.cono(14, 1, 20, rf.GLindex);
					glTranslatef(0,0,0);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glPopMatrix();

					//CILINDROS DE SOPORTE TRASEROS
					glPushMatrix();
					glTranslatef(0, 3, 0);
					glRotatef(90, 1, 0, 0);
					fig1.cono(14, 1, 20, rf.GLindex);
					glTranslatef(0, 0, 0);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glRotatef(30, 0, 0, 1);
					fig1.cono(14, 1, 20, rf.GLindex);
					glPopMatrix();
#if 0
					/// CILINDROS PARA CANASTILLAS

					glPushMatrix();

					glTranslatef(-13, 3.5, 0);
					glRotatef(90, 0, 1, 0);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-7, 0, 1.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-5, 0, 5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-1.5, 0, 6.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(2, 0, 7);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(5, 0, 4.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(6.5, 0, 2);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glPopMatrix();
					/// TERMINAN CILINDROS DE CANASTILLAS

					/// CILINDROS PARA CANASTILLAS TRASEROS

					glPushMatrix();

					glTranslatef(-13, 3.5, 0);
					glRotatef(90, 0, 1, 0);
					//fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(7, 0, 1.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(5, 0, 5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(1.5, 0, 6.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-2, 0, 7);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-5, 0, 4.5);
					fig1.cilindro(1, 4, 20, rf.GLindex);
					glTranslatef(-6.5, 0, 2);
					//fig1.cilindro(1, 4, 20, rf.GLindex);
					glPopMatrix();
					/// TERMINAN CILINDROS DE CANASTILLAS TRASEROS  
#endif // 0

					/// CANASTILLAS
					glPushMatrix();
					glTranslatef(-14, 5.5, 2);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);

					glPopMatrix();
					glPushMatrix();

					glTranslatef(-12,5.5,8);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();

					glPushMatrix();

					glTranslatef(-7, 5.5,13);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();

					glPushMatrix();

					glTranslatef(0, 5.5, 15);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();


					glPushMatrix();

					glTranslatef(8, 5.5, 13);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();


					glPushMatrix();

					glTranslatef(12.5, 5.5, 8);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();

					glPushMatrix();
					glTranslatef(14, 5.5, 2);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);

					glPopMatrix();

					///CANASTILLAS SUPERIORES

					glPushMatrix();

					glTranslatef(-12, 5.5, -7);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();

					glPushMatrix();

					glTranslatef(-7, 5.5,-13);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();

					glPushMatrix();

					glTranslatef(0, 5.5, -15);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();


					glPushMatrix();

					glTranslatef(8, 5.5, -13);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();


					glPushMatrix();

					glTranslatef(12.5, 5.5, -7);
					glRotatef(180, 0, 1, 0);
					glRotatef(-rol, 0, 1, 0);
					fig1.prisma(4, 1, 1.5, can.GLindex);
					glTranslatef(1, 0, 1);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, 0, -2);
					fig1.prisma(4, 3, 0.5, can.GLindex);
					glTranslatef(0, -1.75, 1);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glTranslatef(0, 3.75, 0);
					fig1.prisma(0.5, 3, 1.5, can.GLindex);
					glPopMatrix();
					glPopMatrix();


	//glEnable(GL_LIGHTING);
	glColor3f(1,1,1);
	glPopMatrix();

}

void cerca() {
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, cerca1.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-75.0, 0.0, -60);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(75.0, 0.0, -60);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(75.0, 5.0, -60);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-75.0, 5.0, -60);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);

	glPopMatrix();
	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glTranslatef(0,0,-2.5);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, cerca1.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-69.5, 0.0, -61.5);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(69.5, 0.0, -61.5);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(69.5, 5.0, -61.5);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-69.5, 5.0, -61.5);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);


	glPopMatrix();


	///segunda parte front y right

	glPushMatrix();
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, cerca1.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-75.0, 0.0, 59.25);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(75.0, 0.0, 59.25);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(75.0, 5.0, 59.25);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-75.0, 5.0, 59.25);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);

	glPopMatrix();
	glPushMatrix();

	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -2.5);
	//glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, cerca1.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-69.5, 0.0, 67);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(69.5, 0.0, 67);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(69.5, 5.0, 67);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-69.5, 5.0, 67);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glEnable(GL_LIGHTING);


	glPopMatrix();

}

void rusa() {
	glPushMatrix();
		glPushMatrix();
		glScalef(1, 3, 1);
			glTranslatef(0,0.5,30);
			fig2.prisma(0.5,100,0.5,rusas.GLindex);//RIEL DELANTERO 1
			glPushMatrix();
			glColor3f(1,1,1);
			glPushMatrix();
			glTranslatef(7, 1.575, 0);
			fig2.prisma(0.65, 10, 0.5, rusas.GLindex);// bajada 2
			glPushMatrix();
			glTranslatef(-56.1, 1.2, 0);
			fig2.prisma(0.64, 2.2, 0.5, rusas.GLindex);// bajada 6
			glPushMatrix(); /// BAJADA 7
			glTranslatef(-6.1, 0, 0);
			fig2.prisma(0.64, 10, 0.5, rusas.GLindex);//  
			glPushMatrix(); /// BAJADA 8
			glTranslatef(-5, 1.125, 11);
			glRotatef(5.74,-1, 0, 0);
			fig2.prisma(0.64, 0.5, 22, rusas.GLindex);// 
			glPopMatrix();
			glPushMatrix(); /// BAJADA 9
			glTranslatef(-5, 2.2, 23.5);
			fig2.prisma(0.69, 0.5, 3.5, rusas.GLindex);// 
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glTranslatef(-17.5, 1.25, 0);
			glRotatef(5.75, 0, 0, -1);
			fig2.prisma(0.65, 25.25, 0.5, rusas.GLindex);// bajada 3
			glTranslatef(-22, -1.9, 0);
			glRotatef(11.5, 0, 0, 1);
			fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 4
			glTranslatef(-12.5, 0.6, 0);
			glRotatef(11.4, 0, 0, -1);
			fig2.prisma(0.65, 6, 0.5, rusas.GLindex);// bajada 5
			
			glPopMatrix();
			glTranslatef(30.75, 11, 0);
			glRotatef(26.5,0,0,1);
			fig2.prisma(0.5, 42.5, 0.5, rusas.GLindex);// bajada 1
			glPopMatrix();
				glPushMatrix();
					glTranslatef(49.9, 10.25, 0);
					fig2.prisma(20, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(19.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(19, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(18.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(18, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(17.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(17, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(16.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(16, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(15.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(15, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(14.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(14, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(13.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(13, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(12.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(12, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(11.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(11, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(10.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(10, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(9.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(8.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(7.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(6.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(5.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(4.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(1.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					////////////////////////
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);

					///AQUI INICIA CURVA EXTERIOR

					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05,1);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(4.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(4.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(4.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(4.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(4.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.0, 1);
					fig2.prisma(4.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.0, 1);
					fig2.prisma(4.4, 0.2, 0.5, rusas.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0, 0, 5);
					fig2.prisma(0.5, 100, 0.5, rusas.GLindex); //RIEL DELANTERO 2
					glPushMatrix();
					glColor3f(1, 1, 1);
					glPushMatrix();
					glTranslatef(7, 1.575, 0);
					fig2.prisma(0.65, 10, 0.5, rusas.GLindex);// bajada 2
					glPushMatrix();
					glTranslatef(-56.1, 1.2, 0);
					fig2.prisma(0.64, 2.2, 0.5, rusas.GLindex);// bajada 6
					glPushMatrix(); /// BAJADA 7
					glTranslatef(-1, 0.575, 5.5);
					glRotatef(5.74, -1, 0, 0);
					fig2.prisma(0.64, 0.5, 11.5, rusas.GLindex);// 
					glPopMatrix();
					glPushMatrix(); /// BAJADA 9
					glTranslatef(-1, 1.175, 13.2);
					fig2.prisma(0.58, 0.5, 4.1, rusas.GLindex);// 
					glPopMatrix();
					glPopMatrix();
					glTranslatef(-17.5, 1.25, 0);
					glRotatef(5.75, 0, 0, -1);
					fig2.prisma(0.65, 25.25, 0.5, rusas.GLindex);// bajada 3
					glTranslatef(-22, -1.9, 0);
					glRotatef(11.5, 0, 0, 1);
					fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 4
					glTranslatef(-12.5, 0.6, 0);
					glRotatef(11.4, 0, 0, -1);
					fig2.prisma(0.65, 6, 0.5, rusas.GLindex);// bajada 5
					glTranslatef(4, 1, 15);
					glRotatef(0.1, 0, 0, -1);
					fig2.prisma(0.65, 18, 0.5, rusas.GLindex);// bajada 10
						glPushMatrix();
						glTranslatef(-5.125, -0.01, 5);
						glRotatef(0.05, 0, 0, 1);
						fig2.prisma(0.65, 28.25, 0.5, rusas.GLindex);// bajada 10 b
						glPopMatrix();
					glTranslatef(37.25, 3.8, 0);
					glRotatef(00, 0, 0, -1);
					fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 12
						glPushMatrix();
						glTranslatef(0, 0, 5);
						glRotatef(00, 0, 0, -1);
						fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 12
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-19,-1.9, 0);
						glRotatef(11.4, 0, 0, 1);
						fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 12
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-19, -1.9, 5);
						glRotatef(11.4, 0, 0, 1);
						fig2.prisma(0.65, 19.25, 0.5, rusas.GLindex);// bajada 12
						glPopMatrix();
					glTranslatef(43.25, 4.8, 0);
					glRotatef(00, 0, 0, -1);
					fig2.prisma(0.65, 20.25, 0.5, rusas.GLindex);// bajada 14
						glPushMatrix();
						glTranslatef(0, 0, 5);
						glRotatef(00, 0, 0, -1);
						fig2.prisma(0.65, 20.25, 0.5, rusas.GLindex);// bajada 14
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-21.9,-2.4, 0);
						glRotatef(11.45, 0, 0, 1);
						fig2.prisma(0.65, 24.125, 0.5, rusas.GLindex);// bajada 14
						glPopMatrix();
						glPushMatrix();
						glTranslatef(-21.9, -2.4, 5);
						glRotatef(11.45, 0, 0, 1);
						fig2.prisma(0.65, 24.125, 0.5, rusas.GLindex);// bajada 14
						glPopMatrix();
					glPopMatrix();
					glTranslatef(30.75, 11, 0);
					glRotatef(26.5, 0, 0, 1);
					fig2.prisma(0.5, 42.5, 0.5, rusas.GLindex);// bajada 1
					glPopMatrix();
					glPushMatrix();
					glTranslatef(49.9, 10.25, 0);
					fig2.prisma(20, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(19.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(19, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(18.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(18, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(17.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(17, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(16.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(16, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(15.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(15, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(14.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(14, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(13.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(13, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(12.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(12, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(11.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(11, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(10.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(10, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(9.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(8.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(7.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(6.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(5.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(4.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(1.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.25, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0, 0);
					fig2.prisma(1, 0.2, 0.5, rusas.GLindex);
					////////////////////////
					////////////////////////
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.0, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);

					///////////// AQUI ENTRA LA CURVA

					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0.05, 1);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0, 1);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0, 1);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(0, 0, 1);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);

					glPopMatrix();
				glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glScalef(1, 3, 1);
			glTranslatef(0, 0.5, 50);
			fig2.prisma(0.5, 100, 0.5, rusas.GLindex);//RIEL TRASERO 1
				glPushMatrix();
					glTranslatef(49.9, 1.25, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(4.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, -0.05, 0);
					fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
					glTranslatef(-1, 0.05, 0);
					fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
					
					
				glPopMatrix();

			glPushMatrix();
				glTranslatef(0, 0, 5);
				fig2.prisma(0.5, 100, 0.5, rusas.GLindex); //RIEL TRASERO 2
				glPushMatrix();
				glTranslatef(49.9, 1.25, 0);
				fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(2.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, -0.05, 0);
				fig2.prisma(1.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(1.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(2.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.4, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.5, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.6, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.7, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.8, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(3.9, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.0, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.1, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.2, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.3, 0.2, 0.5, rusas.GLindex);
				glTranslatef(-1, 0.05, 0);
				fig2.prisma(4.4, 0.2, 0.5, rusas.GLindex);
				glPopMatrix();

			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50.25, 0, -7.50);
			fig2.prisma(0.5, 0.5, 15.5, rusas.GLindex);//RIEL vuelta interior 1
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-55, 0, -20);
			fig2.prisma(0.5, 10, 0.5, rusas.GLindex);//RIEL complementario delatero 1
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-55.25, 0, 5);
			fig2.prisma(0.5, 10.5, 0.5, rusas.GLindex);//RIEL complementario trasero 1
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-60.25, 0, -7.750);
			fig2.prisma(0.5, 0.5, 25, rusas.GLindex);//RIEL vuelta exterior 1
			glPopMatrix();

			glPopMatrix();

	glPopMatrix();

}





void puestos() {
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	//glColor3f(1,1,1);
	glTranslatef(-50,8,0);
	fig1.prisma(2,15,4, puesto.GLindex);
	glPushMatrix();
	//glColor3f(1, 1, 1);
	glTranslatef(7.5, -3, 1.5);
	glRotatef(90,0,0,1);
	fig1.prisma(0.2, 3.95, 0.5, palos.GLindex);
	glTranslatef(0, 0, -3);
	fig1.prisma(0.2, 3.95, 0.5, palos.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.5, -3, 1.5);
	glRotatef(90, 0, 0, 1);
	fig1.prisma(0.2, 3.95, 0.5, palos.GLindex);
	glTranslatef(0, 0, -3);
	fig1.prisma(0.2, 3.95, 0.5, palos.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -6, 0);
	fig1.prisma(2, 15, 4, puesto2.GLindex);
	glPopMatrix();



	//glEnable(GL_LIGHTING);
	//glColor3f(1,1,1);
	glPopMatrix();



}
void carrusel() {
	int j;
	
	glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(0, 0, 80);
	glScalef(3, 4, 3);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-15, 4.5, -40);
	glRotatef(vcs, 0, 1, 0);
	fig1.esfera(0.5, rebanadas, sas,0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, -0.7);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	fig1.cono(0.8, 3.0, 100, carpa.GLindex);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	fig1.cono(0, 3.0, 100, carpa.GLindex);
	glPopMatrix();
	glRotatef(180, 0, 1, 0);



	for (i = 0, c = 0, x = 0, j = -1; i < 10; i++, j += -0.1)
		{
		glPushMatrix();
		glRotatef(-90, 1, 0, 0);
		glRotatef(36 * i, 0, 1, 0);
		glRotatef(vcs, 0, 1, 0);
		glTranslatef(0, 0, 3.0);
		if (x == 0) { glColor3d(1, 1, 1); x = 1; }
		else if (x == 1) { glColor3d(1, 1, 1); x = 0; }

		fig1.esfera(0.1, rebanadas, sas,0);
		glRotatef(90, 1, 0, 0);
		glutWireCone(0, 3, 2, 1);
		glTranslatef(0, 0, 3);
		fig1.esfera(0.1, rebanadas, sas,0);


		glPushMatrix();		
		glTranslatef(-0.5, 0.3, -1);
		glTranslatef(0, 0, sin(vcs*(j*0.1)) / 3);
		glRotatef(90,-1,0,0);
		glScalef(2, 2, 2);
		glDisable(GL_COLOR_MATERIAL);
		arbusto.GLrender(NULL, _SHADED, 1.0);
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();
		glPopMatrix();
		
	}
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, 3);
	glRotatef(-180, 0, 1, 0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	fig1.cono(0.1, 3.0, 100, carpa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	glRotatef(90, 1, 0, 0);
	fig1.cono(4.3, 0.9, 20, puesto2.GLindex);
	glPopMatrix();


	glPopMatrix();
	glColor3f(1, 1, 1);

	glPopMatrix();

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				//glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				//glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();

			glTranslatef(-30, 1.5, -15);
			glDisable(GL_COLOR_MATERIAL);
			glScalef(0.05, 0.05, 0.05);
			glRotatef(90, 0, -1, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);


			glEnable(GL_COLOR_MATERIAL);

			glPopMatrix();

			glPushMatrix();
			
			glTranslatef(60,45,32.5);
			glRotatef(55,0,0,1);
			glScalef(2,2,2);
			canastilla();
			glPopMatrix();


			glPushMatrix();

			glTranslatef(-10, 1.5, -15);
			glDisable(GL_COLOR_MATERIAL);
			glScalef(0.05, 0.05, 0.05);
			glRotatef(90, 0, -1, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-80, 0, 0);
			banca.GLrender(NULL, _SHADED, 1.0);


			glEnable(GL_COLOR_MATERIAL);

			glPopMatrix();



			glPushMatrix();
			glDisable(GL_COLOR_MATERIAL);
			glTranslatef(60, -1, -15);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,-1,0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(30, 0, 0);
			baño.GLrender(NULL, _SHADED, 1.0);
			glEnable(GL_COLOR_MATERIAL);
			glPopMatrix();

			glPushMatrix();

			glTranslatef(0,-1,0);
			carrusel();
			glPopMatrix();



			glPushMatrix();
			glTranslatef(-45, -1, -10);
			arbol_alpha();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-17.5, -1, -25);
			arbol_alpha();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(25, -1, -10);
			arbol_alpha();
			glTranslatef(20, 0, 0);
			arbol_alpha();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(25, -1, 10);
			arbol_alpha();
			glTranslatef(20, 0, 0);
			arbol_alpha();
			glPopMatrix();


			fortuna();
			glPushMatrix();
			glTranslatef(0, -1, 0);
			puestos();
			glTranslatef(20, 0,0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glPopMatrix();
			glPushMatrix();
			puestos();
			glTranslatef(0, -1, 20);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glTranslatef(20, 0, 0);
			puestos();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, -1, 0);
			rusa();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(0, -1, 0);
			cerca();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0,0,0);
			//glDisable(GL_LIGHTING);
			glDisable(GL_COLOR_MATERIAL);
			glTranslatef(-55, 0, 3.5);
			glScalef(0.1, 0.1, 0.1);
			glRotatef(90, 0, 1, 0);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			
			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);

			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0,40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			
			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			
			glEnable(GL_COLOR_MATERIAL);

			glPopMatrix();

			

			
			glPushMatrix();
			glColor3f(0, 0, 0);
			//glDisable(GL_LIGHTING);

			glDisable(GL_COLOR_MATERIAL);
			glRotatef(270, 0, 1, 0);
			glTranslatef(16.5, 0, -16.5);
			glScalef(0.1, 0.1, 0.1);
			
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);

			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);

			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);

			glTranslatef(-0, 0, 80);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);
			glTranslatef(-0, 0, 40);
			nigga.GLrender(NULL, _SHADED, 1.0);


			glColor3f(1,1,1);
			glEnable(GL_COLOR_MATERIAL);

			glPopMatrix();

			

			glPushMatrix();
				//Para que el coche conserve sus colores
				glDisable(GL_COLOR_MATERIAL);
				glRotatef(90, 0, 1, 0);
				glScalef(0.3, 0.3, 0.3);
				glTranslatef(0, 4, movKit);
				//Pongo aquí la carroceria del carro
				//kit.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS
				//TRASERA IZQUIERDA
				
				glPushMatrix(); 
				glTranslatef(6.5,-1,-9.5);
				glRotatef(180, 0, 1, 0);
				glRotatef(movKit * 50, -1, 0, 0);

				//llanta.GLrender(NULL,_SHADED,1.0);
				glPopMatrix();
				//TRASERA DERECHA
				glPushMatrix();
				glTranslatef(-6.5, -1, -9.5);
				glRotatef(movKit * 50, 1, 0, 0);
				//llanta.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				/////////////////////////////////////////// DELANTERAS

				// IZQUIERDA

				glPushMatrix();
				glTranslatef(6.5, -1, 7.5);
				glRotatef(180, 0, 1, 0);
				glRotatef(movKit * 50, -1, 0, 0);

				//llanta.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();
				// DERECHA
				glPushMatrix();
				glTranslatef(-6.5, -1, 7.5);
				glRotatef(movKit*50, 1, 0, 0);
				//llanta.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();


			glPopMatrix();

			//Para que el comando glColor funcione con iluminacion
			glEnable(GL_COLOR_MATERIAL);
			
			glPushMatrix(); //Flecha
				glScalef(7,0.1,7);
				glDisable(GL_LIGHTING);
				//fig3.prisma_anun(text3.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Camino1
				glTranslatef(23.5,0.0,0.0);
				glScalef(40,0.1,7);
				glDisable(GL_LIGHTING);
				//fig3.prisma2(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Camino2
				glTranslatef(-23.5,0.0,0.0);
				glScalef(40,0.1,7);
				//glDisable(GL_LIGHTING);
				//fig3.prisma2(text4.GLindex, 0);
				//glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,-4.0);
				glScalef(87,0.1,100);
				//glDisable(GL_LIGHTING);
				//fig4.prisma2(text5.GLindex, 0);
				//glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,0.0);
				glScalef(130,0.1,130);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, torDiffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, torDiffuse);				
				fig4.prisma2(text5.GLindex, 0);
				//glEnable(GL_LIGHT_MODEL_LOCAL_VIEWER);
			glPopMatrix();

			glPushMatrix(); //Casa01
				glTranslatef(0.0,3.0,7.0);
				glRotatef(90,1,0,0);
				glRotatef(180,0,0,1);
				glScalef(6,5.0,6);
				//glDisable(GL_LIGHTING);
				//fig5.prisma2(text6.GLindex, 0);
				//glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Casa01
				glTranslatef(0.0,3.0,-7.0);
				glRotatef(90,1,0,0);
				glScalef(6,5.0,6);
				glDisable(GL_LIGHTING);
				//fig5.prisma2(text6.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glColor3f(1.0,1.0,1.0);

		glPopMatrix();
	glPopMatrix();

	

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	if (circuito) //comienza maquina de estados
	{
		if (recorrido1)//comienza estado A
		{
			movKitX--;
			movKitY+=0.01;
			
			if (movKitX < -30 && movKitY>0.30 )
			{
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2)// estado B
		{
			rotKit = -55;
			movKitX-=0.1;
			movKitY -=0.01;
			if (movKitX<-3 && movKitY < -0.5)
			{
				recorrido2 = false;
				//recorrido2 = true;

			}
		}
		if (recorrido3)//comienza estado C
		{
			//rotKit = 90;
			movKitX--;
			movKitZ--;
			if (movKitZ < 0)//transicion a D
			{
				//recorrido3 = false;
				recorrido4 = true;
			}
		}
		if (recorrido4)//estado D
		{
			//rotKit = 210;
			movKitX--;
			movKitZ -= 2.5;
			if (movKitZ < -155 && movKitX < 0)//transicion a E

			{
				//recorrido4 = false;
				recorrido5 = true;
			}
		}
		if (recorrido5)//estado E
		{
			//rotKit = 0;
			movKitZ++;
			if (movKitZ > 0)//transición a E1
			{
				recorrido5 = false;
				recorrido1 = true;
			}
		}
	}

	
	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;
		case 'q':   //Movimientos de camara
		case 'Q':
			objCamera.UpDown_Camera(-CAMERASPEED);
			break;

		case 'z':   //Movimientos de camara
		case 'Z':
			glDisable(GL_LIGHT0);
			break;

		case 'x':   //Movimientos de camara
		case 'X':
			glEnable(GL_LIGHT0);
			break;


		case 'c':   //Movimientos de camara
		case 'C':
			glDisable(GL_LIGHT1);
			break;

		case 'v':   //Movimientos de camara
		case 'V':
			glEnable(GL_LIGHT1);
			break;
		case 'i':		//  
		case 'I':
			circuito ^= true; //Activamos/desactivamos la animacíon
			g_fanimacion = false;
			break;

		case 't':   //Movimientos de camara
			vcs += 2;
			break;
		case 'T':
			vcs -= 2;
			break;
		case 'e':
		case 'E':
			objCamera.UpDown_Camera(CAMERASPEED);
			break;


		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':
			rol +=2.5f;
			break;
		case 'R':
			rol -= 2.5f;
			break;

		case ' ':		//Poner algo en movimiento
			g_fanimacion^= true;//Activamos/desactivamos la animacíon
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final FERIA"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
