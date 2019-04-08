#ifndef ___ALUMINIUM_H___
#define ___ALUMINIUM_H___

#include <iostream>

#include "material.h"

/**
 * @brief 
 * 
 */
namespace MassCalculator
{
namespace Material
{  
  /**
   * @brief 
   * 
   */
  class Aluminium : public Material<Aluminium>
  {
    public:
    enum class Type : uint8_t
    {
      AL_6080 = 0,
      AL_6030
    };

    /**
     * @brief Construct a new Aluminium object
     * 
     */
    Aluminium(Type)
    {

    };

    Aluminium(void)
    {

    };

    double getSpecificMass(void);

    /**
     * @brief Delete copy constructor
     * 
     */
    Aluminium(const Aluminium&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Aluminium(Aluminium&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Aluminium& operator=(const Aluminium&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Aluminium& operator=(Aluminium&&) = default;

    /**
     * @brief Destroy the Aluminium object
     * 
     */
    ~Aluminium(void) = default;
  };

  // /**
  //  * @brief 
  //  * 
  //  * @param os 
  //  * @param val 
  //  * @return std::ostream& 
  //  */
  // std::ostream &operator << (std::ostream &os, const Aluminium &val)
  // {
  //   os << "Value from class: ";
  //   return os;
  // }

}//end namespace Material
}//end namespace MassCalculator
#endif