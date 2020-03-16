#ifndef ___OCTAGON_BAR_H___
#define ___OCTAGON_BAR_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class OctagonBar, that holds all the nessesary information for OctagonBar and it's details therefore we can use in the interface
   * 
   */
  class OctagonBar : public Shape<OctagonBar>
  {
    public: enum class Type : uint8_t; //Remove this you get an error, also check the Lagger TODO:

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of OctagonBar class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param side_ double Parameter to save side of the OctagonBar
       * @param length_ double Parameter to save length of the OctagonBar
       * 
       */
      std::pair<std::string, Type> type_{"OctagonBar", OctagonBar::Type::OctagonBar};
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
      OctagonBar = BEGIN,

      END
    };

    /**
     * @brief Construct a new OctagonBar object
     * 
     */
    OctagonBar(void) = default;

    /**
     * @brief Construct a new OctagonBar object
     * 
     * @param side Side of the OctagonBar in meter
     * @param length Length of the OctagonBar in meter
     */
    OctagonBar(double side, double length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the OctagonBar in meter
     * @param length Length of the OctagonBar in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double side, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the OctagonBar
     */
    double getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return const double Side of the OctagonBar
     */
    double getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the OctagonBar
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the OctagonBar
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the OctagonBar
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the OctagonBar
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the OctagonBar object
     * 
     */
    ~OctagonBar(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const OctagonBar &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    OctagonBar(const OctagonBar&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    OctagonBar(OctagonBar&&) = default;

    /**
     * @brief Delete assignment operator
     */
    OctagonBar& operator=(const OctagonBar&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    OctagonBar& operator=(OctagonBar&&) = default;

  };
}//end namespace MassCalculator
#endif//___OCTAGON_BAR_H___