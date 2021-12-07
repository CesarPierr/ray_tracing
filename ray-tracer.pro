
# Ceci est un fichier de configuration pour une application Qt
# Il faut peut-etre legerement l adapter pour votre ordinateur.

# nom de votre executable
TARGET  = ray-tracer
# config de l executable
CONFIG *= qt opengl release
CONFIG += c++11
# config de Qt
QT     *= opengl xml
QMAKE_CXXFLAGS += -std=c++11

# Noms de vos fichiers entete
HEADERS = viewer.hpp vector.hpp color.hpp sphere.hpp graphicalobject.hpp light.hpp \
        materiaux.hpp pointlight.hpp image2D.hpp image2Dwriter.hpp renderer.hpp rayon.hpp
        
# Noms de vos fichiers source
SOURCES = viewer.cpp raytracer.cpp sphere.cpp 

###########################################################
# Commentez/decommentez selon votre config/systeme
# (Une config windows est possible)
###########################################################

# Exemple de configuration Linux Ubuntu 16.04, Qt5 et libQGLViewer
INCLUDEPATH *= /usr/include
LIBS *= -L/usr/lib/x86_64-linux-gnu -lQGLViewer

# Exemple de configuration MacOSX avec macports
## INCLUDEPATH *= /opt/local/include
## LIBS *= -L/opt/local/lib -lQGLViewer 

# Exemple de configuration MacOSX avec frameworks
##  INCLUDEPATH *= /Users/login/libQGLViewer-2.6.4
##  LIBS *= -F/Users/login/Library/Frameworks -framework QGLViewer