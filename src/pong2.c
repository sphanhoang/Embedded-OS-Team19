#include <stdio.h>
//#include "raylib.h"
#include "../inc/framebf.h"
#include "framebf.c"
#include "../inc/uart0.h"
#include "../inc/uart1.h"

int player_score = 0;
int cpu_score = 0;

typedef struct Ball {
    int x, y;
    int speed_x, speed_y;
    int attr;
} Ball;

void DrawBall(Ball ball) {              
    drawPixel(ball.x, ball.y, ball.attr);
}

void UpdateBall(Ball *ball) {           //GetScreenHeight->actual boundary value
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if (ball->y >= mbox[6] ) {          //vertical collision
        ball->speed_y *= -1;
    }

    if (ball->x >= mbox[5] ) {          //horizontal collision
        ball->speed_x *= -1;
    }
}

typedef struct Paddle {
    int x1,y1;
    int x2,y2;
    int speed;                        //speed in y-direction
} Paddle;

void DrawPaddle(Paddle paddle) {        
    drawRect(paddle.x1, paddle.y1, paddle.x2, paddle.y2, BLUE, 1);
}

void UpdatePaddle(Paddle *paddle) {
    if (uart_getc("i")) {            //if (IsKeyDown(KEY_UP))
        paddle->y2 -= paddle->speed;
    }

    if (uart_getc("k")) {          //if (IsKeyDown(KEY_DOWN))
        paddle->y2 += paddle->speed;
    }

    // Limit paddle movement within the screen boundaries
    if (paddle->y1 <= 0) {
        paddle->y1 = 0;
    }

    if (paddle->y2 >= mbox[6]) { 
        paddle->y2 = mbox[6];
    }
}

/*
typedef struct CpuPaddle {
    int x1,y1;
    int x2,y2;
    int speed;
} CpuPaddle; 
*/

void UpdateCpuPaddle(Paddle *cpu, int ball_y) {
    //CpuPaddle paddle = &(cpu->paddle);
    if (cpu->y1 > ball_y) {
        cpu->y1 -= cpu->speed;
    }
    if (cpu->y2 < ball_y) {
        cpu->y2 += cpu->speed;
    }

    // Limit paddle movement within the screen boundaries
    if (cpu->y1 <= 0) {
        cpu->y1 = 0;
    }

    if (cpu->y2 >= mbox[6]) {
        cpu->y2 = mbox[6];
    }
}

int main() {
    //printf("bruhhhhh\n");
    framebf_init();
    //const int screen_width = 1600;
    //const int screen_height = 900;
    drawRect(0, 0, mbox[5], mbox[6], WHITE, 0);
    //SetTargetFPS(60);

    Ball ball;
    //ball.radius = 20;
    ball.x = mbox[5] / 2;
    ball.y = mbox[6] / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;                   //checkpoint 1, Ball done

    Paddle player;
    //player.width = 20;
    //player.height = 180;
    player.x1 = mbox[5] - 20;
    player.y1 = mbox[6] / 2 - 180 / 2;
    player.x2 = mbox[5];
    player.y2 = mbox[6] / 2 + 180 / 2;
    player.speed = 7;                   // player Paddle done

    Paddle cpu;
    //cpu.paddle.width = 20;
    //cpu.paddle.height = 180;
    cpu.x1 = 10;
    cpu.y1 = 0;
    cpu.x2 = 10 + 20;
    cpu.y2 = mbox[6] / 2 + 180 / 2;
    cpu.speed = 7;                      // cpu Paddle done

    while (1) {
        //BeginDrawing();
        
        // Update
        UpdateBall(&ball);
        UpdatePaddle(&player);
        UpdateCpuPaddle(&cpu, ball.y);

        // Check for collisions
        //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){player.x, player.y, player.width, player.height})) {
          if(ball.x <= cpu.x2) {
            ball.speed_x *= -1;
        }

        //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){cpu.paddle.x, cpu.paddle.y, cpu.paddle.width, cpu.paddle.height})) {
          if(ball.x >=player.x1) {
            ball.speed_x *= -1;
        }

        // Draw
        clearScreen();                            //ClearBackground(BLACK);
        //DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        DrawBall(ball);
        DrawPaddle(player);
        DrawPaddle(cpu);

        //EndDrawing();
    }

    //CloseWindow();
    return 0;
}
