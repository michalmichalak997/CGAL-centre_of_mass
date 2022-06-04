// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel            Kernel;
typedef Kernel::Point_2                                               Point2;
typedef Kernel::Vector_2                                               Vector2;

struct Point_mass {

    Point2 pos;
    double mass;
    Point_mass(const Point2& p, double m) : pos(p), mass(m) {}
};

Point2 centre_of_mass(Point_mass* cur, Point_mass* beyond) {

    Vector2 sumv(0.0, 0.0);
    double sumw = 0.0;
    for (; cur != beyond; ++cur) {

        sumv = sumv + (cur->pos - CGAL::ORIGIN) * cur->mass;
        sumw += cur->mass;
    }
    return CGAL::ORIGIN + sumv / sumw;
}
int main()
{
    const int N = 4;
    Point_mass points[N] = {
        Point_mass(Point2(3,4), 100),
        Point_mass(Point2(-3,5), 1),
        Point_mass(Point2(2.1,0), 10),
        Point_mass(Point2(7,-12), 1),
    };


    Point2 centre = centre_of_mass(points, points + N);
    std::cout << "The centre of mass is: (" << centre.x() << ", " << centre.y() << ")\n";
}
