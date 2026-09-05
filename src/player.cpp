#include "player.h"
#include <graphx.h>
#include <keypadc.h>
#include <stdlib.h>

void updatePlayer(float dt){
if (kb_Data[7] & kb_Left)
        {
            if (velocityX > -300.0f)
            {
                velocityX -= 600.0f * dt;
             if(velocityX < -300.0f){
                    velocityX = -300.0f;
                }
            }
        }
        else if (kb_Data[7] & kb_Right)
        {
            if (velocityX < 300.0f)
            {
                velocityX += 600.0f * dt;
                if(velocityX > 300.0f){
                    velocityX = 300.0f;
                }
            }
        }
        else
        {
            if (velocityX > 0)
            {
                velocityX -= 1800.0f * dt;
                if(velocityX <= 0){
                    velocityX = 0;
                }
            }
            else if (velocityX < 0)
            {
                velocityX += 1800.0f * dt;
                if(velocityX >= 0){
                    velocityX = 0;
                }
            }
        }

        if (kb_Data[7] & kb_Up)
        {
            if (velocityY > -300.0f)
            {
                velocityY -= 600.0f * dt;
                if(velocityY < -300.0f){
                    velocityY = -300.0f;
                }
            }
        }
        else if (kb_Data[7] & kb_Down)
        {
            if (velocityY < 300.0f)
            {
                velocityY += 600.0f * dt;
                if(velocityY > 300.0f){
                    velocityY = 300.0f;
                }
            }
        }
        else if (velocityY > 0)
        {
            velocityY -= 1800.0f * dt;
            if(velocityY <= 0){
                    velocityY = 0;
                }
        }
        else if (velocityY < 0)
        {
            velocityY += 1800.0f * dt;
            if(velocityY >= 0){
                    velocityY = 0;
                }
        }

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
}