#include <iostream>

#include <mln/core/concept/image.hh>
#include <mln/core/image/image2d.hh>
#include <mln/core/alias/window2d.hh>
#include <mln/core/alias/neighb2d.hh>

#include <mln/value/int_u8.hh>


#include <mln/morpho/watershed/flooding.hh>
#include <mln/morpho/closing/area.hh>
#include <mln/morpho/elementary/gradient.hh>
#include <mln/level/transform.hh>

namespace mln
{
  using value::int_u8;

  template <typename I>
  mln_concrete(I) rag(const Image<I>& input)
  {
    typedef int_u8 L;
    L n_basins;
    mln_concrete(I) grad;
    grad = morpho::closing::area(input, c4(), 5);
    image2d<L> output =
      morpho::watershed::flooding(grad, c4(), n_basins);
    return output;
  }

}
