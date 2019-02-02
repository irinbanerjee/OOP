#include <iostream>
#include <string.h>
#define clr printf("\e[2J\e[H")
using namespace std;

//Class Student

//Class attributes and function declaration
class student{
	//Available to all instances of the class
	static int total_students;

	//Private attributes
	int roll;
	char name[100];
	char course[300];
	char addmission_date[17];
	char subject[100][5];
	float marks[5];

	//Private functions
	void generate_roll(void);
	void set_addmission_date(void);
	static void increment_total_student_count(void);

	//Public functions
	public:
	void display_student_info(void);
	void taking_addmission(void);
	void prepare_marksheet(void);
	void display_total_student_count(void);
	
};
	
//Class function definitions

//Generates Roll
void student::generate_roll(void){
	roll=total_students+2019*100000;
};

//Sets addmission date
void student::set_addmission_date(void){
	cout<<"Enter current date: ";
	cin>>addmission_date;
};

//Updates total student number
void student::increment_total_student_count(void){
	total_students++;
};

//Dispalys student info
void student::display_student_info(void){
	cout<<"NAME :"<<name<<"\n";
	cout<<"COURSE :"<<course<<"\n";
	cout<<"ROLL :"<<roll<<"\n";
	cout<<"ADMISSION DATE :"<<addmission_date<<"\n";
};

//Generates roll depending on course
void student::taking_addmission(void){
	cout<<"-----------------------------------------\n";
	cout<<"Please enter the following information:\n";
	cout<<"-----------------------------------------\n";
	cout<<"Enter name :";
	cin>>name;
	cout<<"Enter course name :";
	cin>>course;
	this->generate_roll();
	this->set_addmission_date();
	student.increment_total_student_count();
};


//Preparing Marksheet
void student::prepare_marksheet(void){
	for(int i=0;i<5;++i){
		cout<<"Enter name of Subject "<<i+1<<" :"<<;
		cin>>subject[i];
		cout<<"Enter marks scored in "<<subject[i]<<" :"<<;
		cin>>marks[i];	
		clr;
	};
	
	cout<<"-----------------------------------------\n";
	cout<<"\tMARKSHEET\n";
	cout<<"-----------------------------------------\n";
	cout<<"\tSTUDENT INFORMATION\n";
	cout<<"-----------------------------------------\n";
	this->display_student_info();
	cout<<"-----------------------------------------\n";
	cout<<"\tRESULT\n";
	cout<<"-----------------------------------------\n";
	for(int i=0;i<5;++i){
		cout<<subject[i]<<":\t"<<marks[i]<<"\n";
	};
	cout<<"-----------------------------------------\n";
};

//Displays total student count
void student::display_total_student_count(void){
	cout<<"TOTAL NUMBER OF STUDENTS :"<<total_students<<"\n";
};

//--------------------User Interface Functions--------------------------------

void menu(void){
	cout<<"-----------------------------------------\n\tWELCOME\n";
	cout<<"-----------------------------------------\n";
	cout<<"Choose an option :\n(0)Exit\n(1)Admit a student\n(2)Prepare Marksheet\n(3)Display total student count\n";
};

void process(int choice,int student_list[500],int* count){
	if(choice==1){
		student STUDENT;
		STUDENT.taking_addmission();
		STUDENT.display_student_info();
		student_list[*count]=STUDENT;
		*count++;
	}
	else if(choice==2){
		cout<<"All current students :\n";
		cout<<"-----------------------------------------\n";
		for(int i=0;i<*count;++i){
			cout<<"Student Number :"<<i+1<<"\n";
			student_list[i].display_student_info();
			cout<<"-----------------------------------------\n";
		};
		cout<<"Enter the student number to prepare marksheet :";
		cin>>choice;
		student_list[choice-1].prepare_marksheet();
	}
	else{
		student.display_total_student_count();
	}:
};
			
//=================Main Function========================================
int main(){
	clr;
	student student_list[500];
	int choice,count;
	while(1){
		menu();
		cin>>choice;
		if(choice==0)break;
		process(choice,student_list,&count);
	};
	return 0;
};




