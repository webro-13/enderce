#include <graphx.h>
#include <stdlib.h>

bool key, prevkey;
key = kb_Data[1] == kb_2nd;

bool key2, prevkey2;
key2 = kb_Data[1] == kb_clear;

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


    if (key && !prevkey) {
    gfx_FillRectangle(x, y += 2, 30, 30);
    }
    prevkey = key;

    if (key2 && !prevkey2) {
        gfx_End();
        running = false;
    }
    prevkey2 = key2;
}

    return 0;
}
