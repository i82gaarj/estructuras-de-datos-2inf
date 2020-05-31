#include "a_star_algorithm.hpp"
#include "maze_solver.hpp"

#include <stack>
#include <cmath>

/**
 * @brief Convert from vertex label to x,y coordinates.
 * @param v is the vertex label.
 * @param grid_width is the width of the grid.
 * @return a tuple <x,y>.
 */
static inline std::tuple<int, int>
label_to_grid_coord(size_t v, int grid_width)
{
    //TODO
    return std::make_tuple(v % grid_width, v / grid_width);
}

/**
 * @brief Functional to compute the euclidean distance between graph vertices.
 */
struct Distance
{
    Distance(int grid_width /* arguments? */)
    {
        //TODO
        grid_width_ = grid_width; // Inicializamos
    }

    float operator()(const WGraph<int>::NodeRef& a,
                     const WGraph<int>::NodeRef& b) const
    {
        //TODO
        auto a_point = label_to_grid_coord(a -> label(), grid_width_);
        auto b_point = label_to_grid_coord(b -> label(), grid_width_);
        double distancia = sqrt(pow(std::get <0>(b_point) - std::get <0>(a_point), 2) + pow(std::get <1>(b_point) - std::get <1>(a_point), 2));
        return distancia;
    }
    int grid_width_;
};

void
maze_solver(WGraph<int>& maze,
            WGraph<int>::NodeRef& start,
            WGraph<int>::NodeRef& end,
            const int grid_width,
            std::vector<std::tuple<int, int> > &path)
{
    std::vector<size_t> predecesors;
    std::vector<float> distances;

    //TODO
    //Call to a*  with the proper arguments.
    a_star_algorithm(maze, start, end, Distance(grid_width), predecesors, distances);
    //
    path.resize(0);

    if (end -> is_visited() == true /*replace with a comparison to see if a route was found.*/)
    {
        //If there is a path, save it into path vector.
        //Remenber: the result will be tuples <x,y> for the all the points in the path from start point to end point.

        //TODO
        size_t current = end -> label(); // Comenzamos desde el final
        bool finalizado = false;
        while (finalizado == false) {
            path.push_back(label_to_grid_coord(current, grid_width));
            if (current == start -> label()){ // Paramos si llega al principio
                finalizado = true;
            }

            current = predecesors[current]; // Continuamos hacia atras
        }

        // Le damos la vuelta al vector
        for (int i = 0; i < path.size() / 2; i++){
            auto aux = path[path.size() - 1 - i];
            path[path.size() - 1 - i] = path[i];
            path[i] = aux;
        }
    }
}
