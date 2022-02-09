
#include "viewer.hpp"
#include "sphere.hpp"
#include "buble_light.hpp"
#include "environnement.hpp"
#include "plan.hpp"

int main()
{

    Sphere S1(Point3(26.0, 4.0, 4.0), 3, Materiaux().emerald_green());
    Sphere S2(Point3(18.0, -2.0, 0.0), 3, Materiaux().glass());
    Sphere S3(Point3(18.0, 4.0, -4), 3, Materiaux().emerald_red());

    Plan P(Point3(0.0, -5.0, 0.0), Vector3(0.0, 1.0, 0.0), Materiaux().moquette_mirroir());
    Plan P_devant(Point3(40.0, 0.0, 0.0), Vector3(-1.0, 0.0, 0.0), Materiaux().moquette_jaune());
    Plan P_gauche(Point3(0.0, 0.0, -12.0), Vector3(0.0, 0.0, 1.0), Materiaux().moquette_bleue());
    Plan P_droite(Point3(13.0, 12.0, 12.0), Vector3(0.0, 0.0, -1.0), Materiaux().moquette_rouge());
    Plan P_haut(Point3(8.0, 8.0, 12.0), Vector3(0.0, -1.0, 0.0), Materiaux().moquette_blanche());
    Plan P_derriere(Point3(-5.0, 8.0, 12.0), Vector3(1.0, 0.0, 0.0), Materiaux().moquette_moche());
    Buble_light Bl(Point3(30.0, 7.0, 0.0), 1);
    BaseEnv env;
    Bl.light_color = Color(0.7, 0.7, 0.7);
    Scene S;

    S.add_object(S1);
    // S.add_object(S2);
    // S.add_object(S3);
    S.add_object(P);
    S.add_object(P_devant);
    S.add_object(P_gauche);
    S.add_object(P_droite);
    S.add_object(P_haut);
    S.add_object(P_derriere);
    S.add_light(Bl);
    S.set_env(env);
    Screen screen;
    screen.S = S;
    screen.pos = Point3(0.0, 0.0, 0.0);
    screen.Render();
    return 0;
}