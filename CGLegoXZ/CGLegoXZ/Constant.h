#include"GUIGl.h"

#pragma once

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

const int BUTTON_GAP = 10;

const int BUTTON_OUTER_BORDER = 1;

const int MODEL_BUTTON_PER_ROW = 4;
const int MODEL_BUTTON_WIDTH = 60;
const int MODEL_BUTTON_HEIGHT = 60;
const int MODEL_AMOUNT = 14;
const int MODEL_START_X = SCREEN_WIDTH - (MODEL_BUTTON_PER_ROW * (BUTTON_GAP + MODEL_BUTTON_WIDTH)) - 20;
const int MODEL_START_Y = BUTTON_GAP + 20;

const int COLOR_BUTTON_PER_ROW = 5;
const int COLOR_BUTTON_WIDTH = 50;
const int COLOR_BUTTON_HEIGHT = 50;
const int COLOR_AMOUNT = 7;
const int COLOR_START_X = MODEL_START_X;
const int COLOR_START_Y = SCREEN_HEIGHT - 250;

const float hud3dPosition[3] = {-10000, 0, -10000};
const float color_suit[COLOR_AMOUNT][3] = {{0, 1, 1}, {0, 1, 0}, {0, 0.5, 1}, {1, 0.5, 0}, {1, 1, 1}, {1,1,0}, {0.3,0.3,0.3}};
const float button3dPosition[15][3] = {{13.6, 0, 4}, {13.6, -6.5, -1}, {15, -10 ,-5}, {16.5, -10, -7}, {6, -42, -12}, {3.5, -68.5, -29.5}, {14.5, -22.5, -8},  {16, -35, -18}, {6, -62.5, -15}, {16.5, -15, 2}, {17.8, -19, -2}, {18.8, -32, -10}, {14.3, -30, 1.5}, {13.8, -60, -11}};

const int CLICK_LEFT = 0;
const int CLICK_RIGHT = 2;

const int CLICKED = 0;
const int RELEASED = 1;

/*this function is intent to initial the gui*/
