/*
#include<iostream>  --> this is pre processor directive
#define  -- you can create macros using this

what is macro - a piece of code of program replaced by macro
*/

#include<iostream>
#define pi 3.14    //this is not a varibable this is macro when you compile program, 'pi' will be repleced by 3.14 and 
                    // it won't take any variable unlike variables
using namespace std;

int main (){
    int r=4;
    // pi =pi+1; // macro can't be modified
    double Area = pi*r*r;
    cout<<"Area is "<<Area<<endl;
}

/*
types of macros 

1. object like macro
            #define pi 3.14

2.chain macro
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

3.Multiline macro

4. function like macro
#define min(a, b) (((a) < (b)) ? (a) : (b))

Q4. Can macros be recursive?
Answer:

No, macros cannot be recursive. If a macro becomes recursive then definition refers to itself, and it will lead to an infinite loop during preprocessing.
*/