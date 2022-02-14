#ifndef COLOR_HPP
#define COLOR_HPP
#include "pointVector.hpp"

class Color
{
public:
    Vector3 rgb;
    Color();
    Color(float red, float green, float blue);

    float r() const { return rgb[0]; }
    float g() const { return rgb[1]; }
    float b() const { return rgb[2]; }
    float &r() { return rgb[0]; }
    float &g() { return rgb[1]; }
    float &b() { return rgb[2]; }

    Color operator*(float v) const;

    Color operator*(const Color &c) const;

    Color operator+(const Color &c) const;

    Color &operator+=(Color c);

    // set values between 0 and 1 to the TSV conversion
    Color &normalize();
    Color sup(Color other) const;

    float max() const { return std::max(std::max(r(), g()), b()); }
    float min() const { return std::min(std::min(r(), g()), b()); }
    float s, v;
    int t;
    // TSV  = teinte saturation valeur, perception system of colors by humans
    //  v = brillance de la couleur, t = teinte, s = saturation/ intensité de la couleur
    void getTSV(int &t, float &s, float &v) const;

    void setTSV(int t, float s, float v);
};

Color operator*(float v, const Color &c);

float Distance(const Color &c1, const Color &c2);

#endif