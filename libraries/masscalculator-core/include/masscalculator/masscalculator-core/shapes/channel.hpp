#ifndef ___CHANNEL_H___
#define ___CHANNEL_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class Channel, that holds all the nessesary information for Channel and it's details therefore we can use in the interface
   * 
   */
  class Channel : public Shape<Channel>
  {
    public: enum class Type : uint8_t; //Remove this you get an error, also check the Lagger TODO:

    /**
     * @brief Struct with material specific properties
     * TODO:Check if this can be moved to the base class
     */
    struct Properties
    {

      /**
       * @brief Private members of Channel class. Values defaulted with brace-enclosed initializer list
       * and will be set from the constructor.
       * 
       * @param type_ Type The parameter to save the specific type (Need to check for this TODO)
       * @param side_ double Parameter to save side of the Channel
       * @param length_ double Parameter to save length of the Channel
       * 
       */
      std::pair<std::string, Type> type_{"Channel", Channel::Type::Channel};
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
      Channel = BEGIN,

      END
    };

    /**
     * @brief Construct a new Channel object
     * 
     */
    Channel(void) = default;

    /**
     * @brief Construct a new Channel object
     * 
     * @param side Side of the Channel in meter
     * @param length Length of the Channel in meter
     */
    Channel(double side, double length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the Channel in meter
     * @param length Length of the Channel in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(double side, double length);

    /**
     * @brief Get the Radius object
     * 
     * @return const double Radius of the Channel
     */
    double getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return const double Side of the Channel
     */
    double getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return const double Length of the Channel
     */
    double getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return double Volume of the Channel
     */
    double getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Channel
     */
    double getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return double Surface Are of the Channel
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the Channel object
     * 
     */
    ~Channel(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const Channel &obj);

    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    Channel(const Channel&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Channel(Channel&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Channel& operator=(const Channel&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Channel& operator=(Channel&&) = default;

  };
}//end namespace MassCalculator::Shapes
#endif//___CHANNEL_H___