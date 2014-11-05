#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;
int main () {
    char search[50],choice;
    do
    {
    printf("Enter word:");
    scanf("%s",&search);
    if(strcmp(strlwr(search),"cpu")==0)
    {
  ifstream ifs ( "cpu.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"program")==0)
    {
  ifstream ifs ( "program.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"programmer")==0)
    {
  ifstream ifs ( "programmer.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"flowchart")==0)
    {
  ifstream ifs ( "flowchart.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"programming")==0)
    {
  ifstream ifs ( "programming.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"syntax")==0)
    {
  ifstream ifs ( "syntax.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"byte")==0)
    {
  ifstream ifs ( "byte.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"computer")==0)
    {
  ifstream ifs ( "computer.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
 else if(strcmp(strlwr(search),"ics")==0)
    {
  ifstream ifs ( "ics.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
else if(strcmp(strlwr(search),"ascii")==0)
    {
  ifstream ifs ( "ascii.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
else if(strcmp(strlwr(search),"c++")==0 || strcmp(strlwr(search),"c")==0)
    {
  ifstream ifs ( "c++.txt" , ifstream::in );

  while (ifs.good())
    cout << (char) ifs.get();

  ifs.close();
}
else
printf("\n\nThe word is NOT FOUND!!!!! o baka mali lang spelling mo?? HAHA!!");
printf("\n\nDo you want to enter another word again? [Y/N]");
scanf("%s",&choice);
}
while(choice== 'y' || choice=='Y');
  return 0;
}
