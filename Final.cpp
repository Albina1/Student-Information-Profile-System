//header files
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#define FIELD_SIZE 25
#define length(array) ( sizeof (array) / sizeof (array)[i] )


struct account {
  char *id;
  char *password;
};

static struct account accounts[] = {
  { "user1", "khwopa" },
  { "user2", "khwopa" },
  { "user3", "khwopa" }
};

int is_authorized ( const char *uid, const char *pwd )
{
  int i;

  for ( i = 0; i < length ( accounts ); i++ ) {
    if ( stricmp ( uid, accounts[i].id ) == 0 &&
	 strcmp ( pwd, accounts[i].password ) ==0 )
    {
      return 1;
    }
  }

  return 0;
}

void get_password ( char *pwd, int size )
{
  int i = 0;
  int ch;

  while ( i < size - 1 && ( ch = getch() ) != '\r' ) {
    if ( ch == '\b' ) {
      /* Don't run off the front end of the array */
      if ( i != 0 ) {
	printf ( "\b%c\b", ' ' );
	--i;
      }
    }
    else {
      putchar ( '*' );
      pwd[i++] = (char)ch;
    }
  }

  pwd[i] = '\0';
}

void login()
{
  char uid[FIELD_SIZE];
  char pwd[FIELD_SIZE];

  printf ( "User ID: " );
  fflush ( stdout );

  if ( fgets ( uid, sizeof uid, stdin ) != NULL ) {
    char *newline = strchr ( uid, '\n' );

    /* Trim the newline if it's present */
    if ( newline != NULL )
      *newline = '\0';

    printf ( "Password: " );
    fflush ( stdout );

    get_password ( pwd, sizeof pwd );

    if ( is_authorized ( uid, pwd ) )
     { printf("\n\n\t\tUSER AUTHENTICATED\n");}
    else
     { printf("\n\n\t\tINVALID USER\n");
     getch();
     cout<<"Try Again\n\n";
     login();
     }
  }


}

void callup()
{ int font=0;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  setcolor(8);
  settextstyle(font, HORIZ_DIR,1);
  outtextxy(30,469,"Mahesh Yakami     Prabin Shaiju     Rabina Prajapati     Sanjeev Tamang");

}

//class defined
class student
{
	int rollno, attendance, m11_marks, c11_marks, p11_marks, e11_marks, cb11_marks,mb12_marks,c12_marks,p12_marks,e12_marks,n12_marks;
	float per11,per12;
	char grade11, grade12, name[50], group;
	void calculate11();	//function to calculate grade of 11
	void calculate12();	//function to calculate grade of 12
public:

	void getdata11();       //function to accept data of grade 11 from user
	void getdata12();       //function to accept data of grade 12 from user
	void showdata11();	//function to show data of 11 on screen
	void showdata12();	//function to show data of 12 on screen
	void show_tabular();    //to show result in tabular form
	void mainintro();       //for startup graphics
	int retrollno();        //returns roll no
	char grp();             //returns group
}; //end of class


void /*student::*/mainintro()
{    int gd=DETECT,gm;
     int x=35,y=100;
     int a,b,c;
     int font=0;
     initgraph(&gd,&gm,"C:\\TC\\BGI");
     setcolor(19);
     settextstyle(font, HORIZ_DIR,2);
     outtextxy(x,y,"STUDENT INFORMATION PROFILE SYSTEM");
     settextstyle(font,HORIZ_DIR,1);
     outtextxy(200,260,"***  3rd Sem Final Project  ***");
     setcolor(13);
     outtextxy(450,405,":Mahesh Yakami");
     outtextxy(450,420,":Prabin Shaiju");
     outtextxy(450,435,":Rabina Prajapati");
     outtextxy(450,450,":Sanjeev Tamang");
     //setlinestyle(1,0,1);
     line(0,0,640,0);
     line(0,0,0,480);
     line(639,0,639,480);
     line(639,479,0,479);
     for(a=1;a<=1000;a++)
      {
	b=rand()%639;
	c=rand()%480;
	putpixel(b,c,2);
     }

     getch();
     closegraph();
}


char student::grp()
  {
     return(group);
  }


void student::calculate11()
{
	per11=(m11_marks+c11_marks+p11_marks+e11_marks+cb11_marks)/5.0;

	if(m11_marks>=32 && c11_marks>=32 && p11_marks>=32 && e11_marks>=32 && cb11_marks>=32)
	{
	  if(per11>=80)
		grade11='A';
	  else if(per11>=60)
		grade11='B';
	  else if(per11>=50)
		grade11='C';
	  else
		grade11='D';
	}
	else
		grade11='F';
}

void student::calculate12()
{
	per12=(mb12_marks+c12_marks+p12_marks+e12_marks+n12_marks)/5.0;

	if(mb12_marks>=32 && c12_marks>=32 && p12_marks>=32 && e12_marks>=32 && n12_marks>=32)
	{
	  if(per12>=80)
		grade12='A';
	  else if(per12>=60)
		grade12='B';
	  else if(per12>=50)
		grade12='C';
	  else
		grade12='D';
	}
	else
		grade12='F';
}

void student::getdata11()
{

	cout<<"\nEnter the roll number of student			   : ";
	cin>>rollno;
	cout<<"\n\nEnter the Name of student 				   : ";
	gets(name);
	cout<<"Enter P for Physical group and B for Biological group       :";
	s:
	  group=getche();
	  if(group=='P' || group=='B')
	   {
	    cout<<"\nsuccess";
	    getch();
	   }
	  else
	  {
	   goto s;
	  }
	cout<<"\nEnter total attendance in grade 11\t\t";
	cin>>attendance;

	cout<<"Enter information of grade 11\n";

		cout<<"\nEnter the marks in Mathematics out of 100      : ";
	Mrk1:
		cin>>m11_marks;
		if (m11_marks<0 || m11_marks>100)
		{
			goto Mrk1;
		}



		cout<<"\nEnter the marks in Chemistry out of 100        : ";
	Mrk2:
		cin>>c11_marks;
		if (c11_marks<0 || c11_marks>100)
		{
			goto Mrk2;
		}

		cout<<"\nEnter the marks in Physics out of 100	        : ";

	Mrk3:
		cin>>p11_marks;
		if (p11_marks<0 || p11_marks>100)
		{
			goto Mrk3;
		}

		cout<<"\nEnter the marks in English out of 100 	        : ";
	Mrk4:
		cin>>e11_marks;
		if (e11_marks<0 || e11_marks>100)
		{
			goto Mrk4;
		}

		cout<<"\nEnter the marks in Computer/Biology out of 100 : ";
	Mrk5:
		cin>>cb11_marks;
		if (cb11_marks<0 || cb11_marks>100)
		{
			goto Mrk5;
		}



	calculate11();
}

void student::getdata12()
{

	cout<<"Enter total attendance in grade 12\t\t";
	cin>>attendance;


	cout<<"Enter information of grade 12\n";

		cout<<"\nEnter the marks in Mathematics/Biology out of 100 : ";
	Mrk1:
		cin>>mb12_marks;
		if (mb12_marks<0 || mb12_marks>100)
		{
			goto Mrk1;
		}



		cout<<"\nEnter the marks in Chemistry out of 100           :";
	Mrk2:
		cin>>c12_marks;
		if (c12_marks<0 || c12_marks>100)
		{
			goto Mrk2;
		}

		cout<<"\nEnter the marks in Physics out of 100		   : ";

	Mrk3:
		cin>>p12_marks;
		if (p12_marks<0 || p12_marks>100)
		{
			goto Mrk3;
		}

		cout<<"\nEnter the marks in English out of 100 	           : ";
	Mrk4:
		cin>>e12_marks;
		if (e12_marks<0 || e12_marks>100)
		{
			goto Mrk4;
		}

		cout<<"\nEnter the marks in Nepali out of 100              : ";
	Mrk5:
		cin>>n12_marks;
		if (n12_marks<0 || n12_marks>100)
		{
			goto Mrk5;
		}



	calculate12();
}

void student::showdata11()
{
	cout<<"\nRoll number of student     : "<<rollno;
	cout<<"\nName of student            : "<<name;
	cout<<"\nGroup of student           : ";
	if(grp()=='P')
	{cout<<"Physical";}
	else
	{cout<<"Biological";}
	cout<<"\nMarks in Mathematics       :   "<<m11_marks;
	cout<<"\nMarks in Chemistry 	    :   "<<c11_marks;
	cout<<"\nMarks in Physics	    :   "<<p11_marks;
	cout<<"\nMarks in English           :   "<<e11_marks;
	cout<<"\nMarks in Computer/Biology  :   "<<cb11_marks;
	cout<<"\n\npercentage of student    :   "<<per11;
	cout<<"\nGrade of student is 	    : \n"<<grade11;
}

void student::showdata12()
{
	cout<<"\nMarks in Mathematics/Biology : "<<mb12_marks;
	cout<<"\nMarks in Chemistry 	      : "<<c12_marks;
	cout<<"\nMarks in Physics	      : "<<p12_marks;
	cout<<"\nMarks in English             : "<<e12_marks;
	cout<<"\nMarks in Nepali 	      : "<<n12_marks;
	cout<<"\n\npercentage of student      : "<<per12;
	cout<<"\nGrade of student is 	      : "<<grade12;
}

void student::show_tabular()
{
	cout<<rollno<<"   "<<setw(18)<<name<<"   "<<group<<"        "<<m11_marks<<"        "<<c11_marks<<"   "<<p11_marks<<"   "<<e11_marks<<"     "<<cb11_marks<<"       "<<setw(4)<<per11<<"    "<<grade11<<endl;
	cout<<setw(34)<<" "<<mb12_marks<<"        "<<c12_marks<<"   "<<p12_marks<<"   "<<e12_marks<<"     "<<n12_marks<<"       "<<setw(4)<<per12<<"    "<<grade12<<endl;

}


int  student::retrollno()
{
	return rollno;
}


//function used

void write_student();   	//write the record in binary file
void display_all();	        //read all records from binary file
void display_sp(int);	        //accept rollno and read record from binary file
void modify_student(int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();        	//display all records in tabular format from binary file
void result();	               	//display result menu
void entry_menu();	        //display entry menu on screen


//main function


void main()
{
	char ch;
	//cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2);   // program outputs decimal number to two decimal places
	clrscr();
	mainintro();
	clrscr();
	login();



	do
	{       clrscr();
		callup();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		clrscr();
		closegraph();
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
	}while(ch!='3');
      }

//writing into file function

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata11();
	st.getdata12();
	outFile.write((char *) &st, sizeof(student));
	outFile.close();
	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();             //Causes up to n characters in the input stream to be skipped; stops if delim is encountered.
	getch();
}


//display all

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showdata11();
		st.showdata12();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	getch();
}

//read using id number

void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()==n)
		{
			 st.showdata11();
			 st.showdata12();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}

//modify record

void modify_student(int n)
{
	int found=0;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(student)) && found==0)
	{
		if(st.retrollno()==n)
		{
			st.showdata11();
			st.showdata12();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata11();
			st.getdata12();
			int pos=(-1)*sizeof(st);
			File.seekp(pos,ios::cur);
			File.write((char *) &st, sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}


//delete record

void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) &st, sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}

//display all record

void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"================================================================================\n";
	cout<<"RN         Name          grp      Maths    Chem  Phy  Eng Cmptr/Bio   (%)  Grade";
	cout<<"                                Maths/Bio  Chem  Phy  Eng    Nep      (%)  Grade";
	cout<<"================================================================================\n";
	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.show_tabular();
	}
	getch();
	inFile.close();
}

//display result menu

void result()
{
	int in;
	int rno;
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1/2/3)? ";
	cin>>in;
	clrscr();
	switch(in)
	{
	case 1 :class_result(); break;
	case 2 :cout<<"\n\n\tEnter Roll Number Of Student : ";
		  cin>>rno;
		  display_sp(rno); break;
	case 3 :break;
	default :cout<<"\a";
	}
}


//entry and edit menu

void entry_menu()
{
	char ch;
	int num;
	clrscr();
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	cout<<"\a"; entry_menu();
	}
}


