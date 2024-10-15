#include "simulated_annealing.h"



double Simulated_annealing::min(
    std::function<double(double)> func,
        double t_start,
        double t_stop,
        double coefficient
)
{
    std::uniform_real_distribution<double> unif(-10, 10);
    std::default_random_engine re;
    
    double oldPoint = unif(re);
    double oldValue = func(oldPoint);

    do
    {
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
        std::cout << "Energy = " << oldValue << "\n";
    }
    while (t_start > t_stop);

    return oldPoint;
}