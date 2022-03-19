
#include<iostream>
#include<stdlib.h>//for system("CLS");
#include<string>//for getline for string;
using namespace std;

class node
{
public:
	string question;
	string sagot;
	node* next_ptr;
};
string questionArr[15] = { "Which of the following cannot be a member of a structure\n",
"Nodes in a linked list are composed of two things, __ and __.\n",
"Which of the following statements are TRUE about overloaded functions?",
"Which of the following is TRUE about arrays? Refer to the following code segment:",
"int arr[4][7];",
"What happens when passing by reference is done to a variable when calling a function?",
"int x;",
"struct Profile{",
"Given the following C++ structs, how would you set the value of the id in the Union struct to 501?",
"Which of the following statements is true about C++ structs?",
"What happens when ofstream myfile.open",
"What would happen if a program tries to read a file which it cannot open?",
"A linked list has a pointer that stores the first node of the list. The pointer is called ___.",
"When passing a two-dimensional array as a parameter to another function, you must declare the row and column size of the two-dimensional array in the function declaration",
"It is possible for recursive functions to enter infinite recursion without control structures" };

string sagotArr[15] = { "function","Data and pointer","They are functions with the same name but with different data types",
"secondArray[0]==firstArray[0]", "no. 5 no data xD","no. 6 no data xd", "20 - memory address of y","missing semi colon","no. 9 no data xD",
"no.10 no data xD","no. 11 no data xd, no.12 no data xD", "head","false","true" };

bool isEmpty(node* head);
void assignQuestionToSagot(node*& head, node*& last,string question, string sagot);
void hanapSagot(node* current);

int main()
{
	node* head = NULL;
	node* last = NULL;
	string question;
	string sagot;
	string choice = "nope";
	cout << "hello mga kopyarul\n";
	assignQuestionToSagot(head,last,question,sagot);
	cout << head->question;
	do
	{
		
		cout << "just copy paste the first line of the question\n";
		hanapSagot(head);

		cout << "type 'fuck you' when you want to exit this shit\n";
		cout << "nope if not\n";
		choice = "fuck you";
		cin.ignore();
		getline(cin, choice);
	} while (choice != "fuck you");

}



bool isEmpty(node* head)//checks if the linkedlist is empty
{
	if (head == NULL)
	{
		return true;
	}
	else
		return false;
}

void assignQuestionToSagot(node*&head, node*& last,string question, string sagot)
{
	int i = 0;
	do
	{
		if (isEmpty(head))
		{
			node* temp = new node;

			temp->question = questionArr[i];
			temp->sagot = sagotArr[i];
			temp->next_ptr = NULL;

			head = temp;
			last = temp;
		}
		else
		{
			node* temp = new node;

			temp->question = questionArr[i];
			temp->sagot = sagotArr[i];
			temp->next_ptr = NULL;
			last->next_ptr = temp;
			last = temp;
		}
		i++;
	} while (i<15);

}


void hanapSagot(node* current)
{
	string tanongfind;
	getline(cin, tanongfind);
	bool questionMatch = false;
	cout << "searching for " << tanongfind << "..." << endl << endl;
	cout << current->sagot;
	while (current != NULL)
	{
		if (tanongfind == current->question)
		{
			cout << "sagot found\n";
			cout << current->sagot << endl;
			current = current->next_ptr;
			questionMatch = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (questionMatch == false)
				{
					cout << "wale pre " << tanongfind << endl;
				}
			}
		}
	}
}
