#include <stdio.h>
#include "raylib.h"
#include <math.h>
#define screen_width 800
#define screen_height 600

typedef struct{

  Vector2 particle_position;
  Vector2 particle_velocity;
  float particle_radius;
  
}particle;

float distance(Vector2 position1, Vector2 position2){

  float x = (position1.x - position2.x)*(position1.x - position2.x);
  float y = (position1.y - position2.y)*(position1.y - position2.y);

  return x + y;
}


int main(){
  

  InitWindow(screen_width,screen_height,"Chaser");

  particle object;
  particle chaser;
  
  chaser.particle_position = (Vector2) {400,20};
  SetTargetFPS(60);
  
  while (!WindowShouldClose()){
    
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10,10);
    object.particle_position = GetMousePosition();
    float dt = GetFrameTime();
    chaser.particle_velocity = (Vector2) {(object.particle_position.x - chaser.particle_position.x) , (object.particle_position.y - chaser.particle_position.y)};
    
    float dist = distance(object.particle_position,chaser.particle_position);
    if (dist > 625){

      chaser.particle_position.x += chaser.particle_velocity.x * dt;
      chaser.particle_position.y += chaser.particle_velocity.y * dt;

      DrawCircleV(chaser.particle_position,12.5,RED);
    }
    else{
      DrawCircleV(chaser.particle_position, 50, YELLOW);
    }    
    DrawCircleV(object.particle_position,12.5,WHITE);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
