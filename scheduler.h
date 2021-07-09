#include"queue.h"
#include"processors.h"

#define BINS 64
#define ROWS 1<<9
#define COLUMNS 1<<9
#define CORES 8

class Scheduler{
    public:
    vector<int> binarray, rowarray;

    void init(){
        binarray = vector<int>(CORES,0);
        rowarray = vector<int>(BINS,0); //next row number to be scheduled from each bin
    }

    void schedule(Queue &que, Processors &processor, int coreId){
        int binNmbr = binarray[coreId];
        int row = rowarray[coreId*8 + binNmbr];  
        vector<int> rowdata = que.readQueue(binNmbr,row);
        processor.inputbuffer = rowdata;
        processor.free = 0;
        binarray[coreId]++;
        rowarray[coreId*8 + binNmbr]++;
    }
};