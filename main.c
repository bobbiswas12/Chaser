#include <stdio.h>
#include "raylib.h"

#define screen_width 800
#define screen_height 600

int main(){


  InitWindow(screen_width,screen_height,"Chaser");
  Vector2 chaser_position = (Vector2) {400,20};
  SetTargetFPS(60);
  while (!WindowShouldClose()){
    
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10,10);
    Vector2 mouse_position = GetMousePosition();
    float dt = GetFrameTime();
    Vector2 velocity = (Vector2) {(mouse_position.x - chaser_position.x) , mouse_position.y - chaser_position.y};
    
    float distance = (mouse_position.x - chaser_position.x)*(mouse_position.x - chaser_position.x) + (mouse_position.y - chaser_position.y)*(mouse_position.y - chaser_position.y);
    
    if (distance > 625){

      chaser_position.x += velocity.x * dt;
      chaser_position.y += velocity.y * dt;

      DrawCircleV(chaser_position,12.5,RED);
    }
    else{
      DrawCircleV(chaser_position, 50, YELLOW);
    }    
    DrawCircleV(mouse_position,12.5,WHITE);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
