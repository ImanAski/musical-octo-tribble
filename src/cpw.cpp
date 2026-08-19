#include "cpw/cpw.hpp"
#include "cpw/geometry.hpp"

#include <stdexcept>

namespace cpw {
CPW::CPW(Geometry geometry, double frequency)
    : geometry_(std::move(geometry)), frequency_(frequency) {}

void CPW::add_material(const Material &material) {
  materials_.push_back(material);
}

void CPW::validate() const {
  if (geometry_.width() <= 0) {
    throw std::invalid_argument("CPW Width must be positive");
  }

  if (geometry_.thickness() <= 0) {
    throw std::invalid_argument("CPW conductor thickness must be positive");
  }

  if (geometry_.height() <= 0)
    throw std::invalid_argument(
        "Height of the first material must be positive");

  if (materials_.empty())
    throw std::invalid_argument("CPW requires at least one material");
}

double CPW::frequency() const { return frequency_; }

const Geometry &CPW::geometry() const { return geometry_; }

CPWType CPW::substrate_type() const {
  if (materials_.size() < 2)
    return CPWType::NoSubstrate;

  const auto &m1 = materials_[0];
  const auto &m2 = materials_[1];

  if (m1.epsilon_r() > m2.epsilon_r())
    return CPWType::BufferLayer;

  if (m1.epsilon_r() < m2.epsilon_r())
    return CPWType::ThinFilm;

  return CPWType::NoSubstrate;
}

const std::vector<Material> &CPW::materials() const { return materials_; }

} // namespace cpw
