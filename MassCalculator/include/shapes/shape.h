#ifndef ___SHAPE_H___
#define ___SHAPE_H___
#include <iostream>

/**
 * @brief 
 * 
 */
namespace MassCalculator
{
  /**
   * @brief 
   * 
   */
  template<typename TShapeType>
  class Shape 
  {
    public:
    enum class Type : uint8_t
    {
      AL_6080 = 0,
      AL_6030
    };

    /**
     * @brief Construct a new Shape object
     * 
     */
    Shape(Type)
    {

    };

    template<class... Args>
    bool setSize(const Args&... args)
    {
      static_cast<TShapeType*>(this)->setSize(args...);

      return true;
    }

    Shape(void)
    {

    };

    double getMass()
    {
      return{static_cast<TShapeType*>(this)->getMass()};
    }

    /**
     * @brief Delete copy constructor
     * 
     */
    Shape(const Shape&) = delete;

    /**
     * @brief Set move constructor to default
     * 
     */
    Shape(Shape&&) = default;

    /**
     * @brief Delete assignment operator
     */
    Shape& operator=(const Shape&) = delete;

    /**
     * @brief Allow move assignment operator
     */
    Shape& operator=(Shape&&) = default;

    /**
     * @brief Destroy the Shape object
     * 
     */
    virtual ~Shape(void) = default;
  };

  // /**
  //  * @brief 
  //  * 
  //  * @param os 
  //  * @param val 
  //  * @return std::ostream& 
  //  */
  // std::ostream &operator << (std::ostream &os, const Shape &val)
  // {
  //   os << "Value from class: ";
  //   return os;
  // }

}//end namespace MassCalculator
#endif