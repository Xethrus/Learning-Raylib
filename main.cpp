#include "raylib.h"
#include <vector>

const float SCREEN_WIDTH = 800;
const float SCREEN_HEIGHT = 800;
std::vector<Vector2> squarePositions;

class Ball
{
public:
    Vector2 ballPosition;
    const int BALL_SIZE;
    Ball(float x, float y, int size) : ballPosition{x, y}, BALL_SIZE{30} {};
};

void drawSquare(Vector2 square, Ball &ballP)
{

    DrawRectangle(square.x,square.y, ballP.BALL_SIZE, ballP.BALL_SIZE,BLACK);
}
void iteratePositions()
{
    for (const auto& s : squarePositions)
    {
        drawSquare(s, ball);
    }
}
Vector2 update(Ball &ballP)
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
        Vector2 squareP;
        squareP = ballP.ballPosition;
        squarePositions.push_back(squareP);
    }

    return ballP.ballPosition;
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

Ball ball; // the beginning of a new ball :D
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
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
        update(ball);
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
