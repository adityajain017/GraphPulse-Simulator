#define CORES 8
#define COLUMNS 1<<9
#define THRESHOLD 0.5

#include"generationunit.h"

class Processors{
    public:
    vector<int> inputbuffer;
    GenerationUnit gnrtunit;
    bool free = true;;
    ull frstVrtx =-1;

    int gnrtbufferId;
    int currentindx=0;

    void init(){
        inputbuffer = vector<int>(COLUMNS,0);
        gnrtunit.init();
    }

    bool isFree(){
        return free;
    }

    void execute(Graph &gr, Queue &que){
        gnrtbufferId = gnrtunit.getFreeBuffer();
        if(!free){
            write();
            compute();
            read(gr,que);
        }
    }

    void read(Graph &gr, Queue &que){
        if(gnrtbufferId!=-1){
            while(inputbuffer[currentindx]!=0) currentindx++;
            if(currentindx<=COLUMNS){
                ull vertexId = frstVrtx+currentindx;
                int vrtxproperty = gr.vrtxproperty[vertexId];
                ull outdegree = gr.csr_oa[vertexId+1] - gr.csr_oa[vertexId];
                gr.vrtxproperty[vertexId]+=inputbuffer[currentindx];
                if(outdegree>0){
                    if(inputbuffer[currentindx] > THRESHOLD)
                       gnrtunit.propogate(gr, que, vertexId, inputbuffer[currentindx], gnrtbufferId);
                }
            }
            else{
                free = true;
                currentindx=0;
            }
        }
    }

    void compute(){

    }

    void write(){
        if(gnrtbufferId!=-1){
            
        }
    }
};