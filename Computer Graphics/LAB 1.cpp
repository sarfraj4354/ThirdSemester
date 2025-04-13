#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
	int x1,y1,x2,y2;
	float m;
	printf("Enter the x1,y1,x2,y2");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	int dx=x2-x1;
	int dy=y2-y1;
	m=float (dy/dx);
	if(m<1){
		int xinc=1;
		int yinc=1;
		float x=x1;
		float y=y1;
		int i;
		for(i=1;i<=dx;i++)
		{
			putpixel(round(x),round(y),RED);
			x=x+xinc;
			y=y+yinc;
		}
	}
	getch();
	return 0;
}
