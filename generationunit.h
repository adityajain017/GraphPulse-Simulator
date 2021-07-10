#define ull unsigned long long
#include"graph.h"

class GenerationUnit{
    public:
    vector<bool> genbufferFree;

    void init(){
        genbufferFree = vector<bool>(4,true); 
    }

    // returns index of the buffer which is empty or returns -1 if no buffer is free. 
    int getFreeBuffer(){
        for(int i=0; i<4;i++){
            if(genbufferFree[i]==true) return i;
        }
        return -1;
    }

    void propogate(Graph &gr, Queue &que, ull vertex, int delta, int bufferId){
        genbufferFree[bufferId] = false;
        for(ull i=gr.csr_oa[vertex]; i<gr.csr_oa[vertex+1];i++){
            que.insert(gr.csr_na[i], delta);
        }
    }
};