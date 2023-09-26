#ifndef PONG2_H
#define PONG2_H

#include "framebf.h"
#include "uart1.h"
#include "delay.h"

typedef struct {
    int x, y;
    int radius;
    int speed_x, speed_y;
} Ball;

typedef struct {
    int x1,y1;
    int x2,y2;
    int speed;                        //speed in y-direction
} Paddle;

typedef enum{
    menu,
    play,
    endgame
}state;

void DrawBall (Ball ball);
void UpdateBall(Ball *ball);
void DrawPaddle(Paddle paddle);
void UpdatePaddle(Paddle *paddle);
void UpdateCpuPaddle(Paddle *cpu, int ball_y);
// void collision(Ball *ball, Paddle *rect);
void gameini(Ball *ball, Paddle *cpu, Paddle *player);
void game();

#endif