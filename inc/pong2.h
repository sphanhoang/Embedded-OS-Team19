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

int player_score, cpu_score;

typedef enum{
    menu,
    play
}state;

void DrawBall (Ball ball);
void UpdateBall(Ball *ball);
void UpdateScore(int player_score, int cpu_score, Ball *ball);
void DrawPaddle(Paddle paddle);
void UpdatePaddle(Paddle *paddle);
void UpdateCpuPaddle(Paddle *cpu, int ball_y);
void game();

#endif
