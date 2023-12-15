#include <iostream>
#include <stack>
#include <string>

bool Check(std::string st1, std::stack<std::string>& s)
{
    for (int i = 0; i < st1.length();i++)
    {
        if (st1[i] == '(' || st1[i] == '{' || st1[i] == '[')
        {
            std::string temp;
               temp += st1[i];
            s.push(temp);
        }
        else if (st1[i] == ')' || st1[i] == '}' || st1[i] == ']')
        {
            std::string temp1;
            if (st1[i] == ')')
            {
                if (s.empty())
                {
                    return false;
                }
                temp1 += s.top();
                if (temp1 != "(")
                {
                    return false;
                } 
                temp1 = "";
                s.pop();
            }
            else if (st1[i] == ']')
            {
                if (s.empty())
                {
                    return false;
                }
                temp1 += s.top();
                if (temp1 != "[")
                {
                    return false;
                }
                temp1 = "";
                s.pop();

            }
            else if (st1[i] == '}')
            {
                if (s.empty())
                {
                    return false;
                }
                temp1 += s.top();
                if (temp1 != "{")
                {
                    return false;
                }
                temp1 = "";
                s.pop();

            }


        }

    }
    return s.empty();

}

int main()
{
    std::string st;
    std::cout << "Enter the expression to check the balance brackets!\n";
    std::getline(std::cin, st);
    int length = st.length();
    std::stack<std::string> s1;
    if (Check(st, s1))
    {
        std::cout << "Brackets are balanced";
    }
    else
        std::cout << "not balanced";

}
