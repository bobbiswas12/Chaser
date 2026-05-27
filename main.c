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

float distance(particle p1, particle p2){

  float x = (p1.particle_position.x - p2.particle_position.x)*(p1.particle_position.x - p2.particle_position.x);
  float y = (p1.particle_position.y - p2.particle_position.y)*(p1.particle_position.y - p2.particle_position.y);

  return x + y;
}

bool closeenough(particle p1, particle p2){

  return (distance(p1,p2) > 625);
}

particle update(particle p1, float time){

  p1.particle_position.x += p1.particle_velocity.x * time;
  p1.particle_position.y += p1.particle_velocity.y * time;

  return p1;
}

void draw_particle(particle p1,float radius, Color color){

  DrawCircleV(p1.particle_position,radius,color);

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
    
    if (closeenough(object,chaser)){

      chaser = update(chaser,dt);
      draw_particle(chaser,12.5,RED);
      
    }
    else{
      
      draw_particle(chaser,50,YELLOW);
    }
    
    draw_particle(object,12.5,WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
