#include <iostream>
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
    out <<"+("<< c.img<< ")i\n"; 
    return out; 
};
  
istream & operator >> (istream &in, complex &c) { 
    in >> c.real; 
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
	cin>>a;
	cin>>b;
	c=a-b;
	cout<<c;
	return 0;
};
	

