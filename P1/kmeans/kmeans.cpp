#include "kmeans.hpp"
#include "pattern.hpp"
#include <cstdlib>
#include <ctime>
#include <utility>

/**
 * @brief kmeans_initialice_centroids
 * Initialize K centroids picking at random K patterns from dts.
 * @warning avoid select the same pattern several times.
 */
static void
kmeans_initialize_centroids(const std::vector<Pattern>& dts,
                                 size_t K,
                                 std::vector<Pattern>& centroids)
{
    centroids.resize(K, Pattern(dts[0].dim()));

    //TODO : WARNING AVOD SELECT THE SAME PATTERN SEVERAL TIMES.
    std::vector <int> indices(K);
    srand(time(0));
    
    for (int i = 0; i < K; i++){
        int indice = rand() % dts.size();
        for (int j = 0; j < indices.size(); j++){
            if (indices[j] == indice){
                indice = rand() % dts.size();
                j = 0;
            }
        }
        indices.push_back(indice);
        centroids[i] = dts[indice];
        centroids[i].set_class_label(i);
    }
}

/** @brief assign patterns to the nearest centroid.
 * Each pattern in dts will have the nearest centroid's label.
 * @return the number of changes carried out.
 */
static size_t
kmeans_assign_patterns(std::vector<Pattern>& dts,
                           std::vector<Pattern>& centroids)
{
    size_t num_changes = 0;

    //TODO
    for (int i = 0; i < dts.size(); i++){
        float distancia_minima = distance(dts[i], centroids[0]);
        int indice_minima_distancia = 0;
        for (int j = 1; j < centroids.size(); j++){
            float distancia = distance(dts[i], centroids[j]); // Calculamos la distancia con cada uno de los centroides y elegimos el de menor distancia
            if (distancia < distancia_minima){
                distancia_minima = distancia;
                indice_minima_distancia = j;
            }
        }

        if (dts[i].class_label() != centroids[indice_minima_distancia].class_label()){ // Establecemos la nueva etiqueta si esta es distinta
            dts[i].set_class_label(centroids[indice_minima_distancia].class_label());
            num_changes++;
        }
    }
    
    return num_changes;
}

/**
 * @brief Given a dts compute the centrois of each class label.
 * @param dts is the dataset.
 * @param centroids are the centroids.
 */
static void
kmeans_compute_centroids(const std::vector<Pattern>& dts,
                              const size_t K,
                              std::vector<Pattern>& centroids)
{
    /* reset centroids to zero.*/
    const size_t dim = dts[0].dim();
    if (centroids.size() != K)
        centroids.resize(K, Pattern(dts[0].dim()));
    for(size_t k=0; k<centroids.size(); ++k)
        centroids[k] = Pattern(dim, static_cast<int>(k));

    //TODO
    std::vector <float> v(centroids.size(), 0);
    for (int i = 0; i < K; i++){
        for (int j = 0; j < dts.size(); j++){
            if (dts[j].class_label() == centroids[i].class_label()){
                centroids[i] += dts[j];
                v[i]++;
            }
        }
    }

    for (int i = 0; i < K; i++){
        centroids[i] *= (1 / v[i]);
    }
}


size_t
kmeans(std::vector<Pattern>& dts,
            const size_t K,
            const size_t max_iters,
            std::vector<Pattern>& centroids)
{

    /*Reset labels to -1 (none class).*/
    for(size_t i = 0; i < dts.size(); ++i)
        dts[i].set_class_label(-1);

    /*Initialice picking at random K patterns.*/
    kmeans_initialize_centroids(dts, K, centroids);

    size_t iter = 0;
    size_t num_changes;
    do
    {
        num_changes = kmeans_assign_patterns(dts, centroids);
        /* assign patterns to the nearest centroid. */
        if (num_changes>0)
            kmeans_compute_centroids (dts, K, centroids);
    }
    while (++iter < max_iters && num_changes>0);
    return iter;
}
