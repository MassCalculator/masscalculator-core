#ifndef ___SQUARE_TUBING_H___
#define ___SQUARE_TUBING_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class SquareTubing, that holds all the nessesary information for SquareTubing and it's details therefore we can use in the interface
   * 
   */
  class SquareTubing : public Shape<SquareTubing>
  {
    public: enum class Type : uint8_t; //Remove this you get an error, also check the Lagger TODO:

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of SquareTubing class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param side_ double Parameter to save side of the SquareTubing
       * @param length_ double Parameter to save length of the SquareTubing
       * 
       */
      std::pair<std::string, Type> type_{"SquareTubing", SquareTubing::Type::SquareTubing};
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
      SquareTubing = BEGIN,

      END
    };

    /**
     * @brief Construct a new SquareTubing object
     * 
     */
    SquareTubing(void) = default;

    /**
     * @brief Construct a new SquareTubing object
     * 
     * @param side Side of the SquareTubing in meter
     * @param length Length of the SquareTubing in meter
     */
    SquareTubing(double side, double length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the SquareTubing in meter
     * @param length Length of the SquareTubing in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double side, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the SquareTubing
     */
    double getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return const double Side of the SquareTubing
     */
    double getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the SquareTubing
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the SquareTubing
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the SquareTubing
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the SquareTubing
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the SquareTubing object
     * 
     */
    ~SquareTubing(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const SquareTubing &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    SquareTubing(const SquareTubing&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    SquareTubing(SquareTubing&&) = default;

    /**
     * @brief Delete assignment operator
     */
    SquareTubing& operator=(const SquareTubing&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    SquareTubing& operator=(SquareTubing&&) = default;

  };
}//end namespace MassCalculator
#endif//___SQUARE_TUBING_H___