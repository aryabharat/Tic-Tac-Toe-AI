#include<iostream>
#include <cstdlib>
using namespace std;
 void draw( int game[])//function to draw the output
 {
     for(int i=1;i<=9;i++)
     {
         if(i==1||i==4||i==7)
            cout<<"\t\t\t\t\t\t";
            if(game[i]==1)
         cout<<" "<<"X"<<" ";
         else if( game[i]==-1)
            cout<<" "<<"O"<<" ";
         else
            cout<<" "<<" "<<" ";

         if(i==3||i==6)
        cout<<endl<<"\t\t\t\t\t\t"<<"---*---*---"<<endl;
         else if(i==9)
        cout<<endl;
            else
                cout<<"|";
     }

 }

 int  win(int game[10])//function to check the winner
 {
     unsigned wins[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{7,5,3}};//ALL possible wins
     for( int i = 0; i < 8; ++i)
         {

        if(game[wins[i][0]] !=0 &&
           game[wins[i][0]] == game[wins[i][1]] &&
           game[wins[i][0]] == game[wins[i][2]])
            return game[wins[i][2]];
        }
    return 0;//return 0 if no winner
}

int minimax(int game[10],int player)//function to calculate all the possible move
{

    int winner = win(game);
    if(winner != 0) return winner*player;//return score if according to the result

int     move = -1;
    int score = -2;
    int i;
    for(i = 1; i <=9; ++i) {
        if(game[i] == 0) {
            game[i] = player;
            int thisScore = -minimax(game, player*-1);//recurssieon
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            game[i] = 0;//reset the game
        }
    }
    if(move == -1) return 0;//return o if no winner
    return score;//return score
}

 void comp( int game[10])//computer move
{
    int move = -1;
    int score = -2;
    int i;
    for(i = 1; i <=9; ++i) {
        if(game[i] == 0) {
            game[i] = 1;
            int tempScore = -minimax(game, -1);//calling minimax to check the best possible move
            game[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax function.
    game[move] = 1;
    draw(game);
}

 void human(int game[10])//ask player for a move
 {
     cout<<"your turn enter a the position number from the game [1-9]";
     int n;
     cin>>n;
      if(game[n]==0)
        game[n]=-1;
      else
        cout<<"invalid";
 }

int main()
{int c=1;
    while(c!=0)
    {
        system("cls");
cout<<"\t\t\t\t\t   THE TIC-TAC-TOE GAME\n\n\n";
int  game[10]={0,0,0,0,0,0,0,0,0,0};
draw( game);//for output
int n;

cout<<"\n\n\t\t\t\t\t  play First[1] or play second[2]  ";
cin>>n;
int i=0;
while(win(game)==0&&i<5)//for all the moves
{
   if(n==2)
    {
     comp(game);
     if(win(game)!=0)
        break;
     human(game);
    }
   else
    {
    human(game);
    if(win(game)!=0)
        break;
    comp(game);
    }

    i++;
}

int check=win(game);

if(check==1)
    cout<<"YOU LOSE";
else if(check==0)
    cout<<"DRAW";

    cout<<"\n\n\t\t\t PRESS ANY KEY TO GIVE ONR MORE SHOT........press 0 to exit  ";
    cin>>c;

    }
    system("cls");
    cout<<"\n\n\t\t\t\****THAN YOU****";
}
