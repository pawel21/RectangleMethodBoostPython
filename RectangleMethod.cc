#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include "boost/python/extract.hpp"
#include "boost/python/numeric.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace boost::python;

double f(double x)
{
  return x*x;
}

double rectangle_method(double a, double b, int N)
{
  double dx=0;
  dx = (b-a)/N;
  double area = 0;
  for(int i=0; i<N; ++i)
  {
    area = area + f(a + i*dx)*dx;
  }
  return area;
}


BOOST_PYTHON_MODULE(libNumericIntegration)
{
  def("rectangle_method", &rectangle_method);
}
