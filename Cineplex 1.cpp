
/**

Name of the project : Cineplex_Booking_System
Size : 80 kb
Compiler : GNU/GCC
IDE used : code::blocks 16.01


Description :

    CINE_FUN ( Cineplex_Booking System) is movie booking cum Cineplex management program.
    It offers two modes-
        1.Admin
            Admin mode is password protected. The password can be changed any  time.
            Admin has the authority to insert,update and delete a movie and to change the ticket cost.
        2.User Mode
            User mode facilitates booking a ticket, cancelling a ticket, displaying tickets and screen status in
            the back drop of an extremely interactive interface. The program offers  user friendly  functions and
            display. The program is completely tested and is flawless. It  keeps the account of availability of seats,
            variation in ticket cost and even compute the total cost of tickets.

*/
//===========================================================
/*---------------------------------Header Files used-------------------------------------------------*/

#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<fstream>
#include <windows.h>
#include<process.h>
#include<iomanip>
#define MAX 100
#define sk 'X'

using namespace std;




/*-----------------------------------MISCELLANEOUS FUNCTIONS & CLASSES-----------------------------------------------------*/
void welcomescr()
{
   cout<<"|\t\t***** Welcome To Cinepolis_Cinemas *****";
   cout<<"|";
   cout<<"|\t\t <<<PRESS ANY KEY TO CONTINUE>>>";
   cout<<"+------------------------------------------------------------------------------------";
       cout<<"- -";

}

void loading()
{
    char ch=219;
    int i,j,k;

       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t \t\t      Loading...\n\t\t\t\t \t\t ____________________";

       cout<<"\n\t\t\t\t \t\t |";

       for(k=0;k<2;k++)
   {

      for(i=0;i<9;i++)
   {
       for(j=0;j<19999999;j++)
        ;
       cout<<ch;

   }


   }

cout<<"|\n\t\t\t\t \t\t";


}

void update_price()
{
     float p;
    ifstream fin("pd.dat",ios::binary|ios::in);
     cout<<"\n The current rates are : ";
    fin.read((char*)&p,sizeof(p));
    cout<<"\n\n  Premium :  Rs."<<p;
    fin.read((char*)&p,sizeof(p));
    cout<<"\n\n  Gold    :  Rs."<<p;
    fin.read((char*)&p,sizeof(p));
    cout<<"\n\n  Silver  :  Rs."<<p;
    fin.close();
    ofstream fout("pd.dat",ios::binary|ios::out);
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";


    cout<<"\n\n Enter the new rates : ";
    cout<<"\n\n\n  Premium :  Rs.";
    cin>>p;
    fout.write((char*)&p,sizeof(p));
cout<<"\n\n  Gold    :  Rs.";
        cin>>p;
    fout.write((char*)&p,sizeof(p));
cout<<"\n\n  Silver  :  Rs.";
        cin>>p;
    fout.write((char*)&p,sizeof(p));
    fout.close();


}



void show_time_slot(int n)      //function to view the 4 time slots of screen
{
    if(n==1)
        cout<<" 9 : 00 AM";
    if(n==2)
        cout<<"12 : 15 PM";
        if(n==3)
        cout<<" 3 : 30 PM";
        if(n==4)
        cout<<" 7 : 00 PM";
}

int convert_odd(int n)          //function to convert the number to odd natural number
{

    if(n>24)
        n=n-12;
    n=n/2;
    return n;
}

char*disp_avail(int n)         //function to check if the screen or slot is available
{

    if(n)
        return "NOT AVAILABLE";
    else
        return "AVAILABLE";

}

ifstream ufil;

class seat                  //class representing seats in every screen
{

    char r;                 //represents row number of seat
    int c;                  //represents column number of the seat
    float price;            //represents the price for seat category
    char category[MAX];     //represents category of the seat like gold, premium or silver
    void assign_category()  //assigns category to an object of seat
    {
        if(r<='D'&&r>='A')
            strcpy(category,"PREMIUM");
        else if(r>='E'&&r<='H')
            strcpy(category,"GOLD");
        else
            strcpy(category,"SILVER");
    }
   void set_price()         //assigns price to an object of seat
   {
       float p,p1,p2,p3;
    ifstream fin("pd.dat",ios::binary|ios::in);
     fin.read((char*)&p,sizeof(p));
    p1=p;
     fin.read((char*)&p,sizeof(p));
    p2=p;
           fin.read((char*)&p,sizeof(p));
    p3=p;
    fin.close();

       if(strcmpi(category,"PREMIUM")==0)   //checking the category and assigning price accordingly
        price=p1;
       else if(strcmpi(category,"GOLD")==0)
        price=p2;
        else
        price=p3;
   }
public :
    seat()          //default constructor which sets the default values
    {
        r=0;
        c=0;
        strcpy(category,"NA");
        assign_category();
        set_price();
    }

    void rset_seat()        //function called when a seat is canceled
    {
        r=0;c=0;strcpy(category,"NA");
        assign_category();
        set_price();

    }
    char get_r(){return r;}         //getter function to get number of rows

    int get_c(){return c;}          //getter function to get number of columns

    void get_seat()                 //function to enter the seat, set its category and set its price
    {
        cout<<"\n Enter the seat : ";
        cout<<"\n\t\t\t\t\t\tROW : ";
        cin>>r;
        cout<<"\n\t\t\t\t\t\tCOLUMN : ";
        cin>>c;
        r=toupper(r);
        assign_category();          //assigning category
        set_price();                //assigning price
    }

    float get_price()               //function to set price by the user
    {
       assign_category();           //getting category
       set_price();
        return price;               //returning assigned price
    }

    void disp_seat()                //function to display seat number while displaying ticket
    {
        if(c<10)
        cout<<r<<"  "<<c;
        else
            cout<<r<<' '<<c;
    }

};


/*----------------------------------ADMIN------------------------------------------------------------------------*/

class admin             //class for setting a username and password for administrator
{
private:
    char admin_name[25];
    char a_pass[10];
    long int admin_ID;

public:
    admin()                 //default constructor
    {
        strcpy(admin_name,"Not Alotted");
        strcpy(a_pass,"password");
        admin_ID=12345678;
    }
   void set_admin_name()           //getter function to get admin name
   {
       gets(admin_name);
   }
   void set_pass()                 //function to set password
   {
    char pass[10],ch;int i=-1;
    cout<<"\n\t\t\t\t\t\tEnter Password : ";
    do
    {
        ch=getch();         //this makes the entered password invisible
         pass[++i]=ch;
    }
    while(ch!='\r');        //take characters until the user press enter key

    pass[i]='\0';
    strcpy(a_pass,pass);    //setting the password

   }

   void get_a_id()          //function to get admin ID
    {
        cin>>admin_ID;
    }

    int check_pass()            //function to check the user entered password
    {
    pass_check :                //label for goto at the end of function
    char pass[10],ch;int i=-1;
    cout<<"\n\t\t\t\t\t\tEnter Password : ";
    do                          //loop for entering password
    {
        ch=getch();
        pass[++i]=ch;
    }
    while(ch!='\r');
    pass[i]='\0';
    if(strcmp(pass,a_pass)==0)   //checking if the password is correct
        return 1;
    else                         //else function moves the program to pass_check
        {
            cout<<"\n \t\t\t\t\t\tWRONG PASSWORD !!! \n\n\t\t\t\t\t\t<<Press a key to enter again>> ";

            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cin.get();
            goto pass_check;
        }
    }



};

admin ADMIN;            //object of class admin is declared

//--------------------------------SLOT-------------------------------------------------------------------------
class slot
{
    int mat[12][12];
    int slot_num;
    int tot_s,booked_seat;
public:
    slot()
    {
        for(int i=0;i<12;i++)
            for(int j=0;j<12;j++)
            mat[i][j]=0;
        slot_num=0;
        tot_s=0;
        booked_seat=0;

    }
     int ck(char r,int c)
     {
         int i=r;
         i-=65;

         if(mat[i][c-1]==1)
         {
             cout<<"\n\n\t\t\t\t\tAlready Booked !!!    Enter  again\n\n";
             return 1;
         }
         return 0;

     }
     void bk_seat(char r,int c)         //function books the seat with r row and c column
     {
         int i=r;
         i-=65;
         mat[i][c-1]=1;
         booked_seat++;
     }
    void canc_seat(char r,int c)        //function cancels the seat with r row and c column
    {
        int i=r;
         i-=65;
         mat[i][c-1]=0;
         booked_seat--;
    }
    void reset_seat(char r,int c)           //function that resets a seat when ticket is cancelled
    {
        int i=r;
        i-=65;
        mat[i-1][c-1]=0;
    }
    void reset_slot()                       //function to free all seats
    {
        for(int i=0;i<12;i++)
            for(int j=0;j<12;j++)
            mat[i][j]=0;
    }
    int get_avail()                         //function to check if seat is available
    {
        if(booked_seat==144)
            return 1;
        else
            return 0;
    }
    void disp_slot()                        //function to display screen status
    {
        int i,j;
        char k='A',ch='_';
        cout<<"\n\n\n";
        //  cout<<"\t\t\t  1   2   3   4   5   6                         7   8   9  10  11  12 \n";
        cout<<"\t\t        -----------------------------------------------------------------------\n";
        cout<<"\t\t        | 1   2   3   4   5   6         PREMIUM         7   8   9  10  11  12 |";
        cout<<"\n\t\t        -----------------------------------------------------------------------\n";
         for(i=0;i<4;i++)
       {

        cout<<"\t\t\t";
        for(j=0;j<36;j++)
        {
            if(j<24&&j>12)
                {
                    if(j==18)
                       cout<<k++;
                    else
                        cout<<"  ";
                }
            else  if(j%2==0)
                    cout<<'|';

            else if(mat[i][convert_odd(j)]==1)
              {
                  cout<<'_'<<sk<<'_';

              }
            else
                    cout<<"___";
        }
        cout<<"|\n";

    }
    cout<<"\t\t        -----------------------------------------------------------------------\n";
     //cout<<"\t\t        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";

    cout<<"\n\t\t        -----------------------------------------------------------------------\n";
   cout<<"\t\t        | 1   2   3   4   5   6          GOLD           7   8   9  10  11  12 |";
   cout<<"\n\t\t        -----------------------------------------------------------------------\n";
   for(i=4;i<8;i++)
    {

        cout<<"\t\t\t";
        for(j=0;j<36;j++)
        {
            if(j<24&&j>12)
                {
                    if(j==18)
                       cout<<k++;
                    else
                        cout<<"  ";
                }
            else  if(j%2==0)
                    cout<<'|';

            else if(mat[i][convert_odd(j)]==1)
              {
                  cout<<'_'<<sk<<'_';

              }
            else
                    cout<<"___";
        }
        cout<<"|\n";

    }
   cout<<"\t\t        -----------------------------------------------------------------------\n";
//cout<<"\t\t        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";

   cout<<"\n\t\t        -----------------------------------------------------------------------\n";
   cout<<"\t\t        | 1   2   3   4   5   6         SILVER          7   8   9  10  11  12 |";
   cout<<"\n\t\t        -----------------------------------------------------------------------\n";
    for(i=8;i<12;i++)
    {

        cout<<"\t\t\t";
        for(j=0;j<36;j++)
        {
            if(j<24&&j>12)
                {
                    if(j==18)
                       cout<<k++;
                    else
                        cout<<"  ";
                }
            else  if(j%2==0)
                    cout<<'|';

            else if(mat[i][convert_odd(j)]==1)
              {
                  cout<<'_'<<sk<<'_';

              }
            else
                    cout<<"___";
        }
        cout<<"|\n";

    }
cout<<"\t\t        -----------------------------------------------------------------------\n";
cout<<"\n\n\n\t\t        -----------------------------------------------------------------------\n";

cout<<"\t\t        |>>>>>>>>>>>>>>>>>>             SCREEN               <<<<<<<<<<<<<<<<<|";
cout<<"\n\t\t        -----------------------------------------------------------------------\n";


    }
};


//--------------------------------SCREEN----------------------------------------------------------------------


class screen                //class that defines the screen which has 4 slots
{
private :
    slot s[4];
    int s_stat[4];
public:
    int scr_num;
    int max_shows;
     screen()                       //default constructor
    {
        scr_num=0;
        max_shows=4;
        for(int i=0;i<4;i++)
            s_stat[i]=0;
    }

   int get_slot(int n)              //getter function
   {
       return s_stat[n-1];
   }

    void reset_screen(int n)        //function to reset screen
    {
        s[n-1].reset_slot();
    }

    void set_m_slot(int n)          //function to allocate a movie to a screen
    {
        s_stat[n-1]=1;
        max_shows--;
    }

    void reset_m_slot(int n)        //function to deallocate a movie to a screen
     {
         max_shows++;
         s_stat[n-1]=0;
     }

    void book_seat(char r,int c,int n)     //function to book a seat
    {

        r=toupper(r);
        s[n-1].bk_seat(r,c);
    }

    int ckst(char r,int c,int n)
    {
        int d=0;
        if(s[n-1].ck(r,c))
            d++;
        return d;
    }
    void cancel_seat(char r,int c,int n)        //function to cancel a show
    {
        r=toupper(r);
        s[n-1].canc_seat(r,c);
    }

    int get_slot_stat(int n)            //function to check the slot status
    {
        return s[n-1].get_avail();
    }

    void disp_screen(int n)         //function to display a screen slot
    {
        s[n-1].disp_slot();
    }
};


//-----------------------------------------------------------------------------------------------------------------

void reset_screen_status(int n)         //function to reset the screen status
    {
         int pos;
         screen m;
         fstream fin;
         if(n==1)
            fin.open("Screen_Info1.dat",ios::binary|ios::in|ios::out);      //opening the screen file
        else if(n==2)
            fin.open("Screen_Info2.dat",ios::binary|ios::in|ios::out);      //opening the screen file
        else if(n==3)
            fin.open("Screen_Info3.dat",ios::binary|ios::in|ios::out);      //opening the screen file
        else
            fin.open("Screen_Info4.dat",ios::binary|ios::in|ios::out);      //opening the screen file

         pos=fin.tellg();            //storing starting address
         fin.read((char*)&m,sizeof(m));         //reading a screen
         for(int i=0;i<4;i++)
         m.reset_screen(i+1);
         fin.seekg(pos);
         fin.write((char*)&m,sizeof(m));
         fin.close();

    }

void disp_screen_status()           //function to display screen status
{

        screen m;
        ifstream filin;

        filin.open("Screen_Info1.dat",ios::binary|ios::in);         //opening screen 1
        filin.read((char*)&m,sizeof(m));                            //displaying contents
        cout<<"\n\t\t\t Screen "<<1<<"  ( "<<disp_avail(!m.max_shows)<<" ) ";
        filin.close();
        filin.open("Screen_Info2.dat",ios::binary|ios::in);         //opening screen 2
        filin.read((char*)&m,sizeof(m));
        cout<<"\n\t\t\t Screen "<<2<<"  ( "<<disp_avail(!m.max_shows)<<" ) ";
        filin.close();
        filin.open("Screen_Info3.dat",ios::binary|ios::in);            //opening screen 3
        filin.read((char*)&m,sizeof(m));
        cout<<"\n\t\t\t Screen "<<3<<"  ( "<<disp_avail(!m.max_shows)<<" ) ";
        filin.close();
        filin.open("Screen_Info4.dat",ios::binary|ios::in);
        filin.read((char*)&m,sizeof(m));
        cout<<"\n\t\t\t Screen "<<4<<"  ( "<<disp_avail(!m.max_shows)<<" ) ";
        filin.close();
}



//----------------------------------------------------------MOVIE---------------------------------------------------


class movie             //class to define a movie
{
private :
    int mcode;
    char m_name[100];
    char cert[4];
    int nos,num;                //No. of shows
    float duration;
    int m_slot[4];
    void gen_mcode()
    {
     ifstream fmcode("Mcode.dat",ios::binary|ios::in);
     fmcode.read((char*)&mcode,sizeof(mcode));
     ofstream fitout("Mcode.dat",ios::binary|ios::out);
     if(mcode==0)
     {

      mcode=101;
      fitout.write((char*)&mcode,sizeof(mcode)); // redundancy could be removed by writing it only once
     }
     else
     {
     mcode+=1;
      fitout.write((char*)&mcode,sizeof(mcode));  // redundancy could be removed by writing it only once
     }
        fitout.close();
        fmcode.close();
    }


public:
    movie()             //default constructor
    {
        mcode=0;
        strcpy(m_name,"Not Alloted");
        strcpy(cert,"NA");
        nos=0;
        num=0;
        duration=0;
        for(int i=0;i<4;i++)
            m_slot[i]=0;


    }

    void rem_movie()            //function to remove a movie and free a screen slot
    {
        screen s;
        int pos,n=num;
        fstream fout;
        if(n==1)            //checking screen number
            fout.open("Screen_Info1.dat",ios::binary|ios::in|ios::ate);
        else if(n==2)
            fout.open("Screen_Info2.dat",ios::binary|ios::in|ios::ate);
        else if(n==3)
            fout.open("Screen_Info3.dat",ios::binary|ios::in|ios::ate);
        else
            fout.open("Screen_Info4.dat",ios::binary|ios::in|ios::ate);
        pos=fout.tellg();
        fout.read((char *)&s,sizeof(s));
        for(int i=0;i<4;i++)
            {
                if(m_slot[i]==1)
                {
                          s.reset_m_slot(i+1);          //reseting the slot
                }
            }


        fout.seekp(pos);
        fout.write((char *)&s,sizeof(s));
        fout.close();           //closing file
    }

    int get_snum(){return num;}

    void create_movie();        //declaring a function

    void disp_movie();          //declaring a function

    int get_mcode()         //getter function
    {
        return mcode;
    }

    char* get_m_name()      //getter function
    {
        return m_name;
    }

    void set_m_name()       //setter function
    {
        gets(m_name);
    }

    char* get_cert()        //getter function
    {
        return cert;
    }

    void set_cert()         //setter function
    {
        gets(cert);
    }

    int get_nos()           //getter function
    {
        return nos;
    }

    void set_nos()          //setter function
    {
        cin>>nos;
    }

    float get_dura()        //getter function
    {
        return duration;
    }

    void set_dura()         //setter function
    {
        cin>>duration;
    }

    void get_slots()           //function to update number of shows
    {
         rem_movie();
         int n=num;
         screen m;
         char str[]="Screen_Info0.dat";
         str[11]+=n;
         ifstream fin;
         ofstream fout("temp.dat",ios::out|ios::binary);

         if(n==1)
            fin.open("Screen_Info1.dat",ios::binary|ios::in);
        else if(n==2)
            fin.open("Screen_Info2.dat",ios::binary|ios::in);
        else if(n==3)
            fin.open("Screen_Info3.dat",ios::binary|ios::in);
        else
            fin.open("Screen_Info4.dat",ios::binary|ios::in);

             fin.read((char*)&m,sizeof(m));

            cout<<"\n Enter the number of shows ( max "<<m.max_shows<<" ) ";
            cin>>nos;
            cin.get();
            cout<<"\n Select the show timings : ";
            cout<<"\n \t\t\t<1> Morning   (09:00 AM - 12:00 PM)----( "<<disp_avail(m.get_slot(1))<<" ) ";
            cout<<"\n \t\t\t<2> Afternoon (12:15 PM - 03:15 PM)----( "<<disp_avail(m.get_slot(2))<<" ) ";
            cout<<"\n \t\t\t<3> Evening   (03:30 PM - 06:30 PM)----( "<<disp_avail(m.get_slot(3))<<" ) ";
            cout<<"\n \t\t\t<4> Night     (07:00 PM - 10:00 PM)----( "<<disp_avail(m.get_slot(4))<<" ) ";

                  for(int i=0;i<nos;i++)
                  {
                      int tm;
                cout<<"\n\t Show #"<<i+1<<" : \n\t\t\t\t";
                cin>>tm;
                if(tm==1)
                    {
                        m.set_m_slot(1);m_slot[tm-1]=1;
                    }
                else if(tm==2)
                    {
                        m.set_m_slot(2);m_slot[tm-1]=1;
                    }
                else if(tm==3)
                    {
                        m.set_m_slot(3);   m_slot[tm-1]=1;
                    }
              else if(tm==4)
                    {
                        m.set_m_slot(4);m_slot[tm-1]=1;
                    }
               else
                    cout<<"\n Wrong Choice !!!!";
                    ;


                  }

         fout.write((char*)&m,sizeof(m));
         fin.close();
         fout.close();
         remove(str);
         rename("temp.dat",str);

    }

    int return_m_slot(int n)
    {
        return m_slot[n-1];
    }

};

void movie::create_movie()          //function to create a movie
    {

        gen_mcode();
        cin.get();
        cout<<"\n Enter movie name : ";
        gets(m_name);
        cout<<"\n Enter Certificate : ";
        gets(cert);cin.get();
        cout<<"\n Enter the duration of movie(in minutes) : ";
        cin>>duration;cin.get();
        cout<<"\n Select a Screen : ";
        disp_screen_status();
        cout<<"\n Enter (1 -4) : ";
        cin>>num;
        cin.get();
        get_slots();
    }

 void movie::disp_movie()       //member function to display a movie
    {
        cout.setf(ios::left);
        cout<<endl<<setw(8)<<mcode<<setw(30)<<m_name<<setw(7)<<cert<<setw(10)<<duration<<setw(20)<<nos<<setw(7)<<" SCREEN "<<setw(1)<<num;
    }

 void insert_movie()            //function to insert a movie
{
    movie m;                    //creating an object of class movie
    m.create_movie();
    ofstream fout("Movies_this_week.dat",ios::binary|ios::app);
    fout.write((char*)&m,sizeof(m));        //writing data to file
    fout.close();           //closing file
}

void display_movies()       //function to display all movies
{
    int r=0;

    cout<<"\n\n------------------------------------------------------Display Menu--------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t<1> Search for a movie";
    cout<<"\n\n\t\t\t\t\t\t<2> Display all movies";
    cout<<"\n\n\t\t\t\t\t\t<3> <<BACK";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    int ch;
    cout<<"\n\n Enter your choice : ";
    cin>>ch;
        int n;
        movie m;
        system("cls");          //clearing screen
        switch(ch)
        {
        case 1:
            {
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                cout<<"\n\n Enter the movie code : ";
                cin>>n;
                ifstream fin("Movies_this_week.dat",ios::binary|ios::in);
                while(fin)
                {
                    fin.read((char*)&m,sizeof(m));
                    if(fin.eof())
                    break;
                    if(m.get_mcode()==n)
                    {
                        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                        cout.setf(ios::left);
                        cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
                        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                        m.disp_movie();
                        cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                        cin.get();
                        break;

                    }

                }
                fin.close();
                break;
          }

        case 2 :
        {

           ifstream fin("Movies_this_week.dat",ios::binary|ios::in);
           cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
           cout.setf(ios::left);
           cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
           cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
           while(fin)
            {
                cout.setf(ios::left);
                fin.read((char*)&m,sizeof(m));
                if(fin.eof())
                    break;

                m.disp_movie();
            }
            cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";

            fin.close();
            cin.get();
            break;
        }

        case 3:
        {
            r=1; break;
        }
        }

}

void remove_movie()         //function to remove a movie
{
    int r=0;
    scr:
    cout<<"\n\n------------------------------------------------------Delete Menu---------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t<1> Delete a movie";
    cout<<"\n\n\t\t\t\t\t\t<2> Delete all movies";
    cout<<"\n\n\t\t\t\t\t\t<3> <<BACK";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    int ch;
    cout<<"\n\n Enter your choice : ";
    cin>>ch;
    if(ch==1)
    {
         int n;
         movie m;
         system("cls");
         cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
         cout<<"\n\n Enter the movie code : ";
         cin>>n;

         ifstream fin("Movies_this_week.dat",ios::binary|ios::in);      //input stream file
         ofstream fout("Dummy.dat",ios::binary|ios::out);           //output stream file
         while(!fin.eof())      //getting cursor to eof
         {
              fin.read((char*)&m,sizeof(m));
              if(fin.eof())
                break;
              if(m.get_mcode()==n)      //searching for movie
              {
                   cout<<"\n The movie is : ";
                   cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                   cout.setf(ios::left);
                   cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
                   cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                    m.disp_movie();
                    cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                    cout<<"\n                            MOVIE DELETED !";
                    m.rem_movie();
                    cin.get();
                    break;
              }
              else
              {
                   fout.write((char*)&m,sizeof(m));
              }
        }
        while(!fin.eof())       //getting cursor to eof
          {
              fin.read((char*)&m,sizeof(m));
              if(fin.eof())
              break;
              fout.write((char*)&m,sizeof(m));
          }
          fout.close();
          fin.close();
          remove("Movies_this_week.dat");       //removing original file
          rename("Dummy.dat","Movies_this_week.dat");       //renaming dummy as original file
          cin.get();
          goto scr;
    }
    if(ch==2)
    {
        for(int i=0;i<4;i++)
        {
            reset_screen_status(i+1);
        }
        remove("Movies_this_week.dat");
        cout<<"\n\t\t\t All Movies Deleted ! ";

       cin.get();
       goto scr;
    }
    if(ch==3)
        r=0;
    cin.get();

}

void update_movie()         //function to update a movie
{
    movie m;
    int n;
    ifstream filin("Movies_this_week.dat",ios::binary|ios::in);
    ofstream filout("Dummy.dat",ios::binary|ios::out);
    cout<<"\nEnter the movie code : ";
    cin>>n;
    system("cls");          //clearing screen
    while(!filin.eof())
    {
        filin.read((char*)&m,sizeof(m));
        if(filin.eof())
            break;
        if(m.get_mcode()==n)
        {
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
            cout.setf(ios::left);
            cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
            m.disp_movie();
            cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
            cin.get();
            break;
        }

        else
            filout.write((char*)&m,sizeof(m));
    }
    int ch;
    do
    {
        cin.get();
        system("cls");
        cout<<"\n\n------------------------------------------------------Update Menu--------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t<1> Change Movie name";
        cout<<"\n\n\t\t\t\t\t\t<2> Change movie certificate ";
        cout<<"\n\n\t\t\t\t\t\t<3> Change movie length ";
        cout<<"\n\n\t\t\t\t\t\t<4> Change number of shows ";
        cout<<"\n\n\t\t\t\t\t\t<5> <<BACK";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n Enter your choice : ";
        cin>>ch;
        cin.get();
        switch(ch)              //getting new values
        {
            case 1:         //getting new name
                    {
                        cout<<"\nEnter the new movie name :";m.set_m_name();
                        break;
                    }
            case 2:         //getting new certificate
                    {
                        cout<<"\nEnter the new movie certificate :";m.set_cert();
                        break;
                    }
            case 3:         //getting new movie length
                    {
                        cout<<"\nEnter the new movie length :";m.set_dura();
                        break;
                    }
            case 4:         //getting new slot
                    {
                        m.get_slots();
                        break;
                    }
            case 5:         //exit
            {
                break;
            }
        }
    }
    while(ch!=5);
    filout.write((char*)&m,sizeof(m));          //writing updated record
    cout<<"\n\n\n\t\t\t\t\t\tRecord updation successful!";

    while(!filin.eof())         //writing other records
    {
        filin.read((char*)&m,sizeof(m));
        if(filin.eof())
        break;
        filout.write((char*)&m,sizeof(m));
    }
    filout.close();         //closing file
    filin.close();          //getting cursor to eof
    remove("Movies_this_week.dat");     //deleting old record
    rename("Dummy.dat","Movies_this_week.dat");         //renaming new record
    getch();            //clearing buffer

 }


//------------------------------------------------------------------------------------------------------------------

//-------------------------------TICKET--------------------------------------------------------------------------


class ticket            //class that defines a ticket
{
    long int ticket_no;
    char mname[30];
    seat s;
    int slot_num,snum,m_code;
    float cost;
    void gen_ticket_no()         //function to generate ticket number
    {
         ifstream fmcode("Ticket_Num.dat",ios::binary|ios::in);
         fmcode.read((char*)&ticket_no,sizeof(ticket_no));
         ofstream fitout("Ticket_Num.dat",ios::binary|ios::out);
         if(ticket_no==0)
         {

            ticket_no=1000000;
            fitout.write((char*)&ticket_no,sizeof(ticket_no)); // redundancy could be removed by writing it only once
         }

         else
         {
            ticket_no+=1;
            fitout.write((char*)&ticket_no,sizeof(ticket_no));  // redundancy could be removed by writing it only once
         }
         fitout.close();
         fmcode.close();
    }

public:
    ticket()            //default constructor to assign default values
    {
        ticket_no=0;slot_num=0;
        cost=0;snum=0;
    }

   void set_cost()      //function to set value of cost
   {
       cost=s.get_price();
   }

   float get_cost()        //getter function
   {
       return cost;
   }

   void set_movie(int code)         //function to set a movie according to given code
   {
      movie m;
      m_code=code;
      system("cls");
      ifstream fin("Movies_this_week.dat",ios::binary|ios::in);
      while(fin)
      {
            fin.read((char*)&m,sizeof(m));
            if(fin.eof())           //giving end to loop by eof
                break;
            if(m.get_mcode()==code)
            {
                    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                    cout.setf(ios::left);
                    cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
                    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                    m.disp_movie();         //displaying selected movie
                    cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                    cin.get();
                    snum=m.get_snum();          //to set the screen number of ticket
                    int i=-1;
                    do
                    {
                        ++i;
                        mname[i]=*(m.get_m_name()+i);
                    }
                    while(mname[i]!='\0');
                    break;
            }
        }
        fin.close();            //file closed
    }

    int get_t_snum()            //getter function
    {
        return  snum;
    }

    void set_slotnum(int n)         //function to set slot number
    {
        slot_num=n;
    }

    int get_slotnum()           //getter function
    {
        return slot_num;
    }

    long int get_tno()          //getter function
    {
        return ticket_no;
    }

void book_ticket()              //function to book a ticket
    {

        gen_ticket_no();            //function to generate ticket number


        int n=snum;
        screen sc;
        char str[]="Screen_Info0.dat";          //to select the file to be opened
        str[11]+=n;
        ifstream fin;
        ofstream fout("temp.dat",ios::out|ios::binary);
        if(n==1)
            fin.open("Screen_Info1.dat",ios::binary|ios::in);
        else if(n==2)
            fin.open("Screen_Info2.dat",ios::binary|ios::in);
        else if(n==3)
            fin.open("Screen_Info3.dat",ios::binary|ios::in);
        else
            fin.open("Screen_Info4.dat",ios::binary|ios::in);
         fin.read((char*)&sc,sizeof(sc));       //to read data from file

        jar :
         s.get_seat();               //function to get seat number

         if(sc.ckst(s.get_r(),s.get_c(),slot_num))
            {
                goto jar;
            }
         sc.book_seat(s.get_r(),s.get_c(),slot_num);
         set_cost();

         fout.write((char*)&sc,sizeof(sc));
         fin.close();
         fout.close();          //file closed
         remove(str);           //file deletion
         rename("temp.dat",str);        //renaming temp.dat as str
    }

    void cancel_book()          //function to cancel a booked ticket
    {
         int n=snum;
         screen sc;
         char str[]="Screen_Info0.dat";         //using string to open user manipulated file
         str[11]+=n;
         ifstream fin;
         ofstream fout("temp.dat",ios::out|ios::binary);
         if(n==1)
            fin.open("Screen_Info1.dat",ios::binary|ios::in);
         else if(n==2)
            fin.open("Screen_Info2.dat",ios::binary|ios::in);
         else if(n==3)
            fin.open("Screen_Info3.dat",ios::binary|ios::in);
         else
            fin.open("Screen_Info4.dat",ios::binary|ios::in);
         fin.read((char*)&sc,sizeof(sc));
         sc.cancel_seat(s.get_r(),s.get_c(),slot_num);          //cancelling ticket

         fout.write((char*)&sc,sizeof(sc));
         fin.close();
         fout.close();              //file closed
         remove(str);               //deleting file
         rename("temp.dat",str);        //renaming file

    }

    void disp_ticket()          //function to display ticket
    {
        int l=strlen(mname);
        l=34-l;
        cout<<"\n\t+--------------------------------------------+";
        cout<<"\n\t| T No. :  "<<ticket_no<<"                           |";
        cout<<"\n\t| Movie :  ";
        cout<<mname;
        for(int i=0;i<l;i++)
            cout<<' ';
        cout<<"|";
        cout<<"\n\t| Show  : ";
        show_time_slot(slot_num);           //function to show time slot on ticket
        cout<<"                         |";
        cout<<"\n\t|--------------------------------------------|";
        cout<<"\n\t| Seat  :  ";

        s.disp_seat();          //function to display seat

        set_cost();             //function to set cost of all booked tickets

        cout<<" | Screen : "<<snum<<" |Cost : Rs. "<<setw(4)<<cost<<"|";
        cout<<"\n\t+--------------------------------------------+";

    }

    void change_movie()             //function to change movie in updating record
    {

        movie m;
        ifstream fin("Movies_this_week.dat",ios::binary|ios::in);
        cout<<"\n\n------------------------------------------------------MOVIE MENU----------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout.setf(ios::left);
        cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        while(fin)
        {
            cout.setf(ios::left);

            fin.read((char*)&m,sizeof(m));
            if(fin.eof())
                break;

            m.disp_movie();         //function to display movie
        }
        cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";

        fin.close();
        cin.get();
        int n;
        cout<<"\n Enter the movie code : ";
        cin>>n;
        set_movie(n);           //function called to set movie

    }

    void change_show_time()         //function to change any show's timing
    {
         movie m;
         ifstream fin("Movies_this_week.dat",ios::binary|ios::in);
         while(fin)
         {
             fin.read((char*)&m,sizeof(m));         //to read data from file
             if(fin.eof())
                break;
             if(m.get_mcode()==m_code)          //searching required record
             {
                  screen s;
                  int n=m.get_snum();
                  ifstream finl;
                  if(n==1)
                    finl.open("Screen_Info1.dat",ios::binary|ios::in);
                  else if(n==2)
                    finl.open("Screen_Info2.dat",ios::binary|ios::in);
                  else if(n==3)
                    finl.open("Screen_Info3.dat",ios::binary|ios::in);
                  else
                    finl.open("Screen_Info4.dat",ios::binary|ios::in);

                  finl.read((char*)&s,sizeof(s));
                  finl.close();
                  cin.get();
                  cout<<"\n Select Show timing : ";
                  if(m.return_m_slot(1)==1)
                    cout<<"\n \t\t\t<1> Morning   (06:00 AM - 9:00 PM)----( "<<disp_avail(s.get_slot_stat(1))<<" ) ";
                  if(m.return_m_slot(2)==1)
                    cout<<"\n \t\t\t<2> Afternoon (09:15 AM - 12:15 PM)----( "<<disp_avail(s.get_slot_stat(2))<" ) ";
                  if(m.return_m_slot(3)==1)
                    cout<<"\n \t\t\t<3> Evening   (12:30 PM - 03:30 PM)----( "<<disp_avail(s.get_slot_stat(3))<<" ) ";
                  if(m.return_m_slot(4)==1)
                    cout<<"\n \t\t\t<4> Night     (04:00 PM - 7:00 PM)----( "<<disp_avail(s.get_slot_stat(4))<<" ) ";
                  cout<<"\n Enter (1-4) : ";
                  cin>>n;
                  set_slotnum(n);           //setting slot number of movie
                  cin.get();
                  break;
            }
        }

        fin.close();
    }

  char *get_m_name()            //getter function
  {
      return mname;
  }

};

//----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------USER----------------------------------------------------------------------------
class user
{
private:
    int tickets_sold;
    int user_no;
    char UserName[40];
    float amount;

public:
     user()         //default constructor
     {
         user_no=1;strcpy(UserName,"NA");tickets_sold=0;amount=0;
     }

     void disp_user()       //function to display user details
     {
        cout.setf(ios::left);
        cout<<endl<<setw(5)<<"USER"<<setw(6)<<user_no<<setw(20)<<UserName<<setw(15)<<tickets_sold<<setw(2)<<"Rs"<<setw(8)<<amount;
     }

     void get_user()        //function to get user
     {
          user();
          cout<<"\n---------------------USER "<<"DETAILS"<<" -------------------";
          cout<<"\n\n Enter an User Name (max 10 characters) : ";
          gets(UserName);           //function called for getting username
          cin.get();
     }

     int get_uno()          //getter function
     {
         return user_no;
     }

     void set_tsold(int n)      //function to set number of tickets sold
     {
        tickets_sold+=n;
     }

     void set_amount(float n)       //setter function
     {
        amount+=n;
     }

};

user u;

void book_a_show()          //function to book a show
{
        ufil.open("User_file.dat",ios::in|ios::binary);        //file opening
        ufil.read((char*)&u,sizeof(u));

        ofstream tufil("temu.dat",ios::out|ios::binary);
        ofstream fout("Ticket_file.dat",ios::binary|ios::app|ios::ate);
        //ofstream ftemp("Temp.dat",ios::binary|ios::out);
        int pos=fout.tellp();       //storing starting address

        ticket t;           //objects of classes declared

        movie m;

        ifstream fin;
        fin.open("Movies_this_week.dat",ios::binary|ios::in);
        cout<<"\n\n------------------------------------------------------MOVIE MENU----------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        cout.setf(ios::left);
        cout<<setw(8)<<"M_Code"<<setw(30)<<" Movie Name"<<setw(7)<<"Cert."<<setw(10)<<"Duration"<<setw(20)<<"No. of Shows"<<setw(7)<<" SCREEN ";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
        while(fin)      //finishing loop till eof
        {
            cout.setf(ios::left);

            fin.read((char*)&m,sizeof(m));
            if(fin.eof())
                break;

            m.disp_movie();     //if found, displaying movie
        }
        cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
        fin.close();            //file closed
        //getch();
        int n;
        cout<<"\n\n Enter the movie code : ";
        cin>>n;
        t.set_movie(n);         //setting movie
        fin.open("Movies_this_week.dat",ios::binary|ios::in);

        while(fin)
        {
            cout.setf(ios::left);

            fin.read((char*)&m,sizeof(m));
            if(m.get_mcode()==n)        //checking if mcode is matching given value of n
                break;
        }

         fin.close();           //file closed
         screen s;
         n=t.get_t_snum();
         ifstream finl;         //string declared for opening file
         if(n==1)
            finl.open("Screen_Info1.dat",ios::binary|ios::in);
         else if(n==2)
            finl.open("Screen_Info2.dat",ios::binary|ios::in);
         else if(n==3)
            finl.open("Screen_Info3.dat",ios::binary|ios::in);
         else
            finl.open("Screen_Info4.dat",ios::binary|ios::in);

         finl.read((char*)&s,sizeof(s));     //data reading

         //cin.get();
         cout<<"\n\n Select Show timing : ";         //selecting screen timing
         if(m.return_m_slot(1)==1)
            cout<<"\n \t\t\t<1> Morning   (09:00 AM - 12:00 PM)----( "<<disp_avail(s.get_slot_stat(1))<<" ) ";
         if(m.return_m_slot(2)==1)
            cout<<"\n \t\t\t<2> Afternoon (12:15 PM - 03:15 PM)----( "<<disp_avail(s.get_slot_stat(2))<<" ) ";
         if(m.return_m_slot(3)==1)
            cout<<"\n \t\t\t<3> Evening   (03:30 PM - 06:30 PM)----( "<<disp_avail(s.get_slot_stat(3))<<" ) ";
         if(m.return_m_slot(4)==1)
            cout<<"\n \t\t\t<4> Night     (07:00 PM - 10:00 PM)----( "<<disp_avail(s.get_slot_stat(4))<<" ) ";
         cout<<"\n Enter (1-4) : ";
         cin>>n;
         t.set_slotnum(n);
         int x=n;
         system("cls");
         cout<<"\n\n Enter the number of seats : ";
         cin>>n;
         cout<<"\n Choose "<<n<<" Seats : ";
         s.disp_screen(x);          //displaying screen with booked ticket marked as x
         finl.close();

         float t_cost=0;
         cout<<"\n\n Enter "<<n<<" seats : ";
         for(int i=0;i<n;i++)
         {
           t.book_ticket();
           t_cost+=(t.get_cost());      //adding cost of ticket to total cost
           fout.write((char*)&t,sizeof(t));

         }
         cin.get();
         fout.close();
         system("cls");
         ifstream fil("Ticket_file.dat",ios::binary|ios::in);
         fil.seekg(pos);
         for(int i=0;i<n;i++)
         {

             fil.read((char*)&t,sizeof(t));
             cin.get();
             t.disp_ticket();       //displaying all ticket
         }
         u.set_tsold(n);        //setting number of tickets sold
         cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------\n";
         cout<<"\n\n\t       "<<n<<" tickets for  \" "<<t.get_m_name()<<" \""<<"  SCREEN "<<t.get_t_snum();
         cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
         cout<<" \t    \t::::  TOTAL COST : Rs. "<<t_cost<<"  ::::" ;
         cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
         u.set_amount(t_cost);      //setting amount of money
         t_cost=0;
         fil.close();
         finl.close();
         fin.close();
         tufil.write((char*)&u,sizeof(u));
         tufil.close();
         ufil.close();
         remove("User_file.dat");           //deleting user_file.dat file
         rename("temu.dat","User_file.dat");       //renaming temu as user_file
         cin.get();

}

void display_booking()      //function to display booked tickets
{
    int r=0;
     ticket t;
    long int n;

    ifstream filin("Ticket_file.dat",ios::binary|ios::in);

    cout<<"\n\n------------------------------------------------------Display Menu--------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t<1> Search for a ticket";
    cout<<"\n\n\t\t\t\t\t\t<2> Display all tickets";
    cout<<"\n\n\t\t\t\t\t\t<3> <<BACK";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    int ch;
    cout<<"\n\n Enter your choice : ";
    cin>>ch;

    system("cls");
    switch(ch)
    {
    case 1:
                {
                    cout<<"\nEnter the ticket no. : ";
                    cin>>n;
                    system("cls");
                    cout<<"\n\n------------------------------------------------------Ticket File---------------------------------------------------------------------";
                    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";

                    while(!filin.eof())
                    {
                        filin.read((char*)&t,sizeof(t));
                        if(filin.eof())
                        break;
                        if(t.get_tno()==n)
                            {
                                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                                t.disp_ticket();
                                cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                                cin.get();
                                break;
                            }
                    }
                    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                    getch();
                    break;
                }
    case 2 :
            {
                cout<<"\n\n------------------------------------------------------Ticket File---------------------------------------------------------------------";
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                while(!filin.eof())
                {
                filin.read((char*)&t,sizeof(t));
                if(filin.eof())
                break;

                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                t.disp_ticket();
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                }
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                getch();
                break;
            }

    case 3:
            {
            filin.close();      //function closed
            r=1; break;
            }
    }
}

void cancel_booking()       //function to cancel booking
{
     int ch;
     ufil.open("User_file.dat",ios::in|ios::binary);
     ufil.read((char*)&u,sizeof(u));
     ofstream tufil("temu.dat",ios::out|ios::binary);

     int r=0;
     ticket t;
     long int n;

     ifstream filin("Ticket_file.dat",ios::binary|ios::in);

     do
     {
        system("cls");
        cout<<"\n\n------------------------------------------------------Delete Menu---------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t<1> Cancel a booking";
        cout<<"\n\n\t\t\t\t\t\t<2> Reset ticket file";
        cout<<"\n\n\t\t\t\t\t\t<3> <<BACK";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\n Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1 :        //cancelling booking
        {
            long int n;
            system("cls");
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\n Enter the ticket no : ";
            cin>>n;
            ofstream fout("Dummy.dat",ios::binary|ios::out);

            while(!filin.eof())
            {
             filin.read((char*)&t,sizeof(t));
              if(filin.eof())
                break;
              if(t.get_tno()==n)
                {
                   cout<<"\n The ticket is : ";
                   cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
                   t.disp_ticket();
                   cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                   cout<<"\n                   BOOKING NO. "<<t.get_tno()<<" CANCELED !";
                   t.cancel_book();
                   u.set_tsold(-1);
                   float x=t.get_cost();
                   u.set_amount(-x);
                   cin.get();
                }

              else
              {
                   fout.write((char*)&t,sizeof(t));
              }
            }
            while(!filin.eof())
            {
                filin.read((char*)&t,sizeof(t));
                if(filin.eof())
                    break;
                fout.write((char*)&t,sizeof(t));
            }
            fout.close();
            filin.close();
            remove("Ticket_file.dat");
            rename("Dummy.dat","Ticket_file.dat");
            cin.get();
            break;
        }

        case 2 :        //resetting ticket file
            {
                remove("Ticket_file.dat");
                cout<<"\n File Reset ! ";
                fstream f("Ticket_file.dat",ios::binary|ios::out);
                f.close();
                cin.get();
                break;
            }
        case 3 :            //exit
            break;
        }

        tufil.write((char*)&u,sizeof(u));
            tufil.close();
        ufil.close();
        remove("User_file.dat");        //removing original file
        rename("temu.dat","User_file.dat");     //renaming file
        cin.get();

    }while(ch!=3);      //choice must be 1-3
}

void reset_screen()         //function to reset screen after each show
{
    int n,s;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n Enter the screen no. : ";
    cin>>n;
    cout<<"\n Enter the slot : ";
    cin>>s;
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t Screen "<<n<<" :::: Slot "<<s<<" Reset Successful ! ";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cin.get();
    int pos;
         screen m;
         fstream fin;       //opening screen name by string
         if(n==1)
            fin.open("Screen_Info1.dat",ios::binary|ios::in|ios::out);
         else if(n==2)
            fin.open("Screen_Info2.dat",ios::binary|ios::in|ios::out);
         else if(n==3)
            fin.open("Screen_Info3.dat",ios::binary|ios::in|ios::out);
         else
            fin.open("Screen_Info4.dat",ios::binary|ios::in|ios::out);

         pos=fin.tellg();
         fin.read((char*)&m,sizeof(m));
         m.reset_screen(s);     //resetting screen n and slot s
         fin.seekg(pos);
         fin.write((char*)&m,sizeof(m));
         fin.close();

}

void disp_scr_stat()        //function to check availability of screen or slot for a movie
{
    screen s;
    int n;
    cout<<"\n Enter the screen number : ";
    cin>>n;
    cin.get();
    ifstream finl;      //opening file by string
    if(n==1)
            finl.open("Screen_Info1.dat",ios::binary|ios::in);
    else if(n==2)
            finl.open("Screen_Info2.dat",ios::binary|ios::in);
    else if(n==3)
            finl.open("Screen_Info3.dat",ios::binary|ios::in);
    else
            finl.open("Screen_Info4.dat",ios::binary|ios::in);

    int a;
    finl.read((char*)&s,sizeof(s));
    cout<<"\n Enter the slot number : ";
    cin>>a;
    cin.get();
    system("cls");          //screen clear
    cout<<"\n\n------------------------------------------------Screen "<<n<<" :::: Slot "<<a<<" -----------------------------------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    s.disp_screen(a);           //displaying screen
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cin.get();
    finl.close();           //file closed
}

void user_menu()            //function to get user's choice from his menu
{
    int ch;
    int n;
    l1956 :
    do
    {
        system("cls");

        cout<<"\n\n------------------------------------------------------USER MENU-----------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t<1> Book a show";
        cout<<"\n\t\t\t\t\t\t<2> Cancel Booking";
        cout<<"\n\t\t\t\t\t\t<3> Display Ticket";
        cout<<"\n\t\t\t\t\t\t<4> Reset Screen";
        cout<<"\n\t\t\t\t\t\t<5> Display Screen Status";
        cout<<"\n\t\t\t\t\t\t<6> <<BACK";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";

    cout<<"\n Enter your choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1 :
        {
            system("cls");
            book_a_show();          //function to book a show with slot s and screen n
            break;
        }
    case 2 :
        {
            system("cls");
            cancel_booking();       //function to cancel booking
            break;
        }
    case 3 :
        {
            system("cls");
            display_booking();      //function to display bookings
            break;
        }
    case 4 :
        {
            system("cls");
            reset_screen();         //function to reset screen
            break;
        }
    case 5:
        {
            disp_scr_stat();        //function to display screen/slot status
            break;

        }
    case 6 :
        {
            system("cls");
                   char h3;
                   cout<<"\n\n\n\n\n\t\t\t\t\t\t ::CHANGES SAVED::\n\n\t\t\t\t\tAre you sure you want to exit ?  (Y/N) ";
                   cin>>h3;
                   if(h3=='y'||h3=='Y')
                    break;
                   else
                   goto l1956;

            break;      //back
        }

    }
    }while(ch!=6);      //accepting numbers only 1-6
}



//===========================================================

void admin_menu()       //function to get user's choice from his menu
{
    int ch;
    l2021 :
    do
    {
        system("cls");

        cout<<"\n\n------------------------------------------------------ADMIN MENU----------------------------------------------------------------------";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t<1> Update Admin account";
        cout<<"\n\t\t\t\t\t\t<2> Update Movies";
        cout<<"\n\t\t\t\t\t\t<3> Display Movies";
        cout<<"\n\t\t\t\t\t\t<4> Update ticket cost";
        cout<<"\n\t\t\t\t\t\t<5> Reset Screen";
        cout<<"\n\t\t\t\t\t\t<6> <<BACK";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";


    cout<<"\n Enter your choice : ";
    cin>>ch;

    switch(ch)
    {

    case 1 :        //updating admin account
        {
            int ch2;
            fstream fin("AP.dat",ios::binary|ios::in|ios::out);
            int pos;
            pos=fin.tellg();
            fin.read((char*)&ADMIN,sizeof(ADMIN));

            do
            {
                system("cls");
                cout<<"\n\n------------------------------------------------------Update Menu--------------------------------------------------------------------";
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t<1> Change Admin name";
                cout<<"\n\n\t\t\t\t\t\t<2> Change  password ";
                cout<<"\n\n\t\t\t\t\t\t<3> <<BACK";
                cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                cout<<"\n\n Enter your choice : ";
                cin>>ch2;
                cin.get();
                switch(ch2)
                {
                   case 1 :     //setting admin name
                            {
                            cout<<"\n Enter the new Admin name : ";
                            ADMIN.set_admin_name();
                            break;
                            }
                    case 2 :        //setting admin password
                            {
                            cout<<"\n Enter the new password : ";
                            cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
                            ADMIN.set_pass();
                            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                            cout<<"\n\t\t\t\t\t\t :::: UPDATED ::::";
                            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                            getch();
                            break;
                            }
                    case 3 :        //exit
                        {

                            break;}
                }
            }while(ch2!=3);
                   fin.seekp(pos);
                   fin.write((char*)&ADMIN,sizeof(ADMIN));
                   fin.close();
                   break;

        }
        //future enhancements
  /*  case 2 :
        {
            user u1;
            system("cls");
            ofstream tufil("User_file.dat",ios::out|ios::binary);
            u1.get_user();
            tufil.write((char*)&u1,sizeof(u1));
           tufil.close();
           cin.get();
            break;
        }
    case 3 :
        {
            system("cls");
             ufil.open("User_file.dat",ios::in|ios::binary);
            ufil.read((char*)&u,sizeof(u));
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
            cout.setf(ios::left);
        cout<<setw(10)<<"USER No "<<setw(20)<<" User Name "<<setw(15)<<" Tickets Sold "<<setw(10)<<" Amount ";
         cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            u.disp_user();
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cin.get();


           ufil.close();
           cin.get();
            break;
        }
    case 4 :
        {
           system("cls");
             ufil.open("User_file.dat",ios::in|ios::binary);
            ufil.read((char*)&u,sizeof(u));
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
            cout.setf(ios::left);
        cout<<setw(10)<<"USER No "<<setw(20)<<" User Name "<<setw(15)<<" Tickets Sold "<<setw(10)<<" Amount ";
         cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            u.disp_user();
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\n\t\t\t\t\t\t :::: User Removed ::::";
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cin.get();
            ufil.close();
           remove("User_file.dat");
           cin.get();
            break;

        }*/
    case 2:         //updating movies
            {
                int ch1;
                do
    {
    system("cls");
                            cout<<"\n\n------------------------------------------------------MOVIE MENU----------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
     cout<<"\n\t\t\t\t\t\t<1> Insert Movie";
     cout<<"\n\t\t\t\t\t\t<2> Delete Movie";
     cout<<"\n\t\t\t\t\t\t<3> Update Movie";
    cout<<"\n\t\t\t\t\t\t<4> <<BACK";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n Enter your choice : ";
    cin>>ch1;

    if(ch1==1)
    {
        insert_movie();     //inserting movies
    }
    else if(ch1==2)
    {
        remove_movie();     //removing movies
    }
    else if(ch1==3)
        {
            update_movie();     //updation of movie
        }
    else    //exit
        break;
    }while(ch1!=4);
    break;

       }

        case 3 :        //displaying movies
            {
                system("cls");

                display_movies();
                cin.get();
                break;
            }
         case 4 :
         {
            system("cls");
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            update_price();
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n\t\t\t\t\t\t :::: UPDATED ::::";
            cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
             cin.get();
             cin.get();
            break;
         }
        case 5 :        //resetting screen status
            {
                for(int i=0;i<4;i++)
                {
                    reset_screen_status(i+1);
                }
                    cout<<"\n Screen Reset Successful !!! ";
                    cin.get();
                    cin.get();      //for pressing enter key
                    break;
            }
        case 6 : {
                   system("cls");
                   char h3;
                   cout<<"\n\n\n\n\n\t\t\t\t\t\t ::CHANGES SAVED::\n\n\t\t\t\t\tAre you sure you want to exit ?  (Y/N) ";
                   cin>>h3;
                   if(h3=='y'||h3=='Y')
                    break;
                   else
                   goto l2021;

        }
    }
}while(ch!=6);


}

void tnk_u()
{
    char str[]="\t\t\t\t\t\t***** THANK YOU ******";

     for(int i=0;str[i]!='\0';i++)
   {
       for(int j=0;j<20000000;j++)
        ;
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n";
    for(int k=0;k<i;k++)
        cout<<str[k];
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n";


   }
   char str2[]="\n\n\n\n  Made By  :   Anshaj Malhotra \n\n  School   :   St. Montfort School , Bhopal  \n\n\n\n\n";

     for(int i=0;str2[i]!='\0';i++)
   {
       for(int j=0;j<19999000;j++)
        ;
       cout<<str2[i];

   }

}



int main()
{
    //-----------------------------------------ADMIN PASSWORD SET-----------------------------------------
//remove("AP.dat");
 /*ADMIN.set_admin_name();
 ADMIN.set_pass();
 ofstream fout("AP.dat",ios::binary|ios::out);
 fout.write((char*)&ADMIN,sizeof(ADMIN));
 fout.close();
 *///-----------------------------------------------------------------------------------------------------------------------

            //for creating files for first time
  /*ofstream fo;
  fo.open("Ticket_file.dat",ios::out|ios::binary);
  fo.close();
  fo.open("User_file.dat",ios::out|ios::binary);
  ofstream f;
  f.open("Screen_Info1.dat",ios::out|ios::binary);
  f.close();
   f.open("Screen_Info2.dat",ios::out|ios::binary);
  f.close();
   f.open("Screen_Info3.dat",ios::out|ios::binary);
  f.close();
   f.open("Screen_Info4.dat",ios::out|ios::binary);
  f.close();*/
// Setting initial ticket cost
  /* float p1=180,p2=140,p3=100;
ofstream fout("pd.dat",ios::binary|ios::out);

   fout.write((char*)&p1,sizeof(p1));
   fout.write((char*)&p2,sizeof(p2));
   fout.write((char*)&p3,sizeof(p3));

   fout.close();
*/
  //---------------------------------------------------------------------------------------------------------------------------
    loading();
    system("cls");
    int ch;
    /*cout<<"\n\n\n\n\n\n\n\n-------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t***** Welcome To CINE_CORNER *****";
    cout<<"\n\n\t\t\t\t\t <<<PRESS ANY KEY TO CONTINUE>>>";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------\n";
    //cout<<"\n\n\n\n\n\n\n\n\n  Made By  :   Anshaj Malhotra \n\n  School   :   St. Montfort School , Bhopal                                                                                              ";

    //cout<<"\n\n-------------------------------------------------------------------------------------------------------------------------------------";
*/
   welcomescr();
    getch();
    do
    {
        system("cls");
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t<1> ADMIN MODE";
        cout<<"\n\n\t\t\t\t\t\t<2> USER MODE";
        cout<<"\n\n\t\t\t\t\t\t<3> EXIT";
        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n SELECT A MODE : ";
        cin>>ch;

        system("cls");
        switch(ch)
        {
        case 1:{            //admin mode
                    ifstream fin("AP.dat",ios::binary|ios::in);
                    fin.read((char*)&ADMIN,sizeof(ADMIN));
                    cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                    cout<<"\n\t\t\t\t\t\tEnter your Admin ID : ";
                    ADMIN.get_a_id();
                    cin.get();
                    if(ADMIN.check_pass())      //checking password for security concerns
                    {
                        fin.close();
                        cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------";
                        getch();
                        system("cls");
                        admin_menu();       //for calling admin menu
                    }
                    break;
                }

        case 2:{        //user mode
                     system("cls");
                     user_menu();
                     break;
               }

        case 3 :{       //exit

                    break;
                }

       }
    }while(ch!=3);

    system("cls");      //clear screen
    tnk_u();
       cin.get();//for pressing enter key
    return 0;
}
