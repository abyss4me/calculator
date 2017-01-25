#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <limits>


using namespace std;

template <class T> class Stack
{
    public:
    int s_size;
    struct Node {
        T data;
        Node *next;
    };
    Node *last, *buf, *prev;
    bool first;
    Stack() { last = NULL; s_size = 0; buf = NULL; first = true; } /* init cinstructor */
    ~Stack() { delete last; }
    void push( T t )
    {
            Node *p = new Node; /* creating new node */
            p->data = t;
            if ( first )        /* if node in stack is first I just terminate it's 'next' pointer by NULL and drop flag */
            {
                buf = p;
                last = p;
                first = false; /* create first node - flag */
            }
            else {
                p->next = buf;
                buf = p;
                last = p;
            }
            if ( s_size == 0 )
              last->next = NULL;
            s_size++;
    }
    void pop()
    {
            prev = last->next;
            delete last;
            last = prev;
            buf = last;
            s_size--;
    }
    T top()
    {
            return last->data;
    }
    int stack_size()
    {
        return s_size;
    }
};
int count_of_par = 0;
void ReadString(int c, char*argv[])
{
Stack<char*>st;
count_of_par = c;
int n = 1;
float a=0, b=0;
float f, s;
char str[50];
    while ( n != count_of_par )
    {

        if ( *argv[n] == '+' )
        {
            a = atof(st.top());
            st.pop();
            b = atof(st.top());
            st.pop();
            s = a + b;
            snprintf(str, sizeof(str),"%f",s);
            st.push(str);
        }
        else if ( *argv[n] == '-' )
        {
            a = atof(st.top());
            st.pop();
            b = atof(st.top());
            st.pop();
            s = b - a;
            snprintf(str, sizeof(str),"%f",s);
            st.push(str);
        }
        else if ( *argv[n] == '*' )
        {
            //cout<<"*"<<endl;
            a = atof(st.top());
            st.pop();
            b = atof(st.top());
            st.pop();
            s = (float)a * b;

            snprintf(str, sizeof(str),"%f",s);
            st.push(str);
            }
        else if ( *argv[n] == '/' )
        {
            //cout<<"*"<<endl;
            a = atof(st.top());
            st.pop();
            b = atof(st.top());
            st.pop();
            f = (float)b / a;
//char *s = (char*)&f;
            snprintf(str, sizeof(str),"%f",f);

           // cout<<str<<endl;
            st.push(str);
            }
            else
                {st.push(argv[n]);
        }
        n++;
    }
   // printf()
    printf("    %3.4f\n",atof(st.top()));

}

int main(int argc, char*argv[]) /* main programm*/
{

ReadString(argc,argv);
  // system("PAUSE"); /*sys delay*/
   return 0;
}
