#include <graphx.h>
#include <keypadc.h>
#include <stdlib.h>

bool running = true;

int x = 160;
int y = 1;

/* Main function, called first */
int main(void)
{
    
    gfx_Begin();
    gfx_SetDrawBuffer();

    kb_SetMode(MODE_3_CONTINUOUS);


    while (running) {
        
    if (kb_Data[7] & kb_Right) {
        y += 2
    }

    if (kb_Data[7] & kb_Left) {
       
        running = false;
    }

    gfx_Fillscreen(0);
    gfx_SetColor(255);
    gfx_FillRectangle(x, y, 30, 30);

    gfx_SwapDraw();
}
    gfx_End();
    return 0;
}
