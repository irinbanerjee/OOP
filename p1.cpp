#include <iostream>
#include <string.h>
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
	char str[2];
	cout<<"Enter time in AM/PM or 24-hour format\n";
	cout<<"Use this format [HR]:[MIN]:[SEC](AM/PM/XX)\n";
	cout<<"Enter XX if 24 hour format is used\n";
	scanf("%2d:%2d:%2d%s",&h,&m,&s,str);
	if(str[0]==' '){set_data(h,m,s);}
	else if(str[0]='A'){set_data(h,m,s);}
	else if(str[0]='P'){set_data(h+12,m,s);}
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
	TIME obj;
	obj.get_data();
	obj.display_data();
	obj.add_min();
	obj.display_data();
	return 0;
};
