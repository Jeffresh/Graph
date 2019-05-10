#include"Graph.hpp"



int main(int argc, char const *argv[])
{
    
    Graph g("the_petersen_graph.txt");

    std::cout<<g;

    return 0;
}
