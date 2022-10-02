#pragma once

#include "ASTExpr.h"

/*! \brief Class for a null expression
 */ 
class ASTBoolExpr : public ASTExpr {
public:
  ASTBoolExpr() {}
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};