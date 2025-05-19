#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int i,dinc;
int main()
{	
	printf("Compiled by Sarfraj Alam\n");
	int x1,x2,y1,y2,dx,dy;
	printf("Enter the starting points(x1,y1): ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the starting points(x2,y2): ");
	scanf("%d%d",&x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	float m=float(dy)/dx;
           dx=fabs(dx);
	dy=fabs(dy);
	float x=x1; float y=y1;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,NULL);
	if(fabs(m)<1&&m>=0) {//for positive slope |m|<1	
		for(i=1;i<=dx;i++)
		{
			int x_inc=1;
			putpixel(round(x),round(y),WHITE);
			delay(10);
			x=x+x_inc;
			y=y+m*x_inc;
		}
	}
	else if(fabs(m)>1&&m>=0) //for positive slope |m|>1
	{
		for(i=1;i<=dy;i++)
		{
			int y_inc=1;
			putpixel(round(x),round(y),WHITE);
			delay(10);
			x=x+(1/m);
			y=y+y_inc;
		}
	}
	else if(fabs(m)>1&&m<0) //for negative slope |m|>1
	{
		for(i=1;i<=dy;i++)
		{
			int y_inc=-1;
			putpixel(round(x),round(y),WHITE);
			delay(10);
			x=x+(1/m);
			y=y+y_inc;
		}
	}
	else
	{
	for(i=1;i<=dy;i++) //for negative slope |m|<1
		{
			int x_inc=-1;
			putpixel(round(x),round(y),WHITE);
			delay(10);
			x=x+x_inc;
			y=y+m*x_inc;
		}	
	}
	getch();
	closegraph();
}

