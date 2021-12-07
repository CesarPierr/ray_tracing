#ifndef GRAPHICAL_OBJECT_HPP
#define GRAPHICAL_OBJECT_HPP

// In order to call opengl commands in all graphical objects
#include "viewer.hpp"
#include "vector.hpp"
#include "materiaux.hpp"
#include "rayon.hpp"
 
/// Namespace RayTracer
namespace rt {

    class GraphicalObject {
 
        /// Default constructor. Nothing to do.
        GraphicalObject() {}
    
        /// Virtual destructor since object contains virtual methods.
        virtual ~GraphicalObject() {}
    

        virtual void init( Viewer& /* viewer */ ) = 0;

        virtual void draw( Viewer& /* viewer */ ) = 0;

        virtual Vector3 getNormal( Point3 p ) = 0;
    

        virtual Material getMaterial( Point3 p ) = 0;
    
        virtual Real rayIntersection( const Ray& ray, Point3& p ) = 0;
                        
    
    };

} // namespace rt

#endif // #define _GRAPHICAL_OBJECT_H_