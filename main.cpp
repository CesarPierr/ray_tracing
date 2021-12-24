
#include "viewer.hpp"
#include "sphere.hpp"
#include "buble_light.hpp"
int main(){

    Sphere S1(Point3(8.0,1.0,2.0), 2, Materiaux().redPlastic());
    Sphere S2(Point3(10.0,-1.0,-2.0),2,Materiaux().bronze());
    Buble_light Bl(Point3(5.0,10.0,1.0),0.5);
    Bl.light_color = Color(1.0,1.0,1.0);
    Scene S;
    S.add_object(S1);
    S.add_object(S2);
    S.add_light(Bl);
    Screen screen;
    screen.S = S;
    screen.pos = Point3(0.0,0.0,0.0);
    screen.Render();
    return 0;
}