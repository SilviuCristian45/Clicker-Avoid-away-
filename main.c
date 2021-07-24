/*
    taskkill /F /IM main.exe --- opreste procesul
*/

#include <stdio.h>
#include <stdarg.h>

#include <string.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0500 //constant used by getConsoleWindow

#include <Windows.h>
#include <conio.h>

int main(){
    POINT cursorPos;
    int cursorDistance = 5;

    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_MINIMIZE );  //won't hide the window without SW_MINIMIZE
    ShowWindow( hWnd, SW_HIDE );

    while (1){
        if(GetCursorPos(&cursorPos)){ //if the GetCursorPos function returned true and it works perfectly
            int currentCursorX = cursorPos.x , currentCursorY = cursorPos.y;
            //printf("current mouse pos : x - %d| y - %d", currentCursorX, currentCursorY);

            SetCursorPos(currentCursorX + cursorDistance, currentCursorY + cursorDistance); //set the position of cursor 
            cursorDistance *= -1; //multiply with -1 because we want to move the cursor above and below with that distance

            Sleep(1000); //sleep the program for 1 second
        }
        else {
            printf("couldn't get cursor Pos");
        } 
    }
    
    return 0;
}
