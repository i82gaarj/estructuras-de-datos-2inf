#ifndef __FLOYD_ALGORITHM_HPP__
#define __FLOYD_ALGORITHM_HPP__

#include <exception>
#include <limits>
#include <memory>
#include <valarray>
#include <vector>

#include "graph.hpp"

/**
 * @brief Apply the Prim algorithm to a undirected connected graph to get the minimum spannig tree.
 * The current node of g is used as root.
 * @arg[in] g is the graph.
 * @arg[out] mst is the list of edges of g that forms the minium spanning tree.
 * @return the total weigth of the mininum spanning tree.
 * @pre g is an undirected connected graph.
 * @pre g.hash_current()
 * @warning throw std:runtine_error("It is a non-connected graph.") if a solution could not be computed.
 */
template <class T>
float
prim_algorithm(WGraph<T>& g, std::vector<typename WGraph<T>::EdgeRef>& mst) noexcept(false)
{
    assert(g.has_current_node());

    //TODO: Declare the U, V and C vectors according to the algorithm (see class documentation.)

    float total_distance = 0.0;
    auto u = g.current_node();
    std::vector<bool> u_vector(g.size(), false);
    std::vector<typename WGraph<T>::NodeRef> v(g.size(), nullptr);
    std::vector<float> c(g.size(), std::numeric_limits<float>::infinity());

    //TODO: Add the start node to the Minimum Spanning Tree (mst).
    int indice = 0;
    g.goto_first_node();
    while(g.has_current_node() && g.current_node() != u){ // aqui compruebo cual es el indice del nodo inicial
        indice++;
        g.goto_next_node();
        
    }
    u_vector[indice] = true;

    //ITERATE FOR the N-1 edges.
    for (size_t i=1; i<g.size(); ++i)
    {
        //TODO: Update vector of best distances regarding the last vertex added u to the mst.

        int indice_nodo_menor_coste = 0;
        g.goto_first_node();
        for (int j = 0; j < g.size(); j++){
            float distancia = g.weight(u, g.current_node()); // calculamos la distancia
            if (distancia < c[j] && u_vector[j] == false){ // si la distancia nueva es menor, actualizamos el valor
                c[j] = distancia;
                v[j] = u;
            }

            if (c[j] < c[indice_nodo_menor_coste] && u_vector[j] == false){ // Elegimos el nodo
                indice_nodo_menor_coste = j;
            }
            g.goto_next_node();
        }

        //TODO: Find the next vertex to be added to the mst.
        //Remeber: if a tie exists, select the vertex with lesser label.
        //You can use std::numeric_limits<float>::infinity() if it is necessary.
        g.goto_first_node();
        for(int j = 0; j < indice_nodo_menor_coste; j++){
            g.goto_next_node();
        }

        //TODO: check if a valid condition is met for a connected graph.
        //Suggestion: What about the minimum distance found?
        if (total_distance == std::numeric_limits<float>::infinity()) // si el coste total es infinito, el grafo no es conexo
            throw std::runtime_error("It is a non-connected graph.");

        //TODO:Set vertex found as beloning to the mst.

        //actualizamos cada uno de los vectores u, v y c
        float distancia = c[indice_nodo_menor_coste];
        u_vector[indice_nodo_menor_coste] = true;
        c[indice_nodo_menor_coste] = std::numeric_limits <float>::infinity();

        //TODO:Add the edge found to the mst vector.
        mst.push_back(g.edge(g.current_node(), v[indice_nodo_menor_coste]));

        //TODO: update the total distance of the mst with the new edge's weight.
        total_distance += distancia;

        u = g.current_node(); // vamos al siguiente vertice
    }

    return total_distance;
}



#endif //__FLOYD_ALGORITHM_HPP__
