#include "calc.h"
#include <cassert>

std::vector <double> Calc::solveLinear (Matrix<double> mat) {
    using std::vector;

    assert (mat.size()+1 == mat[0].size());
    vector <double> ret(mat.size());

    for (int i = 0; i < mat.size()-1; ++i) {
        int ind = -1;
        for (int j = i; j < mat.size(); ++j) {
            if (mat[j][i] != 0) {
                ind = j;
                break;
            }
        }
        if (ind < 0) {
            mat[i][i] = 1;
            ind = i;
        }
        mat[i].swap (mat[ind]);

        for (int j = i+1; j < mat.size(); ++j) {
            double ratio = -mat[j][i] / mat[i][i];
            for (int k = 0; k < mat[0].size(); ++k) {
                mat[j][k] += ratio*mat[i][k];
            }
        }
    }


    for (int i = mat.size()-1; i >= 1; --i) {
        int ind = -1;
        for (int j = i; j >= 0; --j) {
            if (mat[j][i] != 0) {
                ind = j;
                break;
            }
        }
        if (ind < 0) {
            mat[i][i] = 1;
            ind = i;
        }
        mat[i].swap(mat[ind]);

        for (int j = i-1; j >= 0; --j) {
            double ratio = -mat[j][i] / mat[i][i];
            for (int k = 0; k < mat[0].size(); ++k) {
                mat[j][k] += ratio*mat[i][k];
            }
        }
    }

    for (int i = 0; i < mat.size(); ++i) {
        ret[i] = mat[i][mat[i].size()-1] / mat[i][i];
    }
    return ret;
}
