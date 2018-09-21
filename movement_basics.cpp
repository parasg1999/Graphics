#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<thread>

using namespace std;

int bgColor = COLOR(0, 138, 197);

int x=50,y=100;


class Brick{
public:
 int x,y;
 void showBrick(){
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
Brick(int a,int b){
x=a;
y=b;}
};

class pipe{
public:
    int x,y;
    void showMediumPipe(){
        setcolor(RGB(51,127,95));
        rectangle(x-40,y-80,x+40,y);
rectangle(x-45,y-120,x+45,y-80);
setfillstyle(SOLID_FILL,RGB(189,255,24));
floodfill(x,y-20,RGB(51,127,95));
floodfill(x,y-100,RGB(51,127,95));
setcolor(RGB(0,173,0));
for(int i=4;i<25;i++){
    line(x+i,y-120,x+i,y);
}
for(int i=4;i<10;i++){
    line(x-30+i,y-120,x-30+i,y);
}
for(int i=38;i<=45;i++)
line(x+i,y-120,x+i,y-80);
setcolor(BLACK);
for(int i=1;i<5;i++)
line(x-40,y-80+i,x+40,y-80+i);}


void showSmallPipe(){
    setcolor(RGB(51,127,95));
rectangle(x-40,y-50,x+40,y);
rectangle(x-45,y-90,x+45,y-50);
setfillstyle(SOLID_FILL,RGB(189,255,24));
floodfill(x,y-20,RGB(51,127,95));
floodfill(x,y-60,RGB(51,127,95));
setcolor(RGB(0,173,0));
for(int i=4;i<25;i++){
    line(x+i,y-90,x+i,y);
}
for(int i=4;i<10;i++){
    line(x-30+i,y-90,x-30+i,y);
}
for(int i=38;i<=45;i++)
line(x+i,y-90,x+i,y-50);
setcolor(BLACK);
for(int i=1;i<5;i++)
line(x-40,y-50+i,x+40,y-50+i);}

void showLargePipe(){
    setcolor(RGB(51,127,95));
        rectangle(x-40,y-120,x+40,y);
rectangle(x-45,y-160,x+45,y-120);
setfillstyle(SOLID_FILL,RGB(189,255,24));
floodfill(x,y-20,RGB(51,127,95));
floodfill(x,y-130,RGB(51,127,95));
setcolor(RGB(0,173,0));
for(int i=4;i<25;i++){
    line(x+i,y-160,x+i,y);
}
for(int i=4;i<10;i++){
    line(x-30+i,y-160,x-30+i,y);
}
for(int i=38;i<=45;i++)
line(x+i,y-160,x+i,y-120);
setcolor(BLACK);
for(int i=1;i<5;i++)
line(x-40,y-120+i,x+40,y-120+i);
    }
    };
    class clouds{
        public:
        int x;
    void showCloud(){
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
sector(x,getmaxy()*0.25,0,360,30,30);
sector(x+20,getmaxy()*0.25,0,360,30,30);
sector(x+30,getmaxy()*0.25-30,0,360,30,30);
sector(x+40,getmaxy()*0.25-10,0,360,30,30);
sector(x+60,getmaxy()*0.25-20,0,360,30,30);
sector(x+50,getmaxy()*0.25+10,0,360,30,30);
    }};
    class ground{
    public:
    int x;
    void showground(){
    int y=getmaxy();
setcolor(RGB(141,79,58));
rectangle(x-20,y-60,x+20,y);
setfillstyle(SOLID_FILL,RGB(199,109,59));
floodfill(x,y-10,RGB(141,79,58));
setcolor(BLACK);
line(x-20,y-40,x,y-20);
line(x,y-20,x,y);
line(x,y-20,x+10,y-40);
line(x+10,y-40,x+10,y-60);
line(x+10,y-40,x+20,y-40);
    }
    };
    class mountain{
public :
    int x,y;
    void showMountain(){
        setcolor(RGB(6,174,11));
line(x-80,y,x,y-100);
line(x,y-100,x+80,y);
line(x-80,y,x+80,y);
setfillstyle(SOLID_FILL,RGB(6,174,11));
floodfill(x,y-10,RGB(6,174,11));
setcolor(RGB(6,70,11));
ellipse(x-5,y-50,0,360,3,7);
ellipse(x+5,y-70,0,360,3,7);
setfillstyle(SOLID_FILL,RGB(6,70,11));
floodfill(x-5,y-50,RGB(6,70,11));
floodfill(x+5,y-70,RGB(6,70,11));
    }
    };
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
            Brick b(30,40);
            b.showBrick();
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



    getch();

}
