#include "ASTForStmt.h"
#include "ASTVisitor.h"

void ASTForStmt::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    getStart()->accept(visitor);
    getEnd()->accept(visitor);
    getBegin()->accept(visitor);
    if (getStep() != nullptr) {
      getStep()->accept(visitor);
    }
    getDo()->accept(visitor);
  }
  visitor->endVisit(this);
}

std::ostream& ASTForStmt::print(std::ostream &out) const {
  out << "for (" << *getStart() << " : " << *getEnd() << " .. " << *getBegin();
  if (getStep() != nullptr) {
     out << " by " << *getStep();
  }
  out << ") " << *getDo();
  return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTForStmt::getChildren() {
  std::vector<std::shared_ptr<ASTNode>> children;

  children.push_back(START);
  children.push_back(END);
  children.push_back(BEGIN);
  if(getStep() != nullptr) {
    children.push_back(STEP);
  }
  children.push_back(DO);
  return children;
}
