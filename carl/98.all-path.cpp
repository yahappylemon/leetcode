#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(const vector<vector<int>>&graph, int node){
    if(node==graph.size()-1){
        result.push_back(path);
        return;
    }
    for(int i=1;i<int(graph.size());i++){
        if(graph[node][i]==1){
            path.push_back(i);
            backtracking(graph, i);
            // backtracking
            path.pop_back();
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
    }
    // 完整路徑：起點為1,終點為n
    path.push_back(1);
    backtracking(graph, 1);
    for(int i=0;i<int(result.size());i++){
        for(int j=0;j<int(result[i].size());j++){
            if(j==0){
                cout<<result[i][j];
            }else{
                cout<<" "<<result[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}