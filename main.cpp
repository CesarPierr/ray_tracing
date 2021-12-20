

#include "pointVector.hpp"
#include <stdlib.h>

int main(){
    PointVector<float,3> A(3,4,5);
    PointVector<float,3> B(1,2,3);
    PointVector<float,3> C = A+B;
    std::cout << C << std::endl;
    return 0;
}