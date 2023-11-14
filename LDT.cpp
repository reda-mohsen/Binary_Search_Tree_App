#include <iostream>
using namespace std;

#include "LDT.h"

int main(int argc, const char * argv[]) 
{

	// Testing Constructor and empty()
	LDT<int> intLDT;            // test the class constructor
	cout << "Constructing empty LDT\n";
	cout << "LDT " << (intLDT.empty() ? "is" : "is not") << " empty\n";

	// Testing inorder
	cout << "Inorder Traversal of LDT: \n";
	intLDT.breadth_first_traversal(cout);

	//Testing erase
	int er;
	for (;;)
	{
		cout << "enter an element to tag as erased (-999 to stop): ";
		cin >> er;
		if (er == -999) break;
		intLDT.erase(er);
	}
	cout << "Inorder Traversal of LDT: \n";
	intLDT.breadth_first_traversal(cout);
	cout << endl;

	// Testing insert
	cout << "\nNow insert a bunch of integers into the LDT."
		"\nTry items not in the LDT and some that are in it:\n";
	int number;
	for (;;)
	{
		cout << "Item to insert (-999 to stop): ";
		cin >> number;
		if (number == -999) break;
		intLDT.insert(number);
	}


	cout << "LDT " << (intLDT.empty() ? "is" : "is not") << " empty\n";
	cout << "Inorder Traversal of LDT: \n";
	intLDT.breadth_first_traversal(cout);
	cout << endl;

	// Testing Size
	cout << "Size of tree is " << intLDT.size();
	cout << endl;

	// Testing height
	cout << "Height of tree is " << intLDT.height();
	cout << endl;


	//// Testing member
	//int mem;
	//cout << "enter an element to check if it is a member in the tree" << endl;
	//cin >> mem;
	//cout << intLDT.member(mem) << endl;

	//Testing erase

	for (;;)
	{
		cout << "enter an element to tag as erased (-999 to stop): ";
		cin >> er;
		if (er == -999) break;
		intLDT.erase(er);
	}
	cout << "Inorder Traversal of LDT: \n";
	intLDT.breadth_first_traversal(cout);
	cout << endl;

	// Testing insert
	cout << "\nNow insert a bunch of integers into the LDT."
		"\nTry items not in the LDT and some that are in it:\n";

	for (;;)
	{
		cout << "Item to insert (-999 to stop): ";
		cin >> number;
		if (number == -999) break;
		intLDT.insert(number);
	}
	cout << "Inorder Traversal of LDT: \n";
	intLDT.breadth_first_traversal(cout);
	cout << endl; 


		////Testing clear
		//cout << "Deleting all nodes of the tree" << endl;
		//intLDT.clear();
		//cout << "Inorder Traversal of LDT: \n";
		//intLDT.breadth_first_traversal(cout);
		//cout << endl;
		//cout << "LDT " << (intLDT.empty() ? "is" : "is not") << " empty\n";
		//cout << endl;
};
