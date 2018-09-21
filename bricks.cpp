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
int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm," ");
setbkcolor(RGB(0,138,197));
int x,y;
cin>>x>>y;
clouds c;
c.x=x;
c.showCloud();
getch();
closegraph();
return 0;}
