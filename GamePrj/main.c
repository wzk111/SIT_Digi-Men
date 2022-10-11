#include "cprocessing.h"


/* Forward declarations */
void menu_init(void);
void menu_update(void);
void menu_exit(void);

void char_select_init(void);
void char_select_update(void);
void char_select_exit(void);

void settings_init(void);
void settings_update(void);
void settings_exit(void);

void game_init(void);
void game_update(void);
void game_exit(void);

/* Entry point */
int main(void)
{
    CP_Engine_SetNextGameState(game_init, game_update, game_exit);
    CP_Engine_Run();
    return 0;
}
