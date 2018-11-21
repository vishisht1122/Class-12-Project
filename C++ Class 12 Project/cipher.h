#include<iostream>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;
string filo="Plaintxt.txt";
string file="Filer.txt";
char Q[26]=
{
'A','B','C','D','E','F','G','H','I',
'J','K','L','M','N','O','P','Q','R',
'S','T','U','V','W','X','Y','Z'
};
int n,a1,b1;


void Write(std::string const& fileName, std::string const& data)
{
   ofstream binFile(fileName.c_str(),ios::trunc);
   if (binFile.is_open())
   {
      size_t len = data.size();
      binFile.write((char*)&len, sizeof(len));
      binFile.write((char*)&data[0], len);
   }
}

void Read(std::string const& fileName, std::string& data)
{
   ifstream binFile(fileName.c_str());
   if(binFile.is_open())
   {
      size_t len = 0;
      binFile.read((char*)&len, sizeof(len));
      data.resize(len);
      binFile.read((char*)&data[0], len);
   }
}

void Vign(string b,int q)
{
  string a;
  if(q==1)
  {
    Read(filo,a);
  }

  else if(q==2)
  {
    Read(file,a);
  }
  string c=a;
  string d=a;

  for(int i=0;i<a.length();i++)
  {
   c[i]=b[i];
   if(i>=b.length())
   {
     c[i]=b[i-b.length()];
   }
  }
  //cout<<"KeyText is "<<c<<endl;
  for(int j=0;j<a.length();j++)
  {

    if(q==1)
    {
      if(a[j]==' ')
        d[j]=a[j];
      else
      d[j]=((a[j]+c[j])%26)+'A';
    }
    if(q==2)
    {
      if(a[j]==' ')
        d[j]=a[j];
      else
      d[j]=((a[j]-c[j]+26)%26)+'A';
    }
  }
  //cout<<d;
  cout<<"Written To File!!\n";
  Write(file,d);
}

void PF(string b,int q){
  string removeDuplicate(string str);
  string a;
  if(q==1)
  {
    Read(filo,a);
  }
  else if(q==2)
  {
    Read(file,a);
  }
  char z[5][5];
  string t;
  string g;
  string pfcphr="ABCDEFGHIKLMNOPQRSTUVWXYZ";
  string coder=removeDuplicate(b)+pfcphr;
  string fincoder=removeDuplicate(coder);
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      z[j][i]=fincoder[i+5*j];
    }
  }
    if(q==1)
    {
      cout<<"the coding matrix is :\n\n";
      for(int c=0;c<5;c++)
      {
        for(int d=0;d<5;d++)
        {
          cout<<z[c][d]<<" ";
        }
        cout<<endl;
      }
    for(int e=0;e<a.length();e++)
    {
      for(int c=0;c<5;c++)
      {
        for(int d=0;d<5;d++)
        {
          if(a[e]==z[c][d])
          {
            g+=c+1+'0';
            g+="|";
            g+=d+1+'0';
            g+=" ";
          }

          else if(a[e]==' ')
          {
            g+=0+'0';
            g+="|";
            g+=0+'0';
            g+=" ";
          }
        }
      }
    }
    cout<<"Written To File!!\n";
    Write(file,g);
  }
  else if(q==2)
  {
      for(int v=0;v<a.length();v++)
      {
      if(a[v]=='|' && a[v]!=' ')
      {
        int frst=(a[v-1]-'0');
        int scnd=(a[v+1]-'0');
        if(frst>0 && scnd>0)
        t+=z[frst-1][scnd-1];
        else
        t+=' ';
      }
    }
    cout<<"Written To File!!\n";
    Write(file,t);
  }
}

string removeDuplicate(string str)
{
   int index = 0;
   for (int i=0; i<str.length(); i++){
     int j;
     for (j=0; j<i; j++){
      if (str[i] == str[j]||str[i]=='J')
       break;
       }
     if (j == i)
      str[index++] = str[i];
   }
   return str;
}

void ROT13(int q)
{
  string a;
  if(q==1)
  {
    Read(filo,a);
  }

  else if(q==2)
  {
    Read(file,a);
  }
  string d=a;
  for(int j=0;j<a.length();j++)
  {
      if(a[j]==' ')
        d[j]=a[j];
      else
      d[j]=(((a[j]-'A')+13)%26)+'A';
  }
  //cout<<d;
  Write(file,d);
  cout<<"Written To File!!\n";
}
void pmenu(void)
{
  cout<<"====================================\n";
  cout<<"\n\n\nFILE DECODER/ENCODER\n\n\n";
  cout<<"====================================\n";
  cout<<"0)Enter Plaintext In File\n";
  cout<<"1)Vignere Cipher\n";
  cout<<"2)Playfair Cipher\n";
  cout<<"3)ROT13 Cipher\n";
  cout<<"4)Affine Cipher\n";
  cout<<"Enter Choice:\n::";
}

void encryptionMessage(void)
{
    string Msg;
    Read(filo,Msg);
    string CTxt = "";
    int a = 3;
    int b = 7;
    for (int i = 0; i < Msg.length(); i++)
    {
      if(!isalpha(Msg[i]))
      CTxt = CTxt + (char) ((((a * Msg[i]) + b) % 26) + 65);
      else
      CTxt=CTxt + Msg[i];
    }
    Write(file,CTxt);
}

void decryptionMessage(void)
{
    string CTxt;
    Read(file,CTxt);
    string Msg = "";
    int a = 3;
    int b = 7;
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < CTxt.length(); i++)
    {
      if(CTxt[i]!=' ')
      Msg = Msg + (char) (((a_inv * ((CTxt[i] - b)) % 26)) + 65);
      else
      Msg = Msg + CTxt[i];
    }
    Write(file,Msg);
}
