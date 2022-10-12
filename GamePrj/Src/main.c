#include "cprocessing.h"

#include "../Inc/menu.h"




/* Entry point */
int main(void)
{
    CP_Engine_SetNextGameState(menu_init, menu_update, menu_exit);
    CP_Engine_Run();
    return 0;
}
