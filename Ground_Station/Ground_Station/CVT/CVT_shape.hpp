/*******************************
 * CVT_shape.hpp : The head file of CVT_shape.cpp, contains the shape creater of CVT function.
 * Function name : CVT_shape
 * Parameter :
 *        [Out] Con : The container of CVT function, after this function
 *                           it will contain the required shape.
 *        [In] Shape : The series number of required shape, more detail
 *                           in CVT_shape.cpp.
 * Output : This function will output true if the parameter meet the
 *               requests, false other wise.
 *
 * Author : Junxun Zhong
 * Created date : 2016.11.15
 *******************************/

#ifndef CVT_SHAPE_HPP
#define CVT_SHAPE_HPP

#include "voro++/voro++.hh"


#define CUBIC 0
#define TETRAHEDRON 1
#define TRIANGLE 2
#define SQUARE 3
#define CIRCLE 4

bool CVT_shape(voro::container &Con, const int Shape);

#endif //CVT_SHAPE_HPP
