#ifndef RAYON_HPP
#define RAYON_HPP

#include "vector.hpp"

 
namespace ray {
 
   /// object stocking a vector for direction and the origin point
   class Ray {
    
        /// origin of the ray.
        Point3 origin;
        /// unit direction of the ray.
        Vector3 direction;
        /// depth of the ray, i.e. the number of times it can bounce on an object.
        int depth;
        
        /// Default constructor
        Ray() {}
        
        /// Constructor from origin and vector. The vector may not be unitary.
        Ray( const Point3& o, const Vector3& dir, int d = 1 )
        : origin(o), direction(dir), depth(d)
        {
            Real l = direction.norm();
            if ( l != 1.0f ) direction /= l;
        }
   };
 
   
 
 } // namespace rt
 
 #endif 