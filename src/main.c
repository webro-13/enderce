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
    gfx_FillRectangle(x, y, 30, 30);

    kb_Scan();

    if (kb_Data[7] & kb_2nd) {
    gfx_FillRectangle(x, y += 2, 30, 30);
    }

    if (kb_Data[7] & kb_Clear) {
       
        running = false;
    }
}
    gfx_End();
    return 0;
}
