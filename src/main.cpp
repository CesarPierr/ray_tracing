
#include "viewer.hpp"
#include "xml/xml_loader.hpp"

int main()
{
    Screen screen;
    char name[9] = "data.xml";

    if (load_xml(screen, name) == -1)
    {
        std::cout << "error : unable to load the scene" << std::endl;
        return EXIT_FAILURE;
    }
    /*Sphere S1(Point3(26.0, 4.0, 4.0), 3, Materiaux().glass());
    Sphere S2(Point3(35.0, -2.0, 0.0), 3, Materiaux().emerald_green());
    Sphere S3(Point3(35.0, 4.0, -4), 3, Materiaux().emerald_red());

    Plan P(Point3(0.0, -5.0, 0.0), Vector3(0.0, 1.0, 0.0), Materiaux().moquette_moche());
    Plan P_devant(Point3(45.0, 0.0, 0.0), Vector3(-1.0, 0.0, 0.0), Materiaux().moquette_jaune());
    Plan P_gauche(Point3(0.0, 0.0, -12.0), Vector3(0.0, 0.0, 1.0), Materiaux().moquette_mirroir());
    Plan P_droite(Point3(13.0, 12.0, 12.0), Vector3(0.0, 0.0, -1.0), Materiaux().moquette_rouge());
    Plan P_haut(Point3(8.0, 8.0, 12.0), Vector3(0.0, -1.0, 0.0), Materiaux().moquette_blanche());
    Plan P_derriere(Point3(-5.0, 8.0, 12.0), Vector3(1.0, 0.0, 0.0), Materiaux().moquette_moche());
    Buble_light Bl(Point3(30.0, 7.0, 0.0), 1);
    BaseEnv env;
    Bl.light_color = Color(0.7, 0.7, 0.7);

    S.add_object(S1);
    S.add_object(S2);
    S.add_object(S3);
    S.add_object(P);
    S.add_object(P_devant);
    S.add_object(P_gauche);
    S.add_object(P_droite);
    S.add_object(P_haut);
    S.add_object(P_derriere);
    S.add_light(Bl);
    S.set_env(env);*/

    //    screen.pos = Point3(0.0, 0.0, 0.0);
    std::cout << screen.S.l_objets.size() << std::endl;
    for (int i = 0; i < screen.S.l_lumieres.size(); i++)
    {
        std::cout << screen.S.l_lumieres[i] << std::endl;
    }

    screen.Render();

    return EXIT_SUCCESS;
}