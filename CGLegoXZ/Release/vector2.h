#pragma once

#include <iostream>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif

#define PI 3.14159265359
#define toRa 0.01745329251
#define toDg 57.2957795131



//bool drawing=false;
using namespace std;




typedef class splane *plane;
//วาดตัวคว่าหันออก โดยจุดที่ต่อกับคอ คือ 0,0

float*  cross(float *a,float *b);
float dot(float *a,float *b);
float dot(float x,float y,float z,float a,float b,float c);
float r(float x,float y,float z);
float th(float x,float y,float z);
float phi(float x,float y,float z);
void rotate(float xin,float yin,float *xout,float *yout,float radians);
void rotateAT(float xin,float yin,float zin,float *xout,float *yout,float *zout,float thrad,float alrad);
float* rotateAround(float *a,float* b,float ph);

class splane{
public:
	bool tr,tl,up,down,shooting,spinup,spindown;
	float cx,cy,cz;
	float *h,*t;
	float thetha,alpha,tht;
	void move(float v);
	void doth2();
	void doth();
	void updateV();
	

	splane();
	void setht(float* hh,float* tt);
	splane(float *hh,float *tt);
	splane(float xx,float yy,float zz);
	~splane();


};



void turnLeft(plane plane,float rads);
void spin(plane plane,float rads);
void rotateWheel(plane plane,float rads);

void planDo(plane plane);





void moveRight(plane plane,float v);
void setByplane(plane plane);














