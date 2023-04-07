/**
 * @file cylinder.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief Cylinder class that holds the parameters for the shape
 * @version 0.1
 * @date 2020-04-05
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___CYLINDER_H___
#define ___CYLINDER_H___
#include "shape.hpp"

/**
 * @brief Default Shapes namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class Cylinder, that holds all the nessesary information for Cylinder and it's details therefore we can use in the interface
   * 
   */
  class Cylinder : public Shape<Cylinder>
  {
    /**
     * @brief Struct with shape specific properties
     * 
     */
    typedef struct Properties
    {
      /**
       * @brief Parameter to save the specific Enum type and name
       * 
       */
      std::pair<std::string, Type> type_;

      /**
       * @brief meter_t Parameter to save diameter of the cylinder
       * 
       */
      meter_t diameter_;

      /**
       * @brief meter_t Parameter to save length of the cylinder
       * 
       */
      meter_t length_;

      /**
       * @brief Construct a new Properties object with all three parameters initialized
       * 
       */
      Properties() : type_{std::make_pair(Constants::Shape::Cylinder, Cylinder::Type::Cylinder)},
                     diameter_{1},
                     length_{1} { }

      /**
       * @brief Construct a new Properties object and set diameter and length
       * 
       */
      Properties(meter_t diameter, meter_t length) : type_{std::make_pair(Constants::Shape::Cylinder, Cylinder::Type::Cylinder)},
                                                     diameter_{diameter},
                                                     length_{length} { }
    }Properties_t;

    public:
    /**
     * @brief Construct a new Cylinder object
     * 
     */
    Cylinder(void) = default;

    /**
     * @brief Construct a new Cylinder object
     * 
     * @param diameter Diameter of the Cylinder in meter
     * @param length Length of the Cylinder in meter
     */
    Cylinder(meter_t diameter, meter_t length);

    /**
     * @brief Set the Size object
     * 
     * @param diameter Diameter of the Cylinder in meter
     * @param length Length of the Cylinder in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(meter_t diameter, meter_t length);

    /**
     * @brief Get the Radius object
     * 
     * @return meter_t Radius of the Cylinder
     */
    meter_t getRadius(void) const;

    /**
     * @brief Get the Diameter object
     * 
     * @return meter_t Diameter of the Cylinder
     */
    meter_t getDiameter(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return meter_t Length of the Cylinder
     */
    meter_t getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return cubic_meter Volume of the Cylinder
     */
    cubic_meter_t getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return square_meter Surface Are of the Cylinder
     */
    square_meter_t getSurfaceArea(void) const;

    /**
     * @brief Get the type as string
     * 
     * @return std::string Type as string
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the Cylinder object
     * 
     */
    ~Cylinder(void) = default;

    /**
     * @brief Shift operator overload for class Cylinder, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Cylinder &obj);

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

    private:
    /**
     * @brief Properties struct to hold the specific object properties
     * 
     */
    Properties_t properties_;
  };
}//end namespace MassCalculator::Shapes
#endif//___CYLINDER_H___