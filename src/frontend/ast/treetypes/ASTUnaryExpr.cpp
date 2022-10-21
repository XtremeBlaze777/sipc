#include "ASTUnaryExpr.h"
#include "ASTVisitor.h"

void ASTUnaryExpr::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getRight()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTUnaryExpr::print(std::ostream &out) const {
  out << "(" << getOp() << *getRight() << ")";
  return out;
}  // LCOV_EXCL_LINE