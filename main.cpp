#include "raylib.h"
#include <iostream>
#include <vector>

const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 800;
class Ball
{
public:
    Vector2 ballPosition;
    const float BALL_SIZE;
    Ball(float x, float y, float size) : ballPosition{x, y}, BALL_SIZE{size} {};
};
class Square
{
public:
    Vector2 squarePosition;
    float SQUARE_SIZE;
    Color SQUARE_COLOR = {0,0,0,255};
    Square(float x, float y, float size) : squarePosition{x,y}, SQUARE_SIZE{size} {};
};
//std::vector<Square> squarePositions;
void drawSquare(const Square &squareP, std::vector<Square> squarePositions)
{
    DrawRectangle((int)squareP.squarePosition.x,(int)squareP.squarePosition.y, (int)squareP.SQUARE_SIZE, (int)squareP.SQUARE_SIZE, squareP.SQUARE_COLOR);
}

void iteratePositions(std::vector<Square> squarePositions) //not sure if I should pass it here
{
    for (const auto& s : squarePositions)
    {
        drawSquare(s, squarePositions);
    }
}

void squareRight(std::vector<Square> &squarePositions){
    for (auto& s : squarePositions)
    {
        std::cout << s.squarePosition.x << std::endl;
        s.squarePosition.x += 100;
    }
}

void dealocateSquare(std::vector<Square> &squarePositions)
{
    auto iter = squarePositions.begin();
    while (iter != squarePositions.end())
    {
        if(iter->squarePosition.x > SCREEN_WIDTH)
        {
            iter = squarePositions.erase(iter);
        } else {++iter;}
    }
}

void update(Ball &ballP, std::vector<Square> &squarePositions) //passed it here- this kinda makes sense
{
    std::cout << squarePositions.size() << std::endl;
    if (ballP.ballPosition.y < SCREEN_HEIGHT - ballP.BALL_SIZE)
    {
        if (IsKeyDown(KEY_DOWN))
            ballP.ballPosition.y += 2.0f;
    }
    if (ballP.ballPosition.y > ballP.BALL_SIZE)
    {
        if (IsKeyDown(KEY_UP))
            ballP.ballPosition.y -= 2.0f;
    }
    if (ballP.ballPosition.x > ballP.BALL_SIZE)
    {
        if (IsKeyDown(KEY_LEFT))
            ballP.ballPosition.x -= 2.0f;
    }
    if (ballP.ballPosition.x < SCREEN_WIDTH - ballP.BALL_SIZE)
    {
        if (IsKeyDown(KEY_RIGHT))
            ballP.ballPosition.x += 2.0f;
    }
    if (IsKeyDown(KEY_SPACE))
    {
        Square square(ballP.ballPosition.x,ballP.ballPosition.y,30.0);
        squarePositions.push_back(square);
        std::cout << squarePositions.size() << std::endl;
    }
    iteratePositions(squarePositions);
    squareRight(squarePositions);
};

void render(Ball &ballP, std::vector<Square> &squarePositions)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Move the ball with the arrow keys", (int)ballP.ballPosition.x  - 150, (int)ballP.ballPosition.y + 50, 16, BLACK);
    DrawCircle((int)ballP.ballPosition.x, (int)ballP.ballPosition.y, ballP.BALL_SIZE, BLUE);
    EndDrawing();
}

Square square(0,0,30); // the beginning of a new ball :D
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    Ball ball(0,0,30);
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    //Vector2 startPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2}; if i ever want to use this
    std::vector<Square> squarePositions;
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        update(ball, squarePositions);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        render(ball, squarePositions); //currently does not do anything (need to pass in square s : squarePositions)
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
