#ifndef LIGHT_HPP
#define LIGHT_HPP

// In order to call opengl commands in all graphical objects
#include "viewer.hpp"
#include "vector.hpp"

/// Namespace RayTracer
namespace rt {
 
   /// Lights are used to give lights in a scene.
    class Light {
 
        /// Default constructor. Nothing to do.
        Light() {}
    
        /// Virtual destructor since object contains virtual methods.
        virtual ~Light() {}
        
        /// This method is called by Scene::init() at the beginning of the
        /// display in the OpenGL window.
        virtual void init( Viewer& /* viewer */ ) = 0;
    
        /// This method is called by Scene::light() at each frame to
        /// set the lights in the OpenGL window.
        virtual void light( Viewer& /* viewer */ ) = 0;
    
        /// This method is called by Scene::draw() at each frame to
        /// redisplay objects in the OpenGL window.
        virtual void draw( Viewer& /* viewer */) = 0;
    
        /// Given the point \a p, returns the normalized direction to this
        /// light.
        virtual Vector3 direction( const Vector3& /* p */ ) const = 0;
    
        /// @return the color of this light viewed from the given point \a
        /// p.
        virtual Color color( const Vector3& /* p */ ) const = 0;
 
    };
 
} // namespace rt
 
#endif // #define _LIGHT_H_