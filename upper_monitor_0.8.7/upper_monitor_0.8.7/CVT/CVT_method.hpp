/*******************************
 * CVT_method.hpp : The head file of CVT_method.cpp, contains the main part of the CVT function
 * Function name : CVT_Lloyd_method
 * Parameter :
 *        [Out] Con : The container of CVT function, after the method
 *                           function it will contain the robots inside.
 *        [Out] Out_pos : A vector contains the position of each robot which
 *                                 contains the same number of robots size 3 vector.
 *        [Out] Neigh : A vector contain the neighbors' ID of each robot.
 *        [In] Robot_num : The number of robots.
 * Output : Always output 0.
 *
 * Author : Junxun Zhong
 * Create date : 2016.11.15
 *******************************/

#ifndef CVT_METHOD_HPP
#define CVT_METHOD_HPP

//Use this define  to output the debug message
//#define DEBUG

#include <vector>
#include "voro++/voro++.hh"

int CVT_Lloyd_method(voro::container &Con, std::vector<std::vector<double> > &Out_pos, std::vector<std::vector<int> > &Neigh, const int Robot_num);

//Control the iteration of Lloyd's method
const int Lloyd_iter = 100;

#endif // CVT_METHOD_HPP
