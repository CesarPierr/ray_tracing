#include "utils/color.hpp"

Color::Color() : rgb(0.0, 0.0, 0.0){};
Color::Color(float red, float green, float blue) : rgb(red, green, blue)
{
    normalize();
};

Color Color::operator*(float v) const
{
    Color tmp(*this);
    tmp.rgb[0] *= v;
    tmp.rgb[1] *= v;
    tmp.rgb[2] *= v;
    return tmp;
}

Color Color::operator*(const Color &c) const
{
    Color tmp(*this);
    tmp.rgb[0] *= c.rgb[0];
    tmp.rgb[1] *= c.rgb[1];
    tmp.rgb[2] *= c.rgb[2];
    return tmp;
}

Color Color::operator+(const Color &c) const
{
    Color tmp(*this);
    tmp.rgb[0] += c.rgb[0];
    tmp.rgb[1] += c.rgb[1];
    tmp.rgb[2] += c.rgb[2];
    return tmp;
}

Color &Color::operator+=(Color c)
{
    *this = *this + c;
    return *this;
}

// set values between 0 and 1 to the TSV conversion
Color &Color::normalize()
{
    rgb[0] = std::max(0.0f, std::min(1.0f, rgb[0]));
    rgb[1] = std::max(0.0f, std::min(1.0f, rgb[1]));
    rgb[2] = std::max(0.0f, std::min(1.0f, rgb[2]));
    return *this;
}
Color Color::sup(Color other) const
{
    other.rgb[0] = std::max((*this).rgb[0], other.rgb[0]);
    other.rgb[1] = std::max((*this).rgb[1], other.rgb[1]);
    other.rgb[2] = std::max((*this).rgb[2], other.rgb[2]);
    return other;
}

// TSV  = teinte saturation valeur, perception system of colors by humans
//  v = brillance de la couleur, t = teinte, s = saturation/ intensité de la couleur
void Color::getTSV(int &t, float &s, float &v) const
{
    // set value
    v = max();
    // set saturation
    s = max() == 0.0 ? 0.0 : 1.0 - min() / max();
    // set teinte :
    if (max() == min())
        t = 0;
    else if (r() >= g() && r() >= b())
        t = (int)(60 * (g() - b()) / (max() - min()) + 360) % 360;
    else if (g() >= r() && g() >= b())
        t = (int)(60 * (b() - r()) / (max() - min()) + 120);
    else
        t = (int)(60 * (r() - g()) / (max() - min()) + 240);
}

void Color::setTSV(int t, float s, float v)
{
    int ti = (t / 60) % 6;
    float f = ((float)t / 60) - ti;
    float l = v * (1 - s);
    float m = v * (1 - f * s);
    float n = v * (1 - (1 - f) * s);
    switch (ti)
    {
    case 0:
        r() = v;
        g() = n;
        b() = l;
        break;
    case 1:
        r() = m;
        g() = v;
        b() = l;
        break;
    case 2:
        r() = l;
        g() = v;
        b() = n;
        break;
    case 3:
        r() = l;
        g() = m;
        b() = v;
        break;
    case 4:
        r() = n;
        g() = l;
        b() = v;
        break;
    case 5:
        r() = v;
        g() = l;
        b() = m;
        break;
    }
}

Color operator*(float v, const Color &c)
{
    Color tmp(c);
    return tmp * v;
}

float Distance(const Color &c1, const Color &c2)
{
    return std::max(std::fabs(c1.r() - c2.r()), std::max(std::fabs(c1.g() - c2.g()), std::fabs(c1.b() - c2.b())));
}