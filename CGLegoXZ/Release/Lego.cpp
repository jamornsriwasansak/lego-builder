#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm> 
#ifdef __APPLE__setw
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif
#include "Lego.h"
#include"GLM.h"
#include <vector>
#include <string>
using namespace std;
_GLMmodel** World::LegoObj;
Lego* Lego::dm=0;
	bool World::isbp=false;
	splane* World::bp=0;
Lego* Lego::createARandomLego(){

	int xx=World::worldX/2,yy=0,zz=World::worldZ/2,th=0;
	
	if(Lego::dm){
		xx=Lego::dm->x;yy=Lego::dm->y;zz=Lego::dm->z;th=dm->thetha;}
	
	int r = (int)(((double) rand() / (RAND_MAX))*14);
	int rr= (int)((double) rand() / (RAND_MAX)*2),
		gg= (int)((double) rand() / (RAND_MAX)*2),
		bb= (int)((double) rand() / (RAND_MAX)*2);
	if(!rr && !gg &&!bb){
	int j=(int)((double) rand() / (RAND_MAX)*3);
	switch (j)
	{case 1:rr=1;
	case 2:gg=1;
	case 0 :bb=1;
	default:
		break;
	}
	}
    Lego* a=new Lego(r,rr,gg,bb);
	//Lego *a =new Lego(r,1,1,1);
	
	a->x=xx;
	a->y=yy;
	a->z=zz;
	a->thetha=th;
	return a;

}


void Lego::setw(){

	mood=0;
	switch (index){
		case 0:wx=1;wz=1;h=3;break;
		case 1:wx=1;wz=2;h=3;break;
		case 2:wx=1;wz=3;h=3;break;
		case 3:wx=1;wz=4;h=3;break;
		case 4:wx=1;wz=6;h=3;break;
		case 5:wx=1;wz=8;h=3;break;
		case 6:wx=2;wz=2;h=3;break;
		case 7:wx=2;wz=4;h=3;break;
		case 8:wx=2;wz=6;h=3;break;
		case 9:wx=1;wz=2;h=3;break;
		case 10:wx=1;wz=2;h=3;break;
		case 11:wx=1;wz=3;h=3;break;
		case 12:wx=1;wz=3;h=3;break;
		case 13:wx=1;wz=6;h=3;break;
	default:
		break;
	}
	

}
void drawStaticLego(Lego* c){
	glPushMatrix();
	glTranslatef(c->x,c->y,c->z);
	glmDraw(World::LegoObj[c->index],(GLuint) GLM_SMOOTH);
	glPopMatrix();
}
void drawALeg(int i,float R,float G,float B,bool isdm){
	if(i!=9){
	if(isdm){glColor4f(R,G,B,.4);isdm=true;}
	else glColor3f(R,G,B);
		glmDraw(World::LegoObj[i],(GLuint) GLM_SMOOTH);
	}else
	{   
			if(isdm){glColor4f(R,G,B,.4);isdm=true;}
	        else glColor3f(R,G,B);
		    glmDraw(World::LegoObj[0],(GLuint) GLM_SMOOTH);
	   
		   glColor4f(1,1,0,.3);
		   glTranslatef(0,0,-Lego::re);
		   glmDraw(World::LegoObj[9],(GLuint) GLM_SMOOTH);
	  
	}
	//printf(",");
}

void World::drawAllLego(){
	
	int i=0;
	for (std::vector<Lego*>::iterator it = allLego.begin(); it != allLego.end(); ++it)
	{
		//printf("%d\n",i++);
	Lego* a=*it;
	
	a->drawLego();
	}

	

}

const float Lego::re=1.0;
const float	Lego::he=1.0/3;



int World::max(int x,int z,int h){
	return std::max(h,board[x][z]->findmax(board[x][z]->root)->element);
}
int World::addVal(int x,int z,int h){
	
	board[x][z]->insert(h,board[x][z]->root);
	return h;
}
World::World(){
	initialWorld();
}

Lego::Lego(int idx,float rr,float gg,float bb){
	int xx=World::worldX/2,yy=0,zz=World::worldZ/2;thetha=0;

	if(Lego::dm){xx=Lego::dm->x;yy=Lego::dm->y;zz=Lego::dm->z;
	thetha=dm->thetha;
	}
	x=xx;
	y=yy;
	z=zz;
	index=idx;
	mood=0;
	R=rr;G=gg;B=bb;
     setw();
	
		
		
	
}
int World::removeVal(int x,int z,int value){
	//never use h
	board[x][z]->del(value,board[x][z]->root);
	
	return value;
}


	//vector<int>** World::board;
	
	void World::initialWorld(){
		LegoObj = new _GLMmodel*[15];
		LegoObj[14]=glmReadOBJ("Lego_32x32_Base.obj");
		for(int i=0;i<14;i++){
			char buff[100];
            itoa(i,buff,10);
			
			strcat(buff,".obj");
			LegoObj[i]=glmReadOBJ(buff);
			
		}
		
		board=new bstree**[World::worldX];
		
		for(int i=0;i<World::worldZ;i++)
		{   
        board[i]=new bstree*[World::worldZ];
	
		for(int j=0;j<World::worldZ;j++){
			
				board[i][j]=new bstree;
				board[i][j]->insert(0,board[i][j]->root);
		   }
		
	
		}
		
		
	}
	 World::~World(){
	 for(int i=0;i<worldX;i++)
	 {   
		 for(int j=0;j<worldZ;j++){
			 board[i][j]->makeempty(board[i][j]->root);
			 delete board[i][j];
		 }
		
		 delete[] board[i];
	 }
	
	 delete[] board;
	 for (std::vector<Lego*>::iterator it = allLego.begin(); it != allLego.end(); ++it)
	 {      
		 Lego* x=*it;
		 delete x;
	 }
		
 }

	int World::find(Lego* a)// up =0;down=1;left=2;righ=3;
	{    
		int gg=a->traverse(0,0,this);
	
	return gg;
	}
	



	int World::addLego(Lego* a){
	  a-> mood=0;
	   Lego::dm=a;
	   int temp=find(a);
	   printf("\n\n\nadd :%d a->h %d\n\n\n",temp,a->h);
	   if(temp<0)return 0;
	   a->y=temp;
	   a->traverse(2,temp+a->h,this);
	   allLego.push_back(a);
	   return 1;
	}
void Lego::init(int xx,int yy,int zz,int tht,int idx,float rr,float gg,float bb){
		x=xx;
		y=yy;
		z=zz;
		thetha=tht;
		index=idx;
		R=rr;G=gg;B=bb;
		setw();
}

Lego::Lego(int x,int y,int z,int idx,float rr,float gg,float bb){
	
		init(x,y,z,0,idx,rr,gg,bb);
}
int World::canADD(int x,int z,int value,bool &pass){
	/*if(!board[x][z]->root->left &&!board[x][z]->root->right){
		printf("canADDZero %d x%d z%d\n",value,x,z);
		if(value==3)pass=true;
		return 1;
	}*/
	printf("canADD %d x%d z%d\n",value,x,z);
	int min=value,max=value+6;
	board[x][z]->find(value,board[x][z]->root,min,max);
		printf("BFifmin %d max%d\n",min,max);
	if(min <= value-3 && max >=value+3){
	printf("min %d max%d\n",min,max);
		if(max==value+3 || min==value-3)pass=true;	
		return 1;
	}

		return 0;
}
int Lego::traverse(int choose,int begin,World* w){
	
	bool pass=false;
		if(thetha == 0){
			for(int i=0;i < wx;i++){
				for(int j=0;j < wz;j++){
					int xx=x+i;
					int zz=z-j;
					
					if(xx>=World::worldX || xx<0||zz>=World::worldZ||zz<0)return -1;
					switch (choose)
					{case 0: begin=w->max(xx,zz,begin);break;
					 case 1:  w->removeVal(xx,zz,begin);break;
					 case 2:  w->addVal(xx,zz,begin);break;
					 case 3: 
						 printf("xx%d zz%d \n",xx,zz);
						 if(!w->canADD(xx,zz,begin,pass))return 0; break;
					 default:break;
					}
				}
			}
		} else if(thetha == 270){
			for(int i=0;i < wz;i++){
				for(int j=0;j < wx;j++){
					int xx=x+i;
					int zz=z+j;
						
					if(xx>=World::worldX || xx<0||zz>=World::worldZ||zz<0)return -1;
					switch (choose)
					{case 0: begin=w->max(xx,zz,begin);break;
					case 1:  w->removeVal(xx,zz,begin);break;
					case 2:  w->addVal(xx,zz,begin);break;
					case 3: printf("xx%d zz%d \n",xx,zz);if(!w->canADD(xx,zz,begin,pass))return 0; break;
					default:
						break;
					}
				}
			}
		} else if(thetha == 180){
			for(int i=0;i < wx;i++){
				for(int j=0;j < wz;j++){
					int xx=x-i;
					int zz=z+j;
						
					if(xx>=World::worldX || xx<0||zz>=World::worldZ||zz<0)return -1;
					switch (choose)
					{case 0: begin=w->max(xx,zz,begin);break;
					case 1:  w->removeVal(xx,zz,begin);break;
					case 2:  w->addVal(xx,zz,begin);break;
						case 3: printf("xx%d zz%d \n",xx,zz);if(!w->canADD(xx,zz,begin,pass))return 0; break;
					default:
						break;
					}
				}
			}

		} else if(thetha == 90){
			for(int i=0;i < wz;i++){
				for(int j=0;j < wx;j++){
					int xx=x-i;
					int zz=z-j;
						
					if(xx>=World::worldX || xx<0||zz>=World::worldZ||zz<0)return -1;
					switch (choose)
					{case 0: begin=w->max(xx,zz,begin);break;
					case 1:  w->removeVal(xx,zz,begin);break;
					case 2:  w->addVal(xx,zz,begin);break;
						case 3: printf("xx%d zz%d \n",xx,zz);if(!w->canADD(xx,zz,begin,pass))return 0; break;
					default:
						break;
					}
			}
		}
	}
		return choose==3?pass:begin ;
}
bool mov=false;
void Lego::drawLego(){
	glPushMatrix();
	bool isdm=false;
	if(this==dm && !mov){glColor4f(R,G,B,.5);isdm=true;}
	else glColor3f(R,G,B);
	
	
	glTranslatef(re*(x
		-World::worldX/2
		),he*y,re*(z
		-World::worldZ/2
		));
	glRotatef(thetha,0,1,0);
	glTranslatef(-re/2,0,re/2); 
	
//----
	drawALeg(index,R,G,B,isdm);
//---
	glPopMatrix();

}

void World::move(int xx,int zz){

	mov=true;
	Lego* t=undo();
	if(!t)return;
	
	t->x+=xx;t->z+=zz;
 //surebutslow
	int accept=find(t);
	if(accept<0){
	t->x-=xx;t->z-=zz;
	}

	addLego(t);

	

	mov=false;
}
void World::rotate(int i){
	
	mov=true;
	Lego* t=undo();
	if(!t)return;
	
	t->thetha+= (i>0)?90:-90;
	while(t->thetha>=360)t->thetha=360-t->thetha;
	while(t->thetha<0)t->thetha+=360;
	printf("rotate %d\n",t->thetha);

		//sure but slow
	int accept=find(t);
	if(accept<0){
		t->thetha-= (i>0)?90:-90;
		while(t->thetha>=360)t->thetha=360-t->thetha;
	    while(t->thetha<0)t->thetha+=360;
	}
   
	addLego(t);
	mov=false;
}

 void World::drawField(){

	 glPushMatrix();
            glColor3f(.92578125,.78515625,.686274509);
			glTranslatef(-Lego::re/2.0-worldX/2-Lego::re,-Lego::he,worldZ/2*Lego::re+Lego::re/2.0);
			glmDraw(LegoObj[14],(GLuint) GLM_SMOOTH);
	glPopMatrix();
	

}

 void World::LegoDown(){
	printf("downNA \n");
	 if(!allLego.size())return;
	 Lego*a=allLego.back();
	 a=undo();

	
 int i;
	 for( i=a->y;i>=3;i-=3){

		 if(a->traverse(3,i,this)){
			 printf("okidown %d \n",i);
			 break;
		 }
	
	 }
	 
	 if(i<=0){
		 printf("\ni<0 %d \n\n",i);
		 this->addLego(a);return;}
	 
	 printf("idown %d \n",i);
	 a->y=i-3; a->mood++;
	 a->traverse(2,i,this);
	 allLego.push_back(a);
	 Lego::dm=a;
 
 }
 void World::LegoUp(){

	 Lego*a = allLego.back();
	
	 a = undo();
	 if(!a)return;
	 int fin=find(a);
	 
	  int i;
	 for( i=a->y+2*a->h;i<fin;i+=3){

		 if(a->traverse(3,i,this)){
			 printf("okiup %d \n",i);
			 break;
		 }
		
	 }
	 if(i>=fin){ this->addLego(a);return;}
	      a->y=i-3;a->mood--;
		  a->traverse(2,i,this);
		  
	      allLego.push_back(a);
	      Lego::dm=a;
	

 }
 Lego* World::undo(){
		
		if(!allLego.size()){Lego::dm=0;return 0;}
		Lego* c=allLego.back();
		
		c->traverse(1,c->y+c->h,this);
		allLego.pop_back();
		if(!allLego.size())Lego::dm=0;else Lego::dm=allLego.back();

		return c;
	}
	

	
 
void World::safe(char *s){
  ofstream myfile;
  myfile.open (s);
  myfile<< allLego.size()<<endl;
  int i=0;
  if(!allLego.size())return;
	for (std::vector<Lego*>::iterator it = allLego.begin(); it != allLego.end(); ++it)
	{Lego* x=*it;
	printf("safeing %d %\n",i++);
	myfile<<x->index<<" "<<x->x<<" "<<x->y<<" "<<x->z<<" "<<x->R<<" "<<x->G<<" "<<x->B<<" "<<x->thetha<<" "<<x->mood<<endl;
	}
	printf("safe DONe \n");

  myfile.close();
  


}
World* World::load(char* s,World* w){
	// World* w=new World(); 
	 ifstream myfile;
     myfile.open (s, ios::in);
	 if(!myfile.is_open())return 0;
 int idx,x,y,z,th,mood;
 float R,G,B;
 int has;
   myfile >> has;

   for(int i=0;i<World::worldX;i++)
		{   
		for(int j=0;j<World::worldZ;j++){
			// printf("initing boad & height-%d \n",i,j);
				w->board[i][j]->makeempty(w->board[i][j]->root);
				w->board[i][j]->insert(0,w->board[i][j]->root);
		   }
//	 printf("initing boad & height-%d \n",i);
		}
   printf("inited boad & height \n");
		while(w->allLego.size()){
			Lego* c=w->allLego.back();
			w->allLego.pop_back();
			delete c;
		
		}
	Lego::dm=0;
  printf("inited allot \n");
 if (has) {
 while (!myfile.eof()) {


	 myfile >> idx>>x>>y>>z>>R>>G>>B>>th>>mood;
     Lego* c=new Lego(idx,R,G,B);	
	 c->x=x;
	 c->y=y;
	 c->z=z;
	
	 c->thetha=th;
	 w->addLego(c);
	 for(int i=0;i<mood;i++){
		 w->LegoDown();
	 }

 }
}
 w->undo();
 myfile.close();
 printf("Load DONe \n");

 return w;
 }
node* newnode(int f){
    node *x=new node;
	x->element=f;
	x->left=0;
	x->right=0;
	x->height=0;
	

}


void bstree::insert(int x,nodeptr &p)
{
	if (p == NULL)
	{   size++;
		p = new node;
		p->element = x;
		p->left=NULL;
		p->right = NULL;
		p->height=0;
		if (p==NULL)
		{
			cout<<"Out of Space\n"<<endl;
		}
	}
	else
	{
		if (x<p->element)
		{
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2)
			{
				if (x < p->left->element)
				{
					p=srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x>p->element)
		{
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2)
			{
				if (x > p->right->element)
				{
					p=srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			cout<<"Element Exists "<< x<<endl;
		}
}
int m,n,d;
m=bsheight(p->left);
n=bsheight(p->right);
d=max(m,n);
p->height = d + 1;
}
// Finding the Smallest
nodeptr bstree::findmin(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->left !=NULL)
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}
// Finding the Largest node
nodeptr bstree::findmax(nodeptr p)
{
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->right !=NULL)
		{
			p=p->right;
			//return p;
		}
		return p;
	}
}
// Finding an element
void bstree::find(int x,nodeptr &p,int &min,int &max)
{
	if (p==NULL)
	{
		cout<<"Sorry! element not found "<<x<<endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x,p->left,min,max=p->element);
		}
		else
		{
			if (x>p->element)
			{
				find(x,p->right,min=p->element,max);
			}
			else
			{   min=x;max=x;
				cout<<"Element found! "<<x<<endl;
			}
		}
	}
}
// Copy a tree
void bstree::copy(nodeptr &p,nodeptr &p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}
// Make a tree empty
void bstree::makeempty(nodeptr &p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d=p;
		free(d);
		p=NULL;
	}
}
// Copy the nodes
nodeptr bstree::nodecopy(nodeptr &p)
{
	nodeptr temp;
	if (p==NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}

// Deleting a node
void bstree::del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
	{
		cout<<"Sorry! element not found\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{size--;
		d=p;
		free(d);
		p=NULL;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->left == NULL)
	{size--;
		d=p;
		free(d);
		p=p->right;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->right == NULL)
	{size--;
		d=p;
		p=p->left;
		free(d);
		cout<<"Element deleted successfully\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}

int bstree::deletemin(nodeptr &p)
{
	int c;
	cout<<"inside deltemin\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}
void bstree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
		cout<<p->element<<"\t";
		preorder(p->left);
		preorder(p->right);
	}
}

// Inorder Printing
void bstree::inorder(nodeptr p)
{
	if (p!=NULL)
	{
		inorder(p->left);
		cout<<p->element<<"\t";
		inorder(p->right);
	}
}

// PostOrder Printing
void bstree::postorder(nodeptr p)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->element<<"\t";
	}
}

int bstree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}
int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr bstree:: srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left),p1->height) + 1;
	return p2;
}
nodeptr bstree:: srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(p1->height,bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree:: drl(nodeptr &p1)
{
	p1->left=srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int bstree::nonodes(nodeptr p)
{
	int count=0;
	if (p!=NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;
}
