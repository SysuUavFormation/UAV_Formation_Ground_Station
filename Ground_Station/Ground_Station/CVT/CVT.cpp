// CVT.cpp : The funciton use centroidal voronoi tessellation(CVT) algorithm to
//           compute location of robots in 3D space, more details in CVT.cpp
// Author : Junxun Zhong
// Created date : 2016.11.15 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "CVT.hpp"
#include "CVT_method.hpp"
#include "CVT_shape.hpp"

//If you change the following parameter, remember to change the shape parameter in CVT_shape.cpp
// and the function rnd() in CVT_method.cpp
const double x_min = -1, x_max = 1;
const double y_min = -1, y_max = 1;
const double z_min = -1, z_max = 1;

const int x_n = 10, y_n = 10, z_n = 10;

//This function is used to shift the robots postion to the Position and meet the request of minimum distance Gap
inline void CVT_shift(std::vector<std::vector<double> > &Output, const std::vector<std::vector<int> > &Neigh, const std::vector<double> &Position, const double Gap);

int CVT(std::vector<std::vector<double> > &Output, const int Robot_num, const std::vector<double> &Position, const int Shape, const double Gap)
{

//The variable DEBUG is defined in CVT_method.hpp
#ifdef DEBUG
    std::cout << "CVT start." << "\n";
#endif //DEBUG

    if (Robot_num <= 0)
    {
        return -1;
    }

#ifdef DEBUG
    std::cout << "Robot_num pass." << "\n";
#endif //DEBUG

    if (Position.size() != 3)
    {
        return -2;
    }

#ifdef DEBUG
    std::cout << "Position pass." << "\n";
#endif //DEBUG

    if (Gap <= 0)
    {
        return -4;
    }

#ifdef DEBUG
    std::cout << "Gap pass." << "\n";
#endif //DEBUG

    voro::container con(x_min, x_max, y_min, y_max, z_min, z_max, x_n, y_n, z_n, false, false, false, 10);
    if (!CVT_shape(con, Shape))
    {
        return -3;
    }

#ifdef DEBUG
    std::cout << "Shape pass." << "\n";
#endif // DEBUG

    Output.clear();
    Output.resize(Robot_num);
    for (int i = 0; i < Robot_num; i++)
    {
        Output[i].resize(3);
    }
    std::vector<std::vector<int> > neigh;
    neigh.resize(Robot_num);

#ifdef DEBUG
    std::cout << "Start main function." << "\n";
#endif //DEBUG

    CVT_Lloyd_method(con, Output, neigh, Robot_num);

#ifdef DEBUG
    std::cout << "Main function finished." << "\n";
#endif //DEBUG

    CVT_shift(Output, neigh, Position, Gap) ;

#ifdef DEBUG
    std::cout << "CVT finished." << "\n";
#endif //DEBUG

    return 0;

}

inline void CVT_shift(std::vector<std::vector<double> > &Output, const std::vector<std::vector<int> > &Neigh, const std::vector<double> &Position, const double Gap)
{
    double shortest_dis = 25;

    for (int i = 0; i < Neigh.size(); i++)
    {
        //std::sort(Neigh[i].begin(), Neigh[i].end());
        for (int j = Neigh[i].size() - 1; j >= 0; j--)
        {
            if (Neigh[i][j] > i)
            {
                int k = Neigh[i][j];
                double dis = pow(Output[i][0] - Output[k][0], 2)
                                     + pow(Output[i][1] - Output[k][1], 2)
                                     + pow(Output[i][2] - Output[k][2], 2);
                if (dis < shortest_dis)
                {
                    shortest_dis = dis;
                }
            }
        }
    }

    double frac = Gap / sqrt(shortest_dis);

    for (int i = 0; i < Output.size(); i++)
    {
        Output[i][0] = frac * Output[i][0] + Position[0];
        Output[i][1] = frac * Output[i][1] + Position[1];
        Output[i][2] = frac * Output[i][2] + Position[2];
    }

#ifdef DEBUG
    std::cout << "CVT_nearest finished. frac = " << frac << "\n";
#endif //DEBUG

}
