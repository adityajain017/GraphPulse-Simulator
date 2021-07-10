using namespace std;

#include<iostream>
#include<vector>
#include<queue>

#include"scheduler.h"
// #include"graph.h"

#define ull unsigned long long
#define CORES 8


int main(){
// Initialization phase start
    string path = "test.txt";
    // string path = "web-Google/web-Google.mtx";
    Queue que;
    vector<Processors> processor(CORES);
    Scheduler scheduler;
    Graph gr;
    gr.createGraph(path);
    cout<<gr.numVertices<<" "<<gr.numEdges<<endl;
    
    que.init(1/gr.numVertices);
    for(int core=0; core<CORES;core++)
        processor[core].init();
    
    scheduler.init(); 
// Initialization phase over

// Cycle Phase starts
    int converge =1;
    u_int64_t cycle =1;
    
    while(1){
        for(int core=0; core<CORES; core++){
            if(processor[core].isFree()){
                scheduler.schedule(processor[core]);
            }
            processor[core].execute(gr);
        }
        que.pipelineProcess();
        if(scheduler.filloutbuffer(que)) break;
        if(converge) break;
        cycle++;
    }
// Cycle Phase over

    cout<<"Number of cycles: "<<cycle<<endl;
}