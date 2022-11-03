#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for an AST Array Index Expression 
 */
class ASTArrIndex : public ASTExpr {
  std::shared_ptr<ASTExpr> IDX, ARR;
public:
  ASTArrIndex(std::unique_ptr<ASTExpr> IDX, std::unique_ptr<ASTExpr> ARR)
      : IDX(std::move(IDX)), ARR(std::move(ARR) ){}
  ASTExpr* getIdx() const { return IDX.get(); }
  ASTExpr* getArr() const { return ARR.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
