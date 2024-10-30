#include "simulated_annealing.h"

inline void swap(vec_p& v, int a, int b)
{
    iter_swap(v.begin() + a, v.begin() + b);
}

inline double distance(vec_p& v,
    std::function<double(vec_d, vec_d)> metric)
{
    double res = 0.;
    for (int i = 0; i < v.size() - 1; ++i)
        res += metric(v[i].coords, v[i+1].coords);
    return res + metric(v[0].coords, v[v.size()-1].coords);
}

double Simulated_annealing::salesman(
        vec_p& points,
        double T,
        double TStop,
        double coefficient,
        std::function<double(vec_d, vec_d)> metric
    )
{
    srand(std::time(0));

    int size = points.size();
    double oldDistanse = distance(points, metric);

    do
    {
        int a = rand_i(0, size); int b;
        do b = rand_i(0, size);
        while (b == a);

        swap(points, a, b);
        
        double newDistance = distance(points, metric);
        
        if (newDistance > oldDistanse)
            if (!stay(T, (oldDistanse - newDistance)))
                swap(points, a, b);
            else
                oldDistanse = newDistance;    
        else
            oldDistanse = newDistance;

        T *= coefficient;
    }
    while (T > TStop);

    return oldDistanse;
}