#include<iostream>
using namespace std;

class Stack
{
    public:
    virtual bool push (const int element) = 0;
    virtual bool pop(int &element) = 0;
    virtual bool top(int &element) const = 0;
};
class ArrayStack: public Stack
{
    private:
    int *data;
    int topIndex;
    int size;
    public:
    ArrayStack (int size);
    virtual bool push(const int element);
    virtual bool pop(int &element);
    virtual bool top(int &element) const;
};

ArrayStack::ArrayStack(int size)
: size(size), topIndex(-1), data(new int[size]){}
bool ArrayStack::push(const int element)
{
    if (topIndex < size - 1)
    {
        topIndex++;
        data[topIndex] = element;
        return true;

    }
    else
    {
        return false;
    }
}

bool ArrayStack::top(int &element) const { if (topIndex < 0)
{
    return false;
}
else
{
    element = data[topIndex];
    return true;
}
}
bool ArrayStack::pop(int &element) { if (top (element))
{
    topIndex--;
    return true;
}
else
{
    return false;
}
}

int main()
{
    Stack *s = new ArrayStack(10);
    s-> push(10);
    s->push(9);
    int element;
    s->top(element);
    cout << "Top element is " <<element << "\n";
    s->pop(element);
    cout << "popped element is " << element << '\n';
}