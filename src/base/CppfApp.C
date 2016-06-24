#include "CppfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<CppfApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

CppfApp::CppfApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CppfApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CppfApp::associateSyntax(_syntax, _action_factory);
}

CppfApp::~CppfApp()
{
}

// External entry point for dynamic application loading
extern "C" void CppfApp__registerApps() { CppfApp::registerApps(); }
void
CppfApp::registerApps()
{
  registerApp(CppfApp);
}

// External entry point for dynamic object registration
extern "C" void CppfApp__registerObjects(Factory & factory) { CppfApp::registerObjects(factory); }
void
CppfApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CppfApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CppfApp::associateSyntax(syntax, action_factory); }
void
CppfApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
