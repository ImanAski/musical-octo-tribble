#include "cpw/material.hpp"
#include <string>

namespace cpw {
Material::Material(std::string name, double epsilon_r, double mu_r,
                   double sigma)
    : name_(name), epsilon_r_(epsilon_r), mu_r_(mu_r), sigma_(sigma) {}

double Material::epsilon_r() const { return epsilon_r_; }

std::string Material::name() const { return name_; }

double Material::mu_r() const { return mu_r_; }

double Material::sigma() const { return sigma_; }
} // namespace cpw
