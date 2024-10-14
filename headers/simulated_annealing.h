#include "metrics.hpp"
#include "includes.h"
#include "Point.h"
#include <iostream>

using vec_p = std::vector<Point>;
using vec_ptr = std::vector<Point*>;
using vec_d = std::vector<double>;

DLL_ANNEALING_EXPORTS
class Simulated_annealing
{

public:

    static
    void salesman(
        vec_p& points,
        double T,
        double coefficient,
        std::function<double(vec_d, vec_d)> metric = metrics::euclidian
    );

};