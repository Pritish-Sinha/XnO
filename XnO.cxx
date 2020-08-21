#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char status[7],waste;
char name[20];
int play[4][4]={8,8,8,8,8,5,5,5,8,5,5,5,8,5,5,5};
int z=1,moveans=1;
int pmove[5],cmove[4];
int start=0,wins=0,loss=0,draw;
class game
{
	public: 
int x,y;
void getcoordinates();
void gamecalc();
void winlosecheck();
};
void move1calc();
void move2calc();
void randmove();
void cmovecalc(int c);
void body();
int main()
{
	clrscr();
	if(start==0)
	{
		cout<<"\n\n\t\tEnter Your Name : ";
		gets(name);
		clrscr();
		start=1;
	}
	body();
	
	return 0;
}

void game::getcoordinates()
{
	int xc,yc;
	char cxc,cyc;
	textcolor(15);
	gotoxy(38,10);
	cout<<" ";
	gotoxy(38,11);
	cout<<" ";
	gotoxy(8,10);
	cout<<"Enter grid co-ordinates ¦ y : ";
	gotoxy(34,11);
	cout<<"x : ";
	gotoxy(38,10);
	cyc=getche();
	gotoxy(38,11);
	cxc=getche();
	xc=cxc-48;
	yc=cyc-48;
	
	if(yc==9||xc==9)
		{
			clrscr();
			cout<<"\tWHAT ELSE COULD YOU DO! ";
			cout<<"Press Any key..";
		waste=getch();
			exit(0);
		}
	else if(xc<0||(xc>3)||yc<0||(yc>3)||play[yc][xc]!=5)
	{
		clrscr();
		moveans=1;
		z=1;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			play[i][j]=5;
		}	
		body();
	}
	if(xc==1)
	x=24;
	else if(xc==2)
	x=27;
	else if(xc==3)
	x=30;
	if(yc==1)
	y=6;
	else if(yc==2)
	y=7;
	else if(yc==3)
	y=8;
	
	play[yc][xc]=1;
	if(yc==1)
	pmove[z]=xc;
	else if(yc==2)
	pmove[z]=xc+3;
	else if (yc==3)
	pmove[z]=xc+6; 
	textcolor(11);
	gotoxy(x,y);
	cout<<"X";
}

void game::gamecalc()
{
	
	int *t;
	t=&play[1][1];
	
	if(((*t==*(t+1))&&(*t==*(t+2)))||((*t==*(t+4))&&(*t==*(t+8)))||((*t==*(t+5))&&(*t==*(t+10))))
	{
		if(*t==1)
		{
		    	strncpy(status, "overw",6);
		    	gotoxy(24,13);
		    	cout<<"You Won";
		 }
		 else if(*t==0)
		 {
		    	strncpy(status, "overl",6);
		    	gotoxy(24,13);
		    	cout<<"CANT BEAT ME!";
		  }
	}
	  if((*(t+10)==*(t+2)&&*(t+10)==*(t+6))||(*(t+10)==*(t+9)&&*(t+10)==*(t+8)))
	{
		if(*(t+10)==1)
		{
		    	strncpy(status, "overw",6);
		    	gotoxy(24,13);
		    	cout<<"You Won";
		 }
		 else if(*(t+10)==0)
		 {
		    	strncpy(status, "overl",6);
		    	gotoxy(24,13);
		    	cout<<"LOST! LOL :)";
		  }
		
	}
	if(*(t+2)==*(t+5)&&*(t+2)==*(t+8))
	{
		if(*(t+2)==1)
		{
		    	strncpy(status, "overw",6);
		    	gotoxy(24,13);
		    	cout<<"You Won";
		 }
		 else if(*(t+2)==0)
		 {
		    	strncpy(status, "overl",6);
		    	gotoxy(24,13);
		    	cout<<"GO AND PRACTICE";
		 }
	}
	if(*(t+1)==*(t+5)&&*(t+1)==*(t+9))
	{
		if(*(t+1)==1)
		{
		    	strncpy(status, "overw",6);
		    	gotoxy(24,13);
		    	cout<<"You Wom";
		 }
		 else if(*(t+1)==0)
		 {
		    	strncpy(status, "overl",6);
		    	gotoxy(24,13);
		    	cout<<"SHAME!";
		 }
	}
	if(*(t+4)==*(t+5)&&*(t+4)==*(t+6))
	{
		if(*(t+4)==1)
		{
		    	strncpy(status, "overw",6);
		    	gotoxy(24,13);
		    	cout<<"You Won";
		 }
		 else if(*(t+4)==0)
		 {
		    	strncpy(status, "overl",6);
		    	gotoxy(24,13);
		    	cout<<"BOOOOOOOO!!";
		 }
	  }
	  
}

void game:: winlosecheck()
{
	moveans=1;
	int *t[9],a=1;
	t[0]=&play[1][1];
	t[1]=&play[1][2];
	t[2]=&play[1][3];
	t[3]=&play[2][1];
	t[4]=&play[2][2];
	t[5]=&play[2][3];
	t[6]=&play[3][1];
	t[7]=&play[3][2];
	t[8]=&play[3][3];
	
	
		if(((*t[0]==*t[8]&&*t[0]==0)||(*t[2]==*t[6]&&*t[2]==0))&&(*t[4]==5))
		{
				gotoxy(27,7);
				textcolor(14);
				*t[4]=0;
				cout<<"0"; a=0; moveans=0;
		}
	
	else if((*t[0]==*t[4]&&*t[8]==5)&&(*t[0]==0))
	{
			gotoxy(30,8);
			textcolor(14);
			*t[8]=0;
			cout<<"0"; a=0; moveans=0;
	}
	else if((*t[4]==*t[8]&&*t[0]==5)&&(*t[4]==0))
	{
			gotoxy(24,6);
			textcolor(14);
			*t[0]=0;
			cout<<"0"; a=0;  moveans=0;
	}
	else if((*t[2]==*t[4]&&*t[6]==5)&&(*t[2]==0))
	{
			gotoxy(24,8);
			textcolor(14);
			*t[6]=0;
			cout<<"0";  a=0;  moveans=0;
	}
	else if((*t[4]==*t[6]&&*t[2]==5)&&(*t[4]==0))
	{
			gotoxy(30,6);
			textcolor(14);
			*t[2]=0;
			cout<<"0";  a=0; moveans=0;
	}
	
	else{
	for(int i=0; i<3 ;i++)
	{
		
		if(*t[i]==*t[i+6]&&(*t[i]==0)&&*t[i+3]==5)
		{
			gotoxy(24+3*i,7);
			textcolor(14);
			*t[i+3]=0;
			cout<<"0"; a=0;
			 moveans=0; break;
		}
	
		else if(*t[i]==*t[i+3]&&(*t[i]==0)&&*t[i+6]==5)
		{
			gotoxy(24+3*i,8);
			textcolor(14);
			*t[i+6]=0;
			cout<<"0";  a=0;
			moveans=0; break;
		}

		else if(*t[i+3]==*t[i+6]&&(*t[3+i]==0)&&*t[i]==5)
		{
			gotoxy(24+3*i,6);
			textcolor(14);
			*t[i]=0;
			cout<<"0"; a=0;
			  moveans=0; break;
		}
	
		else if(*t[3*i]==*t[3*i+2]&&(*t[3*i]==0)&&*t[3*i+1]==5)
		{
			gotoxy(27,6+i);
			textcolor(14);
			*t[i*3+1]=0;
			cout<<"0"; a=0;
			moveans=0; break;
		}
	
		else if(*t[3*i]==*t[3*i+1]&&(*t[3*i]==0)&&*t[3*i+2]==5)
		{
			gotoxy(30,6+i);
			textcolor(14);
			*t[3*i+2]=0;
			cout<<"0"; a=0;
			  moveans=0; break;
		}
	
		else if(*t[3*i+2]==*t[3*i+1]&&(*t[3*i+2]==0)&&*t[3*i]==5)
		{
			gotoxy(24,6+i);
			textcolor(14);
			*t[i*3]=0;
			cout<<"0"; a=0;
			moveans=0; break;
		}
	}
	}
	if(a==1)
	{

	
		if(((*t[0]==*t[8]&&*t[0]==1)||(*t[2]==*t[6]&&*t[2]==1))&&(*t[4]==5))
		{
				gotoxy(27,7);
				textcolor(14);
				*t[4]=0;
				cout<<"0"; moveans=0;
		}
	
	else if((*t[0]==*t[4]&&*t[8]==5)&&(*t[0]==1))
	{
			gotoxy(30,8);
			textcolor(14);
			*t[8]=0;
			cout<<"0";  moveans=0;
	}
	else if((*t[4]==*t[8]&&*t[0]==5)&&(*t[4]==1))
	{
			gotoxy(24,6);
			textcolor(14);
			*t[0]=0;
			cout<<"0";   moveans=0;
	}
	else if((*t[2]==*t[4]&&*t[6]==5)&&(*t[2]==1))
	{
			gotoxy(24,8);
			textcolor(14);
			*t[6]=0;
			cout<<"0";   moveans=0;
	}
	else if((*t[4]==*t[6]&&*t[2]==5)&&(*t[4]==1))
	{
			gotoxy(30,6);
			textcolor(14);
			*t[2]=0;
			cout<<"0";  moveans=0;
	}
	
	else{
	for(int i=0; i<3 ;i++)
	{
		
		if(*t[i]==*t[i+6]&&(*t[i]==1)&&*t[i+3]==5)
		{
			gotoxy(24+3*i,7);
			textcolor(14);
			*t[i+3]=0;
			cout<<"0";
			 moveans=0; break;
		}
	
		else if(*t[i]==*t[i+3]&&(*t[i]==1)&&*t[i+6]==5)
		{
			gotoxy(24+3*i,8);
			textcolor(14);
			*t[i+6]=0;
			cout<<"0"; 
			moveans=0; break;
		}

		else if(*t[i+3]==*t[i+6]&&(*t[3+i]==1)&&*t[i]==5)
		{
			gotoxy(24+3*i,6);
			textcolor(14);
			*t[i]=0;
			cout<<"0";
			  moveans=0; break;
		}
	
		else if(*t[3*i]==*t[3*i+2]&&(*t[3*i]==1)&&*t[3*i+1]==5)
		{
			gotoxy(27,6+i);
			textcolor(14);
			*t[i*3+1]=0;
			cout<<"0"; 
			moveans=0; break;
		}
	
		else if(*t[3*i]==*t[3*i+1]&&(*t[3*i]==1)&&*t[3*i+2]==5)
		{
			gotoxy(30,6+i);
			textcolor(14);
			*t[3*i+2]=0;
			cout<<"0";
			  moveans=0; break;
		}
	
		else if(*t[3*i+2]==*t[3*i+1]&&(*t[3*i+2]==1)&&*t[3*i]==5)
		{
			gotoxy(24,6+i);
			textcolor(14);
			*t[i*3]=0;
			cout<<"0"; 
			moveans=0; break;
		}
	}
	}
	}
	for(int h=0;h<4;h++) 	
	{ 	for(int k=0;k<4;k++)
	         {
	         	 if(play[h][k]==0)
	         	 { 
	         	 if(h==1) 
	         	 cmove[z]=k; 
	         	 else if(h==2)
	         	 cmove[z]=k+3; 
	         	 else if (h==3) 
	         	 cmove[z]=k+6;  			
	         	 } 		
	        } 	
	 }
	 
	 
}

void move1calc()
{
	int *t[10],a=1,b=1,xr=1,yr=1;
	t[1]=&play[1][1];
	t[2]=&play[1][2];
	t[3]=&play[1][3];
	t[4]=&play[2][1];
	t[5]=&play[2][2];
	t[6]=&play[2][3];
	t[7]=&play[3][1];
	t[8]=&play[3][2];
	t[9]=&play[3][3];
	if(*t[5]==1)	
	{
		srand(time(NULL));
		a=rand()%(4+1-1)+1;
		b=rand()%(4+1-1)+1;
		if(a==1||a==4)
		{xr=24; a=1;}
		else if(a==2||a==3)	
		{xr=30; a=3;}
		if(b==1||b==3)
		{yr=6; b=1;}
		else if(b==2||b==4)
		{yr=8; b=3;}
		
		gotoxy(xr,yr);
		textcolor(14);
		cout<<"0";
		play[b][a]=0;
		if(b==1) 
	      cmove[z]=a; 
	      else if(b==2)
	      cmove[z]=a+3; 
	      else if (b==3) 
	      cmove[z]=a+6;
	}
	else if(*t[1]==1||*t[3]==1||*t[7]==1||*t[9]==1)
	{
		gotoxy(27,7);
		textcolor(14);
		cout<<0;
		*t[5]=0;
		cmove[z]=5;
	}
	else if(*t[2]==1||*t[4]==1||*t[6]==1||*t[8]==1)
	{
		srand(time(NULL));
		a=rand()%(4+1-1)+1;
		if(a==1||a==4)
		{
			gotoxy(27,7);
			textcolor(14);
			cout<<0;
			*t[5]=0;
			cmove[z]=5;
		}
		else if(a==2||a==3)
		{
			if(pmove[1]==2)
			cmove[1]=8;
			else if(pmove[1]==4)
			cmove[1]=6;
			else if(pmove[1]==6)
			cmove[1]=4;
			else if(pmove[1]==8)
			cmove[1]=2;
			*t[cmove[1]]=0;
			cmovecalc(1);
			textcolor(14);
			cout<<0;
		}
	}
			
}
void move2calc()
{
	int *t[10],a=1,i=0;
	t[1]=&play[1][1];	t[2]=&play[1][2];
	t[3]=&play[1][3];
	t[4]=&play[2][1];
	t[5]=&play[2][2];
	t[6]=&play[2][3];
	t[7]=&play[3][1];
	t[8]=&play[3][2];
	t[9]=&play[3][3];
	

						if(pmove[1]==5&&(pmove[2]==1||pmove[2]==3||pmove[2]==7||pmove[2]==9))
	{
		
		srand(time(NULL));
		a=rand()%(4+1-1)+1;
		if(a==1||a==3)
		{
			if(cmove[1]==1)
			cmove[2]=3;
			else if(cmove[1]==3)
			cmove[2]=9;
			else if(cmove[1]==9)
			cmove[2]=7;
			else if(cmove[1]==7)
			cmove[2]=1;
		}
		else if(a==2||a==4)
		{
			if(cmove[1]==1)
			cmove[2]=7;
			else if(cmove[1]==3)
			cmove[2]=1;
			else if(cmove[1]==9)
			cmove[2]=3;
			else if(cmove[1]==7)
			cmove[2]=9;
		}
		*t[cmove[2]]=0;
		cmovecalc(2);
		textcolor(14);
		cout<<0;
	}
		
else if(cmove[1]==5&&((pmove[1]==1&&pmove[2]==9)||(pmove[1]==3&&pmove[2]==7)||(pmove[1]==7&&pmove[2]==3)||(pmove[1]==9&&pmove[2]==1)))
	{
		do 
		{
			i++;
			srand(time(NULL));
			a=rand()%(9+1-1)+1;
			if(i==10)
			{ a=2; break;}
		}while(*t[a]!=5&&i<11);
		cmove[2]=a;
		*t[a]=0;
		cmovecalc(2);
		textcolor(14);
		cout<<0;
	}
	//corner-centre-edge
	else if(cmove[1]==5&&((pmove[1]==7&&(pmove[2]==2||pmove[2]==6))||(pmove[1]==1&&(pmove[2]==6||pmove[2]==8))||(pmove[1]==3&&(pmove[2]==4||pmove[2]==8))||(pmove[1]==9&&(pmove[2]==2||pmove[2]==4))))
	{
		if(pmove[1]==1)
		cmove[2]=9;
		else if(pmove[1]==3)
		cmove[2]=7;
		else if(pmove[1]==9)
		cmove[2]=1;
		else if(pmove[1]==7)
		cmove[2]=3;
		*t[cmove[2]]=0;
		cmovecalc(2);
		textcolor(14);
		cout<<0;
	}
	//edge-centre
	else if(pmove[1]==4||pmove[1]==2||pmove[1]==6||pmove[1]==8)
	{
		srand(time(NULL));
		a=rand()%(4+1-1)+1;
		if(cmove[1]!=5)
		{
			if(pmove[2]!=5)
			{
				if(pmove[1]==2)
				{
					if(a==1||a==4)
					cmove[2]=1;
					else if(a==2||a==3)
					cmove[2]=3;
				}
				else if(pmove[1]==4)
				{
					if(a==1||a==4)
					cmove[2]=1;
					else if(a==2||a==3)
					cmove[2]=7;
				}
				else if(pmove[1]==6)
				{
					if(a==1||a==4)
					cmove[2]=3;
					else if(a==2||a==3)
					cmove[2]=9;
				}
				else if(pmove[1]==8)
				{
					if(a==1||a==4)
					cmove[2]=7;
					else if(a==2||a==3)
					cmove[2]=9;
				}
			}
			else if(pmove[2]==5)
			{
				if(a==1)
				cmove[2]=1;
				else if(a==2)
				cmove[2]=3;
				else if(a==3)
				cmove[2]=7;
				else if(a==4)
				cmove[2]=9;
			}
		*t[cmove[2]]=0;
		cmovecalc(2);
		textcolor(14);
		cout<<0;
		}
		else if(cmove[1]==5)
		{
			if((pmove[1]==2&&pmove[2]==4)||(pmove[2]==2&&pmove[1]==4))
			{
				if(a==1||a==3)
				cmove[2]=1;
				else if(a==2)
				cmove[2]=3;
				else if(a==4)
				cmove[2]=7;
			}
			else if((pmove[1]==4&&pmove[2]==8)||(pmove[2]==4&&pmove[1]==8))
			{
				if(a==1||a==3)
				cmove[2]=7;
				else if(a==2)
				cmove[2]=1;
				else if(a==4)
				cmove[2]=9;
			}
			else if((pmove[1]==6&&pmove[2]==8)||(pmove[2]==6&&pmove[1]==8))
			{
				if(a==1||a==3)
				cmove[2]=9;
				else if(a==2)
				cmove[2]=7;
				else if(a==4)
				cmove[2]=3;
			}
			else if((pmove[1]==2&&pmove[2]==6)||(pmove[2]==2&&pmove[1]==6))
			{
				if(a==1||a==3)
				cmove[2]=3;
				else if(a==2)
				cmove[2]=1;
				else if(a==4)
				cmove[2]=9;
			}
			else
			a=0;
			if(a!=0)
			{
				*t[cmove[2]]=0;
				cmovecalc(2);
				textcolor(14);
				cout<<0;
			}
			else if(a==0)
			randmove;
		}
		
	}		
}
		
void randmove()
{
	int *t[10],a=1,i=0;
	t[1]=&play[1][1];
	t[2]=&play[1][2];
	t[3]=&play[1][3];
	t[4]=&play[2][1];
	t[5]=&play[2][2];
	t[6]=&play[2][3];
	t[7]=&play[3][1];
	t[8]=&play[3][2];
	t[9]=&play[3][3];
	do 
	{
		i++;
		srand(time(NULL));
		a=rand()%(9+1-1)+1;
		if(i==10)
		{
			for(int k=1;k<10;k++)
			{
				if(*t[k]==5)
				{
					a=k;
					break;
				}
			}	
		}
	}while(*t[a]!=5&&i<11);
	cmove[z]=a;
	*t[a]=0;
	cmovecalc(z);
	textcolor(14);
	cout<<0;
}
void cmovecalc(int c)
{
	if(cmove[c]==1)
	gotoxy(24,6);
	else if(cmove[c]==2)
	gotoxy(27,6);
	else if(cmove[c]==3)
	gotoxy(30,6);
	else if(cmove[c]==4)
	gotoxy(24,7);
	else if(cmove[c]==5)
	gotoxy(27,7);
	else if(cmove[c]==6)
	gotoxy(30,7);
	else if(cmove[c]==7)
	gotoxy(24,8);
	else if(cmove[c]==8)
	gotoxy(27,8);
	else if(cmove[c]==9)
	gotoxy(30,8);
}

void body()
{
	while(1){
		clrscr();
	textcolor(2);
	gotoxy(5,4);
	cout<<"GAME WILL";
	gotoxy(5,5);
	cout<<"RESTART IF";
	gotoxy(5,6);
	cout<<"YOU ENTER";
	gotoxy(5,7);
	cout<<"WRONG ";
	gotoxy(5,8);
	cout<<"COORDINATES";
	
	textcolor(15);
	gotoxy(40,4);
	cout<<"NAME : ";
	textcolor(10);
	puts(name); 
	gotoxy(40,5);
	textcolor(9);
	cout<<"WINS : ";
		textcolor(10);
		cout<<wins;
		textcolor(12);
		gotoxy(40,6);
		cout<<"LOSS : ";
		textcolor(10);
		cout<<loss;
		textcolor(7);
		gotoxy(40,7);
		cout<<"DRAW : ";
		textcolor(10);
		cout<<draw;
		gotoxy(24,13);
		cout<<"        ";
	moveans=1;
	z=1;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			play[i][j]=5;
		}		
	strncpy(status, "none",6);
	for(int i=0;i<5;i++)
	{
		pmove[i]=0;
		if(i==4)
		break;
		cmove[i]=0;
	}
	game turn[7];
	textcolor(15);
	gotoxy(18,3);
	cout<<"_NOUGHTS & CROSSES_";
	gotoxy(23,5);
	cout<<" 1  2  3";
	gotoxy(20,6);
	cout<<"1  [ ][ ][ ]";
	gotoxy(20,7);
	cout<<"2  [ ][ ][ ]";
	gotoxy(20,8);
	cout<<"3  [ ][ ][ ]";
	textcolor(15);	
	gotoxy(10,16);
	cout<<"Enter 9 in y or x to Quit";
	
	while(strcmp(status,"none")==0)
	{
		if(z>2)
	      turn[z].gamecalc();
		
		if(z==5&&((strcmp(status,"overw")!=0)&&
	           (strcmp(status,"overl")!=0)))
		{
			textcolor(15);
			gotoxy(24,13);
			cout<<"DRAW";
			strncpy(status,"draw",6);
			break;
		}
	      if((strcmp(status,"overw")==0)||
	           (strcmp(status,"overl")==0))
	       break;
	       turn[z].getcoordinates();
	       turn[z].winlosecheck();
	      if(moveans==1)
	      {
	      	if(z==1)
	      	move1calc();
	      	if(z==2)
	      	move2calc();
	      	if(z==3||z==4)
	      	randmove();
	      	
	      }
	      
	    
	      ++z;
      }
    if(strcmp(status,"overw")==0)
    ++wins;
    else if(strcmp(status,"overl")==0)
    ++loss;
    else if(strcmp(status,"draw")==0)
    ++draw;
    textcolor(15);
	gotoxy(40,4);
	cout<<"NAME : ";
	textcolor(10);
	puts(name);
	gotoxy(40,5);
	textcolor(9);
	cout<<"WINS : ";
		textcolor(10);
		cout<<wins;
		textcolor(12);
		gotoxy(40,6);
		cout<<"LOSS : ";
		textcolor(10);
		cout<<loss;
		textcolor(7);
		gotoxy(40,7);
		cout<<"DRAW : ";
		textcolor(10);
		cout<<draw;
		gotoxy(20,14);
		cout<<"Press Any key..";
		waste=getch();

	}	
}