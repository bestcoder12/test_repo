#include <iostream>
#include <string>

using namespace std;

#define QUIT_VAL "#q"

// Program to show the usage of constructor and destructors

/* 
 * Program to specify the specifications of a football
 * and order them as per requirement.
 * This is done by storing the items in a singly link list
 * each new thing is explained as they occur in the program.
 */

// Enumeration data type of name color which creates a mapping of symbols to 
// integer values starting from top,
// for example WHITE will have a value of 0, RED will have a value of 1
// and so on.

enum color
{
	WHITE,
	RED,
	BLUE,
	YELLOW,
	BROWN,
	BLACK,
	GREEN
};

// Another enumeration data type of the name comp for companies.

enum comp
{
	ADIDAS,
	NIKE,
	PUMA
};

class Football
{
private:
	int size;
	color b_col;
	comp b_comp;
	int quant;
public:
	int set_Vals(int sz, string col, string comp, int qnt)
	{	
		if (sz < 0 || sz > 5)
		{
			cout << "Wrong size entered!" << endl;
			return -1;
		}
		size = sz;
		if (col.compare("White") == 0)  { b_col = WHITE;}
		if (col.compare("Red") == 0)    { b_col = RED;}
		if (col.compare("Blue")== 0)    { b_col = BLUE;}
		if (col.compare( "Yellow") == 0){ b_col = YELLOW;}
		if (col.compare( "Brown") == 0) { b_col = BROWN;}
		if (col.compare( "Black") == 0) { b_col = BLACK;}
		if (col.compare( "Green") == 0) { b_col = GREEN;}
		if (b_col > 6 || b_col < 0) {cout << "Wrong color entered!" << endl; return -1;} 
		if (comp.compare("Adidas") == 0) {b_comp = ADIDAS;}
		if (comp.compare("Nike") == 0) {b_comp = NIKE;  }
		if (comp.compare( "Puma") == 0) {b_comp = PUMA;  }
		if (b_comp > 2 || b_comp < 0) {cout << "Wrong company entered!" << endl; return -1;}
		if (qnt < 0)
		{
			cout << "Wrong quantity entered!" << endl;
			return -1;
		}
		quant = qnt;
		return 0;
	}
	void disp_Val()
	{
		cout << "Size: " << size << endl;
		switch (b_col)
		{
			case 0: { cout << "Color: " << "White" << endl; break; }
			case 1: { cout << "Color: " << "Red" << endl; break; }
			case 2: { cout << "Color: " << "Blue" << endl; break; }
			case 3: { cout << "Color: " << "Yellow" << endl; break; }
			case 4: { cout << "Color: " << "Brown" << endl; break; }
			case 5: { cout << "Color: " << "Black" << endl; break; }
			case 6: { cout << "Color: " << "Green" << endl; break; }
		}
		switch (b_comp)
		{
			case 0: { cout << "Company: " << "Adidas" << endl; break; }
			case 1: { cout << "Company: " << "Nike" << endl; break; }
			case 2: { cout << "Company: " << "Puma" << endl; break; }
		}
		cout << "Quantity: " << quant;	
	}		
};

class Order
{
private:
	class Node
	{
		public:
			Football item;
			Node * link;	
	};
	Node * start;
public:
	Order()
	{
		start = NULL;
	}
	void ins_n(Football t_ball)
	{
		if (start == NULL)
		{
			Node * new_node = new Node;
			new_node->item = t_ball;
			new_node->link = NULL;
			start = new_node;
			return;
		}
		Node * temp = start;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		Node * new_node = new Node;
		new_node->item = t_ball;
		new_node->link = NULL;
		temp->link = new_node;
	}
	void del_n(void)
	{
		Node * temp = start;
		while (temp->link->link != NULL)
		{
			temp = temp->link;
		}
		Node * temp2 = temp->link;
		temp->link = NULL;
		delete temp2;
	}
	void disp_list(void)
	{
		Node * temp = start;
		cout << endl;
		cout << "The items entered till now:" << endl;
		int cnt = 1;
		while (temp != NULL)
		{
			cout << endl;
			cout << "Item no. " << cnt << endl;
			cout << "----------------" << endl;
			(temp->item).disp_Val();
			cout << endl;
			cnt++;
			temp = temp->link;
		}
		cout << endl;	
	}
	~Order()
	{
		Node * temp = start;
		Node * ptr = temp;
		while (ptr != NULL)
		{
			temp = ptr->link;
			delete ptr;
			ptr = temp;
		}
		cout << "Your order is being processed." << endl;
	}
};

int main(void)
{
	cout << "\n\t\t\t\tOrdering System for Footballs!\n\n" << endl;
	cout << "To end or stop the order press #q anywhere required.\n" << endl;
	cout << "Enter the specifications of the footballs:" << endl;
	cout << "\tSizes available: 1 to 5" << endl;
	cout << "\tColors available: White, Red, Blue, Yellow, Brown, Black, Green" <<endl;
	cout << "\tCompanies available: Adidas, Nike, Puma" << endl;
	cout << "\tQuantity available: Any number you can imagine less than infinity for each item. :p\n" << endl;
	cout << " --------------------------------------------------------------------------------------------------\n" << endl;
	Order o1;
	string inpt;
	int t_sz = 0;
	string t_color;
	string t_company;
	int t_quant = 0;
	for (;;)
	{
		cout << "Size: ";
		getline(cin,inpt);
		if (inpt.compare(QUIT_VAL) == 0)
		{
			break;
		}
		t_sz = stoi(inpt);
		cout << "Color: ";
		getline(cin,inpt);
		if (inpt.compare(QUIT_VAL) == 0)
		{
			break;
		}
		t_color = inpt;
		cout << "Company: ";
		getline(cin,inpt);
		if (inpt.compare(QUIT_VAL) == 0)
		{
			break;
		}
		t_company = inpt;
		cout << "Quantity: ";
		getline(cin,inpt);
		if (inpt.compare(QUIT_VAL) == 0)
		{
			break;
		}
		t_quant = stoi(inpt);
		cout << endl;
		Football temp_ball;
		if ( temp_ball.set_Vals(t_sz,t_color,t_company,t_quant) < 0)
		{
			cout << endl;
			continue;
		}
		o1.ins_n(temp_ball);
	}
	o1.disp_list();
	return 0;
}
