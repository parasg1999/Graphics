#include<iostream>
#include<graphics.h>
using namespace std;
class brick{
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
brick(int a,int b){
x=a;
y=b;}
};

class pipe{
public:
    int x,y;
    pipe(int a,int b){
    x=a;
    y=b;}
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
        clouds(int a){
        x=a;}
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
    ground(int a){
    x=a;}
    void showground(){
    int y=getmaxy();
setcolor(RGB(199,109,59));
rectangle(x-20,y-60,x+20,y);
setfillstyle(SOLID_FILL,RGB(199,109,59));
floodfill(x,y-10,RGB(199,109,59));
setcolor(BLACK);
line(x-20,y-40,x,y-20);
line(x,y-20,x,y);
line(x,y-20,x+10,y-40);
line(x+10,y-40,x+10,y-60);
line(x+10,y-40,x+20,y-40);
y=getmaxy()-60;
x=x-30;
setcolor(RGB(199,109,59));
rectangle(x-20,y-60,x+20,y);
setfillstyle(SOLID_FILL,RGB(199,109,59));
floodfill(x,y-10,RGB(199,109,59));
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
    mountain(int a,int b){
    x=a;
    y=b;}
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
int main(){
 DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth,screenHeight,"",-3,-3);

setbkcolor(COLOR(0,138,197));
for(int i=0;i<2500;i=i+40){
    ground g(i);
    g.showground();

}
pipe p1(500,getmaxy()-120);
pipe p2(1000,getmaxy()-120);
pipe p3 (750,getmaxy()-120);
p3.showLargePipe();
p1.showSmallPipe();
p2.showMediumPipe();
clouds s(200);
clouds s2(700);
s.showCloud();
s2.showCloud();
brick b1(100,500);
brick b2(140,500);
brick b3(140,500);
b1.showBrick();
b2.showBrick();
b3.showBrick();

getch();
return 0;}
