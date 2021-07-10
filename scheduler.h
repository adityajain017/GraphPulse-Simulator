#include"queue.h"
#include"processors.h"

#define BINS 64
#define ROWS 1<<9
#define COLUMNS 1<<9
#define CORES 8

class Scheduler{
    public:
    vector<int> rowarray;
    queue<vector<int>> queue_outbuffer;
    queue<int> bin_que;
    queue<ull> frstvrtx_que;

    void init(){
        rowarray = vector<int>(BINS,0); //next row number to be scheduled from each bin

        for(int binNmbr =0; binNmbr<BINS; binNmbr++)
            bin_que.push(binNmbr);
    }

    // When a core is free, a row from the output buffer of the queue is supplied to the 
    // input buffer of that core
    void schedule(Processors &processor){
        if(!queue_outbuffer.empty()){
            processor.inputbuffer = queue_outbuffer.front();
            processor.frstVrtx = frstvrtx_que.front();
            processor.free = false;
            queue_outbuffer.pop();
            frstvrtx_que.pop();
        }
    }

    // This reads a row from the queue and insert it into the outputbuffer of the queue.
    // If outputbuffer has space.
    bool filloutbuffer(Queue &que){
        vector<int> temp;
        ull tmpvrtx;
        if(!bin_que.empty()){
            for(int i=0; i<CORES and queue_outbuffer.size()<8; i++){
                int binNmbr = bin_que.front();
                bin_que.pop();
                if(que.readQueue(binNmbr,rowarray[binNmbr],temp,tmpvrtx)){
                    rowarray[binNmbr]++;
                    if(rowarray[binNmbr]<ROWS) bin_que.push(binNmbr);
                    queue_outbuffer.push(temp);
                    frstvrtx_que.push(tmpvrtx);
                }
                else bin_que.push(binNmbr);
            }
            return false;
        }
        else {
            cout<<"Iteration Over"<<endl;
            return true;
        }
    }
};