vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    
    vector<int> ans;

    int i ;

    // int h = INT_MIN;

    priority_queue<pair<int,int>>q; 
    // pi p;

    for(i=0;i<B-1; i++){
        q.push(make_pair(A[i],i));
    }

    int j =0;

    while(i<A.size()){
        q.push(make_pair(A[i],i));
        while(q.top().second<j){
            q.pop();
        }

        ans.push_back(q.top().first);

        i++;
        j++;

    }

    return ans;

}
