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
 * 
*/
void UpdateBall(Ball *ball, Paddle *paddle) 
{           //GetScreenHeight->actual boundary value
    drawCircle(ball->x, ball->y, ball->radius, BLACK, 1);
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if ((ball->y + ball->radius >= height) || (ball->y - ball->radius <= 0)) 
    {          //vertical collision
        ball->speed_y *= -1;
    }
    for (int i = 0; i < 2; i++)
    {
        if (collision(ball, paddle[i])) 
        {
            if (ball->speed_x < 0)  // ball is moving left
            {
                ball->speed_x -= 1; 
            }
            else                    // ball is moving right
            {
                ball->speed_x += 1;
            }
            ball->speed_x *= -1;

            // change vertical velocity
            int hit_pos = (paddle[i].y2 - ball->y);

            // the paddle length is 180, divided it into 5 region
            if (hit_pos >= 0 && hit_pos < 36)
            {
                ball->speed_y = 10;
            }

            if (hit_pos >= 36 && hit_pos < 72)
            {
                ball->speed_y = 5;
            }
            
            if (hit_pos >= 72 && hit_pos < 108)
            {
                ball->speed_y = 0;
            }
            
            if (hit_pos >= 108 && hit_pos < 144)
            {
                ball->speed_y = -5;
            }
            
            if (hit_pos >= 144 && hit_pos < 180)
            {
                ball->speed_y = -10;
            }
        }   
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
        if (paddle[0].y1 >= 0)    // limit paddle movement to screen boundary
        {
            drawRect(paddle[0].x1, paddle[0].y1, paddle[0].x2, paddle[0].y2, BLACK, 1);
            paddle[0].y1 -= paddle[0].speed;
            paddle[0].y2 -= paddle[0].speed;
        }
    }

    if (userInput == 's') 
    {          //if (IsKeyDown(KEY_DOWN))
        if (paddle[0].y2 <= height)  // limit paddle movement to screen boundary
        {
            drawRect(paddle[0].x1, paddle[0].y1, paddle[0].x2, paddle[0].y2, BLACK, 1);
            paddle[0].y1 += paddle[0].speed;
            paddle[0].y2 += paddle[0].speed;
        }
    }
}

/**
 * Update CPU paddle position
*/
void UpdateCpuPaddle(Paddle *paddle, int ball_y) 
{
    //CpuPaddle paddle = &(cpu->paddle);
    if (paddle[1].y1 > ball_y) 
    {
        if (paddle[1].y1 >= 0)   // limit paddle movement to screen boundary
        {
            drawRect(paddle[1].x1, paddle[1].y1, paddle[1].x2, paddle[1].y2, BLACK, 1);
            paddle[1].y1 -= paddle[1].speed;
            paddle[1].y2 -= paddle[1].speed;
        }
    }
    if (paddle[1].y2 < ball_y) 
    {
        if (paddle[1].y2 <= height) // limit paddle movement to screen boundary
        {
            drawRect(paddle[1].x1, paddle[1].y1, paddle[1].x2, paddle[1].y2, BLACK, 1);
            paddle[1].y1 += paddle[1].speed;
            paddle[1].y2 += paddle[1].speed;
        }
    }
}


/**
 * Check for collision 
*/
int collision(Ball *ball, Paddle rect)
{
    int ball_left = ball->x - ball->radius;
    int ball_right = ball->x + ball->radius;
    int ball_top = ball->y - ball->radius;
    int ball_bottom = ball->y + ball->radius;

    if (ball_left > rect.x2)
    {
        return 0;
    }

    if (ball_right < rect.x1)
    {
        return 0;
    }

    if (ball_top > rect.y2)
    {
        return 0;
    }

    if (ball_bottom < rect.y1)
    {
        return 0;
    }
    return 1;
}

/**
 * Initialize the game with default parameters
*/
void gameini(Ball *ball, Paddle *paddle)
{
    //ball.radius = 20;
    ball->x = width / 2;
    ball->y = height / 2;
    ball->radius = 10;
    ball->speed_x = 10;
    ball->speed_y = 10;                   //checkpoint 1, Ball done

    //player.width = 20;
    //player.height = 180;
    paddle[0].x1 = width- 25;
    paddle[0].y1 = height / 2 - 180 / 2;
    paddle[0].x2 = width- 5;
    paddle[0].y2 = height / 2 + 180 / 2;
    paddle[0].speed = 20;                   // player Paddle done

    //cpu.paddle.width = 20;
    //cpu.paddle.height = 180;
    paddle[1].x1 = 5;
    paddle[1].y1 = height/ 2 - 180 / 2;
    paddle[1].x2 = 5 + 20;
    paddle[1].y2 = height/ 2 + 180 / 2;
    paddle[1].speed = 20;  
}


/**
 * Game main program
*/
void game() 
{
    uart_puts("SaltOS> Welcome to Pong! Press 'c' to return to CLI");
    clearScreen();
    Ball ball;
    // Paddle player;
    // Paddle cpu;
    Paddle player[2]; // 0 = player, 1 = cpu

    userInput = 0;
    int playerScore = 0;
    int cpuScore = 0;

    gameini(&ball, player);
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
                DrawPaddle(player[0]);
                DrawPaddle(player[1]);
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
                UpdateBall(&ball, player);
                UpdatePaddle(player);
                UpdateCpuPaddle(player, ball.y);
            
                /* Check for edge collisions */
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
                DrawPaddle(player[0]);
                DrawPaddle(player[1]);

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
                    gameini(&ball, player);
                    clearScreen();
                }
                break;
            default:
                gameState = menu;
                break;
        }
    }
}
