#ifndef VISITOR_H
#define VISITOR_H
class Set;
class Integer;

class Visitor
{
  public:
      virtual void visitSet(Set * s) = 0;
      virtual void visitInteger(Integer * i) = 0;
};
#endif
