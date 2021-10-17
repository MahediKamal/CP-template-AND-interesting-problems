# 10368 - Euclid's Game [***Problem Link***](https://onlinejudge.org/external/103/10368.pdf)

## problem simplified:
Given two initial numbers. two player subtract from the large number in turns. if two numbers are a, b and a > b; then subtraction process is a = a - n\*b (where n is an integer such that n\*b < a)


## Solution Idea
- if two numbers always satisfy the condition that `max(a,b) / min(a,b) < 2` then none of the player will be able to control the game. So number of turns is fixed, if number of turns is odd then `Stan wins` else `Ollie wins`.for example: `(3,5) -> (3,2) -> (1,2) -> (1,0)`. In case like this, number of turns is 3, so Stan wins.

- Any player who gets an opportunity to controll the game first will win. For example, let at a position a player get to number (2,7); so from (2,7) he can go to (2,5), (2,3) or (2,1). But if we go to (2,3) then the next must go to (2,1) or he himself can go to (2,1), so a player can controll the game once he player gets the opportunity to give multiple choices and can win the game. 



## **Solution Code(C++)**

```C++

#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(true){
        cin>>a>>b;
        if((a == 0 && b == 0)) break;
        int turns = 0;
        while(a>0 && b>0){
            if(a < b) swap(a, b);
            int d = a / b;
            if(d > 1 || a%b == 0) break;
            
            a -= (d * b);
            
            turns++;
        }
        if(turns % 2 == 0){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }
    }
}

```
