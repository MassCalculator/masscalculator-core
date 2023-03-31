#include "shapes/square_bar.hpp"

namespace MassCalculator::Shapes
{
  SquareBar::SquareBar(meter_t side, meter_t length) : properties_{side, length}
  {
    LOG_DEBUG("I just set the size of square bar from constructor: Side: %f, Length: %f", side.to<double>(), length.to<double>());
  }

  bool SquareBar::setSize(meter_t side, meter_t length)
  {
    this->properties_.side_ = side;
    this->properties_.length_ = length;

    if(this->properties_.side_ != side && this->properties_.length_ != length)
    {
      LOG_ERROR("Could not set the size of square bar. %s", __PRETTY_FUNCTION__);
      return false;
    }

    LOG_DEBUG("I just set the size of square bar: Side: %f, Length: %f", side.to<double>(), length.to<double>());

    return true;
  }

  meter_t SquareBar::getDiagonal(void) const
  {
    return{this->properties_.side_ * std::sqrt(2)};
  }

  meter_t SquareBar::getSide(void) const
  {
    return{this->properties_.side_};
  }

  meter_t SquareBar::getLength(void) const
  {
    return{this->properties_.length_};
  }

  cubic_meter_t SquareBar::getVolume(void) const
  {
    return{units::math::pow<2>(this->getSide()) * this->getLength()};
  }

  square_meter_t SquareBar::getSurfaceArea(void) const
  {
    return{(2 * this->getSide()) * (this->getSide() + (2 * this->getLength()))};
  }

  std::string SquareBar::getType(void) const
  {
    return{this->properties_.type_.first};
  }

  std::ostream &operator << (std::ostream &os, const SquareBar &obj)
  {
    os << "  SquareBar object properties: " "\n"
          "   - Diagonal : " + units::length::to_string(obj.getDiagonal()) + "\n"
          "   - Side     : " + units::length::to_string(obj.getSide()) + "\n"
          "   - Length   : " + units::length::to_string(obj.getLength()) + "\n"
          "   - Volume   : " + units::volume::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + units::area::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }

}//end namespace MassCalculator::Shapes