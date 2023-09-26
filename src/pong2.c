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
void UpdateCpuPaddle(Paddle *cpu, int ball_y) 
{
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

void gameini(Ball *ball, Paddle *cpu, Paddle *player)
{
    //ball.radius = 20;
    ball->x = width / 2;
    ball->y = height / 2;
    ball->radius = 10;
    ball->speed_x = 10;
    ball->speed_y = 10;                   //checkpoint 1, Ball done

    //player.width = 20;
    //player.height = 180;
    player->x1 = width- 25;
    player->y1 = height / 2 - 180 / 2;
    player->x2 = width- 5;
    player->y2 = height / 2 + 180 / 2;
    player->speed = 20;                   // player Paddle done

    //cpu.paddle.width = 20;
    //cpu.paddle.height = 180;
    cpu->x1 = 5;
    cpu->y1 = height/ 2 - 180 / 2;
    cpu->x2 = 5 + 20;
    cpu->y2 = height/ 2 + 180 / 2;
    cpu->speed = 20;  
}

/**
 * Check for collision 
*/
// void collision(Ball *ball, Paddle *cpu, Paddle *player)
// {
//     int rectWidth = rect->x2 - rect->x1;
//     int rectHeight = rect->y2 - rect->y1;

//     int rectX = (rect->x1 + rect->x2)/2;
//     int rectY = (rect->y1 + rect->y2)/2;

//     int ballDistanceX = (ball->x - rectX);
//     int ballDistanceY = (ball->y - rectY);

//     if (ballDistanceX <= (rectWidth/2))     // check for right/left edge collision
//     { 
//         ball->speed_x *= -1; 
//     } 
//     if (ballDistanceY <= (rectHeight/2))    // check for top/bottom edge collision 
//     { 
//         ball->speed_y *= -1;
//     }
//     int cornerDistance_sq = (ballDistanceX - rectWidth/2)^2 +
//                          (ballDistanceY - rectHeight/2)^2;

//     if (cornerDistance_sq <= (ball->radius^2))   // check for corner collision
//     {
//         ball->speed_x *= -1;
//         ball->speed_y *= -1;
//     }
// }

/**
 * Game main program
*/
void game() 
{
    clearScreen();
    Ball ball;
    Paddle player;
    Paddle cpu;

    userInput = 0;
    int playerScore = 0;
    int cpuScore = 0;

    gameini(&ball, &cpu, &player);
    state gameState = menu;
    while (userInput != 'c') 
    {
        userInput = getUart();
        switch (gameState)
        {
            case menu:
                drawString(280, 100, "Welcome to Pong", WHITE, 4);
                drawString(260, 300, "Press W and S to move up and down", YELLOW, 2);
                DrawBall(ball);
                DrawPaddle(player);
                DrawPaddle(cpu);
                drawString(330, 250, "Press Spacebar to begin", YELLOW, 2);
                wait_msec(250000);  // 250ms
                drawString(330, 250, "Press Spacebar to begin", BLACK, 2);
                wait_msec(250000);  // 250ms

                if (userInput == ' ')
                {
                    gameState = play;
                    clearScreen();
                }
                break;
            case play:
                drawLine(width/2, 0, width/2, height, WHITE);
                /* update */
                UpdateBall(&ball);
                UpdatePaddle(&player);
                UpdateCpuPaddle(&cpu, ball.y);
            
                /* Check for paddle collisions */
                if ((ball.x - ball.radius <= cpu.x2) && (ball.y - ball.radius >= cpu.y1) && (ball.y + ball.radius <= cpu.y2))
                {
                   
                    ball.x *= -1;
            
                }
                if ((ball.x + ball.radius >= player.x1) && (ball.y - ball.radius >= player.y1) && (ball.y + ball.radius <= player.y2))
                {
                 
                    ball.x *= -1;
                 
                }
                if (ball.x + ball.radius >= width)
                {
                    cpuScore++;
                    gameState = endgame;
                }
                else if  (ball.x - ball.radius <= 0)
                {          //horizontal collision
                    playerScore++;
                    gameState = endgame;
                }       
                DrawBall(ball);
                DrawPaddle(player);
                DrawPaddle(cpu);

                wait_msec(33000);   // 33ms = 30fps
                break;
            case endgame:
                if (playerScore == 1)   
                {
                    drawString(400, 100, "YOU WON!", WHITE, 4);
                    playerScore = 0;
                    cpuScore = 0; 
                }
                else if (cpuScore == 1)
                {
                    drawString(400, 100, "YOU LOSE!", WHITE, 4);
                    playerScore = 0;
                    cpuScore = 0;
                }
                drawString(280, 250, "Press Spacebar to play again!", YELLOW, 2);
                wait_msec(250000);  // 250ms
                drawString(280, 250, "Press Spacebar to play again!", BLACK, 2);
                wait_msec(250000);  // 250ms
                if (userInput == ' ')
                {
                    gameState = play;
                    gameini(&ball, &cpu, &player);
                    clearScreen();
                }
                break;
            default:
                gameState = menu;
                break;
        }
    }
}
