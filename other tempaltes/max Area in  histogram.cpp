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
