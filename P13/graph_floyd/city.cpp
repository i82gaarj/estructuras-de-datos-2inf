#include <cmath>
#include "city.hpp"

/** @brief convert from degrees to radians. */
inline static
double
to_rad(const double a)
{
    return M_PI/180.0 * a;
}

double
distance(const City& s, const City& d)
{
    const double EARTH_RADIX = 6378.0; //Km.
    const double dif_latitude = to_rad(d.latitude - s.latitude);
    const double dif_longitude = to_rad(d.longitude - s.longitude);

    const double a = std::pow(std::sin(dif_latitude/2.0), 2.0) +
              std::cos(to_rad(s.latitude))*
              std::cos(to_rad(d.latitude))*
              std::pow(std::sin(dif_longitude/2.0),2.0);
    const double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0-a));
    return c*EARTH_RADIX;
}

/**
 * @brief unfold a city from an input stream.
 */
std::istream&
operator>>(std::istream& in, City& c)
{
    in >> c.name >> c.latitude >> c.longitude;
    return in;
}

/**
 * @brief fold a City to an output stream.
 */
std::ostream&
operator<<(std::ostream& out, City const& c)
{
    out << c.name << ' ' << c.latitude << ' ' << c.longitude;
    return out;
}

/**
 * @brief Template specialization for City.
 */
template<>
std::shared_ptr<WGraph<City>> create_wgraph(std::istream &in) noexcept(false)
{
    assert(in);
    std::shared_ptr<WGraph<City>> graph;

    //TODO
    //Remenber: to save space, for the edges it is only used the name of de
    //city and not the whole city data.
    std::string tipo;
    in >> tipo;

    bool is_directed;
    if (tipo == "DIRECTED"){
        tipo = true;
    }
    else if (tipo == "NON_DIRECTED"){
        is_directed = false;
    }
    else{
        std::runtime_error("Wrong graph");
    }

    unsigned int ncities;
    in >> ncities;
    graph = std::make_shared<WGraph<City>>(WGraph<City>(ncities));

    City c;

    for(unsigned int i = 0; i < ncities; i++){
        in >> c;
        graph -> add_node(c);
    }

    unsigned int n_edges;
    in >> n_edges;
    

    for(unsigned int i = 0; i < n_edges; i++){
        std::string item1;
        std::string item2;
        float peso;
        in >> item1 >> item2 >> peso;

        graph -> set_weight(graph -> find(item1), graph -> find(item2), peso);

        if (is_directed == false){
            graph -> set_weight(graph -> find(item2), graph -> find(item1), peso);
        }
    }
    return graph;
}

