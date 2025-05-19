#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
int main()
{
	printf("Compiled by Sarfraj Alam\n");
	int gm,gd=DETECT;
	int x1,y1,x2,y2,i,j,Pk;
	float m,x,y;
	printf("Enter the initial coordinate(x1,y1): ");
	scanf("%d%d",&x1,&y1);
	printf("Enter the final coordinate(x2,y2): ");
	scanf("%d%d",&x2,&y2);
	initgraph(&gd,&gm," ");
	int dx=x2-x1;
	int dy=y2-y1;
	m=float(dy)/dx;
	dx=fabs(dx);
	dy=fabs(dy);
	if(fabs(m)>1) //for slope:|m|>1;
	{
	float P0=2*dx-dy;
		x=x1;
		y=y1;
		if(m>=0)// for positive slope & |m|>1
		{
		for(i=0;i<=dy;i++)
		{
		
	if(P0<0)
	{
			x=x;
			y=y+1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx;
		}
	else 
	{
			x=x+1;
			y=y+1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx-2*dy;
		}
	}}
	else
	{
		for(i=0;i<=dy;i++)// for negative slope & |m|>1
		{	
	if(P0<0)
	{
			x=x;
			y=y-1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx;
		}
	else 
	{
			x=x+1;
			y=y-1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx-2*dy;
		}
	}
	}
}
else //for slope:|m|<1
	{
	float P0=2*dy-dx;
		x=x1;
		y=y1;
		if(m>=0)// for positive slope & |m|<1
		{
		for(i=0;i<=dx;i++)
		{
		
	if(P0<0)
	{
			x=x+1;
			y=y;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dy;
		}
	else 
	{
			x=x+1;
			y=y+1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dy-2*dx;
		}
	}}
	else
	{
		for(i=0;i<=dx;i++)// for negative slope & |m|<1
		{	
	if(P0<0)
	{
			x=x+1;
			y=y-1;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx;
		}
	else 
	{
			x=x+1;
			y=y;
			putpixel(x,y,WHITE);
			delay(10);
			P0=P0+2*dx-2*dy;
		}
	}
	}
}
getch();
closegraph();
return 0;
}

