
#include <iostream>
#include <functional>
#include <vector>


using namespace std;

void Do_work(int a)
{
    cout << "\n" << a << endl;
}

int main()
{
    vector<int> a;
    
        a.push_back(2);
        a.push_back(4);
        a.push_back(1);
        a.push_back(7);
        a.push_back(1);
        a.push_back(7);
   
        cout << "\n\nBefore sorting\n" << endl;
    for (int i = 0; i < a.size(); i++)// виводимо до сортування
    {
        cout << a.data()[i] << ' ';
    }

    function<void(vector<int>&a)> f = [](vector<int>&a)// сортування
    {
            for (int i = 0; i < a.size(); i++)
            {
                for (int i = 0; i < a.size() - 1; i++)
                {
                    if (a.data()[i] > a.data()[i + 1])
                    {
                        swap(a.data()[i], a.data()[i + 1]);
                    }
                }
            }
    };
    
    f(a);
    cout << "\n\nAfter sorting\n"<<endl;
    for (int i = 0; i < a.size(); i++)// виводимо до сортування
    {
        cout << a.data()[i] << ' ';
    }
    

    cout << "\n\n----------------Part - 2------------------------\n" << endl;

    int p = 0;
    cout <<"\nP before: " << p << endl;

    function<void(int)> l = [&p](int a)
        {
            p = a;
        };
   
    l(2);
    
    cout << "\nP after: " << p << endl;
    

    cout << "\n\n----------------Part - 3------------------------\n" << endl;
    vector<int> k;
    k.push_back(1);
    k.push_back(2);
    k.push_back(3);
    k.push_back(4);
    k.push_back(5);

    int num;
    bool controller = true;
    while (controller)
    {
        cout << "\nEnter 1 to add sum number to every element\nEnter 2  to myltiply\nEnter 0 to leave:\nEnter 3 to show data:";
        cout << "\nEnter the number to launch the operation you want: ";
        cin >> num;

        if (num == 0)
        {
            controller = false;
            
        }
        else if (num == 1)
        {
            int number;
            cout << "\nEnter the number you want to add";
            cin >> number;

            function<void(vector<int>& k)> s = [&number](vector<int>& k)
                {
                    for (int i = 0; i < k.size(); i++)
                    {
                        k.data()[i] += number;
                    }
                };

            s(k);
            
        }

        else if (num == 2)
        {
            int number;
            cout << "\nEnter the number you want to myltiply: ";
            cin >> number;

            function<void(vector<int>& k)> s = [&number](vector<int>& k)
                {
                    for (int i = 0; i < k.size(); i++)
                    {
                        k.data()[i] *= number;
                    }
                };

            s(k);
           
        }
        else if (num == 3)
        {
            function<void(vector<int>& k)> s = [](vector<int>& k)
                {
                    for (int i = 0; i < k.size(); i++)
                    {
                        cout << k.data()[i] << ' ';
                    }
                };
            cout << "\n--------------"<<endl;
            s(k);
            cout << "\n--------------" << endl;
            
        }
    }

}


