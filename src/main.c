#include <graphx.h>
#include <keypadc.h>
#include <sys/timers.h>
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

        if (playerX >= 300)
        {
            playerX = 300;
            velocityX = 0;
        }
        else if (playerX <= 0)
        {
            playerX = 0;
            velocityX = 0;
        }

        if (playerY >= 220)
        {
            playerY = 220;
            velocityY = 0;
        }
        else if (playerY <= 0)
        {
            playerY = 0;
            velocityY = 0;
        }

        playerX += velocityX;
        playerY += velocityY;

        gfx_Fillscreen(0);
        gfx_SetColor(255);
        gfx_FillRectangle(playerX, playerY, 30, 30);

        gfx_SwapDraw();
        delay(16);
    }
    gfx_End();
    return 0;
}
