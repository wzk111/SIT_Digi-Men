#include <stdio.h>
#include "cprocessing.h"
//#include "menu_utils.h"
#define GRID_COLS 30 
#define GRID_ROWS 30 

#include "../Inc/game.h"
CP_Image Logo1;
float grid_size = 30;
float sizegrid = 134;
void menu_init(void) {

	float textSize;

	//CP_System_SetWindowSize(980, 624);

	CP_Graphics_ClearBackground(CP_Color_Create(227, 193, 111, 255));  // warm beach colour (remind self to grid the back ground)
	textSize = 65.0f;
	CP_Settings_TextSize(textSize);

	Logo1 = CP_Image_Load("Assets/");// add images to BG load assets from the file

	CP_System_SetWindowSize(GRID_ROWS * 40, GRID_COLS * 30);
}

void menu_update(void) {

	CP_Graphics_ClearBackground(CP_Color_Create(227, 193, 111, 255)); // beach colour BG
	for (int row = 0; row < GRID_ROWS; ++row) {

		CP_Graphics_DrawLine(row * sizegrid, 0, row * sizegrid, GRID_COLS * sizegrid);

	}
	for (int col = 0; col < GRID_COLS; ++col) {

		CP_Graphics_DrawLine(0, col * sizegrid, GRID_ROWS * sizegrid, col * sizegrid);
	}


	//button for tutorial(sizes,position,shape)
	CP_Settings_RectMode(CP_POSITION_CENTER);

	CP_Settings_Fill(CP_Color_Create(184, 139, 74, 255));

	float button_width = CP_System_GetWindowWidth() / 4.0f;
	float button_height = CP_System_GetWindowHeight() / 6.0f;

	float play_button_x = CP_System_GetWindowWidth() / 3.5f;
	float play_button_y = CP_System_GetWindowHeight() / 3.5f;

	float exit_button_x = CP_System_GetWindowWidth() / 3.5f;
	float exit_button_y = CP_System_GetWindowHeight() / 1.5f;

	float tutorial_button_x = CP_System_GetWindowWidth() / 1.5f;
	float tutorial_button_y = CP_System_GetWindowWidth() / 4.7f;

	float setting_button_x = CP_System_GetWindowWidth() / 1.5f;
	float setting_button_y = CP_System_GetWindowHeight() / 1.5f; // setting buttion still empty (for sound adjsutments)

	//rounded rects
	CP_Graphics_DrawRectAdvanced(play_button_x, play_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(exit_button_x, exit_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(tutorial_button_x, tutorial_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(setting_button_x, setting_button_y, button_width, button_height, 0.0, 20.0);

	//text colour
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	CP_Font_DrawText("PLAY", play_button_x, play_button_y);
	CP_Font_DrawText("EXIT", exit_button_x, exit_button_y);
	CP_Font_DrawText("TUTORIAL", tutorial_button_x, tutorial_button_y);
	CP_Font_DrawText("SETTINGS", setting_button_x, setting_button_y);

		// function for 4 buttons on main menu
	if (IsAreaClicked(play_button_x, play_button_y, button_width, button_height, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
		CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		CP_Engine_Run();
	}
	
	else if (IsAreaClicked(exit_button_x, exit_button_y, button_width, button_height, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
		CP_Engine_Terminate();
	}
	
	else if (IsAreaClicked(tutorial_button_x, tutorial_button_y, button_width, button_height, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

		//CP_Engine_SetNextGameState();// set function and description for tutorial
		//CP_Engine_Run();
		CP_Engine_Terminate();
	}
	
	else if (IsAreaClicked(setting_button_x, setting_button_y, button_width, button_height, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

		//CP_Engine_SetNextGameState();// set function for setting (sound adjustment)
		//CP_Engine_Run();
		CP_Engine_Terminate();

	}

}


void menu_exit(void) {

}


