#include "shapes/square_tubing.hpp"

namespace MassCalculator::Shapes
{
  SquareTubing::SquareTubing(meter_t side, meter_t thickness, meter_t length) : properties_{side, thickness, length}
  {
    LOG_DEBUG("I just set the size of square tubing from constructor: Side: %f, Thickness: %f, Length: %f", side.to<double>(), thickness.to<double>(), length.to<double>());
  }

  bool SquareTubing::setSize(meter_t side, meter_t thickness, meter_t length)
  {
    this->properties_.side_ = side;
    this->properties_.thickness_ = thickness;
    this->properties_.length_ = length;

    if(this->properties_.side_ != side && this->properties_.thickness_ != thickness && this->properties_.length_ != length)
    {
      LOG_ERROR("Could not set the size of square tubing. %s", __PRETTY_FUNCTION__);
      return false;
    }

    LOG_DEBUG("I just set the size of square tubing: Side: %f, Thickness: %f, Length: %f", side.to<double>(), thickness.to<double>(), length.to<double>());

    return true;
  }

  meter_t SquareTubing::getInnerDiagonal(void) const
  {
    meter_t _inner_diagonal = (this->properties_.side_ - this->properties_.thickness_) * std::sqrt(2);

    LOG_DEBUG("Square tubing inner diagonal: %f", _inner_diagonal.to<double>());

    return{_inner_diagonal};
  }

  meter_t SquareTubing::getOutterDiagonal(void) const
  {
    meter_t _outter_diagonal = this->properties_.side_ * std::sqrt(2);

    LOG_DEBUG("Square tubing outter diagonal: %f", _outter_diagonal.to<double>());

    return{_outter_diagonal};
  }

  meter_t SquareTubing::getSide(void) const
  {
    meter_t _side = this->properties_.side_;

    LOG_DEBUG("Square tubing side: %f", _side.to<double>());

    return{_side};
  }

  meter_t SquareTubing::getThickness(void) const
  {
    meter_t _thickness = this->properties_.thickness_;

    LOG_DEBUG("Square tubing thickness: %f", _thickness.to<double>());

    return{_thickness};
  }

  meter_t SquareTubing::getLength(void) const
  {
    meter_t _length = this->properties_.length_;

    LOG_DEBUG("Square tubing length: %f", _length.to<double>());

    return{_length};
  }

  cubic_meter_t SquareTubing::getVolume(void) const
  {
    cubic_meter_t _total_volume = units::math::pow<2>(this->getSide()) * this->getLength();
    cubic_meter_t _hollow_volume = units::math::pow<2>(this->getSide() - this->getThickness()) * this->getLength();
    cubic_meter_t _volume = _total_volume - _hollow_volume;

    LOG_DEBUG("Square tubing volume: Total: %f, hollow: %f, calculated: %f", _total_volume.to<double>(), _hollow_volume.to<double>(), _volume.to<double>());

    return{_volume};
  }

  square_meter_t SquareTubing::getSurfaceArea(void) const
  {
    square_meter_t _total_area = (2 * this->getSide()) * (this->getSide() + (2 * this->getLength()));
    square_meter_t _hollow_area = (2 * (this->getSide() - this->getThickness())) * ((this->getSide() - this->getThickness()) + (2 * this->getLength()));
    square_meter_t _surface_area = _total_area - _hollow_area;

    LOG_DEBUG("Square tubing surface area: Total: %f, hollow: %f, calculated: %f", _total_area.to<double>(), _hollow_area.to<double>(), _surface_area.to<double>());

    return{_surface_area};
  }

  std::string SquareTubing::getType(void) const
  {
    std::string _type = this->properties_.type_.first;

    LOG_DEBUG("Square tubing type: %s",_type.c_str());

    return{_type};
  }

  std::ostream &operator << (std::ostream &os, const SquareTubing &obj)
  {
    os << "  SquareTubing object properties: " "\n"
          "   - Inner Diagonal  : " + units::length::to_string(obj.getInnerDiagonal()) + "\n"
          "   - Outter Diagonal : " + units::length::to_string(obj.getOutterDiagonal()) + "\n"
          "   - Side      : " + units::length::to_string(obj.getSide()) + "\n"
          "   - Thickness : " + units::length::to_string(obj.getThickness()) + "\n"
          "   - Length    : " + units::length::to_string(obj.getLength()) + "\n"
          "   - Volume    : " + units::volume::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + units::area::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }
}//end namespace MassCalculator::Shapes