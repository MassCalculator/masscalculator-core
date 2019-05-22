#ifndef ___DXF_SHAPE_H___
#define ___DXF_SHAPE_H___
#include "shape.hpp"

/**
 * @brief Default namespace
 * 
 */
namespace MassCalculator
{
  /**
   * @brief Class DxfShape, that holds all the nessesary information for the shape that is read from the dxf file and it's details therefore we can use in the interface
   * 
   */
  class DxfShape : public Shape<DxfShape>
  {
    DxfShape(void) = default;

    ~DxfShape(void) = default;

  };
}//end namespace MassCalculator
#endif