//I <tyler> have not used any code other than my own(or that in the textbook) for this project.I also have not used any function or data - structure from the Standard - Template Library.I understand that any violation of this disclaimer will result in a 0 for the project.


#include <fstream>
#include <string>
#include <cassert>
#include <cctype>
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	//1.The program must #include <fstream.h>.
	//2. The program needs to declare an ifstream variable that will "attach" to the input file.The data type of this variable is ifstream.For example,
	//you could make the declaration of an ifstream variable called input, as shown here :
	ifstream input; // Will be attached to the input file
	//3. The ifstream must be attached to the input file by activating the open function.The argument to the open function is an ordinary C string constant or string variable.
	//For example, if input is an ifstream, then we can attach input to a file named foo with the function call :
	input.open("tests.txt");
	//The argument to the open function can also be a string variable-- i.e., an array of characters with the last character followed by the null character '\0'.
	//4. You must check that the file was successfully opened.This check can be made by activating the fail function.This function returns a true / false value to indicate whether the ifstream has failed to properly attach to the input file(true indicates failure).I'd suggest something like this:
	if (input.fail())
	{
		cout << "Could not open input file." << endl;
		exit(0);
	}
	string infex;
	//10. Once the ifstream input has been successfully opened, you may use the name input in the same way that you use other input devices(such as cin).
	//For example, suppose that the next item in the input file is an integer, and i is an integer variable.Then you may execute the statement :
	//input >> infex
	//All the other familiar input functions(such as peek and ignore) can be used with the ifstream, in the same way that you have previously used these function with cin.
	//11. Eventually you will read the end of the input file.At the end of the file there is usually a special character called EOF(which is not actually part of the data of the file).
	//You can also use the name of the ifstream(such as input in our example) as a boolean expression which is true so long as the file has not contained any bad input
	//(such as an alphabetic character when a digit is expected).Thus, the complete boolean expression to test whether there is more input reads like this:

	//12. When you are done reading from the input file, then you should activate the close function, as shown here for our example :
	while (input && input.peek() != EOF)
	{
		input >> infex;
		//initialize a stack of characters to hold the operation symbols and parentheses

		stack<char> s;
		for (char& c : infex)
		{
			if (c == '(')
				//read the left parenthesis and push it onto the stack
			{
				s.push(c);
			}
			else if (isdigit(c))
			{
				//read the operand and write it to the output
				cout << c;
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				// the stack isnt empty 
				// && the next symbol on the stack isn't a left parenthesis 
				// && the next symbol on the stack isn't an operation with lower precedence than the next input symbol)
				while ((!s.empty()) && (s.top() != '(') && (s.top() != '+' && s.top() != '-'))
				{
					//print the top operation and pop it
					cout << s.top();
					s.pop();
				}
				s.push(c);
			}
			else
			{
				while (s.top() != '(' && !s.empty())
				{
					//read and discard the next input symbol
					cout << s.top();
					s.pop();
					/*read and discard the next input symbol which should be a ")"
					print the top operation and pop it, keep printing and popping until the next symbol on the stack is a "("
					if no perenthesis is encountered, then print an error message indicating unbalanced perenthesis, and halt
					finnaly pop the left parenthsis*/
				}
				s.pop();
			}
		}
		while (!s.empty())
		{
			//print and pop any remaining operations on the stack
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
	input.close();
	system("pause");
}