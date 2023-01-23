#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void
getData (ifstream & inFile, string & romanOne, string & romanTwo, char &oper)
{
  inFile >> romanOne >> romanTwo >> oper;
}

string
convertToRoman (int number)
{
  string roman = "";
  while (number > 0)
    {
      if (number >= 100)	// Change "else if" to "if"
	{
	  roman += "C";
	  number -= 100;
	}
      else if (number >= 50)
	{
	  roman += "L";
	  number -= 50;
	}
      else if (number >= 10)
	{
	  roman += "X";
	  number -= 10;
	}
      else if (number >= 5)
	{
	  roman += "V";
	  number -= 5;
	}
      else
	{
	  roman += "I";
	  number -= 1;
	}
    }
  return roman;
}

int
convertToDecimal (string roman)
{
  int number = 0;

  for (int i = 0; i < roman.length (); i++)
    {
      switch (roman[i])
	{
	case 'C':
	  number += 100;
	  break;
	case 'L':
	  number += 50;
	  break;
	case 'X':
	  number += 10;
	  break;
	case 'V':
	  number += 5;
	  break;
	case 'I':
	  number += 1;
	  break;
	}
    }
  return number;
}

int
main ()
{
    string input1, input2, operation;
    cout << "Welcome to Roman Calculator!" << endl;
    while (true) {
        cout << "Enter first number (or 'EXIT' to EXIT): ";
        cin >> input1;
        if (input1 == "EXIT") {
            break;
        }
        while(convertToDecimal(input1) == 0) {
            cout<<"This numeral is incorrect, please enter again: ";
            cin >> input1;
        }
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == "EXIT") {
            break;
        }
        cout << "Enter second number: ";
        cin >> input2;
        if (input2 == "EXIT") {
            break;
        }
        while(convertToDecimal(input2) == 0) {
            cout<<"This numeral is incorrect, please enter again: ";
            cin >> input2;
        }
        int number1 =convertToDecimal(input1);
        int number2 = convertToDecimal(input2);
        if (number1 > 100 || number2 > 100) {
            cout << "Error: Only numbers up to 100 are allowed." << endl;
            continue;
        }
        int result;
        if (operation == "+") {
            result = number1 + number2;
        } else if (operation == "-") {
            result = number1 - number2;
        } else if (operation == "*") {
            result = number1 * number2;
        } else if (operation == "/") {
            result = number1 / number2;
        } else {
            cout << "Error: Invalid operation." << endl;
            continue;
        }
        cout << "Result: " << convertToRoman(result) << endl;
    }
}

