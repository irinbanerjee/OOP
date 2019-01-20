#include <iostream>
#include <string.h>
//#define printf("\e[2J\e[H")
using namespace std;

//Defning TIME class 
class TIME{
	int hour,min,sec;
	inline void set_data(int=0,int=0,int=0);
	public:
		inline void get_data(void);
		inline void display_data(void);
		inline void add_min(void);
};
//------------------------------------------------------------------------
inline void TIME::set_data(int h,int m,int s){
	hour=h;
	min=m;
	sec=s;
};

inline void TIME::get_data(void){
	int h,m,s;
	char str[13];
	cout<<"Enter time in AM/PM or 24-hour format\n";
	cout<<"Use this format [HR]:[MIN]:[SEC](AM/PM)\n";
	cout<<"Enter XX if 24 hour format is used\n";
	cin>>str;
	h=(int)(str[0]-48)*10+(int)(str[1]-48);
	m=(int)(str[3]-48)*10+(int)(str[4]-48);
	s=(int)(str[6]-48)*10+(int)(str[7]-48);
	if(str[9]=='\0'){set_data(h,m,s);}
	else if(str[9]='A'){set_data(h,m,s);}
	else if(str[9]='P'){set_data(h+12,m,s);}
};
//------------------------------------------------------------------------
inline void TIME::display_data(void){
	int choice;
	cout<<"Press to display in :\n(1)24-hour format\n(2)AM/PM format\n";
	cin>>choice;
	if(choice==1){printf("%2d:%2d:%2d\n",hour,min,sec);}
	else if(choice==2){
		if(hour<=12){printf("%2d:%2d:%2d AM\n",hour,min,sec);}
		else{printf("%2d:%2d:%2d PM\n",hour-12,min,sec);};
	}
	else{cout<<"INVALID INPUT\n";};
};

//------------------------------------------------------------------------
inline void TIME::add_min(void){
	int m;
	cout<<"Enter minutes to add: ";
	cin>>m;
	min=min+m;
	if(min>59){
		hour=hour+min/60;
		min=min%60;
	};
}

//------------------------------------------------------------------------
int main(){
	int choice;
	while(1){
		//printf("\e[2J\e[H");
		cout<<"----------------------------------------------------------\n";
		cout<<"Press to choose the option :\n";
		cout<<"(0)To exit menu\n(1)Create a time object\n";
		cin>>choice;
		if(choice==0){break;}
		else{
			TIME obj;
			obj.get_data();
			//printf("\e[2J\e[H");
			cout<<"Press to choose the option :\n";
			cout<<"(0)To exit menu\n(1)Display object\n(2)Add mintute\n";
			cin>>choice;
			if(choice==0){break;}
			else if(choice==1){obj.display_data();}
			else{obj.add_min();obj.display_data();};
		};
		
	};
	return 0;
}
