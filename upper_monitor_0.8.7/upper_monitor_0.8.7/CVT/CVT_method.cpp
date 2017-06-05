// CVT_method.cpp : The main part of CVT function, more details in CVT_method.hpp
// Author : Junxun Zhong
// Created date : 2016.11.15

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "CVT_method.hpp"

//Remember to change this function when you change the size of container
double rnd() {return double(rand()) / RAND_MAX * 2 - 1;}

int CVT_Lloyd_method(voro::container &Con, std::vector<std::vector<double> > &Out_pos, std::vector<std::vector<int> > &Neigh, const int Robot_num)
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < Robot_num; i++)
    {
        double x, y, z;

        do
        {
            x = rnd();
            y = rnd();
            z = rnd();
        }while (!Con.point_inside(x, y, z));

        Out_pos[i][0] = x;
        Out_pos[i][1] = y;
        Out_pos[i][2] = z;

        Con.put(i, x, y, z);

//The variable DEBUG is defined in CVT_method.hpp
#ifdef DEBUG
        std::cout << "Put " << i + 1 << " points." << "\n";
        std::cout << "pos: x=" << x << ", y=" << y << ", z=" << z << "\n";
#endif //DEBUG
    }

#ifdef DEBUG
    std::cout << "Lloyd's method's iniaialization finished." << "\n";
#endif //DEBUG

    for (int iter = 0; iter < Lloyd_iter; iter++)
    {
        voro::c_loop_all cl(Con);
        voro::voronoicell_neighbor vcn;

        if (cl.start())
        {
            do
            {
                if (Con.compute_cell(vcn, cl))
                {
                    int temp = cl.pid();
                    vcn.centroid(Out_pos[temp][0], Out_pos[temp][1], Out_pos[temp][2]);

                    //The following three sentences is used to fix the bug of voro++
                    Out_pos[temp][0] += cl.x();
                    Out_pos[temp][1] += cl.y();
                    Out_pos[temp][2] += cl.z();

                    vcn.neighbors(Neigh[temp]);
                }
#ifdef DEBUG
                else
                {
                    std::cout << "Can not compute the voronoicell in iter" << iter << ".\n";
                }
#endif //DEBUG
            }while (cl.inc());
        }
#ifdef DEBUG
        else
        {
            std::cout << "The container has no particle in iter" << iter << ".\n";
        }
#endif //DEBUG

        Con.clear();

        for (int i = 0; i < Robot_num; i++)
        {
            Con.put(i, Out_pos[i][0], Out_pos[i][1], Out_pos[i][2]);
        }
    }

#ifdef DEBUG
    std::cout << "Lloyd's method is finished." << "\n";
    Con.draw_particles("particles.gnu");
    Con.draw_cells_gnuplot("voronoicells.gnu");
#endif // DEBUG

    return 0;
}
