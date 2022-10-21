#pragma once

#include "ASTStmt.h"

/*! \brief Class for binary operators: inc & dec.
 */
class ASTIncDecStmt : public ASTStmt {
  std::string OP;
  std::shared_ptr<ASTStmt> STMT;
public:
  ASTBinaryStmt(const std::string &OP, std::unique_ptr<ASTStmt> STMT
      : OP(OP), STMT(std::move(STMT)) {}
  std::string getOp() const { return OP; }
  ASTStmt* getStmt() const { return STMT.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
