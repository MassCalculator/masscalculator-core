#ifndef ___OBJECT_H___
#define ___OBJECT_H___
#include <memory>

#include "materials/materials.hh"
#include "shapes/shapes.hh"

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
   * @brief 
   * 
   * @tparam TShape 
   * @tparam TMaterial 
   */
  template<typename TShape, typename TMaterial>
  class Object
  {
    /**
     * @brief 
     * 
     */
    struct ObjectProperties
    {
      double object_weight_;
    }object_properties_;

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
     * @param shape 
     * @param material 
     */
    Object(std::unique_ptr<TShape> const &shape, std::unique_ptr<TMaterial> const &material)
    {
      object_properties_.object_weight_ = shape->getVolume() * material->getSpecificDensity();
      //Calculate here all the data for the moment, and fill the struct

      shape->setSize(5, 5);
    };

    /**
     * @brief Get the Weight object
     * 
     * @return double 
     */
    double getWeight(void) const
    {
      return{object_properties_.object_weight_};
    };

    /**
     * @brief Destroy the Object object
     * 
     */
    ~Object() = default;

    /**
     * @brief 
     * 
     * @param os 
     * @param obj 
     * @return std::ostream& 
     */
    template<typename TShapeOs, typename TMaterialOs>
    friend std::ostream &operator << (std::ostream &os, const Object<TShapeOs, TMaterialOs> &obj)
    {
      //Here we need to write out in os the objects tshape and tmaterial
      os << "  Object properties: " "\n"
            //"   - Name    : " + *TShapeOs + "\n"
            "   - Weight   : " + std::to_string(obj.getWeight()) + "\n";
      return os;
    }

  };
}//end namespace Interface
}//end namespace MassCalculator
#endif