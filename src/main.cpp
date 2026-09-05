#include <graphx.h>
#include <keypadc.h>
#include <sys/timers.h>
#include <ctime>
#include <stdlib.h>

float playerX = 160;
float playerY = 120;
float velocityX = 0;
float velocityY = 0;

/* Main function, called first */
int main(void)
{

    gfx_Begin();
    gfx_SetDrawBuffer();

    kb_SetMode(MODE_3_CONTINUOUS);

    clock_t previousTime = clock();

    while (!(kb_Data[6] & kb_Clear))
    {

    clock_t currentTime = clock();

    clock_t elapsed = currentTime - previousTime;

    float dt = static_cast<float>(elapsed) / CLOCKS_PER_SEC;

    previousTime = currentTime;
        
    updatePlayer(dt);

        gfx_FillScreen(0);
        gfx_SetColor(255);
        gfx_FillRectangle(playerX, playerY, 30, 30);

        gfx_SwapDraw();

        


    }
    gfx_End();
    return 0;
}
