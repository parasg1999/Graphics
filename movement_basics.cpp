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
class Brick{
public:
 int x,y;
 void showBrick(int x,int y){
setcolor(RGB(141,79,58));
rectangle(x-20,y-20,x+20,y+20);
setfillstyle(SOLID_FILL,RGB(141,79,58));
floodfill(x,y,RGB(141,79,58));
setcolor(BLACK);
line(x-20,y-10,x+20,y-10);
line(x-20,y,x+20,y);
line(x-20,y+10,x+20,y+10);
line(x-10,y-10,x-10,y);
line(x+10,y-10,x+10,y);
line(x,y,x,y+10);
line(x-10,y+10,x-10,y+20);
line(x+10,y+10,x+10,y+20);
line(x,y-10,x,y-20);
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
    b1.showBrick(45,89);
    t3.join();

    getch();

}
