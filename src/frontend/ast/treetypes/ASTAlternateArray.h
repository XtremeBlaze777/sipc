#pragma once

#include "ASTExpr.h"
#include <ostream>

/*! \brief Class for an array.
 *
 */
class ASTMainArray: public ASTNode {
    std::string name;
    std::shared_ptr<ASTExpr> startExpr;
    std::shared_ptr<ASTExpr> endExpr;
    public:
        std::vector<std::shared_ptr<ASTNode>> getChildren() override;
        ASTAlternateArray(std::unique_ptr<ASTExpr> startExpr, std::unique_ptr<ASTExpr> endExpr)
                        : startExpr(std::move(startExpr)), endExpr(std::move(lastExpr)) {}
        std::string getName() const { return name; }
        ASTExpr* getStartExpr() const { return startExpr.get(); }
        ASTExpr* getEndExpr() const { return endExpr.get(); }
        void accept(ASTVisitor * visitor) override;
        llvm::Value *codegen() override;
    protected:
        std::ostream& print(std::ostream &out) const override;
