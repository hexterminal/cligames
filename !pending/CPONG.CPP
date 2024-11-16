#include <conio.h>
#include <dos.h>
#include <cstdio>
#include <iostream>
#include "graphics.h"
class bum
{
	public:
	int up;
	int down;
	int centre;
	char status;
	int mov;
	bum();
	void moveup()
	{
		centre=centre-mov;
		reorder(centre);
		status='u';
	}
	void movedown()
	{
		centre=centre+mov;
		reorder(centre);
		status='d';
	}
	void reorder(int c)
	{
		up=c-50;
		down=c+50;
	}
	void limit(int mov)
	{
		if(up-mov<70)
		{
			centre=120;
			reorder(centre);
		}
		if(down+mov>400)
		{
			centre=350;
			reorder(centre);
		}
	}
	void recentre()
	{
		if(centre>235)
		{
			if(centre-mov<=235)
			{
				centre=235;
			}
			moveup();
		}
		else if(centre<235)
		{
			if(centre-mov>=235)
			{
				centre=235;
			}
			movedown();
		}
	}
};
bum::bum()
{
	centre=235;
	up=235-50;
	down=235+50;
	mov=5;
}
class ball
{
	public:
	int x,y,x1,x2,y1,y2,movx,movy,reset_valx,reset_valy,hit_by;
	int ty1,ty2,tx1,tx2;
	ball();
	void reorder(int x,int y)
	{
		x1=x-10;
		x2=x+10;
		y1=y-10;
		y2=y+10;
		tx1=x1+movx;
		tx2=x2+movx;
		ty1=y1+movy;
		ty2=y2+movy;
	}
	void move(int movx,int movy)
	{
		x=x+movx;
		y=y+movy;
	}
	void bounce(char status)
	{
		if(x2==525)
		{
			hit_by=1;
			movx=movx-movx-movx;
			if(status=='u')
			{
				if(movy<=4 && movy>=-4)
				{
					if(movy-2!=0)
					{
						movy=movy-2;
					}
				}
			}
			else if(status=='d')
			{
				if(movy<=4 && movy>=-4)
				{
					if(movy+2!=0)
					{
						movy=movy+2;
					}
				}
			}
		}
		else if(x1==100)
		{
			hit_by=0;
			movx=movx-movx-movx;
			if(status=='u')
			{
				if(movy<=4 && movy>=-4)
				{
					if(movy-2!=0)
					{
						movy=movy-2;
					}
				}
			}
			else if(status=='d')
			{
				if(movy<=4 && movy>=-4)
				{
					if(movy+2!=0)
					{
						movy=movy+2;
					}
				}
			}
		}
		else
		{
			 movy=movy-movy-movy;
		}
	}
	void res()
	{
		x=reset_valx;
		y=reset_valy;
		movx=5;
		movy=2;
	}
	void limit(int a1, int a2, int b1, int b2)
	{
		if(tx1<100)
		{
			if(tx1<100 && y1>=b1-13 && y2<=b2+13)
			{
				x=110;
				reorder(x,y);
			}
			else if(tx1<75)
			{
				x=85;
				reorder(x,y);
			}
		}
		else if(tx2>525)
		{
			if(tx2>525 && y1>=a1-13 && y2<=a2+13)
			{
				x=515;
				reorder(x,y);
			}
			else if(tx2>550)
			{
				x=540;
				reorder(x,y);
			}
		}
		else if(ty1<70)
		{
			y=80;
			reorder(x,y);
		}
		else if(ty2>400)
		{
			y=390;
			reorder(x,y);
		}
	}
};
ball::ball()
{
	x=313;
	y=235;
	x1=x-10;
	x2=x+10;
	y1=y-10;
	y2=y+10;
	movx=5;
	movy=2;
	reset_valx=x;
	reset_valy=y;
	tx1=x1+10;
	tx2=x2+10;
	ty1=y1+10;
	ty2=y2+10;
}
void win(int wn)
{
	char buff[80];
	cleardevice();
	if(wn==1)
	{
		sprintf(buff, "CPU WON!");
		outtextxy(200, 100, buff);
	}
	else if(wn==2)
	{
		sprintf(buff, "YOU WON!");
		outtextxy(200, 100, buff);
	}
	getch();
}
void draw(int x1, int y1, int x2, int y2, int up1, int down1, int up2, int down2)
{
		rectangle(75, 70, 550, 400);								//OUTLINE
		bar(x1, y1, x2, y2);    									//BALL
		rectangle(x1, y1, x2, y2);
		rectangle(525, up1, 550, down1);							//RIGHT RECTANGLE
		rectangle(75, up2, 100, down2);								//LEFT RECTANGLE
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://TURBOC3/BGI");
	char ch,buff[80];
	int cpu_score=0, user_score=0, diff=3,temp=0,de=25,i=1,col=15;
	int hit_c=0,w=0;
	int l[4]={295,350,400,550};
	bum a,b;
	ball k;
	do
	{
		if(hit_c>=0 && hit_c<2)
		{
			diff=0;
			b.mov=3;
		}
		else if(hit_c>=2 && hit_c<4)
		{
			diff=1;
			b.mov=3;
		}
		else if(hit_c>=4 && hit_c<6)
		{
			diff=2;
			b.mov=4;
		}
		else if(hit_c>=6)
		{
			diff=3;
			b.mov=10;
		}
		if(user_score>cpu_score && user_score<cpu_score+2 && diff<1)
		{
			diff=1;
			b.mov=3;
		}
		else if(user_score>=cpu_score+2 && user_score<cpu_score+3 && diff<2)
		{
			diff=2;
			b.mov=4;
		}
		else if(hit_c>=2 && user_score>=cpu_score+3)				//GODMODE
		{
			if(hit_c>1)
			{
				diff=3;
				b.mov=10;
			}
		}
		ch='x';
		cleardevice();
		if(diff==3)
		{
			if(i==1)
			{
				col=1;
				i--;
			}
			else if(i==0)
			{
				col=4;
				i++;
			}
		}
		setcolor(col);
		draw(k.x1, k.y1, k.x2, k.y2, a.up, a.down, b.up, b.down);
		sprintf(buff, "CPU - %d || PLAYER - %d",cpu_score,user_score);
		outtextxy(200, 10, buff);
		//cout<<"\t\t\tCPU - "<<cpu_score<<"\t|| "<<"PLAYER - "<<user_score<<"\t\t\t\t\t"<<endl; CPU - %d || <<PLAYER - %d",cpu_score,user_score
		if(diff==3)
		{
			sprintf(buff, "GOD MODE");
			outtextxy(200, 30, buff);
		}
		k.move(k.movx, k.movy);
		k.reorder(k.x, k.y);
		k.limit(a.up, a.down, b.up, b.down);

		if(k.x2==525||k.x1==100||k.y2==400||k.y1==70)
		{
			if(k.x2==525 && k.y1>=a.up-13 && k.y2<=a.down+13)
			{
				k.bounce(a.status);
			}
			else if(k.x1==100 && k.y1>=b.up-13 && k.y2<=b.down+13)
			{
				k.bounce(b.status);
				if(k.movy!=0)
				{
					hit_c++;
				}
				if(diff==3)
				{
					if(de-5>0)
					{
						de=de-5;
					}
				}
			}
			else if(k.y2==400 || k.y1==70)
			{
				k.bounce(a.status);
			}
		}
		a.status='s';
		b.status='s';
		if(kbhit())
		{
			switch(ch=getch())
			{
				case 'a':
				{
					if(a.up>70)
					{
						a.moveup();
					}
					break;
				}
				case 'z':
				{
					if(a.down<400)
					{
						a.movedown();
					}
					break;
				}
				case 'p':
				{
					getch();
					break;
				}
				default:
				{
					break;
				}
			}
		}
		b.limit(b.mov);
		a.limit(a.mov);
		if(k.hit_by == 1 && k.x<l[diff])	//AI PADDLE LOCATION
		{
			if(k.y>b.centre)
			{
				if(b.down<400)
				{
					b.movedown();
				}
			}
			if(k.y<b.centre)
			{
				if(b.up>70)
				{
					b.moveup();
				}
			}
		}
		if(k.hit_by==0)					//AI PADDLE RESET
		{
			b.recentre();
		}
		if(k.x2>=550 || k.x1<=75)
		{
			if(k.x2==550)
			{
				cpu_score++;
				hit_c=0;
				diff=0;
				de=20;
				col=15;

			}
			else if(k.x1==75)
			{
				user_score++;
				hit_c=0;
				diff=0;
				de=20;
				col=15;
			}
			k.res();
			a.centre=235;
			a.reorder(a.centre);
			b.centre=235;
			b.reorder(b.centre);
			k.reorder(k.x,k.y);
		}
		if(user_score==10||cpu_score==10)
		{
			if(cpu_score==10)
			{
				w=1;
			}
			else if(user_score==10)
			{
				w=2;
			}
			win(w);
			goto exit;
		}
		delay(10);
		delay(de);
	}while(ch!='e');
	exit:
	return 0;
}