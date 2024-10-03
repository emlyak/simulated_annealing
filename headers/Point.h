#include "dllexport.h"
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

DLL_ANNEALING_EXPORTS
class Point{

public:
    Point() = default;

    Point(std::vector<double> coords_):
    coords(coords_) {};

    double& operator[](std::size_t i)
    {
        return coords[i];
    }

    std::vector<double> coords;

};