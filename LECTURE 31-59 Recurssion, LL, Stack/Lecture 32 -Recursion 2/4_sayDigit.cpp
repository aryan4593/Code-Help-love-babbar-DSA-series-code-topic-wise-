#include <iostream>
#include <string>
using namespace std;
    string Spelling[10] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};

void getNum (int n){
    if(n/10==0){ 
        cout<<Spelling[n]<<" "; 
        return ;
    }
    getNum(n/10);
    cout<<Spelling[n%10]<<" ";
    


}
int main()
{
    cout << "enter number " << endl;
    int n;
    
    cin >> n;
    getNum(n);

    return 0;
}