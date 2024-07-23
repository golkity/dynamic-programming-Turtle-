#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    vector<vector<int>> t(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));
    for (int i =0;i<t.size();++i) {
        for (int j = 0; j < t[i].size(); ++j) {
            int nums;
            cin >> nums;
            t[i][j] = nums;
        }
    }
    for(int i =1;i<n;++i){
        t[i][0] += t[i-1][0];
    }
    for(int i =1;i<m;++i){
        t[0][i] += t[0][i-1];
    }
    for(int i =1;i<n;++i){
        for(int j=1;j<m;++j){
            t[i][j] += min(t[i-1][j], t[i][j-1]);
        }
    }
    cout<<t[n-1][m-1];

    return 0;
}
