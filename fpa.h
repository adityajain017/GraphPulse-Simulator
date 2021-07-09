#define BINS 64
#define ull unsigned long long

class FPA{
    public:
    vector< queue<pair<ull,int>> > pipeline;
    
    void init(){
        pipeline = vector< queue<pair<ull,int>> >(BINS);
    }

    void pipelineProcess(){
        for(int binNmbr=0; binNmbr<BINS; binNmbr++){
            store(binNmbr);
            compute4(binNmbr);
            compute3(binNmbr);
            compute2(binNmbr);
            compute1(binNmbr);
            read(binNmbr);
        }
    }

    void read(int binNmbr){
        
    }

    void compute1(int binNmbr){

    }
    
    void compute2(int binNmbr){

    }

    void compute3(int binNmbr){

    }

    void compute4(int binNmbr){

    }

    void store(int binNmbr){

    }
    
};