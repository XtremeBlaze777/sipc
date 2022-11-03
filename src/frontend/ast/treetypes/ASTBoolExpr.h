#pragma once

#include "ASTExpr.h"

/*! \brief Class for numeric literals.
 */
class ASTBoolExpr : public ASTExpr {
  std::string VAL;
public:
  ASTBoolExpr(std::string VAL) : VAL(VAL) {}
  std::string getValue() const { return VAL; }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
