// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")

class TooFewOperands{};
class UnexpectedInput{};
class TooManyItems{};


int main() 
{
    string in;
    stack<string> st;   // stack definition
    int value3 = 0;
    int value2;
    int value1;

    cin >> in;

    while(in != "q")
    {
        try{
            if(is_str_digit(in)){
                st.push(in);
            }
            else if(is_str_operator(in))
            {
                try{
                    if (st.size() < 2)
                        throw TooFewOperands();
                    value1 = stoi(st.top());
                    st.pop();
                    value2 = stoi(st.top());
                    st.pop();
                }
                catch(TooFewOperands){
                    cerr << "There are too few operands\nTerminating program\n";
                    return -1;
                }

                switch(in[0])
                {
                    case '+':
                        value3 = value2 + value1;
                        break;

                    case '-':
                        value3 = value2 - value1;
                        break;

                    case '*':
                        value3 = value2 * value1;
                        break;

                    case '/':
                        value3 = value2 / value1;
                        break;

                }

                st.push(to_string(value3));

            }
            else 
                throw UnexpectedInput();
        }
        catch(UnexpectedInput) {
            cerr << "Invalid input\nTerminating program\n";
            return -1;
        }
        cin >> in;
    }
    try{
        if (st.size() > 1)
            throw TooManyItems();
        cout << "The answer is : " << st.top() << endl;
    }
    catch (TooManyItems) {
        cerr << "There are too many items left on the stack\nTerminating program\n";
        return -1;
    }
    
    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}

bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}
