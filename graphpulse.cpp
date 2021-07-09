using namespace std;

#include<iostream>
#include"queue.h"

#define ull unsigned long long

int main(){
    // int n =64;
    // vector<vector<vector<int>>> bins(n, vector<vector<int>>(ROWS, vector<int>(COLUMNS)));
    ull numberVertices=10, numberEdges;
    Queue que;
    que.init(1/numberVertices);

    int converge =1;
    u_int64_t cycle =1;
    while(1){
        que.pipelineProcess();
        if(converge) break;
        cycle++;
    }
}