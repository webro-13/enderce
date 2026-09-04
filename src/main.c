#include <graphx.h>
#include <stdlib.h>


int x = 0;
int y = 0;

/* Main function, called first */
int main(void)
{
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_FillRectangle(160, 120, 30, 30);

    return 0;
}
