#include "ASTForEachStmt.h"
#include "ASTVisitor.h"

void ASTForEachStmt::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getElem()->accept(visitor);
    getArr()->accept(visitor);
    getDo()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTIfStmt::print(std::ostream &out) const {
  out << "for (" << *getElem() << ":" << *getArr << ") ";
  out << *getDo();
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTIfStmt::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;

  children.push_back(ELEM);
  children.push_back(ARR);
  children.push_back(DO);

  return children;
}
