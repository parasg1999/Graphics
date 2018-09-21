#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<thread>

using namespace std;

int bgColor = COLOR(0, 138, 197);

int x=50,y=100;

class Mario {
public:
    Mario() {
        setbkcolor(bgColor);
    }
    void moveRight() {
        while(true) {
            if(GetAsyncKeyState(VK_RIGHT)) {
            cleardevice();
            circle(++x,y,50);
            }
            delay(3);
        }
    }
    void moveLeft() {
        while(true) {
            if(GetAsyncKeyState(VK_LEFT)) {
            cleardevice();
            circle(--x,y,50);
            }
            delay(3);
        }
    }
    void jump() {
        while(true) {
            if(GetAsyncKeyState(VK_SPACE)) {
                for(int i=0; i<50;i++) {
                    cleardevice();
                    circle(x,--y,50);
                    delay(3);
                }
                for(int i=0; i<50;i++) {
                    cleardevice();
                    circle(x,++y,50);
                    delay(3);
                }
            }
            delay(5);
        }
    }

};

class Brick {
public:
    Brick() {
        //setcolor(BROWN);
        while(true) {
        setfillstyle(INTERLEAVE_FILL, RED);
        bar(100,100,140,140);
        }
    }

};

int main() {

    //Getting the screen dimensions
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth,screenHeight,"",-3,-3);

    int page=0;

    Mario mario;

    circle(x,y,50);

    thread t1(Mario::moveLeft,mario);
    thread t2(Mario::moveRight,mario);
    thread t3(Mario::jump,mario);
   // thread t4(Mario::backgroundColor,mario);

    Brick b1;

    t3.join();

    getch();

}
