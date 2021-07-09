#define CORES 8
#define COLUMNS 1<<9

#include"generationunit.h"

class Processors{
    public:
    vector<int> inputbuffer;
    GenerationUnit gnrtunit;
    int free =1;

    void init(){
        inputbuffer = vector<int>(COLUMNS,0);
        gnrtunit.init();
    }

    int isFree(){
        return free;
    }
};