#include "TipArr.h"
#include "TipTypeVisitor.h"

#include <sstream>

TipArr::TipArr(std::vector<std::shared_ptr<TipType>> type): TipCons(std::move(type)) { }

std::shared_ptr<TipType> TipArr::getType() const {
    return arguments.front();
}

std::ostream &TipArr::print(std::ostream &out) const {   
    out << "arr::" << *(arguments.front());
    return out;
}

bool TipArr::operator==(const TipType &other) const {
    auto otherTipArr = dynamic_cast<const TipArr *>(&other);
    if(!otherTipArr) {
        return false;
    }

    // Empty array case
    //if (arguments.size() == 0 || otherTipArr->arguments.size() == 0) {
    //    if (arguments.size() != otherTipArr->arguments.size()) {
    //        return false;
    //    } else {
    //        return true;
    //    }
    // }

    if(*(arguments.at(0)) != *(otherTipArr->arguments.at(0))) {
        return false;
    }

    return true;
}

bool TipArr::operator!=(const TipType &other) const {
    return !(*this == other);
}

void TipArr::accept(TipTypeVisitor * visitor) {
  if (visitor->visit(this)) {
    for (auto a : arguments) {
       a->accept(visitor);
    }
  }
  visitor->endVisit(this);
}
