#ifndef WB_RT_VEC3_HPP
#define WB_RT_VEC3_HPP

#include <cmath>

class Vec3
{
	public:
		float x, y, z;

		Vec3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		~Vec3(){};

		Vec3& operator+=(const Vec3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vec3& operator*=(const double t)
		{
			x *= t;
			y *= t;
			z *= t;
			return *this;
		}

		Vec3& operator/=(const double t)
		{
			return *this *= 1 / t;
		}

		double length() const
		{
			return sqrt(length_squared());
		}

		double length_squared() const
		{
			return x * x + y * y + z * z;
		}
};

using Point3D = Vec3;
using Colour = Vec3;

inline Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vec3 operator*(double t, const Vec3 &v)
{
	return Vec3(t * v.x, t * v.y, t * v.z);
}

inline Vec3 operator*(const Vec3 &v, double t)
{
	return t * v;
}

inline Vec3 operator/(Vec3 v, double t)
{
	return (1 / t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v)
{
	return u.x * v.x
		 + u.y * v.y
		 + u.z * v.z;
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x);
}

inline Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}

#endif