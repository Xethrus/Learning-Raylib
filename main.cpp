#include "raylib.h"
#include <vector>

const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 800;
class Ball
{
public:
    Vector2 ballPosition;
    const int BALL_SIZE;
    Ball(float x, float y, int size) : ballPosition{x, y}, BALL_SIZE{size} {};
};
class Square
{
public:
    Vector2 squarePosition;
    const int SQUARE_SIZE;
    Color SQUARE_COLOR = {0,0,0,255};
    Square(float x, float y, int size) : squarePosition{x,y}, SQUARE_SIZE{size} {};
};
std::vector<Square> squarePositions;
void drawSquare(const Square &squareP)
{
    DrawRectangle((int)squareP.squarePosition.x,(int)squareP.squarePosition.y, squareP.SQUARE_SIZE, squareP.SQUARE_SIZE, squareP.SQUARE_COLOR);
}
void iteratePositions()
{
    for (const auto& s : squarePositions)
    {
        drawSquare(s);
    }
}
void update(Ball &ballP, Square &squareP)
{
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
        Square square(ballP.ballPosition.x,ballP.ballPosition.y,30);
        squarePositions.push_back(square);
    }
};

void render(Ball &ballP)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Move the ball with the arrow keys", ballP.ballPosition.x - 150, ballP.ballPosition.y + 50, 16, BLACK);
    DrawCircle(ballP.ballPosition.x, ballP.ballPosition.y, ballP.BALL_SIZE, BLUE);
    iteratePositions();
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
    Vector2 startPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        update(ball, square);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        render(ball);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
