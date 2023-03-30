/**
 * @file square_tubing.hpp
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief SquareTubing class that holds the parameters for the shape
 * @version 0.1
 * @date 2020-04-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef ___SQUARE_TUBING_H___
#define ___SQUARE_TUBING_H___
#include "shape.hpp"

/**
 * @brief Default Shapes namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class SquareTubing, that holds all the nessesary information for SquareTubing and it's details therefore we can use in the interface
   * 
   */
  class SquareTubing : public Shape<SquareTubing>
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
       * @brief meter_t Parameter to save side of the squaretubing
       * 
       */
      meter_t side_;

      /**
       * @brief meter_t Parameter to save thickness of the squaretubing
       * 
       */
      meter_t thickness_;

      /**
       * @brief meter_t Parameter to save length of the squaretubing
       * 
       */
      meter_t length_;

      /**
       * @brief Construct a new Properties object with all three parameters initialized
       * 
       */
      Properties() : type_{std::make_pair(Constants::Shape::SquareTubing, SquareTubing::Type::SquareTubing)},
                     side_{1},
                     thickness_{1},
                     length_{1} { }

      /**
       * @brief Construct a new Properties object and set diameter and length
       * 
       */
      Properties(meter_t side, meter_t length, meter_t thickness) : type_{std::make_pair(Constants::Shape::SquareTubing, SquareTubing::Type::SquareTubing)},
                                                                    side_{side},
                                                                    thickness_{thickness},
                                                                    length_{length} { }
    }Properties_t;

    public:
    /**
     * @brief Construct a new SquareTubing object
     * 
     */
    SquareTubing(void) = default;

    /**
     * @brief Construct a new SquareTubing object
     * 
     * @param side Side of the SquareTubing in meter
     * @param thickness Thickness of the SquareTubing in meter
     * @param length Length of the SquareTubing in meter
     */
    SquareTubing(meter_t side, meter_t thickness, meter_t length);

    /**
     * @brief Set the Size object
     * 
     * @param side Side of the SquareTubing in meter
     * @param thickness Thickness of the SquareTubing in meter
     * @param length Length of the SquareTubing in meter
     * @return true If setting the size is successful
     * @return false If setting the size fails
     */
    bool setSize(meter_t side, meter_t thickness, meter_t length);

    /**
     * @brief Get the inner Diagonal object
     * 
     * @return meter_t Inner Diagonal of the SquareTubing
     */
    meter_t getInnerDiagonal(void) const;

    /**
     * @brief Get the outter Diagonal object
     * 
     * @return meter_t Outter Diagonal of the SquareTubing
     */
    meter_t getOutterDiagonal(void) const;

    /**
     * @brief Get the Side object
     * 
     * @return meter_t Side of the SquareTubing
     */
    meter_t getSide(void) const;

    /**
     * @brief Get the Thickness object
     * 
     * @return meter_t Thickness of the SquareTubing
     */
    meter_t getThickness(void) const;

    /**
     * @brief Get the Length object
     * 
     * @return meter_t Length of the SquareTubing
     */
    meter_t getLength(void) const;

    /**
     * @brief Get the Volume object
     * 
     * @return cubic_meter_t Volume of the SquareTubing
     */
    cubic_meter_t getVolume(void) const;

    /**
     * @brief Get the Surface Area object
     * 
     * @return square_meter_t Surface Are of the SquareTubing
     */
    square_meter_t getSurfaceArea(void) const;

    /**
     * @brief Get the type as string
     * 
     * @return std::string Type as string
     */
    std::string getType(void) const;

    /**
     * @brief Destroy the SquareTubing object
     * 
     */
    ~SquareTubing(void) = default;

    /**
     * @brief Shift operator overload for class SquareTubing, this will print all the nessesery informations
     * 
     */
    friend std::ostream &operator << (std::ostream &os, const SquareTubing &obj);

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

    private:
    /**
     * @brief Properties struct to hold the specific object properties
     * 
     */
    Properties_t properties_;
  };
}//end namespace MassCalculator::Shapes
#endif//___SQUARE_TUBING_H___