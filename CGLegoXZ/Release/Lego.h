#pragma once
#include <vector>
#include"GLM.h"
#include"vector2.h"
using namespace std;

struct node
{
	int element;
	node *left;
	node *right;
	int height;
};
typedef struct node *nodeptr;

class bstree
{  
	public:
		int size;
		nodeptr root;
		bstree(){
		size=0;
		root=0;
		}
		void insert(int,nodeptr &);
		void del(int, nodeptr &);
		int deletemin(nodeptr &);
		void find(int,nodeptr &,int &min,int &max);
		nodeptr findmin(nodeptr);
		nodeptr findmax(nodeptr);
		void makeempty(nodeptr &);
		void copy(nodeptr &,nodeptr &);
		nodeptr nodecopy(nodeptr &);
		void preorder(nodeptr);
		void inorder(nodeptr);
		void postorder(nodeptr);
		int bsheight(nodeptr);
		nodeptr srl(nodeptr &);
		nodeptr drl(nodeptr &);
		nodeptr srr(nodeptr &);
		nodeptr drr(nodeptr &);
		int max(int,int);
		int nonodes(nodeptr);
};
node* newnode(int x);


class World;
class Lego{
public:
	
	float R,G,B;
	int mood;
	static Lego* dm;
	static const  float re;
	static const float he;
    int x,z,y,h,wx,wz,thetha,index;
	void init(int xx,int yy,int zz,int tht,int idx,float rr,float gg,float bb);
	Lego(int x,int y,int z,int idx,float rr,float gg,float bb);
	Lego(int idx,float rr,float gg,float bb);
	int traverse(int choose,int begin,World* w);
	
	void drawLego();
	static Lego* createARandomLego();
	void setw();

};

class World{
public:
	static bool isbp;
	static splane* bp;
	static _GLMmodel** LegoObj;
	static const int worldX=32,worldZ=33;
	
	bstree  ***board;
	
	
	vector<Lego*> allLego;
	World();
	~World();
	void initialWorld();
	 int max(int x,int z,int h);
	 int addVal(int x,int z,int h);
	 int canADD(int x,int z,int h,bool &pass);
	 int removeVal(int x,int z,int h);
	 int addLego(Lego* a);
	 int find(Lego* a);// up =0;down=1;left=2;righ=3;
	
	 void drawAllLego();
	 Lego* undo();
	 void move(int xx,int zz);
	 void rotate(int i);
	 void drawField();
	 void LegoDown();
	 void LegoUp();
	void safe(char* s);
	static World* load(char* s,World *w);
};
void drawStaticLego(Lego* c);
