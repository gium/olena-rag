#include <iostream>

#include <mln/core/concept/image.hh>
#include <mln/core/image/image2d.hh>
#include <mln/core/alias/window2d.hh>
#include <mln/core/alias/neighb2d.hh>

#include <mln/value/int_u8.hh>
#include <mln/value/label_8.hh>

#include <mln/morpho/watershed/flooding.hh>
#include <mln/morpho/meyer_wst.hh>
#include <mln/morpho/closing/area.hh>
#include <mln/morpho/elementary/gradient.hh>
#include <mln/level/transform.hh>

#include <mln/make/region_adjacency_graph.hh>
#include <mln/util/graph.hh>

#include <mln/core/site_set/p_vertices.hh>
#include <mln/core/var.hh>
#include <mln/fun/i2v/array.hh>
#include <mln/make/p_vertices_with_mass_centers.hh>
#include <mln/literal/grays.hh>
#include <mln/debug/draw_graph.hh>

namespace mln
{
  using value::int_u8;
  using value::label_8;

  template <typename I>
  mln_concrete(I) rag(Image<I>& input_)
  {
    I& input = exact(input_);
    typedef label_8 L;
    L n_basins;
    mln_concrete(I) grad;
    grad = morpho::closing::area(input, c4(), 6);
    image2d<L> wsed =
      morpho::watershed::flooding(grad, c4(), n_basins);
    util::graph g = make::region_adjacency_graph(wsed, c4(), 4u);
    mln_VAR(vertices, make::p_vertices_with_mass_centers(wsed, n_basins, g));
    debug::draw_graph(input, vertices, 100, 200);
    return input;
  }

}
