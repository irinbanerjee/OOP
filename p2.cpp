#include <iostream>
#include <string.h>
using namespace std;

//Class attribute and functions declarations
class complex{
	float real,img;
	void set_data(float=0,float=0);
	public:
		//void display_data(void);
		friend ostream & operator << (ostream &out, complex &c); 
   		friend istream & operator >> (istream &in,  complex &c); 
		complex operator +(complex);
		complex operator -(complex);		
};
 
//Class function definitions
void complex::set_data(float r,float i){
	real=r;
	img=i;
};

ostream & operator << (ostream &out, complex &c) { 
	out << c.real; 
	if(c.img>0){out<<"+"<<c.img<<"i";}
	else if(c.img<0){out<<c.img<<"i";}
	out <<"\n"; 
	return out; 
};
  
istream & operator >> (istream &in, complex &c) { 
	cout<<"Enter real part :";
	in >> c.real; 
	cout<<"Enter complex part :";
	in >> c.img; 
	return in; 
};

complex complex::operator +(complex obj){
	complex result;
	result.set_data(real+obj.real,img+obj.img);
	return result;
};

complex complex::operator -(complex obj){
	complex result;
	result.set_data(real-obj.real,img-obj.img);
	return result;
};

/*void complex::display_data(void){
	cout<<real<<"+"<<img<<"i\n";
};*/

//Main function
int main(){
	complex a,b,c;
	int choice;
	cout<<"-------------------------------------------------------------\n";
	cout<<"Press :\n(1)To add 2 complex numbers\n(2)To find the difference\n";
	cout<<"-------------------------------------------------------------\n";
	cin>>choice;
	cout<<"-------------------------------------------------------------\n";
	cout<<"Enter 1st complex number :\n";cin>>a;
	cout<<"-------------------------------------------------------------\n";
	cout<<"Enter 2nd complex number:\n";cin>>b;
	cout<<"-------------------------------------------------------------\n";
	cout<<"Answer :";
	if(choice==1){c=a+b;cout<<c;}
	else{c=a-b;cout<<c;};	
	cout<<"-----------------------------------------------------------\n";	
	return 0;
};
	

