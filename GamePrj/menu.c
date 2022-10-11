#include <stdio.h>
#include "cprocessing.h"
#include "char_select.c"

CP_Image Logo1;


void menu_init(void) {

	float textSize;

	CP_System_SetWindowSize(980, 624);

	CP_Graphics_ClearBackground(CP_Color_Create(227, 193, 111, 255));  // warm beach colour (remind self to grid the back ground)
	textSize = 120.0f;
	CP_Settings_TextSize(textSize);

	Logo1 = CP_Image_Load("Assets/")// add images to BG load assets from the file

}

void menu_update(void) {

	CP_Graphics_ClearBackground(CP_Color_Create(227, 193, 111, 255)); // beach colour BG


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
	float tutorial_button_y = CP_System_GetWindowWidth() / 3.5f;

	float setting_button_x = CP_System_GetWindowWidth() / 1.5f;
	float setting_button_y = CP_System_GetWindowHeight() / 1.5f; // setting buttion still empty (for sound adjsutments)

	//rounded rects
	CP_Graphics_DrawRectAdvanced(play_button_x, play_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(exit_button_x, exit_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(tutorial_button_x, tutorial_button_y, button_width, button_height, 0.0, 20.0);
	CP_Graphics_DrawRectAdvanced(setting_button_x, setting_button_y, button_width, button_height, 0.0, 20.0);

	//text colour
	CP_Settings_Fill(CP_Color_Create(0, 139, 74, 255));
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	CP_Font_DrawText("PLAY", play_button_x, play_button_y);
	CP_Font_DrawText("EXIT", exit_button_x, exit_button_y);
	CP_Font_DrawText("TUTORIAL", tutorial_button_x, tutorial_button_y);
	CP_Font_DrawText("SETTINGS", setting_button_x, setting_button_y);

		// function for 4 buttons on main menu
	if (IsAreaClicked(play_button_x, play_button_y, button_width, button_height, 0.0, 20.0, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
		

		CP_Engine_SetNextGameState(char_select_init, char_select_update, char_select_exit);
		CP_Engine_Run();
	}
	
	else if (IsAreaClicked(exit_button_x, exit_button_y, button_width, button_height, 0.0, 20.0, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {
		CP_Engine_Terminate();
	}
	
	else if (IsAreaClicked(tutorial_button_x, tutorial_button_y, button_width, button_height, 0.0, 20.0, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

	    CP_Engine_SetNextGameState()// set function and description for tutorial
		CP_Engine_Run();
	}
	
	else if (IsAreaClicked(setting_button_x, setting_button_y, button_width, button_height, 0.0, 20.0, CP_Input_GetMouseX(), CP_Input_GetMouseY())) {

		CP_Engine_SetNextGameState()// set function for setting (sound adjustment)
		CP_Engine_Run();

	}

	else {
		return 0;
	}

}


void menu_exit(void) {

}

//function for button click
int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)//
{

	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT)) {
		if ((area_center_x - area_width / 2) < click_x && click_x < (area_center_x + area_width / 2) && (area_center_y - area_height / 2) < click_y && click_y < (area_center_y + area_height / 2)) {

			return 1;
		}
		else {
			return 0;
		}
	}
}
