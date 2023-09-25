#include "../inc/pong2.h"

int player_score = 0;
int cpu_score = 0;

void DrawBall(Ball ball) 
{              
    drawCircle(ball.x, ball.y, ball.radius, WHITE, 1);
}

void UpdateBall(Ball *ball) 
{           //GetScreenHeight->actual boundary value
    drawCircle(ball->x, ball->y, ball->radius, BLACK, 1);
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if (ball->y >= mbox[6] ) 
    {          //vertical collision
        ball->speed_y *= -1;
    }

    if (ball->x >= mbox[5] ) 
    {          //horizontal collision
        ball->speed_x *= -1;
    }
}

void DrawPaddle(Paddle paddle) 
{        
    drawRect(paddle.x1, paddle.y1, paddle.x2, paddle.y2, BLUE, 1);
}

void UpdatePaddle(Paddle *paddle) 
{
    if (getUart() == 'i') 
    {            //if (IsKeyDown(KEY_UP))
        if (paddle->y1 >= 0)    // limit paddle movement to screen boundary
        {
            drawRect(paddle->x1, paddle->y1, paddle->x2, paddle->y2, BLACK, 1);
            paddle->y1 -= paddle->speed;
            paddle->y2 -= paddle->speed;
        }
    }

    if (getUart() == 'k') 
    {          //if (IsKeyDown(KEY_DOWN))
        if (paddle->y2 <= mbox[6])  // limit paddle movement to screen boundary
        {
            drawRect(paddle->x1, paddle->y1, paddle->x2, paddle->y2, BLACK, 1);
            paddle->y1 += paddle->speed;
            paddle->y2 += paddle->speed;
        }
    }
}

void UpdateCpuPaddle(Paddle *cpu, int ball_y) {
    //CpuPaddle paddle = &(cpu->paddle);
    if (cpu->y1 > ball_y) 
    {
        if (cpu->y1 >= 0)   // limit paddle movement to screen boundary
        {
            drawRect(cpu->x1, cpu->y1, cpu->x2, cpu->y2, BLACK, 1);
            cpu->y1 -= cpu->speed;
            cpu->y2 -= cpu->speed;
        }
    }
    if (cpu->y2 < ball_y) 
    {
        if (cpu->y2 <= mbox[6]) // limit paddle movement to screen boundary
        {
            drawRect(cpu->x1, cpu->y1, cpu->x2, cpu->y2, BLACK, 1);
            cpu->y1 += cpu->speed;
            cpu->y2 += cpu->speed;
        }
    }
}

/**
 * Game main program
*/
void game() 
{
    clearScreen();
    drawRect(0, 0, mbox[5]-1, mbox[6]-1, WHITE, 0);

    Ball ball;
    //ball.radius = 20;
    ball.x = mbox[5] / 2;
    ball.y = mbox[6] / 2;
    ball.radius = 10;
    ball.speed_x = 3;
    ball.speed_y = 3;                   //checkpoint 1, Ball done

    Paddle player;
    //player.width = 20;
    //player.height = 180;
    player.x1 = mbox[5] - 25;
    player.y1 = mbox[6] / 2 - 180 / 2;
    player.x2 = mbox[5]-5;
    player.y2 = mbox[6] / 2 + 180 / 2;
    player.speed = 3;                   // player Paddle done

    Paddle cpu;
    //cpu.paddle.width = 20;
    //cpu.paddle.height = 180;
    cpu.x1 = 5;
    cpu.y1 = mbox[6] / 2 - 180 / 2;
    cpu.x2 = 5 + 20;
    cpu.y2 = mbox[6] / 2 + 180 / 2;
    cpu.speed = 3;                      // cpu Paddle done

    while (getUart() != 'c') 
    {
        //BeginDrawing();
        
        // Update
        UpdateBall(&ball);
        UpdatePaddle(&player);
        UpdateCpuPaddle(&cpu, ball.y);

        // Check for collisions
        //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){player.x, player.y, player.width, player.height})) {
        if(ball.x <= cpu.x2) 
        {
            ball.speed_x *= -1;
        }

        //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){cpu.paddle.x, cpu.paddle.y, cpu.paddle.width, cpu.paddle.height})) {
        if(ball.x >=player.x1) 
        {
            ball.speed_x *= -1;
        }
        // Draw
        //ClearBackground(BLACK);
        //DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        DrawBall(ball);
        DrawPaddle(player);
        DrawPaddle(cpu);

        wait_msec(5000);
    }
}
