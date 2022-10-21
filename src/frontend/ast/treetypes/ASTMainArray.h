#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for an array.
 *
 */
class ASTMainArray: public ASTNode {
    std::string name;
    std::vector<std::shared_ptr<ASTExpr>> elements;
    public:
        std::vector<std::shared_ptr<ASTNode>> getChildren() override;
        ASTMainArray(std::vector<std::unique_ptr<ASTExpr>> elements);
        std::string getName() const { return name; }
        std::vector<ASTExpr*> getElements() const;
        void accept(ASTVisitor * visitor) override;
        llvm::Value *codegen() override;
    protected:
        std::ostream& print(std::ostream &out) const override;
