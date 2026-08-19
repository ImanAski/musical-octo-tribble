#pragma once
#include <string>
namespace cpw {
class Material {
public:
  Material(std::string name, double epsilon_r, double mu_r, double sigma);
  std::string name() const;
  double epsilon_r() const;
  double mu_r() const;
  double sigma() const;

private:
  std::string name_;
  double epsilon_r_;
  double mu_r_;
  double sigma_;
};

} // namespace cpw
