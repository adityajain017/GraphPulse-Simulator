#define BINS 64
#define ull unsigned long long

class FPA{
    public:
    vector< queue<pair<ull,int>> > pipeline;
    vector<vector<int>> activeRows;
    vector<int> toStore, c1,c2,c3, c4; 
    
    void init(){
        pipeline = vector< queue<pair<ull,int>> >(BINS);
        activeRows = vector<vector<int>>(BINS,vector<int>(ROWS,0));
        c1 = vector<int>(BINS,-1);
        c2 = vector<int>(BINS,-1);
        c3 = vector<int>(BINS,-1);
        c4 = vector<int>(BINS,-1);
        toStore = vector<int>(BINS,-1);
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
        if(!pipeline[binNmbr].empty()){
            vector<int> entry = pipeline[binNmbr].front();
            int row = entry[0];
            int col = entry[1];
            int delta = entry[2];
            if(activeRows[binNmbr][row]){
                c1[binNmbr] = -1;
            }
            else{
                bins[binNmbr][row][col]+=delta;
                pipelineProcess[binNmbr].pop();
                activeRows[binNmbr][row] = 1;
                c1[binNmbr] = row;
            }
            
        }
    }

    void compute1(int binNmbr){
        c2[binNmbr]= c1[binNmbr];
    }
    
    void compute2(int binNmbr){
        c3[binNmbr]= c2[binNmbr];
    }

    void compute3(int binNmbr){
        c4[binNmbr]= c3[binNmbr];
    }

    void compute4(int binNmbr){
        toStore[binNmbr]= c4[binNmbr];
    }

    void store(int binNmbr){
        if(toStore[binNmbr]!=-1) activeRows[binNmbr][toStore[binNmbr]] =0;
    }
    
};