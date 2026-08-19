#include "cpw/geometry.hpp"

namespace cpw {
Geometry::Geometry(double s_minus, double s_plus, double wg_minus,
                   double wg_plus, double w, double h1, double h2, double t)
    : s_minus_(s_minus), s_plus_(s_plus), wg_minus_(wg_minus),
      wg_plus_(wg_plus), w_(w), t_(t), h_(h1), h2_(h2) {}

double Geometry::s_plus() const { return s_plus_; }

double Geometry::s_minus() const { return s_minus_; }

double Geometry::s_total() const { return s_minus_ + s_plus_; }
double Geometry::wg_plus() const { return wg_plus_; }
double Geometry::wg_minus() const { return wg_minus_; }

double Geometry::thickness() const { return t_; }
double Geometry::width() const { return w_; }

double Geometry::height() const { return h_; }
double Geometry::h2() const { return h2_; }
} // namespace cpw
