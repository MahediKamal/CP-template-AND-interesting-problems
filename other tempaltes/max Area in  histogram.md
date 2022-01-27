## maxAreaHistogram Algorithm

- The function needs gets a vector of integer
- vector represents the height(`y`) of the histogram for different vale of `x` in a sequencial order
- Function will retirn the max possible rectanglar area in the histogram.
- The time complexity of this algorithm is  `O(n)`.


```C++

int maxAreaHistogram(vector<int>v){
    stack<int> s;
    int tp, res = 0, i = 0;

    while (i < v.size()){
        
        if (s.empty() || v[s.top()] <= v[i]) s.push(i++);
        else{
            tp = s.top(); 
            s.pop(); 

            res = max(res, v[tp] * (s.empty() ? i : i - s.top() - 1));
        }
    }
 
   
    while (s.empty() == false){
        tp = s.top();
        s.pop();
        res = max(res, v[tp] * (s.empty() ? i : i - s.top() - 1));
    }
 
    return res;
}

```
