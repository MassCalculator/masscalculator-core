#ifndef ___ANGLE_H___
#define ___ANGLE_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class Angle, that holds all the nessesary information for Angle and it's details therefore we can use in the interface
   * 
   */
  class Angle : public Shape<Angle>
  {
    public: enum class Type : uint8_t; //Remove this you get an error, also check the Lagger TODO:

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Angle class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param side_ double Parameter to save side of the Angle
       * @param length_ double Parameter to save length of the Angle
       * 
       */
      std::pair<std::string, Type> type_{"Angle", Angle::Type::Angle};
      std::string lagger_;
      double side_{1};
      double length_{1};
    }properties_;

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
      Angle = BEGIN,

      END
    };

    /**
     * @brief Construct a new Angle object
     * 
     */
    Angle(void) = default;

    /**
     * @brief Construct a new Angle object
     * 
     * @param side Side of the Angle in meter
     * @param length Length of the Angle in meter
     */
    Angle(double side, double length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the Angle in meter
     * @param length Length of the Angle in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double side, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the Angle
     */
    double getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return const double Side of the Angle
     */
    double getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Angle
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the Angle
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Angle
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Angle
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the Angle object
     * 
     */
    ~Angle(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Angle &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Angle(const Angle&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Angle(Angle&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Angle& operator=(const Angle&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Angle& operator=(Angle&&) = default;

  };
}//end namespace MassCalculator
#endif //___ANGLE_H___