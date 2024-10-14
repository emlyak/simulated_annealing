#include "includes.h"
#include "dllexport.h"

DLL_ANNEALING_EXPORTS
class Point{

public:
    Point() = default;

    Point(const std::vector<double>& coords_):
    coords(coords_) {};

    Point(std::vector<double>&& coords_)
    : coords(std::move(coords_))
    {};

    double& operator[](std::size_t i)
    {
        return coords[i];
    }
    std::size_t size()
    {
        return coords.size();
    }


    std::vector<double> coords;

};