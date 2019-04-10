#ifndef ___MATERIAL_H___
#define ___MATERIAL_H___
#include <iostream>

#include <functional>

/**
 * @brief 
 * 
 */
namespace MassCalculator
{
  /**
   * @brief 
   * 
   */
  template<typename TMaterialType>
  class Material 
  {
    public:
    enum class Type : uint8_t
    {
      AL_6080 = 0,
      AL_6030
    };

    Material(void)
    {

    };

    double getSpecificMass()
    {
      return{static_cast<TMaterialType*>(this)->getSpecificMass()};
    }

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
     * @brief Destroy the Material object
     * 
     */
    virtual ~Material(void) = default;
  };

  // /**
  //  * @brief 
  //  * 
  //  * @param os 
  //  * @param val 
  //  * @return std::ostream& 
  //  */
  // std::ostream &operator << (std::ostream &os, const Material &val)
  // {
  //   os << "Value from class: ";
  //   return os;
  // }

}//end namespace MassCalculator
#endif