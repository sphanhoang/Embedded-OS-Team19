#include "../inc/pong2.h"

int player_score = 0;
int cpu_score = 0;
extern int width, height; // physical dimension
char userInput;

/**
 * Draw ball function
 * @param ball: Ball variable contains x, y and radius parameter
*/
void DrawBall(Ball ball) 
{              
    drawCircle(ball.x, ball.y, ball.radius, WHITE, 1);
}

/**
 * Update current position of the ball
 * @param ball: a pointer point to ball variable
*/
void UpdateBall(Ball *ball) 
{           //GetScreenHeight->actual boundary value
    drawCircle(ball->x, ball->y, ball->radius, BLACK, 1);
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if ((ball->y + ball->radius >= height) || (ball->y - ball->radius <= 0)) 
    {          //vertical collision
        ball->speed_y *= -1;
    }

    if ((ball->x + ball->radius >= width) || (ball->x - ball->radius <= 0)) 
    {          //horizontal collision
        ball->speed_x *= -1;
    }
}
void UpdateScore (int player_score, int cpu_score, Ball *ball)
{
    if (ball->x - ball->radius <= 0) 
    {
        player_score++;
    }

    if (ball->x + ball->radius >= width)
    {
        cpu_score++;
    }
}
/**
 * Draw paddle function
 * @param paddle: Paddle variable contains coordinate of top left and bottom right points and color
*/
void DrawPaddle(Paddle paddle) 
{        
    drawRect(paddle.x1, paddle.y1, paddle.x2, paddle.y2, BLUE, 1);
}

/**
 * Update player paddle position
*/
void UpdatePaddle(Paddle *paddle) 
{
    if (userInput == 'w') 
    {            //if (IsKeyDown(KEY_UP))
        if (paddle->y1 >= 0)    // limit paddle movement to screen boundary
        {
            drawRect(paddle->x1, paddle->y1, paddle->x2, paddle->y2, BLACK, 1);
            paddle->y1 -= paddle->speed;
            paddle->y2 -= paddle->speed;
        }
    }

    if (userInput == 's') 
    {          //if (IsKeyDown(KEY_DOWN))
        if (paddle->y2 <= height)  // limit paddle movement to screen boundary
        {
            drawRect(paddle->x1, paddle->y1, paddle->x2, paddle->y2, BLACK, 1);
            paddle->y1 += paddle->speed;
            paddle->y2 += paddle->speed;
        }
    }
}

/**
 * Update CPU paddle position
*/
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
        if (cpu->y2 <= height) // limit paddle movement to screen boundary
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
    userInput = 0;
    Ball ball;
    //ball.radius = 20;
    ball.x = width / 2;
    ball.y = height / 2;
    ball.radius = 10;
    ball.speed_x = 3;
    ball.speed_y = 3;                   //checkpoint 1, Ball done

    Paddle player;
    //player.width = 20;
    //player.height = 180;
    player.x1 = width- 25;
    player.y1 = height/ 2 - 180 / 2;
    player.x2 = width- 5;
    player.y2 = height/ 2 + 180 / 2;
    player.speed = 20;                   // player Paddle done

    Paddle cpu;
    //cpu.paddle.width = 20;
    //cpu.paddle.height = 180;
    cpu.x1 = 5;
    cpu.y1 = height/ 2 - 180 / 2;
    cpu.x2 = 5 + 20;
    cpu.y2 = height/ 2 + 180 / 2;
    cpu.speed = 3;                      // cpu Paddle done

    state gameState = menu;
    while (userInput != 'c') 
    {
        userInput = getUart();
        switch (gameState)
        {
            case menu:
                drawString(280, 100, "Welcome to Pong", WHITE, 4);
                drawString(330, 250, "Press Spacebar to begin", YELLOW, 2);
                drawString(260, 300, "Press W and S to move up and down", YELLOW, 2);
                DrawBall(ball);
                DrawPaddle(player);
                DrawPaddle(cpu);
                if (userInput == ' ')
                {
                    gameState = play;
                    clearScreen();
                }
                break;
            case play:
                //BeginDrawing();
                // Update
                drawScore(0,20, "Player's score: %d", player_score, WHITE,1);
                drawScore(0,40, "CPU's score: %d", cpu_score, WHITE,1);
                UpdateScore(player_score, cpu_score, &ball);
                UpdateBall(&ball);
                UpdatePaddle(&player);
                UpdateCpuPaddle(&cpu, ball.y);

                // Check for collisions
                //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){player.x, player.y, player.width, player.height})) {
                if((ball.x - ball.radius <= cpu.x2) && (ball.y - ball.radius >= cpu.y1) && (ball.y + ball.radius < cpu.y2)) 
                {
                    ball.speed_x *= -1;
                }

                //if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, (Rectangle){cpu.paddle.x, cpu.paddle.y, cpu.paddle.width, cpu.paddle.height})) {
                if((ball.x + ball.radius >= player.x1) && (ball.y - ball.radius >= player.y1) && (ball.y + ball.radius < player.y2))
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
                break;
            default:
                gameState = menu;
                break;
        }
    }
}
