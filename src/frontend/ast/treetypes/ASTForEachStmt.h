#pragma once

#include "ASTStmt.h"
#include "ASTExpr.h"

/*! \brief Class for if-then-else.
 */
class ASTForEachStmt : public ASTStmt {
  std::shared_ptr<ASTExpr> ELEM, ARR;
  std::shared_ptr<ASTStmt> DO;
public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTIfStmt(std::unique_ptr<ASTExpr> ELEM, std::unique_ptr<ASTStmt> ARR,
            std::unique_ptr<ASTStmt> DO)
      : ELEM(std::move(ELEM)), ARR(std::move(ARR)), DO(std::move(DO)) {}
  ASTExpr* getElem() const { return ELEM.get(); }
  ASTExpr* getArr() const { return ARR.get(); }
  ASTStmt* getDo() const { return DO.get(); }

  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
