#include "cipher.h"
using namespace std;
int main()
{

  int choice=1;
  string c,a;
  do
  {
    pmenu();
    cin>>choice;
    switch (choice)
    {
      case 0:
      {
        cout<<endl;
        cin.ignore();
        getline(cin,a);
        Write("Plaintxt.txt",a);
        system("open Plaintxt.txt");
        break;
      }
      case 1:
      {
        cout<<"Encode String(1)\nDecode String(2)??:";
        cin>>n;
        cout<<"\nEnter Key(All CAPS):";
        cin.ignore();
        getline(cin,c);
        Vign(c,n);
        system("open Filer.txt");
        break;
      }
      case 2:
      {
        cout<<"Encode String(1)\nDecode String(2)??:";
        cin>>n;
        cout<<"\nEnter Key(All CAPS):";
        cin.ignore();
        getline(cin,c);
        PF(c,n);
        system("open Filer.txt");
        break;
      }
      case 3:
      {
        cout<<"Encode String(1)\nDecode String(2)??:";
        cin>>n;
        ROT13(n);
        system("open Filer.txt");
        break;
      }
      case 4:
      {
        cout<<"Encode String(1)\nDecode String(2)??:";
        cin>>n;
        if(n==1)
        {
          encryptionMessage();
        }
        else if(n==2)
        {
          decryptionMessage();
        }
        system("open Filer.txt");
        break;
      }
    }
  }
 while(choice==1||choice==2||choice==3||choice==4||choice==0);
 return 0;
}
