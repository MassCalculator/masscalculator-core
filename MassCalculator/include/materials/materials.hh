/**
 * @file materials.hh
 * @author Mergim Halimi (m.halimi123@gmail.com)
 * @brief This header contains all the headers for Materials, if this header is included, you include all the headers
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ___MATERIALS_HH___
#define ___MATERIALS_HH___

  /**
   * @brief : Uncomment these headers and find out hot to leave here and not redefine template function from base class.
   * Error: /home/jimmyhalimi/cpp_ws/MassCalculator/MassCalculator/include/materials/material.hpp:164:26: error: redefinition of ‘template<class TMaterial> std::ostream& MassCalculator::operator<<(std::ostream&, const MassCalculator::Material<TMaterial>&)’
       friend std::ostream &operator << (std::ostream &os, const Material<TMaterial> &obj)
   *
   * [resolved] : Added the define preprocessor guards, so we don't have a redefinition
   */

  #ifndef ___ALLOY_COPPERS_H___
  #define ___ALLOY_COPPERS_H___
    #include "alloy_coppers.hpp"
  #endif//___ALLOY_COPPERS_H___

  #ifndef ___ALLOY_STEELS_H___
  #define ___ALLOY_STEELS_H___
    #include "alloy_steels.hpp"
  #endif//___ALLOY_STEELS_H___

  #ifndef ___ALUMINIUM_H___
  #define ___ALUMINIUM_H___
    #include "aluminium.hpp"
  #endif//___ALUMINIUM_H___

  #ifndef ___BRASS_H___
  #define ___BRASS_H___
    #include "brass.hpp"
  #endif//___BRASS_H___

  #ifndef ___BRONZ_H___
  #define ___BRONZ_H___
    #include "bronz.hpp"
  #endif//___BRONZ_H___

  #ifndef ___COPPER_H___
  #define ___COPPER_H___
    #include "copper.hpp"
  #endif//___COPPER_H___

  #ifndef ___MAGNESIUM_H___
  #define ___MAGNESIUM_H___
    #include "magnesium.hpp"
  #endif//___MAGNESIUM_H___

  #ifndef ___NICKEL_H___
  #define ___NICKEL_H___
    #include "nickel.hpp"
  #endif//___NICKEL_H___

  #ifndef ___PLASTIC_H___
  #define ___PLASTIC_H___
    #include "plastic.hpp"
  #endif//___PLASTIC_H___

  #ifndef ___STAINLESS_STEEL_H___
  #define ___STAINLESS_STEEL_H___
    #include "stainless_steel.hpp"
  #endif//___STAINLESS_STEEL_H___

  #ifndef ___STEEL_H___
  #define ___STEEL_H___
    #include "steel.hpp"
  #endif//___STEEL_H___

  #ifndef ___TITANIUM_H___
  #define ___TITANIUM_H___
    #include "titanium.hpp"
  #endif//___TITANIUM_H___

  #ifndef ___ZINC_H___
  #define ___ZINC_H___
    #include "zinc.hpp"
  #endif//___ZINC_H___

#endif//___MATERIALS_HH___