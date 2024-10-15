#include "metrics.hpp"
#include "includes.h"
#include "Point.h"
#include <iostream>
#include <random>

using vec_p = std::vector<Point>;
using vec_ptr = std::vector<Point*>;
using vec_d = std::vector<double>;

DLL_ANNEALING_EXPORTS
inline double rand_d()
{
    return (double)rand() / (double)RAND_MAX ;
}

DLL_ANNEALING_EXPORTS
inline int rand_i(int a, int b)
{
    return a + rand()%(b-a);
}

DLL_ANNEALING_EXPORTS
inline bool stay(double T, double delta)
{
    return rand_d() < std::exp(delta / T);
}

DLL_ANNEALING_EXPORTS
class Simulated_annealing
{

public:

    /** @brief returns shortest path
     * 
     *  @param points vector of points
     *  @param T start temperature
     *  @param coefficient temperature down coefficient
     *  @param metric metric for calculating distance
     *  @return point to local minimum
     */
    static
    void salesman(
        vec_p& points,
        double T,
        double coefficient,
        std::function<double(vec_d, vec_d)> metric = metrics::euclidian
    );

    
    /** @brief returns argument of function global minimum
     * 
     *  @param func target function
     *  @param t_start start temperature
     *  @param t_stop temperature at the end of algorithm
     *  @param coefficient temperature down coefficient
     *  @return point to local minimum
     */
    static
    double min(
        std::function<double(double)> func,
        double t_start,
        double t_stop,
        double coefficient
    );

};