#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

Expression *BinaryExpression::getRight() {
    return this->right;
}

Expression *BinaryExpression::getLeft() {
    return this->left;
}
