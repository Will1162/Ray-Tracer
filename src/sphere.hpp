#ifndef WB_RT_SPHERE_HPP
#define WB_RT_SPHERE_HPP

#include "hittable_object.hpp"
#include "vec3.hpp"

class Sphere : public HittableObject
{
	public:
		Point3D centre;
		double radius;
		std::shared_ptr<Material> material;

		Sphere();
		Sphere(Point3D centre, double radius, std::shared_ptr<Material> material);

		virtual bool Hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;
};

#endif