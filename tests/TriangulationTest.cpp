// Copyright 2021 the Polygon Mesh Processing Library developers.
// Distributed under a MIT-style license, see LICENSE.txt for details.

#include "gtest/gtest.h"

#include <pmp/algorithms/triangulation.h>
#include "Helpers.h"

using namespace pmp;

TEST(TriangulationTest, min_area)
{
    auto mesh = l_shape();
    triangulate(mesh, TriangulationObjective::min_area);
    EXPECT_EQ(mesh.n_faces(), size_t(10));
}

TEST(TriangulationTest, max_angle)
{
    auto mesh = l_shape();
    triangulate(mesh, TriangulationObjective::max_angle);
    EXPECT_EQ(mesh.n_faces(), size_t(10));
}