#include "objet/triangle.hpp"
Triangle::Triangle() : A(Point3(0.0, 0.0, 0.0)), B(Point3(0.0, 0.0, 0.0)), C(Point3(0.0, 0.0, 0.0)) { normale = (B - A).vectorial_product(C - A); }

Triangle::Triangle(Point3 a, Point3 b, Point3 c) : A(a), B(b), C(c){};
Triangle::Triangle(Point3 a, Point3 b, Point3 c, Materiaux m) : A(a), B(b), C(c)
{
    mat = m;
    normale = (B - A).vectorial_product(C - A);
};
void Triangle::maj_normal()
{
    normale = (B - A).vectorial_product(C - A);
}
float Triangle::get_inter(const Ray &r, Point3 &test, Vector3 &norm)
{
    Point3 projete = r.src - normale.dot(r.src - A) * normale;
    if (r.dir.dot(projete - r.src) < 0)
    {
        // std::cout << "salut" << std::endl;
        return -1;
    }
    else
    {
        normale /= normale.norm();
        float distance_Triangle = normale.dot(r.src - A);
        float t = -distance_Triangle / (r.dir.dot(normale));
        test = r.src + t * r.dir;
        Vector3 QA = A - test, QB = B - test, QC = C - test;
        Vector3 n1 = QA.vectorial_product(QB);
        Vector3 n2 = QB.vectorial_product(QC);
        Vector3 n3 = QC.vectorial_product(QA);
        if (n1.dot(n2) < 0 || n2.dot(n3) < 0)
            return -1;
        norm = normale;
        return t;
    }
}

Materiaux Triangle::get_mat(const Point3 &p)
{
    return mat;
}
Ray Triangle::get_refracted_ray(const Ray &inc_ray, Point3 p, const Vector3 &normale)
{
    // std::cout << p << std::endl;
    Ray refract(inc_ray);
    refract.src = p + 0.001f * inc_ray.dir;
    return refract;
}
void Triangle::get_xml(pugi::xml_node pl)
{
    pugi::xml_node a = pl.child("A");
    float x = atof(a.child("x").child_value());
    float y = atof(a.child("y").child_value());
    float z = atof(a.child("z").child_value());
    A = Point3(x, y, z);

    pugi::xml_node b = pl.child("B");
    x = atof(b.child("x").child_value());
    y = atof(b.child("y").child_value());
    z = atof(b.child("z").child_value());
    B = Point3(x, y, z);

    pugi::xml_node c = pl.child("C");
    x = atof(c.child("x").child_value());
    y = atof(c.child("y").child_value());
    z = atof(c.child("z").child_value());
    C = Point3(x, y, z);

    maj_normal();

    const char *mat_name = pl.child("Materiaux").child_value();
    this->mat = Materiaux().get_existing_mat(mat_name);
}
