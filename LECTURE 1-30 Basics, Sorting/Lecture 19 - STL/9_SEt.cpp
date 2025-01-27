#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(7);

    cout << "size : " << s.size() << endl;
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for (int i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "is 5 present? " << s.count(5) << endl;
    cout << "is 9 present? " << s.count(9) << endl;

    set<int>::iterator itr = s.find(5);
    cout << "value present at itr--> " << *itr << endl;

    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}