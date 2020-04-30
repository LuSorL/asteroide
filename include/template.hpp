#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <cstdlib>

template <class T>

T generateRandomNumber(T startRange, T endRange)
{
    return startRange + T(rand()) / T(RAND_MAX) * (endRange - startRange);
}

#endif