#ifndef VIEWER_HPP
#define VIEWER_HPP
#include "pointlight.hpp"
#include "scene.hpp"
#include "bitmap_image.hpp"


class Screen : public std::vector<Vector3>
{
    public :
        int width;
        int height;
        Scene S;
        Point3 pos = Point3(0.0,0.0,0.0);
        float distance = 2;
        float pixel_size = 0.002;
        //base de la matrice de pixel dans l'espace (plan v,b et t direction de regard)
        float max_r = 0,max_g = 0,max_b = 0;
        Vector3 t = Vector3(1.0,0.0,0.0), v = Vector3(0.0,1.0,0.0), b = Vector3(0.0,0.0,1.0); 

        Screen(): width(1920),height(1080) 
        { 
            (*this).reserve(width*height);
        };

        Screen(int w, int h) : width(w), height(h) { (*this).reserve(w*h); };
        int nb_pixel(int x,int y)
        {
            return x+width*y;
        }

        void Render()
        {   
            for(int x = 0; x < width; x++)
            {
                for(int y = 0; y< height; y++)
                    (*this)[nb_pixel(x,y)] = get_color(x,y);
            }
            savePicture("result.png");
        }

        void get_pixel(int x,int y, Vector3& pix)
        {
            pix = (*this)[nb_pixel(x,y)];
        }
        
        Vector3 get_color(int x, int y)
        {
            float gx = (float)width*pixel_size/2;
            float gy = (float)height*pixel_size/2;

            Vector3 v_dir = (distance*t- gx*b-gy*v)+x*pixel_size*b+(height-y)*pixel_size*v;
            Ray r(pos,v_dir);
            S.compute(r,0);
            if(r.pix.r() > max_r)
                max_r = r.pix.r();
            if(r.pix.g() > max_g)
                max_g = r.pix.g();
            if(r.pix.b() > max_b)
                max_b = r.pix.b();
            return r.pix.rgb;
        }

        void savePicture( const std::string& filename)
        {
            std::ofstream ofs( filename.c_str(), std::ios::out | std::ios::binary );
            ofs << "P6\n"
                << width << " " << height << "\n255\n";
            
            for ( int i = 0; i < width * height; ++i ) {
                (*this)[i]*= 255;
                unsigned char r = max_r <= 1.0 ? (unsigned char)((int)(*this)[i][0]) : (unsigned char)((int)((*this)[i][0])/max_r) ;
                unsigned char b = max_g <= 1.0 ? (unsigned char)((int)(*this)[i][1]) : (unsigned char)((int)((*this)[i][0])/max_g);
                unsigned char g = max_b <= 1.0 ? (unsigned char)((int)(*this)[i][2]) : (unsigned char)((int)((*this)[i][0])/max_b);

                ofs << r << g << b;
            }
            ofs.close();
        }
        
};


#endif