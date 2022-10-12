#include <stdio.h>
#include "cprocessing.h"

#define GRID_SIZE 128
#define GRID_ROW 24
#define GRID_COL 24
double ROOM_HEIGHT = GRID_SIZE * GRID_ROW;
double ROOM_WIDTH = GRID_SIZE * GRID_COL;

struct entity { //we use entity as the default list of stats for all players and enemies.
    CP_Vector vector; //u can call for the x or y coords with .vector.x or .vector.y
    int HP;
    int DMG;
    int MOVE_SPEED;
};

struct entity player;

/*to define future enemies u can use :
struct entity enemy1;
struct entity enemy2;
...
..
and so on and so forth.
*/



/* 
    
    IMPORTANT THINGS TO NOTE:

The camera will move around and display everything in its scene and
subsequently, everything drawn will have its x and y coords artificially shifted

EVERYTHING that you use CP_DRAW for needs to have -camera1.x in its x coords. and -camera1.y in its y coords.

If the camera system is too complicated i can remove it and just stick to a non moving screen.

making sure the player is in the center of the view
so we first need the create an imaginary camera */

struct camera {
    double x;
    double y;
    int view_width; //view  width of the screen
    int view_height; //view height of the entire screen
    int camera_width; //camera width
    int camera_height; //camera height
};

struct camera camera1;


//Creating a Grid to work with in the future. (2D array)
GRID[GRID_COL][GRID_ROW];



//Setting Images for Assets
CP_Image PAWN;
CP_Image KNIGHT;
CP_Image BISHOP;
CP_Image ROOK;
CP_Image QUEEN;
CP_Image KING;





void game_init(void) {

    //loading in images
    PAWN = CP_Image_Load("/Assets/pawn.png");
    KNIGHT = CP_Image_Load("../Assets/knight.png");
    BISHOP = CP_Image_Load("../Assets/bishop.png");
    ROOK = CP_Image_Load("../Assets/rook.png");
    QUEEN = CP_Image_Load("../Assets/queen.png");
    KING = CP_Image_Load("../Assets/king.png");


    //putting the player in the center of the room
    player.vector.x = (float)ROOM_WIDTH / 2;
    player.vector.y = (float)ROOM_HEIGHT / 2;
    
    //setting player Stats
    player.DMG = 2;
    player.HP = 3;
    player.MOVE_SPEED = 10;

    //setting camera view width and heights
    camera1.view_height = GRID_SIZE * GRID_ROW / 3;
    camera1.view_width = GRID_SIZE * GRID_COL / 2;
    
    //setting window size
    CP_System_SetWindowSize(GRID_SIZE * GRID_ROW/2, GRID_SIZE * GRID_COL/3);

    //setting camera width and heights
    camera1.camera_width = camera1.view_width;
    camera1.camera_height = camera1.view_height;

}

void game_update(void) {


    //putting the camera at set distance from player and not exiting screen
    camera1.x = player.vector.x - camera1.camera_width/2;
    camera1.y = player.vector.y - camera1.camera_height/2;


    //limiting the camera so it doesn't go out of bounds
    if (camera1.x < 0) { camera1.x = 0; }
    if ((camera1.x+camera1.camera_width) > ROOM_WIDTH) { camera1.x = ROOM_WIDTH-camera1.view_width; }
    if (camera1.y < 0) { camera1.y = 0; }
    if ((camera1.y+camera1.camera_height) > ROOM_HEIGHT) { camera1.y = ROOM_HEIGHT-camera1.camera_height; }

    //limiting the player so it doesn't go out of bounds
    if (player.vector.x < 0) { player.vector.x = 0; }
    if (player.vector.x > ROOM_WIDTH) { player.vector.x = ROOM_WIDTH; }
    if (player.vector.y < 0) { player.vector.y = 0; }
    if (player.vector.y > ROOM_HEIGHT) { player.vector.y = ROOM_HEIGHT; }


    //drawing lines;
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    CP_Settings_Stroke(CP_Color_Create(255, 255, 255, 255));
    //From 131-136 got possible warning data loss can someone look into it?
    for (int row = 0; row <= GRID_ROW; row++) {
        CP_Graphics_DrawLine(row * GRID_SIZE -camera1.x, 0 -camera1.y, row * GRID_SIZE - camera1.x, GRID_COL * GRID_SIZE - camera1.y);
    }
    for (int col = 0; col <= GRID_COL; col++) {
        CP_Graphics_DrawLine(0 - camera1.x, col * GRID_SIZE - camera1.y, GRID_ROW * GRID_SIZE - camera1.x, col * GRID_SIZE - camera1.y);
    }


    //player WASD example
    if (CP_Input_KeyDown(KEY_A || KEY_LEFT)) {
        player.vector.x -=player.MOVE_SPEED;
    }
    if (CP_Input_KeyDown(KEY_D || KEY_RIGHT)) {
        player.vector.x += player.MOVE_SPEED;
    }
    if (CP_Input_KeyDown(KEY_W || KEY_UP)) {
        player.vector.y -= player.MOVE_SPEED;
    }
    if (CP_Input_KeyDown(KEY_S || KEY_DOWN)) {
        player.vector.y += player.MOVE_SPEED;
    }

    //Drawing player Example
    CP_Image_Draw(PAWN, player.vector.x- camera1.x, player.vector.y - camera1.y, GRID_SIZE, GRID_SIZE, 255);



}

void game_exit(void) {

    //freeing images
    CP_Image_Free(&PAWN);
    CP_Image_Free(&KNIGHT);
    CP_Image_Free(&BISHOP);
    CP_Image_Free(&ROOK);
    CP_Image_Free(&QUEEN);
    CP_Image_Free(&KING);



}
