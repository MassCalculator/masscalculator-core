#ifndef ___CYLINDER_H___
#define ___CYLINDER_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief 
   * 
   */
  class Cylinder : public Shape<Cylinder>
  {
    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Cylinder class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param diameter_ double Parameter to save diameter of the cylinder
       * @param length_ double Parameter to save length of the cylinder
       * 
       */
      //std::pair<std::string, Type> type_{"UNSPECIFIED", Aluminium::Type::UNSPECIFIED};
      double diameter_{1};
      double length_{1};
    }properties_;

    public:
    /**
     * @brief Construct a new Cylinder object
     * 
     */
    Cylinder() = default;

    /**
     * @brief Construct a new Cylinder object
     * 
     * @param diameter 
     * @param length 
     */
    Cylinder(double diameter, double length);

    /**
     * @brief Set the Size object
     * 
     * @param diameter 
     * @param length 
     * @return true 
     * @return false 
     */
    bool setSize(double diameter, double length);

    const double getRadius(void);

    const double getDiameter(void);

    const double getLength(void);

    double getVolume(void);

    double getSurfaceArea(void);

    /**
     * @brief Get the Mass object
     * 
     * @return double 
     */
    double getMass(void);

    /**
     * @brief Destroy the Cylinder object
     * 
     */
    ~Cylinder(void) = default;

    /**
     * @brief 
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Cylinder &obj);

    private:
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

  };
}//end namespace MassCalculator
#endif