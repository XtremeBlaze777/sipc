#include "ASTArrIndex.h"
#include "ASTVisitor.h"

void ASTArrIndex::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getIdx()->accept(visitor);
    getArr()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTArrIndex::print(std::ostream &out) const {
  out << *getArr() << "[" << *getIdx() << "]";
  return out;
}  // LCOV_EXCL_LINE
