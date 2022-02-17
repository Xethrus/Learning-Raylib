#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int ballSize = 30;

class Ball {
    public:
    Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
};
Vector2 update(Ball& ballP) {
    if (ballP.ballPosition.y < screenHeight - ballSize)
    {
        if (IsKeyDown(KEY_DOWN))
            ballP.ballPosition.y += 2.0f;
    }
    if (ballP.ballPosition.y > ballSize)
    {
        if (IsKeyDown(KEY_UP))
            ballP.ballPosition.y -= 2.0f;
    }
    if (ballP.ballPosition.x > ballSize)
    {
        if (IsKeyDown(KEY_LEFT))
            ballP.ballPosition.x -= 2.0f;
    }
    if (ballP.ballPosition.x < screenWidth - ballSize)
    {
        if (IsKeyDown(KEY_RIGHT))
            ballP.ballPosition.x += 2.0f;
    }
    return ballP.ballPosition;
};
void render(Ball& ballP)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Move the ball with the arrow keys", ballP.ballPosition.x - 150, ballP.ballPosition.y + 50, 16, BLACK);
    DrawCircle(ballP.ballPosition.x, ballP.ballPosition.y, ballSize, BLUE);

    EndDrawing();
}
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Vector2 startPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        Ball ball;
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
