#include "dllexport.h"
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Point.h"
#include "metrics.hpp"
#include <functional>


DLL_ANNEALING_EXPORTS
class Simulated_annealing
{
    using vec_p = std::vector<Point>;
    using vec_d = std::vector<double>;

    static
    vec_p salesman(
        double T,
        double coefficient,
        vec_p& points,
        std::function<double(vec_d, vec_d)> metric = metrics::euclidian
    );

};