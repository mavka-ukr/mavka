#pragma once

#ifndef AST_H
#define AST_H

#include <map>
#include <string>
#include <vector>

namespace mavka::ast {
  class ASTNode;
  class ASTValueNode;
  class ASTExprNode;
  class ASTSome;
  class AnonDiiaNode;
  class ArgNode;
  class ArithmeticNode;
  class ArrayNode;
  class AsNode;
  class AssignByElementNode;
  class AssignByIdentifierNode;
  class AssignSimpleNode;
  class BitwiseNode;
  class BitwiseNotNode;
  class BreakNode;
  class CallNode;
  class ChainNode;
  class ComparisonNode;
  class CompInstBlockProgramNode;
  class CompInstAssignNode;
  class ContinueNode;
  class DictionaryElementNode;
  class DictionaryNode;
  class DiiaNode;
  class EachNode;
  class EvalNode;
  class FromToComplexNode;
  class FromToSimpleNode;
  class FunctionNode;
  class GenericNode;
  class GetElementNode;
  class GiveElementNode;
  class GiveNode;
  class GodNode;
  class IdentifierNode;
  class IfNode;
  class MethodDeclarationNode;
  class MockupDiiaNode;
  class MockupModuleNode;
  class MockupStructureNode;
  class MockupSubjectNode;
  class ModuleNode;
  class MRMDiiaNode;
  class NegativeNode;
  class NotNode;
  class NumberNode;
  class ParamNode;
  class PositiveNode;
  class PostDecrementNode;
  class PostIncrementNode;
  class PreDecrementNode;
  class PreIncrementNode;
  class ProgramNode;
  class ReturnNode;
  class StringNode;
  class StructureNode;
  class TakeModuleNode;
  class TakePakNode;
  class TernaryNode;
  class TestNode;
  class ThrowNode;
  class TryNode;
  class TypeValueSingleNode;
  class WaitNode;
  class WhileNode;

  ASTSome* make_ast_some(ast::AnonDiiaNode* node);
  ASTSome* make_ast_some(ast::ArgNode* node);
  ASTSome* make_ast_some(ast::ArithmeticNode* node);
  ASTSome* make_ast_some(ast::ArrayNode* node);
  ASTSome* make_ast_some(ast::AsNode* node);
  ASTSome* make_ast_some(ast::AssignByElementNode* node);
  ASTSome* make_ast_some(ast::AssignByIdentifierNode* node);
  ASTSome* make_ast_some(ast::AssignSimpleNode* node);
  ASTSome* make_ast_some(ast::BitwiseNode* node);
  ASTSome* make_ast_some(ast::BitwiseNotNode* node);
  ASTSome* make_ast_some(ast::BreakNode* node);
  ASTSome* make_ast_some(ast::CallNode* node);
  ASTSome* make_ast_some(ast::ChainNode* node);
  ASTSome* make_ast_some(ast::ComparisonNode* node);
  ASTSome* make_ast_some(ast::CompInstBlockProgramNode* node);
  ASTSome* make_ast_some(ast::CompInstAssignNode* node);
  ASTSome* make_ast_some(ast::ContinueNode* node);
  ASTSome* make_ast_some(ast::DictionaryElementNode* node);
  ASTSome* make_ast_some(ast::DictionaryNode* node);
  ASTSome* make_ast_some(ast::DiiaNode* node);
  ASTSome* make_ast_some(ast::EachNode* node);
  ASTSome* make_ast_some(ast::EvalNode* node);
  ASTSome* make_ast_some(ast::FromToComplexNode* node);
  ASTSome* make_ast_some(ast::FromToSimpleNode* node);
  ASTSome* make_ast_some(ast::FunctionNode* node);
  ASTSome* make_ast_some(ast::GenericNode* node);
  ASTSome* make_ast_some(ast::GetElementNode* node);
  ASTSome* make_ast_some(ast::GiveElementNode* node);
  ASTSome* make_ast_some(ast::GiveNode* node);
  ASTSome* make_ast_some(ast::GodNode* node);
  ASTSome* make_ast_some(ast::IdentifierNode* node);
  ASTSome* make_ast_some(ast::IfNode* node);
  ASTSome* make_ast_some(ast::MethodDeclarationNode* node);
  ASTSome* make_ast_some(ast::MockupDiiaNode* node);
  ASTSome* make_ast_some(ast::MockupModuleNode* node);
  ASTSome* make_ast_some(ast::MockupStructureNode* node);
  ASTSome* make_ast_some(ast::MockupSubjectNode* node);
  ASTSome* make_ast_some(ast::ModuleNode* node);
  ASTSome* make_ast_some(ast::MRMDiiaNode* node);
  ASTSome* make_ast_some(ast::NegativeNode* node);
  ASTSome* make_ast_some(ast::NotNode* node);
  ASTSome* make_ast_some(ast::NumberNode* node);
  ASTSome* make_ast_some(ast::ParamNode* node);
  ASTSome* make_ast_some(ast::PositiveNode* node);
  ASTSome* make_ast_some(ast::PostDecrementNode* node);
  ASTSome* make_ast_some(ast::PostIncrementNode* node);
  ASTSome* make_ast_some(ast::PreDecrementNode* node);
  ASTSome* make_ast_some(ast::PreIncrementNode* node);
  ASTSome* make_ast_some(ast::ProgramNode* node);
  ASTSome* make_ast_some(ast::ReturnNode* node);
  ASTSome* make_ast_some(ast::StringNode* node);
  ASTSome* make_ast_some(ast::StructureNode* node);
  ASTSome* make_ast_some(ast::TakeModuleNode* node);
  ASTSome* make_ast_some(ast::TakePakNode* node);
  ASTSome* make_ast_some(ast::TernaryNode* node);
  ASTSome* make_ast_some(ast::TestNode* node);
  ASTSome* make_ast_some(ast::ThrowNode* node);
  ASTSome* make_ast_some(ast::TryNode* node);
  ASTSome* make_ast_some(ast::TypeValueSingleNode* node);
  ASTSome* make_ast_some(ast::WaitNode* node);
  ASTSome* make_ast_some(ast::WhileNode* node);
  // ASTSome* make_ast_some(ast::ASTNode* node);

  ASTNode* get_ast_node(ASTSome* ast_some);

  class ASTNode {
   public:
    size_t start_line = 0;
    size_t start_column = 0;
    size_t end_line = 0;
    size_t end_column = 0;

    virtual ~ASTNode() = default;
  };

  class ASTValueNode : public ASTNode {
   public:
  };

  class ASTExprNode : public ASTNode {
   public:
  };

  class ASTSome {
   public:
    mavka::ast::AnonDiiaNode* AnonDiiaNode = nullptr;
    mavka::ast::ArgNode* ArgNode = nullptr;
    mavka::ast::ArithmeticNode* ArithmeticNode = nullptr;
    mavka::ast::ArrayNode* ArrayNode = nullptr;
    mavka::ast::AsNode* AsNode = nullptr;
    mavka::ast::AssignByElementNode* AssignByElementNode = nullptr;
    mavka::ast::AssignByIdentifierNode* AssignByIdentifierNode = nullptr;
    mavka::ast::AssignSimpleNode* AssignSimpleNode = nullptr;
    mavka::ast::BitwiseNode* BitwiseNode = nullptr;
    mavka::ast::BitwiseNotNode* BitwiseNotNode = nullptr;
    mavka::ast::BreakNode* BreakNode = nullptr;
    mavka::ast::CallNode* CallNode = nullptr;
    mavka::ast::ChainNode* ChainNode = nullptr;
    mavka::ast::ComparisonNode* ComparisonNode = nullptr;
    mavka::ast::CompInstBlockProgramNode* CompInstBlockProgramNode = nullptr;
    mavka::ast::CompInstAssignNode* CompInstAssignNode = nullptr;
    mavka::ast::ContinueNode* ContinueNode = nullptr;
    mavka::ast::DictionaryElementNode* DictionaryElementNode = nullptr;
    mavka::ast::DictionaryNode* DictionaryNode = nullptr;
    mavka::ast::DiiaNode* DiiaNode = nullptr;
    mavka::ast::EachNode* EachNode = nullptr;
    mavka::ast::EvalNode* EvalNode = nullptr;
    mavka::ast::FromToComplexNode* FromToComplexNode = nullptr;
    mavka::ast::FromToSimpleNode* FromToSimpleNode = nullptr;
    mavka::ast::FunctionNode* FunctionNode = nullptr;
    mavka::ast::GenericNode* GenericNode = nullptr;
    mavka::ast::GetElementNode* GetElementNode = nullptr;
    mavka::ast::GiveElementNode* GiveElementNode = nullptr;
    mavka::ast::GiveNode* GiveNode = nullptr;
    mavka::ast::GodNode* GodNode = nullptr;
    mavka::ast::IdentifierNode* IdentifierNode = nullptr;
    mavka::ast::IfNode* IfNode = nullptr;
    mavka::ast::MethodDeclarationNode* MethodDeclarationNode = nullptr;
    mavka::ast::MockupDiiaNode* MockupDiiaNode = nullptr;
    mavka::ast::MockupModuleNode* MockupModuleNode = nullptr;
    mavka::ast::MockupStructureNode* MockupStructureNode = nullptr;
    mavka::ast::MockupSubjectNode* MockupSubjectNode = nullptr;
    mavka::ast::ModuleNode* ModuleNode = nullptr;
    mavka::ast::MRMDiiaNode* MRMDiiaNode = nullptr;
    mavka::ast::NegativeNode* NegativeNode = nullptr;
    mavka::ast::NotNode* NotNode = nullptr;
    mavka::ast::NumberNode* NumberNode = nullptr;
    mavka::ast::ParamNode* ParamNode = nullptr;
    mavka::ast::PositiveNode* PositiveNode = nullptr;
    mavka::ast::PostDecrementNode* PostDecrementNode = nullptr;
    mavka::ast::PostIncrementNode* PostIncrementNode = nullptr;
    mavka::ast::PreDecrementNode* PreDecrementNode = nullptr;
    mavka::ast::PreIncrementNode* PreIncrementNode = nullptr;
    mavka::ast::ProgramNode* ProgramNode = nullptr;
    mavka::ast::ReturnNode* ReturnNode = nullptr;
    mavka::ast::StringNode* StringNode = nullptr;
    mavka::ast::StructureNode* StructureNode = nullptr;
    mavka::ast::TakeModuleNode* TakeModuleNode = nullptr;
    mavka::ast::TakePakNode* TakePakNode = nullptr;
    mavka::ast::TernaryNode* TernaryNode = nullptr;
    mavka::ast::TestNode* TestNode = nullptr;
    mavka::ast::ThrowNode* ThrowNode = nullptr;
    mavka::ast::TryNode* TryNode = nullptr;
    mavka::ast::TypeValueSingleNode* TypeValueSingleNode = nullptr;
    mavka::ast::WaitNode* WaitNode = nullptr;
    mavka::ast::WhileNode* WhileNode = nullptr;

    bool is_nullptr();
    bool is_popable();
  };

  class AnonDiiaNode final : public ASTValueNode {
   public:
    bool async;
    std::vector<GenericNode*> generics;
    std::vector<ParamNode*> params;
    std::vector<TypeValueSingleNode*> return_types;
    std::vector<ASTSome*> body;
  };

  class ArgNode final : public ASTExprNode {
   public:
    size_t index;
    std::string name;
    ASTSome* value;
    bool spread = false;
  };

  class ArithmeticNode final : public ASTValueNode {
   public:
    ASTSome* left;
    ASTSome* right;
    std::string op;
  };

  class ArrayNode final : public ASTValueNode {
   public:
    std::vector<ASTSome*> elements;
    std::vector<TypeValueSingleNode*> types;
  };

  class AsNode final : public ASTValueNode {
   public:
    ASTSome* left;
    ASTSome* right;
  };

  class AssignByIdentifierNode final : public ASTExprNode {
   public:
    ASTSome* left;
    std::string identifier;
    std::string op;
    ASTSome* value;
  };

  class AssignByElementNode final : public ASTExprNode {
   public:
    ASTSome* left;
    ASTSome* element;
    std::string op;
    ASTSome* value;
  };

  class AssignSimpleNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<TypeValueSingleNode*> types;
    std::string op;
    ASTSome* value;
  };

  class BitwiseNode final : public ASTValueNode {
   public:
    ASTSome* left;
    ASTSome* right;
    std::string op;
  };

  class BitwiseNotNode final : public ASTValueNode {
   public:
    ASTSome* value;
  };

  class BreakNode final : public ASTExprNode {
   public:
  };

  class CallNode final : public ASTValueNode {
   public:
    ASTSome* value;
    std::vector<std::vector<TypeValueSingleNode*>> generics;
    std::vector<ArgNode*> args;
  };

  class ChainNode final : public ASTValueNode {
   public:
    ASTSome* left;
    IdentifierNode* right;
  };

  class ComparisonNode final : public ASTValueNode {
   public:
    ASTSome* left;
    ASTSome* right;
    std::string op;
  };

  class CompInstBlockProgramNode final : public ASTExprNode {
   public:
    std::string name;
    std::string value;
    std::vector<ASTSome*> body;
  };

  class CompInstAssignNode final : public ASTExprNode {
   public:
    std::string name;
    std::string value;
  };

  class ContinueNode final : public ASTExprNode {
   public:
  };

  class DictionaryElementNode final : public ASTExprNode {
   public:
    ASTSome* key;
    ASTSome* value;
  };

  class DictionaryNode final : public ASTValueNode {
   public:
    std::vector<TypeValueSingleNode*> key_types;
    std::vector<TypeValueSingleNode*> value_types;
    std::vector<DictionaryElementNode*> elements;
  };

  class DiiaNode final : public ASTExprNode {
   public:
    bool ee = false;
    bool async = false;
    std::string structure;
    std::string name;
    std::vector<GenericNode*> generics;
    std::vector<ParamNode*> params;
    std::vector<TypeValueSingleNode*> return_types;
    std::vector<ASTSome*> body;
  };

  class EachNode final : public ASTExprNode {
   public:
    ASTSome* value;
    std::string keyName;
    std::string name;
    std::vector<ASTSome*> body;
  };

  class EvalNode final : public ASTExprNode {
   public:
    std::string value;
  };

  class GenericNode final : public ASTExprNode {
   public:
    std::string name;
  };

  class FunctionNode final : public ASTExprNode {
   public:
    bool async;
    std::vector<ParamNode*> params;
    std::vector<TypeValueSingleNode*> return_types;
    std::vector<ASTSome*> body;
  };

  class FromToSimpleNode final : public ASTExprNode {
   public:
    ASTSome* from;
    ASTSome* to;
    std::string toSymbol;
  };

  class FromToComplexNode final : public ASTExprNode {
   public:
    ASTSome* from;
    ASTSome* to;
    std::string toSymbol;
    ASTSome* step;
    std::string stepSymbol;
  };

  class GetElementNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
    ASTSome* index = nullptr;
  };

  class GiveElementNode final : public ASTExprNode {
   public:
    std::string name;
    std::string as;
  };

  class GiveNode final : public ASTExprNode {
   public:
    std::vector<GiveElementNode*> elements;
  };

  class GodNode final : public ASTExprNode {
   public:
    std::vector<ASTSome*> elements;
  };

  class IdentifierNode final : public ASTValueNode {
   public:
    std::string name;
  };

  class IfNode final : public ASTExprNode {
   public:
    ASTSome* condition;
    std::vector<ASTSome*> body;
    std::vector<ASTSome*> else_body;
  };

  class MethodDeclarationNode final : public ASTExprNode {
   public:
    bool ee = false;
    bool async = false;
    std::string name;
    std::vector<GenericNode*> generics;
    std::vector<ParamNode*> params;
    std::vector<TypeValueSingleNode*> return_types;
  };

  class MockupDiiaNode final : public ASTExprNode {
   public:
    bool ee = false;
    bool async = false;
    std::string structure;
    std::string name;
    std::vector<GenericNode*> generics;
    std::vector<ParamNode*> params;
    std::vector<TypeValueSingleNode*> return_types;
  };

  class MockupModuleNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<ASTSome*> elements;
  };

  class MockupStructureNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<GenericNode*> generics;
    ASTSome* parent;
    std::vector<GenericNode*> parent_generics;
    std::vector<ParamNode*> params;
    std::vector<MethodDeclarationNode*> methods;
  };

  class MockupSubjectNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<TypeValueSingleNode*> types;
  };

  class ModuleNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<ASTSome*> body;
  };

  class MRMDiiaNode final : public ASTValueNode {
   public:
    std::string body;
  };

  class NegativeNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class NotNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class NumberNode final : public ASTValueNode {
   public:
    std::string value;
  };

  class ParamNode final : public ASTExprNode {
   public:
    bool ee = false;
    std::string name;
    std::vector<TypeValueSingleNode*> types;
    ASTSome* value;
    bool variadic = false;
  };

  class PositiveNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class PostDecrementNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class PostIncrementNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class PreDecrementNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class PreIncrementNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class ProgramNode final : public ASTExprNode {
   public:
    std::vector<ASTSome*> body;
  };

  class ReturnNode final : public ASTExprNode {
   public:
    ASTSome* value = nullptr;
  };

  class StringNode final : public ASTValueNode {
   public:
    std::string value;
    bool html_tag = false;
  };

  class StructureNode final : public ASTExprNode {
   public:
    std::string name;
    std::vector<GenericNode*> generics;
    ASTSome* parent;
    std::vector<GenericNode*> parent_generics;
    std::vector<ParamNode*> params;
    std::vector<MethodDeclarationNode*> methods;
  };

  class TakeModuleNode final : public ASTExprNode {
   public:
    bool relative;
    std::string name;
    std::string as;
    std::map<std::string, std::string> elements;
  };

  class TakePakNode final : public ASTExprNode {
   public:
    std::string name;
    std::string version;
    std::string as;
  };

  class TernaryNode final : public ASTValueNode {
   public:
    ASTSome* condition = nullptr;
    ASTSome* body = nullptr;
    ASTSome* else_body = nullptr;
  };

  class TestNode final : public ASTValueNode {
   public:
    ASTSome* left;
    ASTSome* right;
    std::string op;
  };

  class ThrowNode final : public ASTExprNode {
   public:
    ASTSome* value = nullptr;
  };

  class TryNode final : public ASTExprNode {
   public:
    std::vector<ASTSome*> body;
    std::string name;
    std::vector<ASTSome*> catch_body;
  };

  class TypeValueSingleNode final : public ASTExprNode {
   public:
    ASTSome* value;
    std::vector<std::vector<TypeValueSingleNode*>> generics;
  };

  class WaitNode final : public ASTValueNode {
   public:
    ASTSome* value = nullptr;
  };

  class WhileNode final : public ASTExprNode {
   public:
    ASTSome* condition;
    std::vector<ASTSome*> body;
  };
} // namespace mavka::ast
#endif // AST_H
