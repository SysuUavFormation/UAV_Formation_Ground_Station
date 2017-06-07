/*******************************
 * CVT project : A project use centroidal voronoi tessellation(CVT) algorithm to compute
 *               location of robots in 3D space, mainly contain a function called CVT.
 * CVT.hpp : The head file of CVT.cpp, contains the main function of CVT project.
 * Function name : CVT
 * Parameter :
 *        [Out] Output : The output of CVT function which will contain the same number
 *                       of robots size3 vector.
 *        [In] Robot_num : The number of robot, don't set it too big, or you should 
 *                         modify the iteration times in CVT_method.hpp to support it.
 *        [In] Position : The centroid of robots position, a size 3 vector.
 *        [In] Shape : The series number of the space shape, more detail in CVT_shape.hpp.
 *        [In] Gap : The minimum distance between two robots.
 * Output : This function will return -1 if Robot_num don't meet the request, return -2 if
 *          Position don't meet the request and so on, return 0 other wise.
 *
 * Author : Junxun Zhong
 * Created date : 2016.11.15
 *******************************/

#ifndef CVT_HPP
#define CVT_HPP

#include <vector>
#include "voro++/voro++.hh"

int CVT(std::vector<std::vector<double> > &Output, const int Robot_num, const std::vector<double> &Position, const int Shape = 0, const double Gap = 1);

#endif //CVT_HPP
