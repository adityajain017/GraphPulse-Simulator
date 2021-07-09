#include<fstream>
#include<unordered_map>
#include<unordered_set>

#define ull unsigned long long

class Graph{
    public:
    ull numVertices, numEdges;
    vector<int> csr_oa;
    vector<int> csr_na;
    vector<int> outdegree;
    void init(){

    }

    void createGraph(string path){
        ifstream ipf1;
        ipf1.open(path);  // Opens the file - input.txt
        if(!ipf1.is_open()) cout<<"File not find"<<endl; // Error response if file is not present.
        string line;
        getline(ipf1,line);
        while(line[0]=='%'){ // Skipping the initial introductry data in the file
            getline(ipf1,line);
        }

        // Creating the graph by reading the edgelists.
        unordered_map<ull,vector<ull>> adjlist;
        // unordered_set<ull> count;
        numEdges = 0;
        numVertices = 0;
        ull u,v;
        while( ipf1>>u>>v){
            numEdges++;
            // count.insert(u);
            // count.insert(v);
            numVertices = max(numVertices,u);
            adjlist[u].push_back(v);
        }
        // debugging
        // cout<<"size of set: "<<count.size()<<endl;

        for(u=1; u<=numVertices; u++){
            csr_oa.push_back(csr_na.size());
            outdegree.push_back(adjlist[u].size());
            for(ull i=0; i<adjlist[u].size();i++){
                v = adjlist[u][i];
                csr_na.push_back(v);
            }
        }
        // debugging
        // cout<<csr_oa[2] - csr_oa[1]<<" "<<outdegree[1]<<endl;
    }
};