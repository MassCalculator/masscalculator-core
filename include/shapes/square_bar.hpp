#ifndef ___SQUARE_BAR_H___
#define ___SQUARE_BAR_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class SquareBar, that holds all the nessesary information for SquareBar and it's details therefore we can use in the interface
   * 
   */
  class SquareBar : public Shape<SquareBar>
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
       * @brief meter_t Parameter to save side of the squarebar
       * 
       */
      meter_t side_;

      /**
       * @brief meter_t Parameter to save length of the squarebar
       * 
       */
      meter_t length_;

      /**
       * @brief Construct a new Properties object with all three parameters initialized
       * 
       */
      Properties() : type_{std::make_pair(Constants::Shape::SquareBar, SquareBar::Type::SquareBar)},
                     side_{1},
                     length_{1} { }

      /**
       * @brief Construct a new Properties object and set diameter and length
       * 
       */
      Properties(meter_t side, meter_t length) : type_{std::make_pair(Constants::Shape::SquareBar, SquareBar::Type::SquareBar)},
                                                 side_{side},
                                                 length_{length} { }
    }Properties_t;

    public:
    /**
     * @brief Construct a new SquareBar object
     * 
     */
    SquareBar(void) = default;

    /**
     * @brief Construct a new SquareBar object
     * 
     * @param side Side of the SquareBar in meter
     * @param length Length of the SquareBar in meter
     */
    SquareBar(meter_t side, meter_t length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the SquareBar in meter
     * @param length Length of the SquareBar in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(meter_t side, meter_t length);

    /**
     * @brief Get the Diagonal object
     * 
     * @return meter_t Diagonal of the SquareBar
     */
    meter_t getDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return meter_t Side of the SquareBar
     */
    meter_t getSide(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return meter_t Length of the SquareBar
     */
    meter_t getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return cubic_meter_t Volume of the SquareBar
     */
    cubic_meter_t getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return square_meter_t Surface Are of the SquareBar
     */
    square_meter_t getSurfaceArea(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return std::string Surface Are of the SquareBar
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the SquareBar object
     * 
     */
    ~SquareBar(void) = default;

    /**
     * @brief Shift operator overload for class Aluminium, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const SquareBar &obj);

    /**
     * @brief Delete copy constructor
     * 
     */
    SquareBar(const SquareBar&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    SquareBar(SquareBar&&) = default;

    /**
     * @brief Delete assignment operator
     */
    SquareBar& operator=(const SquareBar&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    SquareBar& operator=(SquareBar&&) = default;

    private:
    /**
     * @brief Properties struct to hold the specific object properties
     * 
     */
    Properties_t properties_;
  };
}//end namespace MassCalculator::Shapes
#endif