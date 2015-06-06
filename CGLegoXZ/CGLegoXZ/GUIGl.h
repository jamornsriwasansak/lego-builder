#pragma once

#include "Lego.h"
#include "POVExp.h"
#include "GUIGl.h"
#include <iostream>
#include <vector>

#define BUTTON_PRESSED 129
#define BUTTON_RELEASED 130

namespace listenerWrap {
	class Listener {
	public:
		virtual void onClick(int, int, int, int);
	};

	class colorListener : public Listener {
	public:
		float r;
		float g;
		float b;
		float *currentR;
		float *currentG;
		float *currentB;
		World *world;
	public:
		colorListener(float r, float g, float b, float *currentR, float *currentG, float *currentB, World *world);
		void onClick(int, int, int, int);
	};

	class modelListener :public Listener {
	public:
		int modelIndex;
		int *currentModelIndex;
		World *world;
	public:
		modelListener(int modelIndex, int *currentModelIndex, World *world);
		void onClick(int, int, int, int);
	};

	class renderListener : public Listener {
	public:
		PovExp *povExp;
		World *world;
		Camera *cam;
	public:
		renderListener(PovExp *povExp, World *world, Camera *cam) {
			this->povExp = povExp;
			this->world = world;
			this->cam = cam;
		}
		void onClick(int, int, int, int) {
			povExp->convert(this->world, this->cam);
		}
	};
}

namespace guigl{
	void guiBegin(int screen_w,int screen_h);
	void guiEnd();
	void guiDrawStupidBox(int pos_x, int pos_y, 
		float r, float g, float b);
	void guiDrawString(int pos_x, int pos_y, 
		float r, float g, float b, void *font,
		/*
		GLUT_BITMAP_8_BY_13
		GLUT_BITMAP_9_BY_15
		GLUT_BITMAP_TIMES_ROMAN_10
		GLUT_BITMAP_TIMES_ROMAN_24
		GLUT_BITMAP_HELVETICA_10
		GLUT_BITMAP_HELVETICA_12
		GLUT_BITMAP_HELVETICA_18
		*/
		char *string);

	class glGuiObject {
	public:
		float r;
		float g;
		float b;
		float rPost;
		float gPost;
		float bPost;
		listenerWrap::Listener *lw;
	protected:
		void drawRect(int x1, int y1, int x2, int y2, 
			float r, float g, float b);
	public:
		virtual void onClick(int button, int state, int x, int y);
		virtual void draw();
		void setOnClickListener(listenerWrap::Listener *lw);
	};
	
	class glGuiDrawer {
	private:
		std::vector<guigl::glGuiObject *> arraylist;
	public:
		glGuiDrawer();
		void addComponent(guigl::glGuiObject *component);
		void onClick(int button, int state, int x, int y);
		void draw();
	};

	class glSlider : public glGuiObject {
	private:
		int pos_x;
		int pos_y;
		int width;
		int height;
	public:
		float percent;
		glSlider(int pos_x, int pos_y, int width, int height);
	protected:
		void draw();
		void onClick(int button, int state, int x, int y);
	};

	class glButton : public glGuiObject {
	private:
		int pos_x;
		int pos_y;
		int width;
		int height;
		int state;
	public:
		glButton(int pos_x, int pos_ym, int width,int height);
	protected:
		void draw();
		void onClick(int button, int state, int x, int y);
	};
}

namespace listenerWrap {
	class sliderListener : public Listener {
	public:
		float *color;
		guigl::glSlider *slider;
	public:
		sliderListener(guigl::glSlider *slider, float *currentColor) {
			this->color = currentColor;
			this->slider = slider;
		}
		void onClick(int, int, int, int) {
			(*color) = slider->percent;
		}
	};
}