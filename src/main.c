#include <graphx.h>
#include <keypadc.h>
#include <stdlib.h>

bool running = true;

int x = 160;
int y = 1;

/* Main function, called first */
int main(void)
{
    while (running) {
        gfx_Begin();
        gfx_SetDrawBuffer();
        gfx_SetColor(0);
gfx_FillRectangle(0, 0, 320, 240);
        gfx_SetColor(255);
        gfx_FillRectangle(x, y, 30, 30);

    kb_Scan();

    if (kb_Data[7] & kb_Right) {
    gfx_SetColor(255);
    gfx_FillRectangle(x, y += 2, 30, 30);
    }

    if (kb_Data[7] & kb_Left) {
       
        running = false;
    }
}
    gfx_End();
    return 0;
}
