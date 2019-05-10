
#ifndef GRAPH_ADJ_HPP
#define GRAPH_ADJ_HPP


#include<vector>
#include<set>
#include<iostream>
#include<fstream>
#include<string>



class Graph
{
    public:

    typedef int Vertex;
    typedef std::vector<std::vector<Vertex>> Adjacency_List;
    typedef std::pair<Vertex,Vertex> Edge;
    typedef std::set<Edge> Edges; 

    Graph(); //empty graph.
    Graph(const char*); // contruct a graph given a file that represent the edges.
    
    
    int num_vertices(){ return n_vertices_;};
    int num_edges(){return n_edges_;}

    const int num_vertices()const{ return n_vertices_;};
    const int num_edges()const{return n_edges_;}

    Adjacency_List& adlist(){ return adl_;}
    const Adjacency_List& adlist()const{return adl_;};

    friend std::ostream &operator<<(std::ostream& os, const Graph& g);
    friend void ncol2SAT(const Graph& g,size_t ncol);


    

    private:
    
    Adjacency_List adl_;
    size_t n_vertices_;
    size_t n_edges_;


};



Graph::Graph(const char* name_file)
{
    std::ifstream myfile(name_file);
    std::string line;
    int a;
    size_t pos1,pos2, end;
    const char* b="\0";
    int i =0;
    n_edges_ = 0;
    n_vertices_ =0;

    if(myfile.is_open())
    {

        while ( getline (myfile,line) )
        {
            pos1 = line.find(":")+1;

            end =line.find(";");
            adl_.push_back(std::vector<Vertex>());

            
            do
            {

                pos2 = line.find(":", pos1);
                
                if(pos2== std::string::npos)
                    pos2 =end;
                
                std::string substring = line.substr(pos1, pos2-pos1);
                adl_[i].push_back(std::stoi(substring));

                pos1 = pos2+1;

                n_edges_++;
             

            }while(pos2!=end);

            pos1 =0;
            i++;


        }

        n_vertices_ =i;

    }

    else
    {
        std::cout<<"Error opening the file";
    }
    



    myfile.close();
}

std::ostream &operator<<(std::ostream& os, const Graph& g)
{
    int i=0;

    for(auto lista:g.adl_)
    {

        for(auto nodo:lista)
        {

            os<<"< "<<i<<" , "<<nodo<<" >"<<" ";

        }

        os<<'\n'<<std::endl;
        i++;


    }

    return os;
    
}




#endif