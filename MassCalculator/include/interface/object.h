#ifndef ___OBJECT_H___
#define ___OBJECT_H___
#include <memory>

#include "materials/materials.hh"
#include "shapes/shapes.hh"

namespace MassCalculator 
{
namespace Interface
{
  template<typename TShape, typename TMaterial>
  class Object
  {
    public:
    Object(void) = delete;
    
    Object(std::unique_ptr<TShape> const &shape, std::unique_ptr<TMaterial> const &material)
    {
      weight_ = shape->getMass() * material->getSpecificDensity();

      shape->setSize(5, 5);
    };

    double getWeight() const
    {
      return{weight_};
    };

    ~Object() = default;

    private:
    double weight_;
  };
}//end namespace Interface
}//end namespace MassCalculator
#endif