#pragma once

namespace cpw {
class Geometry {
public:
  Geometry(double s_minus, double s_plus, double wg_minus, double wg_plus,
           double w, double h1, double h2, double t);

  double s_plus() const;
  double s_minus() const;
  double s_total() const;
  double wg_plus() const;
  double wg_minus() const;

  double thickness() const;
  double width() const;

  double height() const;
  double h2() const;

private:
  double s_minus_;
  double s_plus_;
  double wg_minus_;
  double wg_plus_;
  double w_;
  double t_;
  double h_;
  double h2_;
};
} // namespace cpw
