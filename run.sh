
wget https://suitesparse-collection-website.herokuapp.com/MM/SNAP/web-Google.tar.gz
echo "Raw Graph Downloaded"

: '
Source of graph: J. Leskovec, K. Lang, A. Dasgupta, M. Mahoney. Community Structure in Large    
 Networks: Natural Cluster Sizes and the Absence of Large Well-Defined Clusters.
 arXiv.org:0810.1355, 2008.
' 


tar -xvzf web-Google.tar.gz
echo "Graph Edgelists Extracted"

g++ graphpulse.cpp -o graphpulse
./graphpulse
echo "Execution Completed"

