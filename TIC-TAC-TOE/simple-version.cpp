#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;
char a[3][3];
int over=0;
void in()
{
    system("CLS");
     cout<<"******************************THE TIC-TAC-TOE GAME******************************\n\n\n";
     a[0][0]='1';a[0][1]='2';a[0][2]='3';
     a[1][0]='4';a[1][1]='5';a[1][2]='6';
     a[2][0]='7';a[2][1]='8';a[2][2]='9';
}
void draw()
{
     for(int i=0;i<3;i++)
    {
        cout<<"\t\t\t\t";
      for(int j=0;j<3;j++)
            {
                   if(j==2)
                cout<<a[i][j];
                else
                    cout<<a[i][j]<<" |";
            }
            if(i==2)
                cout<<endl;
            else
            cout<<endl<<"\t\t\t       "<<"........."<<endl;
    }
}
void ask()
{
    char t;
          cin>>t;
          for(int i=0;i<3;i++)
          {
            for(int j=0;j<3;j++)
               {
                  if(a[i][j]==t)
                      a[i][j]='X';
                }
          }
}

int  put()
{
     int l=0;
   while(1)
   {

     for(int i=0;i<3;i++)
          {
            for(int j=0;j<3;j++)
               {
                  if(a[i][j]==l)
                  {
                      a[i][j]='O';
                      return 0;
                  }
                }

          }
          l++;
}
}
int win()
{
    if (a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]=='X'||a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]=='O')
   {over++;return 0;}

    else  if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]=='X'||a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]=='O')
        {over++;return 0;}

    else if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]=='X'||a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]=='O')
       {over++;return 0;}

    else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]=='X'||a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]=='O')
         {over++;return 0;}

    else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]&&a[2][0]=='X'||a[0][0]==a[1][0]&&a[1][0]==a[2][0]&&a[2][0]=='O')
        {over++;return 0;}

    else if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[2][1]=='X'||a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[2][1]=='O')
        {over++;return 0;}

    else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]&&a[2][2]=='X'||a[0][2]==a[1][2]&&a[1][2]==a[2][2]&&a[2][2]=='O')
         {over++;return 0;}

        else if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]=='X'||a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]=='O')
        {over++;return 0;}

        else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]=='X'||a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]=='O')
        {over++;return 0;}

        else return 0;
}
int main()
{
    int e=0;
       char c='Y';
       while(c=='Y')
       { in();
       draw();
       e=0;
         while(e!=1)
        {
            cout<<"your turn  ";
           ask();
           draw();
           win();
           cout<<endl;
           if(over!=0)
           {
               cout<<"\n\n\t\t\t\t\t YOU WIN";
               e=1;

           }
           if(e==1)
           {
               cout<<"\nDO U WANT MORE PRESS 'Y' FOE EXIT PRESS 'Z'  ";
               cin>>c;
               break;
           }

           put();
           win();
           draw();
           cout<<endl;
           if(over!=0)
           {
               cout<<"\n\n\t\t\t\t\t YOU LOSE";
               e=1;

           }

           if(e==1)
           {
               cout<<"\nDO U WANT MORE PRESS 'Y' FOE EXIT PRESS 'Z'  ";
               cin>>c;
           }


           cout<<endl;
         }
       }
       cout<<"\t\tTHANK YOU";
}


