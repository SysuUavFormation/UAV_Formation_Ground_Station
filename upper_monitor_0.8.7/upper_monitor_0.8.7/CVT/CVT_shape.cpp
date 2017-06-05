// CVT_shape.cpp : The creater of CVT function, more details in CVT_shape.hpp
// Author : Junxun Zhong
// Created date : 2016.11.15

#include <iostream>
#include "CVT_shape.hpp"


void Cubic(voro::container &Con) {}

void Tetrahedron(voro::container &Con)
{
    static voro::wall_plane p1(1, 1, 1, 1);
    Con.add_wall(p1);
    static voro::wall_plane p2(-1, -1, 1, 1);
    Con.add_wall(p2);
    static voro::wall_plane p3(1, -1, -1, 1);
    Con.add_wall(p3);
    static voro::wall_plane p4(-1, 1, -1, 1);
    Con.add_wall(p4);
}

void Triangle(voro::container &Con)
{
    static voro::wall_plane p1(0, 0, 1, 0.002);
    Con.add_wall(p1);
    static voro::wall_plane p2(0, 0, -1, 0.002);
    Con.add_wall(p2);
    static voro::wall_plane p3(1, 1, 0, 0);
    Con.add_wall(p3);
//    static voro::wall_plane p4(-1, 1, -1, 1);
//    Con.add_wall(p4);
}

void Square(voro::container &Con)
{
    static voro::wall_plane p1(0, 0, 1, 0.002);
    Con.add_wall(p1);
    static voro::wall_plane p2(0, 0, -1, 0.002);
    Con.add_wall(p2);
}
void Circle(voro::container &Con)
{
    static voro::wall_plane p1(0, 0, 1, 0.002);
    Con.add_wall(p1);
    static voro::wall_plane p2(0, 0, -1, 0.002);
    Con.add_wall(p2);
    static voro::wall_plane p3(1, 1, 0, 1.5);
    Con.add_wall(p3);
    static voro::wall_plane p4(-1, 1, 0, 1.5);
    Con.add_wall(p4);
    static voro::wall_plane p5(-1, -1, 0, 1.5);
    Con.add_wall(p5);
    static voro::wall_plane p6(1, -1, 0, 1.5);
    Con.add_wall(p6);
}

bool CVT_shape(voro::container &Con, const int Shape)
{
    if (Shape < 0)
    {
        return false;
    }
    else if (Shape == CUBIC) //Cubic
    {
        Cubic(Con);
        return true;
    }
    else if (Shape == TETRAHEDRON) //Tetrahedron
    {
        Tetrahedron(Con);
        return true;
    }
    else if (Shape == TRIANGLE) //Triangle
    {
        Triangle(Con);
        return true;
    }
    else if (Shape == SQUARE) //Square
    {
        Square(Con);
        return true;
    }
    else if (Shape == CIRCLE) //Circle
    {
        Circle(Con);
        return true;
    }
    else
    {
        return false;
    }
}
