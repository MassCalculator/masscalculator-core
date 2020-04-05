#ifndef ___CYLINDER_H___
#define ___CYLINDER_H___
#include "shape.hpp"

/**
 * @brief Default namespace
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
    public: enum class Type : uint8_t;

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    typedef struct Properties
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
      std::pair<std::string, Type> type_;
      // std::string lagger_;
      double diameter_;
      double length_;
    }Properties_t;

    public:

    enum class Type : uint8_t
    {
      BEGIN = 0,
      /**
       * @brief This grade is commercially pure aluminum. It is soft and ductile and has excellent workability, making it ideal for applications with difficult forming. 
       * It can be welded using any method, but it is non heat-treatable. It has an excellent resistance to corrosion and is commonly used in the chemical and 
       * food processing industries.
       * 
       */
      Cylinder = BEGIN,

      END
    };

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
    Cylinder(double diameter, double length);

    /**
     * @brief Set the Size object
     * 
     * @param diameter Diameter of the Cylinder in meter
     * @param length Length of the Cylinder in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double diameter, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the Cylinder
     */
    double getRadius(void) const;

    /**
     * @brief Get the Diameter object
     * 
     * @return const double Diameter of the Cylinder
     */
    double getDiameter(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Cylinder
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the Cylinder
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Cylinder
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Cylinder
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the Cylinder object
     * 
     */
    ~Cylinder(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
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
    
    Properties_t properties_{std::make_pair("Cylinder", Cylinder::Type::Cylinder), 1, 1};
  };
}//end namespace MassCalculator::Shapes
#endif//___CYLINDER_H___