#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<thread>

using namespace std;

int x=50,y=100;

class Mario {
public:
    void moveRight() {
        while(true) {
            if(GetAsyncKeyState(VK_RIGHT)) {
            cout<<"Right";
            cleardevice();
            circle(++x,y,50);
            }
            delay(3);
        }
    }
    void moveLeft() {
        while(true) {
            if(GetAsyncKeyState(VK_LEFT)) {
            cout<<"Left";
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

int main() {

    //Getting the screen dimensions
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth,screenHeight,"",-3,-3);

    int page=0;


    circle(x,y,50);

    Mario mario;

    thread t1(Mario::moveLeft,mario);
    thread t2(Mario::moveRight,mario);
    thread t3(Mario::jump,mario);

    t1.join();



}
