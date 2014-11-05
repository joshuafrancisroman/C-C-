#include <iostream>
#include <cstdlib>
#include <ctime>
//JOSHUA FRANCIS ROMAN
using namespace std;

int check(int ,int [],int [],int);

void assign(int [],int [],int,int,int*,int*);

int input();

void offer(int , int [],int []);

char deal(int ,int []);

int main()
{   int briefcase[27]={0}; //Dito ko ilalagay yung values. 27 lahat ng buffer kasi disregarded yung suscript "0"
    int value[26]={1,5,10,25,50,75,100,150,200,300,400,500,750,1000,2500,5000,10000,25000,50000,100000,200000,300000,400000,500000,1000000,2000000};
    //eto yung mga pwedeng lumabas na values
    int random,ctr=1,ctr2=1,choose,special=0;
    char letter;
    // random=container ng random value. ctr=para umulit ng 26 times. ctr2=para sa repeated value check. choose=yung input ng user na briefcase number
    //srand para magenerate random number
    srand(time(NULL));
    //uulit siya ng 26 times.
    while(ctr<=26)
    {
       choose=input();                 
       //para malaman if briefcase number is hindi kasama like 0,27 etc
       if(choose>=1&&choose<=26)
         {
       //nilalagay na yung value ng random
          random=rand()%26;
       //eto yung repeated value check. ichecheck nya one-by-one if yung value is nakalagay na sa ibang briefcase.
          random=check(random,value,briefcase,ctr2);          
       //binalik yung ctr2=1 para next loop checheck nya ulet 
          ctr2=1;
       //dito malalaman if yung briefcase is may laman na or nabuksan
          assign(briefcase,value,choose,random,&ctr,&special);
        //bankers offer. Using selfmade algorithm
          if(ctr==7||ctr==13||ctr==18||ctr==22||ctr==25)
             {
             offer(ctr,briefcase,value);
             letter=deal(special,briefcase);
                if(letter=='y'||letter=='Y')
                  {break;}
             }
          else if(ctr==27)   //you opened all briefcases.
             {cout<<"The game has finished. Your briefcase has a value of "<<briefcase[special]<<endl;}                           
          }
       //eto yung kapartner nung unang if. check din to if 0 or 27 etc
       else
          {cout<<"Invalid briefcase number.";} 
     }
     
system("pause");
}



int input()
{     int choose;
      cout<<"Input number of briefcase to open."<<"\n";
      cin>>choose;
      return choose;
}


int check(int random,int value[],int briefcase[],int ctr2)
{
  while(ctr2<=26)
                {
                while(value[random]==briefcase[ctr2])
                     {
                     random=rand()%26;
                     ctr2=1;
                     //Tricky part yung ctr2=1 dito sa while loop. Kasi if wala yan uulit parin.
                     }
                ctr2++;      
                }
  return random;
}


void assign(int briefcase[],int value[],int choose,int random,int *ctr,int *special)
{         
          if(choose==*special)
                {
                 cout<<"Briefcase "<<choose<<" is main case."<<"\n";    
                }             
          else if(briefcase[choose]!=0)
                {
                 cout<<"Briefcase "<<choose<<" is open."<<"\n";
                }
           //kapag walang laman, i-assign na siya sa pangalawang array. 
          else  {
                 briefcase[choose]=value[random];
                    {
                     if(*ctr==1)
                          {
                               *special=choose;
                               cout<<"Your main briefcase is "<<*special<<"\n";
                          }
                    
                     else {                        
                               cout<<"You opened briefcase "<<choose<<" which contains "<<briefcase[choose]<<"\n";
                          }
                 *ctr=*ctr+1;         
                     }
                 }
}

void offer(int ctr, int B[],int V[])
{
     int ave,totalB=0,totalV=0,ctr2;
     for(ctr2=0;ctr2<26;ctr2++)
       {
         totalB=totalB+B[ctr2+1];
         totalV=totalV+V[ctr2];
       }
     ave=(totalV-totalB)/(26-ctr)/10;
     cout<<"\n\n";
     cout<<"The banker offered: "<<ave<<"\n";
} 

char deal(int special,int briefcase[])
{
 char letter;
 cout<<"Enter\n"; 
 cout<<"Y if Deal\n";
 cout<<"N if No Deal\n";
 cin>>letter;
 if(letter=='Y' or letter=='y')
  {
   cout<<"You accepted the banker's offer.\n";
   cout<<"The value of your briefcase is "<<briefcase[special]<<"\n";
  }
 return letter;
} 
