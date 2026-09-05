#include <graphx.h>
#include <keypadc.h>
#include <sys/timers.h>
#include <ctime.h>
#include <stdlib.h>

int playerX = 160;
int playerY = 120;
int velocityX = 0;
int velocityY = 0;

/* Main function, called first */
int main(void)
{

    gfx_Begin();
    gfx_SetDrawBuffer();

    kb_SetMode(MODE_3_CONTINUOUS);

    clock_t previousTime = clock();

    while (!(kb_Data[6] & kb_Clear))
    {

        if (kb_Data[7] & kb_Left)
        {
            if (velocityX > -5)
            {
                velocityX -= 1;
            }
        }
        else if (kb_Data[7] & kb_Right)
        {
            if (velocityX < 5)
            {
                velocityX += 1;
            }
        }
        else
        {
            if (velocityX > 0)
            {
                velocityX -= 1;
            }
            else if (velocityX < 0)
            {
                velocityX += 1;
            }
        }

        if (kb_Data[7] & kb_Up)
        {
            if (velocityY > -5)
            {
                velocityY -= 1;
            }
        }
        else if (kb_Data[7] & kb_Down)
        {
            if (velocityY < 5)
            {
                velocityY += 1;
            }
        }
        else if (velocityY > 0)
        {
            velocityY -= 1;
        }
        else if (velocityY < 0)
        {
            velocityY += 1;
        }
        
        clock_t currentTime = clock();

    clock_t elapsed = currentTime - previousTime;

    float dt = static_cast<float>(elapsed) / CLOCKS_PER_SEC;

    previousTime = currentTime;
    

        playerX += velocityX * dt;
        playerY += velocityY * dt;

        if (playerX > 300)
        {
            playerX = 300;
            if (velocityX > 0)
                velocityX = 0;
        }
        else if (playerX < 0)
        {
            playerX = 0;
            if (velocityX < 0)
                velocityX = 0;
        }

        if (playerY > 220)
        {
            playerY = 220;
            if (velocityY > 0)
                velocityY = 0;
        }
        else if (playerY < 0)
        {
            playerY = 0;
            if (velocityY < 0)
                velocityY = 0;
        }
        

        gfx_FillScreen(0);
        gfx_SetColor(255);
        gfx_FillRectangle(playerX, playerY, 30, 30);

        gfx_SwapDraw();

        


    }
    gfx_End();
    return 0;
}
