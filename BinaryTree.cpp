#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
#include "binaryTree.h"

using namespace std;

int main()
{
	int x;	//first number to read to form binary tree
	char ch;
	int totalSum = 0;
	string filename;
	ifstream infile;
	bool check = true;
	bool tof;
	myStack<int> A;
	while (check)
	{
		cout << "Enter file name: ";
		cin >> filename;
		infile.open(filename);
		if (infile)
		{
			check = false;
		}
	}
	cout << endl;
	infile >> totalSum; //this is the target sum we need
	infile >> ch;		//this is the first paranthesis

	while (infile && infile.peek() != EOF)
	{
		binTreeNode<int>* root;
		if (infile.peek() == ')')
		{
			cout << "No such path exists, LISP is a pain anyway" << endl;
			cout << endl;
		}
		else {
			infile >> x;		//this is the root number
			/*cout << "TOTALSUM: " << totalSum << endl;
			cout << "Paranthesis: " << ch << endl;
			cout << "First num: " << x << endl;*/
			root = new binTreeNode<int>;
			root->item = x;	//make root the first item in the binary tree
			readLISP(root, infile);		//pass in root and file
			tof = evaluate(root, 0, totalSum, A);
			destroyTree(root);
			if (A.isEmpty())
			{
				cout << "No such path exists, LISP is a pain anyway" << endl;
				cout << endl;
			}
			else
			{
				while (!A.isEmpty())
				{
					cout << A.top();
					A.pop();
					if (!A.isEmpty())
					{
						cout << " + ";
					}
				}
				cout << " = " << totalSum << endl;
				cout << endl;
			}		
		}
		infile >> totalSum; //this is the target sum we need
		infile >> ch;		//this is the first paranthesis
		if (infile.eof())	//if eof has been detected, exit the program
		{
			infile.close();
			return 0;
		}
	}
	return 0;
}

