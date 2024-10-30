#include "simulated_annealing.h"



double Simulated_annealing::min(
    std::function<double(double)> func,
        double t_start,
        double t_stop,
        double coefficient
)
{
    std::uniform_real_distribution<double> unif(-100, 100);
    std::default_random_engine re;
    
    double oldPoint = unif(re);
    double oldValue = func(oldPoint);

    do
    {   
        std::uniform_real_distribution<double> unif(oldPoint - 100, oldPoint + 100);
        double newPoint = unif(re);
        double newValue = func(newPoint);
        
        if (newValue > oldValue)
        {
            if (stay(t_start, (oldValue - newValue)))
            {
                oldPoint = newPoint;
                oldValue = newValue;
            }
        }  
        else
        {
            oldPoint = newPoint;
            oldValue = newValue;
        }

        t_start *= coefficient;
    }
    while (t_start > t_stop);

    return oldPoint;
}