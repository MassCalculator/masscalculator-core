/**
 * @file material.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This class is the base class for the Materials, this will be inherited from all the Material types, and holds the prototypes
 * so the derived classes can be accessed from it's object pointer
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <iostream>

#include "../../helper_functions/helper_functions.hpp"
using namespace MassCalculator::HelperFunctions;

#include "../../helper_classes/lua_handler.hpp"
using namespace MassCalculator::HelperClasses;

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  namespace Constants
  {
    //Material type constants
    const std::string  AlloyCoppers{"AlloyCoppers"};
    const std::string  AlloySteels{"AlloySteels"};
    const std::string  Aluminium{"Aluminium"};
    const std::string  Brass{"Brass"};
    const std::string  Bronz{"Bronz"};
    const std::string  Copper{"Copper"};
    const std::string  Magnesium{"Magnesium"};
    const std::string  Nickel{"Nickel"};
    const std::string  Plastic{"Plastic"};
    const std::string  StainlessSteel{"StainlessSteel"};
    const std::string  Steel{"Steel"};
    const std::string  Titanium{"Titanium"};
    const std::string  UNSPECIFIED{"UNSPECIFIED"};

    //Color constants
    const std::string  Metallic{"Metallic"};
    const std::string  DarkTone{"DarkTone"};
  }

  /**
   * @brief Template base class Material
   * 
   */
  template<typename TMaterialType>
  class Material 
  {
    public: enum class Type : uint8_t;

    struct Properties;

    public:
    /**
     * @brief Construct a new Material object
     * 
     */
    Material(void) = default;

    /**
     * @brief Construct a new Material object
     * 
     * @param type Type of the Material
     */
    Material(Type type)
    {
      static_cast<TMaterialType*>(this)(type);
    }

    /**
     * @brief Init the Lua config file
     * 
     */
    bool initLuaScript()
    {
      static_cast<TMaterialType*>(this)->initLuaScript();
      return true;
    }

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Material
     * @return true If the type is set successfully
     * @return false If the type failed to set
     */
    bool setType(Type type)
    {
      static_cast<TMaterialType*>(this)->setType(type);
      return true;
    }

    /**
     * @brief Get the Type object
     * 
     * @return const std::pair<std::string, Type> Pair with type name and type enum from Derived class
     */
    constexpr std::pair<std::string, Type> getType(void)
    {
      return{static_cast<TMaterialType*>(this)->getType()};
    }

    /**
     * @brief Get the Specific Color object
     * 
     * @return const std::string Color of the material from Derived class
     */
    constexpr std::string getSpecificColor(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificColor()};
    }

    /**
     * @brief Get the Specific Density object
     * 
     * @return const double Density of the material from Derived class
     */
    constexpr double getSpecificDensity(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificDensity()};
    }

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return const double Gravity of the material from Derived class
     */
    constexpr double getSpecificGravity(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificGravity()};
    }

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return const double The specific melting point of Material type from Derived class
     */
    constexpr double getSpecificMeltingPoint(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificMeltingPoint()};
    }

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Material type from Derived class
     */
    constexpr double getSpecificPoissonsRatio(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificPoissonsRatio()};
    }

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return double The specific thermal conductivity of Material type from Derived class
     */
    constexpr double getSpecificThermalConductivity(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificThermalConductivity()};
    }

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return const double The specific modulus of elasticity tension point of Material type from Derived class
     */
    constexpr double getSpecificModOfElasticityTension(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificModOfElasticityTension()};
    }

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return const double The specific modulus of elasticity torsion point of Material type from Derived class
     */
    constexpr double getSpecificModOfElasticityTorsion(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificModOfElasticityTorsion()};
    }

    /**
     * @brief Destroy the Material object
     * 
     */
    ~Material(void) = default;

    /**
     * @brief Shift operator template overload, for the base class Material
     * 
     */
    template <typename TMaterial>
    friend std::ostream &operator << (std::ostream &os, const Material<TMaterialType> &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Material(const Material&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    public: Material(Material&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Material& operator=(const Material&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Material& operator=(Material&&) = default;

    /**
     * @brief Function to return "this" derived object
     * 
     * @return const TMaterialType& 
     */
    const TMaterialType& thisTMaterialType() const { return *static_cast<const TMaterialType*>(this); }

  };

  //Specialisation
  // template <>
  // class Material<int> { };

  template <typename TMaterial>
  std::ostream &operator << (std::ostream &os, const Material<TMaterial> &obj)
  {
    //TODO: This causes segmentation fault, it works if you comment out headers in materials.hh and you move implementation in the class
    os << "\n" "Material" "\n" << obj.thisTMaterialType();
    return os;
  }

}//end namespace MassCalculator
#endif
