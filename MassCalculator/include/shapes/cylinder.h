#ifndef ___CYLINDER_H___
#define ___CYLINDER_H___

#include <iostream>

#include "shape.h"

/**
 * @brief 
 * 
 */
namespace MassCalculator
{
namespace Shape
{  
  /**
   * @brief 
   * 
   */
  class Cylinder : public Shape<Cylinder>
  {
    public:
    /**
     * @brief Construct a new Cylinder object
     * 
     */
    Cylinder() = default;

    Cylinder(double radius, double length);

    bool setSize(double radius, double length);

    double getMass(void);

    /**
     * @brief Delete copy constructor
     * 
     */
    Cylinder(const Cylinder&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Cylinder(Cylinder&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Cylinder& operator=(const Cylinder&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Cylinder& operator=(Cylinder&&) = default;

    /**
     * @brief Destroy the Cylinder object
     * 
     */
    ~Cylinder(void) = default;
  };

  // /**
  //  * @brief 
  //  * 
  //  * @param os 
  //  * @param val 
  //  * @return std::ostream& 
  //  */
  // std::ostream &operator << (std::ostream &os, const Cylinder &val)
  // {
  //   os << "Value from class: ";
  //   return os;
  // }
}//end namespace Shape
}//end namespace MassCalculator
#endif