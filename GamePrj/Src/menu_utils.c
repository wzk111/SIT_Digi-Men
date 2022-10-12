#include "cprocessing.h"

//function for button click
int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
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