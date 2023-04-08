#include<dos.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>
#include<conio.h>
char Item[22][25]={"GOLGAPPA AATA","GOLGAPPA SUJI","MOMOAS","AALOO TICKKI",


		      "DAHI BADA","KHASTA","KARELA","MATAR","TAMATAR","PAPRI"


		      ,"BATI CHOKHA","CHATNI KACHAURI","DAHI BADA",


		       "GULAB JAMUN","GUJIA","GAJAR KA HALWA"};


  float PRICE[]={10,15,30,15,15,10,10,10,10,10,20,20,20,10,20,20};

void Dish()
  {
  int r=1;
  clrscr();
  gotoxy(31,r); cout<<"MODI  CHAT  CORNER";
  gotoxy(30,++r); cout<<"---------------------";
  gotoxy(1,++r);


  for(int i=0;i<70;i++)
  cout<<'-';
  gotoxy(1,++r); cout<<'|';
  gotoxy(4,r); cout<<"S_No";
  gotoxy(10,r); cout<<'|';
  gotoxy(19,r); cout<<"DESCRIPTION";
  gotoxy(50,r); cout<<'|';
  gotoxy(58,r); cout<<"PRICE";
  gotoxy(70,r); cout<<'|';
  gotoxy(1,++r);
  for(i=0;i<70;i++)
  cout<<'-';
  for(i=0;i<16;i++)
  {
   gotoxy(1,++r); cout<<'|';
   gotoxy(5,r); cout<<i+1;
   gotoxy(10,r); cout<<'|';
   gotoxy(13,r); cout<<Item[i];
   gotoxy(50,r); cout<<'|';
   gotoxy(60,r); cout<<PRICE[i];;
   gotoxy(70,r); cout<<'|';
  }
  gotoxy(1,++r);
  for(i=0;i<70;i++)
   cout<<'-';
 }

fstream sfile;
class bill
{
 int item_no[15],bill_no,dd,mm,yy,qty[15],x;
 float price[15],g_total;
 char dish[15][25],plate[16];
 public:
 void read(int b)
 {
 struct dosdate_t d;
    _dos_getdate(&d);
    dd=d.day;
    mm=d.month;
    yy=d.year;
       bill_no=b;


 x=0;
 float tot=0;
 g_total=0;
 char ch='y';
 while(ch!='n')
 {
  Dish();
  tot=0;
  cout<<"\nEnter the item_no : ";
  cin>>item_no[x];
  int k = item_no[x];
    cout<<"Enter H for HALF PLATE and F for FULL PLATE : ";
  cin>>plate[x];
  if(islower(plate[x]))
  plate[x]=toupper(plate[x]);
  cout<<"Enter Quantity : ";
  cin>>qty[x];
  price[x]=PRICE[k-1];
  strcpy(dish[x],Item[k-1]);
  if(plate[x]=='H')
  {
  tot=(price[x]/2)*qty[x];
  }
  else
  tot=price[x]*qty[x];
  g_total+=tot;
  x++;
  plate[x]='\0';
  cout<<"Do you want more item : ";
  cin>>ch;
 }
 cash_memo();
 }
void cash_memo()
{ clrscr();
   int r=1;
  clrscr();

  gotoxy(31,r); cout<<"MODI  CHAT  CORNER";
  gotoxy(30,++r); cout<<"---------------------";
  gotoxy(1,++r);  cout<<"Bill No : "<<bill_no;
  gotoxy(65,r);  cout<<"Date : "<<dd<<'/'<<mm<<'/'<<yy;

  gotoxy(1,++r);


  for(int i=0;i<80;i++)
  cout<<'-';
  gotoxy(1,++r); cout<<'|';
  gotoxy(3,r); cout<<"S_No";
  gotoxy(8,r); cout<<'|';
  gotoxy(10,r); cout<<"I_NO";
  gotoxy(15,r); cout<<'|';
  gotoxy(22,r); cout<<"DESCIRPTION";
  gotoxy(41,r); cout<<'|';
  gotoxy(43,r); cout<<"P_TYP";

  gotoxy(49,r); cout<<'|';
  gotoxy(51,r); cout<<"QTY";
  gotoxy(55,r); cout<<'|';
  gotoxy(59,r); cout<<"PRICE";
  gotoxy(67,r); cout<<'|';
  gotoxy(71,r); cout<<"TOTAL";

  gotoxy(80,r); cout<<'|';

  gotoxy(1,++r);
  for(i=0;i<80;i++)
  cout<<'-';
  for(i=0;i<x;i++)
     {
     gotoxy(1,++r); cout<<'|';
      gotoxy(4,r);  cout<<i+1;
      gotoxy(8,r); cout<<'|';

      gotoxy(11,r);   cout<<item_no[i];
      gotoxy(15,r); cout<<'|';

      gotoxy(19,r);   cout<<dish[i];
       gotoxy(41,r); cout<<'|';

      gotoxy(45,r);   cout<<plate[i];
       gotoxy(49,r); cout<<'|';

      gotoxy(52,r);   cout<<qty[i];
      gotoxy(55,r); cout<<'|';

      gotoxy(58,r);   cout<<price[i];
       gotoxy(67,r); cout<<'|';

      gotoxy(70,r);
      if(plate[i]=='H')
       cout<<(price[i]/2)*qty[i];
      else
       cout<<qty[i]*price[i];
     gotoxy(80,r); cout<<'|';

     }
    gotoxy(1,++r);    for(i=0;i<80;i++)       cout<<"-";
    gotoxy(1,++r);    cout<<"Grand Total:";
    gotoxy(70,r);     cout<<g_total;
    gotoxy(1,++r);    cout<<"GST:";
    int d=g_total*4/100;
    gotoxy(71,r);     cout<<d;
    gotoxy(1,++r);    for(int j=0;j<80;j++)   cout<<"-";
    gotoxy(55,++r);   cout<<"Total:";
    float f=g_total+d;
    gotoxy(70,r);     cout<<f<<'\n';
    gotoxy(55,r+=2);  cout<<"Signature:"<<'\n';
   }

 //getch();
// }
 int reteno()
   {
    return bill_no;
   }


}s;
void main()
{
 clrscr();
   cout<<"\n";
   cout<<"\t************************************************************"
       <<"*****\n";
   cout<<"\t*                      WELCOME TO THE                           *\n";
   cout<<"\t*                     ~~~~~~~~~~~~~~~~                          *\n";
   cout<<"\t*                        PROJECT ON                             *\n";
   cout<<"\t*                       ~~~~~~~~~~~~                            *\n";
   cout<<"\t*                    MODI CHAT CORNER                           *\n";
   cout<<"\t*            *       ~~~~~~~~~~~~~~~~~~~                        *\n";
   cout<<"\t*           * *                                                 *\n";
   cout<<"\t*         *     *                                               *\n";
   cout<<"\t*        * * * * *                                              *\n";
   cout<<"\t*      *     U     *                                            *\n";
   cout<<"\t*     *   @     @   *                                           *\n";
   cout<<"\t*     *     _I_     *                                           *\n";
   cout<<"\t*      *  +=+=+=+  *                    PRERARED BY:            *\n";
   cout<<"\t*       *   ~~~   *                     ~~~~~~~~~~~             *\n";
   cout<<"\t*         * * * *                      ISHITA MAURYA            *\n";
   cout<<"\t*                                           XII-B               *\n";
   cout<<"\t*                                       (2017 - 2018)           *\n";
   cout<<"\t*   GUIDED BY:                                                  *\n";
   cout<<"\t*  ~~~~~~~~~~~~                                                 *\n";
   cout<<"\t*  MRS. ARCHANA AGARWAL                                         *\n";
   cout<<"\t************************************************************"
       <<"*****\n";
   cout<<"\nPress any key to cotinue";

   getch();

 sfile.open("CHATSALE.DAT",ios::in|ios::out|ios::binary);    //OPENING OF FILE "SALE.DAT"
    int sx;
    unsigned long sib,slb;
    sib=0;
    sfile.seekg(0,ios::end);
    slb=sfile.tellp();
    if(slb==0)
     sx=0;
    else
     {
      sfile.seekg(slb-sizeof(s),ios::beg);

      sfile.read((char*)&s,sizeof(s));
      sx=s.reteno();
     }
    int n;
    char ch=' ';
    while(ch!='n')
     {
      clrscr();
	   clrscr();
  for( int j=0;j<25;j++)
  {
   gotoxy(2,1+j);cout<<"$";
   gotoxy(79,1+j);cout<<"$";
  }
  for(j=0;j<78;j++)
  {
   gotoxy(2+j,25);cout<<"$";
   gotoxy(2+j,1);cout<<"$";
  }
  gotoxy(31,2); cout<<"MODI  CHAT  CORNER";
  gotoxy(30,3); cout<<"---------------------";

  gotoxy(20,5);cout<<"************** MAIN MENU ***************";
  for(int i=0;i<14;i++)
  {
   gotoxy(20,6+i);cout<<"*";
   gotoxy(59,6+i);cout<<"*";
  }
  for( i=0;i<40;i++)
  {
   gotoxy(20+i,19);cout<<"*";
  }
  gotoxy(22,8);  cout<<" 1 For Display the Item List ";
  gotoxy(22,11);  cout<<" 2 For Order From Customer ";
  gotoxy(22,14);  cout<<" 3 For Display all Bills";
  //getch(); exit(0);
  gotoxy(22,17);  cout<<" 4 For Exit";
   gotoxy(12,22);cout<<"Enter Choice : ";
  int n;
   cin>>n;

      switch(n)
       {
       case 1:
	Dish();
	break;
	case 2:                                            //CASE 1 TO READ THE DETAILS OF THE ITEMS
	char che=' ';
      sfile.seekg(0,ios::end);
      while(che!='n')
       {
	  s.read(++sx);
	  sfile.write((char*)&s,sizeof(s));
	  cout<<"\nDo you want to read more?:\n";           cin>>che;
       }
      break;
      case 3:                               //CASE 5 TO DISPLAY THE WHOLESALES ITEM
      sib=0;
      sfile.seekg(0,ios::end);
      slb=sfile.tellp();
      sfile.seekg(0);
      while(sib!=slb)
       {
	  sfile.seekg(sib,ios::beg);
	  sfile.read((char*)&s,sizeof(s));
	  s.cash_memo();
	  getch();
	  sib+=sizeof(s);
       }
      break;
      default:
      exit(0);
     }
   cout<<"\n\n\n\t\t\tDo you want more operation y/n  :";
   cin>>ch;
   }
 sfile.close();                              //CLOSING OF THE FILE
}
