#include<iostream>
#include<graphics.h>
#include<windows.h>

int main() {

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth,screenHeight,"",-3,-3);

    int page=0, barX=200;

    int x=50,y=100;
    circle(x,y,50);

    while(1) {

        if(GetAsyncKeyState(VK_RIGHT)) {

        cleardevice();circle(++x,y,50);
        }
        if(GetAsyncKeyState(VK_LEFT)) {

        cleardevice();
            circle(--x,y,50);
        }
        if(GetAsyncKeyState(VK_SPACE)) {

            for(int i=0; i<50;i++) {
                    if(GetAsyncKeyState(VK_RIGHT)) {

        cleardevice();circle(++x,y,50);
        }
                    cleardevice();
                    circle(x,--y,50);
                    delay(5);
            }
            for(int i=0; i<50;i++) {
                    cleardevice();
                    circle(x,++y,50);
                    delay(5);
            }


        }
        delay(5);
    }
}
