#pragma once
#include <vector>
#include "Sphere.h"
#include "Plane.h"
#include "Ray.h"

class Scene
{
public:
    std::vector<Sphere> spheres;
    std::vector<Plane> planes;

    void addSphere(const Sphere &sphere)
    {
        spheres.push_back(sphere);
    }

    void addPlane(const Plane &plane)
    {
        planes.push_back(plane);
    }

    bool trace(const Ray &ray, float &t, int &id, bool &isSphere) const
    {
        t = 1e20;
        bool hit = false;
        isSphere = false;

        for (size_t i = 0; i < spheres.size(); ++i)
        {
            float d;
            if (spheres[i].intersect(ray, d) && d < t)
            {
                t = d;
                id = i;
                hit = true;
                isSphere = true;
            }
        }

        for (size_t i = 0; i < planes.size(); ++i)
        {
            float d;
            if (planes[i].intersect(ray, d) && d < t)
            {
                t = d;
                id = i;
                hit = true;
                isSphere = false;
            }
        }

        return hit;
    }
};