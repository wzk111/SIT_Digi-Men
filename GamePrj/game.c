#include <stdio.h>
#include "cprocessing.h"

#define GRID_SIZE 64
#define GRID_ROW 48
#define GRID_COL 48
double ROOM_HEIGHT = GRID_SIZE * GRID_ROW;
double ROOM_WIDTH = GRID_SIZE * GRID_COL;

struct entity { //we use entity as the default list of stats for all players and enemies.
    CP_Vector vector; //u can call for the x or y coords with .vector.x or .vector.y
    int HP;
    int DMG;
    int MOVE_SPEED;
};

struct entity Player;

/*to define future enemies u can use :
struct entity enemy1;
struct entity enemy2;
...
..
and so on and so forth.
*/

//making sure the player is in the center of the view
//so we first need the create an imaginary camera
struct camera {
    double x;
    double y;
    int view_width; //view  width of the screen
    int view_height; //view height of the entire screen
    int camera_width; //camera width
    int camera_height; //camera height
};



/* 
    
    IMPORTANT THINGS TO NOTE:

The camera will move around and display everything in its scene and
subsequently, everything drawn will have its x and y coords artificially shifted

EVERYTHING that you use CP_DRAW for needs to have -camera1.x in its x coords. and -camera1.y in its y coords.

If the camera system is too complicated i can remove it and just stick to a non moving screen.

*/





struct camera camera1;

void game_init(void) {

    //putting the player in the center of the room
    Player.vector.x = ROOM_WIDTH / 2;
    Player.vector.y = ROOM_HEIGHT / 2;

    camera1.view_height = GRID_SIZE * GRID_ROW / 2;
    camera1.view_width = GRID_SIZE * GRID_COL / 3;
    
    CP_System_SetWindowSize(GRID_SIZE * GRID_ROW/2, GRID_SIZE * GRID_COL/3);

    camera1.camera_width = camera1.view_width;
    camera1.camera_height = camera1.view_height;

}

void game_update(void) {


    //putting the camera at set distance from player and not exiting screen
    camera1.x = Player.vector.x - camera1.camera_width/1.5;
    camera1.y = Player.vector.y - camera1.camera_height/3;



    //limiting the player so it doesn't go out of bounds
    if (Player.vector.x < 0) { Player.vector.x = 0; }
    if (Player.vector.x > ROOM_WIDTH) { Player.vector.x = ROOM_WIDTH; }
    if (Player.vector.y < 0) { Player.vector.y = 0; }
    if (Player.vector.y > ROOM_HEIGHT) { Player.vector.y = ROOM_HEIGHT; }


    //drawing grid;
    CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));
    for (int row = 0; row <= GRID_ROW; row++) {
        CP_Graphics_DrawLine(row * GRID_SIZE -camera1.x, 0 -camera1.y, row * GRID_SIZE -camera1.x, GRID_COL * GRID_SIZE - camera1.y);
    }
    for (int col = 0; col <= GRID_COL; col++) {
        CP_Graphics_DrawLine(0 - camera1.x, col * GRID_SIZE - camera1.y, GRID_ROW * GRID_SIZE - camera1.x, col * GRID_SIZE - camera1.y);
    }



    //Player WASD example
    if (CP_Input_KeyDown(KEY_A)) {
        Player.vector.x -= 20;
    }
    if (CP_Input_KeyDown(KEY_D)) {
        Player.vector.x += 20;
    }
    if (CP_Input_KeyDown(KEY_W)) {
        Player.vector.y -= 20;
    }
    if (CP_Input_KeyDown(KEY_S)) {
        Player.vector.y += 20;
    }

    //Drawing Player Example
    CP_Graphics_DrawCircle(Player.vector.x - camera1.x, Player.vector.y - camera1.y, 32);


}

void game_exit(void) {

}
