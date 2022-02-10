#include "viewer.hpp"

Screen::Screen()
{
    (*this).reserve(width * height);
};

Screen::Screen(int w, int h) : width(w), height(h) { (*this).reserve(w * h); };

int Screen::nb_pixel(int x, int y)
{
    return x + width * y;
}

void Screen::Render()
{
    int avancement = 0;
#pragma omp parallel shared(avancement) num_threads(8)
    {
#pragma omp for
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                (*this)[nb_pixel(x, y)] = get_color(x, y);
                ++avancement;
                //std::cout << "avancement : " << 100 * avancement / (width * height) << " %" << std::endl;
            }
        }
    }
    savePicture("result.png");
}

void Screen::get_pixel(int x, int y, Vector3 &pix)
{
    pix = (*this)[nb_pixel(x, y)];
}

Vector3 Screen::get_color(int x, int y)
{
    float gx = (float)width * pixel_size / 2;
    float gy = (float)height * pixel_size / 2;
    float dx,dy;
    Vector3 c(0.0,0.0,0.0);
    Vector3 v_dir;
    Ray r;
    for(int k =0; k< antialliasing; k++)
    {
        dx = random_double();
        dy = random_double();
        v_dir = (distance * t - (gx+dx) * b - (gy+dy) * v) + x * pixel_size * b + (height - y) * pixel_size * v;
        r = Ray(pos, v_dir);
        S.compute(r, 0);
        c+= r.pix.rgb;
    }
    return c*(1/(float)antialliasing);
}

void Screen::savePicture(const std::string &filename)
{
    std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::binary);
    ofs << "P6\n"
        << width << " " << height << "\n255\n";

    for (int i = 0; i < width * height; ++i)
    {
        float exposure = -5.0f;
        (*this)[i][0] = 1.0f - expf((*this)[i][0] * exposure);
        (*this)[i][1] = 1.0f - expf((*this)[i][1] * exposure);
        (*this)[i][2] = 1.0f - expf((*this)[i][2] * exposure);
        (*this)[i] *= 254;
        unsigned char r = (unsigned char)((int)(*this)[i][0]);
        unsigned char g = (unsigned char)((int)(*this)[i][1]);
        unsigned char b = (unsigned char)((int)(*this)[i][2]);

        ofs << r << g << b;
    }
    ofs.close();
}