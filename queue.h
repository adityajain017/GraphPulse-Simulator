#include<vector>
#include<queue>

#include"fpa.h"

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
    FPA fpa;

    void init(int val){
        bins = vector<vector<vector<int>>>(BINS, vector<vector<int>>(ROWS, 
                        vector<int>(COLUMNS, val)));
        bitvector = vector<vector<int>>(BINS,vector<int>(ROWS));
        fpa.init();
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
        
        if(fpa.pipeline[binNmbr].empty()){
            fpa.pipeline[binNmbr].push({vertex,delta});
            //  wait till insertion is complete in the FPA pipeline
            return 1;
        }
        else return 0;
    }

    

};

