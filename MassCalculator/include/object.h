#ifndef ___OBJECT_H___
#define ___OBJECT_H___
#include <iostream>

#include "materials/aluminium.h"
#include "shapes/cylinder.h"

#include <memory>

namespace MassCalculator 
{
namespace Interface
{
  template<typename TShape, typename TMaterial>
  class Object
  {
    public:
    Object(void) = delete;
    
    Object(std::shared_ptr<TShape> shape, std::shared_ptr<TMaterial> material)
    {
      weight_ = shape->getMass() * material->getSpecificMass();

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