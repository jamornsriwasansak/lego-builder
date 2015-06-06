#pragma once

#include "GL/glut.h"
#include <math.h>
#include <iostream>

const float accrlX = 0.009;
const float accrlZ = 0.009;
const float inertX = 0.003;
const float inertZ = 0.003;
const float accrlZoom = 0.010;
const float inertZoom = 0.001;
const float rotateVlcty = 3;
const float vlctyLimit = 30;

class Camera {
public:
	float r;
	float theta;
	float phi;
	float x;
	float y;
	float z;
	float vlctyX;
	float vlctyZ;
	float vlctyZoom;
public:
	Camera(float r, float theta, float phi, float x, float y, float z) {
		this->r = r;
		this->theta = theta;
		this->phi = phi;
		this->x = x;
		this->y = y;
		this->z = z;
		this->vlctyX = 0;
		this->vlctyZ = 0;
	}
	
	float getCenterX() {
		return this->x;
	}

	float getCenterY() {
		return this->y;
	}

	float getCenterZ() {
		return this->z;
	}

	float getEyeX() {
		return r * sin(theta * M_PI / 180) * sin(phi * M_PI / 180) + this->x;
	}

	float getEyeY() {
		return r * cos(theta * M_PI / 180) + this->y;
	}

	float getEyeZ() {
		return r * sin(theta * M_PI / 180) * cos(phi * M_PI / 180) + this->z;
	}

	void rotateCW() {
		phi += rotateVlcty;
	}

	void rotateCCW() {
		phi -= rotateVlcty;
	}

	void rotateUp() {
		theta += rotateVlcty;
		if(theta >= 170) //prevent flippy bug
			theta = 170;
	}

	void rotateDown() {
		theta -= rotateVlcty;
		if (theta <= 10) //prevent flippy bug
			theta = 10;
	}

	void moveUp() {
		vlctyX = (vlctyX + accrlX);
		if(vlctyX >= vlctyLimit)
			vlctyX = vlctyLimit;
	}
	
	void moveDown() {
		vlctyX = (vlctyX - accrlX);
		if(vlctyX <= -vlctyLimit)
			vlctyX = vlctyLimit;
	}
	
	void moveLeft() {
		vlctyZ = (vlctyZ - accrlZ);
		if(vlctyZ <= -vlctyLimit)
			vlctyZ = vlctyLimit;
	}
	
	void moveRight() {
		vlctyZ = (vlctyZ + accrlZ);
		if(vlctyZ >= vlctyLimit)
			vlctyZ = vlctyLimit;
	}

	void zoomIn() {
		vlctyZoom -= accrlZoom;
		if(vlctyZoom <= -vlctyLimit)
			vlctyZoom = -vlctyLimit;
	}

	void zoomOut() {
		vlctyZoom += accrlZoom;
		if(vlctyZoom >= vlctyLimit)
			vlctyZoom = vlctyLimit;
	}

	void update() {
		this->x += vlctyX;
		this->z += vlctyZ;

		this->r += vlctyZoom;
		if(r <= 10) {
			r = 10;
		}

		if(vlctyZoom > 0) {
			vlctyZoom -= inertZoom;
			vlctyZoom = (vlctyZoom < 0) ? 0 : vlctyZoom;
		} else if (vlctyZoom < 0) {
			vlctyZoom += inertZoom;
			vlctyZoom = (vlctyZoom > 0) ? 0 : vlctyZoom;
		}

		if(vlctyX > 0) {
			vlctyX = (vlctyX - inertX);
			vlctyX = (vlctyX < 0) ? 0 : vlctyX;
		} else if (vlctyX < 0) {
			vlctyX = (vlctyX + inertX);
			vlctyX = (vlctyX > 0) ? 0 : vlctyX;
		}

		if(vlctyZ > 0) {
			vlctyZ = (vlctyZ - inertZ);
			vlctyZ = (vlctyZ < 0) ? 0 : vlctyZ;
		} else if (vlctyZ < 0) {
			vlctyZ = (vlctyZ + inertZ);
			vlctyZ = (vlctyZ > 0) ? 0 : vlctyZ;
		}
	}
};