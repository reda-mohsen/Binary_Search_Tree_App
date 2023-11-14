
#include <iostream>
using namespace std;

#include "LDT.h"

int main(int argc, const char * argv[]) {
	// Testing Constructor and empty()
	LDT<int> intLDT;            // test the class constructor
	cout << "Constructing empty LDT\n";
	cout << "LDT " << (intLDT.empty() ? "is" : "is not") << " empty\n";

	// Testing inorder
	cout << "Inorder Traversal of LDT: \n";
	intLDT.inorder(cout);

	// Testing insert
	cout << "\nNow insert a bunch of integers into the LDT."
		"\nTry items not in the LDT and some that are in it:\n";
	int number;
	for (;;)
	{
		cout << "Item to insert (-999 to stop): ";
		cin >> number;
		if (number == -999) break;
		intLDT.insertx(number);
	}


	cout << "LDT " << (intLDT.empty() ? "is" : "is not") << " empty\n";
	cout << "Inorder Traversal of LDT: \n";
	intLDT.inorder(cout);

	cout << endl;

	cout<< "Height of tree is " <<intLDT.height();
	cout << endl;
}
