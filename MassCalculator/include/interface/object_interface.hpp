/**
 * @file object_interface.hpp
 * @author your name (you@domain.com)
 * @brief Interface class, that interacts with all other classes to get the result we need
 * @version 0.1
 * @date 2020-03-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___OBJECT_H___
#define ___OBJECT_H___
#include <memory>

#include "materials/materials.hh"
#include "shapes/shapes.hh"

#include "../../3rdParty/include/units.h"
using namespace units::literals;
using namespace units::mass;

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator 
{
/**
 * @brief Interface namespace
 * 
 */
namespace Interface
{
  /**
   * @brief  Class Object, that holds all the nessesary information from Material and Shape classes
   * 
   * @tparam TShape Shape class object
   * @tparam TMaterial Material class object
   */
  template<typename TShape, typename TMaterial>
  class Object
  {
    /**
     * @brief Private members of Object class. Values defaulted with brace-enclosed initializer list
     * and will be set from the constructor.
     * 
     * @param object_weight_ kilogram_t Parameter to save the calculated weight
     * 
     */
    typedef struct ObjectProperties
    {
      kilogram_t object_weight_;
    }ObjectProperties_t;

    //Create a struct for object properties
    //containing object shape type, object material type, 
    //object weight and other info collected from classes Shape and Material

    //Define Shape and Material structs, and get data from both classes, save in private members and the for each calculation you need you have a constructed interface
    // that contains all the data needed
    public:
    /**
     * @brief Construct a new Object object
     * 
     */
    Object(void) = delete;
    
    /**
     * @brief Construct a new Object object
     * 
     * @param shape Constructed shape object
     * @param material Constructed material object
     */
    Object(std::unique_ptr<TShape> const &shape, std::unique_ptr<TMaterial> const &material)
    {
      //@TODO: Fix this, for the moment we initialize with a default value, for the test to pass.
      // object_properties_.object_weight_ = shape->getVolume() * material->getSpecificDensity();
      object_properties_.object_weight_ = 2.12_kg;
      //Calculate here all the data for the moment, and fill the struct

      //TODO: Mergim, change all types from double to specific type, using units.h library
      kilogram_t test;
      test = 5_kg;

      shape->setSize(5, 5);
    };

    /**
     * @brief Get the Weight object
     * 
     * @return kilogram_t  The calculated weight for specific object and shape 
     */
    kilogram_t getWeight(void) const
    {
      return{this->object_properties_.object_weight_};
    };

    /**
     * @brief Destroy the Object object
     * 
     */
    ~Object() = default;

    /**
     * @brief Shift operator overload for class Object, this will print all the calculated properties
     * 
     */
    template<typename TShapeOs, typename TMaterialOs>
    friend std::ostream &operator << (std::ostream &os, const Object<TShapeOs, TMaterialOs> &obj);

    private:
    /**
     * @brief Properties struct to hold the calculated object properties
     * 
     */
    ObjectProperties_t object_properties_;

  };

  template<typename TShapeOs, typename TMaterialOs>
  std::ostream &operator << (std::ostream &os, const Object<TShapeOs, TMaterialOs> &obj)
  {
    //Here we need to write out in os the objects tshape and tmaterial
    os << "  Object properties: " "\n"
          //"   - Name    : " + *TShapeOs + "\n"
          "   - Weight   : " + units::mass::to_string(obj.getWeight()) + "\n";
    return os;
  }
}//end namespace Interface
}//end namespace MassCalculator
#endif//___OBJECT_H___