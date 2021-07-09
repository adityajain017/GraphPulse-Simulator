#define ull unsigned long long


class GenerationUnit{
    public:
    vector<int> genbuffer;

    void init(){
        genbuffer = vector<int>(4,0); 
    }

    // returns index of the buffer which is empty or returns -1 if no buffer is free. 
    int getFreeBuffer(){
        for(int i=0; i<4;i++){
            if(genbuffer[i]==0) return i;
        }
        return -1;
    }

    void propogate(ull vertex, int delta, int bufferId){

    }
};