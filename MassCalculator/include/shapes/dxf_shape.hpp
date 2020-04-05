#ifndef ___DXF_SHAPE_H___
#define ___DXF_SHAPE_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator::Shapes
{
  /**
   * @brief Class DxfShape, that holds all the nessesary information for the shape that is read from the dxf file and it's details therefore we can use in the interface
   * 
   */
  class DxfShape : public Shape<DxfShape>
  {

    public:
    
    /**
     * @brief Construct a new DxfShape object
     * 
     */
    DxfShape(void) = default;

    /**
     * @brief Destroy the DxfShape object
     * 
     */
    ~DxfShape(void) = default;
    
    private:
    /**
     * @brief Delete copy constructor
     * 
     */
    DxfShape(const DxfShape&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    DxfShape(DxfShape&&) = default;

    /**
     * @brief Delete assignment operator
     */
    DxfShape& operator=(const DxfShape&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    DxfShape& operator=(DxfShape&&) = default;

  };
}//end namespace MassCalculator::Shapes
#endif