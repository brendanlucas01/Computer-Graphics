#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
void main()
{
int i,gd=DETECT,gm;
int x1,y1,x2,y2,xmin,xmax,ymin,ymax;
int xx1,xx2,yy1,yy2,dx,dy;
float t1,t2,p[4],q[4],temp;
clrscr();
// cout<<"Enter the Coordinates of the starting point";
// cin>>x1>>y1;
// cout<<"Enter the Coordinates of the Ending point";
// cin>>x2>>y2;
x1=100;
x2=400;
y1=100;
y2=400;
/*
cout<<"Enter the Coordinates of topleft point of window";
cin>>xmin>>ymin;
cout<<"Enter the Coordinates of the bottomright point of ";
cin>>xmax>>ymax;
*/
xmin=213;
ymin=160;
xmax=426;
ymax=320;
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
rectangle(xmin,ymin,xmax,ymax);
dx=x2-x1;
dy=y2-y1;
line(x1,y1,x2,y2);
delay(2500);
cleardevice();
setcolor(10);
line(x1,y1,x2,y2);
setcolor(15);
rectangle(xmin,ymin,xmax,ymax);
p[0]=-dx;
p[1]=dx;
p[2]=-dy;
p[3]=dy;
q[0]=x1-xmin;
q[1]=xmax-x1;
q[2]=y1-ymin;
q[3]=ymax-y1;
for(i=0;i<4;i++)
{
if(p[i]==0)
{
if(q[i]>=0)
{
if(i<=1)
{
if(y1<ymin)
{
y1=ymin;
}
if(y2>ymax)
{
y2=ymax;
}
line(x1,y1,x2,y2);
goto end;
}
if(i>=2)
{
if(x1<xmin)
{
x1=xmin;
}
if(x2>xmax)
{
x2=xmax;
}
line(x1,y1,x2,y2);
goto end;
}
}
}
}
t1=0;
t2=1;
for(i=0;i<4;i++)
{
temp=q[i]/p[i];
if(p[i]<0)
{
if(t1<temp)
t1=temp;
}
else
{
if(t2>temp)
t2=temp;
}
}
if(t1<t2)
{
xx1 = x1 + t1 * p[1];
xx2 = x1 + t2 * p[1];
yy1 = y1 + t1 * p[3];
yy2 = y1 + t2 * p[3];
line(xx1,yy1,xx2,yy2);
}
end: delay(2500);
closegraph();
}