#pragma once

#include <string.h>
#include <vector>
#include <iostream>
#include "GL\glut.h"

#include "Lego.h"
#include "GUIGl.h"
#include "Constant.h"

void guigl::guiBegin(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, w, h, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	glLoadIdentity();
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
}

void guigl::guiEnd() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void guigl::guiDrawStupidBox(int x, int y, 
	float r, float g, float b) {
	glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + 20, y);
		glVertex2f(x + 20, y + 20);
		glVertex2f(x, y + 20);
	glEnd();
}

void guigl::guiDrawString(int x, int y, 
	float r, float g, float b, void *font, char *string) {
	glColor3f( r, g, b );
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

/***************/
/* glGuiDrawer */
/***************/
guigl::glGuiDrawer::glGuiDrawer() {
}

void guigl::glGuiDrawer::addComponent(guigl::glGuiObject *component) {
	this->arraylist.push_back(component);
}

void guigl::glGuiDrawer::draw() {
	for(std::vector<guigl::glGuiObject *>::iterator iter = this->arraylist.begin(); iter != this->arraylist.end();++iter) {
		(*iter)->draw();
	}
}

void guigl::glGuiDrawer::onClick(int button, int state, int x, int y) {
	for(std::vector<guigl::glGuiObject *>::iterator iter = this->arraylist.begin(); iter != this->arraylist.end();++iter) {
		(*iter)->onClick(button, state, x, y);
	}
}


/***************/
/* glGuiObject */
/***************/
void guigl::glGuiObject::drawRect(int x1, int y1, 
	int x2, int y2, float r, float g, float b) {
	glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
	glEnd();
}

void guigl::glGuiObject::onClick(int button, int state, int x, int y) {
	/*this function isn't supposes to do anything as it's virtual*/
}

void guigl::glGuiObject::draw() {
	/*this function isn't supposes to do anything as it's virtual*/
}

void guigl::glGuiObject::setOnClickListener(listenerWrap::Listener *lw) {
	this->lw = lw;
}

/************/
/* glSlider */
/************/
guigl::glSlider::glSlider(int pos_x, int pos_y, int width, int height) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->width = width;
	this->r = 1.0;
	this->g = 1.0;
	this->b = 1.0;
	this->rPost = 1.0;
	this->gPost = 0.5;
	this->bPost = 1.0;
	this->height = height;
	this->percent = 0.5;
	this->lw = NULL;
}

void guigl::glSlider::onClick(int button, int state, int x, int y) {
	if(x < pos_x  || y < pos_y || x > pos_x + width || y > pos_y + height) {
		return;
	}
	percent = (1.0f * (x - pos_x)) / (width);
	if(lw != NULL){
		lw->onClick(button, state, x, y);
	} else {
		std::cout << "WARNING : You didn't set onClickListener()" << std::endl;
	}
}

void guigl::glSlider::draw() {
	this->drawRect(pos_x, pos_y, pos_x + (int)(width * percent), pos_y + height, this->r, this->g, this->b);
	this->drawRect(pos_x, pos_y, pos_x + width, pos_y + height, this->rPost, this->gPost, this->bPost);
}

/************/
/* glButton */
/************/
guigl::glButton::glButton(int pos_x, int pos_y, int width, int height) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->width = width;
	this->height = height;
	this->state = BUTTON_RELEASED;
	this->r = 1.0;
	this->g = 1.0;
	this->b = 1.0;
	this->rPost = 0.3;
	this->gPost = 0.3;
	this->bPost = 0.3;
	this->lw = NULL;
}

void guigl::glButton::onClick(int button, int mouse_state, int x, int y) {
	if(button != 0) {
		/*not left click*/
		return;
	}
	if(state == BUTTON_PRESSED && mouse_state == 1) {
		/*release left click*/
		state = BUTTON_RELEASED;
		return;
	}
	if(x < pos_x  || y < pos_y || x > pos_x + width || y > pos_y + height) {
		/*out of the button area*/
		return;
	}
	if(lw != NULL){
		lw->onClick(button, state, x, y);
	} else {
		std::cout << "WARNING : You didn't set onClickListener()" << std::endl;
	}
	state = BUTTON_PRESSED;
}

void guigl::glButton::draw() {
	if(state == BUTTON_PRESSED)
		this->drawRect(pos_x, pos_y, pos_x + width, pos_y + height, this->rPost, this->gPost, this->bPost);
	else if(state == BUTTON_RELEASED)
		this->drawRect(pos_x, pos_y, pos_x + width, pos_y + height, this->r, this->g, this->b);
	this->drawRect(pos_x - BUTTON_OUTER_BORDER, pos_y - BUTTON_OUTER_BORDER, 
		pos_x + width + BUTTON_OUTER_BORDER, pos_y + height + BUTTON_OUTER_BORDER, 0.3, 0.3, 0.3);
	this->drawRect(pos_x - BUTTON_OUTER_BORDER + 4, pos_y - BUTTON_OUTER_BORDER + 4, 
		pos_x + width + BUTTON_OUTER_BORDER + 4, pos_y + height + BUTTON_OUTER_BORDER + 4, 0.2, 0.2, 0.2);
}

/************/
/* listener */
/************/

void listenerWrap::Listener::onClick(int, int, int, int) {
}

listenerWrap::colorListener::colorListener(float r, float g, float b, float *currentR, float *currentG, float *currentB, World *world) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->world = world;
	this->currentR = currentR;
	this->currentG = currentG;
	this->currentB = currentB;
	
}

void listenerWrap::colorListener::onClick(int, int, int, int) {
	*(this->currentR) = this->r;
	*(this->currentG) = this->g;
	*(this->currentB) = this->b;
	if(!world->allLego.size())return;
	Lego* x=world->allLego.back();
	
	x->R=r;
	x->G=g;
	x->B=b;
	std::cout << "Just Clicked color " << this->r << ", " << this->g << ", " << this->b << std::endl;	
}

listenerWrap::modelListener::modelListener(int modelIndex, int *currentModelIndex, World *world) {
	this->modelIndex = modelIndex;
	this->currentModelIndex = currentModelIndex;
	this->world = world;
}

void listenerWrap::modelListener::onClick(int, int, int, int) {
	*(this->currentModelIndex) = modelIndex;
	if(!world->allLego.size())return;
	Lego* x=world->undo();
	
	x->index=modelIndex;
	x->setw();
	world->addLego(x);
}