class Solution {
public:
    
bool check2(pair<int, int> top_left, pair<int, int> bottom_right) {
    return top_left.first <= bottom_right.first && top_left.second >= bottom_right.second;
}

bool check(pair<int, int> point, pair<int, int> top_left, pair<int, int> bottom_right) {
    int x = point.first;
    int y = point.second;

    int rect_x1 = top_left.first;
    int rect_y1 = top_left.second;
    int rect_x2 = bottom_right.first;
    int rect_y2 = bottom_right.second;


    if (!check2(top_left, bottom_right)) {
        cout << "Invalid rectangle: top_left is not towards the bottom and right of bottom_right." << endl;
        return false;
    }


    if (rect_x1 <= x && x <= rect_x2 && rect_y1 >= y && y >= rect_y2) {
        return true;
    } else {
        return false;
    }
}

    
    int numberOfPairs(vector<vector<int>>& v1) {
        // n^2 works 
        vector<vector<int>> v2=v1;
        vector<pair<int,int>> v;
        for(auto it:v1){
            v.push_back({it[0],it[1]});
        }
        // sort(v.begin(),v.end());
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                if(i==1 and j==0){cout<<"fff"<<endl;}
                if(check2(v[i],v[j])){
                    // valid ho sakta 
                    int f=1;
                    for(int k=0;k<n;k++){
                        if(k==i or k==j){continue;}
                        if(check(v[k],v[i],v[j])==1){f=0;break;}
                    }
                    if(f){ans++;cout<<i<<" "<<j<<endl;}
                }
            }
        }
        return ans;
    }
};
