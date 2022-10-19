#include "camera.hpp"

Camera::Camera()
{
	auto aspectRatio = 16.0 / 9.0;
	auto viewportHeight = 2.0;
	auto viewportWidth = aspectRatio * viewportHeight;
	auto focalLength = 1.0;

	origin = Point3D(0, 0, 0);
	horizontal = Vec3(viewportWidth, 0, 0);
	vertical = Vec3(0, viewportHeight, 0);
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);
}

Ray Camera::GetRay(double u, double v) const
{
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}