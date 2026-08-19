#include "geometry.hpp"
#include "material.hpp"
#include <vector>
namespace cpw {
struct CPWPair {
  double plus;
  double minus;

  double total() const { return plus + minus; }
};

enum CPWType { ThinFilm, BufferLayer, NoSubstrate };

class CPW {
public:
  CPW(Geometry geometry, double frequency);

  void add_material(const Material &material);
  void validate() const;
  double frequency() const;
  const Geometry &geometry() const;

  CPWType substrate_type() const;

  const std::vector<Material> &materials() const;

private:
  Geometry geometry_;
  double frequency_;
  std::vector<Material> materials_;
};
} // namespace cpw
