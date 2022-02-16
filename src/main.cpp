#include "engine/base_engine.hpp"
#include "engine/parallele_engine.hpp"
#include "xml/xml_loader.hpp"
#include <chrono>
int main()
{
    ParalleleEngine engine;
    char name[9] = "data.xml";

    if (load_xml(engine, name) == -1)
    {
        std::cout << "error : unable to load the scene" << std::endl;
        return EXIT_FAILURE;
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    engine.Render();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Temps calcul image : " << elapsed_seconds.count()
              << std::endl;

    return EXIT_SUCCESS;
}