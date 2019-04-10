/**
 * @file material.h
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief TODO add brief
 * @version 0.1
 * @date 2019-04-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <iostream>

/**
 * @brief TODO
 * 
 */
namespace MassCalculator
{
  /**
   * @brief TODO
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
     * @param type TODO
     */
    Material(Type type)
    {
      static_cast<TMaterialType*>(this)(type);
    }

    /**
     * @brief Set the Type object
     * 
     * @param type TODO
     * @return true TODO
     * @return false TODO
     */
    bool setType(Type type)
    {
      static_cast<TMaterialType*>(this)->setType(type);
      return true;
    }

    /**
     * @brief Get the Type object
     * 
     * @return const std::pair<std::string, Type> TODO
     */
    const std::pair<std::string, Type> getType(void) const
    {
      return{static_cast<TMaterialType*>(this)->getType()};
    }

    /**
     * @brief Get the Specific Color object
     * 
     * @return const std::string TODO
     */
    const std::string getSpecificColor(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificColor()};
    }

    /**
     * @brief Get the Specific Density object
     * 
     * @return const double TODO
     */
    const double getSpecificDensity(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificDensity()};
    }

    /**
     * @brief Get the Specific Volume object
     * 
     * @return const double TODO
     */
    const double getSpecificVolume(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificVolume()};
    }

    /**
     * @brief Get the Specific Mass object
     * 
     * @return const double TODO
     */
    const double getSpecificMass(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificMass()};
    }

    /**
     * @brief Get the Specific Weight object
     * 
     * @return const double TODO
     */
    const double getSpecificWeight(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificWeight()};
    }

    /**
     * @brief Get the Specific Melting Point object
     * 
     * @return const double TODO
     */
    const double getSpecificMeltingPoint(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificMeltingPoint()};
    }

    /**
     * @brief Get the Specific Boiling Point object
     * 
     * @return const double TODO
     */
    const double getSpecificBoilingPoint(void)
    {
      return{static_cast<TMaterialType*>(this)->getSpecificBoilingPoint()};
    }

    /**
     * @brief Destroy the Material object
     * 
     */
    virtual ~Material(void) = default;

    /**
     * @brief Shift operator template overload, for the base class Material
     * 
     */
    template <typename TMaterial>
    friend std::ostream &operator << (std::ostream &os, const Material<TMaterial> &obj)
    {
      os << "\n" "Material" "\n" << obj.thisT();
      return os;
    }

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
     * @brief TODO
     * 
     * @return const TMaterialType& 
     */
    const TMaterialType& thisT() const { return *static_cast<const TMaterialType*>(this); }

  };

}//end namespace MassCalculator
#endif