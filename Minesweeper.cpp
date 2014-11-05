//Xmax stands for numbers of the X-axis same for Ymax for Y-axis. bombs for the number of bombs. If you want to change the difficulty, just change those 3 values in the source code
#include <iostream>
#include<cstdlib>
#include <ctime>
#define Xmax 10
#define Ymax 10
#define bombs 20
using namespace std;

void placeBomb(int[][Ymax]);           //Randomizes the place of the bombs.
void display(int[][Ymax],int,int[][Ymax]);   //Outputs the board
void generate(int [][Ymax]);      //Says how many bombs around a specified subscript 
void choose(int [][Ymax],int *, int [] [Ymax]);  //the input value of the user
void initialize(int [][Ymax]);     //initializes the values of the array
void play();   //play again

int main()
{
    int arr[Xmax][Ymax]={0},arr2[Xmax][Ymax];
    int gameover=0;
    initialize(arr2);
    srand(time(NULL));
    placeBomb(arr);
    generate(arr);
    display(arr,gameover,arr2);
    while(gameover==0)
    {
                      choose(arr,&gameover,arr2);
                      display(arr,gameover,arr2);
    }
    cout<<endl;
    play();
    system("pause");
    return 0;
}

void placeBomb(int arr[][Ymax])
{
     int randomX,randomY;
     int bombcount=0;
     while(bombs>bombcount)
     {
                    randomX=rand()%Xmax;
                    randomY=rand()%Ymax;
                    if(arr[randomX][randomY]==0)
                    {
                                                arr[randomX][randomY]=9;
                                                bombcount++;
                    }
     }
     
}

void display(int arr[][Ymax],int gameover,int arr2[][Ymax])
{
     int x,y;
     cout<<"* ";
     for(x=0;x<Xmax;x++)
     {
                        cout<<x<<" ";
     }
     for(x=0;x<Xmax;x++)
     {
                      cout<<endl;
                      cout<<x<<" ";
                      for(y=0;y<Ymax;y++)
                      {
                                         if(gameover==1)
                                         {
                                                        if(arr[x][y]==9)
                                                        {
                                                                        cout<<"*|";
                                                        }
                                                        else
                                                        {
                                                            cout<<arr[x][y]<<"|";
                                                        }
                                         }
                                         else if(gameover==0)
                                         {
                                              if(arr2[x][y]==10)
                                              {
                                                               cout<<"_|";
                                              }
                                              else
                                              {
                                                  cout<<arr2[x][y]<<"|";
                                              }
                                         }
                                                               
                      }
     }
}

void generate(int arr[][Ymax])
{
     int x,y;
     for(x=0;x<Xmax;x++)
     {
                     for(y=0;y<Ymax;y++)
                     {
                                     if(arr[x][y]==9)
                                     {
                                                     if(arr[x-1][y]<9 && x>0)
                                                     {
                                                                      arr[x-1][y]++;
                                                     }
                                                     if(arr[x-1][y+1]<9 && x>0 && y<Ymax)
                                                     {
                                                                        arr[x-1][y+1]++;
                                                     }
                                                     if(arr[x][y+1]<9 && y<Ymax)
                                                     {
                                                                      arr[x][y+1]++;
                                                     }
                                                     if(arr[x+1][y+1]<9 && x<Xmax && y<Ymax)
                                                     {
                                                                        arr[x+1][y+1]++;
                                                     }
                                                     if(arr[x+1][y]<9 && x<Xmax)
                                                     {
                                                                      arr[x+1][y]++;
                                                     }
                                                     if(arr[x+1][y-1]<9 && x<Xmax && y>0)
                                                     {
                                                                        arr[x+1][y-1]++;
                                                     }
                                                     if(arr[x][y-1]<9 && y>0)
                                                     {
                                                                      arr[x][y-1]++;
                                                     }
                                                     if(arr[x-1][y-1]<9 && x>0 && y>0)
                                                     {
                                                                        arr[x-1][y-1]++;
                                                     }
                                     }
                     }
     }
}

void choose(int arr[][Ymax],int *gameover,int arr2[][Ymax])
{
     int a,b; 
     cout<<endl<<"Input the X and Y: "<<endl;
     cin>>a;
     cin>>b;
     cout<<endl;
     if(a>=Xmax || b>=Ymax || a<0 || b<0)
     {
            cin.clear();
            cin.ignore();
            cout<<"Invalid Input."<<endl;
            choose(arr,gameover,arr2);
     }
     else if(arr[a][b]==9)
     {
          *gameover=1;
          return;
     }
     else if(arr[a][b]<9)
     {
          arr2[a][b]=arr[a][b];
          
     }
}

void initialize(int arr[][Ymax])
{
     int x,y;
     for(x=0;x<Xmax;x++)
     {
                        for(y=0;y<Ymax;y++)
                        {
                                           arr[x][y]=10;
                        }
     }
}

void play()
{
     char letter;
     cout<<"Do you want to play again? Y/N "<<endl;
     cin>>letter;
     if(letter=='Y' || letter=='y')
     {
                    main();
     }
}
