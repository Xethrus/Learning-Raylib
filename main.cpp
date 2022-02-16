#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int ballSize = 30;
Vector2 startPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
Vector2 update(void)
{
    if (startPosition.y < screenHeight - ballSize)
    {
        if (IsKeyDown(KEY_DOWN))
            startPosition.y += 2.0f;
    }
    if (startPosition.y > ballSize)
    {
        if (IsKeyDown(KEY_UP))
            startPosition.y -= 2.0f;
    }
    if (startPosition.x > ballSize)
    {
        if (IsKeyDown(KEY_LEFT))
            startPosition.x -= 2.0f;
    }
    if (startPosition.x < screenWidth - ballSize)
    {
        if (IsKeyDown(KEY_RIGHT))
            startPosition.x += 2.0f;
    }
    return startPosition;
}
void render(void)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Move the ball with the arrow keys", startPosition.x - 150, startPosition.y + 50, 16, BLACK);
    DrawCircle(startPosition.x, startPosition.y, ballSize, BLUE);

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
        update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        render();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
