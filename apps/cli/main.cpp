#include "cpw/cpw.hpp"
#include "cpw/geometry.hpp"
#include "cpw/material.hpp"

#include <iostream>
#include <vector>

int main() {

  // cp := cpw.NewCPW(cpw.Geometry{
  // 	SMinus:  15e-6,
  // 	SPlus:   15e-6,
  // 	WGMinus: 100e-6,
  // 	WGPlus:  100e-6,
  // 	W:       8e-6,
  // 	H:       50e-6,
  // 	H2:      1.5e-6,
  // 	T:       10e-6,
  // }, 20e9)
  cpw::Geometry geo(15e-6, 15e-6, 100e-6, 100e-6, 8e-6, 50e-6, 1.5e-6, 10e-6);
  cpw::CPW cp(geo, 20e9);

  cpw::Material cu("Copper", 1.0, 0.999994, 5.96e7);
  cpw::Material al("Aliminum", 1.0, 0.999994, 5.96e7);

  cp.add_material(cu);
  cp.add_material(al);

  cp.validate();

  for (cpw::Material m : cp.materials()) {
    std::cout << m.name() << "\n";
  }
  return 0;
}
