#ifndef CALC_H
#define CALC_H
#include <vector>
#include "matrix.h"

class Calc {
public:
    static std::vector <double> solveLinear (Matrix<double> matr);
};

#endif // CALC_H
