class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        // for (int i = 0; i < points.size(); i++) {
        //     auto p = points[i];
        //     q.push({p[0]*p[0]+p[1]*p[1], i});
        // }
        // vector<vector<int>> ans;
        // while (k > 0) {
        //     ans.push_back(points[q.top().second]);
        //     q.pop(), k--;
        // }
        // return ans;
        
        int pivot = -1, left = 0, right = points.size()-1;
        while(pivot+1 != k) {
            pivot = partition(points, left, right);
            if (pivot+1 > k) right = pivot-1;
            else left = pivot+1;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i <= pivot; i++) ans.push_back(points[i]);
        return ans;
    }
    
private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int midPoint = l + (r-l)/2;
        auto mid = points[midPoint];
        int pivot = mid[0] * mid[0] + mid[1] * mid[1];
        swap(points[midPoint], points[r]);
        int i = l, j = l;
        for (; j < r;) {
            auto a = points[i];
            auto b = points[j];
            if (b[0]*b[0]+b[1]*b[1] < pivot) {
                swap(points[i], points[j]);
                i++, j++;
            }
            else j++;
        }
        swap(points[i], points[r]);
        return i;
    }
};