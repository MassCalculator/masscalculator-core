/**
 * @file material.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This class is the base class for the Materials, this will be inherited from all the Material types, and holds the prototypes
 * so the derived classes can be accessed from it's object pointer
 * @version 0.2
 * @date 2020-03-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <iostream>
#include <functional>
#include <unordered_map>

#include "../../3rdParty/include/units.h"
using namespace units::literals;
using namespace units::mass;
using namespace units::density;
using namespace units::acceleration;
using namespace units::temperature;
using namespace units::power;
using namespace units::pressure;

#include "../../helper_functions/helper_functions.hpp"
using namespace MassCalculator::HelperFunctions;

#include "../../helper_classes/lua_handler.hpp"
using namespace MassCalculator::HelperClasses;

/**
 * @brief Default Materials namespace
 * 
 */
namespace MassCalculator::Materials
{
    /**
   * @brief String constants that are used through the code
   * 
   */
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
   * @brief Writing repeated static_casts in CRTP base classes quickly becomes cumbersome, as it does not add much meaning to the code.
   * With this template struct, I get rid of it and handled both const and non-const cases
   * 
   * @tparam TMaterial Material type template argument
   */
  template <typename TMaterial>
  struct crtp
  {
    TMaterial& materialType() { return static_cast<TMaterial&>(*this); }
    TMaterial const& materialType() const { return static_cast<TMaterial const&>(*this); }
  };

  /**
   * @brief Template base class Material
   * 
   */
  template<typename TMaterialType>
  class Material : crtp<TMaterialType>
  {
    public: enum class Type : uint8_t;

    public: typedef struct Properties_base
    {

      /**
       * @brief 
       * @todo This won't work, but leaving here so I don't forget. Try to deduce enumeration type from derived class in compile time
       * 
       * @param type_ Type The parameter to save the specific type
       * @param color_ string Parameter to save specific color
       * @param density_ kilograms_per_cubic_meter_t Parameter to save specific density
       * @param gravity_ meters_per_second_squared_t Parameter to save specific gravity
       * @param melting_point_ kelvin_t Parameter to save specific melting point
       * @param poissons_ratio_ double Parameter to save specific poissons ratio
       * @param thermal_conductivity_ watt_t Parameter to save specific thermal conductivity
       * @param mod_of_elasticity_tension_ pascal_t Parameter to save specific modulus of elasticity tension
       * @param mod_of_elasticity_torsion_ pascal_t Parameter to save specific modulus of elasticity torsion
       * 
       */
      std::pair<std::string, Type> type_;
      std::string color_;
      kilograms_per_cubic_meter_t density_;
      meters_per_second_squared_t gravity_;
      kelvin_t melting_point_;
      double poissons_ratio_;
      watt_t thermal_conductivity_;
      pascal_t mod_of_elasticity_tension_;
      pascal_t mod_of_elasticity_torsion_;

      Properties_base() : type_{{Constants::UNSPECIFIED}, { }},
                          // type_{{Constants::UNSPECIFIED}, {TMaterialType::Type::UNSPECIFIED}}, //I would love to do this
                          color_{""},
                          density_{0_kg_per_cu_m},
                          gravity_{0_mps_sq},
                          melting_point_{0_K},
                          poissons_ratio_{0},
                          thermal_conductivity_{0_W},
                          mod_of_elasticity_tension_{0_Pa},
                          mod_of_elasticity_torsion_{0_Pa} { }

    }Properties_base_t;

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
    Material(const Type &type)
    {
      this->materialType()(type);
    }

    /**
     * @brief Init the Lua config file
     * 
     */
    bool initLuaScript()
    {
      this->materialType()->initLuaScript();
      return true;
    }

    /**
     * @brief Set the Type object
     * 
     * @param type Type of the Material
     * @return true If the type is set successfully
     * @return false If the type failed to set
     */
    bool setType(const Type &type)
    {
      this->materialType()->setType(type);
      return true;
    }

    /**
     * @brief Get the Type object
     * 
     * @return const std::pair<std::string, Type> Pair with type name and type enum from Derived class
     */
    constexpr std::pair<std::string, Type> getType(void) const
    {
      return{this->materialType()->getType()};
    }

    /**
     * @brief Get the Specific Color object
     * 
     * @return const std::string Color of the material from Derived class
     */
    constexpr std::string getSpecificColor(void) const
    {
      return{this->materialType()->getSpecificColor()};
    }

    /**
     * @brief Get the Specific Density object
     * 
     * @return kilograms_per_cubic_meter_t Density of the material from Derived class
     */
    constexpr kilograms_per_cubic_meter_t getSpecificDensity(void) const
    {
      return{this->materialType()->getSpecificDensity()};
    }

    /**
     * @brief Get the Specific Gravity object
     * 
     * @return meters_per_second_squared_t Gravity of the material from Derived class
     */
    constexpr meters_per_second_squared_t getSpecificGravity(void) const
    {
      return{this->materialType()->getSpecificGravity()};
    }

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return kelvin_t The specific melting point of Material type from Derived class
     */
    constexpr kelvin_t getSpecificMeltingPoint(void) const
    {
      return{this->materialType()->getSpecificMeltingPoint()};
    }

    /**
     * @brief Get the Specific PoissonsRatio object
     * 
     * @return double The specific poissons ratio of Material type from Derived class
     */
    constexpr double getSpecificPoissonsRatio(void) const
    {
      return{this->materialType()->getSpecificPoissonsRatio()};
    }

    /**
     * @brief Get the Specific Thermal Conductivity object
     * 
     * @return watt_t The specific thermal conductivity of Material type from Derived class
     */
    constexpr watt_t getSpecificThermalConductivity(void) const
    {
      return{this->materialType()->getSpecificThermalConductivity()};
    }

    /**
     * @brief Get the Specific Modulus of Elasticity Tension object
     * 
     * @return pascal_t The specific modulus of elasticity tension point of Material type from Derived class
     */
    constexpr pascal_t getSpecificModOfElasticityTension(void) const
    {
      return{this->materialType()->getSpecificModOfElasticityTension()};
    }

    /**
     * @brief Get the Specific Modulus of Elasticity Torsion object
     * 
     * @return pascal_t The specific modulus of elasticity torsion point of Material type from Derived class
     */
    constexpr pascal_t getSpecificModOfElasticityTorsion(void) const
    {
      return{this->materialType()->getSpecificModOfElasticityTorsion()};
    }

    /**
     * @brief Destroy the Material object
     * 
     */
    ~Material(void) = default;

    /**
     * @brief Delete copy constructor
     * 
     */
    Material(const Material&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Material(Material&&) = default;

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

    /**
     * @brief Shift operator template overload, for the base class Material
     * 
     */
    template <typename TMaterial>
    friend std::ostream &operator << (std::ostream &os, const Material<TMaterialType> &obj);
  };

  template <typename TMaterial>
  std::ostream &operator << (std::ostream &os, const Material<TMaterial> &obj)
  {
    //TODO: This causes segmentation fault, it works if you comment out headers in materials.hh and you move implementation in the class
    //TODO: Update: The error is caused in interface when calling with make unique base object.
    os << "\n" "Material" "\n" << obj.thisTMaterialType();
    return os;
  }
}//end namespace MassCalculator::Materials
#endif//___MATERIAL_H___