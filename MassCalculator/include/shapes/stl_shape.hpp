#ifndef ___STL_SHAPE_H___
#define ___STL_SHAPE_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class StlShape, that holds all the nessesary information for the shape that is read from the dxf file and it's details therefore we can use in the interface
   * 
   */
  class StlShape : public Shape<StlShape>
  {

    public:
    
    /**
     * @brief Construct a new StlShape object
     * 
     */
    StlShape(void) = default;

    /**
     * @brief Destroy the StlShape object
     * 
     */
    ~StlShape(void) = default;
    
    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    StlShape(const StlShape&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    StlShape(StlShape&&) = default;

    /**
     * @brief Delete assignment operator
     */
    StlShape& operator=(const StlShape&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    StlShape& operator=(StlShape&&) = default;

  };
}//end namespace MassCalculator
#endif