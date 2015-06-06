#include <iostream>
#include <stdlib.h>
#include <algorithm> 
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif
#include "Lego.h"
#include <vector>
using namespace std;
	
const float Lego::re=1;
const float	Lego::he=1/3;
vector<Lego*> World::allLego;

int World::max(int x,int z,int h){
	return std::max(h,height[x][z]);
}
int World::addVal(int x,int z,int h){
	height[x][z]=h;
	board[x][z].push_back(h);
	return 1;
}
int World::removeVal(int x,int z,int h){
	//never use h
	board[x][z].pop_back();
	int t=board[x][z].back();
	height[x][z]=t;
	return 1;
}

int** World::height;
	vector<int>** World::board;
	void World::initialWorld(){
		
		board=new vector<int>*[World::worldX];
		height=new int*[World::worldX];
		for(int i=0;i<World::worldZ;i++)
		{   
        board[i]=new vector<int>[World::worldZ];
		height[i]=new int[World::worldZ];
		for(int j=0;j<World::worldZ;j++){
				height[i][j]=0;
		   }
	
		}
	}
	int World::find(Lego* a)// up =0;down=1;left=2;righ=3;
	{int h=a->traverse(World::max,0);
	return h;
	}
	Lego* World::undo(){
		Lego* c=allLego.back();
		allLego.pop_back();
		c->traverse(removeVal,0);
		return c;
	}
	int World::addLego(Lego* a){
	   int temp=find(a);
	   a->traverse(World::addVal,temp+a->h);
	   allLego.push_back(a);
	return 0;
	}
void Lego::init(int xx,int yy,int zz,int hh,int wwx,int wwz,int tht,int idx){
		x=xx;
		y=yy;
		z=zz;
		h=hh;
		wx=wwx;
		wz=wwz;
		thetha=tht;
		index=idx;
}

Lego::Lego(int x,int y,int z,int h,int wx,int wz,int idx){
		init(x,y,z,h,wx,wz,0,idx);
}

int Lego::traverse(int (*func)(int,int,int),int begin){
	
		if(thetha == 0){
			for(int i=0;i < wx;i++){
				for(int j=0;j < wz;j++){
					int xx=x+i;
					int zz=z+j;
					begin=func(xx,zz,begin);
				}
			}
		} else if(thetha == 270){
			for(int i=0;i < wz;i++){
				for(int j=0;j < wx;j++){
					int xx=x+i;
					int zz=z+j;
					begin=func(xx,zz,begin);
				}
			}
		} else if(thetha == 180){
			for(int i=0;i < wx;i++){
				for(int j=0;j < wz;j++){
					int xx=x-i;
					int zz=z-j;
					begin=func(xx,zz,begin);
				}
			}

		} else if(thetha == 90){
			for(int i=0;i < wz;i++){
				for(int j=0;j < wx;j++){
					int xx=x-i;
					int zz=z-j;
					begin=func(xx,zz,begin);
			}
		}
	}
		return begin;
}

void Lego::drawLego(void (*drawALego)(int i)){
	glPushMatrix();
	glTranslatef(re*x,he*y,re*z);
	glRotatef(thetha,0,1,0);
	glTranslatef(re/2,0,re/2); 
//----
	drawALego(index);
//---
	glPopMatrix();

}
