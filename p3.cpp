#include <iostream>
#include <string.h>
#define clr printf("\e[2J\e[H")
using namespace std;

//----------------------------------------------------------------------
//CLASS ITEM
//Class attributes/functions declarations
class item{

	//Private attributes
	char code[100];
	char name[100];
	float rate,quantity;

	//Public functions
	public:
	void set_data(void);
	void display_data(void);
	void set_rate(void);
	void set_quantity(float);
	char* return_code(void);
	char* return_name(void);
	float return_rate(void);
	float return_quantity(void);
	
};

//Member function definition	

//Sets values for item-attributes
void item::set_data(void){
	cout<<"Enter the following information\n";
	cout<<"Item Code: ";cin>>code;
	cout<<"Item  Name: ";cin>>name;
	cout<<"Item Rate: ";cin>>rate;
	cout<<"Item  Quantity: ";cin>>quantity;
};

//Displays all item attributes
void item::display_data(void){
	cout<<"Item Code: ";cout<<code;
	cout<<"	Item  Name: ";cout<<name;
	cout<<"	Item Rate: ";cout<<rate;
	cout<<"	Item  Quantity: ";cout<<quantity;
	cout<<"\n";
};


//Change rate
void item::set_rate(void){
	cout<<"Enter new rate :";
	cin>>rate;
};

//Change quantity
void item::set_quantity(float q ){
	quantity=q;
};

//Return Item Code
char* item::return_code(void){
	return code;
};

//Return Item Name
char* item::return_name(void){
	return name;
};

//Return Item Rate
float item::return_rate(void){
	return rate;
};

//Return Item Quantity
float item::return_quantity(void){
	return quantity;
};

//-----------------------------------------------------------------------------------------------------------------

//CLASS ITEMLIST
//Class attributes/functions declarations
class itemlist{
	//Private attributes
	item list[100];
	int count;
	
	//Public functions
	public:
	itemlist(){count=0;};
	int check_code(char*);
	int find_item(char*);
	void add_item(void);
	void display_list(void);
	item& return_item(int);
};

//Member function definition	

//Checks if item code is unique
int itemlist::check_code(char c[100]){
	for(int i=0;i<count;++i){
		if (strcmp(list[i].return_code(),c)==0){return 0;}
	};
	return 1;
};
//Searches for an item,returns index if found else -1	
int itemlist::find_item(char icode[100]){
	for(int i=0;i<count;++i){
		if(strcmp(list[i].return_code(),icode)==0){
			return i;
		}
	};
	return -1;
};

//Add items to list
void itemlist::add_item(void){
	item obj;
	cout<<"Enter details of the new item to be added.\n";
	obj.set_data();
	if(this->find_item(obj.return_code())==-1){
		list[count]=obj;
		count++;
	}
	else{cout<<"Duplicate Item\n";getchar();getchar();};
};

//Displays all items in list
void itemlist::display_list(void){
	for(int i=0;i<count;++i){
		cout<<"ITEM NUMBER :"<<i+1<<"\n";
		list[i].display_data();
	};
	cout<<"\n";
};

//Returns Item
item& itemlist::return_item(int i){
	return list[i];
};
//-----------------------------------------------------------------------------------------------------------------

//Class OrderLine
class orderline{
	//Private attributes
	char icode[100];
	float iquantity;

	//Public functions
	public:
	void set_orderline(void);
	float process_orderline(itemlist*);
	void display_orderline(void);
};
//Set data attributes
void orderline::set_orderline(void){
	cout<<"Enter item-code :";
	cin>>icode;
	cout<<"Enter quantity :";
	cin>>iquantity;
};

//Processes a single orderline in an order
float orderline::process_orderline(itemlist* ilist){
	if(ilist->find_item(icode)==-1){
		cout<<"Item is not sold here\n";
		return -1;
	}
	else{
		float q=(ilist->return_item(ilist->find_item(icode))).return_quantity();
		if(q<iquantity){
			cout<<"Required quantity not in stock.\n";			
			return -1;
		}
		else{
			ilist->return_item(ilist->find_item(icode)).set_quantity(q-iquantity);
			return (iquantity)*(ilist->return_item(ilist->find_item(icode)).return_rate());
		};
	};
};
	
void orderline::display_orderline(void){
	cout<<"Item :"<<icode<<"\n";
	cout<<"Quantity :"<<iquantity<<"\n";
};
	
//------------------------------------------------------------------

//Class Order
//Class attributes/functions declarations
class order{
	//Private attributes
	orderline list[100];
	int count;
	
	//Public functions
	public:
	order(){count=0;};
	void add_orderline(void);
	void display_order(void);
	void display_bill(itemlist*);
};

//Member function definition	

//Adds an orderline to the order
void order::add_orderline(void){
	orderline obj;
	obj.set_orderline();
	list[count]=obj;
	count++;
};
//Displays the order
void order::display_order(void){
	for(int i=0;i<count;++i){
		list[i].display_orderline();
	};
};

//Display Bill
void order::display_bill(itemlist* ITEMLIST){
	//ITEMLIST->display_list();
	float total=0;
	for(int i=0;i<count;++i){
		float x=list[i].process_orderline(ITEMLIST);
		if(x>=0){
			total=total+x;
		}
		list[i].display_orderline();
		cout<<"Price :"<<x<<"\n";
	};
	cout<<"TOTAL :"<<total<<"\n";
};

//------------------------------------------------------------------

//User Interface

void menu(void){
	cout<<"-------------------------------------\n";
	cout<<"Press a key to select the option :\n";
	cout<<"-------------------------------------\n";
	cout<<"(1)Add an Item to stock\n";
	cout<<"(2)Update the rate of an item\n";
	cout<<"(3)Update the quantity of an item\n";
	cout<<"(4)Place an order\n";
	cout<<"(5)Receive item\n";
	cout<<"(6)Exit\n";
};

void process_menu(int choice,itemlist* ITEMLIST){
	order ORDER;
	char c[100];
	int x;
	switch(choice){
		case 1:   clr;
			  ITEMLIST->add_item();
			  cout<<"---------------------------------------------------------------------\n";
			  ITEMLIST->display_list();
			  cout<<"---------------------------------------------------------------------\n";
			  getchar();getchar();
			  break;
		case 2:   clr;
			  ITEMLIST->display_list();
			  cout<<"Enter Item Code :";
			  cin>>c;
			  x=ITEMLIST->find_item(c);
			  if(x==-1){cout<<"Item is not sold here\n";getchar();}
			  else{ITEMLIST->return_item(x).set_rate();
			       ITEMLIST->return_item(x).display_data();
			       getchar();getchar();
			  };
			  break;
		case 3:   clr;
			  ITEMLIST->display_list();
			  cout<<"Enter Item Code :";
			  cin>>c;
			  x=ITEMLIST->find_item(c);
			  if(x==-1){cout<<"Item is not sold here\n";getchar();}
			  else{
				float q;
				cout<<"Enter new quantity :";
				cin>>q;
				ITEMLIST->return_item(x).set_quantity(q);
				getchar();getchar();
			};
			break;
		case 4:
			while(1){
				int choice;
				clr;
				cout<<"Press\n(0)To display bill\n";
				cout<<"(1)To add to your order\n";
				cin>>choice;
				if(choice==0){
					clr;
					//ITEMLIST->display_list();
					ORDER.display_bill(ITEMLIST);
					getchar();getchar();
					break;
				}
				else{
					clr;
					ITEMLIST->display_list();
					ORDER.add_orderline();
				};
			};
			break;
		case 5:
			clr;
			ITEMLIST->display_list();
			cout<<"Enter Item Code :";
			cin>>c;
			x=ITEMLIST->find_item(c);
			if(x==-1){cout<<"Item is not sold here\n";getchar();getchar();}
			else{
				float q;
				cout<<"Enter quantity being received :";
				cin>>q;
				q=q+ITEMLIST->return_item(x).return_quantity();
				ITEMLIST->return_item(x).set_quantity(q);
				getchar();getchar();
			};
			break;
	};
};

void sales_interface(void){
	int choice;
	itemlist ITEMLIST;
	while(1){
		menu();
		cin>>choice;
		if(choice==6){
			clr;
			cout<<"-------------------------------------\n";
			cout<<"\t\tTHANK YOU\n";
			cout<<"-------------------------------------\n";
			break;
		}
		process_menu(choice,&ITEMLIST);
		clr;
	};
};

//-----------------------------------------------------------------
int main(void){
	clr;
	sales_interface();
	return 0;
};
	
			
