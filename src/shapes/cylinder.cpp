#include "shapes/cylinder.hpp"

namespace MassCalculator::Shapes
{
  Cylinder::Cylinder(meter_t diameter, meter_t length) : properties_{diameter, length}
  {
    LOG_DEBUG("I just set the size of cylinder from constructor: %f", static_cast<double>(diameter * length));
  }

  bool Cylinder::setSize(meter_t diameter, meter_t length)
  {
    this->properties_.diameter_ = diameter;
    this->properties_.length_ = length;

    if(this->properties_.diameter_ != diameter && this->properties_.length_ != length)
    {
      LOG_ERROR("Could not set the size of cylinder. %s", __PRETTY_FUNCTION__);
      return false;
    }

    LOG_DEBUG("I just set the size of cylinder: %f", static_cast<double>(diameter * length));

    return true;
  }

  meter_t Cylinder::getRadius(void) const
  {
    return{this->properties_.diameter_/2};
  }

  meter_t Cylinder::getDiameter(void) const
  {
    return{this->properties_.diameter_};
  }

  meter_t Cylinder::getLength(void) const
  {
    return{this->properties_.length_};
  }

  cubic_meter_t Cylinder::getVolume(void) const
  {
    return{M_PI * units::math::pow<2>(this->getRadius()) * this->getLength()};
  }

  square_meter_t Cylinder::getSurfaceArea(void) const
  {
    return{2 * M_PI * this->getRadius() * (this->getRadius() + this->getLength())};
  }

  std::string Cylinder::getType(void) const
  {
    return{this->properties_.type_.first};
  }

  std::ostream &operator << (std::ostream &os, const Cylinder &obj)
  {
    os << "  Cylinder object properties: " "\n";
          "   - Radius  : " + units::length::to_string(obj.getRadius()) + "\n"
          "   - Diameter: " + units::length::to_string(obj.getDiameter()) + "\n"
          "   - Length  : " + units::length::to_string(obj.getLength()) + "\n"
          "   - Volume  : " + units::volume::to_string(obj.getVolume()) + "\n"
          "   - Surface area: " + units::area::to_string(obj.getSurfaceArea()) + "\n";
    return os;
  }
}//end namespace MassCalculator::Shapes