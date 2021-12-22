

#include "color.hpp"

int main(){
    Color a(0.1,0.2,0.3);
    a = a*2;
    Color b(0.1,0.2,0.3);
    a+=b;
    std::cout << b.r() << b.g() << a.b() << std::endl;
    int t;
    float s,v;
    a.setTSV(t,s,v);
    std::cout << t << " " << s << " " << v << std::endl;
    return 0;
}