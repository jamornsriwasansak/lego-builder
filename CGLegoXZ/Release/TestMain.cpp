#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "GL/glut.h"
#include "GLFuncs.h"
#include "GUIGl.h"
#include "Constant.h"
#include "Lego.h"
#include "Camera.h"
#include "glm.h"
#include "Manual.h"
#include "vector2.h"
//external library

using namespace std;
using namespace guigl;
using namespace listenerWrap;

float x=0, y=0, z=0, graus=0;
float *currentR, *currentG, *currentB;

float *specialR, *specialG, *specialB;

int fps=0, displayList=0;
int *currentModel;
int mouseX, mouseY;

bool clicking[3] = {RELEASED, RELEASED, RELEASED};
bool hudOn = true;

Lego * lego;
GLfloat lightPos[4] = {50.0, 30.0 ,0.0, 0.0};
GLfloat lightAmb[3] = {.2, .2, .2};
GLfloat lightDiff[3] = {1.0, 1.0, 1.0};
glButton *colorButton;
colorListener *colorButtonListener;
glGuiDrawer guiDrawer;
Camera *cam;
Camera *hudCam;

World* world;
PovExp* povExp;
bool sh=false;
bool doing=false;

void drawScene() {
	cam->update();
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/***********/
	/*DRAW LEGO*/
	/***********/
	glClear(GL_DEPTH_BUFFER_BIT);
		if(!World::isbp){gluLookAt(cam->getEyeX(), cam->getEyeY(), cam->getEyeZ(),
			cam->getCenterX(), cam->getCenterY(), cam->getCenterZ(),
			0, 1, 0);
	}else {setByplane(World::bp);}
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
		glTranslatef(x,y,z);
		glRotatef(graus, 1.0, 0.0, 0.0);
		
		world->drawAllLego();
		world->drawField();
		if(World::isbp){gluLookAt(cam->getEyeX(), cam->getEyeY(), cam->getEyeZ(),
			cam->getCenterX(), cam->getCenterY(), cam->getCenterZ(),
			0, 1, 0);}
		glCallList(displayList);
	
	if(hudOn) {
		/**********/
		/*DRAW GUI*/
		/**********/
		guiBegin(SCREEN_WIDTH, SCREEN_HEIGHT);
			guiDrawString(MODEL_START_X, MODEL_START_Y - 10, 0.7, 0.7, 0.7, GLUT_BITMAP_HELVETICA_12, "Choose your model");
			guiDrawString(COLOR_START_X, COLOR_START_Y - 10, 0.7, 0.7, 0.7, GLUT_BITMAP_HELVETICA_12, "Choose your color");
			guiDrawer.draw();	
			guiDrawString(SCREEN_WIDTH - 120, SCREEN_HEIGHT - 42, 0, 0, 0, GLUT_BITMAP_HELVETICA_12, "RENDER!!");
		guiEnd();

		/************/
		/*DRAW MODEL*/
		/************/
		glClear(GL_DEPTH_BUFFER_BIT);
		gluLookAt(hudCam->getEyeX(), hudCam->getEyeY(), hudCam->getEyeZ(),
			hudCam->getCenterX(), hudCam->getCenterY(), hudCam->getCenterZ(),
			0, 1, 0);
		for(int i = 0;i < MODEL_AMOUNT;i++) {
			lego->index = i;
			lego->x = button3dPosition[i][0] + hud3dPosition[0];
			lego->y = button3dPosition[i][1] + hud3dPosition[1];
			lego->z = button3dPosition[i][2] + hud3dPosition[2];
			lego->drawLego();
		}
	}
	glutSwapBuffers();
}

Lego* createRandomLego() {
	Lego* lego = Lego::createARandomLego();
	lego->R = *currentR;
	lego->G = *currentG;
	lego->B = *currentB;
	return lego;
}

bool bp2=false,bpx=false,bpw=false,bps=false,bpa=false,bpd=false,bpq=false,bpe=false;float ds=0,dw=0,dt=0,dm=0;
void keyup(unsigned char key, int x, int y){
	switch (key)
	{case' ':sh=false;break;
		case'q':bpq=false;ds=0; break;
		case'e':bpe=false;ds=0; break;
		case '2': bp2=false; dw=0; break;
		case 'x': bpx=false; dw=0; break;
		case 'd': bpd=false; dt=0;  break;
		case 'a': bpa=false; dt=0; break;
		case 'w': bpw=false; dm=0; break;
		case 's': bps=false; dm=0; break;
	default:break;
	}
}

void doBp(){
	if(bpd)moveRight(World::bp,.1+(dt<.2?dt+=.02:.2));
	if(bpa)moveRight(World::bp,-.1-(dt<.2?dt+=.02:.2));
	if(bpw)World::bp->move(.1+(dm<.2?dm+=.02:.2));
	if(bps)World::bp->move(-.1-(dm<.2?dm+=.02:.2));
}

void toggleHud() {
	if(hudOn) 
		hudOn = false;
	else
		hudOn = true;
}

void handleKeypress(unsigned char key, int x, int y) {
	//glutPostRedisplay();
	
	int state = glutGetModifiers();
	cout << "STATE : " << state << endl;
	switch (state) {
	case GLUT_ACTIVE_ALT : break;
	case GLUT_ACTIVE_CTRL : world->LegoDown(); break;
	case GLUT_ACTIVE_SHIFT : world->LegoUp(); break;
	default:
		break;
	}

	cout << "JUST PRESS " << key << endl;
	switch(key) {
		case 27: exit(0); break;
		case'q':bpq=true; break;
		case'e':bpe=true; break;
		case '0':World::isbp=!World::isbp; cout<<"!!!!!! World::bp "<<World::isbp<<" !!!!\n\n";break;
		case 'w': bpw=true; if(!World::isbp)cam->moveUp(); break;
		case 'h': toggleHud(); break;
		case 's': bps=true; if(!World::isbp)cam->moveDown(); break;
		case 'd': bpd=true; if(!World::isbp)cam->moveRight(); break;
		case 'a': bpa=true; if(!World::isbp)cam->moveLeft(); break;
		case '2': bp2=true; if(!World::isbp)cam->zoomIn(); break;
		case 'x': bpx=true; if(!World::isbp)cam->zoomOut(); break;
		case 'P': CaptureScreen("captured.bmp", SCREEN_WIDTH, SCREEN_HEIGHT);break;
		case',':world->LegoDown();printf("\ndown\n\n\n");break;
		case'.':world->LegoUp();printf("\nup\n\n\n");break;
	   case ' ':sh=true;break;
		case 127: if(Lego::dm){Lego* a=world->undo();delete a;}break;
		case 13:	world->addLego( new Lego((*currentModel)%14,*currentR ,*currentG, *currentB )); break;
			break;
		
	}
	if(World::isbp)doBp();
	cout << "CAM X : " << cam->x << ", CAM Y : " << cam->y << "CAM Z : " << cam->z << endl;
	cout << "THETA : " << cam->theta << ", PHI : " << cam->phi << endl;
}
int thesholdss=30;
bool meet=false;bool uuu=false,ddd=false,lll=false,rrr=false;
void handleMouseMotion(int x, int y) {
	colorButton->r = *specialR;
	colorButton->g = *specialG;
	colorButton->b = *specialB;
	colorButtonListener->r = *specialR;
	colorButtonListener->g = *specialG;
	colorButtonListener->b = *specialB;

	if(!meet){
		meet=true;
		mouseX = x;
		mouseY = y;
		return;
	}
	if(World::isbp  ){
		
		GLint m_viewport[4];
        glGetIntegerv( GL_VIEWPORT, m_viewport );
		
		if(m_viewport[2]-x<thesholdss || x<thesholdss){
		if(m_viewport[2]-x<thesholdss)lll=true;
				else if(x<thesholdss)rrr=true;
				
		
		}else {lll=false;rrr=false; }
			
		if( m_viewport[3]-y<thesholdss ||y<thesholdss){
				
				if(m_viewport[3]-y<thesholdss)uuu=true;
				else if(y<thesholdss )ddd=true;
				
		
		}else {uuu=false;ddd=false;}
		if( m_viewport[3]-y<thesholdss ||y<thesholdss ||m_viewport[2]-x<thesholdss || x<thesholdss){	
		mouseX = x;
			mouseY = y;
			return;
		}
	}else { uuu=false;ddd=false;lll=false;rrr=false;  }
	if(clicking[CLICK_LEFT] == CLICKED) {
		cout << "LEFT MOUSE CLICKING!";
		guiDrawer.onClick(1, 1, x, y);
	}
	if(clicking[CLICK_RIGHT] == CLICKED) {
		cout << "RIGHT MOUSE CLICKING!";
		cout << "X : " << x << ", Y : " << y << endl;
		if(x > mouseX)
			if(!World::isbp)cam->rotateCCW();else turnLeft(World::bp,.002*(x-mouseX));
		if(x < mouseX)
			if(!World::isbp)cam->rotateCW();else turnLeft(World::bp,-.002*(mouseX-x));
		if(y > mouseY)
			if(!World::isbp)cam->rotateDown();else rotateWheel(World::bp,.002*(y-mouseY));
		if(y < mouseY)
			if(!World::isbp)cam->rotateUp();else rotateWheel(World::bp,-.002*(mouseY-y));
	}
	mouseX = x;
	mouseY = y;
}

void handleMouseMotion2(int x, int y) {
	if(!World::isbp)return;
	if(!meet){
		meet=true;
	mouseX = x;
	mouseY = y;
	return;
	}



	if(World::isbp  ){
		
		GLint m_viewport[4];
        glGetIntegerv( GL_VIEWPORT, m_viewport );
		
		if(m_viewport[2]-x<thesholdss || x<thesholdss){
		if(m_viewport[2]-x<thesholdss)lll=true;
				else if(x<thesholdss)rrr=true;
				
		
		}else {lll=false;rrr=false; }
			
			if( m_viewport[3]-y<thesholdss ||y<thesholdss){
				
				if(m_viewport[3]-y<thesholdss)uuu=true;
				else if(y<thesholdss )ddd=true;
				
		
		}else {uuu=false;ddd=false;}

	}else { uuu=false;ddd=false;lll=false;rrr=false;  }


	
	mouseX = x;
	mouseY = y;
}

void handleMouse(int button, int state, int x, int y) {
	clicking[button] = state;
	if(button == 0)
		guiDrawer.onClick(button, state, x, y);
	colorButton->r = *specialR;
	colorButton->g = *specialG;
	colorButton->b = *specialB;
	colorButtonListener->r = *specialR;
	colorButtonListener->g = *specialG;
	colorButtonListener->b = *specialB;

	cout << "BUTTON :" << button << "STATE :" << state << endl;
	lego->R = *currentR;
	lego->G = *currentG;
	lego->B = *currentB;
	cout << "R : " << *currentR << ", G : " << *currentG << ", B : " << *currentB << endl;
	cout << "Model : " << *currentModel << endl;
}

void initialGUI() {
	/*************/
	/*CURRENT COL*/
	/*************/
	currentR = (float*)malloc(sizeof(float));
	currentG = (float*)malloc(sizeof(float));
	currentB = (float*)malloc(sizeof(float));
	specialR = (float*)malloc(sizeof(float));
	specialG = (float*)malloc(sizeof(float));
	specialB = (float*)malloc(sizeof(float));
	currentModel = (int*)malloc(sizeof(int));

	*currentModel=0;
	*currentR=1;
	*currentB=1;
	*currentG=1;	

	*(specialR) = 0.5;
	*(specialG) = 0.5;
	*(specialB) = 0.5;


	/************/
	/*MODEL SEL */
	/************/
	//guigl::guiDrawString(10, 10, 1, 1, 1, GLUT_BITMAP_HELVETICA_10, "Select your model");
	for(int i = 0;i < MODEL_AMOUNT;i++) {
		glButton* gl = new glButton(MODEL_START_X + (MODEL_BUTTON_WIDTH + BUTTON_GAP) * (i % (MODEL_BUTTON_PER_ROW)), 
			MODEL_START_Y + (MODEL_BUTTON_HEIGHT + BUTTON_GAP) * (i / (MODEL_BUTTON_PER_ROW)), 
			MODEL_BUTTON_WIDTH, MODEL_BUTTON_HEIGHT);
		modelListener *modelFuncWrap = new modelListener(i, currentModel, world);
		gl->setOnClickListener(modelFuncWrap);
		guiDrawer.addComponent(gl);
	}

	/************/
	/*COLOR SEL */
	/************/
	for(int i = 0;i < COLOR_AMOUNT;i++) {
		glButton* gl = new glButton(COLOR_START_X + (COLOR_BUTTON_WIDTH + BUTTON_GAP) * (i % (COLOR_BUTTON_PER_ROW)), 
			COLOR_START_Y + (COLOR_BUTTON_HEIGHT + BUTTON_GAP) * (i / (COLOR_BUTTON_PER_ROW)), 
			COLOR_BUTTON_WIDTH, COLOR_BUTTON_HEIGHT);
		colorListener *colFuncWrap = new colorListener(color_suit[i][0], 
			color_suit[i][1], color_suit[i][2], currentR, currentG, currentB, world);
		gl->setOnClickListener(colFuncWrap);
		gl->r = color_suit[i][0];
		gl->g = color_suit[i][1];
		gl->b = color_suit[i][2];
		guiDrawer.addComponent(gl);
	}

	/***********/
	/* SLIDER  */
	/***********/
	glSlider* gls = new glSlider(COLOR_START_X, COLOR_START_Y + (COLOR_BUTTON_HEIGHT + BUTTON_GAP) * (COLOR_AMOUNT / (COLOR_BUTTON_PER_ROW) + 1), 
		100, 15);
	gls->r = 1; gls->b = 0; gls->g = 0; gls->bPost = 1; gls->rPost = 1; gls->gPost = 1;
	gls->setOnClickListener(new sliderListener(gls, specialR));
	guiDrawer.addComponent(gls);

	gls = new glSlider(COLOR_START_X, COLOR_START_Y + (COLOR_BUTTON_HEIGHT + BUTTON_GAP) * (COLOR_AMOUNT / (COLOR_BUTTON_PER_ROW) + 1) + 20, 
		100, 15);
	gls->r = 0; gls->g = 1; gls->b = 0; gls->bPost = 1; gls->rPost = 1; gls->gPost = 1;
	gls->setOnClickListener(new sliderListener(gls, specialG));
	guiDrawer.addComponent(gls);

	gls = new glSlider(COLOR_START_X, COLOR_START_Y + (COLOR_BUTTON_HEIGHT + BUTTON_GAP) * (COLOR_AMOUNT / (COLOR_BUTTON_PER_ROW) + 1) + 40, 
		100, 15);
	gls->r = 0; gls->g = 0; gls->b = 1; gls->bPost = 1; gls->rPost = 1; gls->gPost = 1;	
	gls->setOnClickListener(new sliderListener(gls, specialB));
	guiDrawer.addComponent(gls);

	colorButton = new glButton(COLOR_START_X + 105, COLOR_START_Y + (COLOR_BUTTON_HEIGHT + BUTTON_GAP) * (COLOR_AMOUNT / (COLOR_BUTTON_PER_ROW) + 1),
		55, 55);
	colorButtonListener = new colorListener(0.5, 0.5 ,0.5, currentR, currentG, currentB, world);
	colorButton->setOnClickListener(colorButtonListener);
	guiDrawer.addComponent(colorButton);
	/*****************/
	/* RENDER BUTTON */
	/*****************/
	
	glButton* gl = new glButton(SCREEN_WIDTH - 120 , SCREEN_HEIGHT - 40, 100, 20);
	renderListener *renderWrap = new renderListener(povExp, world, cam);
	gl->setOnClickListener(renderWrap);
	guiDrawer.addComponent(gl);
}

void funcPress(int key,int x,int y){
	printf("funckey %d",key);
	
	switch (key) {
	case GLUT_ACTIVE_ALT:
		cout << "ALT ACTIVE" << endl;
		break;
	case GLUT_KEY_UP:
		if(doing)return;
		doing=true;
		world->move(1,0); 
		doing=false;
		break;
	case GLUT_KEY_DOWN:
		if(doing)return;
		doing=true;
		world->move(-1,0);
		doing=false;
		break;
	case GLUT_KEY_LEFT:
		if(doing)return;
		doing=true;
		world->move(0,-1);
		doing=false;
		break;
	case GLUT_KEY_RIGHT:
		if(doing)return;
		doing=true;
		world->move(0,1);
		doing=false;
		break;
	case GLUT_KEY_PAGE_UP:
		if(doing)return;
		doing=true;
		world->rotate(1);
		doing=false;
		break;
	case GLUT_KEY_PAGE_DOWN:
		if(doing)return;
		doing=true;
		world->rotate(-1);
		doing=false;
		break;
		break;
	
	default:
		//while(dis);
		//dis=true;
		if(key<=12){
		char a[10];
		char c[4];
		strcpy(a,"");
		strcat(a,itoa(key,c,10));
		strcat(a,".zego");
		printf("%d %b\n",key,sh);
		if(sh){
			world->safe(a);
		
		}else{
		
			world=World::load(a,world);
		}
		//dis=false;
		}
		break;
	}
}

void update(int value) {
	if(World::isbp  ){
		if(lll)turnLeft(World::bp,.003);
		else if(rrr)turnLeft(World::bp,-.003);
		if(uuu)rotateWheel(World::bp,.003);
		else if(ddd)rotateWheel(World::bp,-.003);

	}
	glutPostRedisplay();
	glutTimerFunc(1, update, 0);
}

int main(int argc, char** argv) {
	float h[3]={0,0,-1};
	float t[3]={0,1,0};
	World::bp = new splane(h,t);
	World::isbp = false;
	World::bp->cy=3;
	World::bp->cz=20;

	//rotateWheel(World::bp,0);
	lego = new Lego(0, 1, 1, 1);
	povExp = new PovExp();
	cam = new Camera(15, 45, 255, 0, 0, 0);
	hudCam = new Camera(15, 45, 45, hud3dPosition[0], hud3dPosition[1], hud3dPosition[2]);

	world = new World();

	initialGUI();
	
	world->addLego(new Lego(0,1,1,1));
	
	cout << "Start Init" << endl;

	glutInit(&argc, argv);
	initRendering();
	displayList = glGenLists(1);
	glutSpecialFunc(funcPress);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(keyup);
	glutMouseFunc(handleMouse);
	glutMotionFunc(handleMouseMotion);
	glutIdleFunc(drawScene);
	glutReshapeFunc(handleResize);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glutTimerFunc(1, update, 0);
	*currentB=1;*currentR=1;*currentG=1;
	glutMainLoop();
	return 0;
}