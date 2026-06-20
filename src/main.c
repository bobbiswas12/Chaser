
/* A Chaser, it chases you! */
/* Copyright (C) 2026  Tanmay Rai */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/*    (at your option) any later version. */

/*    This program is distributed in the hope that it will be useful, */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*    GNU General Public License for more details. */

/*    You should have received a copy of the GNU General Public License */
/*    along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "raylib.h"

#define screen_width 800
#define screen_height 600
#define fps 60

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
  SetTargetFPS(fps);
  
  while (!WindowShouldClose()){
    
    BeginDrawing();
    ClearBackground(BLACK);
    
    DrawFPS(10,10);
    
    object.particle_position = GetMousePosition();
    
    float dt = GetFrameTime();
    
    chaser.particle_velocity = (Vector2) { (object.particle_position.x - chaser.particle_position.x) , (object.particle_position.y - chaser.particle_position.y)};
    
    if (closeenough(object,chaser)){

      chaser = update(chaser,dt);
      draw_particle(chaser,12.5,RED);
      
    }
    else{
      
      draw_particle(chaser,50,YELLOW);
    }
    
    draw_particle(object,12.5,WHITE);
    DrawText(TextFormat("Current Distance: %d", (int) distance(chaser,object)),10,40,20,GREEN);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
