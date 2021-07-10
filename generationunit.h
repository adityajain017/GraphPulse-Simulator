#define ull unsigned long long


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

    void propogate(ull vertex, int delta, int bufferId){
        genbufferFree[bufferId] = false;
    }
};