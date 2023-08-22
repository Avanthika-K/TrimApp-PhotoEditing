//---------------------------------header files
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <alloc.h>
#include <fstream.h>
#include <process.h>
union REGS i,o;
//---------------------------------mouse fns
void initmouse()
{ i.x.ax=0;
  int86(0x33,&i,&o);
}
void showmouse()
{ i.x.ax=1;
  int86(0x33,&i,&o);
}
void hidem()
{ i.x.ax=2;
  int86(0x33,&i,&o);
}
void getmousestatus(int &b,int &x,int &y)
{ i.x.ax=3;
  int86(0x33,&i,&o);
  x=o.x.cx;
  y=o.x.dx;
  b=o.x.bx;
}
class BMP
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

  public:
     int ShowBMP(int,int,char*);
  };

 int BMP::ShowBMP(int x,int y,char* Filename)
 {
   int b, a;
   struct BMP Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=Obj.height;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,c);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }

    //CROP_OPTION;
   //class def. for showing ;
class BMPs
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

  public:
       int ShowBMPS(int,int,char*);
 };

 int BMPs::ShowBMPS(int x,int y,char* Filename)
 {
   int b, a;
   struct BMPs Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=Obj.height;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,c);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }

  //class def.for potrait crop;
   class BMPp
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

   public:
     int ShowBMPp(int,int,char*);
  };

 int BMPp::ShowBMPp(int x,int y,char* Filename)
 {
   int b, a;
   struct BMPp Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=256;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=250;a<=380;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,c);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }

  //class def.for landscape crop;
  class BMPl
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

   public:
       int ShowBMPl(int,int,char*);
 };


 int BMPl::ShowBMPl(int x,int y,char* Filename)
 {
   int b, a;
   struct BMPl Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=100;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,c);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   } //end of crop classes;


  //FixFilter_Option
  class BMP1
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

  public:
       int ShowBMPk(int,int,char*);
 };

 int BMP1::ShowBMPk(int x,int y,char* Filename)
 {
   int b, a;
   struct BMP1 Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=Obj.height;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,c);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }


   class BMP2
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

  public:
       int ShowBMPv(int,int,char*);
 };

 int BMP2::ShowBMPv(int x,int y,char* Filename)
 {
   int b, a;
   struct BMP2 Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=Obj.height;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,5);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }

   class BMP3
{
  char TYPE[2];
  unsigned long size ;
  unsigned long Reserved;
  unsigned long offset;
  unsigned long headsize;
  unsigned long width;
  unsigned long height;
  unsigned int planes;
  unsigned int bitsperpixel;
  unsigned long compression;
  unsigned long sizeimage;
  unsigned long Xpixelspremeter;
  unsigned long Ypixelspremeter;
  unsigned long colorsused;
  unsigned long colorsimportant;

  public:
       int ShowBMPg(int,int,char*);
 };

 int BMP3::ShowBMPg(int x,int y,char* Filename)
 {
   int b, a;
   struct BMP3 Obj;

   unsigned char* Datas;
   int in=0;
   unsigned char c=0;
   FILE * fp;
   fp=fopen(Filename,"rb");
   if(!fp){
   cout<<"\nError : Unale to open file..";
   exit(0);
   }


   fread(&Obj,sizeof(Obj),1,fp);
   if(Obj.bitsperpixel!=4)
    {
      fclose(fp);
      cout<<"\nError:File formt not supported..";
      exit(0);
    };

    fseek(fp,Obj.offset,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.width/2+1,sizeof(unsigned char));
    for(b=Obj.height;b>=0;b--)
    {
      fread(Datas,sizeof(unsigned char),Obj.width/2,fp);
      c=0;
      in=0;
      for(a=0;a<=Obj.width;a+=2)
      {
	c=(Datas[in] | 0x00) >>4;
	putpixel(a+x,b+y,c);
	c=(Datas[in] | 0xF0) & 0x0F;
	putpixel(a+1+x,b+y,2);
	++in;
       }
     }
     free(Datas);
     fclose(fp);
     return 1;
   }                //end of Fixfilter classes;
void crop()   //------------------------------------crop ()
{    int gd,gm,b=0,x,y,e;
     clrscr();
     int color,m;
     gd=VGA;
     gm=VGAHI;
     initgraph(&gd,&gm,"C://TURBOC3//BGI");
     char *fname;
     setcolor(CYAN);
 outtextxy(100,40,"_____________________________________________________");
 outtextxy(100,45,"_____________________________________________________");
 outtextxy(100,345,"____________________________________________________");
 outtextxy(100,350,"____________________________________________________");
     settextstyle(6,0,4);
     setcolor(YELLOW);
     outtextxy(150,110,"ENTER YOUR FILE NAME: ");
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ";
     gets(fname);
     char *temp=fname;
     gd=VGA;
     gm=VGAHI;
     clrscr();
     initgraph(&gd,&gm,"C://TURBOC3//BGI");
     e=graphresult();
     if(e)
     { clrscr();
      cout<<"error code no: "<<e;
      getch();
      exit(1);
      }
     setcolor(LIGHTBLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");

      settextstyle(6,0,4);
      setcolor(WHITE);
      outtextxy(80,80,"|>OPTIONS");
      settextstyle(6,0,4);
      setcolor(CYAN);
      outtextxy(80,150,"|>PORTRAIT");
      rectangle(75,149,270,195);
      settextstyle(6,0,4);
      setcolor(LIGHTMAGENTA);
      outtextxy(80,200,"||>LANDSCAPE");
      rectangle(75,199,270,240);

      BMP S;
      S.ShowBMP(280,80,temp);
      initmouse();
      showmouse();
      while(b==0)
	getmousestatus(b,x,y);
      hidem();
	 //--------------------------------- potrait crop;
	 if(x>75&&x<270&&y>149&&y<195)
	   {	   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(LIGHTBLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");
		   setcolor(YELLOW);
		   settextstyle(6,0,4);
		   outtextxy(100,200,"PROCESSING...PLEASE WAIT!");
		   for( m=80;m<380;m++)
		      {
			 circle(50+m,275,10);
			 delay(10);
		       }
		   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(LIGHTBLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,400,"____________________________________________________");
 outtextxy(100,405,"____________________________________________________");
		   setcolor(YELLOW);
		   settextstyle(6,0,4);
		   outtextxy(150,80,"PROCESS COMPLETED!");
		   BMPp P;
		   P.ShowBMPp(10,130,temp);
	       }
	else   if(x>75&&x<270&&y>199&&y<240)//-------landscape crop
		 {  clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(LIGHTBLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");
		   setcolor(YELLOW);

		   settextstyle(6,0,4);
		   outtextxy(100,150,"PROCESSING...PLEASE WAIT!");
		   for( m=80;m<380;m++)
		      {
			 circle(50+m,275,10);
			 delay(10);
		       }

		   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(LIGHTBLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,400,"____________________________________________________");
 outtextxy(100,405,"____________________________________________________");
		   setcolor(YELLOW);

		   settextstyle(6,0,4);
		   outtextxy(150,100,"PROCESS COMPLETED!");
		   BMPl L;
		   L.ShowBMPl(200,150,temp);
		   }
		else
		{ clrscr();
		 gd=VGA;
		 gm=VGAHI;
		 initgraph(&gd,&gm,"C://TURBOC3//BGI");
		 settextstyle(6,0,4);
		 setcolor(YELLOW);
		 outtextxy(80,100,"You Have Entered a Wrong Choice!!");
		  }
}
void fltr()        //-------------------------------fltr()
{     clrscr();
      int color,m;
      int gd,gm,b=0,x,y;
      gd=VGA;
      gm=VGAHI;
      initgraph(&gd,&gm,"C://TURBOC3//BGI");
      char *fname;
      setcolor(CYAN);
 outtextxy(100,40,"_____________________________________________________");
 outtextxy(100,45,"_____________________________________________________");
 outtextxy(100,345,"____________________________________________________");
 outtextxy(100,350,"____________________________________________________");
     settextstyle(6,0,4);
     setcolor(YELLOW);
     outtextxy(150,110,"ENTER YOUR FILE NAME: ");
      cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ";
      gets(fname);
      char *temp=fname;
      clrscr();
      gd=VGA;
      gm=VGAHI;
      initgraph(&gd,&gm,"C://TURBOC3//BGI");
      setcolor(YELLOW);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");

      settextstyle(6,0,4);
      setcolor(WHITE);
      outtextxy(80,80,"|>OPTIONS");
      settextstyle(6,0,4);
      setcolor(CYAN);
      outtextxy(80,150,"|>VIOLET");
      rectangle(75,145,250,190);
      settextstyle(6,0,4);
      setcolor(YELLOW);
      outtextxy(80,200,"|>|>GREEN");
      rectangle(75,197,250,245);
      BMP1 A;
      A.ShowBMPk(280,80,temp);
	initmouse();
	showmouse();
	while(b==0)
	  getmousestatus(b,x,y);
	hidem();
	   //---------------------------------- violet Filter;
	    if(x>75&&x<250&&y>145&&y<190)
	      {	   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(BLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");
		   setcolor(CYAN);
		   settextstyle(6,0,4);
		   outtextxy(100,200,"PROCESSING...PLEASE WAIT!");
		   for( m=80;m<380;m++)
		      {
			 circle(50+m,275,10);
			 delay(10);
		       }
		   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(BLUE);
 outtextxy(100,20,"_____________________________________________________");
 outtextxy(100,25,"_____________________________________________________");
 outtextxy(100,410,"____________________________________________________");
 outtextxy(100,415,"____________________________________________________");
		   setcolor(CYAN);
		   settextstyle(6,0,4);
		   outtextxy(150,55,"PROCESS COMPLETED!");
		   BMP2 V;
		   V.ShowBMPv(200,150,temp);
		   delay(1000);
	       }

	  //---------------------------------- GREEN Filter
	 else  if(x>75&&x<250&&y>197&&y<245)
		 {  clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(BLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,380,"____________________________________________________");
 outtextxy(100,385,"____________________________________________________");
		   setcolor(CYAN);
		   settextstyle(6,0,4);
		   outtextxy(80,200,"PROCESSING...PLEASE WAIT!");
		   for(  m=80;m<380;m++)
		      {
			 circle(50+m,275,10);
			 delay(10);
		       }

		   clrscr();
		   gd=VGA;
		   gm=VGAHI;
		   initgraph(&gd,&gm,"C://TURBOC3//BGI");
		   setcolor(BLUE);
 outtextxy(100,50,"_____________________________________________________");
 outtextxy(100,55,"_____________________________________________________");
 outtextxy(100,410,"____________________________________________________");
 outtextxy(100,415,"____________________________________________________");
		   setcolor(CYAN);
		   settextstyle(6,0,4);
		   outtextxy(150,60,"PROCESS COMPLETED!");
		   BMP3 G;
		   G.ShowBMPg(200,150,temp);
		  }

	 else
	      {	 clrscr();
		 gd=VGA;
		 gm=VGAHI;
		 initgraph(&gd,&gm,"C://TURBOC3//BGI");
		 settextstyle(6,0,4);
		 setcolor(YELLOW);
		 outtextxy(80,100,"You Have Entered a Wrong Choice!!");
	       }



 }//ftr() close
//------------------------------------main()------------------------------
//------------------------------------------------------------------------
void main()
{//char cn;
 int b,x,y;
 char *fname,*Fname,*temp,*Temp;
 int choice;
 int c,m;
 int color;
 clrscr();
 int gd=DETECT,gm=0;
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
 rectangle(14,24,546,446);
 rectangle(18,28,542,442);

 setbkcolor(MAGENTA);
 settextstyle(7,0,5);
 for(int i=10;i<=14;i++)
 {
  delay(550);
  setcolor(i);
  line(100,100,100,80);
  line(100,80,120,80);
  line(100,160,100,180);
  line(100,180,120,180);

  outtextxy(120,100,"|>TRIMAPP");
 }
 for(int k=1;k<=10;k++)
 {
   delay(180);
   settextstyle(1,HORIZ_DIR,4);
   setcolor(k);
   outtextxy(170,210,"LIFE NEEDS EDITING...!!");
 }
 settextstyle(1,HORIZ_DIR,3);
 setcolor(15);
 outtextxy(140,280,"LOADING...");
 setcolor(7);
 settextstyle(1,HORIZ_DIR,2);
 setcolor(14);
 outtextxy(330,340,"BY:");
 setcolor(15);
 outtextxy(298,360,"K.AVANTHIKA");
 outtextxy(298,380,"B.SWEATHAA VARTHINE ");
 for( m=80;m<380;m++)

 {
   circle(50+m,275,10);
   delay(10);
 }
 clrscr();
 gd=DETECT,gm=0;
 initgraph(&gm,&gd,"C://TURBOC3//BGI");
 int a,j,l;
 char ch;
     settextstyle(7,0,2);
     setcolor(WHITE);
     outtextxy(185,50," |> HOW TO USE ?");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,80," Any image by default will be in ");
     settextstyle(7,0,1);
     setcolor(RED);
     outtextxy(290,80,"JPG");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(330,80,"format .");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,100,"First convert it to ");
     settextstyle(7,0,1);
     setcolor(RED);
     outtextxy(180,100,"BMP");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(230,100,"format .");
     settextstyle(6,0,1);
     setcolor(WHITE);
     outtextxy(40,135,"   |> How To Convert JPG -> BMP ?");
     setcolor(WHITE);
     outtextxy(40,140,"________________________________");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,170,"|>Open the image to be used in 'PAINT' application.");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,190,"|>Choose 'RESIZE',in that choose 'PIXELS'.Set");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(400,190,"'Horizontal Value' to 256. ");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,210,"|>Goto 'Save As',choose 'BMP PICTURE'.");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,230,"|>A 'WARNING' message will appear on the screen. ");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(420,230,"Click 'OK'");
     outtextxy(40,250,"|>Choose the location to be BIN folder in TURBOC++.");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,270,"|>Give a name and choose format option below that.");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,290,"|>Choose '16-Color bitmap' option");
     settextstyle(6,0,1);
     setcolor(YELLOW);
     outtextxy(40,310,"|>'SAVE' the picture");
     b=0;
     setcolor(LIGHTMAGENTA);
     settextstyle(6,0,3);
     outtextxy(150,360,"MENU");
     rectangle(145,358,220,395);
     rectangle(143,356,223,398);
     outtextxy(300,360,"EXIT");
     rectangle(295,358,370,395);
     rectangle(293,356,373,398);
     initmouse();
     showmouse();
     while(b==0)
       getmousestatus(b,x,y);
     hidem();
     clrscr();
   if(x>145&&x<220&&y>358&&y<395)
 { //  do{
     b=0;
     initmouse();
     clrscr();
     gd=VGA;
     gm=VGAHI;
     initgraph(&gd,&gm,"C://TURBOC3//BGI");
     settextstyle(6,0,4);
     setcolor(YELLOW);
     outtextxy(210,95,"MENU");
     settextstyle(6,0,4);
     setcolor(LIGHTMAGENTA);
     outtextxy(150,145,"|>CROP");
     rectangle(145,143,350,185);
     outtextxy(150,195,"|>|>FIXFILTER");
     rectangle(145,193,350,235);
     outtextxy(150,245,"|>|>|>EXIT");
     rectangle(145,243,350,285);
     settextstyle(6,0,5);
      setcolor(CYAN);
 outtextxy(100,40,"_____________________________________________________");
 outtextxy(100,45,"_____________________________________________________");
 outtextxy(100,285,"____________________________________________________");
 outtextxy(100,290,"____________________________________________________");

     delay(200);
     showmouse();
     while(b==0)
       getmousestatus(b,x,y);
     hidem();
    if(x>145&&x<350&&y>143&&y<185)
      { clrscr();
	crop();
	 /*cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
	  cout<<"Do You Want To Continue?(y/n): ";
	  cin>>cn;*/
      }
    else
	if(x>145&&x<350&&y>193&&y<235)
	  { clrscr();
	    fltr();
	  /*cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t";
	    cout<<"Do You Want To Continue?(y/n): ";
	    cin>>cn;*/
	  }
	else
	   { if(x>145&&x<350&&y>243&&y<285)
	      { clrscr();
		 gd=VGA;
		 gm=VGAHI;
		 initgraph(&gd,&gm,"C://TURBOC3//BGI");
		 setbkcolor(BLACK);
		 settextstyle(7,0,5);
		 setcolor(WHITE);
		 rectangle(14,24,546,446);
		 rectangle(18,28,542,442);
		 for( i=10;i<=14;i++)
		   {
		      delay(550);
		      setcolor(i);
		      line(100,100,100,80);
		      line(100,80,120,80);
		      line(100,160,100,180);
		      line(100,180,120,180);
		      outtextxy(80,100,"You Have EXITED!!");
		   }
		   delay(900);
		   clrscr();
		   exit(0);
		// cn='n';

	       }//else closed
   }//if                          }while(cn=='y'||cn=='Y');
  }
else                      //menu else open
 {clrscr();
		 gd=VGA;
		 gm=VGAHI;
		 initgraph(&gd,&gm,"C://TURBOC3//BGI");
		 setbkcolor(BLACK);
		 settextstyle(7,0,5);
		 setcolor(WHITE);
		 rectangle(14,24,546,446);
		 rectangle(18,28,542,442);
		 for( i=7;i<=14;i++)
		   {
		      delay(550);
		      setcolor(i);
		      line(100,100,100,80);
		      line(100,80,120,80);
		      line(100,160,100,180);
		      line(100,180,120,180);
		      outtextxy(80,100,"You Have EXITED!!");
		   }
		   delay(900);
		   clrscr();
		   exit(0);
     }//menu else close
 getch();
 closegraph();
} //main() close



