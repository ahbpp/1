//
//  main.cpp
//  A
//
//  Created by Alexey Karpov on 25.11.16.
//  Copyright © 2016 Alexey Karpov. All rights reserved.
//

#include <iostream>

using namespace std;

struct snode
{
    int info;
    snode *prev;
};
struct stack
{
    snode *top;
};

void create (stack *node);
void push (int a, stack *node);
bool emptyornot (stack *node);
void pop (stack *node);
void back (stack *node);
void min (stack *node);
void size (stack *node);
void clear (stack *node);

int main() {
    int n;
    cin >> n;
    stack *a;
    create(a);
    int *c = new int[n];
    for (int i = 0; i < n; i++)
    {
        char *command = new char [6];
        cin >> command;
        if (*command == 'p' && *(command + 1) == 'u')
        {
            cin >> c[i];
            c[i] = c[i] * 10 + 1;
        } else {
            if (*command == 'p' && *(command + 1) == 'o')
            {
                c[i] = 2;
            } else {
                if (*command == 'b')
                {
                    c[i] = 3;
                } else {
                    if (*command == 'm')
                    {
                        c[i] = 4;
                    } else {
                        if (*command == 's')
                        {
                            c[i] = 5;
                        } else {
                            c[i] = 6;
                        }
                    }
                }
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        switch (c[i] % 10) {
            case 1:
                push(c[i] / 10, a);
                break;
            case 2:
                pop(a);
                break;
            case 3:
                back(a);
                break;
            case 4:
                min (a);
                break;
            case 5:
                size(a);
                break;
            case 6:
                clear(a);
                break;
        }
    }
    if (emptyornot(a) == false)
    {
        do
        {
            snode *t = a -> top;
            a -> top = a -> top -> prev;
            delete t;
        }
        while (a -> top != NULL);
    }
    delete [] c;
    return 0;
}
void create (stack *node)
{
    node -> top = NULL;
}
void push (int a, stack *node)
{
    snode *t = new snode;
    t -> info = a;
    t -> prev = node -> top;
    node -> top = t;
    cout << "ok" << endl;
}
bool emptyornot (stack *node)
{
    return node -> top == NULL;
}
void pop (stack *node)
{
    if (emptyornot(node))
    {
        cout << "error" << endl;
    } else {
        cout << node -> top -> info << endl;
        snode *t = node -> top;
        node -> top = node -> top -> prev;
        delete t;
    }
}
void back (stack *node)
{
    if (emptyornot(node))
    {
        cout << "error" << endl;
    } else {
        cout << node -> top -> info << endl;
    }
}
void min (stack *node)
{
    if (emptyornot(node))
    {
        cout << "error" << endl;
    } else {
        snode *min = node -> top;
        snode *t = node -> top -> prev;
        do
        {
            if (t -> info < min -> info)
                min = t;
            t = t -> prev;
        }
        while (t != NULL);
        cout << min -> info << endl;
    }
}
void size (stack *node)
{
    if (emptyornot(node))
    {
        cout << 0 << endl;
    } else {
        int k = 0;
        snode *t = node -> top;
        do
        {
            k++;
            t = t -> prev;
        }
        while (t != NULL);
        cout << k << endl;
    }
}
void clear (stack *node)
{
    do
    {
        snode *t = node -> top;
        node -> top = node -> top -> prev;
        delete t;
    }
    while (node -> top != NULL);
    cout << "ok" << endl;
}