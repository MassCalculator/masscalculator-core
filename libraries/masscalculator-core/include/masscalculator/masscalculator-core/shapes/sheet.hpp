#ifndef ___SHEET_H___
#define ___SHEET_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class Sheet, that holds all the nessesary information for Sheet and it's details therefore we can use in the interface
   * 
   */
  class Sheet : public Shape<Sheet>
  {
    public: enum class Type : uint8_t; //Remove this you get an error, also check the Lagger TODO:

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Sheet class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param side_ double Parameter to save side of the Sheet
       * @param length_ double Parameter to save length of the Sheet
       * 
       */
      std::pair<std::string, Type> type_{"Sheet", Sheet::Type::Sheet};
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
      Sheet = BEGIN,

      END
    };

    /**
     * @brief Construct a new Sheet object
     * 
     */
    Sheet(void) = default;

    /**
     * @brief Construct a new Sheet object
     * 
     * @param side Side of the Sheet in meter
     * @param length Length of the Sheet in meter
     */
    Sheet(double side, double length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the Sheet in meter
     * @param length Length of the Sheet in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double side, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the Sheet
     */
    double getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return const double Side of the Sheet
     */
    double getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Sheet
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the Sheet
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Sheet
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Sheet
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the Sheet object
     * 
     */
    ~Sheet(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Sheet &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Sheet(const Sheet&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Sheet(Sheet&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Sheet& operator=(const Sheet&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Sheet& operator=(Sheet&&) = default;

  };
}//end namespace MassCalculator::Shapes
#endif//___SHEET_H___