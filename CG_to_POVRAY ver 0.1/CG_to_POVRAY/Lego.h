#pragma once

#include <vector>
using namespace std;

class Lego{
public:
	static const  float re;
	static const float he;
    int x,z,y,h,wx,wz,thetha,index;
	void init(int xx,int yy,int zz,int hh,int wwx,int wwz,int tht,int idx);
	Lego(int x,int y,int z,int h,int wx,int wz,int idx);
	int traverse(int (*func)(int,int,int),int begin);
	void drawLego(void (*drawALego)(int i));
	
};

class World{
public:
	static const int worldX=80,worldZ=80;
	static  int** height;
	static vector<int>** board;
	static vector<Lego*> allLego;
	static void initialWorld();
	static int max(int x,int z,int h);
	static int addVal(int x,int z,int h);
	static int removeVal(int x,int z,int h);
	static int addLego(Lego* a);
	static int find(Lego* a);// up =0;down=1;left=2;righ=3;
	static Lego* undo();
	
};
