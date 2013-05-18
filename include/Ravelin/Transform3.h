/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef TRANSFORM3
#error This class is not to be included by the user directly. Use Transform3d.h or Transform3f.h instead. 
#endif

class POSE3;

/// A transformation between two rigid body poses 
class TRANSFORM3
{
  public:
    TRANSFORM3();
    TRANSFORM3(const TRANSFORM3& source) { operator=(source); }
    TRANSFORM3(const AANGLE& a);
    TRANSFORM3(const MATRIX3& m);
    TRANSFORM3(const QUAT& q);
    TRANSFORM3(const AANGLE& a, const ORIGIN3& v);
    TRANSFORM3(const MATRIX3& m, const ORIGIN3& v);
    TRANSFORM3(const QUAT& q, const ORIGIN3& v);
    TRANSFORM3(const ORIGIN3& v);
    static TRANSFORM3 identity() { TRANSFORM3 T; T.set_identity(); return T; }
    static bool rel_equal(const TRANSFORM3& p1, const TRANSFORM3& p2, REAL tol = EPS);
    POINT3 transform(const POINT3& p) const;
    VECTOR3 transform(const VECTOR3& v) const;
    POINT3 inverse_transform(const POINT3& p) const;
    VECTOR3 inverse_transform(const VECTOR3& v) const;
    WRENCH transform(const WRENCH& w) const;
    WRENCH inverse_transform(const WRENCH& w) const;
    TWIST transform(const TWIST& t) const;
    TWIST inverse_transform(const TWIST& t) const;
    SPATIAL_RB_INERTIA transform(const SPATIAL_RB_INERTIA& j) const;
    SPATIAL_RB_INERTIA inverse_transform(const SPATIAL_RB_INERTIA& j) const;
    SPATIAL_AB_INERTIA transform(const SPATIAL_AB_INERTIA& j) const;
    SPATIAL_AB_INERTIA inverse_transform(const SPATIAL_AB_INERTIA& j) const;
    TRANSFORM3& set_identity();
    TRANSFORM3& invert();
    TRANSFORM3 inverse() const { return invert(*this); }
    static TRANSFORM3 invert(const TRANSFORM3& m);
    TRANSFORM3& set(const AANGLE& a);
    TRANSFORM3& set(const MATRIX3& m);
    TRANSFORM3& set(const QUAT& q);
    TRANSFORM3& set(const AANGLE& a, const ORIGIN3& v);
    TRANSFORM3& set(const MATRIX3& m, const ORIGIN3& v);
    TRANSFORM3& set(const QUAT& q, const ORIGIN3& v);
    TRANSFORM3& operator=(const TRANSFORM3& source);
    TRANSFORM3 operator*(const TRANSFORM3& m) const;

    /// the relative orientation
    QUAT q;

    /// the relative origin
    ORIGIN3 x;

    /// the "source" pose
    boost::shared_ptr<const POSE3> source; 

    /// the "target" pose
    boost::shared_ptr<const POSE3> target; 
}; // end class

std::ostream& operator<<(std::ostream& out, const TRANSFORM3& m);

