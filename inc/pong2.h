#include "../inc/framebf.h"
#include "../inc/uart1.h"
#include "../inc/delay.h"

typedef struct {
    int x, y;
    int speed_x, speed_y;
} Ball;

typedef struct {
    int x1,y1;
    int x2,y2;
    int speed;                        //speed in y-direction
} Paddle;

void DrawBall (Ball ball);
void UpdateBall(Ball *ball);
void DrawPaddle(Paddle paddle);
void UpdatePaddle(Paddle *paddle);
void UpdateCpuPaddle(Paddle *cpu, int ball_y);
void game();