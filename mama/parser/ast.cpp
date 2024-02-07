#include "ast.h"

namespace mavka::ast {
  ASTSome* make_ast_some(ast::AnonDiiaNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->AnonDiiaNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ArgNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ArgNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ArithmeticNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ArithmeticNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ArrayNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ArrayNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::AsNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->AsNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::AssignByElementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->AssignByElementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::AssignByIdentifierNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->AssignByIdentifierNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::AssignSimpleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->AssignSimpleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::BitwiseNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->BitwiseNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::BitwiseNotNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->BitwiseNotNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::BreakNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->BreakNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::CallNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->CallNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ChainNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ChainNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ComparisonNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ComparisonNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::CompInstBlockProgramNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->CompInstBlockProgramNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::CompInstAssignNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->CompInstAssignNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ContinueNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ContinueNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::DictionaryElementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->DictionaryElementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::DictionaryNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->DictionaryNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::DiiaNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->DiiaNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::EachNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->EachNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::EvalNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->EvalNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::FromToComplexNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->FromToComplexNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::FromToSimpleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->FromToSimpleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::FunctionNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->FunctionNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::GenericNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->GenericNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::GetElementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->GetElementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::GiveElementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->GiveElementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::GiveNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->GiveNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::GodNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->GodNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::IdentifierNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->IdentifierNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::IfNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->IfNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MethodDeclarationNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MethodDeclarationNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MockupDiiaNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MockupDiiaNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MockupModuleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MockupModuleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MockupStructureNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MockupStructureNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MockupSubjectNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MockupSubjectNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ModuleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ModuleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::MRMDiiaNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->MRMDiiaNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::NegativeNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->NegativeNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::NotNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->NotNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::NumberNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->NumberNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ParamNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ParamNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::PositiveNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->PositiveNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::PostDecrementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->PostDecrementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::PostIncrementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->PostIncrementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::PreDecrementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->PreDecrementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::PreIncrementNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->PreIncrementNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ProgramNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ProgramNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ReturnNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ReturnNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::StringNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->StringNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::StructureNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->StructureNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TakeModuleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TakeModuleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TakePakNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TakePakNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TernaryNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TernaryNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TestNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TestNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::ThrowNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->ThrowNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TryNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TryNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::TypeValueSingleNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->TypeValueSingleNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::WaitNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->WaitNode = node;
    return ast_some;
  }
  ASTSome* make_ast_some(ast::WhileNode* node) {
    const auto ast_some = new ASTSome();
    ast_some->WhileNode = node;
    return ast_some;
  }

  /*
  ASTSome* make_ast_some(ast::ASTNode* node) {
    if (const auto real_node = dynamic_cast<AnonDiiaNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->AnonDiiaNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ArgNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ArgNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ArithmeticNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ArithmeticNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ArrayNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ArrayNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<AsNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->AsNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<AssignByElementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->AssignByElementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<AssignByIdentifierNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->AssignByIdentifierNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<AssignSimpleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->AssignSimpleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<BitwiseNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->BitwiseNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<BitwiseNotNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->BitwiseNotNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<BreakNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->BreakNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<CallNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->CallNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ChainNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ChainNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ComparisonNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ComparisonNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<CompInstBlockProgramNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->CompInstBlockProgramNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<CompInstAssignNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->CompInstAssignNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ContinueNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ContinueNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<DictionaryElementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->DictionaryElementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<DictionaryNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->DictionaryNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<DiiaNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->DiiaNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<EachNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->EachNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<EvalNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->EvalNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<FromToComplexNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->FromToComplexNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<FromToSimpleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->FromToSimpleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<FunctionNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->FunctionNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<GenericNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->GenericNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<GetElementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->GetElementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<GiveElementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->GiveElementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<GiveNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->GiveNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<GodNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->GodNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<IdentifierNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->IdentifierNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<IfNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->IfNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<MethodDeclarationNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->MethodDeclarationNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<MockupDiiaNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->MockupDiiaNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<MockupModuleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->MockupModuleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<MockupStructureNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->MockupStructureNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<MockupSubjectNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->MockupSubjectNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ModuleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ModuleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<NegativeNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->NegativeNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<NotNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->NotNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<NumberNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->NumberNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ParamNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ParamNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<PositiveNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->PositiveNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<PostDecrementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->PostDecrementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<PostIncrementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->PostIncrementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<PreDecrementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->PreDecrementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<PreIncrementNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->PreIncrementNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ProgramNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ProgramNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ReturnNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ReturnNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<StringNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->StringNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<StructureNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->StructureNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TakeModuleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TakeModuleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TakePakNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TakePakNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TernaryNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TernaryNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TestNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TestNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<ThrowNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->ThrowNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TryNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TryNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<TypeValueSingleNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->TypeValueSingleNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<WaitNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->WaitNode = real_node;
      return ast_some;
    }
    if (const auto real_node = dynamic_cast<WhileNode*>(node)) {
      const auto ast_some = new ASTSome();
      ast_some->WhileNode = real_node;
      return ast_some;
    }
    return nullptr;
  }*/

  ASTNode* get_ast_node(ASTSome* ast_some) {
    if (ast_some->AnonDiiaNode != nullptr)
      return ast_some->AnonDiiaNode;
    if (ast_some->ArgNode != nullptr)
      return ast_some->ArgNode;
    if (ast_some->ArithmeticNode != nullptr)
      return ast_some->ArithmeticNode;
    if (ast_some->ArrayNode != nullptr)
      return ast_some->ArrayNode;
    if (ast_some->AsNode != nullptr)
      return ast_some->AsNode;
    if (ast_some->AssignByElementNode != nullptr)
      return ast_some->AssignByElementNode;
    if (ast_some->AssignByIdentifierNode != nullptr)
      return ast_some->AssignByIdentifierNode;
    if (ast_some->AssignSimpleNode != nullptr)
      return ast_some->AssignSimpleNode;
    if (ast_some->BitwiseNode != nullptr)
      return ast_some->BitwiseNode;
    if (ast_some->BitwiseNotNode != nullptr)
      return ast_some->BitwiseNotNode;
    if (ast_some->BreakNode != nullptr)
      return ast_some->BreakNode;
    if (ast_some->CallNode != nullptr)
      return ast_some->CallNode;
    if (ast_some->ChainNode != nullptr)
      return ast_some->ChainNode;
    if (ast_some->ComparisonNode != nullptr)
      return ast_some->ComparisonNode;
    if (ast_some->CompInstBlockProgramNode != nullptr)
      return ast_some->CompInstBlockProgramNode;
    if (ast_some->CompInstAssignNode != nullptr)
      return ast_some->CompInstAssignNode;
    if (ast_some->ContinueNode != nullptr)
      return ast_some->ContinueNode;
    if (ast_some->DictionaryElementNode != nullptr)
      return ast_some->DictionaryElementNode;
    if (ast_some->DictionaryNode != nullptr)
      return ast_some->DictionaryNode;
    if (ast_some->DiiaNode != nullptr)
      return ast_some->DiiaNode;
    if (ast_some->EachNode != nullptr)
      return ast_some->EachNode;
    if (ast_some->EvalNode != nullptr)
      return ast_some->EvalNode;
    if (ast_some->FromToComplexNode != nullptr)
      return ast_some->FromToComplexNode;
    if (ast_some->FromToSimpleNode != nullptr)
      return ast_some->FromToSimpleNode;
    if (ast_some->FunctionNode != nullptr)
      return ast_some->FunctionNode;
    if (ast_some->GenericNode != nullptr)
      return ast_some->GenericNode;
    if (ast_some->GetElementNode != nullptr)
      return ast_some->GetElementNode;
    if (ast_some->GiveElementNode != nullptr)
      return ast_some->GiveElementNode;
    if (ast_some->GiveNode != nullptr)
      return ast_some->GiveNode;
    if (ast_some->GodNode != nullptr)
      return ast_some->GodNode;
    if (ast_some->IdentifierNode != nullptr)
      return ast_some->IdentifierNode;
    if (ast_some->IfNode != nullptr)
      return ast_some->IfNode;
    if (ast_some->MethodDeclarationNode != nullptr)
      return ast_some->MethodDeclarationNode;
    if (ast_some->MockupDiiaNode != nullptr)
      return ast_some->MockupDiiaNode;
    if (ast_some->MockupModuleNode != nullptr)
      return ast_some->MockupModuleNode;
    if (ast_some->MockupStructureNode != nullptr)
      return ast_some->MockupStructureNode;
    if (ast_some->MockupSubjectNode != nullptr)
      return ast_some->MockupSubjectNode;
    if (ast_some->ModuleNode != nullptr)
      return ast_some->ModuleNode;
    if (ast_some->MRMDiiaNode != nullptr)
      return ast_some->MRMDiiaNode;
    if (ast_some->NegativeNode != nullptr)
      return ast_some->NegativeNode;
    if (ast_some->NotNode != nullptr)
      return ast_some->NotNode;
    if (ast_some->NumberNode != nullptr)
      return ast_some->NumberNode;
    if (ast_some->ParamNode != nullptr)
      return ast_some->ParamNode;
    if (ast_some->PositiveNode != nullptr)
      return ast_some->PositiveNode;
    if (ast_some->PostDecrementNode != nullptr)
      return ast_some->PostDecrementNode;
    if (ast_some->PostIncrementNode != nullptr)
      return ast_some->PostIncrementNode;
    if (ast_some->PreDecrementNode != nullptr)
      return ast_some->PreDecrementNode;
    if (ast_some->PreIncrementNode != nullptr)
      return ast_some->PreIncrementNode;
    if (ast_some->ProgramNode != nullptr)
      return ast_some->ProgramNode;
    if (ast_some->ReturnNode != nullptr)
      return ast_some->ReturnNode;
    if (ast_some->StringNode != nullptr)
      return ast_some->StringNode;
    if (ast_some->StructureNode != nullptr)
      return ast_some->StructureNode;
    if (ast_some->TakeModuleNode != nullptr)
      return ast_some->TakeModuleNode;
    if (ast_some->TakePakNode != nullptr)
      return ast_some->TakePakNode;
    if (ast_some->TernaryNode != nullptr)
      return ast_some->TernaryNode;
    if (ast_some->TestNode != nullptr)
      return ast_some->TestNode;
    if (ast_some->ThrowNode != nullptr)
      return ast_some->ThrowNode;
    if (ast_some->TryNode != nullptr)
      return ast_some->TryNode;
    if (ast_some->TypeValueSingleNode != nullptr)
      return ast_some->TypeValueSingleNode;
    if (ast_some->WaitNode != nullptr)
      return ast_some->WaitNode;
    if (ast_some->WhileNode != nullptr)
      return ast_some->WhileNode;
    return nullptr;
  }

  bool ASTSome::is_nullptr() {
    return get_ast_node(this) == nullptr;
  }

  bool ASTSome::is_popable() {
    if (this->AssignByElementNode) {
      return false;
    }
    if (this->AssignByIdentifierNode) {
      return false;
    }
    if (this->AssignSimpleNode) {
      return false;
    }
    if (this->DiiaNode) {
      return false;
    }
    if (this->EachNode) {
      return false;
    }
    if (this->IfNode) {
      return false;
    }
    if (this->ModuleNode) {
      return false;
    }
    if (this->ProgramNode) {
      return false;
    }
    if (this->BreakNode) {
      return false;
    }
    if (this->ContinueNode) {
      return false;
    }
    if (this->ReturnNode) {
      return false;
    }
    if (this->StructureNode) {
      return false;
    }
    if (this->TakeModuleNode) {
      return false;
    }
    if (this->TakePakNode) {
      return false;
    }
    if (this->ThrowNode) {
      return false;
    }
    if (this->TryNode) {
      return false;
    }
    if (this->WhileNode) {
      return false;
    }
    return true;
  }
} // namespace mavka::ast