//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee,
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>

using namespace boost;

enum family
{
    Jeanie,
    Debbie,
    Rick,
    John,
    Amanda,
    Margaret,
    Benjamin,
    N
};

struct name_t {
    typedef boost::edge_property_tag kind;
};

int main()
{
    const char* name[] = { "Jeanie", "Debbie", "Rick", "John", "Amanda",
        "Margaret", "Benjamin" };

    // adjacency_list<listS, vecS, bidirectionalS,
    //                    property<vertex_index_t, int> > g(N);


    typedef adjacency_list<listS, listS, directedS, property<boost::vertex_index_t, int, property<name_t, family>> > Graph;

    Graph g(N);
    for(int i = 0; i < 6; i++){
        add_vertex(g);
    }
    
    add_edge(Jeanie, Debbie, g);
    add_edge(Jeanie, Rick, g);
    add_edge(Jeanie, John, g);
    add_edge(Debbie, Amanda, g);
    add_edge(Rick, Margaret, g);
    add_edge(John, Benjamin, g);

    graph_traits< Graph >::vertex_iterator i, end;
    // // property_map< adjacency_list<>, vertex_index_t >::type index_map
    // //     = get(vertex_index, g);

    // property_map<Graph, first_name_t>::type first_name = get(first_name_t, g);

    typedef boost::graph_traits<Graph>::vertex_descriptor MyVertex;

    int ind = 0;

    for (auto[i, end] = vertices(g); i != end; ++i, ++ind)
    {
        MyVertex v = vertex(*i, g);
        g[v].jg = ind;
        std::cout << vertex(*i, g) << ' ' << g[v].jg;
        std::cout << std::endl;
    }

    remove_vertex(0, g);

    std::cout << std::endl;

    for (auto[i, end] = vertices(g); i != end; ++i)
    {
        MyVertex v = vertex(*i, g);
        std::cout << *i << ' ' << vertex(*i, g) << ' ' << g[v].jg;
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}