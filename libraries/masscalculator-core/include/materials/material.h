/**
 * @file material.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This class is the base class for the Materials, this will be inherited
 * from all the Material types, and holds the prototypes so the derived classes
 * can be accessed from it's object pointer
 * @version 0.2
 * @date 2020-03-28
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <functional>
#include <unordered_map>

#include "macro_logger.hpp"
#include "units.h"
using namespace units::literals;
using namespace units::mass;
using namespace units::density;
using namespace units::acceleration;
using namespace units::temperature;
using namespace units::power;
using namespace units::pressure;

/**
 * @brief Default Materials namespace
 *
 */
namespace MassCalculator::Materials {
/**
 * @brief String constants that are used through the code
 *
 */
namespace Constants {
namespace Material {
/** @brief String constant for AlloyCoppers material */
const std::string AlloyCoppers{"AlloyCoppers"};

/** @brief String constant for AlloySteels material */
const std::string AlloySteels{"AlloySteels"};

/** @brief String constant for Aluminium material */
const std::string Aluminium{"Aluminium"};

/** @brief String constant for Brass material */
const std::string Brass{"Brass"};

/** @brief String constant for Bronz material */
const std::string Bronz{"Bronz"};

/** @brief String constant for Copper material */
const std::string Copper{"Copper"};

/** @brief String constant for Magnesium material */
const std::string Magnesium{"Magnesium"};

/** @brief String constant for Nickel material */
const std::string Nickel{"Nickel"};

/** @brief String constant for Plastic material */
const std::string Plastic{"Plastic"};

/** @brief String constant for StainlessSteel material */
const std::string StainlessSteel{"StainlessSteel"};

/** @brief String constant for Steel material */
const std::string Steel{"Steel"};

/** @brief String constant for Titanium material */
const std::string Titanium{"Titanium"};

/** @brief String constant for Zinc material */
const std::string Zinc{"Zinc"};

/** @brief String constant for UNSPECIFIED material */
const std::string UNSPECIFIED{"UNSPECIFIED"};
}  // namespace Material

namespace Color {
/** @brief String constant for Metallic color */
const std::string Metallic{"Metallic"};

/** @brief String constant for Darktone color */
const std::string DarkTone{"DarkTone"};
}  // namespace Color
}  // namespace Constants

/**
 * @brief Writing repeated static_casts in CRTP base classes quickly becomes
 * cumbersome, as it does not add much meaning to the code. With this template
 * struct, I get rid of it and handled both const and non-const cases
 *
 * @tparam TMaterial Material type template argument
 */
template <typename TMaterial>
struct crtp {
  /**
   * @brief
   *
   * @return TMaterial&
   */
  TMaterial& materialType() { return static_cast<TMaterial&>(*this); }

  /**
   * @brief
   *
   * @return TMaterial const&
   */
  TMaterial const& materialType() const {
    return static_cast<TMaterial const&>(*this);
  }
};

/**
 * @brief Template base class Material
 *
 */
template <typename TMaterialType>
class Material : crtp<TMaterialType> {
 public:
  enum class Type : uint8_t;

  // /**
  //  * @brief Struct with material specific properties
  //  * @todo: Check if this can be moved to the base class, the problem is only
  //  in the std::pair<T, Type>, Type cannot be deduced from base to derived
  //  */
  // typedef struct Properties
  // {
  //   /**
  //    * @brief Type The parameter to save the specific type
  //    *
  //    */
  //   std::pair<std::string, Type> type_;

  //   /**
  //    * @brief string Parameter to save specific color
  //    *
  //    */
  //   std::string color_;

  //   /**
  //    * @brief kilograms_per_cubic_meter_t Parameter to save specific density
  //    *
  //    */
  //   kilograms_per_cubic_meter_t density_;

  //   /**
  //    * @brief meters_per_second_squared_t Parameter to save specific gravity
  //    *
  //    */
  //   meters_per_second_squared_t gravity_;

  //   /**
  //    * @brief kelvin_t Parameter to save specific melting point
  //    *
  //    */
  //   kelvin_t melting_point_;

  //   /**
  //    * @brief double Parameter to save specific poissons ratio
  //    *
  //    */
  //   double poissons_ratio_;

  //   /**
  //    * @brief watt_t Parameter to save specific thermal conductivity
  //    *
  //    */
  //   watt_t thermal_conductivity_;

  //   /**
  //    * @brief pascal_t Parameter to save specific modulus of elasticity
  //    tension
  //    *
  //    */
  //   pascal_t mod_of_elasticity_tension_;

  //   /**
  //    * @brief pascal_t Parameter to save specific modulus of elasticity
  //    torsion
  //    *
  //    */
  //   pascal_t mod_of_elasticity_torsion_;

  //   /**
  //    * @brief Construct a new Properties object with all parameters
  //    initialized
  //    *
  //    */
  //   Properties() : type_{std::make_pair("", Type::UNSPECIFIED)},
  //                  color_{""},
  //                  density_{0_kg_per_cu_m},
  //                  gravity_{0_mps_sq},
  //                  melting_point_{0_K},
  //                  poissons_ratio_{0},
  //                  thermal_conductivity_{0_W},
  //                  mod_of_elasticity_tension_{0_Pa},
  //                  mod_of_elasticity_torsion_{0_Pa} { }

  //   /**
  //    * @brief Construct a new Properties object through initializer list
  //    *
  //    */
  //   Properties(std::pair<std::string,typename TMaterialType::Type> type,
  //              std::string color,
  //              kilograms_per_cubic_meter_t density,
  //              meters_per_second_squared_t gravity,
  //              kelvin_t melting_point,
  //              double poissons_ratio,
  //              watt_t thermal_conductivity,
  //              pascal_t mod_of_elasticity_tension,
  //              pascal_t mod_of_elasticity_torsion) : type_{type},
  //                                                    color_{color},
  //                                                    density_{density},
  //                                                    gravity_{gravity},
  //                                                    melting_point_{melting_point},
  //                                                    poissons_ratio_{poissons_ratio},
  //                                                    thermal_conductivity_{thermal_conductivity},
  //                                                    mod_of_elasticity_tension_{mod_of_elasticity_tension},
  //                                                    mod_of_elasticity_torsion_{mod_of_elasticity_torsion}
  //                                                    { }
  // }Properties_t;

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
  Material(const Type& type) { this->materialType()(type); }

  /**
   * @brief Init the Lua config file
   *
   */
  bool initLuaScript() {
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
  bool setType(const Type& type) {
    this->materialType()->setType(type);
    return true;
  }

  /**
   * @brief Get the Type object
   *
   * @return const std::pair<std::string, Type> Pair with type name and type
   * enum from Derived class
   */
  constexpr std::pair<std::string, Type> getType(void) const {
    return {this->materialType()->getType()};
  }

  /**
   * @brief Get the Specific Color object
   *
   * @return const std::string Color of the material from Derived class
   */
  constexpr std::string getSpecificColor(void) const {
    return {this->materialType()->getSpecificColor()};
  }

  /**
   * @brief Get the Specific Density object
   *
   * @return kilograms_per_cubic_meter_t Density of the material from Derived
   * class
   */
  constexpr kilograms_per_cubic_meter_t getSpecificDensity(void) const {
    return {this->materialType()->getSpecificDensity()};
  }

  /**
   * @brief Get the Specific Gravity object
   *
   * @return meters_per_second_squared_t Gravity of the material from Derived
   * class
   */
  constexpr meters_per_second_squared_t getSpecificGravity(void) const {
    return {this->materialType()->getSpecificGravity()};
  }

  /**
   * @brief Get the Specific Melting Point object
   *
   * @return kelvin_t The specific melting point of Material type from Derived
   * class
   */
  constexpr kelvin_t getSpecificMeltingPoint(void) const {
    return {this->materialType()->getSpecificMeltingPoint()};
  }

  /**
   * @brief Get the Specific PoissonsRatio object
   *
   * @return double The specific poissons ratio of Material type from Derived
   * class
   */
  constexpr double getSpecificPoissonsRatio(void) const {
    return {this->materialType()->getSpecificPoissonsRatio()};
  }

  /**
   * @brief Get the Specific Thermal Conductivity object
   *
   * @return watt_t The specific thermal conductivity of Material type from
   * Derived class
   */
  constexpr watt_t getSpecificThermalConductivity(void) const {
    return {this->materialType()->getSpecificThermalConductivity()};
  }

  /**
   * @brief Get the Specific Modulus of Elasticity Tension object
   *
   * @return pascal_t The specific modulus of elasticity tension point of
   * Material type from Derived class
   */
  constexpr pascal_t getSpecificModOfElasticityTension(void) const {
    return {this->materialType()->getSpecificModOfElasticityTension()};
  }

  /**
   * @brief Get the Specific Modulus of Elasticity Torsion object
   *
   * @return pascal_t The specific modulus of elasticity torsion point of
   * Material type from Derived class
   */
  constexpr pascal_t getSpecificModOfElasticityTorsion(void) const {
    return {this->materialType()->getSpecificModOfElasticityTorsion()};
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
  const TMaterialType& thisTMaterialType() const {
    return *static_cast<const TMaterialType*>(this);
  }

  /**
   * @brief Shift operator template overload, for the base class Material
   *
   */
  template <typename TMaterial>
  friend std::ostream& operator<<(std::ostream& os,
                                  const Material<TMaterialType>& obj);
};

template <typename TMaterial>
std::ostream& operator<<(std::ostream& os, const Material<TMaterial>& obj) {
  // TODO: This causes segmentation fault, it works if you comment out headers
  // in materials.hh and you move implementation in the class
  // TODO: Update: The error is caused in interface when calling with make
  // unique base object.
  os << "\n"
        "Material"
        "\n"
     << obj.thisTMaterialType();
  return os;
}
}  // end namespace MassCalculator::Materials
#endif  //___MATERIAL_H___