#include "engine/base_engine.hpp"

void BaseEngine::Render()
{

    int avancement = 0;
    {
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                (*this)[nb_pixel(x, y)] = get_color(x, y);
                ++avancement;
                std::cout << "avancement : " << 100 * avancement / (width * height) << " %" << std::endl;
            }
        }
    }
    savePicture("result.png");
}