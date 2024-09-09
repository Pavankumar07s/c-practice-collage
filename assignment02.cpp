#include <iostream>
using namespace std;
// Node class definition
class Node
{
public:
    char Data;
    Node *next;

    Node(char new_data)
    {
        this->Data = new_data;
        this->next = nullptr;
    }
};

// Stack class definition
class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        this->head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(char new_data)
    {
        Node *newNode = new Node(new_data);

        if (newNode == nullptr)
        {
            cout << "\nStack overflow";
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "\nStack underflow";
            return ' ';
        }
        else
        {
            Node *temp = head;
            head = head->next;
            char poppedData = temp->Data;
            delete temp;
            return poppedData;
        }
    }

    char peek()
    {
        if (isEmpty())
        {

            return ' ';
        }
        else
        {
            return head->Data;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->Data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    // stack.push(0);
    // stack.push(1);
    // stack.push(2);
    // stack.push(3);
    // stack.push(4);
    // stack.push(5);
    // stack.push(6);

    // cout << "Peek element is: " << stack.peek() <<endl;

    // int poppedElement = stack.pop();
    // cout << "Removed the Top element: " << poppedElement << endl;

    // int peekElement = stack.peek();
    // cout << "Peek element is: " << peekElement << endl;

    // cout << "Printing all elements: ";
    // stack.display();

    string infix = "a+b*c+d";
    string postfix = "";
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/')
        {
            postfix += infix[i];
        }
        else
        {
            if (stack.isEmpty())
            {
                stack.push(infix[i]);
            }
            else if (stack.peek()>infix[i])
            {
                while (!stack.isEmpty())
                {
                    char tempOperator = stack.pop();
                    postfix += tempOperator;
                }
            }

            stack.push(infix[i]);
        }
    }

    for (int i = 0; i < postfix.size(); i++)
    {
        cout << postfix[i];
    }
    return 0;
}
