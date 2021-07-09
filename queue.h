#include<vector>
#include<queue>



#define BINS 64
#define ROWS 1<<9
#define COLUMNS 1<<9
#define ull unsigned long long

int getBin(ull vertex){
    return 0;
}

int getRow(ull vertex){
    return 0;
}

int getCol(ull vertex){
    return 0;
}

class Queue{
    public:
    int n =64;
    vector<vector<vector<int>>> bins;
    vector<vector<int>> bitvector;
    
    vector< queue<vector<int>> > pipeline;
    vector<vector<int>> activeRows;
    vector<int> toStore, c1,c2,c3, c4; 

    void init(int val){
        bins = vector<vector<vector<int>>>(BINS, vector<vector<int>>(ROWS, 
                        vector<int>(COLUMNS, val)));
        bitvector = vector<vector<int>>(BINS,vector<int>(ROWS));
        
        pipeline = vector< queue<vector<int>> >(BINS);
        activeRows = vector<vector<int>>(BINS,vector<int>(ROWS,0));
        c1 = vector<int>(BINS,-1);
        c2 = vector<int>(BINS,-1);
        c3 = vector<int>(BINS,-1);
        c4 = vector<int>(BINS,-1);
        toStore = vector<int>(BINS,-1);
    }

    vector<int> readQueue(ull vertex){
        int binNmbr = getBin(vertex);
        int row = getRow(vertex);

        return bins[binNmbr][row];
    }

    // returns 1 if insertion is completed else 0. 
    // Generation unit needs to wait until insertion is completed.
    int insert(ull vertex, int delta){
        int binNmbr = getBin(vertex);
        int row = getRow(vertex);
        int col = getCol(vertex);
        
        if(pipeline[binNmbr].empty()){
            pipeline[binNmbr].push({row,col,delta});
            //  wait till insertion is complete in the FPA pipeline
            return 1;
        }
        else return 0;
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
                pipeline[binNmbr].pop();
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

