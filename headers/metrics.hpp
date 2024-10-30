#include <vector>
#include <numeric>
#include <cmath>
#include "dllexport.h"

namespace metrics {

    DLL_ANNEALING_EXPORTS
    inline
    auto euclidian = [](const std::vector<double>& x, const std::vector<double>& y)
    {
        return std::sqrt(
                std::inner_product(
                    x.begin(),
                    x.end(),
                    y.begin(),
                    0., std::plus<>(), [](double a, double b)
                    {return std::pow((a - b), 2);}
                )
            );
    };

    DLL_ANNEALING_EXPORTS
    inline
    auto city_blocks = [](const std::vector<double>& x, const std::vector<double>& y)
    {
        return std::inner_product(
            x.begin(),
            x.end(),
            y.begin(),
            0.,
            std::plus<>(),
            [](double a, double b) {return std::abs(a - b);}
        );
    };
    
    // DLL_ANNEALING_EXPORTS
    // inline
    // auto d3 = [](const std::vector<double>& x, const std::vector<double>& y)
    // {
    //     return std::inner_product(
    //         x.begin(),
    //         x.end(),
    //         y.begin(),
    //         0.,
    //         std::plus<>(),
    //         [](double& a, double& b) {return std::abs(a - b);}
    //     );
    // };
    
    
}