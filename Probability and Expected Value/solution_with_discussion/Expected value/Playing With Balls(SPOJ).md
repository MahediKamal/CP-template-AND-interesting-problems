# Playing With Balls[***Problem Link***](https://www.spoj.com/problems/IITKWPCN/)

## problem simplified:
There are `W` white balls and `B` black balls in a bag. </br>

In each step, a magician randomly removes any two balls from the bag. If the drawn balls are of the same color, he will put one white ball in the bag, otherwise he will put a black ball in it. The two drawn balls from the bag from the ball are discarded. </br>

you have to determine the probability that the color of last ball remaining in the bag is black. </br>
</br> </br>
### 3 possible outcomes are: </br>
![...](../../../images/Playing%20With%20Balls.PNG) 

## observations
- From the picture we can easily see that at a time two black ball is removed. We can't move `1` balck ball
- So, if `number of black ball is even` then it will be impossible that last ball remaining is black
- Similarly, if  `number of black ball is odd` then it will be impossible that last ball remaining is white. Beacase the last black ball can't be removed.
    
 



## **Solution Code(C++)**

```C++

    #include <iostream>
    using namespace std;
    #define lli long long int

    int main() {
        lli t; cin>>t;
        while(t--){
            lli w, b; cin>>w>>b;
            if(b % 2 == 0){
                cout<<"0.000000"<<endl;
            }else cout<<"1.000000"<<endl;
        }
    }
    
```
