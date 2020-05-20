#ifndef __GRAPH_TRAVERSALS_HPP
#define __GRAPH_TRAVERSALS_HPP

#include <stack>
#include <queue>

#include "graph.hpp"

/**
 * @brief Depth first search from a vertex.
 * The current node will be used as start vertex.
 * @arg g is the graph.
 * @arg p is a functional to process the vertex.
 * @return the last p() return value.
 * @pre g.has_current_node()
 * @warning if p() return false, the search will be finished.
 * @warning only a spanning tree is searched.
 */
template<class T, class Processor>
bool depth_first_search(WGraph<T>& g, Processor& p)
{
    assert(g.has_current_node());
    bool ret_val = true;

    //TODO
    //Do an ITERATIVE implementation.
    g.set_visited(false);

    std::stack <std::shared_ptr <GraphNode <T>>> frontier;
    frontier.push(g.current_node());
    std::shared_ptr <GraphNode <T>> current;
    while(frontier.empty() == false){
        current = frontier.top();

        frontier.pop();

        if (current -> is_visited() == false){
            current -> set_visited(true);

            if (p.apply(current) == false){
                ret_val = true;
                break;
            }
            else{
                g.goto_node(current);
                g.goto_first_node();

                for (int i = 0; i < g.size(); i++){
                    if (g.are_adjacent(current, g.current_node())){
                        frontier.push(g.current_node());
                    }
                    g.goto_next_node();
                }

            }
        }
    }

    return ret_val;
}

/**
 * @brief breadth first search from a vertex.
 * The current node will be used as start node.
 * @arg g is the graph.
 * @arg p is a functional to process the vertex.
 * @return the last p() return value.
 * @pre g.has_current_node()
 * @warning if p() return false, the search will be finished.
 * @warning only a spanning tree is searched.
 */
template<class T, class Processor>
bool breadth_first_search(WGraph<T>& g, Processor& p)
{
    assert(g.has_current_node());
    bool ret_val = true;

    //TODO
    g.set_visited(false);

    std::queue <std::shared_ptr <GraphNode <T>>> frontier;
    frontier.push(g.current_node());
    std::shared_ptr <GraphNode <T>> current;
    while(frontier.empty() == false){
        current = frontier.front();

        frontier.pop();

        if (current -> is_visited() == false){
            current -> set_visited(true);

            if (p.apply(current) == false){
                ret_val = true;
                break;
            }
            else{
                g.goto_node(current);
                g.goto_first_node();

                for (int i = 0; i < g.size(); i++){
                    if (g.are_adjacent(current, g.current_node())){
                        frontier.push(g.current_node());
                    }
                    g.goto_next_node();
                }

            }
        }
    }
    return ret_val;
}

#endif // __GRAPH_TRAVERSALS_HPP
