using namespace std;

#include<iostream>
#include<vector>
#include<queue>

#include"scheduler.h"
#include"graph.h"

#define ull unsigned long long
#define CORES 8


int main(){
    Queue que;
    vector<Processors> processor(CORES);
    Scheduler scheduler;
    Graph gr;
    gr.createGraph("web-Google/web-Google.mtx");
    cout<<gr.numVertices<<" "<<gr.numEdges<<endl;
    
    que.init(1/gr.numVertices);
    for(int core=0; core<CORES;core++)
        processor[core].init();
    
    scheduler.init();
    

    int converge =1;
    u_int64_t cycle =1;
    
    while(1){
        for(int core=0; core<CORES; core++){
            if(processor[core].isFree()){
                scheduler.schedule(que,processor[core],core);
            }
        }
        que.pipelineProcess();
        if(converge) break;
        cycle++;
    }
}