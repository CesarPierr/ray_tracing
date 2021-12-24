
#ifndef POINTVECTOR_HPP
#define POINTVECTOR_HPP

#include <cmath>
#include <array>
#include<iostream>
#include <assert.h>
template<typename T,std::size_t N>
class PointVector : public std::array<T,N>
{
    public :
    
        PointVector(){}
        PointVector(std::initializer_list<T> L) {
            int i = 0;
            for (auto v : L){
                (*this)[i] = v;
                i++;
            }
        };
        PointVector(T a) {
            if (N > 0){
                (*this)[0] = a;
            }
        };
        PointVector(T a, T b) {
            if (N > 1){
                (*this)[0] = a;
                (*this)[1] = b;
            }
        };
        PointVector(T a, T b, T c) {
            if (N > 2){
                (*this)[0] = a;
                (*this)[1] = b;
                (*this)[2] = c;
            }
        };

        PointVector(T a, T b, T c, T d){
            if (N > 3){
                (*this)[0] = a;
                (*this)[1] = b;
                (*this)[2] = c;
                (*this)[3] = d;
            }
        };

        PointVector(const PointVector<T,N>& pv)
        {
            for(int i =0; i < N ; i++)
                (*this)[i] = pv[i];
        };
        PointVector(const T* vals){
            for ( int i = 0; i < N; i++ ) 
                (*this)[ i ] = *vals++;
        };

        operator T*()
        {
            return this->data(); 
        }
        
        
        operator const T*() const 
        {
            return this->data(); 
        }

        PointVector<T,N>& operator+=(const PointVector<T,N>& other){
            for(int i = 0; i<N; i++){
                (*this)[i] += (other)[i];
            }
            return *this;
        }
        PointVector<T,N>& operator-=( const PointVector<T,N>& other )
        {
            for ( int i = 0; i < N; ++i ) 
                (*this)[ i ] -= other[ i ];
            return *this;
        }
        PointVector<T,N>& operator*=( T val )
        {
            for ( int i = 0; i < N; ++i ) 
                (*this)[ i ] *= val;
            return *this;
        }
        PointVector<T,N>& operator/=( T val )
        {
            for ( int i = 0; i < N; ++i ) 
                (*this)[ i ] /= val;
            return *this;
        }

        T dot( const PointVector<T,N>& other ) const
        {
            T result = 0;
            for ( int i = 0; i < N; ++i ) 
                result += (*this)[ i ] * other[ i ];
            return result;
        }

        PointVector<T,N> vectorial_product( const PointVector<T,N>& other ) const
        {
            assert( N == 3 );
            return PointVector<T,N>( (*this)[1]*other[2] - (*this)[2]*other[1],
                        (*this)[2]*other[0] - (*this)[0]*other[2],
                        (*this)[0]*other[1] - (*this)[1]*other[0] );
        }

        PointVector<T,N> operator+( const PointVector<T,N>& other ) const
        {
            PointVector<T,N> result( *this );
            result += other;
            return result;
        }

        PointVector<T,N> operator-( const PointVector<T,N>& other ) const
        {
            PointVector<T,N> result( *this );
            result -= other;
            return result;
        }

        T norm() const
        {
            return sqrt( dot( *this ) );
        }


        void print(std::ostream & aStream ) const
        {
            aStream << "(";
            for ( int i = 0; i < N; i++ )
                aStream << (*this)[ i ] << ( ( i < N-1 ) ? ',' : ')' );
        }




};

template <typename T, std::size_t N>
std::ostream& operator <<(std::ostream &flux, const PointVector<T,N>& vector)
{
    vector.print(flux);
    return flux;
}


template <typename T, std::size_t N>
PointVector<T,N> operator*( T val, const PointVector<T,N>& PV )
{
    PointVector<T,N> result( PV );
    for ( int i = 0; i < N; ++i ) 
        result[ i ] *= val;
    return result;
}

template <typename T, std::size_t N>
PointVector<T,N> operator*( const PointVector<T,N>& PV, T val )
{
    PointVector<T,N> result( PV );
    for ( int i = 0; i < N; ++i ) 
        result[ i ] *= val;
    return result;
}

template <typename T, std::size_t N>
PointVector<T,N> operator/( T val, const PointVector<T,N>& PV )
{
    PointVector<T,N> result( PV );
    for ( int i = 0; i < N; ++i ) 
        result[ i ] = val / result[ i ];
    return result;
}

template <typename T, std::size_t N>
PointVector<T,N> operator/( const PointVector<T,N>& PV, T val )
{
    PointVector<T,N> result( PV );
    for ( int i = 0; i < N; ++i ) 
        result[ i ] /= val;
    return result;
}

template <typename T, std::size_t N>
inline
T distance2( const PointVector<T,N>& p1, const PointVector<T,N>& p2 )
{
    PointVector<T,N> tmp = p2 - p1;
    return tmp.dot( tmp );
} 

template <typename T, std::size_t N>
inline
T distance( const PointVector<T,N>& p1, const PointVector<T,N>& p2 )
{
    return sqrt( distance2( p1, p2 ) );
} 

typedef PointVector< float, 2 > Vector2;
typedef PointVector< float, 2 > Point2;
/// The type for representing a 3d point.
typedef PointVector< float, 3 > Vector3;
/// The type for representing a 3d vector;
typedef PointVector< float, 3 > Point3;
//4d vector and 4d point
typedef PointVector< float, 4 > Vector4;
typedef PointVector< float, 4 > Point4;

#endif