#include<time.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
int logs=0;
char na[80];
struct login
{
 char name[40];
 char pass[40];
 }ob;
class crim_rec
{
    char doj[50],name[20], sex, fathr_name[20], addrs[25], offense[20], blood[5], dob[9];
    int crim_code,leav;float reward;
    void disp();
public:
    void get();
    void wf();
    void rff();
    void search();
    void del();
    void mod();
    void salmod();
    void inc();
    void leave();
}c;
void crim_rec::get()
{
randomize();
    puts("Enter name of employee:");
    gets(name);
    puts("gender (m/f):");
    do
    {
    cin>>sex;
     if(sex!='m'&&sex!='f')
      cout<<"Please enter a valid gender :";
    }while(sex!='m'&&sex!='f');
    puts("Enter date of birth:");
    gets(dob);
    puts("Enter blood group (Ap/An/Bp/Bn/ABp/ABn/Op/On:");
    gets(blood);
    puts("Enter father's name:");
    gets(fathr_name);
    puts("Enter address:");
    gets(addrs);
    puts("Enter job:");
    gets(offense);
    if(strcmpi(offense,"Janitor")==0)
	 reward=random(200)+2000;
     else if(strcmpi(offense,"Manager")==0)
	 reward=random(200)+10000;
      else if(strcmpi(offense,"Vice President")==0)
	 reward=random(2000)+20000;
      else if(strcmpi(offense,"Senior Vice President")==0)
	 reward=random(2000)+30000;
      else if(strcmpi(offense,"President")==0)
	 reward=random(4000)+50000;
     else if(strcmpi(offense,"Chairman")==0)
	 reward=random(5000)+75000;
      else if(strcmpi(offense,"Team Leader")==0)
	 reward=random(2500)+35000;
    leav=0;
    cout<<"Transferring data to server.......";
    delay(1000);
}
void crim_rec::disp()
{

    cout<<"\nThe record of employee:\n";
    cout<<"\nName of employee: "<<name;
    cout<<"\ngender: "<<sex;
    cout<<"\nDOB: "<<dob;
    cout<<"\nBlood Group: "<<blood;
    cout<<"\nFather's name: "<<fathr_name;
    cout<<"\nAddress: "<<addrs;
    cout<<"\nDesignation: "<<offense;
    cout<<"\nSalary: "<<reward;

}
void crim_rec::salmod()
 {

 time_t timer,t2;
struct tm *tblock;
 fstream f;
    f.open("CBI.dat", ios::in|ios::out|ios::binary);
    f.seekg(0, ios::beg);

while( f.read((char*)&c, sizeof(c)))
{
/* gets time of day */
timer = time(NULL);

/* converts date/time to a structure */
tblock = localtime(&timer);
strcpy(doj,asctime(tblock));
}
cout<<"\nDate of joining is:";
puts(doj);
 char d[20];
  d[0]=doj[4];
  d[1]=doj[5];
  d[2]=doj[6];
  d[3]='\0';
   if(strcmpi(d,"Jan")==0)
     reward=reward+5000;
  t2=time(NULL);
   if(difftime(t2,timer)==31540000)
    leav=0;


 f.close();
 }
void crim_rec::wf()
{
    ofstream ofile;
    ofile.open("CBI.dat", ios::app|ios::binary);
    get();
    ofile.write((char*)&c, sizeof(c));
    ofile.close();
}
void crim_rec::rff()
{
    ifstream ifile;
    int o=0;
    ifile.open("CBI.dat",ios::binary);
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
    if(o>0&&o%2==0)
      {
       cout<<"\nEnter to view next rec(s)";
       getch();
      }
	disp();
	ifile.read ((char*)&c, sizeof(c));
	o++;
    }
    ifile.close();
}
void crim_rec::search()
{
    char m[20];
    ifstream ifile("CBI.dat",ios::binary);
    puts("Enter name of employee which has to be searched");
    gets(m);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	if (strcmpi(m, name)==0)
	    disp();
	    ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
}
void crim_rec::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("CBI.dat", ios::app|ios::binary);
    ofstream ofile;
    ofile.open("New.dat", ios::app|ios::binary);
    puts("Enter the name of the employee whose records you want to del");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	if (strcmpi(b, name))
	    ofile.write((char*)&c, sizeof(c));
	ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("CBI.dat");
    rename("new.dat", "CBI.dat");
    }
void crim_rec::mod()
{
    char d[20];
    int ch;
    char choice1, choice;
    int p;
    puts("\nEnter name of employee whose record you want to modify\n");
    gets(d);
    fstream f;
    f.open("CBI.dat", ios::in|ios::out|ios::binary);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
	if (!strcmpi(d, name))
	{
	    puts("\n-Press 1 to change name\n-Press 2 to change Gender\n-Press 3 to change date of birth\n-Press 4 to change blood group\n-Press 5 to change father's name\n-Press 6 to change address\n-Press 7 to change JOB\n-Press 8 to change Salary\n");
	    cin>>p;
	    switch(p)
	    {
	    case 1:
		cout<<"Enter changed name of "<<name<<":";
		gets(name);
		break;
	    case 2:
		cout<<"Enter the new Gender of "<<name<<":";
		cin>>sex;
		break;
	    case 3:
		cout<<"Enter the new birth date of "<<name<<":";
		gets(dob);
		break;
	    case 4:
		cout<<"Enter the correct blood group of "<<name<<":";
		gets(blood);
		break;
	    case 5:
		cout<<"Enter correct fathers name of "<<name<<":";
		gets(fathr_name);
		break;
	    case 6:
		cout<<"Enter the correct address of "<<name<<":";
		gets(addrs);
		break;
	    case 7:
		cout<<"Enter the correct Designation of the employee "<<name<<":";
		gets(offense);
		break;
	      case 8:
		cout<<"Enter the correct SALARY of the employee "<<name<<":";
		cin>>reward;
		break;
	    }
	    f.seekg(a-sizeof(c), ios::beg);

	    f.write((char*)&c, sizeof(c));
	}
	f.read((char*)&c, sizeof(c));
	a=f.tellg();
    }
    f.close();

}

void crim_rec::inc()
 { char na[20]; int ch;
 int amt1,amt2,sal1,sal2;
 cout<<"Enter Employee name";
 gets(na);
   cout<<"Enter \n1.House Loan \n2.Car Loan ";
    cin>>ch;
    fstream f1("CBI.dat",ios::in|ios::out|ios::binary);
    while(f1.read((char*)&c,sizeof(c)))
     {
      if(strcmpi(c.name,na)==0)
	{
	break;
	}
      }
f1.seekg((f1.tellg()-sizeof(c)),ios::beg);
	if(ch==1)
	 {
	 cout<<"Enter the amount you want to withdraw: ";
	 cin>>amt1;
	 sal1=reward/12;
	 reward=reward-sal1;
	 cout<<"Your new salary until your house loan is repaid: ";
	 cout<<reward;
	 }
	else if(ch==2)
	{
     cout<<"Enter the amount you want to withdraw: ";
      cin>>amt2;
      sal2=amt2/12;
      reward=reward-sal2;
      cout<<"Your new salary until your car loan is repaid: ";
      cout<<reward;
     }




  f1.write((char*)&c,sizeof(c));



 f1.close();
 }
void crim_rec::leave()
 {  int n;
    char nam[20];
 cout<<"Enter Employee name";
  gets(nam);
   fstream f1("CBI.dat",ios::in|ios::out|ios::binary);
   while(f1.read((char*)&c,sizeof(c)))
     {
     if(strcmpi(c.name,nam)==0)
      {
       break;
       }
    }
f1.seekg((f1.tellg()-sizeof(c)),ios::beg);
  cout<<"Enetr Number of days you want to take a holiday for (Enter 108.if maternity leave)";
  cin>>n;
  if(n==108)
    cout<<"You are granted free holiday of 4 days";
 else
   {

    for(int i=0;i<n;i++)
     leav++;
   if(leav>4&&leav<10)
    reward=reward-1000;
   else if(leav>10&&leav<20)
    reward=reward-2000;
   else if(leav>20)
   {
   reward=0;

    cout<<"You have taken a lot of holidays you will not be paid this month";
   }
 }
   f1.write((char*)&c,sizeof(c));

  f1.close();

 }
 void password(char pw[50])
  {
   int i;
   char ch;
   i=0;
    do
     {
      ch=getch();
      if(ch!='\b')
       {
	if(ch!='\n'&&ch!='\r')
	 {
	  cout<<'*';
	  pw[i++]=ch;
	 }
      }
     else if(i>0)
     {
     cout<<'\b'<<' '<<'\b';
     i--;
     }
     }while(ch!='\n'&&ch!='\r');
    pw[i]='\0';
 }
void sign()
		  {

		  ofstream f("login.dat",ios::binary);
		   cout<<"enter username: ";
		   gets(ob.name);
		   cout<<"enter password: ";
		   password(ob.pass);

		   f.write((char*)&ob,sizeof(ob));
		   f.close();
		   }
		  void check()
		  {
		  ifstream f("login.dat",ios::binary);
		   login x;
		   cout<<"Enter Username: ";
		   gets(x.name);
		   strcpy(na,x.name);
		   cout<<"Enter Password: ";
		   password(x.pass);
		   while(f.read((char*)&ob,sizeof(ob)))
		    {
		     if(strcmpi(x.name,ob.name)==0&&strcmpi(x.pass,ob.pass)==0)
		     {
		     logs=1;
		     cout<<"\nLogin succesful\n";
		     }
		     else
		     {
		     logs=0;
		     cout<<"ERROR pass or name wrong!!!!\n";
		     }
		     }
		   }

void main ()
{
    int ch;
    char choice;
do
{
    clrscr();
 if(logs==1)
 {
    do
    {
    cout<<"\t\t VALUESOFT \n";
    cout<<"Welcome "<<na;
    cout<<"\n ********************************************";
    cout<<"\n\n *  1. View employee details                *";
    cout<<"\n\n *  2. Add new employee details             *";
    cout<<"\n\n *  3. Search a employee record             *";
    cout<<"\n\n *  4. Delete a employee record             *";
    cout<<"\n\n *  5. Modify a employee record             *";
    cout<<"\n\n *  6. Incentives                           *";
    cout<<"\n\n *  7. Holidays                             *";
    cout<<"\n\n *  8. Exit                                 *";
    cout<<"\n\n *  9. LOGOUT                               *";
    cout<<"\n ********************************************\n";
    cin>>ch;
 if(ch == 1)
 {
 cout<<"Fetching Data.........\n";
    delay(1000);
    c.rff();
    }
 else if(ch==2)
 {
    c.wf();
    c.salmod();
    }
 else if(ch==3)
   {
    c.search();
     cout<<"Fetching Data.........\n";
    delay(1000);
    }
 else if(ch==4)
   {c.del();
    cout<<"deleting Data.........\n";
    delay(1000);
   }
 else if(ch==5)
	c.mod();
 else if(ch==6)
	c.inc();
 else if(ch==7)
	c.leave();

 else if(ch==8)
 {
 cout<<"\nThank you for using the EMPLOYEE MANAGEMENT SYSTEM. DO COME AGAIN";
 getch();
 exit(0);
 }
  else if(ch==9)
   {
   logs=0;
   cout<<"Logging out.........\n";
    delay(1000);
   }
    else	{
	cout<<"\nERROR! SYSTEM PROTOCOL DEVIATION";
	}

    cout<<"\nContinue? (any char)\n";
    getch();
    clrscr();

    }while(logs==1);
    if(choice=='n' || choice == 'N');
    {
    cout<<"WAIT.......";
    delay(1000);
    clrscr();
    }
}//1st if

if(logs==0)
 {
    do
    {
    cout<<"\t VALUESOFT ";
    cout<<"\n ********************************************";
    cout<<"\n\n *  1. View employee details                *";
    cout<<"\n\n *  2. LOGIN                                *";
    cout<<"\n\n *  3. Search an Employee                   *";
    cout<<"\n\n *  4. SIGNUP                               *";
    cout<<"\n\n *  5. Exit                                 *";
    cout<<"\n ********************************************";
    cin>>ch;
 if(ch == 1)
 {
 cout<<"Fetching Data.........\n";
    delay(1000);
    c.rff();
    }
 else if(ch==2)
 {
    check();

    }
 else if(ch==3)
   {
    cout<<"Fetching Data.........\n";
    delay(1000);
    c.search();

    }
 else if(ch==4)
   {
   sign();
   cout<<"\nSignup succesful";
   }
 else if(ch==5)
 {
 cout<<"\nThank you for using the EMPLOYEE MANAGEMENT SYSTEM. DO COME AGAIN";
 getch();
 exit(0);
 }

    cout<<"\nContinue? (Any char)\n";
    getch();
    clrscr();

    }while(logs==0);
    if(choice=='n' || choice == 'N');
    {
    cout<<"WAIT.......";
    delay(1000);
    }
  }
}while(1);
}
