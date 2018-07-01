#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip.h>
void initgraphic()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");

}
void obase()
{
setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADD");
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("DELETE");
}

void abase()
{
setcolor(15);
rectangle(70,165,250,210);
settextstyle(1,HORIZ_DIR,2);
moveto(80,175);
outtext("MANAGE OFFER");
rectangle(360,165,480,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USERINFO");
}

void ubase()
{
setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("LOGIN");
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("CREATE");
}
void mbase()
{
setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADMIN");
rectangle(360,165,440,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USER");

}
class offerdetail
{
public:
char bandwidth[10];
float price;
void odetail(char a[10])
{
strcpy(bandwidth,a);
gotoxy(30,11);
cout<<"Enter price per month:Rs";
cin>>price;
}
};

class user
{
public:
offerdetail O;
tm *ti;
int year,month,date,period;
char times[20],fileoffer[10],fname[10],mname[10],lname[10],sex[6],PN[11],email[20],bandwidth[10];
float cost;
char username[10];
char password[10];
int createaccount();

}U;
void addoffer()
{
offerdetail O;
char offername[10];
gotoxy(35,5);
cout<<"ADD OFFER";
gotoxy(30,10);
cout<<"Enter offername:";
cin>>offername;
O.odetail(offername);
ofstream ofile;
ofile.open(offername);
ofile.write((char*)&O,sizeof(O));
ofile.close();
ofile.open("offlist.txt",ios::app);
ofile<<offername<<endl;
ofile.close();
}

int deleteoffer()
{
char offername[10],fileoffer[10];
gotoxy(35,5);
cout<<"DELETE OFFER";

gotoxy(5,6);
cout<<"Available OFFER";
ifstream fin;
fin.open("offlist.txt",ios::in);
fin>>fileoffer;
int i=1;
gotoxy(5,7);
while(!fin.eof()){
cout<<i<<"."<<fileoffer<<endl;
fin>>fileoffer;
i++;
}
fin.close();

gotoxy(30,10);
cout<<"Enter offername:";
cin>>offername;
if(remove(offername)==0)
{
gotoxy(30,20);
cout<<"Offer Deleted Successfully";
}
else
{
gotoxy(30,20);
cout<<"Offer not found";
getch();
return 0;
}


ofstream fout;
fin.open("offlist.txt",ios::in);
fout.open("temp.txt",ios::out);
fin>>fileoffer;
while(!fin.eof()){
if(strcmp(fileoffer,offername))
fout<<fileoffer<<endl;
fin>>fileoffer;
}
fin.close();
fout.close();
remove("offlist.txt");
rename("temp.txt","offlist.txt");
getch();
}
int adminoffer()
{
int ch;
initgraphic();
cleardevice();
obase();
do{
if(kbhit)                                            //check if a key is pressed
{
ch=getch();

if(ch=='a'||ch==75)                           	//move left
{
setcolor(BLACK);
rectangle(340,155,480,220);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("DELETE");

setcolor(15);
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("DELETE");

setcolor(BLACK);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADD");

setcolor(GREEN);
rectangle(200,155,320,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("ADD");

if(kbhit)
{
ch=getch();
if(ch==13)
{
closegraph();
cin.clear();
addoffer();
clrscr();
initgraphic();
obase();
}
}
}

if(ch=='d'||ch==77)                          	//move right
{
setcolor(BLACK);
rectangle(200,155,320,220);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("ADD");

setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADD");

setcolor(BLACK);
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("DELETE");

setcolor(GREEN);
rectangle(340,155,480,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("DELETE");
if(kbhit)
{
ch=getch();
cin.clear();
if(ch==13)
{
closegraph();
cin.clear();
deleteoffer();
clrscr();
initgraphic();
obase();
}
}

}
if(ch==27)
{
return 0;
}
}
}while(1);
/*cout<<"enter"<<endl
<<"'1' to add offer"<<endl
<<"'2' to delete offer"<<endl
<<"choice:";
cin>>ch;
if(ch==1)
{
addoffer();
}
else if(ch==2)
{
deleteoffer();
}
else
{
cout<<"wrong entry try again";
} */

}

void userinfo()
{
user U;
char uname[40];
gotoxy(35,3);
cout<<"SEARCH USER DETAIL";
gotoxy(33,6);
cout<<"Username:";
cin>>uname;
cin.ignore();
ifstream file;
file.open("userifo.txt",ios::in);
		file.read((char*)&U,sizeof(U));
		while(!file.eof())
		{
		if(strcmp(U.username,uname)==0)
		{
		clrscr();
gotoxy(35,3);
cout<<"USER DETAIL";
gotoxy(10,6);
cout<<"Name:"<<U.fname<<" "<<U.mname<<" "<<U.lname<<endl;
gotoxy(10,7);
cout<<"D.O.B:"<<U.year<<"/"<<U.month<<"/"<<U.date<<endl;
gotoxy(10,8);
cout<<"Gender:"<<U.sex<<endl;
gotoxy(10,9);
cout<<"Phone no.:"<<U.PN<<endl;
gotoxy(10,10);
cout<<"Email:"<<U.email<<endl;
gotoxy(10,11);
cout<<"Bandwidth:"<<U.bandwidth<<endl;
		getch();
		}
		file.read((char*)&U,sizeof(U));
}
}

int adminlogin()
{
int ch;
initgraphic();
cleardevice();
abase();
do{
if(kbhit)                                            //check if a key is pressed
{
ch=getch();

if(ch=='a'||ch==75)                           	//move left
{
setcolor(BLACK);
rectangle(340,155,520,220);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("USERINFO");

setcolor(15);
rectangle(360,165,480,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USERINFO");

setcolor(BLACK);
rectangle(70,165,250,210);
settextstyle(1,HORIZ_DIR,2);
moveto(80,175);
outtext("MANAGE OFFER");

setcolor(GREEN);
rectangle(50,155,310,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(65,170);
outtext("MANAGE OFFER");

if(kbhit)
{
ch=getch();
if(ch==13)
{
closegraph();
cin.clear();
adminoffer();
clrscr();
initgraphic();
abase();
}
}
}

if(ch=='d'||ch==77)                          	//move right
{
setcolor(BLACK);
rectangle(50,155,310,220);
settextstyle(1,HORIZ_DIR,4);
moveto(65,170);
outtext("MANAGE OFFER");

setcolor(15);
rectangle(70,165,250,210);
settextstyle(1,HORIZ_DIR,2);
moveto(80,175);
outtext("MANAGE OFFER");

setcolor(BLACK);
rectangle(360,165,480,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USERINFO");

setcolor(GREEN);
rectangle(340,155,520,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("USERINFO");
if(kbhit)
{
ch=getch();
cin.clear();
if(ch==13)
{
closegraph();
cin.clear();
userinfo();
clrscr();
initgraphic();
abase();
}
}

}
if(ch==27)
{
return 0;
}
}
}while(1);
}

void changepassword(user U,char username[10])
{
clrscr();
user O;
int c=0;
char ch;
			clrscr();
			gotoxy(16,3);
			c=0;
			cout<<"Set Username:";
			while(c<10)
			{
				ch=getch();

				if(isdigit(ch)||isalpha(ch)||ch=='.')
				{
					U.username[c]=ch;
					cout<<U.username[c];
					c++;
					U.username[c]='\0';
				}
				if(ch==8&&c>0)
				{
					gotoxy(29+c-1,3);
					cout<<" ";
					gotoxy(29+c-1,3);
					c--;
					U.username[c]='\0';

				}
				if((ch==13||ch==9)&&c>6)
				{
					goto pass;
				}
				if((ch==9||ch==13)&&c<=5)
				{
					textcolor(RED);
					gotoxy(40,3);
					cprintf("username must be more than 6 words!");
					getch();
					textcolor(BLACK);
					gotoxy(40,3);
					cprintf("username must be more than 6 words!");
					gotoxy(29+c,3);
					textcolor(WHITE);
				}
			}
			pass:
			c=0;
			gotoxy(16,4);
			cout<<"Set Password:";
			while(c<10)
			{
				ch=getch();
				if(isdigit(ch)||isalpha(ch)||ispunct(ch))
				{
					U.password[c]=ch;
					cout<<U.password[c];
					c++;
					U.password[c]='\0';
				}
				if(ch==8&&c>0)
				{
					gotoxy(29+c-1,4);
					cout<<" ";
					gotoxy(29+c-1,4);
					c--;
					U.password[c]='\0';

				}
				if((ch==13||ch==9)&&c>6)
				{
					goto go;
				}
				if((ch==9||ch==13)&&c<=5)
				{
					textcolor(RED);
					gotoxy(40,4);
					cprintf("password must be more tha 6 words!");
					getch();
					textcolor(BLACK);
					gotoxy(40,4);
					cprintf("password must be more than 6 words!");
					gotoxy(29+c,4);
					textcolor(WHITE);
				}
			}

go:
ifstream fin;
ofstream fout;
fin.open("userifo.txt",ios::in);
fout.open("temp.txt",ios::out);
fin.read((char*)&O,sizeof(O));
while(!fin.eof()){
if(strcmp(O.username,username))
fout.write((char*)&O,sizeof(O));
fin.read((char*)&O,sizeof(O));
}
fin.close();
fout.close();
remove("userifo.txt");
rename("temp.txt","userifo.txt");

ofstream file;
file.open("userifo.txt",ios::app);
file.seekp(0,ios::end);
file.write((char*)&U,sizeof(U));
file.close();

}

void upgrade(user U,char username[10])
{
clrscr();
int ch;
user O;
offerdetail C;
char fileoffer[10];

gotoxy(5,4);
cout<<"Choose Bandwidth:"<<endl;
{
ifstream fin;
fin.open("offlist.txt",ios::in);
fin>>fileoffer;
int i=1;
gotoxy(5,5);
while(!fin.eof()){
cout<<i<<"."<<fileoffer<<"  ";
fin>>fileoffer;
i++;
}
fin.close();
}
gotoxy(5,6);
cout<<"choice:";
cin>>ch;
int i=1;
{
ifstream fin;
fin.open("offlist.txt",ios::in);
while(!fin.eof()){
fin>>fileoffer;
if(ch==i)
{
strcpy(U.bandwidth,fileoffer);
fin.close();
break;
}
i++;
}
fin.close();
}

go:
gotoxy(5,7);
cout<<"peroid:"<<endl;
gotoxy(5,8);
cout<<"1. 1 month     "
<<"2. 3 month     "
<<"3. 6 month     "
<<"4. 12 month"<<endl;
gotoxy(5,9);
cout<<"choice:";

t:
textcolor(BLACK);
gotoxy(40,18);
cprintf("wrong entry");
textcolor(WHITE);
gotoxy(5,10);
ch=getch();
if(ch=='1')
{
cout<<"1. 1 month ";
U.period=1;
time_t t=time(0)+86400*30;
U.ti=localtime(&t);
}
else if(ch=='2')
{
cout<<"2. 3 month ";
U.period=3;
time_t t=time(0)+86400*90;
U.ti=localtime(&t);
}
else if(ch=='3')
{
cout<<"3. 6 month ";
U.period=6;
time_t t=time(0)+86400*182;
U.ti=localtime(&t);
}
else if(ch=='4')
{
cout<<"4. 12 month ";
U.period=12;
time_t t=time(0)+86400*365;
U.ti=localtime(&t);
}
else
{
textcolor(RED);
gotoxy(40,18);
cprintf("wrong entry");
getch();
goto go;
}
ifstream ifile;
ifile.open(U.bandwidth);
ifile.read((char*)&C,sizeof(C));
ifile.close();
U.cost=C.price*U.period;

getch();
ifstream fin;
ofstream fout;
fin.open("userifo.txt",ios::in);
fout.open("temp.txt",ios::out);
fin.read((char*)&O,sizeof(O));
while(!fin.eof()){
if(strcmp(O.username,username))
fout.write((char*)&O,sizeof(O));
fin.read((char*)&O,sizeof(O));
}
fin.close();
fout.close();
remove("userifo.txt");
rename("temp.txt","userifo.txt");

ofstream file;
file.open("userifo.txt",ios::app);
file.seekp(0,ios::end);
file.write((char*)&U,sizeof(U));
file.close();

}

void offers()
{
clrscr();
char ch,bandwidth[10],fileoffer[10];
offerdetail O;
gotoxy(35,3);
cout<<"Available OFFER";
ifstream fin;
fin.open("offlist.txt",ios::in);
fin>>fileoffer;
int i=1;
gotoxy(32,6);
while(!fin.eof()){
gotoxy(32,6+i);
cout<<i<<"."<<fileoffer<<"       ";

ifstream ifile;
ifile.open(fileoffer);
ifile.read((char*)&O,sizeof(O));
ifile.close();
cout<<O.price<<endl;

fin>>fileoffer;
i++;
}
fin.close();
getch();
}

void accountinfo(user U)
{
clrscr();
gotoxy(5,3);
cout<<"Name:"<<U.fname<<" "<<U.lname<<endl;
gotoxy(5,4);
cout<<"D.O.B:"<<U.year<<"/"<<U.month<<"/"<<U.date<<endl;
gotoxy(5,5);
cout<<"Gender:"<<U.sex<<endl;
gotoxy(5,6);
cout<<"Phone no.:"<<U.PN<<endl;
gotoxy(5,7);
cout<<"Bandwidth:"<<U.bandwidth<<endl;
gotoxy(5,8);
cout<<"Expires On:"<<U.times<<endl;
getch();
}

void loginaccount(user U)
{
int ch;
gotoxy(35,3);
cout<<"USER ACCOUNT"<<endl;
gotoxy(30,5);
cout<<"'1' to get account info"<<endl;
gotoxy(30,6);
cout<<"'2' to see available offers"<<endl;
gotoxy(30,7);
cout<<"'3' to change user login password"<<endl;
gotoxy(30,8);
cout<<"'4' to upgrade speed"<<endl;
_setcursortype(0);
gotoxy(30,12);
cout<<"choice:";
cin>>ch;
cin.clear();
cin.ignore();
if(ch==1)
{
accountinfo(U);
}
else if(ch==2)
{
offers();
}
else if(ch==3)
{
changepassword(U,U.username);
}
else if(ch==4)
{
upgrade(U,U.username);
}
else
{
cout<<"wrong entry try again";
}
}
int user::createaccount()
{
char* it;
int c=0,ch;
clrscr();
gotoxy(30,1);
cout<<"Enter Your Detail:"<<endl;

gotoxy(5,3);
cout<<"First Name:";
/*
cin>>fname;
	cin.clear();

	for(int j=0;j<strlen(fname);j++)
	{
		if(isalpha(fname[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto fn;
		}
	}
	if(strlen(fname)<4 || strlen(fname)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto fn;
	}   */
next0:
while(c<10)
{
ch=getch();
if(isalpha(ch))
{
fname[c]=ch;
cout<<fname[c];
c++;
fname[c]='\0';
}
if(ch==8&&c>0)
{
gotoxy(16+c-1,3);
cout<<" ";
gotoxy(16+c-1,3);
c--;
fname[c]='\0';

}
if((ch==13||ch==9)&&c>2)
{
goto next1;
}
if((ch==9||ch==13)&&c<=2)
{
textcolor(RED);
gotoxy(40,3);
cprintf("Firstname must be filled!");
getch();
textcolor(BLACK);
gotoxy(40,3);
cprintf("Firstname must be filled!");
gotoxy(16+c,3);
textcolor(WHITE);
}
}
next1:
textcolor(GREEN);
gotoxy(40,4);
cprintf("Optional");

gotoxy(5,4);
cout<<"Middel Name:";
/*cin>>mname;

	for(j=0;j<strlen(mname);j++)
	{
		if(isalpha(mname[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto mn;
		}
	}
	cin.clear();
	if(strlen(mname)<4 || strlen(mname)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto mn;
	}*/
c=0;
while(c<10)
{
ch=getch();
if(isalpha(ch))
{
mname[c]=ch;
cout<<mname[c];
c++;
}
if(ch==8&&c>0)
{
gotoxy(17+c-1,4);
cout<<" ";
gotoxy(17+c-1,4);
c--;
mname[c]='\0';

}
if(ch==13||ch==9)
{
mname[c]='\0';
strcpy(mname," ");
textcolor(BLACK);
gotoxy(40,4);
cprintf("Optional");
textcolor(WHITE);
goto next2;
}
}
next2:
gotoxy(5,5);
cout<<"Last Name:";
/*
cin>>lname;
	cin.clear();

	for(j=0;j<strlen(lname);j++)
	{
		if(isalpha(lname[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto ln;
		}
	}
	if(strlen(lname)<4 || strlen(lname)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto ln;
	} */
c=0;
while(c<10)
{
ch=getch();
if(isalpha(ch))
{
lname[c]=ch;
cout<<lname[c];
c++;
lname[c]='\0';
}
if(ch==8&&c>0)
{
gotoxy(15+c-1,5);
cout<<" ";
gotoxy(15+c-1,5);
c--;
lname[c]='\0';

}
if((ch==13||ch==9)&&c>2)
{
goto next3;
}
if((ch==9||ch==13)&&c<2)
{
textcolor(RED);
gotoxy(40,5);
cprintf("lastname must be filled!");
getch();
textcolor(BLACK);
gotoxy(40,5);
cprintf("lastname must be filled!");
gotoxy(15+c,5);
textcolor(WHITE);
}
}
next3:
gotoxy(5,6);
cout<<"Date of Birth:"<<endl;
{
char COF[4];
y:
COF[4]=0;
int DOF=0;
gotoxy(5,7);
cout<<"year:";
while(DOF!=1)
{
	for(int i=0; i<4;i++)
	{
	COF[i]=getch();
	cout<<COF[i];
	}
	year=0;
	year=atoi(COF);
	cout<<year;
	getch();
	if(ch=='13')
	{
	DOF=1;
	gotoxy(10,7);
	cout<<"    ";
	gotoxy(10,7);
	goto y;
	}
	if(year>1950&&year<2017)
	{
	DOF=1;
	}
	else
	{
	gotoxy(10,7);
	cout<<"    ";
	gotoxy(10,7);
	}
}
}
{
char GOF[2];
m:
GOF[2]=0;
int DOF=0;

gotoxy(20,7);
cout<<"month:";
while(DOF!=1)
{
	for(int i=0; i<2;i++)
	{
	GOF[i]=getch();
	cout<<GOF[i];
	}
	month=atoi(GOF);
	if(ch=='13')
	{
	gotoxy(10,7);
	cout<<"    ";
	gotoxy(10,7);
	goto m;
	}

	if((month>0)&&(month<13))
	{
	DOF=1;
	}
	else
	{
	cout<<month;
	gotoxy(26,7);
	cout<<"  ";
	gotoxy(26,7);
	}
}
}
{
char GOF[2];
d:
int DOF=0;
gotoxy(35,7);
cout<<"date:";
while(DOF!=1)
{
	for(int i=0; i<2;i++)
	{
	GOF[i]=getch();
	cout<<GOF[i];
	}
	date=atoi(GOF);
	if(ch=='13')
	{
	gotoxy(10,7);
	cout<<"    ";
	gotoxy(10,7);
	goto m;
	}

	if(date>0&&date<31)
	{
	DOF=1;
	}
	else
	{
	gotoxy(40,7);
	cout<<"  ";
	gotoxy(40,7);
	}
}
}

gotoxy(5,8);
cout<<"gender:"<<endl;
gotoxy(5,9);
cout<<" 1.male       2.female       3.other"<<endl;
{
gotoxy(5,10);
cout<<"choice:";
s:
textcolor(BLACK);
gotoxy(40,10);
cprintf("wrong entry");
gotoxy(14,10);
ch=getch();
if(ch=='1')
{
cout<<"1. male";
strcpy(sex,"male");
}
else if(ch=='2')
{
cout<<"1. female";
strcpy(sex,"female");
}
else if(ch=='3')
{
cout<<"1. other";
strcpy(sex,"other");
}
else
{
textcolor(RED);
gotoxy(40,10);
cprintf("wrong entry");
getch();
goto s;

}
}
gotoxy(5,11);
cout<<"Phone no.:";
/*
cin>>PN;
	cin.clear();

	for(j=0;j<strlen(PN);j++)
	{
		if(isdigit(PN[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto pn;
		}
	}
	if(strlen(PN)<4 || strlen(PN)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto pn;
	} */
c=0;
while(c<11)
{
ch=getch();
if(isdigit(ch)&&c<10)
{
PN[c]=ch;
cout<<PN[c];
c++;
PN[c]='\0';
}
if(ch==8&&c>0)
{
gotoxy(15+c-1,11);
cout<<" ";
gotoxy(15+c-1,11);
c--;
PN[c]='\0';

}
if((ch==13||ch==9)&&c==10)
{
goto next4;
}
if((ch==9||ch==13)&&c<10)
{
textcolor(RED);
gotoxy(40,11);
cprintf("Phone Number must be filled!");
getch();
textcolor(BLACK);
gotoxy(40,11);
cprintf("Phone Number must be filled!");
gotoxy(15+c,11);
textcolor(WHITE);
}
}
next4:
textcolor(GREEN);
gotoxy(40,12);
cprintf("Optional");
textcolor(WHITE);
gotoxy(5,12);
cout<<"Email:";
/*
cin>>email;
	cin.clear();

	for(j=0;j<strlen(email);j++)
	{
		if(isalpha(email[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto en;
		}
	}
	if(strlen(email)<4 || strlen(email)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto en;
	}*/
c=0;
while(c<20)
{
ch=getch();
if((isalpha(ch)||isdigit(ch))&&c<10)
{
email[c]=ch;
cout<<email[c];
c++;
email[c]='\0';
}
if(ch==8&&c>0)
{
gotoxy(11+c-1,12);
cout<<" ";
gotoxy(11+c-1,12);
c--;
email[c]='\0';

}
if(ch==13||ch==9)
{
strcpy(email," ");
textcolor(BLACK);
gotoxy(40,12);
cprintf("Optional");
textcolor(WHITE);

goto next5;
}
}
next5:
gotoxy(5,13);
cout<<"Choose Bandwidth:"<<endl;
{
ifstream fin;
fin.open("offlist.txt",ios::in);
fin>>fileoffer;
int i=1;
gotoxy(5,14);
while(!fin.eof()){
cout<<i<<"."<<fileoffer<<"  ";
fin>>fileoffer;
i++;
}
fin.close();
}
gotoxy(5,15);
cout<<"choice:";
cin>>ch;
cin.clear();
cin.ignore();
int i=1;
{
ifstream fin;
fin.open("offlist.txt",ios::in);
while(!fin.eof()){
fin>>fileoffer;
if(ch==i)
{
strcpy(bandwidth,fileoffer);
fin.close();
break;
}
i++;
}
fin.close();
}

gotoxy(5,16);
cout<<"peroid:"<<endl;
gotoxy(5,17);
cout<<"1. 1 month     "
<<"2. 3 month     "
<<"3. 6 month     "
<<"4. 12 month"<<endl;
gotoxy(5,18);
cout<<"choice:";

t:
textcolor(BLACK);
gotoxy(40,18);
cprintf("wrong entry");
textcolor(WHITE);
gotoxy(14,18);
ch=getch();
if(ch=='1')
{
cout<<"1. 1 month ";
period=1;
time_t t=time(0)+86400*30;
ti=localtime(&t);
}
else if(ch=='2')
{
cout<<"2. 3 month ";
period=3;
time_t t=time(0)+86400*90;
ti=localtime(&t);
}
else if(ch=='3')
{
cout<<"3. 6 month ";
period=6;
time_t t=time(0)+86400*182;
ti=localtime(&t);
}
else if(ch=='4')
{
cout<<"4. 12 month ";
period=12;
time_t t=time(0)+86400*365;
ti=localtime(&t);
}
else
{
textcolor(RED);
gotoxy(40,18);
cprintf("wrong entry");
getch();
goto t;
}
getch();
cin.ignore();
clrscr();
it=asctime(ti);
strcpy(times,it);
gotoxy(30,1);
cout<<"INTERNET BILL:"<<endl;
gotoxy(5,3);
cout<<"Name:"<<fname<<" "<<lname<<endl;
gotoxy(5,4);
cout<<"D.O.B:"<<year<<"/"<<month<<"/"<<date<<endl;
gotoxy(5,5);
cout<<"Sex:"<<sex<<endl;
gotoxy(5,6);
cout<<"Phone no.:"<<PN<<endl;
gotoxy(5,7);
cout<<"Bandwidth:"<<bandwidth<<endl;
gotoxy(5,8);
cout<<"Expires on:"<<times<<endl;
gotoxy(5,9);
cout<<"total cost:";
ifstream ifile;
ifile.open(bandwidth);
ifile.read((char*)&O,sizeof(O));
ifile.close();
cost=O.price*period;
cout<<cost<<endl;
gotoxy(10,15);
cout<<"Press [ENTER] to proceed";
gotoxy(40,15);
cout<<"Press [ESC] to cancel";
while(1)
{
if(kbhit())
{
ch=getch();
if(ch==13)
{
clrscr();
gotoxy(16,3);
c=0;
cout<<"Set Username:";
/*
cin>>username;
	cin.clear();

	for(j=0;j<strlen(username);j++)
	{
		if(isalpha(username[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto Un;
		}
	}
	if(strlen(username)<4 || strlen(username)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto Un;
	}*/
while(c<10)
{
ch=getch();

if(isdigit(ch)||isalpha(ch)||ch=='.')
{
username[c]=ch;
cout<<username[c];
c++;
username[c]='\0';
}
if(ch==8&&c>0)
{
gotoxy(29+c-1,3);
cout<<" ";
gotoxy(29+c-1,3);
c--;
username[c]='\0';

}
if((ch==13||ch==9)&&c>6)
{
goto pass;
}
if((ch==9||ch==13)&&c<=5)
{
textcolor(RED);
gotoxy(40,3);
cprintf("username must be more than 6 words!");
getch();
textcolor(BLACK);
gotoxy(40,3);
cprintf("username must be more than 6 words!");
gotoxy(29+c,3);
textcolor(WHITE);
}
}
pass:
c=0;
gotoxy(16,4);
cout<<"Set Password:";
/*
cin>>password;
	cin.clear();

	for(j=0;j<strlen(password);j++)
	{
		if(isalpha(password[j])==0)
		{
			gotoxy(60,10);
			cout<<"only alphabets";
			delay(300);
			gotoxy(25,10);
			cout<<"          					 ";
			cin.clear();
			goto pw;
		}
	}
	if(strlen(password)<4 || strlen(password)>10)
	{
		gotoxy(60,9);
		cout<<"Too short/long";
		delay(300);
		gotoxy(26,9);
		cout<<"        					                         ";
		cin.clear();
		goto pw;
	}  */
while(c<10)
{
	ch=getch();
	if(isdigit(ch)||isalpha(ch)||ispunct(ch))
	{
		password[c]=ch;
		cout<<password[c];
		c++;
		password[c]='\0';
	}
	if(ch==8&&c>0)
	{
	gotoxy(29+c-1,4);
	cout<<" ";
	gotoxy(29+c-1,4);
	c--;
	password[c]='\0';

	}
	if((ch==13||ch==9)&&c>6)
	{
	return 0;
	}
	if((ch==9||ch==13)&&c<=5)
	{
	textcolor(RED);
	gotoxy(40,4);
	cprintf("password must be more tha 6 words!");
	getch();
	textcolor(BLACK);
	gotoxy(40,4);
	cprintf("password must be more than 6 words!");
	gotoxy(29+c,4);
	textcolor(WHITE);
	}
}

return 0;
}

}
}


}

int userlogin()
{
int a=0,ch,c=0;
char uname[10],password[10];
initgraphic();
cleardevice();
ubase();
fstream file;
do{
if(kbhit)                                            //check if a key is pressed
{
ch=getch();
if(ch=='a'||ch==75)                           	//move left
{
setcolor(BLACK);
rectangle(340,155,480,220);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("CREATE");

setcolor(15);
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("CREATE");

setcolor(BLACK);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("LOGIN");

setcolor(GREEN);
rectangle(200,155,320,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("LOGIN");

if(kbhit)
{
	ch=getch();
	if(ch==13)
	{
		closegraph();
		//login:
		clrscr();
		gotoxy(35,3);
		cout<<"USER LOGIN";
		gotoxy(30,6);
		cout<<"username:";
		cin>>uname;
		cin.clear();
		cin.ignore();
		gotoxy(30,7);
		cout<<"password:";
		cin>>password;
		cin.clear();
		cin.ignore();
		file.open("userifo.txt",ios::in);
		file.read((char*)&U,sizeof(U));
		while(!file.eof())
		{
		if(strcmp(U.username,uname)==0)
		{
		if(strcmp(U.password,password)==0)
		{
/*
gotoxy(5,3);
cout<<"Name:"<<U.fname<<" "<<U.lname<<endl;
gotoxy(5,4);
cout<<"D.O.B:"<<U.year<<"/"<<U.month<<"/"<<U.date<<endl;
gotoxy(5,5);
cout<<"Gender:"<<U.sex<<endl;
gotoxy(5,6);
cout<<"Phone no.:"<<U.PN<<endl;
gotoxy(5,7);
cout<<"Bandwidth:"<<U.bandwidth<<endl;
gotoxy(5,8);
cout<<"Expires On:"<<U.times<<endl;
gotoxy(5,9);
cout<<"Expires On:"<<U.username<<endl;
gotoxy(5,10);
cout<<"Expires On:"<<U.password<<endl;
getch();*/
clrscr();

		loginaccount(U);
		break;
		}
		else
		{
		cout<<"WRONG ENTRY";
		break;
		}
		}
		/*else
		{
		cout<<"WRONG ENTRY";
		goto login;
		} */
		file.read((char*)&U,sizeof(U));
		}
		file.close();
		clrscr();
		initgraphic();
		ubase();
	}
}
}

if(ch=='d'||ch==77)                          	//move right
{
setcolor(BLACK);
rectangle(200,155,320,220);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("LOGIN");

setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("LOGIN");

setcolor(BLACK);
rectangle(360,165,460,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("CREATE");

setcolor(GREEN);
rectangle(340,155,480,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("CREATE");
if(kbhit)
{
ch=getch();
if(ch==13)
{
closegraph();
cin.clear();
U.createaccount();


file.open("userifo.txt",ios::app);
file.seekp(0,ios::end);
file.write((char*)&U,sizeof(U));
file.close();


clrscr();
initgraphic();
ubase();
}
}

}
if(ch==27)
{
return 0;
}

}

}while(1);

}

void menu()
{
int a=0;
char ch;
initgraphic();
cleardevice();
mbase();
do{
if(kbhit)                                            //check if a key is pressed
{
ch=getch();

if(ch=='a'||ch==75)                           	//move left
{
setcolor(BLACK);
rectangle(340,155,460,220);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("USER");

setcolor(15);
rectangle(360,165,440,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USER");

setcolor(BLACK);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADMIN");

setcolor(GREEN);
rectangle(200,155,320,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("ADMIN");

if(kbhit)
{
ch=getch();
if(ch==13)
{
closegraph();
cin.clear();
adminlogin();
clrscr();
initgraphic();
mbase();
}
}
}

if(ch=='d'||ch==77)                          	//move right
{
setcolor(BLACK);
rectangle(200,155,320,220);
settextstyle(1,HORIZ_DIR,4);
moveto(215,170);
outtext("ADMIN");

setcolor(15);
rectangle(220,165,300,210);
settextstyle(1,HORIZ_DIR,2);
moveto(230,175);
outtext("ADMIN");

setcolor(BLACK);
rectangle(360,165,440,210);
settextstyle(1,HORIZ_DIR,2);
moveto(375,175);
outtext("USER");

setcolor(GREEN);
rectangle(340,155,460,220);
setcolor(1);
settextstyle(1,HORIZ_DIR,4);
moveto(360,170);
outtext("USER");
if(kbhit)
{
ch=getch();
cin.clear();
if(ch==13)
{
closegraph();
cin.clear();
userlogin();
clrscr();
initgraphic();
mbase();
}
}

}
if(ch==27)
{
exit(1);
}
}
}while(1);
/*int ch;
cout<<"enter"<<endl
<<"'1' to go to admin login page"<<endl
<<"'2' to go to user login page"<<endl
<<"choice:";
cin>>ch;
if(ch==1)
{
adminlogin();
}
else if(ch==2)
{
userlogin();
}
else
{
cout<<"wrong entry try again";
}
*/
}
int main()
{
clrscr();
menu();
return 0;
}
