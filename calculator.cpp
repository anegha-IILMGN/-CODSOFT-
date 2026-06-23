#include <iostream>
using namespace std;

class calculator
{
private:
    double first_number;
    double second_numer;
    char operation;
    double final_answer;

public:
    calculator()
    {
        first_number = 0;
        second_numer = 0;
        operation = '+';
        final_answer = 0;
    }

    void take_value()
    {
        cout << "enter first number: ";
        cin >> first_number;

        cout << "enter second number: ";
        cin >> second_numer;

        cout << "enter operation (+, -, *, /):";
        cin >> operation;
    }

    void calculation()
    {
        if (operation == '+')
        {
            final_answer = first_number + second_numer;
        }
        else if (operation == '-')
        {
            final_answer = first_number - second_numer;
        }
        else if (operation == '*')
        {
            final_answer = first_number * second_numer;
        }
        else if (operation == '/')
        {
            if (second_numer != 0)
            {
                final_answer = first_number / second_numer;
            }
            else
            {
                cout << "Division by zero is not allowed!" << endl;
                return;
            }
        }
        else
        {
            cout << "Invalid operation selected." << endl;
            return;
        }
    }

    void result()
    {
        cout << "\nFirst Number: " << first_number << endl;
        cout << "Second Number: " << second_numer << endl;
        cout << "Operation: " << operation << endl;
        cout << "Result: " << final_answer << endl;
    }
};

int main()
{
    calculator obj1;

    obj1.take_value();
    obj1.calculation();
    obj1.result();

    return 0;
}