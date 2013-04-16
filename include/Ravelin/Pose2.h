/****************************************************************************
 * Copyright 2013 Evan Drumwright
 * This library is distributed under the terms of the GNU Lesser General Public 
 * License (found in COPYING).
 ****************************************************************************/

#ifndef POSE2
#error This class is not to be included by the user directly. Use Posed.h or Posef.h instead. 
#endif

/// A 2D rigid body pose 
class POSE2 : public boost::enable_shared_from_this<POSE2>
{
  public:
    POSE2();
    POSE2(const POSE2& source) { operator=(source); }
    POSE2(const ROT2& r, const ORIGIN2& x);
    POSE2(const ORIGIN2& x);
    POSE2(const ROT2& r);
    static POSE2 identity() { POSE2 T; T.set_identity(); return T; }
    static POSE2 interpolate(const POSE2& m1, const POSE2& m2, REAL t);
    POINT2 transform(const POINT2& v) const;
    VECTOR2 transform(const VECTOR2& v) const;
    POINT2 inverse_transform(const POINT2& v) const;
    VECTOR2 inverse_transform(const VECTOR2& v) const;
    POINT2 transform(boost::shared_ptr<const POSE2> p, const POINT2& v) const;
    VECTOR2 transform(boost::shared_ptr<const POSE2> p, const VECTOR2& v) const;
    static POINT2 transform(boost::shared_ptr<const POSE2> source, boost::shared_ptr<const POSE2> target, const POINT2& v);
    static VECTOR2 transform(boost::shared_ptr<const POSE2> source, boost::shared_ptr<const POSE2> target, const VECTOR2& v);
    void set_relative_pose(boost::shared_ptr<const POSE2> p); 
    POSE2& set_identity();
    POSE2& invert();
    POSE2 inverse() const { return inverse(*this); }
    static POSE2 inverse(const POSE2& m);
    POSE2& set(const ROT2& r, const ORIGIN2& v);
    POSE2& set(const ROT2& r);
    POSE2& operator=(const POSE2& source);
    POSE2 operator*(const POSE2& m) const;

    /// the orientation of the pose frame
    ROT2 r;

    /// the position of the pose frame
    ORIGIN2 x;

    /// the pose that *this* pose is relative to (if any)
    boost::shared_ptr<POSE2> rpose; 

  private:
    std::pair<ROT2, ORIGIN2> calc_transform(boost::shared_ptr<const POSE2> p) const;
    static std::pair<ROT2, ORIGIN2> calc_transform(boost::shared_ptr<const POSE2> source, boost::shared_ptr<const POSE2> target);
    static bool is_common(boost::shared_ptr<const POSE2> source, boost::shared_ptr<const POSE2> p, unsigned& i);
}; // end class

std::ostream& operator<<(std::ostream& out, const POSE2& m);
