// Copyright (C) 2012-2016 The VPaint Developers.
// See the COPYRIGHT file at the top-level directory of this distribution
// and at https://github.com/dalboris/vpaint/blob/master/COPYRIGHT
//
// This file is part of VPaint, a vector graphics editor. It is subject to the
// license terms and conditions in the LICENSE.MIT file found in the top-level
// directory of this distribution and at http://opensource.org/licenses/MIT

#ifndef VECGEOMETRY_EDGEGEOMETRY_H
#define VECGEOMETRY_EDGEGEOMETRY_H

#include <glm/vec2.hpp>
#include <vector>

struct EdgeGeometrySample
{
    glm::vec2 centerline1;   // actual data
    glm::vec2 normal1;       // computed normal
    glm::vec2 leftBoundary;  // computed edge boundary (after join style + warping)

    glm::vec2 centerline2;   // == centerline1 (duplicated for shader)
    glm::vec2 normal2;       // == normal1     (duplicated for shader)
    glm::vec2 rightBoundary; // computed edge boundary (after join style + warping)
};

class EdgeGeometry
{
public:
    EdgeGeometry();

    void beginStroke(const glm::vec2 & centerline);
    void continueStroke(const glm::vec2 & centerline);
    void endStroke();
    const std::vector<EdgeGeometrySample> & samples();

private:
    size_t size() const;
    void clear();
    void addSample(const glm::vec2 & centerline);

private:
    std::vector<EdgeGeometrySample> samples_;
    std::vector<float> arclengths_;
    std::vector<glm::vec2> tangents_;
};

#endif // VECGEOMETRY_EDGEGEOMETRY_H
