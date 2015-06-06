#pragma once

#include <iostream>
#include <stdlib.h>
#include "vector2.h"
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif



//bool drawing=false;
using namespace std;




typedef class splane *plane;
//วาดตัวคว่าหันออก โดยจุดที่ต่อกับคอ คือ 0,0

float*  cross(float *a,float *b){
	float *v=new float[3];
	v[0]= a[1] * b[2] - a[2] * b[1];
     v[1]=a[2] * b[0] - a[0] * b[2];
	v[2]=a[0] * b[1] - a[1] * b[0] ;
	return v;
}
float dot(float *a,float *b){
	return a[0] * b[0] + a[1] * b[1]+a[2]*b[2];
}

float dot(float x,float y,float z,float a,float b,float c){
	return a*x + y*b + z*c;
}
float r(float x,float y,float z){
	return sqrtf(x*x+y*y+z*z);
}
float th(float x,float y,float z){
	return acosf(y/r(x,y,z));
}
float phi(float x,float y,float z){
	return  atan2f(x,z);
}
void rotate(float xin,float yin,float *xout,float *yout,float radians){
	float c=cosf(radians),s=sinf(radians);
	*xout=xin*c-yin*s;
	*yout=xin*s+yin*c;

}

void rotateAT(float xin,float yin,float zin,float *xout,float *yout,float *zout,float thrad,float alrad){
	float zt;
	rotate(yin,zin,yout,&zt,thrad);
	rotate(xin,zt,xout,zout,alrad);
}
float* rotateAround(float *a,float* b,float ph){
	float c=cosf(ph),s=sinf(ph);
	float *x=cross(a,b);//float d=dot(a,b);
	float *v=new float[3];
	v[0]=a[0]*c+ x[0]*s;//+ b[i]*d*(1-c)
	v[1]=a[1]*c+ x[1]*s;
	v[2]=a[2]*c+ x[2]*s;
	
	delete[] x;
	return v;
};


	void splane::move(float v){
		updateV();
		cx+=h[0]*v;
		cy+=h[1]*v;
		cz+=h[2]*v;
	}
	void splane::doth2(){
		float ct=cosf(thetha),st=sinf(thetha),
			ca=cosf(alpha),sa=sinf(alpha)
			,yt=-st,zt=ct;

	
	float xt=zt*sa;
	zt=zt*cos(alpha);
	float d=dot(xt,yt,zt,t[0],t[1],t[2]);
	d=d>1?0.9999:d<-1?-0.9999:d;
	float diff=acosf(d);
    
	

	xt=sinf(-diff);
	zt=cosf(-diff);

	yt=-zt*st;
	zt=zt*ct;
	float xt2=zt*sa+xt*ca;
	float zt2=zt*ca-xt*sa;

	float dfx=xt2-t[0],dfy=yt-t[1],dfz=zt2-t[2];
	dfx=dfx<0?-dfx:dfx;
	dfy=dfy<0?-dfy:dfy;
	dfz=dfz<0?-dfz:dfz;

		if(  dfx<0.1 && dfy<0.1 && dfz<0.1){
		tht=-diff;
		}else tht=diff;
		
	//tht=-diff;
	};
	void splane::doth(){
		float yt,zt,xt;
		rotateAT(0,0,1,&xt,&yt,&zt,thetha,alpha);
		
		float dif=acosf(dot(xt,yt,zt,t[0],t[1],t[2]));
		rotate(1,0,&zt,&xt,dif);
		float xt2,yt2,zt2;
		rotateAT(xt,0,zt,&xt2,&yt2,&zt2,thetha,alpha);
	
		if(  (xt2-t[0]<0.2 || t[0]-xt2<0.2) &&(yt2-t[1]<0.2||t[1]-yt2<0.2) && (zt2-t[2]<0.2 || t[2]-zt2<0.2)){
		tht=dif;
		}else tht=dif;
	}
	void splane::updateV(){
		//doth2();

		thetha=th(h[0],h[1],h[2]);
		alpha =phi(h[0],h[1],h[2]);
		
		

		
	};


	splane::splane(){
	};
	void splane::setht(float* hh,float* tt){
		for(int i=0;i<3;i++){h[i]=hh[i];t[i]=tt[i];}

	}
	splane::splane(float *hh,float *tt){
		
		spindown=spinup=false;
		cx=0;cy=0;cz=0;
	
		tl=tr=up=down=false;
		
		h=new float[3];
		t=new float[3];
		setht(hh,tt);
		
		updateV();
	};
	splane::splane(float xx,float yy,float zz){
		
		spindown=spinup=false;
		cx=xx;cy=yy;cz=zz;
	
		tl=tr=up=down=false;
		
		h=new float[3];
		t=new float[3];
		h[0]=0;h[1]=0;h[2]=-1;
		t[0]=0;t[1]=1;t[2]=0;
	
		updateV();
	};
	splane::~splane(){
		
		delete[]h;
		delete[]t;
	};






void turnLeft(plane plane,float rads){
		    float *g=plane->h;
			plane->h=rotateAround(plane->h,plane->t,rads);
			delete []g;

}
void spin(plane plane,float rads){
	    float *tt=plane->t;
			plane->t=rotateAround(plane->t,plane->h,rads);
			delete[] tt;

}
void rotateWheel(plane plane,float rads){
		float *x=cross(plane->h,plane->t);
			float *g=plane->h;
			float *tt=rotateAround(plane->t,x,rads);
			plane->h=rotateAround(plane->h,x,rads);
			float* temp=plane->t;
			plane->t=tt;
			delete temp;
			delete []g;
			delete []x;

}

void planDo(plane plane){
	
	if(plane->spinup){
	   spin(plane,0.05);
	}
	else if(plane->spindown){
		spin(plane,-0.05);
	}
	 if(plane->tr){
		 turnLeft(plane,-0.02);
	}
	else if(plane->tl){
			turnLeft(plane,0.02);
	}
	else if(!plane->tl && !plane->tr)
	{}

	if(plane->up){
		rotateWheel(plane,-0.02);
	}
	else if(plane->down){
	    rotateWheel(plane,0.02);
	}
	else if(!plane->up && !plane->down){  }
	

}

void moveRight(plane plane,float v){
	float* x=cross(plane->h,plane->t);
	plane->cx+=x[0]*v;
	plane->cy+=x[1]*v;
	plane->cz+=x[2]*v;
	delete []x;

}




void setByplane(plane plane) {
	glLoadIdentity();
	plane->updateV();plane->doth2();
	float td=plane->thetha*toDg,ad=plane->alpha*toDg;
	glRotatef(-90,1,0,0);
	glRotatef(-plane->tht*toDg, 0.0f, 1.0f, 0.0f);
	glRotatef(-td,1,0,0);
	glRotatef(-ad, 0.0f, 1.0f, 0.0f);
	glTranslatef(-plane->cx,-plane->cy,-plane->cz); 

}














